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

#include "KeyWatchDog.h"

	bool interop_GetAsyncKeyState(int Key) {
		return ((GetAsyncKeyState(Key) & 0x8000) != 0);
	}

#pragma managed

namespace GTA {

	KeyWatchDog::KeyWatchDog() {
		keystate = gcnew array<bool>(256);
		bShift = false;
		bCtrl = false;
		bAlt = false;
		pModifier = WinForms::Keys::None;
		ckeystate = (BYTE*)malloc(256);
		if (ckeystate == NULL) throw gcnew System::OutOfMemoryException();

		keystate[0] = false;
		keystate[3] = false;
	}
	KeyWatchDog::~KeyWatchDog() {
		if (ckeystate != NULL) free(ckeystate);
	}

	void KeyWatchDog::CheckKeyAsync(WinForms::Keys Key) {
		bool pressed = Helper::isKeyPressedAsync(Key);
		if (pressed == keystate[(int)Key]) return;
		keystate[(int)Key] = pressed;
		if (pressed)
			OnKeyDown(gcnew KeyEventArgs(Key | Modifier));
		else
			OnKeyUp(gcnew KeyEventArgs(Key | Modifier));
	}

	void KeyWatchDog::Check() {
		bool stat;
		WinForms::Keys key;

		//bShift = interop_GetAsyncKeyState((int)Keys::ShiftKey) || interop_GetAsyncKeyState((int)Keys::LShiftKey) || interop_GetAsyncKeyState((int)Keys::RShiftKey);
		//bCtrl = interop_GetAsyncKeyState((int)Keys::ControlKey) || interop_GetAsyncKeyState((int)Keys::LControlKey) || interop_GetAsyncKeyState((int)Keys::RControlKey);
		//bAlt = interop_GetAsyncKeyState((int)Keys::Menu) || interop_GetAsyncKeyState((int)Keys::LMenu) || interop_GetAsyncKeyState((int)Keys::RMenu);
		//pModifier = (bShift ? Keys::Shift : Keys::None) | (bCtrl ? Keys::Control : Keys::None) | (bAlt ? Keys::Alt : Keys::None);
		//
		//for (int i = 0; i < 255; i++) { // yes, 255 is NOT valid!
		//	stat = interop_GetAsyncKeyState(i);
		//	if (stat != keystate[i]) {
		//		key = Helper::RemoveRedundantKeyModifiers(Keys(i) | Modifier);
		//		if (stat)
		//			OnKeyDown(gcnew KeyEventArgs(key));
		//		else
		//			OnKeyUp(gcnew KeyEventArgs(key));
		//		keystate[i] = stat;
		//	}

		//}

		bShift = cIsKeyPressed(WinForms::Keys::ShiftKey) || cIsKeyPressed(WinForms::Keys::LShiftKey) || cIsKeyPressed(WinForms::Keys::RShiftKey);
		bCtrl = cIsKeyPressed(WinForms::Keys::ControlKey) || cIsKeyPressed(WinForms::Keys::LControlKey) || cIsKeyPressed(WinForms::Keys::RControlKey);
		bAlt = cIsKeyPressed(WinForms::Keys::Menu) || cIsKeyPressed(WinForms::Keys::LMenu) || cIsKeyPressed(WinForms::Keys::RMenu);
		pModifier = (bShift ? WinForms::Keys::Shift : WinForms::Keys::None) | (bCtrl ? WinForms::Keys::Control : WinForms::Keys::None) | (bAlt ? WinForms::Keys::Alt : WinForms::Keys::None);

		if (GetKeyboardState(ckeystate)) {
			for (int i = 7; i < 255; i++) { // yes, 255 is NOT valid! // 0 undefined, 3 VK_CANCEL can be ignored, 1 2 4 5 6 mouse keys
				stat = ((ckeystate[i] & 0x80) != 0);
				if (stat != keystate[i]) {
					key = Helper::RemoveRedundantKeyModifiers(WinForms::Keys(i) | Modifier);
					if (stat)
						OnKeyDown(gcnew KeyEventArgs(key));
					else
						OnKeyUp(gcnew KeyEventArgs(key));
					keystate[i] = stat;
				}
			}
		}

		CheckKeyAsync(WinForms::Keys::LButton);
		CheckKeyAsync(WinForms::Keys::RButton);
		CheckKeyAsync(WinForms::Keys::MButton);
		CheckKeyAsync(WinForms::Keys::XButton1);
		CheckKeyAsync(WinForms::Keys::XButton2);
	}

	void KeyWatchDog::OnKeyDown(KeyEventArgs^ e) {
		KeyDown(this, e);
	}
	void KeyWatchDog::OnKeyUp(KeyEventArgs^ e) {
		KeyUp(this, e);
	}

}