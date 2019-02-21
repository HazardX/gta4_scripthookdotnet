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

#pragma once
#include "stdafx.h"

#include "NetHook.h"

#include "Console.h"
#include "ConsoleCommands.h"
#include "D3D_Device.h"
#include "Game.h"
#include "Graphics.h"
#include "KeyboardLayout.h"
#include "KeyWatchDog.h"
#include "MemoryAccess.h"
#include "Player.h"
#include "RemoteScriptDomain.h"
#include "ScriptDomain.h"
#include "StartupThreadC.h"
#include "fFormHost.h"
#include "fMouse.h"
#include "cppHook.h"

#pragma managed

namespace GTA {

	static NetHook::NetHook() {
		pGraphics = gcnew GTA::Graphics();
	}

	[Security::Permissions::SecurityPermissionAttribute(Security::Permissions::SecurityAction::Demand, ControlAppDomain = true )]
	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void NetHook::Initialize(bool isPrimary, int hModule){
		bPrimary = isPrimary;
		pHModule = hModule;
		if (isPrimary) {
			pKeys = gcnew GTA::KeyWatchDog();
			pMouse = gcnew GTA::Forms::Mouse();
			pConsole = gcnew GTA::Console();
		} else {
			pMouse = gcnew GTA::Forms::RemoteMouse();
			pConsole = gcnew GTA::RemoteConsole();
		}

		SupportedGameVersions = gcnew Dictionary<GameVersion,cppHookVersion>();
		SupportedGameVersions->Add(GameVersion::v1010, cppHookVersion::v0_4_0);
		SupportedGameVersions->Add(GameVersion::v1020, cppHookVersion::v0_4_0);
		SupportedGameVersions->Add(GameVersion::v1030, cppHookVersion::v0_4_0);
		SupportedGameVersions->Add(GameVersion::v1040, cppHookVersion::v0_4_0);
		SupportedGameVersions->Add(GameVersion::v1050, cppHookVersion::v0_5_1);
		SupportedGameVersions->Add(GameVersion::v1060, cppHookVersion::v0_5_1);
		SupportedGameVersions->Add(GameVersion::v1070, cppHookVersion::v0_5_1);
		SupportedGameVersions->Add(GameVersion::v1110, cppHookVersion::v0_5_1);
		SupportedGameVersions->Add(GameVersion::v1120, cppHookVersion::v0_5_1);

		CallMutex->WaitOne();
		try {
			if (isPrimary)
				Log(String::Concat( "Initializing ", GTA::NetHook::VersionName, " (on GTA IV version ", GetVersionName(GTA::Game::Version), " with C++ Hook version ", GetVersionName((cppHookVersion)unmanaged::cppHook::GetCppHookVersion()), ")" ),false,true);
			else
				if (VERBOSE) Log(String::Concat( "Initializing SCRIPTDOMAIN for ", GTA::NetHook::VersionName ));

			if (VERBOSE) { 
				Log( "AppDomain: " + System::AppDomain::CurrentDomain->FriendlyName );
				//Assembly^ asb = Assembly::GetCallingAssembly();
				//if isNotNULL(asb) Log( "CallingAssembly: " + asb->Location );
				//asb = Assembly::GetEntryAssembly();
				//if isNotNULL(asb) Log( "EntryAssembly: " + asb->Location );
				//asb = Assembly::GetExecutingAssembly();
				//if isNotNULL(asb) Log( "ExecutingAssembly: " + asb->Location );
			}

			pBaseAddress = reinterpret_cast<u32>( GetModuleHandle(NULL) );
			pBaseAddress -= 0x400000;

			if (GTA::Game::Version == GameVersion::UnknownVersion) {
				Log(String::Concat( "WARNING: Your version of GTA IV cannot be identified! Use GTA IV version ", GetVersionName(MaxGameVersion), " instead!" ));
				return;
			} else if (!SupportedGameVersions->ContainsKey(GTA::Game::Version)) {
				Log(String::Concat( "WARNING: GTA IV version ", GetVersionName(GTA::Game::Version), " is not supported! Latest supported GTA IV patch is ", GetVersionName(MaxGameVersion), "!" ));
				return;
			} else if (!isPrimary) {
				// do not warn again in AppDomains
			} else if ( SupportedGameVersions[GTA::Game::Version] != (cppHookVersion)unmanaged::cppHook::GetCppHookVersion() ) {
				Log(String::Concat( "WARNING: Your C++ ScriptHook version ", GetVersionName((cppHookVersion)unmanaged::cppHook::GetCppHookVersion()) ," and GTA IV version ", GetVersionName(GTA::Game::Version), " are NOT known to be compatible! Use C++ ScriptHook version ", GetVersionName(SupportedGameVersions[GTA::Game::Version]) ," or the newest version of the game AND the C++ ScriptHook instead!" ), true, false);
			}

			unmanaged::MemoryAccess::Init(pBaseAddress, GTA::Game::Version);

			//ScriptHookManager::Initialize(); // Required by BOTH // NOT required anymore!

			String^ lang = System::Globalization::CultureInfo::CurrentCulture->TwoLetterISOLanguageName->ToLower();
			if (lang == "de") {
				pKeyboardLayout = gcnew KeyboardLayoutDE();
			} else {
				pKeyboardLayout = gcnew KeyboardLayoutUS();
			}

			Helper::EnforceCultureUS();

			if (isPrimary) {

				GTA::Console^ cons = (GTA::Console^)pConsole;
				pFormHost = gcnew GTA::Forms::FormHost(nullptr);

				AppDomain::CurrentDomain->AssemblyResolve += gcnew ResolveEventHandler(&MyResolveEventHandler);
				AppDomain::CurrentDomain->UnhandledException += gcnew UnhandledExceptionEventHandler(&CatchUnhandledExceptions);

				//ScriptHookManager::Initialize(); 
				unmanaged::cppHook::RegisterThread( new StartupThreadC(), (HMODULE)hModule );

				//ManagerThread = gcnew GTA::ManagerThread();
				//ManagerThread->RegisterInOldScriptHookManager();
				GTA::Direct3D::InstallHook();
				
				pKeys->KeyDown += gcnew KeyEventHandler(&KeyDown);
				pKeys->KeyUp += gcnew KeyEventHandler(&KeyUp);
				cons->Command += gcnew ConsoleEventHandler(&ConsoleCommand);
				cons->Opened += gcnew EventHandler(&ConsoleOpened);
				cons->Closed += gcnew EventHandler(&ConsoleClosed);


				if isNULL(pScriptDomain) pScriptDomain = gcnew GTA::ScriptDomain();
				//pScriptDomain->Create();

				pScriptDomain->RequestAction(ScriptAction::LoadScripts);

			} else {

				//ScriptHookManager::Initialize(); 

				//ManagerThread = gcnew GTA::ManagerThread();
				//ManagerThread->RegisterInOldScriptHookManager();

			}

		} catchErrors("Error during initialization", if(VERBOSE) Terminate(); )
		CallMutex->ReleaseMutex();
	}

