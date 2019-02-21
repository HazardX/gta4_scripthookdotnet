/*
* Copyright (c) 2009-2011 Hazard (hazard_x@gmx.net / twitter.com/HazardX)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "stdafx.h"

#include "Script.h"

#include "Game.h"
#include "RemoteScriptDomain.h"
#include "NetThread.h"
#include "Player.h"
#include "ScriptThread.h"
#include "SettingsFile.h"
#include "fFormHost.h"
#include "vResources.h"

#pragma managed

namespace GTA{

	Script::Script(){
		BlockWait = true;
		bWaiting = false;
		bRunning = true;
		pInterval = 0;
		keylist = gcnew List<BoundKeyItem>();
		commandlist = gcnew List<BoundCommandItem>();
		scriptcommandlist = gcnew List<BoundScriptCommandItem>();
		phonenumberlist = gcnew List<BoundPhoneNumberItem>();
		NextTick = System::DateTime::MinValue;
		eventlist = gcnew List<sEvent>(); 
		pGUID = Guid(); //Guid::NewGuid();
		pGeneralInfo = String::Empty;

		myThread = ScriptThread::currentlyLoading;
		domain = myThread->domain;
		pFilename = myThread->scriptFile;

		if (pFilename->EndsWith(".net.dll",StringComparison::InvariantCultureIgnoreCase))
			pFilenameWithoutExtension = pFilename->Substring(0,pFilename->Length - 8);
		else if (pFilename->EndsWith(".net",StringComparison::InvariantCultureIgnoreCase))
			pFilenameWithoutExtension = pFilename->Substring(0,pFilename->Length - 4);
		else
			pFilenameWithoutExtension = System::IO::Path::ChangeExtension(pFilename, nullptr);
		

		FormHost = gcnew GTA::Forms::FormHost(this);

		//pSettings = gcnew GTA::value::ScriptSettings(IO::Path::ChangeExtension(pFilename,"ini"));
		//pSettings->Load();

		domain->SetCurrentScript(this);
		BlockWait = false; // DIRTY, but who cares?
	}
	//Script::~Script(){
	//	this->!Script();
	//}
	//Script::!Script(){
	//	LogFin(Name);
	//	Abort();
	//}

	void Script::Initialize(ScriptThread^ scriptThread){
		if (System::Object::ReferenceEquals(myThread, scriptThread)) return;
		this->myThread = scriptThread;
	}

	GTA::SettingsFile^ Script::Settings::get(){
		if isNULL(pSettings) {
			pSettings = GTA::SettingsFile::Open(pFilenameWithoutExtension + ".ini");
			pSettings->Load();
		}
		return pSettings;
	}

	int Script::RenderID::get(){
		i32 id = -1;
		Scripting::GetScriptRendertargetRenderId(&id);
		return id;
	}

	int Script::Interval::get(){
		return pInterval;
	}
	void Script::Interval::set(int value){
		if (value>0) {
			pInterval = value;
			NextTick = DateTime::Now + TimeSpan(0,0,0,0,value);
		} else {
			pInterval = 0;
			NextTick = DateTime::MinValue;
		}
	}

	bool Script::isKeyPressed(System::Windows::Forms::Keys Key){
		return NetHook::isKeyPressed(Key);
	}

	//float Script::RequiredVersion::get() {
	//	return pRequiredVersion;
	//}
	//void Script::RequiredVersion::set(float value) {
	//	pRequiredVersion = value;
	//	//String^ rqversion = pRequiredVersion.ToString("F3",System::Globalization::CultureInfo::InvariantCulture);
	//	//if (pRequiredVersion > NetHook::Version) {
	//	//	NetHook::Log(String::Concat( "The script '", Name, "' was created for the newer .Net ScriptHook version ", rqversion , "! It may not run as expected! Please download the new version!" ));
	//	//	Game::DisplayText("One script requires the newer .Net ScriptHook version " + rqversion + "!", 5000);
	//	//} else if (pRequiredVersion < NetHook::Version) {
	//	//	NetHook::Log(String::Concat( "The script '", Name, "' was created for the older .Net ScriptHook version ", rqversion , "! It may not run as expected!" ));
	//	//}
	//}


	GTA::Player^ Script::Player::get() {
		return Game::LocalPlayer;
	}

	GTA::value::Resources^ Script::Resources::get() {
		if isNULL(pResources) pResources = gcnew GTA::value::Resources(this);
		return pResources;
	}

	bool Script::Exists(System::Object^ Object) {
		if isNULL(Object) return false;
		if ( Object->GetType()->IsSubclassOf(GTA::base::Object::typeid) ) {
			return ((GTA::base::Object^)Object)->Exists();
		}
		return true;
	}
	bool Script::Exists(GTA::base::Object^ GtaObject) {
		if ( Object::ReferenceEquals(GtaObject,nullptr) ) return false;
		return GtaObject->Exists();
	}

	//void Script::WatchKey(Keys key) {
		//if ( ((int)key < 0) || ((int)key > 255) ) return;
		//if (keylist->Contains(key)) return;
		//keylist->Add(key);
	//}

	bool Script::CanWaitNow::get() {
		if isNULL(myThread) return false;
		if (BlockWait) return false;
		return true;
	}

	void Script::Wait(int ms) {
		if isNULL(myThread) {
			NetHook::Log(String::Concat( "Error during constructor of script '", Name, "':",Environment::NewLine, "Do not call Wait() in the constructor of a script! Do it in Startup() instead!" ));
			throw gcnew System::InvalidOperationException();
			return;
		}
		if (BlockWait) {
			NetHook::Log(String::Concat( "Error in script '", Name, "':",Environment::NewLine, "Illegal call to Wait()!" ));
			throw gcnew System::InvalidOperationException();
			return;
		}
		bWaiting = true;
		BlockWait = true;
		myThread->Wait(ms);
		bWaiting = false;
		BlockWait = false;
	}

	void Script::Abort() {
		BlockWait = true;
		bRunning = false;
		if isNotNULL(myThread) {
			myThread->Abort();
		//	myThread = nullptr;
		}
	}

	void Script::DoStartup(){
		bRunning = true;
		//BlockWait = false;
		//Startup(this, EventArgs::Empty);
		//BlockWait = true;
	}

	void Script::SendScriptCommand(GTA::Script^ Script, String^ Command, ... array<System::Object^>^ Parameter) {
		RemoteScriptDomain::Instance->SendScriptCommand(this, Script, Command, Parameter);
	}
	void Script::SendScriptCommand(Guid ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter) {
		RemoteScriptDomain::Instance->SendScriptCommand(this, ScriptGUID, Command, Parameter);
	}
	void Script::SendScriptCommand(String^ ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter) {
		SendScriptCommand(Guid(ScriptGUID), Command, Parameter);
	}
	bool Script::isScriptRunning(Guid GUID) {
		return RemoteScriptDomain::Instance->isScriptRunning(GUID);
	}
	bool Script::isScriptRunning(String^ GUID) {
		return isScriptRunning(Guid(GUID));
	}


	void Script::BindKey(WinForms::Keys Key, KeyPressDelegate^ MethodToBindTo) {
		keylist->Add(BoundKeyItem(Key,MethodToBindTo));
	}
	void Script::BindKey(WinForms::Keys Key, bool Shift, bool Ctrl, bool Alt, KeyPressDelegate^ MethodToBindTo) {
		Key = Key & WinForms::Keys::KeyCode;
		if (Shift) Key = Key | WinForms::Keys::Shift;
		if (Ctrl) Key = Key | WinForms::Keys::Control;
		if (Alt) Key = Key | WinForms::Keys::Alt;
		//keylist->Add(BoundKeyItem(Key,MethodToBindTo));
		BindKey(Key,MethodToBindTo);
	}
	void Script::BindConsoleCommand(String^ Command, ConsoleCommandDelegate^ MethodToBindTo) {
		commandlist->Add(BoundCommandItem(Command, MethodToBindTo, String::Empty));
	}
	void Script::BindConsoleCommand(String^ Command, ConsoleCommandDelegate^ MethodToBindTo, String^ HelpText) {
		commandlist->Add(BoundCommandItem(Command, MethodToBindTo, HelpText));
	}
	void Script::BindScriptCommand(String^ Command, ScriptCommandDelegate^ MethodToBindTo) {
		scriptcommandlist->Add(BoundScriptCommandItem(Command, MethodToBindTo));
	}
	void Script::BindPhoneNumber(String^ PhoneNumber, PhoneDialDelegate^ MethodToBindTo) {
		phonenumberlist->Add(BoundPhoneNumberItem(Helper::CleanPhoneNumber(PhoneNumber),MethodToBindTo));
	}

	void Script::UnbindKey(WinForms::Keys Key) {
		for (int i = keylist->Count-1; i >= 0; i--) {
			if (keylist[i].Key == Key) {
				keylist->RemoveAt(i);
			}
		}
	}
	void Script::UnbindKey(WinForms::Keys Key, bool Shift, bool Ctrl, bool Alt) {
		Key = Key & WinForms::Keys::KeyCode;
		if (Shift) Key = Key | WinForms::Keys::Shift;
		if (Ctrl) Key = Key | WinForms::Keys::Control;
		if (Alt) Key = Key | WinForms::Keys::Alt;
		UnbindKey(Key);
	}
	void Script::UnbindConsoleCommand(String^ Command) {
		String^ cmd = Command->ToLower();
		for (int i = commandlist->Count-1; i >= 0; i--) {
			if (commandlist[i].Command == cmd) {
				commandlist->RemoveAt(i);
			}
		}
	}
	void Script::UnbindScriptCommand(String^ Command) {
		String^ cmd = Command->ToLower();
		for (int i = scriptcommandlist->Count-1; i >= 0; i--) {
			if (scriptcommandlist[i].Command == cmd) {
				scriptcommandlist->RemoveAt(i);
			}
		}
	}
	void Script::UnbindPhoneNumber(String^ PhoneNumber) {
		String^ num = Helper::CleanPhoneNumber(PhoneNumber);
		for (int i = phonenumberlist->Count-1; i >= 0; i--) {
			if (phonenumberlist[i].PhoneNumber == num) {
				phonenumberlist->RemoveAt(i);
			}
		}
	}

	void Script::ProcessBoundKey(WinForms::Keys Key) {
		for (int i = 0; i < keylist->Count; i++) {
			if (keylist[i].Key == Key) {
				keylist[i].Delegate->Invoke();
				return;
			}
		}
	}
	void Script::ProcessBoundCommand(ConsoleEventArgs^ ceva) {
		String^ cmd = ceva->Command->ToLower();
		for (int i = 0; i < commandlist->Count; i++) {
			if (commandlist[i].Command == cmd) {
				commandlist[i].Delegate->Invoke(ceva->Parameter);
				return;
			}
		}
	}
	void Script::ProcessBoundScriptCommand(ScriptCommandEventArgs^ sceva) {
		String^ cmd = sceva->Command->ToLower();
		for (int i = 0; i < scriptcommandlist->Count; i++) {
			if (scriptcommandlist[i].Command == cmd) {
				scriptcommandlist[i].Delegate->Invoke(sceva->sender, sceva->Parameters);
				return;
			}
		}
	}
	void Script::ProcessBoundPhoneNumber(String^ PhoneNumber) {
		for (int i = 0; i < phonenumberlist->Count; i++) {
			if (phonenumberlist[i].PhoneNumber == PhoneNumber) {
				phonenumberlist[i].Delegate->Invoke();
				return;
			}
		}
	}

	void Script::TryTick() {
		if (Interval>0){
			if (NextTick > System::DateTime::Now) return;
			NextTick = System::DateTime::Now + System::TimeSpan(0,0,0,0,Interval);
			Tick(this, EventArgs::Empty);
		} else {
			Tick(this, EventArgs::Empty);
		}
	}

	void Script::ProcessEvents() {
		if (eventlist->Count == 0) return;

		sEvent ev;
		DateTime time = DateTime::Now;

		while (eventlist->Count > 0) {
			ev = eventlist[0];
			eventlist->RemoveAt(0); // remove here already because it may happen that an event triggers ProcessEvents again!

			switch (ev.Event) {

				case ScriptEvent::KeyDown: {
					if ((time-ev.Time).TotalSeconds <= 1.0) {
						KeyEventArgs^ e = (KeyEventArgs^)ev.args;
						if isNotNULL(e) {
							FormHost->TriggerKeyDown(e);
							if (domain->TotalScriptFormCount <= 0) {
								KeyDown(this, e);
								if (keylist->Count > 0) ProcessBoundKey(e->KeyWithModifiers);
							}
						}
					}
					break;
				}

				case ScriptEvent::KeyUp: {
					if ((time-ev.Time).TotalSeconds <= 1.0) {
						KeyEventArgs^ e = (KeyEventArgs^)ev.args;
						if isNotNULL(e) {
							FormHost->TriggerKeyUp(e);
							if (domain->TotalScriptFormCount <= 0) {
								KeyUp(this, e);
							}
						}
					}
					break;
				}

				case ScriptEvent::MouseDown: {
					if ((time-ev.Time).TotalSeconds <= 1.0) {
						MouseEventArgs^ e = (MouseEventArgs^)ev.args;
						if isNotNULL(e) {
							FormHost->TriggerMouseDown(e);
							if (domain->TotalScriptFormCount <= 0) {
								MouseDown(this, e);
							}
						}
					}
					break;
				}

				case ScriptEvent::MouseUp: {
					if ((time-ev.Time).TotalSeconds <= 1.0) {
						MouseEventArgs^ e = (MouseEventArgs^)ev.args;
						if isNotNULL(e) {
							FormHost->TriggerMouseUp(e);
							if (domain->TotalScriptFormCount <= 0) {
								MouseUp(this, e);
							}
						}
					}
					break;
				}

				case ScriptEvent::ConsoleCommand: {
					ConsoleEventArgs^ e = (ConsoleEventArgs^)ev.args;
					if isNotNULL(e) {
						ConsoleCommand(this, e);
						if (commandlist->Count > 0) ProcessBoundCommand(e);
					}
					break;
				}

				case ScriptEvent::ScriptCommand: {
					ScriptCommandEventArgs^ e = (ScriptCommandEventArgs^)ev.args;
					if isNotNULL(e) {
						ScriptCommand(e->sender, e);
						if (scriptcommandlist->Count > 0) ProcessBoundScriptCommand(e);
					}
					break;
				}

				case ScriptEvent::PhoneNumberDialed: {
					PhoneDialEventArgs^ e = (PhoneDialEventArgs^)ev.args;
					if isNotNULL(e) {
						PhoneNumberDialed(this, e);
						if (phonenumberlist->Count > 0) ProcessBoundPhoneNumber(e->PhoneNumber);
					}
					break;
				}
			}
			//eventlist->RemoveAt(0);
		}
	}

	void Script::DoTick(){
		BlockWait = false;

		ProcessEvents();
		TryTick();
		EachTick(this, EventArgs::Empty);

		BlockWait = true;
	}

	void Script::DoPerFrameDrawing(GTA::GraphicsEventArgs^ e) {
		bool bw = BlockWait;
		BlockWait = true;
		
		//PerFrameDrawing3D(this, e);
		//if (!domain->isConsoleActive) {
			PerFrameDrawing(this, e);
			//FormHost->TriggerPaint(e);
			FormHost->TriggerDragging();
		//}

		BlockWait = bw;
	}
	void Script::DoPerFrameScriptDrawing() {
		bool bw = BlockWait;
		BlockWait = true;
		
		PerFrameScriptDrawing(this, EventArgs::Empty);

		BlockWait = bw;
	}

	String^ Script::ToString() {
		return Name;
	}

}