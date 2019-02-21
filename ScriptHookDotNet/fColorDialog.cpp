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

#include "fColorDialog.h"

#include "Font.h"
#include "Graphics.h"
#include "fButton.h"
#include "fScrollbar.h"

#pragma managed

namespace GTA {
namespace Forms {

	ColorDialog::ColorDialog() {
		pBlockChange = true;
		pSelectedColorID = 0;
		pSelectedColorRGB = Drawing::Color::FromArgb(GTA::ColorIndex::colary[pSelectedColorID] | 0xFF000000);;
		Text = "Select a color...";
		InitializeComponent();
		pBlockChange = false;
		bSwatchesVisible = true;
		pAllowScrollbars = true;
		pAllowAlpha = true;
	}

	void ColorDialog::InitializeComponent() {
		int x = ColCols * ColSize + 8*2;
		int y = 24+56+8;

      scrR = gcnew GTA::Forms::Scrollbar();
      scrR->Location = Drawing::Point(32, 8);
      scrR->Size = Drawing::Size(ColCols*ColSize-24, 24);
      scrR->ContentSize = 25;
      scrR->MinValue = 0;
      scrR->MaxValue = 255;
		scrR->Value = pSelectedColorRGB.R;
      scrR->BackColor = Drawing::Color::FromArgb(64, 255, 0, 0);
		scrR->Visible = false;
      Controls->Add(scrR);
		scrR->ValueChanged += gcnew EventHandler(this, &ColorDialog::ScrollbarChanged);

      scrG = gcnew GTA::Forms::Scrollbar();
      scrG->Location = Drawing::Point(32, 8+32);
      scrG->Size = Drawing::Size(ColCols*ColSize-24, 24);
      scrG->ContentSize = 25;
      scrG->MinValue = 0;
      scrG->MaxValue = 255;
		scrG->Value = pSelectedColorRGB.G;
      scrG->BackColor = Drawing::Color::FromArgb(64, 0, 255, 0);
		scrG->Visible = false;
      Controls->Add(scrG);
		scrG->ValueChanged += gcnew EventHandler(this, &ColorDialog::ScrollbarChanged);

      scrB = gcnew GTA::Forms::Scrollbar();
      scrB->Location = Drawing::Point(32, 8+32*2);
      scrB->Size = Drawing::Size(ColCols*ColSize-24, 24);
      scrB->ContentSize = 25;
      scrB->MinValue = 0;
      scrB->MaxValue = 255;
		scrB->Value = pSelectedColorRGB.B;
		scrB->BackColor = Drawing::Color::FromArgb(64, 0, 0, 255);
		scrB->Visible = false;
      Controls->Add(scrB);
		scrB->ValueChanged += gcnew EventHandler(this, &ColorDialog::ScrollbarChanged);

      scrA = gcnew GTA::Forms::Scrollbar();
      scrA->Location = Drawing::Point(32, 8+32*3);
      scrA->Size = Drawing::Size(ColCols*ColSize-24, 24);
      scrA->ContentSize = 25;
      scrA->MinValue = 0;
      scrA->MaxValue = 255;
      scrA->Value = pSelectedColorRGB.A;
		scrA->Visible = false;
      Controls->Add(scrA);
		scrA->ValueChanged += gcnew EventHandler(this, &ColorDialog::ScrollbarChanged);

		butCancel = gcnew Button();
		butCancel->Text = "Cancel";
		butCancel->Size = Drawing::Size(80, 24);
		butCancel->Location = Drawing::Point(ClientRectangle.Size - butCancel->Size - Drawing::Size(8,8)); 
		Controls->Add(butCancel);

		butOK = gcnew Button();
		butOK->Text = "OK";
		butOK->Size = Drawing::Size(80, 24);
		butOK->Location = Drawing::Point(butCancel->Location.X - 8 - butOK->Size.Width, butCancel->Location.Y);
		Controls->Add(butOK);

		butSwitch = gcnew Button();
		butSwitch->Text = "Scrollbars";
		butSwitch->Size = Drawing::Size(butOK->Location.X - 16, 24);
		butSwitch->Location = Drawing::Point(8, butCancel->Location.Y);
		Controls->Add(butSwitch);
		butSwitch->Click += gcnew GTA::MouseEventHandler(this, &ColorDialog::butSwitch_Click);

		AcceptButton = butOK;
		CancelButton = butCancel;
	}

	int ColorDialog::GetColorIdAt(Drawing::Point pt) {
		pt.X -= 8; pt.Y -= 8;
		if ( (pt.X < 0) || (pt.X > (ColSize*ColCols)) || (pt.Y < 0) ) return -1;
		int ID = ((pt.Y / ColSize) * ColCols) + (pt.X / ColSize);
		if (ID >= GTA::ColorIndex::colary->Length) return -1;
		return ID;
	}
	Drawing::Rectangle ColorDialog::GetColorRect(int ID) {
		if (ID < 0) return Drawing::Rectangle();
		Drawing::Rectangle rect;
		rect.X = 8 + (ID % ColCols) * ColSize;
		rect.Y = 8 + (ID / ColCols) * ColSize;
		rect.Width = ColSize;
		rect.Height = ColSize;
		return rect;
	}