	bool NetHook::isInsideScript::get() {
		if (isScriptDomain) {
			return isNotNULL(RemoteScriptDomain::Instance->CurrentScript);
		} else {
			return bInsideScript;
		}
	}
	bool NetHook::CanScriptsRunNow::get() {
		//if (Scripting::IsPauseMenuActive()) return false;
		//if (Game::LastFrameTime == 0.0f) return false;
		Player^ p = Game::LocalPlayer;
		if ( isNULL(p) || (!p->isActive) ) return false;
		return true;
	}

	void NetHook::GameEnded() {
		UnloadScriptDomain();
	}
	void NetHook::Terminate() {
		if (Game::isMultiplayer) {
			Scripting::NetworkEndSession();
			Scripting::NetworkLeaveGame();
		}

		GameEnded();

		HWND win = GetActiveWindow();
		if (win == NULL)
			exit(0);
		else
			SendMessage(win, WM_CLOSE, 0 ,0);
	}
	void NetHook::Minimize() {
		HWND hwnd = GetActiveWindow();
		RECT rect;
		GetWindowRect( hwnd, &rect );
		SetWindowPos(hwnd, HWND_BOTTOM, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top, SWP_SHOWWINDOW);
		ShowWindow(hwnd, SW_SHOWMINIMIZED);
		System::Windows::Forms::Cursor::Show();
	}

	void NetHook::CatchUnhandledExceptions(System::Object^ sender, UnhandledExceptionEventArgs^ args) {
		try {
			Log("Unhandled Exception: " + args->ExceptionObject->ToString());
			if (args->IsTerminating) Log("CRASH!");
		} catchErrors("Unhandled Exception",)
	}

