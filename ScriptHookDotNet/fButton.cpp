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

#include "fButton.h"

#include "Font.h"
#include "Graphics.h"


#pragma managed

namespace GTA {
namespace Forms {

	void Button::OnPaint(GTA::GraphicsEventArgs^ e) {
		Control::OnPaint(e);

		Drawing::Rectangle rect = ScreenRectangle;
		int pushoffset;
		int offY = (rect.Height - int(Font->Height) - 4) / 2;
		if (!bDown) {
			pushoffset = 0;
		} else {
			pushoffset = 2;
			e->Graphics->DrawRectangle(rect, pDownColor); 
		}
		DrawBorder3D(e->Graphics, rect, !bDown, 2);
		//e->Graphics->DrawText(tosX(rect.X+(rect.Width/2)+pushoffset), tosY(rect.Y+offY+pushoffset), Text, ForeColor, TextAlignment::Center, Font->Height, 2.0f, -1.0f, Font);
		e->Graphics->DrawText(Text, Drawing::Rectangle(rect.X+pushoffset,rect.Y+pushoffset,rect.Width,rect.Height), TextAlignment::Center | TextAlignment::VerticalCenter, ForeColor, Font);
	}

	void Button::OnMouseDown(GTA::MouseEventArgs^ e) {
		if (e->Button == Windows::Forms::MouseButtons::Left) {
			bDown = true;
		}
		Control::OnMouseDown(e);
	}
	void Button::OnDragRelease(GTA::MouseEventArgs^ e) {
		bDown = false;
		Control::OnDragRelease(e);
	}

	void Button::OnClick(GTA::MouseEventArgs^ e) {
		if (e->Button != Windows::Forms::MouseButtons::Left) return;
		Control::OnClick(e);
	}

}
}