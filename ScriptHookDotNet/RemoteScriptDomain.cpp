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

#include "RemoteScriptDomain.h"

#include "ContentCache.h"
#include "Game.h"
#include "Graphics.h"
#include "NetThread.h"
#include "GenericThread.h"
#include "RemoteProcessing.h"
#include "ScriptThread.h"
#include "Script.h"
#include "fFormHost.h"
#include "fMouse.h"
#include "nParameter.h"
#include "nTemplate.h"

#pragma managed

namespace GTA {

	// PRIVATE:

	RemoteScriptDomain::RemoteScriptDomain() {
		pGraphics = gcnew GTA::Graphics();
		scriptTypeList = gcnew List<FoundScript>();
		scriptList = gcnew List<GTA::Script^>();
		scriptThreadList = gcnew List<GTA::ScriptThread^>();
		pFormHost = gcnew GTA::Forms::FormHost(nullptr);
		RemoteEventList = gcnew List<GTA::RemoteEventArgs^>();
		RemoteEventListDrawing = gcnew List<GTA::RemoteEventArgs^>();
		pRenderThread = gcnew GenericThread(this, gcnew SomeFunction(this, &RemoteScriptDomain::PerFrameDrawing), "RenderThread");
		pRenderThread->Launch();
		pState = ScriptState::Empty;
		pAction = ScriptAction::Idle;
		bConsoleActive = false;
		bDrawing = false;
		FrameNum = 1;
	}

	void RemoteScriptDomain::Initialize() {
		pInstance = this;
		//this->LocalScriptDomain = localScriptDomain;

#ifdef USE_APPDOMAINS

		NetHook::Initialize(false, 0);
		AppDomain::CurrentDomain->AssemblyResolve += gcnew ResolveEventHandler(&MyResolveEventHandler);
		AppDomain::CurrentDomain->UnhandledException += gcnew UnhandledExceptionEventHandler(&CatchUnhandledExceptions);

#endif

		if (VERBOSE) NetHook::Log("RemoteScriptDomain for AppDomain '"+AppDomain::CurrentDomain->FriendlyName+"' initialized!");
	}

	void RemoteScriptDomain::CatchUnhandledExceptions(System::Object^ sender, UnhandledExceptionEventArgs^ args) {
		try {
			NetHook::Log("Unhandled Exception: " + args->ExceptionObject->ToString());
			if (args->IsTerminating) NetHook::Log("CRASH!");
		} catchErrors("Unhandled Exception",)
	}

	Assembly^ RemoteScriptDomain::MyResolveEventHandler(System::Object^ sender, ResolveEventArgs^ args) {
		AppDomain^ domain = dynamic_cast<AppDomain^>(sender);
		if (args->Name->ToLower()->Contains("scripthookdotnet")) {
			if (VERBOSE) NetHook::Log("D! Successfully resolved '" + args->Name + "' for domain '"+domain->FriendlyName+"'!");
			return Assembly::GetAssembly(GTA::Script::typeid);
		}
		if (VERBOSE) NetHook::Log("D! Failed to resolve Assembly '" + args->Name + "' for domain '"+domain->FriendlyName+"'!");
		return nullptr;
   }

	bool RemoteScriptDomain::LoadScripts() {
		if (((pState != ScriptState::Empty) && (pState != ScriptState::NoneFound)) || (LoadedScriptCount > 0)) { //RemoveAllScripts();
			NetHook::Log("Unable to load scripts now. Remove all currently loaded scripts first!");
			return false;
		}

		NetHook::Log("SEARCHING FOR SCRIPTS...",true,false);
		ChangeState(ScriptState::Loading);

		String^ gamepath = Game::InstallFolder; //System::Windows::Forms::Application::StartupPath;
		String^ scriptpath = String::Concat(gamepath,"\\scripts");
		String^ pluginpath = String::Concat(gamepath,"\\plugins");

		LoadAssemblies(pluginpath,"*.net");
		LoadAssemblies(pluginpath,"*.net.dll");
		//LoadAssemblies(scriptpath,"*.dll");
		LoadAssemblies(scriptpath,"*.net");
		LoadAssemblies(scriptpath,"*.net.dll");
		LoadDynamics(scriptpath,"*.vb");
		LoadDynamics(scriptpath,"*.cs");

		if (scriptTypeList->Count == 0) {
			//System::Windows::Forms::MessageBox::Show("No DotNet Script loaded!","Warning");
			NetHook::Log( "DONE! No DotNet script found!" );
			//if (VERBOSE) {
			//	System::Windows::Forms::MessageBox::Show("No scripts loaded!");
			//	Terminate();
			//}
			ChangeState(ScriptState::NoneFound);
			return false;
		} else {
			NetHook::Log( String::Concat("DONE! ", scriptTypeList->Count, " valid scripts found!") );
			ChangeState(ScriptState::Loaded);
			return true;
		}
	}

