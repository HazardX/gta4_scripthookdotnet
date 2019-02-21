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

#include "fTextbox.h"

#include "Font.h"
#include "Graphics.h"
#include "KeyboardLayout.h"

#pragma managed

namespace GTA {
namespace Forms {

	void Textbox::OnPaint(GTA::GraphicsEventArgs^ e) {
		Control::OnPaint(e);

		Drawing::Rectangle rect = ScreenRectangle;
		int offY = (rect.Height - int(Font->Height) - 4) / 2;

		if (pBorder) DrawBorder3D(e->Graphics, rect, false, 2);
		//e->Graphics->DrawText(rect.X + 2, rect.Y+offY, Text, ForeColor, TextAlignment::Left, Font->Height, 2.0f, -1.0f, Font); //tosX(rect.X + 2), tosY(rect.Y+offY)
		e->Graphics->DrawText(Text, GrowLeft(rect,-2), TextAlignment::SingleLine | TextAlignment::VerticalCenter, ForeColor, Font);
	}

	void Textbox::OnKeyDown(GTA::KeyEventArgs^ e) {
		switch (e->Key) {
			case Windows::Forms::Keys::Back:
				if (Text->Length > 0) Text = Text->Substring(0, Text->Length-1);
				break;
		}
		if ( (pMaxLength <= 0) || (Text->Length < pMaxLength) ) { 
			Text += NetHook::KeyboardLayout->ParseKey(e->KeyWithModifiers);
		}
		Control::OnKeyDown(e);
	}

}
}