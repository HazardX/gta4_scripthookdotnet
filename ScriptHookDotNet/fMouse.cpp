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

#include "fMouse.h"

#include "D3D_Device.h"
#include "Game.h"
#include "Graphics.h"
#include "Player.h"
#include "RemoteScriptDomain.h"
#include "ScriptDomain.h"
#include "fFormHost.h"

#pragma managed

namespace GTA {
namespace Forms {

	Mouse::Mouse() {
		bEnabled = false;
		pPosition = Drawing::PointF(0.5f, 0.5f);
		pMovement = Drawing::PointF(0.0f, 0.0f);
		pButtons = System::Windows::Forms::MouseButtons::None;
		//TexturePack^ tp = gcnew TexturePack("network", true);
		//TexArrow = tp->GetTexture("MOUSECURSOR"); // network.MOUSECURSOR // hud: mousecursorhud, mapcursor1, mapcursorhand(64x64)
		//TexUpDown = tp->GetTexture("ICON_W_ARROW_UPDOWN");

		pCursor = CursorType::Arrow;
		//buttonstate = gcnew array<bool>(7);
	}

	void Mouse::Enabled::set(bool value) {
		if (bEnabled == value) return;
		if (value)
			Game::LocalPlayer->CanControlCharacter = false;
		else
			Game::LocalPlayer->CanControlCharacter = true;
		bEnabled = value;

		//Scripting::ToggleToplevelSprite(value);
		////if (value) {
		////	char* txdptr = PinStringA(TXD);
		////	try {
		////		Scripting::RequestStreamedTxd(txdptr, 1);
		////	} finally {
		////		FreeString(txdptr);
		////	}
		////}
		//if (value) {
		//	TexArrow->LoadToMemory();
		//	TexUpDown->LoadToMemory();
		//}
	}

	Drawing::PointF Mouse::GetMovement() {
		//float x = 0.0f; float y = 0.0f;
		//Scripting::GetMouseInput(&x, &y);
		//return Drawing::PointF(x, y)
		float s = Scripting::GetMouseSensitivity() * 0.0025f;
		float ratio = float(GTA::Game::Resolution.Width) / float(GTA::Game::Resolution.Height); // Y axis has to be faster
		int x = 0; int y = 0;
		Scripting::GetMouseInput(&x, &y);
		return Drawing::PointF(float(x)*s, float(y)*s*ratio);
	}

	void Mouse::CheckButtonDown(WinForms::Keys Key) {
		switch (Key) {
			case WinForms::Keys::LButton:
				DoButtonDown(WinForms::MouseButtons::Left);
				return;
			case WinForms::Keys::RButton:
				DoButtonDown(WinForms::MouseButtons::Right);
				return;
			case WinForms::Keys::MButton:
				DoButtonDown(WinForms::MouseButtons::Middle);
				return;
			case WinForms::Keys::XButton1:
				DoButtonDown(WinForms::MouseButtons::XButton1);
				return;
			case WinForms::Keys::XButton2:
				DoButtonDown(WinForms::MouseButtons::XButton2);
				return;
		}
	}
	void Mouse::CheckButtonUp(WinForms::Keys Key) {
		switch (Key) {
			case WinForms::Keys::LButton:
				DoButtonUp(WinForms::MouseButtons::Left);
				return;
			case WinForms::Keys::RButton:
				DoButtonUp(WinForms::MouseButtons::Right);
				return;
			case WinForms::Keys::MButton:
				DoButtonUp(WinForms::MouseButtons::Middle);
				return;
			case WinForms::Keys::XButton1:
				DoButtonUp(WinForms::MouseButtons::XButton1);
				return;
			case WinForms::Keys::XButton2:
				DoButtonUp(WinForms::MouseButtons::XButton2);
				return;
		}
	}
	void Mouse::DoButtonDown(WinForms::MouseButtons Button) {
		pButtons = (pButtons | Button);
		MouseEventArgs^ e = gcnew MouseEventArgs(bEnabled, pPosition, Button);
		ButtonDown(this, e);
		//try {
		//	NetHook::LocalConsole->MouseDown(e);
		//} catchErrors ("Error in console",)
		NetHook::FormHost->TriggerMouseDown(e);
		if (NetHook::Console->isActive) return;
		NetHook::ScriptDomain->TriggerEvent(ScriptEvent::MouseDown, e);
	}
	void Mouse::DoButtonUp(WinForms::MouseButtons Button) {
		pButtons = (pButtons & ~Button);
		MouseEventArgs^ e = gcnew MouseEventArgs(bEnabled, pPosition, Button);
		ButtonUp(this, e);
		//try {
		//	NetHook::LocalConsole->MouseUp(e);
		//} catchErrors ("Error in console",)
		NetHook::FormHost->TriggerMouseUp(e);
		if (NetHook::Console->isActive) return;
		NetHook::ScriptDomain->TriggerEvent(ScriptEvent::MouseUp, e);
	}