	void RemoteScriptDomain::LoadAssemblies(String^ path, String^ pattern){
		//String^ path = String::Concat(System::Windows::Forms::Application::StartupPath,"\\plugins");
		if (!System::IO::Directory::Exists(path)) return;
		array<String^>^ dlls = System::IO::Directory::GetFiles(path,pattern);
      for(int i=0; i<dlls->Length; i++){
			LoadAssembly(dlls[i]);
		}
	}

	void RemoteScriptDomain::LoadDynamics(String^ path, String^ pattern){
		if (!System::IO::Directory::Exists(path)) return;
		array<String^>^ files = System::IO::Directory::GetFiles(path,pattern);
		for(int i=0; i<files->Length; i++){
			LoadDynamicScript(files[i]);
		}
	}

	bool RemoteScriptDomain::LoadAssembly(String^ filename){
		if (filename->EndsWith(".net",StringComparison::InvariantCultureIgnoreCase)) {
		} else if (filename->EndsWith(".dll",StringComparison::InvariantCultureIgnoreCase)) {
		} else {
			return false;
		}

		Assembly^ asb;
		try {

			//asb = Assembly::LoadFrom(filename);

			System::IO::FileStream^ fs = gcnew System::IO::FileStream(filename,System::IO::FileMode::Open, System::IO::FileAccess::Read, System::IO::FileShare::Read);
			array<Byte>^ data = gcnew array<Byte>((int)fs->Length);
			fs->Read(data,0,(int)fs->Length);
			fs->Close();

			asb = Assembly::Load(data);

			//AntiGC_SourceBytes->Add(data);

		} catchErrors ("Unable to load Assembly '"+filename->Replace(Game::InstallFolder+"\\",String::Empty)+"'", return false; )

		NetHook::Log( String::Concat("Loading scripts in Assembly '", filename->Replace(Game::InstallFolder+"\\",String::Empty), "' ...") );
		return LoadAssembly(asb,filename);
	}

