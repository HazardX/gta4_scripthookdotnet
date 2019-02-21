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

#include "StartupThreadC.h"

// NON FIBER AUTO STARTUP

StartupThreadC::StartupThreadC() {
	SetName("ScriptHookDotNet");
	bRunning = false;
}

void StartupThreadC::RunTick() {
	if (!bRunning) return;
	if (bFirst) {
		bFirst = false;

		//if (GTA::NetHook::ScriptDomain->RunningScriptCount > 0)
		//	GTA::NetHook::ReloadScriptDomain();
		//else
		//	GTA::NetHook::CreateScriptDomain();
		//GTA::NetHook::RequestScriptAction(GTA::ScriptAction::RestartScripts);
		GTA::NetHook::GameReloaded();
	}
	GTA::NetHook::Tick();
}

void StartupThreadC::Start() {
	NativeThread::Start();
	bFirst = true;
	bRunning = true;
}

void StartupThreadC::Kill() {
	bRunning = false;
	//GTA::NetHook::UnloadScriptDomain();
	////if (GTA::NetHook::ScriptDomain->RunningScriptCount > 0) {
	////	GTA::NetHook::RequestScriptAction(GTA::ScriptAction::AbortScripts);
	////	if (!GTA::NetHook::ScriptDomain->WaitForScriptsToAbort(10000)) {
	////		GTA::NetHook::Log("ERROR! Failed to abort scripts:" + System::Environment::NewLine + System::String::Join(System::Environment::NewLine,GTA::NetHook::ScriptDomain->GetRunningScriptNames()));
	////	}
	////}
	GTA::NetHook::GameTerminated();
	NativeThread::Kill();
}