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
#pragma managed

namespace GTA {

	using namespace System;
	using namespace System::Reflection;

	ref class RemoteScriptDomain;

	// Proxy to RemoteScriptDomain
	CLASS_ATTRIBUTES
	private ref class ScriptDomain sealed { 
		//public MarshalByRefObject {
		//public base::iLocalScriptDomain {

	private:

		int pRemoteEventsPerFrame;
		int pRemoteEventsPerFrameCurrent;
		System::AppDomain^ pAppDomain;
		RemoteScriptDomain^ remote;
		//static System::Threading::Mutex^ LocalMutex = gcnew System::Threading::Mutex(false);

		//System::Threading::AutoResetEvent^ wThreadCommand; // = gcnew System::Threading::AutoResetEvent(false);
		//System::Threading::ManualResetEvent^ wThreadHalted; // = gcnew System::Threading::ManualResetEvent(true);
		//array<System::Threading::WaitHandle^>^ wThreadHandles;

	public: //internal:

		void RemoteEvent(RemoteEventArgs^ ev);

	//internal:

	//	void PrintScriptHelp();

	public:

		ScriptDomain();

		property bool isActive {
			bool get();
		}
		property int LoadedScriptCount {
			int get();
		}
		property int RunningScriptCount {
			int get();
		}
		property int TotalScriptFormCount {
			int get();
		}
		property int RemoteEventsPerFrame {
			int get() { return pRemoteEventsPerFrame; }
		}
		array<String^>^ GetLoadedScriptNames();
		array<String^>^ GetRunningScriptNames();

		void Create();
		void Unload();

		bool LoadScripts();
		bool WaitForScriptsToAbort(int timeout);

		void SendScriptCommand(Guid ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter);
		bool isScriptRunning(Guid GUID);

		void ScheduleForRemoteProcessingThread(RemoteProcessingTask CommandID, ... array<System::Object^>^ Arguments);

		void ProcessRemoteEvents();
		void ProcessDrawingRemoteEvents();
		//void ProcessAnyRemoteEvents();

		void TriggerEvent(ScriptEvent Event, EventArgs^ args);
		void RequestAction(ScriptAction action);
		void Tick(); 
		void PerFrameDrawing();
		//void RunScriptTick(int ScriptID, bool WaitForEnd);

	};

}

