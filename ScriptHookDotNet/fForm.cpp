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

#include "fForm.h"

#include "Font.h"
#include "Game.h"
#include "Graphics.h"
#include "RemoteScriptDomain.h"
#include "Script.h"
#include "fButton.h"
#include "fFormHost.h"

#pragma managed

namespace GTA {
namespace Forms {

	void Form::InitEarlyValues() {
		Control::InitEarlyValues();
		pTitleBackColor = Drawing::Color::FromArgb(150,77,109,243);
		BackColor = Drawing::Color::FromArgb(150,200,200,200);
		pSymbolFont = gcnew GTA::Font(DefaultFont);
		TitleSize = 24; // without p to set fontsize too
		pBorder = 2;
	}
	Form::Form() {
		pDialogResult = Windows::Forms::DialogResult::None;
		pBlockVisibleChanged = true;
		Visible = false;
		pBlockVisibleChanged = false;
		pStartPosition = FormStartPosition::Random;
		bDragClose = false;
		bDragTitle = false;

		pDisabledBackColor = Drawing::Color::FromArgb(150,0,0,0);
		pDisabledTitleColor = Drawing::Color::FromArgb(200,0,0,0);
		pDisabledFontColor = Drawing::Color::FromArgb(255,128,128,128);

		Name = this->GetType()->Name;

		if (NetHook::isScriptDomain) pScript = RemoteScriptDomain::Instance->CurrentScript;
	}
	
	void Form::TitleSize::set(int value) {
		pTitleSize = value;
		if (value > 4) pSymbolFont = gcnew GTA::Font(pSymbolFont, float(value-4), FontScaling::Pixel);
		//pSymbolFont->Height = float(value-4); // float(
		//pSymbolFont->EnforcedWidth = pSymbolFont->Height * 1.3f;
	}

	GTA::value::Resources^ Form::Resources::get() {
		return pScript->Resources;
	}

	void Form::AcceptButton::set(Button^ value) {
		if (System::Object::ReferenceEquals(pAcceptButton, value)) return;
		if isNotNULL(pAcceptButton) pAcceptButton->Click -= gcnew MouseEventHandler(this, &Form::AcceptButton_Click);
		pAcceptButton = value;
		if isNotNULL(pAcceptButton) pAcceptButton->Click += gcnew MouseEventHandler(this, &Form::AcceptButton_Click);
	}

	void Form::CancelButton::set(Button^ value) {
		if (System::Object::ReferenceEquals(pCancelButton, value)) return;
		if isNotNULL(pCancelButton) pCancelButton->Click -= gcnew MouseEventHandler(this, &Form::CancelButton_Click);
		pCancelButton = value;
		if isNotNULL(pCancelButton) pCancelButton->Click += gcnew MouseEventHandler(this, &Form::CancelButton_Click);
	}

	void Form::AcceptButton_Click(System::Object^ sender, MouseEventArgs^ e) {
		DialogResult = Windows::Forms::DialogResult::OK;
		Close();
	}
	void Form::CancelButton_Click(System::Object^ sender, MouseEventArgs^ e) {
		DialogResult = Windows::Forms::DialogResult::Cancel;
		Close();
	}

	void Form::OnPaint(GTA::GraphicsEventArgs^ e) {
		Drawing::Rectangle rect = ScreenRectangle;
		if (pTitleSize > 0) {
			Drawing::Rectangle titleRect = Drawing::Rectangle(rect.X,rect.Y,rect.Width,pTitleSize);
			e->Graphics->DrawRectangle(titleRect, pTitleBackColor);
			if (pTitleSize > 4) {
				e->Graphics->DrawText(Text, GrowLeft(titleRect,-4), TextAlignment::SingleLine | TextAlignment::VerticalCenter, ForeColor, pSymbolFont);
				e->Graphics->DrawText("X", Drawing::Rectangle(titleRect.Right-pTitleSize,titleRect.Y,pTitleSize,titleRect.Height), TextAlignment::Center | TextAlignment::VerticalCenter, ForeColor, pSymbolFont);
			}
		}
		e->Graphics->DrawRectangle(Drawing::Rectangle(rect.X,rect.Y+pTitleSize,rect.Width,rect.Height-pTitleSize), BackColor);
		Paint(this, e);
	}
	void Form::TriggerBackgroundPaint(GTA::GraphicsEventArgs^ e) {
		Drawing::Rectangle rect = ScreenRectangle;
		//if (pTitleSize > 0) {
		//	//e->Graphics->DrawRectangle(Drawing::Rectangle(rect.X,rect.Y,rect.Width,pTitleSize), pDisabledTitleColor);
		//	//e->Graphics->DrawText(tosX(rect.X+pBorder),tosY(rect.Y),Text,pDisabledFontColor,pSymbolFont);
		//	//e->Graphics->DrawText(tosX(rect.Right-pTitleSize),tosY(rect.Y),"X",pDisabledFontColor,pSymbolFont);
		//	Drawing::Rectangle titleRect = Drawing::Rectangle(rect.X,rect.Y,rect.Width,pTitleSize);
		//	e->Graphics->DrawRectangle(titleRect, pDisabledTitleColor);
		//	e->Graphics->DrawText(Text, GrowLeft(titleRect,-4), TextAlignment::SingleLine | TextAlignment::VerticalCenter, pDisabledFontColor, pSymbolFont);
		//	e->Graphics->DrawText("X", Drawing::Rectangle(titleRect.Right-pTitleSize,titleRect.Y,pTitleSize,titleRect.Height), TextAlignment::Center | TextAlignment::VerticalCenter, pDisabledFontColor, pSymbolFont);
		//}
		//e->Graphics->DrawRectangle(Drawing::Rectangle(rect.X,rect.Y+pTitleSize,rect.Width,rect.Height-pTitleSize), pDisabledBackColor);
		e->Graphics->DrawRectangle(rect, pDisabledBackColor);
	}

