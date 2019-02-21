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

#include "fKeybox.h"

#include "Font.h"
#include "Graphics.h"

#pragma managed

namespace GTA {
namespace Forms {

	void Keybox::OnPaint(GTA::GraphicsEventArgs^ e) {
		Control::OnPaint(e);

		Drawing::Rectangle rect = ScreenRectangle;
		int offY = (rect.Height - int(Font->Height) - 4) / 2;

		String^ Text;
		if (bAwaitKey) {
			if (pCurrentKey == Windows::Forms::Keys::None)
				Text = "Press a key combination...";
			else
				Text = pCurrentKey.ToString()->Replace(", "," + "); //Helper::RemoveRedundantKeyModifiers
		} else {
			Text = SelectedKey.ToString()->Replace(", "," + "); //Helper::RemoveRedundantKeyModifiers
		}

		DrawBorder3D(e->Graphics, rect, false, 2);
		//e->Graphics->DrawText(rect.X + 2, rect.Y+offY, Text, ForeColor, TextAlignment::Left, Font->Height, 2.0f, -1.0f, Font); //tosX(rect.X + 2), tosY(rect.Y+offY)
		e->Graphics->DrawText(Text, rect, TextAlignment::SingleLine | TextAlignment::VerticalCenter | TextAlignment::Center, ForeColor, Font);
	}

	void Keybox::OnClick(GTA::MouseEventArgs^ e) {
		if (bAwaitKey) return;
		if (e->Button == Windows::Forms::MouseButtons::Left) {
			bAwaitKey = true;
			pCurrentKey = Windows::Forms::Keys::None;
		} else if (e->Button == Windows::Forms::MouseButtons::Right) {
			SelectedKey = Windows::Forms::Keys::None;
		}
	}
	void Keybox::OnKeyDown(GTA::KeyEventArgs^ e) {
		if (bAwaitKey) {
			pCurrentKey = e->KeyWithModifiers;
		}
		Control::OnKeyDown(e);
	}
	void Keybox::OnKeyUp(GTA::KeyEventArgs^ e) {
		if (bAwaitKey && (pCurrentKey != Windows::Forms::Keys::None)) {
			SelectedKey = pCurrentKey;
			bAwaitKey = false;
		}
		Control::OnKeyDown(e);
	}

}
}