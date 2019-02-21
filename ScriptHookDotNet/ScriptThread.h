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

namespace GTA {

	ref class Script;

	CLASS_ATTRIBUTES
#ifdef USE_NETTHREAD
	private ref class ScriptThread : public NetThread { 
#else
	private ref class ScriptThread : public IngameThread {
#endif

	protected:
		virtual void OnStartup() override;
		virtual void OnTick() override;
		virtual void OnThreadContinue() override;
		virtual void OnThreadHalt() override;
		virtual void OnEnd() override;

		//!ScriptThread();

	internal:
		static ScriptThread^ currentlyLoading;

		RemoteScriptDomain^ domain;
		String^ scriptFile;
		System::Type^ scriptType;
		GTA::Script^ script;

		bool LoadScriptNow();

	public:
		ScriptThread(RemoteScriptDomain^ domain, String^ scriptFile, System::Type^ scriptType);
		//~ScriptThread();

	};

}