	void ColorDialog::SelectedColorID::set(int value) {
		if (pSelectedColorID == value) return;
		if ((value < 0) || (value >= GTA::ColorIndex::colary->Length)) return;
		pSelectedColorID = value;
		pSelectedColorRGB = Drawing::Color::FromArgb(GTA::ColorIndex::colary[value] | 0xFF000000);
		AdjustScrollbars();
		OnSelectedColorChanged(EventArgs::Empty);
	}

	GTA::ColorIndex ColorDialog::SelectedColorGTA::get() {
		return GTA::ColorIndex(SelectedColorID);
	}
	void ColorDialog::SelectedColorGTA::set(GTA::ColorIndex value) {
		SelectedColorID = value.Index;
	}

	void ColorDialog::AllowScrollbars::set(bool value) {
		pAllowScrollbars = value;
		if (!value && !bSwatchesVisible) SwitchToPredefined();
		butSwitch->Visible = value;
	}
	void ColorDialog::AllowAlpha::set(bool value) {
		pAllowAlpha = value;
		if (!value) scrA->Value = 255;
		scrA->Visible = value;
	}

	void ColorDialog::OnPaint(GTA::GraphicsEventArgs^ e) {
		Form::OnPaint(e);
		Drawing::Point pos = PointToScreen(Drawing::Point(0,0));
		Drawing::Rectangle rect;
		if (bSwatchesVisible) {
			for (int i = 0; i < GTA::ColorIndex::colary->Length; i++) {
				rect = GetColorRect(i);
				rect.Offset(pos);
				e->Graphics->DrawRectangle(rect, Drawing::Color::FromArgb(GTA::ColorIndex::colary[i] | 0xFF000000));
			}
		} else {
			e->Graphics->DrawText("R", tosX(pos.X + 8), tosY(pos.Y + 8), ForeColor, Font);
			e->Graphics->DrawText("G", tosX(pos.X + 8), tosY(pos.Y + 8+32), ForeColor, Font);
			e->Graphics->DrawText("B", tosX(pos.X + 8), tosY(pos.Y + 8+32*2), ForeColor, Font);
			if (pAllowAlpha) e->Graphics->DrawText("A", tosX(pos.X + 8), tosY(pos.Y + 8+32*3), ForeColor, Font);
		}
		int x = ColCols * ColSize + 8*2;
		e->Graphics->DrawText("Color:", tosX(pos.X + x), tosY(pos.Y + 4), ForeColor, Font);
		rect = Drawing::Rectangle(pos.X + x, pos.Y + 24, ClientRectangle.Width - x - 8, ColRows * ColSize - 16 );
		e->Graphics->DrawRectangle(rect, SelectedColorRGB);
		DrawBorder3D(e->Graphics, rect, false, 2);
	}

	void ColorDialog::OnMouseDown(GTA::MouseEventArgs^ e) {
		if (pBlockChange) return;
		if (bSwatchesVisible) {
			Drawing::Point pos = PointToClient(e->PixelLocation);
			int ID = GetColorIdAt(pos);
			if (ID >= 0) SelectedColorID = ID;
		}
		Form::OnMouseDown(e);
	}

	void ColorDialog::ScrollbarChanged(System::Object^ sender, EventArgs^ e) {
		if (pBlockChange) return;
		if (bSwatchesVisible) return;
		Drawing::Color newcol = Drawing::Color::FromArgb(scrA->Value, scrR->Value, scrG->Value, scrB->Value);
		if (newcol == pSelectedColorRGB) return;
		pSelectedColorID = -1;
		pSelectedColorRGB = newcol;
		OnSelectedColorChanged(EventArgs::Empty);
	}

	void ColorDialog::AdjustScrollbars() {
		pBlockChange = true;
		scrR->Value = pSelectedColorRGB.R;
		scrG->Value = pSelectedColorRGB.G;
		scrB->Value = pSelectedColorRGB.B;
		pBlockChange = false;
	}

	void ColorDialog::butSwitch_Click(System::Object^ sender, GTA::MouseEventArgs^ e) {
		if (bSwatchesVisible)
			SwitchToScrollbars();
		else
			SwitchToPredefined();
	}

	void ColorDialog::SwitchToScrollbars() {
		if (!bSwatchesVisible) return;
		butSwitch->Text = "Predefined";
		bSwatchesVisible = false;
		scrR->Visible = true;
		scrG->Visible = true;
		scrB->Visible = true;
		if(pAllowAlpha) scrA->Visible = true;
	}
	void ColorDialog::SwitchToPredefined() {
		if (bSwatchesVisible) return;
		butSwitch->Text = "Scrollbars";
		bSwatchesVisible = true;
		scrR->Visible = false;
		scrG->Visible = false;
		scrB->Visible = false;
		scrA->Visible = false;
	}

}
}