	bool RemoteScriptDomain::LoadDynamicScript(String^ filename){

		Dictionary<String^,String^>^ providerOptions = gcnew Dictionary<String^,String^>();
        providerOptions->Add("CompilerVersion", "v4.0");

		String^ CompilerOptions;
		CodeDomProvider^ loCompiler;
		if (filename->EndsWith(".vb",StringComparison::InvariantCultureIgnoreCase)) {
			loCompiler = gcnew Microsoft::VisualBasic::VBCodeProvider(providerOptions);
			CompilerOptions = "/optimize /optioninfer";
		} else if (filename->EndsWith(".cs",StringComparison::InvariantCultureIgnoreCase)) {
			loCompiler = gcnew Microsoft::CSharp::CSharpCodeProvider(providerOptions);
			CompilerOptions = "/optimize";
		} else {
			return false;
		}

		NetHook::Log( String::Concat("Loading dynamic scriptfile '", filename->Replace(Game::InstallFolder+"\\",String::Empty), "' ...") );

		FileStream^ fs;
		try {
			fs = gcnew System::IO::FileStream(filename,FileMode::Open,FileAccess::Read);
		} catch (...) {
			return false;
		}
		StreamReader^ sr = gcnew StreamReader(fs);
		String^ lcCode = sr->ReadToEnd();
		sr->Close();
		fs->Close();

		if (lcCode->Length == 0) return false;

		String^ myasbfile = Assembly::GetAssembly(GTA::Script::typeid)->Location;
		//Windows::Forms::MessageBox::Show(myasbfile, "Location");

		CompilerParameters^ loParameters = gcnew CompilerParameters();
		loParameters->ReferencedAssemblies->Add("System.dll");
		loParameters->ReferencedAssemblies->Add("System.Drawing.dll");
		loParameters->ReferencedAssemblies->Add("System.Windows.Forms.dll");
		loParameters->ReferencedAssemblies->Add("System.XML.dll");
		loParameters->ReferencedAssemblies->Add(myasbfile);

		loParameters->GenerateInMemory = true; //false;
		loParameters->CompilerOptions = CompilerOptions;

		CompilerResults^ loCompiled = loCompiler->CompileAssemblyFromSource(loParameters, lcCode);

		if (loCompiled->Errors->HasErrors) {
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			sb->AppendLine(String::Concat(loCompiled->Errors->Count, " Errors in script '", filename, "':"));
			for (int i = 0; i<loCompiled->Errors->Count; i++) {
				sb->AppendLine(String::Concat(" in Line ", loCompiled->Errors->default[i]->Line, ": ", loCompiled->Errors->default[i]->ErrorText));
			}
			//Windows::Forms::MessageBox::Show(sb->ToString(), "Script compile error");
			NetHook::Log(sb->ToString());
         return false;
		}
		return LoadAssembly(loCompiled->CompiledAssembly,filename);
	}

	bool RemoteScriptDomain::LoadAssembly(Assembly^ asb, String^ filename){
		int count = 0;
		array<Type^>^ containedTypes = asb->GetTypes();
		for(int i=0; i<containedTypes->Length; i++){
			System::Type^ containedType = containedTypes[i];
			if (containedType->IsSubclassOf(GTA::Script::typeid)) {
				scriptTypeList->Add(FoundScript(filename,containedType));
				NetHook::Log( String::Concat(" ...found script '", containedType->FullName, "'!") );
				count++;
			}
		}
      return (count>0);
	}

	//GTA::Script^ RemoteScriptDomain::LoadScript(System::Type^ ScriptType){
	//	GTA::Script^ scr;
	//	Object^ o;

	//	try {

	//		// IMPORTANT: Constructor runs here already
	//		o = System::Activator::CreateInstance(ScriptType);
	//		if isNULL(o) return nullptr;
	//		scr = static_cast<GTA::Script^>(o);

	//	} catch (System::Reflection::TargetInvocationException^ ex) {
	//		if ( isNULL(ex) || isNULL(ex->InnerException) ) {
	//			throw gcnew Exception();
	//			return nullptr;
	//		}
	//		throw ex->InnerException;
	//		return nullptr;
	//	} 

	//	return scr;
	//}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void RemoteScriptDomain::LaunchScriptThreads() {
		if (((pState != ScriptState::Loaded) && (pState != ScriptState::Aborted)) || (RunningScriptCount > 0)) {
			//AbortScripts();
			if (pState == ScriptState::Empty)
				NetHook::Log("No scripts to load...");
			else
				NetHook::Log("Can't launch scripts now. Abort all currently running scripts first!");
			return;
		}
		//myNativeThread = gcnew ManagerThread();
		//myNativeThread->Launch();

		//if (!Game::isModdingAllowed) {
		//	NetHook::Log( "Rejected loading of scripts in this multiplayer gamemode...");
		//	return; // Do not launch scripts in ranked MP
		//}
		//if (!bStartup) {
		//	bStartup = true;
			NetHook::Log( "STARTING SCRIPTS...", true, false );
		//}
		ChangeState(ScriptState::Starting);

