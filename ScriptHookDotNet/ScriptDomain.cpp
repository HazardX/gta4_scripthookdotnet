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

#include "ScriptDomain.h"

#include "ContentCache.h"
#include "D3D_Device.h"
#include "Game.h"
#include "MemoryAccess.h"
#include "RemoteScriptDomain.h"
#include "VertexFormats.h"
#include "World.h"
#include "fFormHost.h"
#include "nTemplate.h"

#pragma managed

namespace GTA {

//	void ScriptDomain::BuildLoaderAssembly() {
//		//AssemblyName^ assemblyName = gcnew AssemblyName;
//		//assemblyName->Name = "RemoteAssemblyLoader";
//		//Emit::AssemblyBuilder^ assemblyBuilder = domain->DefineDynamicAssembly( assemblyName, Emit::AssemblyBuilderAccess::Save );
//		//Emit::ModuleBuilder^ moduleBuilder = assemblyBuilder->DefineDynamicModule( "RALModule", "ral.dll", true );
//		//Emit::TypeBuilder^ typeBuilder = moduleBuilder->DefineType( "RALType", TypeAttributes::Public );
//		//Emit::ConstructorBuilder^ constructorBuilder = typeBuilder->DefineConstructor( MethodAttributes::Public, CallingConventions::Standard, nullptr );
//		//Emit::ILGenerator^ ilGenerator = constructorBuilder->GetILGenerator();
//		//ilGenerator->EmitWriteLine( "RALType instantiated!" );
//		//ilGenerator->Emit( Emit::OpCodes::Ret );
//		//typeBuilder->CreateType();
//		//assemblyBuilder->Save( "ral.dll" );

	ScriptDomain::ScriptDomain() {
		//wThreadCommand = gcnew System::Threading::AutoResetEvent(false);
		//wThreadHalted = gcnew System::Threading::ManualResetEvent(true);
		//wThreadHandles = gcnew array<System::Threading::WaitHandle^>(2){wThreadCommand,wThreadHalted};
		pRemoteEventsPerFrame = 0;
		pRemoteEventsPerFrameCurrent = 0;
	}

	bool ScriptDomain::isActive::get() {
		if isNULL(pAppDomain) return false;
		if isNULL(remote) return false;
		return true;
	}

	[Security::Permissions::SecurityPermissionAttribute(Security::Permissions::SecurityAction::Demand, ControlAppDomain = true, ControlEvidence = true )]
	void ScriptDomain::Create() {

		try {

#ifdef USE_APPDOMAINS

		if isNotNULL(pAppDomain) Unload();

		Assembly^ myasb = Assembly::GetAssembly(GTA::Script::typeid);

		AppDomainSetup^ setup = gcnew AppDomainSetup();
		setup->ApplicationBase = Game::InstallFolder;


		System::Security::PermissionSet^ trustedLoadFromRemoteSourceGrantSet = gcnew System::Security::PermissionSet(System::Security::Permissions::PermissionState::Unrestricted);


		pAppDomain = System::AppDomain::CreateDomain("SHDN_ScriptDomain",nullptr,setup,trustedLoadFromRemoteSourceGrantSet); //,nullptr
		//pAppDomain = System::AppDomain::CreateDomain("SHDN_ScriptDomain",nullptr,setup); //,nullptr

		pAppDomain->InitializeLifetimeService();

		if (VERBOSE) NetHook::Log("Trying to get RemoteScriptDomain...");

		Runtime::Remoting::ObjectHandle^ handle = pAppDomain->CreateInstanceFrom(myasb->Location, "GTA.RemoteScriptDomain"); //"RemoteLoader", "Westwind.RemoteLoader.RemoteLoaderFactory"
		System::Object^ obj = handle->Unwrap();
		
		if isNULL(obj) {
			NetHook::Log("ERROR: Unable to retrieve RemoteScriptDomain for ScriptDomain!");
		} else {

			if (VERBOSE) NetHook::Log("Trying to init RSD ("+obj->ToString()+")");
			remote = (RemoteScriptDomain^) obj;
			remote->Initialize();

		}

#else

		remote = gcnew RemoteScriptDomain();

#endif

		//try {
		//	remote->RemoteEvent += gcnew RemoteEventHandler(this,&ScriptDomain::RemoteEvent);
		//} catchErrors("AddEvent",)

		if (VERBOSE) NetHook::Log("AppDomain created!");

		} catchErrors("Error during ScriptDomain.Create",)
	}