	FormHost^ Form::GetFormHost() {
		if (NetHook::isPrimary) {
			return NetHook::FormHost;
		} else {
			GTA::Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if isNULL(scr) return nullptr;
			return scr->FormHost;
		}
	}

	void Form::OnVisibleChanged(EventArgs^ e) {
		if (pBlockVisibleChanged) return;
		Control::OnVisibleChanged(e);

		GTA::Forms::FormHost^ fh = GetFormHost();
		if isNULL(fh) return;

		if (Visible) {
			switch (pStartPosition) {
				case FormStartPosition::CenterScreen: {
					Location = Drawing::Point((GTA::Game::Resolution.Width - Size.Width) / 2, (GTA::Game::Resolution.Height - Size.Height) / 2);
					break; }
				case FormStartPosition::Random: {
					Drawing::Point max = Drawing::Point(GTA::Game::Resolution.Width - Size.Width, GTA::Game::Resolution.Height - Size.Height);
					if (max.X > 0)
						max.X = NetHook::Random->Next(0, max.X);
					else
						max.X = 0;
					if (max.Y > 0)
						max.Y = NetHook::Random->Next(0, max.Y);
					else
						max.Y = 0;
					Location = max; //Drawing::Point(NetHook::Random->Next(0, max.X), NetHook::Random->Next(0, max.Y));
					break; }
				default: {
					break; }
			}
			pDialogResult = Windows::Forms::DialogResult::None;

			fh->Add(this);
			Opened(this, e);

		} else {
			bDragClose = false;
			bDragTitle = false;

			fh->Remove(this);
			Closed(this, e);
		}
	}

	void Form::OnMouseDown(GTA::MouseEventArgs^ e) {
		Drawing::Point pos = PointToClient(e->PixelLocation);
		if (pos.Y < 0) {
			if (pos.X > (Width - TitleSize)) {
				bDragClose = true;
				bDragTitle = false;
			} else {
				bDragClose = false;
				bDragTitle = true;
				pDragOffset = Helper::SubtractPoint(e->PixelLocation, Location);
			}
			return;
		} else {
			bDragClose = false;
			bDragTitle = false;
		}
		Control::OnMouseDown(e);
	}
	void Form::OnDragRelease(GTA::MouseEventArgs^ e) {
		Drawing::Point pos = PointToClient(e->PixelLocation);
		if (pos.Y <= 0) {
			if (pos.X > (Width - TitleSize)) {
				if (bDragClose) {
					Close();
					return;
				}
			}
		}
		bDragClose = false;
		bDragTitle = false;
		Control::OnMouseDown(e);
	}
	void Form::OnDragging(GTA::MouseEventArgs^ e) {
		if (bDragTitle) Location = Helper::SubtractPoint(e->PixelLocation, pDragOffset);
	}

	void Form::Close() {
		if (DialogResult == Windows::Forms::DialogResult::None) DialogResult = Windows::Forms::DialogResult::Cancel;
		Visible = false;
	}
	void Form::Show() {
		Visible = true;
	}
	Windows::Forms::DialogResult Form::ShowDialog() {
		GTA::Forms::FormHost^ fh = GetFormHost();
		if isNULL(fh) return Windows::Forms::DialogResult::None;

		Show();
		fh->SetModalForm(this);

		try {
			GTA::Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if isNULL(scr) return Windows::Forms::DialogResult::None;
			while (Visible) {
				//GTA::Game::WaitInCurrentScript(0);
				scr->Wait(0);
				if (Visible) scr->ProcessEvents();
			}
		} catchErrors("Error during Form.ShowDialog",)
		return DialogResult;
	}

}
}