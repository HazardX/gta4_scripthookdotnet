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

#include "fListbox.h"

#include "Font.h"
#include "Graphics.h"
#include "fScrollbar.h"

#pragma managed

namespace GTA {
namespace Forms {

	Listbox::Listbox() {
		BackColor = Drawing::Color::FromArgb(50, 255, 255, 255);
		pSelectionColor = Drawing::Color::FromArgb(127, 48, 64, 192);
		pBorder = true;
		pSelectedIndex = -1;
		pScrollbarSize = 16;

		scr = gcnew Scrollbar();
		ResizeScrollbar();
		scr->MinValue = 0;
		scr->Value = 0;
		this->Controls->Add(scr);
	}

	void Listbox::ResizeScrollbar() {
		scr->Size = Drawing::Size(pScrollbarSize, Size.Height);
		scr->Location = Point(Size.Width - pScrollbarSize, 0);
	}

	void Listbox::OnPaint(GTA::GraphicsEventArgs^ e) {
		//Control::OnPaint(e);

		Drawing::Rectangle rect = ScreenRectangle;
		Drawing::Rectangle internalrect; 
		int lh = (int)Font->GetLineHeight(FontScaling::Pixel);
		int num = (rect.Height-4) / lh;
		if ( (pScrollbarSize > 0) && (Items->Count > num) ) {
			scr->Visible = true;
			scr->ContentSize = num;
			scr->MaxContentValue = Items->Count-1;
			internalrect = Drawing::Rectangle(rect.X, rect.Y, rect.Width - pScrollbarSize, rect.Height);
		} else {
			scr->Visible = false;
			scr->Value = 0;
			internalrect = rect;
		}

		if (BackColor.A > 0) e->Graphics->DrawRectangle(internalrect,BackColor);
		if (pBorder) DrawBorder3D(e->Graphics, internalrect, false, 2);

		if (Items->Count > 0) {
			int max = System::Math::Min(scr->Value+num, Items->Count);
			int id = 0;
			for (int i = scr->Value; i < max; i++) {
				if (i == pSelectedIndex) e->Graphics->DrawRectangle(Drawing::Rectangle(rect.X, rect.Y+2+id*lh, internalrect.Width, lh), pSelectionColor);
				//e->Graphics->DrawText(tosX(rect.X + 2), tosY(rect.Y+2+id*lh), Items[i].DisplayText, ForeColor, TextAlignment::Left, Font->Height, tosX(internalrect.Right), -1.0f, Font); //tosX(rect.X + 2), tosY(rect.Y+2+id*lh) //tosX(internalrect.Right)
				e->Graphics->DrawText(Items[i].DisplayText, Drawing::Rectangle(rect.X+2, rect.Y+2+id*lh, internalrect.Width-2, lh), TextAlignment::SingleLine, ForeColor, Font);
				id++;
			}
		}

		Paint(this, e);
	}

	void Listbox::OnMouseDown(GTA::MouseEventArgs^ e) {
		int pos = this->PointToClient(e->PixelLocation).Y - 2;
		int id = -1;
		if (pos >= 0) {
			id = scr->Value + pos / int(Font->GetLineHeight(FontScaling::Pixel));
			if (id >= Items->Count) id = -1;
			if (id >= 0) SelectedIndex = id;
		}
		Control::OnMouseDown(e);
	}

}
}