	void ScriptDomain::Unload() {

		try {

#ifdef USE_APPDOMAINS

		if isNULL(pAppDomain) return;

		if (VERBOSE) NetHook::Log("Destroying AppDomain...");

		bool bSuccess = false;
		while (!bSuccess) {
			try {
				System::AppDomain::Unload(pAppDomain);
				//System::GC::Collect();
				bSuccess = true;
			} catch (CannotUnloadAppDomainException^) {
				//
			} catchErrors("Error while unloading AppDomain", bSuccess = true; );
		}
		pAppDomain = nullptr;
		remote = nullptr;

		ContentCache::RemoveAll(true);

		System::GC::Collect();

#else

		remote = nullptr;
		System::GC::Collect();

#endif


		if (VERBOSE) NetHook::Log("AppDomain destroyed!");

		} catchErrors("Error during ScriptDomain.Unload",)
	}

	int ScriptDomain::LoadedScriptCount::get() {
		if isNULL(remote) return 0;
		return remote->LoadedScriptCount;
	}
	int ScriptDomain::RunningScriptCount::get() {
		if isNULL(remote) return 0;
		return remote->RunningScriptCount;
	}
	int ScriptDomain::TotalScriptFormCount::get() {
		if isNULL(remote) return 0;
		return remote->TotalScriptFormCount;
	}
	array<String^>^ ScriptDomain::GetLoadedScriptNames() {
		if isNULL(remote) return gcnew array<String^>(0);
		return remote->GetLoadedScriptNames();
	}
	array<String^>^ ScriptDomain::GetRunningScriptNames() {
		if isNULL(remote) return gcnew array<String^>(0);
		return remote->GetRunningScriptNames();
	}

	//void ScriptDomain::PrintScriptHelp() {
	//	if isNULL(remote) 
	//		NetHook::Console->Print("No scripts running!");
	//	else
	//		remote->PrintScriptHelp();
	//}

	bool ScriptDomain::LoadScripts() {
		if isNULL(remote) return false;
		//LocalMutex->WaitOne();
		//try {
			return remote->LoadScripts();
		//} finally {	LocalMutex->ReleaseMutex(); }
	}
	bool ScriptDomain::WaitForScriptsToAbort(int timeout) {
		if isNULL(remote) return true;
		return remote->WaitForScriptsToAbort(timeout);
	}

	void ScriptDomain::SendScriptCommand(Guid ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter) {
		if isNULL(remote) return;
		remote->SendScriptCommand(nullptr,ScriptGUID, Command, Parameter);
	}
	bool ScriptDomain::isScriptRunning(Guid GUID) {
		if isNULL(remote) return false;
		return remote->isScriptRunning(GUID);
	}

	void ScriptDomain::ProcessRemoteEvents() {
		if isNULL(remote) return;
		RemoteEventArgs^ rev = remote->GetNextRemoteEvent(); //GetNextRemoteEvent(); //NextRemoteEvent;
		while isNotNULL(rev) {
			RemoteEvent(rev);
			rev = remote->GetNextRemoteEvent();
		}
	}
	void ScriptDomain::ProcessDrawingRemoteEvents() {
		//if isNULL(remote) return;
		//RemoteEventArgs^ rev = remote->GetNextDrawingRemoteEvent(); //GetNextDrawingRemoteEvent //GetNextRemoteEvent(); //NextRemoteEvent;
		//while isNotNULL(rev) {
		//	RemoteEvent(rev);
		//	rev = remote->GetNextDrawingRemoteEvent(); //GetNextDrawingRemoteEvent
		//}
		array<RemoteEventArgs^>^ ary = remote->GetDrawingEventList();
		if isNULL(ary) return;
		for (int i = 0; i < ary->Length; i++) {
			RemoteEvent(ary[i]);
		}
	}
	//void ScriptDomain::ProcessAnyRemoteEvents() {
	//	if isNULL(remote) return;
	//	RemoteEventArgs^ rev = remote->GetAnyNextRemoteEvent();
	//	while isNotNULL(rev) {
	//		RemoteEvent(rev);
	//		rev = remote->GetAnyNextRemoteEvent();
	//	}
	//}

