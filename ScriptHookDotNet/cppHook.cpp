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

#pragma unmanaged
#include "../ScriptHook/ScriptHookManager.h"
#include "../ScriptHook/Services/D3DHook.h"
#include "../ScriptHook/Game.h"
#include "../ScriptHook/NativeInvoke.h"
#pragma managed

#include "cppHook.h"

namespace unmanaged {

	u32 cppHook::GetCppHookVersion() {
		return ScriptHookManager::GetScriptHookVersion() & 0xFFF0;
	}

	bool cppHook::isKeyPressed(int Key) {
		return ((GetAsyncKeyState(Key) & 0x8000) != 0);
	}

	//bool cppHook::isAnyGameThreadActive() {
	//	return (Game::GetInstance()->Script_GetActiveThread() != 0);
	//}

	void cppHook::RegisterThread(void* thread, void* hmodule) {
		ScriptHookManager::RegisterThread( (NativeThread*)thread, (HMODULE)hmodule );
	}

	void cppHook::InstallD3dHook(void* nativeHook) {
		// Convenience method for installing the hook, doesn't have to be in here really.
		ID3DHookService *pService = ScriptHookManager::RequestService<ID3DHookService>( "D3DHook" );
		pService->AddDeviceHook( (ID3DDeviceHook*)nativeHook );
	}

	void cppHook::RemoveD3dHook(void* nativeHook) {
		// Convenience method for uninstalling the hook, doesn't have to be in here really.
		ID3DHookService *pService = ScriptHookManager::RequestService<ID3DHookService>( "D3DHook" );
		pService->RemoveDeviceHook( (ID3DDeviceHook*)nativeHook );
	}

	int cppHook::GetGlobalAddress(int index) {
		return (int)Game::GetGlobalAddress((u32)index);
	}



	//template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
	//R NativeInvoke::Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15, T16 p16) {
	//	::NativeInvoke::Invoke(name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
	//}


}