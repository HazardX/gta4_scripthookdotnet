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
//#include "NetHook.h"

int hModule;

bool _stdcall isPrimary() {
	if (System::AppDomain::CurrentDomain->FriendlyName == "SHDN_ScriptDomain") return false;
	
	System::String^ ExecPath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
	System::String^ TempPath = System::Environment::ExpandEnvironmentVariables("%TEMP%") + "\\shdn_";
	if (ExecPath->StartsWith(TempPath,System::StringComparison::InvariantCultureIgnoreCase)) return false;

	return true;
}

unsigned int _stdcall ManagedEntryPoint(void*) {

	bool bPrimary = isPrimary(); //true;

	//if (System::AppDomain::CurrentDomain->FriendlyName == "SHDN_ScriptDomain") bPrimary = false;

	//
	//System::String^ ExecPath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
	//System::String^ TempPath = System::Environment::ExpandEnvironmentVariables("%TEMP%") + "\\shdn_";
	//if (ExecPath->StartsWith(TempPath,System::StringComparison::InvariantCultureIgnoreCase)) bPrimary = false;

	//SetDllDirectoryA("D:\\Spiele\\Vollversionen\\GTA4mod1040\\plugins");

	if (!bPrimary) return 0;

	GTA::NetHook::Initialize(bPrimary, hModule);

	return 0;
}

unsigned int _stdcall ManagedEndPoint(void*) {

	//GTA::NetHook::GameEnded();

	return 0;
}

//[System::STAThreadAttribute]
//int main(array<System::String ^> ^args) {
//	//// Enabling Windows XP visual effects before any controls are created
//	//Application::EnableVisualStyles();
//	//Application::SetCompatibleTextRenderingDefault(false); 
//
//	// Create the main window and run it
//	//Application::Run(gcnew Form1());
//
//	bool bPrimary = isPrimary(); 
//	if (bPrimary) return 0;
//	GTA::NetHook::Initialize(bPrimary);
//
//	return 0;
//}


#pragma unmanaged

//#ifdef DEBUG
//extern "C" { //HACK: allow the use of mixed debug/non-debug code
//   void __cdecl _invalid_parameter_noinfo(void) {  }
//}
//#endif

BOOL WINAPI DllMain( HINSTANCE dllInstHandle, DWORD reason, LPVOID reserved ) {
	switch (reason) {
		case DLL_PROCESS_ATTACH: {

			hModule = (int)dllInstHandle;

		  (void)DisableThreadLibraryCalls(dllInstHandle); // fix for random mscorwks.dll crashes

			// Launch a thread to get a managed entry point
			unsigned int threadId = 0;
			HANDLE threadHandle;
			threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ManagedEntryPoint, 0, 0, (LPDWORD)&threadId);
			if (threadHandle == 0 || threadHandle == INVALID_HANDLE_VALUE)	return FALSE;
			CloseHandle(threadHandle);

			return TRUE;
		}
		case DLL_PROCESS_DETACH: {

			// Shutdown the script hook manager
			//ScriptHookManager::Shutdown();

			unsigned int threadId = 0;
			HANDLE threadHandle;
			threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ManagedEndPoint, 0, 0, (LPDWORD)&threadId);
			if (threadHandle == 0 || threadHandle == INVALID_HANDLE_VALUE)	return FALSE;
			CloseHandle(threadHandle);

			return TRUE;
		}
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			return FALSE;  // fix for random mscorwks.dll crashes - return false on thread calls

    }
    return TRUE;
}

#pragma managed

/*

// ##### FIRST WAY TO TRIGGER MANAGED CODE FROM UNMANAGED DLLMAIN #####

int _stdcall ManagedEntryPoint(ptr) {
	System::Windows::Forms::MessageBox::Show("IT WORKS!\n");
	return 0;
}

#pragma unmanaged

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  fdwReason, LPVOID lpReserved) {
	// Launch a new thread which then allows managed code
	u32 threadId = 0;
	HANDLE threadHandle;
	threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ManagedEntryPoint, 0, 0, (LPDWORD)&threadId);
	if (threadHandle == 0 || threadHandle == INVALID_HANDLE_VALUE)
		return FALSE;
	CloseHandle(threadHandle);
}



// ##### SECOND WAY TO TRIGGER MANAGED CODE FROM UNMANAGED DLLMAIN #####

struct __declspec(dllexport) dllLoaderManagedStruct {
   dllLoaderManagedStruct() {
		System::Windows::Forms::MessageBox::Show("Module ctor initializing based on global instance of class.\n");
   }
   void TriggerConstructor() {
		int i = 1;
   }
};
static dllLoaderManagedStruct dllLoaderManaged;


#pragma unmanaged

struct __declspec(dllexport) dllLoaderUnmanagedStruct {
   dllLoaderUnmanagedStruct() {
		dllLoaderManaged.TriggerConstructor();
   }
   void TriggerConstructor() {
		int i = 1;
   }
};
static dllLoaderUnmanagedStruct dllLoaderUnmanaged;


BOOL APIENTRY DllMain( HANDLE hModule, DWORD  fdwReason, LPVOID lpReserved) {
   // Trigger Constructor of a static unmanaged struct,
	//   which triggers the constructor of a static managed struct,
	//   which can then execute managed code
	dllLoaderUnmanaged.TriggerConstructor();
}

*/