	Assembly^ NetHook::MyResolveEventHandler(System::Object^ sender, ResolveEventArgs^ args) {
		AppDomain^ domain = dynamic_cast<AppDomain^>(sender);
		
		//if (args->Name->Equals(myasb->FullName, StringComparison::InvariantCultureIgnoreCase)) {
		if (args->Name->ToLower()->Contains("scripthookdotnet")) {
			Assembly^ myasb = Assembly::GetAssembly(GTA::Script::typeid);
			if (VERBOSE) Log("Successfully resolved '" + args->Name + "' for domain '"+domain->FriendlyName+"'!");
			return myasb;
		}
		//if (args->Name->ToLower()->Contains("slimdx")) {
		//	Assembly^ sdxasb = Assembly::GetAssembly(GTA::Direct3D9::Device::typeid);
		//	if (VERBOSE) Log("Successfully resolved '" + args->Name + "' for domain '"+domain->FriendlyName+"'!");
		//	return sdxasb;
		//}
		if (VERBOSE) Log("Failed to resolve Assembly '" + args->Name + "' for domain '"+domain->FriendlyName+"'!");
		return nullptr;
   }

	void NetHook::KeyDown(Object^ sender, KeyEventArgs^ e) {
		try {
			LocalConsole->PressKey(e->KeyWithModifiers);
		} catchErrors ("Error in console",)
			
		if ((e->Key) == LocalConsole->ActivationKey) return;
		LocalMouse->CheckButtonDown(e->Key);
		FormHost->TriggerKeyDown(e); // only local

		if (pConsole->isActive) return;
		ScriptDomain->TriggerEvent(ScriptEvent::KeyDown, e);
	}
	void NetHook::KeyUp(Object^ sender, KeyEventArgs^ e) {
		//if (BlockInput) return;
		if ((e->Key) == LocalConsole->ActivationKey) return;
		LocalMouse->CheckButtonUp(e->Key);
		FormHost->TriggerKeyUp(e);

		if (pConsole->isActive) return;
		ScriptDomain->TriggerEvent(ScriptEvent::KeyUp, e);
	}

	void NetHook::ConsoleOpened(Object^ sender, EventArgs^ e) {
		//Game::LocalPlayer->CanControlCharacter = false;
		Mouse->Enabled = true;
	}
	void NetHook::ConsoleClosed(Object^ sender, EventArgs^ e) {
		//Game::LocalPlayer->CanControlCharacter = true;
		//Mouse->Enabled = false;
		TryToDisableMouse();
	}