	void ScriptDomain::TriggerEvent(ScriptEvent Event, EventArgs^ args) {
		if isNULL(remote) return;
		remote->TriggerEvent(Event,args);
	}

	void ScriptDomain::RequestAction(ScriptAction action) {
		if isNULL(remote) return;
		//LocalMutex->WaitOne();
		//try {
			remote->RequestAction(action);
		//} finally {	LocalMutex->ReleaseMutex(); }
	}

	void ScriptDomain::Tick() {
		if isNULL(remote) return;
		pRemoteEventsPerFrame = pRemoteEventsPerFrameCurrent;
		pRemoteEventsPerFrameCurrent = 0;
		//LocalMutex->WaitOne();
		//try {
			remote->SetInfos(NetHook::Console->isActive, NetHook::Mouse->Enabled, NetHook::Mouse->Position, NetHook::Mouse->Movement, NetHook::Mouse->PressedButtons, NetHook::FormHost->FormCount);
			remote->InitFrame();
			//ProcessRemoteEvents();
			//if (VERBOSE) NetHook::Log("Trigger remote Tick");

			//while(remote->RunPreScriptChecksThreadTick()) {
			//	ProcessRemoteEvents();
			//}
			while(remote->RunRemoteProcessingThreadTick()) {
				ProcessRemoteEvents();
			}

			for (int i = remote->RunningThreadCount - 1; i >= 0; i--) {
				while(remote->RunThreadTick(i)) {
					ProcessRemoteEvents();
				}
			}

			remote->PerFrameScriptDrawing();
			//if (VERBOSE) NetHook::Log("Remote Tick ends");
		//} finally {	LocalMutex->ReleaseMutex(); }
	}

	void ScriptDomain::PerFrameDrawing() {
		if isNULL(remote) return;
		//LocalMutex->WaitOne();
		//try {
			remote->SetInfos(NetHook::Console->isActive, NetHook::Mouse->Enabled, NetHook::Mouse->Position, NetHook::Mouse->Movement, NetHook::Mouse->PressedButtons, NetHook::FormHost->FormCount);
			//remote->PerFrameDrawing();
			//ProcessDrawingRemoteEvents();
			//if (VERBOSE) NetHook::Log("Trigger remote RenderThread");
			while(remote->RunRenderThreadTick()) {
				ProcessRemoteEvents(); //ProcessAnyRemoteEvents(); //ProcessDrawingRemoteEvents
			}
			ProcessDrawingRemoteEvents();

			//if (VERBOSE) NetHook::Log("Remote RenderThread finished");
		//} finally {	LocalMutex->ReleaseMutex(); }
	}

	void ScriptDomain::ScheduleForRemoteProcessingThread(RemoteProcessingTask Task, ... array<System::Object^>^ Arguments) {
		if isNULL(remote) return;
		remote->ScheduleForRemoteProcessingThread(Task, Arguments);
	}


	String^ GetTypeName(System::Object^ o) {
		if isNULL(o) return "NULL";
		return o->GetType()->FullName;
	}

