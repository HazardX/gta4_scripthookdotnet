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

#include "fCheckbox.h"

#include "Font.h"
#include "Graphics.h"

#pragma managed

namespace GTA {
namespace Forms {

	void Checkbox::OnPaint(GTA::GraphicsEventArgs^ e) {
		Control::OnPaint(e);

		Drawing::Rectangle rect = ScreenRectangle;
		int boxsize = int(Font->Height) + 4;
		int boxy = rect.Y + (rect.Height - boxsize) / 2;

		DrawBorder3D(e->Graphics, Drawing::Rectangle(rect.X, boxy, boxsize, boxsize), false, 2);
		//e->Graphics->DrawText(tosX(rect.X+boxp+4), tosY(rect.Y), Text, ForeColor, TextAlignment::Left, Font->Height, 2.0f, -1.0f, Font);
		e->Graphics->DrawText(Text, Drawing::Rectangle(rect.X+boxsize+2, rect.Y, rect.Width-boxsize-2, rect.Height), TextAlignment::SingleLine | TextAlignment::VerticalCenter, ForeColor, Font);

		if (Checked) {
			Drawing::Point p1 = Drawing::Point(rect.X+boxsize/4, boxy+(boxsize/5)*2);
			Drawing::Point p2 = Drawing::Point(rect.X+boxsize/2, boxy+(boxsize/4)*3);
			Drawing::Point p3 = Drawing::Point(rect.X+(boxsize/4)*3, boxy);
			e->Graphics->DrawLine(p1, p2, 3, pCheckColor);
			e->Graphics->DrawLine(p2, p3, 3, pCheckColor);
		}
	}

	void Checkbox::OnMouseDown(GTA::MouseEventArgs^ e) {
		int boxp = int(Font->Height) + 4;
		Drawing::Point pos = PointToClient(e->PixelLocation);
		if ((pos.X <=boxp) && (pos.Y <=boxp)) {
			Checked = !Checked;
		}
		Control::OnMouseDown(e);
	}

}
}