	void NetHook::ConsoleCommand(Object^ sender, ConsoleEventArgs^ e) {
		String^ cmd = e->Command->ToLower();

		if (cmd == "exit") { // EXIT
			Terminate();
			return;
		}
		if (ConsoleCommands::ProcessCommand(e)) return;

		//Log( "Console command: " + e->ToString() );
		ScriptDomain->TriggerEvent(ScriptEvent::ConsoleCommand, e);
	}


	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void NetHook::CheckPhone() {
		if (bPhoneError) return;

		String^ num;
		try {
			num = unmanaged::MemoryAccess::GetPhoneNumber();
		//} catchErrors ("Error during GetPhoneNumber (Phone checks will be disabled)", num = String::Empty; bPhoneError = true; )
		} catch(...) {
			num = String::Empty;
			bPhoneError = true;
			GTA::NetHook::Log( "INFO: Phone number checks are not available!" );
		}
	
		if (num != pLastPhoneNumber) {
			if (!bDialing) bDialing = true;
			pLastPhoneNumberChange = DateTime::Now;
			pLastPhoneNumber = num;
			return;
		}
		if (!bDialing) return;
		if ((DateTime::Now-pLastPhoneNumberChange) < pDialingDoneTime) return;
		bDialing = false;
		if (pLastPhoneNumber == String::Empty) return;
		ScriptDomain->TriggerEvent(ScriptEvent::PhoneNumberDialed, gcnew PhoneDialEventArgs(pLastPhoneNumber));
		//Log("Number dialed: " + pLastPhoneNumber);
		// TODO: Call phone event
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void NetHook::Tick() {
		if (!bPrimary) return;

		//if (!unmanaged::cppHook::isAnyGameThreadActive()) {
		//	if (VERBOSE) Log("Terminated Game BEFORE NetHook.Tick!");
		//	GameTerminated();
		//	return;
		//}

		if (!CanScriptsRunNow) return;
		if (!CallMutex->WaitOne(250, false)) {
			if (VERBOSE) Log("Tick call passed because thread is blocked!");
			return;
		}
		try {

			//if (!unmanaged::cppHook::isAnyGameThreadActive()) {
			//	if (VERBOSE) Log("Terminated Game in NetHook.Tick!");
			//	GameTerminated();
			//	return;
			//}

			if (Console->isActive) {
				//if (Scripting::GetTextInputActive() != 0) Scripting::SetTextInputActive(0);
				Scripting::SetTextInputActive(0);
			}

			LocalMouse->Check();
			pKeys->Check();

			Game::PerFrame();

			//LocalConsole->Tick();
			//ConsoleCommands::Tick();

			CheckPhone();

			bInsideScript = true;
			ScriptDomain->Tick();
			bInsideScript = false;

			FormHost->TriggerDragging();

		} catchErrors ("Error during NetHook.Tick",)
		finally {	CallMutex->ReleaseMutex();	}
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void NetHook::Draw() {
		if (!bPrimary) return;

		//if (!unmanaged::cppHook::isAnyGameThreadActive()) {
		//	if (VERBOSE) Log("Terminated Game BEFORE NetHook.Draw!");
		//	GameTerminated();
		//	return;
		//}

		if (!CanScriptsRunNow) return;
		if (!CallMutex->WaitOne(250, false)) {
			if (VERBOSE) Log("Draw call passed because thread is blocked!");
			return;
		}
		try {

			//if (!unmanaged::cppHook::isAnyGameThreadActive()) {
			//	if (VERBOSE) Log("Terminated Game in NetHook.Draw!");
			//	GameTerminated();
			//	return;
			//}

			pGraphics->InitFrame();
			pGraphics->Scaling = FontScaling::Pixel;

			bInsideScript = true;
			try {
				ScriptDomain->PerFrameDrawing();
			} catchErrors ("Error during ScriptDomain.PerFrameDrawing",)
			bInsideScript = false;

			pGraphics->Scaling = FontScaling::Pixel;
			if (VERBOSE) pGraphics->DrawText("REPF: " + ScriptDomain->RemoteEventsPerFrame.ToString(), 16.0f, float(Game::Resolution.Height - 16.0f));

			pGraphics->Scaling = FontScaling::Pixel;
			if (pDisplayTextUntil >= DateTime::Now) {
				if (LocalConsole->isActive) {
					pGraphics->DrawText(pDisplayText, 16.0f, LocalConsole->Height + 16.0f);
				} else {
					TimeSpan last = pDisplayTextUntil-DateTime::Now;
					//Scripting::SetTextScale(0.5f,0.5f);
					if (last.TotalSeconds > 0.5) {
						pGraphics->DrawText(pDisplayText, 16.0f, 16.0f);
					} else {
						pGraphics->DrawText(pDisplayText, 16.0f, 16.0f - ((0.5f-(float)last.TotalSeconds)*64.0f));
					}
				}
			}

			try {
				FormHost->TriggerPaint(gcnew GraphicsEventArgs(pGraphics));
			} catchErrors ("Error during FormHost.TriggerPaint",)

			try {
				LocalConsole->PerFrameDrawing(pGraphics);
			} catchErrors ("Error while console draw", pConsole->Close(); )

			LocalMouse->Draw(pGraphics);

		} finally {	CallMutex->ReleaseMutex();	}
	}

	void NetHook::CreateScriptDomain() {
		if (ScriptDomain->isActive) return;
		ScriptDomain->Create();
	}

	void NetHook::UnloadScriptDomain() {
		if (VERBOSE) Log("Unloading ScriptDomain...");
		try {
			ScriptDomain->RequestAction(ScriptAction::RemoveAllScripts);
			bool res = ScriptDomain->WaitForScriptsToAbort(10000);
			if ((!res) && (VERBOSE)) Log("Not all scripts finished their loop.");
			ScriptDomain->Unload();
		} catchErrors("Error during UnloadScriptDomain",)
		if (VERBOSE) Log("Unloading ScriptDomain done!");
	}

	void NetHook::ReloadScriptDomain() {
		UnloadScriptDomain();
		ScriptDomain->Create();
	}

	void NetHook::GameReloaded() {
		if (VERBOSE) Log( "Reloading game..." );
		//Helper::EnforceCultureUS();

		Direct3D::ForceDeviceReset();
		CallMutex->WaitOne();
		try {
			if (ScriptDomain->RunningScriptCount > 0)
				ReloadScriptDomain();
			else
				CreateScriptDomain();
			RequestScriptAction(ScriptAction::RestartScripts);
		} finally {	CallMutex->ReleaseMutex();	}
		if (VERBOSE) Log( "Reloading game done!" );
	}
	void NetHook::GameTerminated() {
		if (VERBOSE) Log( "Currently running game was terminated!" );
		Direct3D::ForceDeviceRelease();
		CallMutex->WaitOne();
		try {
			UnloadScriptDomain();
		} finally {	CallMutex->ReleaseMutex();	}
	}

	void NetHook::RequestScriptAction(ScriptAction action) {
		ScriptDomain->RequestAction(action);
	}

	void NetHook::DisplayText(String^ Text, int Duration) {
		ALTERNATE_LOCAL_EVENT(RemoteEvent::DisplayText, (gcnew array<Object^>{Text, Duration}),,return;)

		pDisplayText = Text;
		pDisplayTextUntil = DateTime::Now + TimeSpan(0,0,0,0,Duration);
	}

	System::Object^ NetHook::RaiseEventInLocalScriptDomain(RemoteEvent EventID, ... array<System::Object^>^ Arguments) {
		if (NetHook::isPrimary) return nullptr;
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(EventID, Arguments);
		return RemoteScriptDomain::Instance->LastRemoteEventResult;
	}


	bool NetHook::isKeyPressed(System::Windows::Forms::Keys Key){
		if (Console->isActive) return false;
		return ((GetAsyncKeyState((int)Key) & 0x8000) != 0);
	}

	void NetHook::TryToDisableMouse() {
		if (!isPrimary) {
			RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::TryToDisableMouse);
			return;
		}
		int FormCount = FormHost->FormCount + ScriptDomain->TotalScriptFormCount;
		//DisplayText("Form disabled "+FormCount+" forms remain open!", 5000);
		if (FormCount > 0) return;
		Mouse->Enabled = false;
	}



	void NetHook::Log(String^ Text){
		Log(Text,false,false);
	}
	void NetHook::Log(String^ Text, Exception^ ex){
		if (!Object::ReferenceEquals(ex,nullptr)) {
			Log( String::Concat(Text, Environment::NewLine, ex->ToString()), false, false);
			LogInner(ex);
		} else {
			Log( String::Concat(Text, Environment::NewLine, "UNKNOWN EXCEPTION!"), false, false);
		}
	}
	void NetHook::Log(Exception^ ex){
		if (!Object::ReferenceEquals(ex,nullptr)) {
			Log( String::Concat("ERROR:", Environment::NewLine, ex->ToString()), false, false);
			LogInner(ex);
		} else {
			Log( "ERROR: UNKNOWN EXCEPTION!", false, false);
		}
	}
	void NetHook::Log(String^ Text, bool InsertEmptyLine, bool Truncate) {
		if (!bPrimary) Truncate = false;

		//System::Threading::Monitor::Enter(syncrootLog);
		LogMutex->WaitOne();
		try {

			if isNotNULL(pConsole) {
				if (InsertEmptyLine)	pConsole->Print(String::Empty);
				pConsole->Print(Text);
			}

			String^ path = String::Concat(myDllFile->Substring(0,myDllFile->Length-3),"log");
			FileStream^ fs;
			try {
				if (Truncate) {
					fs = gcnew FileStream( path, FileMode::Create, FileAccess::Write, FileShare::Read );
				} else {
					fs = gcnew FileStream( path, FileMode::Append, FileAccess::Write, FileShare::Read );
				}
			} catch (...) {
				return;
			}
			StreamWriter^ sw = gcnew StreamWriter(fs);

			Text = Text->Replace(Environment::NewLine, String::Concat(Environment::NewLine,"                      ") );

			if (InsertEmptyLine) sw->WriteLine();
			sw->Write( DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss",Globalization::CultureInfo::InvariantCulture) );
			sw->Write(" - ");
			if (VERBOSE) {
				sw->Write(AppDomain::CurrentDomain->FriendlyName);
				sw->Write(" - ");
			}
			sw->WriteLine(Text);

			sw->Close();
			fs->Close();

		} catch (...) {
		} finally {
			//System::Threading::Monitor::Exit(syncrootLog);
			LogMutex->ReleaseMutex();
		}
	}
	void NetHook::LogInner(Exception^ ex){
		if (Object::ReferenceEquals(ex,nullptr)) return;
		if (Object::ReferenceEquals(ex->InnerException,nullptr)) return;
		Log( String::Concat(" -> InnerException:", Environment::NewLine, ex->InnerException->ToString()), false, false);
		LogInner(ex->InnerException);
	}

}