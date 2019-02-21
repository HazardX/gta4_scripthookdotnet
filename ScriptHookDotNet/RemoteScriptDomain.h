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

	/// <summary>
	/// Factory class to create objects exposing IRemoteInterface
	/// </summary>
	CLASS_ATTRIBUTES
	private ref class RemoteScriptDomain sealed : public MarshalByRefObject {

	private:
		static const BindingFlags bfi = BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance;

	public:
		RemoteScriptDomain();
		void Initialize();

		static RemoteScriptDomain^ pInstance;
		static property RemoteScriptDomain^ Instance {
			RemoteScriptDomain^ get() {
				return pInstance;
			}
		}

		virtual System::Object^ InitializeLifetimeService() override {
			return nullptr;
		}

	private:

		//GTA::ScriptDomain^ LocalScriptDomain;
		//GTA::base::iLocalScriptDomain^ LocalScriptDomain;
		GTA::Graphics^ pGraphics;
		GTA::Script^ pCurrentScript;
		GTA::NetThread^ pCurrentThread;
		GTA::GenericThread^ pRenderThread;
		GTA::Forms::FormHost^ pFormHost;

		List<FoundScript>^ scriptTypeList;
		List<GTA::Script^>^ scriptList;
		List<GTA::ScriptThread^>^ scriptThreadList;

		List<GTA::RemoteEventArgs^>^ RemoteEventList;
		List<GTA::RemoteEventArgs^>^ RemoteEventListDrawing;
		GTA::RemoteEventArgs^ LastRemoteEvent;

		bool bConsoleActive;
		int pOpenFormsCount;
		bool bDrawing;

		ScriptState pState;
		ScriptAction pAction;
		void ChangeState(ScriptState state);
		void CheckState();

		static Assembly^ MyResolveEventHandler(System::Object^ sender, ResolveEventArgs^ args);
		static void CatchUnhandledExceptions(System::Object^ o, UnhandledExceptionEventArgs^ eventArgs);

		void LoadAssemblies(String^ path, String^ pattern);
		void LoadDynamics(String^ path, String^ pattern);
		bool LoadAssembly(String^ Filename);
		bool LoadDynamicScript(String^ Filename);
		bool LoadAssembly(Assembly^ asb, String^ Filename);

		void LaunchScriptThreads();
		void AbortScripts();
		void RemoveAllScripts();

	internal:
		static int FrameNum;
		
		property GTA::Script^ CurrentScript {
			GTA::Script^ get() {
				return pCurrentScript;
			}
		}
		property String^ CurrentScriptName {
			String^ get();
		}
		property GTA::NetThread^ CurrentThread {
			GTA::NetThread^ get() {
				return pCurrentThread;
			}
		}
		property GTA::Forms::FormHost^ FormHost {
			GTA::Forms::FormHost^ get() {
				return pFormHost;
			}
		}

		void SetCurrentScript(GTA::Script^ script) {
			pCurrentScript = script;
		}
		//void SetCurrentThread(GTA::ScriptThread^ scriptThread) {
		//	pCurrentThread = scriptThread;
		//}
		void AddRunningScript(GTA::Script^ script) {
			scriptList->Add(script);
		}
		void RemoveRunningScript(GTA::Script^ script);

		//GTA::Script^ LoadScript(System::Type^ ScriptType);

		array<String^>^ GetLoadedScriptNames();
		array<String^>^ GetRunningScriptNames();
		bool WaitForScriptsToAbort(int timeout);

		void ScriptError(GTA::Script^ Script, String^ CodeLocation);
		void ScriptError(GTA::Script^ Script, String^ CodeLocation, String^ ErrorDetails);
		void ScriptError(GTA::Script^ Script, String^ CodeLocation, Exception^ ex);

		void PrintScriptHelp();

	public:

		void SetInfos(bool isConsoleActive, bool MouseEnabled, Drawing::PointF MousePosition, Drawing::PointF MouseMovement, System::Windows::Forms::MouseButtons MouseButtons, int LocalOpenFormsCount);
		void InitFrame();

		property bool isConsoleActive {
			bool get() {
				return bConsoleActive;
			}
		}
		property int LoadedScriptCount {
			int get() {
				return scriptTypeList->Count;
			}
		}
		property int RunningScriptCount {
			int get() {
				return scriptList->Count;
			}
		}
		property int RunningThreadCount {
			int get() {
				return scriptThreadList->Count;
			}
		}
		property int TotalScriptFormCount {
			int get();
		}
		property int TotalOverallFormCount {
			int get();
		}
		property ScriptState State {
			ScriptState get() {
				return pState;
			}
		}

		void TriggerEvent(ScriptEvent Event, EventArgs^ args);
		void RequestAction(ScriptAction action);

		bool LoadScripts();
		void PerFrameDrawing();
		void PerFrameScriptDrawing();
		//void RunTickOfAllThreads();
		//void RunScriptTick(int ScriptID, bool WaitForEnd);
		bool RunThreadTick(int ThreadID);
		bool RunRenderThreadTick();
		void SetThreadActive(int ThreadID);

		//static System::Threading::AutoResetEvent^ runFlag = gcnew System::Threading::AutoResetEvent(false);
		//static System::Threading::ManualResetEvent^ stopFlag = gcnew System::Threading::ManualResetEvent(false);
		////System::Threading::Thread^ tThread;
		//static void TestThread(System::Object^ state);

		Script^ GetScript(Guid GUID);
		void SendScriptCommand(GTA::Script^ sender, GTA::Script^ TargetScript, String^ Command, ... array<System::Object^>^ Parameter);
		void SendScriptCommand(GTA::Script^ sender, Guid TargetScriptGUID, String^ Command, ... array<System::Object^>^ Parameter);
		bool isScriptRunning(Guid GUID) {
			return isNotNULL(GetScript(GUID));
		}

		void RaiseEventInLocalScriptDomain(RemoteEvent EventID, ... array<System::Object^>^ Arguments);
		void BeforeRemoteEvent();
		RemoteEventArgs^ GetNextRemoteEvent();
		array<RemoteEventArgs^>^ GetDrawingEventList();
		//RemoteEventArgs^ GetNextDrawingRemoteEvent();
		//RemoteEventArgs^ GetAnyNextRemoteEvent();
		//RemoteEventArgs^ NextRemoteEvent;
		System::Object^ LastRemoteEventResult;
		String^ LastRemoteEventError;

		void ScheduleForRemoteProcessingThread(RemoteProcessingTask CommandID, ... array<System::Object^>^ Arguments);
		bool RunRemoteProcessingThreadTick();
		//void ProcessRemoteProcessingTasks();

		//bool RunPreScriptChecksThreadTick();

		void SyncBackNativeCall(GTA::Native::Template^ result);

	};  

}

