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

#include "fControl.h"

#include "Font.h"
#include "Graphics.h"

#pragma managed

namespace GTA {
namespace Forms {

	Control::Control() {
		bVisible = true;
		pName = String::Empty;
		pControls = gcnew ControlCollection(this);
		pBackColor = Drawing::Color::FromArgb(0,200,200,200);
		pForeColor = Drawing::Color::FromArgb(255,255,255,255);
		pLocation = Drawing::Point(0,0);
		pBorderColorLight = Drawing::Color::FromArgb(100, 255, 255, 255);
		pBorderColorDark = Drawing::Color::FromArgb(100, 0, 0, 0);
		InitEarlyValues();
		pSize = DefaultSize;
	}

	void Control::Visible::set(bool value) {
		if (bVisible == value) return;
		bVisible = value;
		OnVisibleChanged(EventArgs::Empty);
	}

	void Control::Parent::set(Control^ value) {
		if (System::Object::ReferenceEquals(value, pParent)) return;
		if isNotNULL(pParent) pParent->Controls->Remove(this);
		pParent = value;
		pParent->Controls->Add(this);
	}

	GTA::Font^ Control::DefaultFont::get() {
		if isNULL(pDefaultFont) pDefaultFont = gcnew GTA::Font(16.0f, FontScaling::Pixel);
		return pDefaultFont;
	}

	GTA::Font^ Control::Font::get() {
		if isNULL(pFont) {
			if isNotNULL(pParent) {
				pFont = gcnew GTA::Font(pParent->Font);
			} else {
				pFont = gcnew GTA::Font(DefaultFont);
			}
		}
		return pFont;
	}

	void Control::DrawBorder3D(GTA::Graphics^ g, Drawing::Rectangle rect, bool Up, int Width) {
		Drawing::RectangleF rectF = (Drawing::RectangleF)rect; //Graphics::Convert(rect, FontScaling::Pixels, FontScaling::ScreenUnits);
		float edgeX = (float)Width; //tosX(Width);
		float edgeY = (float)Width; //tosY(Width);
		Drawing::Color col1, col2;
		if (Up) {
			col1 = pBorderColorLight;
			col2 = pBorderColorDark;
		} else {
			col1 = pBorderColorDark;
			col2 = pBorderColorLight;
		}
		g->DrawRectangle(rectF.X, rectF.Y+(rectF.Height*0.5f), edgeX, rectF.Height, col1); // left
		g->DrawRectangle(rectF.Right, rectF.Y+(rectF.Height*0.5f), edgeX, rectF.Height, col2); // right
		g->DrawRectangle(rectF.X+(rectF.Width*0.5f), rectF.Y, rectF.Width, edgeY, col1); // top
		g->DrawRectangle(rectF.X+(rectF.Width*0.5f), rectF.Bottom, rectF.Width, edgeY, col2); // bottom
	}

	void Control::DrawEffectLine(GTA::Graphics^ g, float Width, Drawing::Color LineColor, Drawing::Color EffectColor, ... array<Drawing::Point>^ Points) {
		if ( isNULL(Points) || (Points->Length < 2) ) return;
		for (int i = 1; i < Points->Length; i++) {
			g->DrawLine(Points[i-1],Points[i],Width+4.0f,EffectColor);
		}
		for (int i = 1; i < Points->Length; i++) {
			g->DrawLine(Points[i-1],Points[i],Width,LineColor);
		}
	}
	void Control::DrawEffectLine(GTA::Graphics^ g, float Width, ... array<Drawing::Point>^ Points) {
		DrawEffectLine(g, Width, ForeColor, pBorderColorDark, Points); //Font->EffectColor
	}


	void Control::DoTick() {
		for each (Control^ c in pControls) {
			c->DoTick();
		}
	}

	void Control::TriggerPaint(GraphicsEventArgs^ e) {
		if (!bVisible) return;
		OnPaint(e);
		for each (Control^ c in pControls) {
			c->TriggerPaint(e);
		}
	}
	void Control::OnPaint(GTA::GraphicsEventArgs^ e) {
		if (pBackColor.A > 0) {
			e->Graphics->DrawRectangle(ScreenRectangle,pBackColor);
		}
		Paint(this, e);
	}

	float Control::tosX(int ScreenPosX) {
		return float(ScreenPosX);
		//return Graphics::ConvertPixelToUnitsX(float(ScreenPosX));
	}
	float Control::tosY(int ScreenPosY) {
		return float(ScreenPosY);
		//return Graphics::ConvertPixelToUnitsY(float(ScreenPosY));
	}

	Drawing::Point Control::PointToClient(Point ScreenPoint) {
		if isNotNULL(Parent) ScreenPoint = Parent->PointToClient(ScreenPoint);
		return Helper::SubtractPoint(Helper::SubtractPoint(ScreenPoint, Location), ClientRectangle.Location);
	}
	Drawing::Point Control::PointToScreen(Point ClientPoint) {
		Drawing::Point loc = Helper::AddPoint(Helper::AddPoint(Location, ClientRectangle.Location), ClientPoint);
		if isNULL(Parent) return loc;
		return Parent->PointToScreen(loc);
	}

	bool Control::isPointInside(Point ScreenPoint, bool NotWhenInSubcontrol) {
		if (!Helper::PointInRect(ScreenPoint, ScreenRectangle)) return false;
		if (NotWhenInSubcontrol) {
			for each (Control^ c in Controls) {
				if (c->isPointInside(ScreenPoint, false)) return false;
			}
		}
		return true;
	}

	Control^ Control::GetControlAt(Point ScreenPoint) {
		if (!bVisible) return nullptr;
		if (!Helper::PointInRect(ScreenPoint, ScreenRectangle)) return nullptr;
		Control^ res;
		for each (Control^ c in Controls) {
			res = c->GetControlAt(ScreenPoint);
			if isNotNULL(res) return res;
		}
		return this;
	}

}
}