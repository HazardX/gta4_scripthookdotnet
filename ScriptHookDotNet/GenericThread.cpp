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

/*#include "NetHook.h"
#include "RemoteScriptDomain.h"
#include "Game.h"
//#include "Script.h"
//#include "IngameThread.h"
#include "NetThread.h"*/

#include "NetThread.h"

#include "GenericThread.h"

namespace GTA {

	GenericThread::GenericThread(RemoteScriptDomain^ domain, SomeFunction^ func, String^ name) {
		this->domain = domain;
		this->func = func;
		this->name = name;
	}

	//ScriptThread::~GenericThread() {
	//	this->!GenericThread();
	//}
	//ScriptThread::!GenericThread() {
	//}

	void GenericThread::OnStartup() {
		//lock(syncroot) {
		if (VERBOSE) NetHook::Log(name + " Startup");
		//} unlock(syncroot);
	}

	void GenericThread::OnTick() {
		//lock(syncroot) {

		//if (VERBOSE) NetHook::Log(name + " Tick");

			try {

				func->Invoke();

			} catch (System::Threading::ThreadAbortException^ taex) {
				throw taex;
			} catchErrors ("Error in " + name + ".OnTick",)

		//if (VERBOSE) NetHook::Log(name + " Tick End");

		//} unlock(syncroot);
	}

	void GenericThread::OnThreadContinue() {
		//domain->SetCurrentScript(script);
	}
	void GenericThread::OnThreadHalt() {
		//RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain("ThreadHalt",nullptr);
		//domain->SetCurrentScript(nullptr);
	}

	void GenericThread::OnEnd() {
		if (VERBOSE) NetHook::Log(name + " End");
	}

}