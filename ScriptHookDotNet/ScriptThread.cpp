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
#include "NetThread.h"

#include "ScriptThread.h"

#include "RemoteScriptDomain.h"
#include "Script.h"

namespace GTA {

#ifdef USE_NETTHREAD
	ScriptThread::ScriptThread(RemoteScriptDomain^ domain, String^ scriptFile, System::Type^ scriptType) {
#else
	ScriptThread::ScriptThread(RemoteScriptDomain^ domain, String^ scriptFile, System::Type^ scriptType)
		:IngameThread(true) {
#endif
		//SetName("CustomFiberThread");
		//GTA::NetHook::LoadScripts();
		this->domain = domain;
		this->scriptFile = scriptFile;
		this->scriptType = scriptType;
	}

	//ScriptThread::~ScriptThread() {
	//	this->!ScriptThread();
	//}
	//ScriptThread::!ScriptThread() {
	//	if isNotNULL(scriptType) {
	//		LogFin(scriptType->ToString());
	//		//delete scriptType;
	//		scriptType = nullptr;
	//	}
	//	if isNotNULL(script) {
	//		//delete script;
	//		script = nullptr;
	//	}
	//}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool ScriptThread::LoadScriptNow() {
			//if (!Game::isModdingAllowed) {
			//	GTA::NetHook::Log(String::Concat( "Rejected start of script '", scriptType->FullName, "' in this multiplayer gamemode!" ));
			//	//GTA::NetHook::DisplayText(String::Concat( "DO NOT USE MODS/SCRIPTS IN RANKED MULTIPLAYER GAMES!" ), 10000 );
			//	//Abort();
			//	return false ;
			//}

			currentlyLoading = this;
			if (VERBOSE) GTA::NetHook::Log(String::Concat( "Constructing script '", scriptType->FullName, "'..." ));

			try {

				if isNULL(scriptType) return false;
				// IMPORTANT: Constructor runs here already
				System::Object^ o = System::Activator::CreateInstance(scriptType);
				if isNULL(o) return false;

				script = static_cast<GTA::Script^>(o); //domain->LoadScript(scriptType);
				if isNotNULL(script) {
					script->Initialize(this);
					//if (VERBOSE) GTA::NetHook::Log(String::Concat( " ...successfully constructed script '", script->Name, "'!" ));
					return true;
				} else {
					//bError = true;
					return false;
				}

			} catch (System::InvalidOperationException^) {
				//Object::ReferenceEquals(ex,nullptr); // just a dummy to get rid of the warning
				//bError = true;
				return false;

			} catch (System::Reflection::TargetInvocationException^ ex) {
				try {
					if ( isNULL(ex) || isNULL(ex->InnerException) ) {
						throw gcnew Exception();
						return false;
					}
					throw ex->InnerException;
				//} catch (System::MissingMethodException^ ex) {
				//		if (ex->ToString()->Contains("GTA.value.ScriptSettings GTA.Script.get_Settings()")) continue;
				} catchErrors ("Error in constructor of script '"+scriptType->FullName+"'",  )
				return false;

			} catchErrors ("Error during construction of script '"+scriptType->FullName+"'",  ) //bError = true;
			return false;
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void ScriptThread::OnStartup() {
		bool bError = false;

		//lock(syncroot) {

			bError = !LoadScriptNow();
			//bError = isNULL(script);

			if (!bError) {
				//if (!GTA::NetHook::RunScript(script)) bError = true;
				try {
					//if (VERBOSE) GTA::NetHook::Log(String::Concat( " ...starting script '", script->Name, "'..." ));

					domain->SetCurrentScript(script); // we have to set it here again, because script was still Nothing at startup
					script->DoStartup();
					domain->AddRunningScript(script);
					GTA::NetHook::Log(String::Concat( " ...successfully started script '", script->Name, "'!" ));

				} catchScriptErrors (script, "Startup", bError = true; )
			}

			if (bError) {
				GTA::NetHook::DisplayText( String::Concat("Error in script '", scriptType->FullName, "'!"), 5000 );
				if isNotNULL(script) script->myThread = nullptr;
				Abort();
			}


		//} unlock(syncroot);

		//script = GTA::NetHook::RunScript(scriptType);
		//if(script != nullptr) {
		//	script->myThread = this;
		//} else {
		//	Abort();
		//}
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void ScriptThread::OnTick() {
		//lock(syncroot) {

			if ( isNULL(script) || (!script->isRunning) ) {
				//Abort();
				return;
			}

			try {

				script->DoTick();

			} catch (System::Threading::ThreadAbortException^ taex) {
				throw taex;
			} catchScriptErrors (script, "Tick", if isNotNULL(script) script->Abort(); )



		//} unlock(syncroot);
	}

	void ScriptThread::OnThreadContinue() {
		domain->SetCurrentScript(script);
	}
	void ScriptThread::OnThreadHalt() {
		//RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain("ThreadHalt",nullptr);
		domain->SetCurrentScript(nullptr);
	}

	void ScriptThread::OnEnd() {
		if isNotNULL(script) {
			if (VERBOSE) NetHook::Log("Script ended: " + script->Name);
			domain->RemoveRunningScript(script);
		}
	}

}