	//void Mouse::CheckButton(System::Windows::Forms::Keys Key) {
	//	bool pressed = Helper::isKeyPressedAsync(Key);
	//	if (pressed == buttonstate[(int)Key]) return;
	//	buttonstate[(int)Key] = pressed;
	//	if (pressed)
	//		CheckButtonDown(Key);
	//	else
	//		CheckButtonUp(Key);
	//}

	void Mouse::Check() {
		pMovement = GetMovement();
		if (!Enabled) return;
		pPosition.X += pMovement.X;
		pPosition.Y += pMovement.Y;
		if (pPosition.X < 0.0f) pPosition.X = 0.0f;
		if (pPosition.Y < 0.0f) pPosition.Y = 0.0f;
		if (pPosition.X > 1.0f) pPosition.X = 1.0f;
		if (pPosition.Y > 1.0f) pPosition.Y = 1.0f;

		//CheckButton(Keys::LButton);
		//CheckButton(Keys::RButton);
		//CheckButton(Keys::MButton);
		//CheckButton(Keys::XButton1);
		//CheckButton(Keys::XButton2);

		//float s = Scripting::GetMouseSensitivity();
		//NetHook::DisplayText("Mouse: " + pPosition.X.ToString("F2") + " " + pPosition.Y.ToString("F2") + " " + s.ToString("F2") + " " + bDrawn.ToString(), 2000);
	}

	void Mouse::Draw(Graphics^ g) {
		if (!Enabled) return;

		g->Scaling = FontScaling::Pixel;
		Drawing::Point pos = this->PositionPixel;
		//float w = Graphics::ConvertPixelToUnitsX(32.0f);
		//float h = Graphics::ConvertPixelToUnitsY(32.0f);

		//switch (pCursor) {
		//	case CursorType::Arrow:
		//		TexArrow->Draw(pPosition.X + (w * 0.5f), pPosition.Y + (h * 0.5f), w, h, 0.0f, Drawing::Color::White, true);
		//		break;
		//	case CursorType::UpDown:
		//		TexUpDown->Draw(pPosition.X, pPosition.Y, w, h, 0.0f, Drawing::Color::White, true);
		//		break;
		//	case CursorType::LeftRight:
		//		TexUpDown->Draw(pPosition.X, pPosition.Y, w, h, 90.0f, Drawing::Color::White, true);
		//		break;
		//	case CursorType::TopLeftToBottomRight:
		//		TexUpDown->Draw(pPosition.X, pPosition.Y, w, h, -45.0f, Drawing::Color::White, true);
		//		break;
		//	case CursorType::TopRightToBottomLeft:
		//		TexUpDown->Draw(pPosition.X, pPosition.Y, w, h, 45.0f, Drawing::Color::White, true);
		//		break;
		//}

		Direct3D::DrawMouseArrow(pos.X, pos.Y, 12, 0xFFFFFFFF, 0xFF000000);
	}


	// REMOTE MOUSE CLASS

	void RemoteMouse::Enabled::set(bool value) {
		if ( (value == false) && (RemoteScriptDomain::Instance->isConsoleActive) ) return;
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::SetMouseEnabled, value);
		bEnabled = (bool)RemoteScriptDomain::Instance->LastRemoteEventResult;
	}

}
}