	void ScriptDomain::RemoteEvent(RemoteEventArgs^ ev) {
		try {
			pRemoteEventsPerFrameCurrent++;

			//NetHook::Log("RemoteEvent: " + ev->EventID.ToString());
			remote->BeforeRemoteEvent();
			switch (ev->EventID) {

				case RemoteEvent::NativeCall: { // fully managed
					if (ev->ArgumentCount != 1) return;
					try {
						GTA::Native::Template^ t = (GTA::Native::Template^)ev->Argument(0);
						remote->LastRemoteEventResult = t->Invoke();
						remote->SyncBackNativeCall(t);
					} catch(System::AccessViolationException^) {
						remote->LastRemoteEventError = "System.AccessViolationException: Attempted to read or write protected memory";
					}
					break;
				}
				case RemoteEvent::NativeInvoke: { // unmanaged C++
					if (ev->ArgumentCount != 3) return;
					try {
						unmanaged::NativeContext3* cxt = GTA::Native::Function::cxt3;
						unmanaged::NativeContext3::Invoke((int)ev->Argument(0),(array<Byte>^)ev->Argument(1),(int)ev->Argument(2),cxt);
						remote->LastRemoteEventResult = cxt->GetResult<int>();
					} catch(System::AccessViolationException^) {
						remote->LastRemoteEventError = "System.AccessViolationException: Attempted to read or write protected memory";
					}
					break;
				}
				case RemoteEvent::DrawPolygons: {
					if (ev->ArgumentCount != 3) return;
					if (ev->Argument(0)->GetType() == array<VertexFormats::TransformedColored>::typeid)
						Direct3D::DrawPolygons((array<VertexFormats::TransformedColored>^)ev->Argument(0), (array<int>^)ev->Argument(1), (int)ev->Argument(2));
					if (ev->Argument(0)->GetType() == array<VertexFormats::TransformedColoredTextured>::typeid)
						Direct3D::DrawPolygons((array<VertexFormats::TransformedColoredTextured>^)ev->Argument(0), (array<int>^)ev->Argument(1), (int)ev->Argument(2));
					break;
				}
				case RemoteEvent::DrawString: {
					if (ev->ArgumentCount != 5) return;
					//NetHook::Log( "DrawString types: " + GetTypeName(ev->Argument(0)) + ", " + GetTypeName(ev->Argument(1)) + ", " + GetTypeName(ev->Argument(2)) + ", " + GetTypeName(ev->Argument(3)) + ", " + GetTypeName(ev->Argument(4)) );
					//GetTypeName(ev->Argument(0)); GetTypeName(ev->Argument(1)); GetTypeName(ev->Argument(2)); GetTypeName(ev->Argument(3)); GetTypeName(ev->Argument(4)); // FIX for a strange NullReferenceException bug!
					//try {
					Direct3D::DrawString((String^)ev->Argument(0), (Drawing::Rectangle)ev->Argument(1), (TextAlignment)ev->Argument(2), (int)ev->Argument(3), (int)ev->Argument(4));
					//} catchErrors ("Error in RemoteEvent.DrawString with args: " + GetTypeName(ev->Argument(0)) + ", " + GetTypeName(ev->Argument(1)) + ", " + GetTypeName(ev->Argument(2)) + ", " + GetTypeName(ev->Argument(3)) + ", " + GetTypeName(ev->Argument(4)) ,)
					break;
				}
				//case RemoteEvent::TransformFromObjectToScreen: {
				//	if (ev->ArgumentCount != 2) return;
				//	remote->LastRemoteEventResult = Direct3D::TransformFromObjectToScreen((GTA::Vector3)ev->Argument(0), (GTA::Matrix)ev->Argument(1));
				//	break;
				//}
				case RemoteEvent::DisplayText: {
					NetHook::DisplayText((String^)ev->Argument(0),(int)ev->Argument(1));
					break;
				}

				case RemoteEvent::GetValidPedHandles: {
					if (ev->ArgumentCount != 1) return;
					remote->LastRemoteEventResult = World::GetValidPedHandles((GTA::Model)ev->Argument(0));
					break;
				}
				case RemoteEvent::GetValidVehicleHandles: {
					if (ev->ArgumentCount != 1) return;
					remote->LastRemoteEventResult = World::GetValidVehicleHandles((GTA::Model)ev->Argument(0));
					break;
				}
				case RemoteEvent::GetValidObjectHandles: {
					if (ev->ArgumentCount != 1) return;
					remote->LastRemoteEventResult = World::GetValidObjectHandles((GTA::Model)ev->Argument(0));
					break;
				}
				//case RemoteEvent::GetPeds: {
				//	if (ev->ArgumentCount != 3) return;
				//	remote->LastRemoteEventResult = World::GetPeds((GTA::Vector3)ev->Argument(0),(float)ev->Argument(1),(int)ev->Argument(2));
				//	break;
				//}
				//case RemoteEvent::GetAllPeds: {
				//	remote->LastRemoteEventResult = World::GetAllPeds();
				//	break;
				//}

				//case RemoteEvent::GetVehicles: {
				//	if (ev->ArgumentCount != 3) return;
				//	remote->LastRemoteEventResult = World::GetVehicles((GTA::Vector3)ev->Argument(0),(float)ev->Argument(1),(GTA::Model)ev->Argument(2));
				//	break;
				//}
				//case RemoteEvent::GetAllVehicles: {
				//	if (ev->ArgumentCount != 1) return;
				//	remote->LastRemoteEventResult = World::GetAllVehicles((GTA::Model)ev->Argument(0));
				//	break;
				//}

				//case RemoteEvent::GetAllObjects: {
				//	if (ev->ArgumentCount != 1) return;
				//	remote->LastRemoteEventResult = World::GetAllObjects((GTA::Model)ev->Argument(0));
				//	break;
				//}

				case RemoteEvent::ConsoleEvent: {
					if (ev->ArgumentCount == 0) return;
					String^ cmd = ev->Argument(0)->ToString()->ToLower();
					if (cmd == "isactive")
						remote->LastRemoteEventResult = NetHook::Console->isActive;
					else if (cmd == "open")
						if (ev->ArgumentCount > 1) 
							NetHook::Console->Open((String^)ev->Argument(1));
						else
							NetHook::Console->Open();
					else if (cmd == "close")
						NetHook::Console->Close();
					else if (cmd == "print")
						NetHook::Console->Print((String^)ev->Argument(1));
					else if (cmd == "sendcommand")
						NetHook::Console->SendCommand((String^)ev->Argument(1));
					break;
				}
				case RemoteEvent::SetMouseEnabled: {
					if (ev->ArgumentCount == 1) {
						NetHook::Mouse->Enabled = (bool)ev->Argument(0);
					}
					remote->LastRemoteEventResult = NetHook::Mouse->Enabled;
					break;
				}
				case RemoteEvent::TryToDisableMouse: {
					NetHook::TryToDisableMouse();
					break;
				}

				case RemoteEvent::GetGlobalInteger: {
					if (ev->ArgumentCount < 1) return;
					remote->LastRemoteEventResult = unmanaged::MemoryAccess::GetGlobalInteger((int)ev->Argument(0));
					break;
				}
				case RemoteEvent::GetGlobalFloat: {
					if (ev->ArgumentCount < 1) return;
					remote->LastRemoteEventResult = unmanaged::MemoryAccess::GetGlobalFloat((int)ev->Argument(0));
					break;
				}
				case RemoteEvent::GetVehicleRPM: {
					if (ev->ArgumentCount < 1) return;
					remote->LastRemoteEventResult = unmanaged::MemoryAccess::GetVehicleRPM((int)ev->Argument(0));
					break;
				}

				case RemoteEvent::AddNewDirect3DObject: {
					if (ev->ArgumentCount != 1) return; //10
					remote->LastRemoteEventResult = (System::Object^)(-1);
					//int res = Direct3D::NewFont((int)ev->Argument(0), (int)ev->Argument(1), (int)ev->Argument(2), (int)ev->Argument(3), (bool)ev->Argument(4), (int)ev->Argument(5), (int)ev->Argument(6), (int)ev->Argument(7), (int)ev->Argument(8), (String^)ev->Argument(9));
					int res = Direct3D::AddNewObject((GTA::base::iD3DObject^)ev->Argument(0));
					remote->LastRemoteEventResult = res;
					break;
				}
			}
		} //catchErrors("Error during RemoteEvent '"+ev->EventID.ToString()+"' in script '"+remote->CurrentScriptName+"'", remote->LastRemoteEventError = true; )
		catch(System::Exception^ ex) { 
			if isNotNULL(ex)
				remote->LastRemoteEventError = ex->ToString();
			else
				remote->LastRemoteEventError = "UNKNOWN ERROR";
		} catch(...) {
			remote->LastRemoteEventError = "UNKNOWN ERROR";
		} 
	}

}