		for(int i=0; i<scriptTypeList->Count; i++) {
			ScriptThread^ scr;
			try {
				scr = gcnew ScriptThread(this, scriptTypeList->default[i].Filename, scriptTypeList->default[i].Type);
				scriptThreadList->Add(scr);
				//scr->LoadScriptNow(); // create script in main thread
				scr->Launch();
			} catchErrors ("Error on thread creation for script '" + scriptTypeList->default[i].Filename + "'", if isNotNULL(scr) scriptThreadList->Remove(scr); )
		}
		ChangeState(ScriptState::Running);
	}

	void RemoteScriptDomain::RemoveRunningScript(GTA::Script^ script) {
		scriptList->Remove(script);
		scriptThreadList->Remove(script->myThread);
		if (scriptList->Count == 0) CheckState();
	}

	void RemoteScriptDomain::AbortScripts(){
		if (pState != ScriptState::Running) {
			NetHook::Log("Can't abort scripts now!");
			return;
		}
		ChangeState(ScriptState::Aborting);

		//DoGC("AbortScripts call");
		if (scriptList->Count > 0) {
			for(int i=scriptList->Count-1; i>=0; i--){
				try {

					scriptList->default[i]->Abort();
					//DoGC("abort of script " + i.ToString());

				} catchScriptErrors (scriptList->default[i], "finalization",)
			}
			//scriptList->Clear();
			//DoGC("scriptList->Clear()");
			//Log("SCRIPTS TERMINATED!");
			
		}
		//ContentCache::RemoveAll();
		
		//bStartup = false;

		//DoGC("AbortScripts");

		//try {
		//	System::GC::Collect(); 
		//} catchErrors("GC ERROR",)
	}

	void RemoteScriptDomain::RemoveAllScripts() {
		if (((pState != ScriptState::Loaded) && (pState != ScriptState::Aborted)) || (RunningScriptCount > 0)) {
			if (pState == ScriptState::Empty)
				NetHook::Log("No scripts to remove...");
			else
				NetHook::Log("Can't remove scripts now. Abort all currently running scripts first!");
			return;
		}
		//AbortScripts();
		scriptTypeList->Clear();
		ChangeState(ScriptState::Empty);
		//try {
		//	System::GC::Collect(); 
		//} catchErrors("GC ERROR",)
//#ifdef USE_APPDOMAINS
//		AntiGC_Scripts->Clear();
//		AntiGC_Threads->Clear();
//		//UnloadAppDomain();
//		if isNotNULL(pScriptDomain) {
//			pScriptDomain->Unload();
//			pScriptDomain = nullptr;
//		}
//#endif
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void RemoteScriptDomain::PerFrameDrawing() {
		pCurrentScript = nullptr;
		//pCurrentThread = nullptr;
		CheckState();
		if ((pState != ScriptState::Running)) return;
		//if (isConsoleActive) return;

		pGraphics->InitFrame();
		GraphicsEventArgs^ args = gcnew GraphicsEventArgs(pGraphics);

		for(int i=0; i<scriptList->Count; i++){
			try {

				SetCurrentScript(scriptList[i]); // set it here because it is called from outside the thread, wait is blocked anyway
				pGraphics->InitScript();
				scriptList[i]->DoPerFrameDrawing(args);

			} catchScriptErrors (scriptList[i], "PerFrameDrawing", i--; )
		}
		SetCurrentScript(nullptr);
		FormHost->TriggerPaint(args);
		SetCurrentScript(nullptr);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void RemoteScriptDomain::PerFrameScriptDrawing() {
		pCurrentScript = nullptr;
		pCurrentThread = nullptr;
		CheckState();
		if ((pState != ScriptState::Running)) return;

		for(int i=0; i<scriptList->Count; i++){
			try {

				SetCurrentScript(scriptList[i]); // set it here because it is called from outside the thread, wait is blocked anyway
				scriptList[i]->DoPerFrameScriptDrawing();

			} catchScriptErrors (scriptList[i], "PerFrameScriptDrawing", i--; )
		}
		SetCurrentScript(nullptr);
	}


	// INTERNAL:

	array<String^>^ RemoteScriptDomain::GetLoadedScriptNames() {
		array<String^>^ ary = gcnew array<String^>(scriptTypeList->Count);
		for (int i = 0; i < scriptTypeList->Count; i++) {
			ary[i] = scriptTypeList->default[i].FullName;
		}
		return ary;
	}

	array<String^>^ RemoteScriptDomain::GetRunningScriptNames() {
		array<String^>^ ary = gcnew array<String^>(scriptList->Count);
		for (int i = 0; i < scriptList->Count; i++) {
			ary[i] = scriptList->default[i]->FullName;
		}
		return ary;
	}

	bool RemoteScriptDomain::WaitForScriptsToAbort(int timeout) {
		//if (!State == ScriptState::Aborting
		DateTime endtime = DateTime::Now + TimeSpan(0,0,0,0,timeout);
		while (scriptList->Count > 0) {

			for (int i = scriptList->Count-1; i >= 0; i--) {
#ifdef USE_NETTHREAD
				scriptList->default[i]->myThread->TickNow(true);
#else
				scriptList->default[i]->myThread->ForceToRun();
#endif
			}


			System::Threading::Thread::CurrentThread->Sleep(50);
			if (DateTime::Now > endtime) break;
		}
		return (scriptList->Count == 0);
	}

	void RemoteScriptDomain::ScriptError(GTA::Script^ Script, String^ CodeLocation) {
		ScriptError(Script, CodeLocation, String::Empty);
	}
	void RemoteScriptDomain::ScriptError(GTA::Script^ Script, String^ CodeLocation, String^ ErrorDetails) {
		if isNULL(Script) Script = pCurrentScript;
		String^ scriptName = String::Empty;
		if isNotNULL(Script) scriptName = " '" + Script->Name + "'";
		if (isNULL(ErrorDetails) | (ErrorDetails->Length == 0)) 
			NetHook::Log( "Error during " + CodeLocation  + " in script" + scriptName + "!" );
		else
			NetHook::Log( "Error during " + CodeLocation  + " in script" + scriptName + ":" + Environment::NewLine + ErrorDetails );
		Game::DisplayText( "Error in script" + scriptName + "!", 5000 );
		if isNotNULL(Script) scriptList->Remove(Script);
	}
	void RemoteScriptDomain::ScriptError(GTA::Script^ Script, String^ CodeLocation, Exception^ ex) {
		if isNULL(ex)
			ScriptError(Script, CodeLocation, String::Empty);
		else
			ScriptError(Script, CodeLocation, ex->ToString());
	}

	void RemoteScriptDomain::PrintScriptHelp() {
		if (scriptList->Count == 0) {
			NetHook::Console->Print("No scripts running!");
			return;
		}
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		for each (Script^ script in scriptList) {
			if ((script->GeneralInfo->Length > 0) || (script->commandlist->Count > 0)) {
				sb->AppendLine();
				sb->AppendLine(" ### " + script->Name + " ###");
				if (script->GeneralInfo->Length > 0) {
					sb->AppendLine(script->GeneralInfo);
				}
				if (script->commandlist->Count > 0) {
					sb->AppendLine();
					sb->AppendLine("Commands:");
					for (int i = 0; i < script->commandlist->Count; i++) {
						sb->AppendLine("   " + script->commandlist->default[i].CommandPretty + " " + script->commandlist->default[i].HelpText);
					}
				}
			}
		}
		NetHook::Console->Print(sb->ToString());
	}

	// PUBLIC:

	void RemoteScriptDomain::SetInfos(bool isConsoleActive, bool MouseEnabled, Drawing::PointF MousePosition, Drawing::PointF MouseMovement, System::Windows::Forms::MouseButtons MouseButtons, int LocalOpenFormsCount) {
		bConsoleActive = isConsoleActive;
		if isNotNULL(NetHook::Mouse) ((GTA::Forms::RemoteMouse^)NetHook::Mouse)->SetValues(MouseEnabled, MousePosition, MouseMovement, MouseButtons);
		pOpenFormsCount = LocalOpenFormsCount + TotalScriptFormCount;
	}

	void RemoteScriptDomain::InitFrame() {
		FrameNum++;
	}

	String^ RemoteScriptDomain::CurrentScriptName::get() {
		if isNULL(pCurrentScript) return String::Empty;
		return pCurrentScript->Name;
	}

	int RemoteScriptDomain::TotalScriptFormCount::get() {
		//int count = 0;
		//for(int i = 0; i<scriptList->Count; i++) {
		//	count += scriptList[i]->FormHost->FormCount;
		//}
		//return count;
		return FormHost->FormCount;
	}
	int RemoteScriptDomain::TotalOverallFormCount::get() {
		return pOpenFormsCount;
	}

	void RemoteScriptDomain::TriggerEvent(ScriptEvent Event, EventArgs^ args) {
		DateTime time = DateTime::Now;
		for(int i = 0; i<scriptList->Count; i++) {
			scriptList[i]->AddEvent(Event,args,time);
		}
	}

	// called from ScriptDomain
	bool RemoteScriptDomain::RunThreadTick(int ThreadID) {
		pCurrentThread = scriptThreadList->default[ThreadID];
		bool WaitForCommand = pCurrentThread->TickNowWithState();
		if (!WaitForCommand) pCurrentThread = nullptr;
		return WaitForCommand;
	}
	// called from ScriptDomain
	void RemoteScriptDomain::SetThreadActive(int ThreadID) {
		if (ThreadID >= 0)
			pCurrentThread = scriptThreadList->default[ThreadID];
		else
			pCurrentThread = nullptr;
	}

	// called from ScriptDomain
	bool RemoteScriptDomain::RunRenderThreadTick() {
		bDrawing = true;
		pCurrentThread = pRenderThread;
		bool WaitForCommand = pCurrentThread->TickNowWithState();
		if (!WaitForCommand) pCurrentThread = nullptr;
		bDrawing = false;
		return WaitForCommand;
	}

	void RemoteScriptDomain::RaiseEventInLocalScriptDomain(RemoteEvent EventID, ... array<System::Object^>^ Arguments) {
		if (EventID < RemoteEvent::DRAWING_EVENTS) {
			RemoteEventList->Add(gcnew RemoteEventArgs(EventID, Arguments));
			LogCount(RemoteEventList,"RemoteEventList",50);
		} else {
			if (!bDrawing) throw gcnew Exception("Invalid call to " + EventID.ToString() + " from outside PerFrameDrawing!");
			RemoteEventListDrawing->Add(gcnew RemoteEventArgs(EventID, Arguments));
			LogCount(RemoteEventListDrawing,"RemoteEventListDrawing",500);
		}
		if isNotNULL(CurrentThread) { //CurrentScript
			//NextRemoteEvent = gcnew RemoteEventArgs(EventName, Arguments);
			//NetHook::Log("Waiting for RemoteEvent " + EventID.ToString() + "...");
			CurrentThread->WaitForCommandResult(); //CurrentScript->myThread
			if isNotNULL(LastRemoteEventError) throw gcnew Exception("RemoteEvent '"+EventID.ToString()+"' threw a " + LastRemoteEventError);
		}
	}
	RemoteEventArgs^ RemoteScriptDomain::GetNextRemoteEvent() {
		if (RemoteEventList->Count == 0) return nullptr;
		LastRemoteEvent = RemoteEventList->default[0];
		RemoteEventList->RemoveAt(0);
		return LastRemoteEvent;
	}
	array<RemoteEventArgs^>^ RemoteScriptDomain::GetDrawingEventList() {
		if (RemoteEventListDrawing->Count == 0) return nullptr;
		array<RemoteEventArgs^>^ ary = RemoteEventListDrawing->ToArray();
		RemoteEventListDrawing->Clear();
		return ary;
	}
	//RemoteEventArgs^ RemoteScriptDomain::GetNextDrawingRemoteEvent() {
	//	if (RemoteEventListDrawing->Count == 0) return nullptr;
	//	LastRemoteEvent = RemoteEventListDrawing->default[0];
	//	RemoteEventListDrawing->RemoveAt(0);
	//	return LastRemoteEvent;
	//}
	//RemoteEventArgs^ RemoteScriptDomain::GetAnyNextRemoteEvent() {
	//	if (RemoteEventListDrawing->Count > 0) {
	//		LastRemoteEvent = RemoteEventListDrawing->default[0];
	//		RemoteEventListDrawing->RemoveAt(0);
	//		return LastRemoteEvent;
	//	}
	//	if (RemoteEventList->Count > 0) {
	//		LastRemoteEvent = RemoteEventList->default[0];
	//		RemoteEventList->RemoveAt(0);
	//		return LastRemoteEvent;
	//	}
	//	return nullptr;
	//}
	void RemoteScriptDomain::BeforeRemoteEvent() {
		LastRemoteEventResult = nullptr;
		LastRemoteEventError = nullptr;
	}


	void RemoteScriptDomain::ScheduleForRemoteProcessingThread(RemoteProcessingTask Task, ... array<System::Object^>^ Arguments) {
		//RemoteProcessingThreadList->Add(gcnew RemoteEventArgs((RemoteEvent)Task, Arguments));
		RemoteProcessing::ScheduleTask(Task, Arguments);
	}
	// called from ScriptDomain
	bool RemoteScriptDomain::RunRemoteProcessingThreadTick() {
		pCurrentThread = RemoteProcessing::Thread;
		bool WaitForCommand = pCurrentThread->TickNowWithState();
		if (!WaitForCommand) pCurrentThread = nullptr;
		return WaitForCommand;
	}
	//void RemoteScriptDomain::ProcessRemoteProcessingTasks() {
	//}

	//bool RemoteScriptDomain::RunPreScriptChecksThreadTick() {
	//	pCurrentThread = PreScriptChecks::Thread;
	//	bool WaitForCommand = pCurrentThread->TickNowWithState();
	//	if (!WaitForCommand) pCurrentThread = nullptr;
	//	return WaitForCommand;
	//}

	void RemoteScriptDomain::SyncBackNativeCall(GTA::Native::Template^ result) {
		if (isNULL(result) || isNULL(LastRemoteEvent) || (LastRemoteEvent->Argument(0)->GetType() != GTA::Native::Template::typeid)) return;
		GTA::Native::Template^ t = (GTA::Native::Template^)LastRemoteEvent->Argument(0);
		if ((t->Name != result->Name) || (t->ArgumentCount != result->ArgumentCount)) return;
		for (int i = 0; i < result->ArgumentCount; i++) {
			t->Argument(i)->pData = result->Argument(i)->pData;
		}
	}

	Script^ RemoteScriptDomain::GetScript(Guid GUID) {
		for (int i = 0; i < scriptList->Count; i++) {
			if (scriptList->default[i]->GUID == GUID) return scriptList->default[i];
		}
		return nullptr;
	}

	void RemoteScriptDomain::SendScriptCommand(GTA::Script^ sender, GTA::Script^ TargetScript, String^ Command, ... array<System::Object^>^ Parameter) {
		TargetScript->AddEvent(ScriptEvent::ScriptCommand, gcnew ScriptCommandEventArgs(sender, Command, Parameter), DateTime::Now);
	}
	void RemoteScriptDomain::SendScriptCommand(GTA::Script^ sender, Guid TargetScriptGUID, String^ Command, ... array<System::Object^>^ Parameter) {
		if (TargetScriptGUID == Guid()) return;
		Script^ trg = GetScript(TargetScriptGUID);
		if isNULL(trg) return;
		SendScriptCommand(sender,trg,Command,Parameter);
	}


	// ##### STATE MANAGER #####

	void RemoteScriptDomain::ChangeState(ScriptState state) {
		pState = state;
		if (VERBOSE) NetHook::Log("State changed: " + state.ToString());

		switch (pAction) {

			case ScriptAction::LoadScripts:
				switch (state) {

					case ScriptState::Empty:
						LoadScripts();
						return;

					case ScriptState::Aborted:
					case ScriptState::Loaded:
					case ScriptState::NoneFound:
					case ScriptState::Running:
						RequestAction(ScriptAction::Idle);
						return;
			}

			case ScriptAction::RestartScripts:
			case ScriptAction::StartScripts:
				switch (state) {

					case ScriptState::Empty:
						LoadScripts();
						return;

					case ScriptState::Aborted:
					case ScriptState::Loaded:
						LaunchScriptThreads();
						return;

					case ScriptState::NoneFound:
					case ScriptState::Running:
						RequestAction(ScriptAction::Idle);
						return;
			}

			case ScriptAction::AbortScripts:
				switch (state) {

					case ScriptState::Running:
						AbortScripts();
						return;

					case ScriptState::Aborted:
					case ScriptState::Loaded:
					case ScriptState::Empty:
					case ScriptState::NoneFound:
						RequestAction(ScriptAction::Idle);
						return;
			}

			case ScriptAction::RemoveAllScripts:
				switch (state) {

					case ScriptState::Running:
						AbortScripts();
						return;

					case ScriptState::Aborted:
					case ScriptState::Loaded:
						RemoveAllScripts();
						return;
					
					case ScriptState::Empty:
					case ScriptState::NoneFound:
						RequestAction(ScriptAction::Idle);
						return;
			}

			case ScriptAction::ReloadAndStartScripts:
				switch (state) {

					case ScriptState::Aborted:
						RemoveAllScripts();
						return;

					case ScriptState::Empty:
						LoadScripts();
						return;

					case ScriptState::Loaded:
						LaunchScriptThreads();
						return;

					case ScriptState::NoneFound:
					case ScriptState::Running:
						RequestAction(ScriptAction::Idle);
						return;
			}

		}
	}

	void RemoteScriptDomain::RequestAction(ScriptAction action) {
		if (VERBOSE) NetHook::Log("Action requested: " + action.ToString());

		pAction = action;
		switch (action) {

			case ScriptAction::LoadScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					LoadScripts();
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					pAction = ScriptAction::Idle;
					return;
				} else {
					pAction = ScriptAction::Idle;
					return;
				}
				return;

			case ScriptAction::StartScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					LoadScripts();
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					LaunchScriptThreads();
					return;
				} else if (pState == ScriptState::Running) {
					pAction = ScriptAction::Idle;
					return;
				} else {
					NetHook::Log("Can't start scripts now!");
					pAction = ScriptAction::Idle;
					return;
				}
				return;

			case ScriptAction::RestartScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					LoadScripts();
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					LaunchScriptThreads();
					return;
				} else if (pState == ScriptState::Running) {
					AbortScripts();
					return;
				} else {
					NetHook::Log("Can't restart scripts now!");
					pAction = ScriptAction::Idle;
					return;
				}
				return;

			case ScriptAction::AbortScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					pAction = ScriptAction::Idle;
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					pAction = ScriptAction::Idle;
					return;
				} else if (pState == ScriptState::Running) {
					AbortScripts();
					return;
				} else {
					NetHook::Log("Can't abort scripts now!");
					pAction = ScriptAction::Idle;
					return;
				}
				return;

			case ScriptAction::RemoveAllScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					pAction = ScriptAction::Idle;
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					RemoveAllScripts();
					return;
				} else if (pState == ScriptState::Running) {
					AbortScripts();
					return;
				} else {
					NetHook::Log("Can't remove scripts now!");
					pAction = ScriptAction::Idle;
					return;
				}
				return;

			case ScriptAction::ReloadAndStartScripts:
				if ((pState == ScriptState::Empty) || (pState == ScriptState::NoneFound)) {
					LoadScripts();
					return;
				} else if ((pState == ScriptState::Loaded) || (pState == ScriptState::Aborted)) {
					RemoveAllScripts();
					return;
				} else if (pState == ScriptState::Running) {
					AbortScripts();
					return;
				} else {
					NetHook::Log("Can't reload scripts now!");
					pAction = ScriptAction::Idle;
					return;
				}
				return;

		}
	}

	void RemoteScriptDomain::CheckState() {
		switch (pState) {

			case ScriptState::Aborting:
				if (scriptList->Count == 0) {
					ContentCache::RemoveAll(true);
					scriptThreadList->Clear();
					//ThreadManager::RemoveThreads();
					NetHook::Log("SCRIPTS TERMINATED!");
					ChangeState(ScriptState::Aborted);
				}
				return;

		}
	}

	// ##### STATE MANAGER END #####

}