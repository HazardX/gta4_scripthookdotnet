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

#pragma once
#include "stdafx.h"

#include "Graphics.h"

#include "D3D_Device.h"
#include "Font.h"
#include "Game.h"

#pragma managed

#define DrawText DrawText

namespace GTA {

	Graphics::Graphics() {
		pDefaultFont = gcnew Font();
	}

	void Graphics::InitFrame() {
		f32 ft = 0.0f;
		Scripting::GetFrameTime(&ft);
		pFrameTime = ft;
		//pLineTex = (gcnew TexturePack("network", true))->GetTexture("MAPCURSOR1"); //MAPCURSOR1
	}
	void Graphics::InitScript() {
		//pLastFont = nullptr;
		pScaling = FontScaling::Pixel;
	}


	void Graphics::DrawText(String^ Text, float X, float Y, Drawing::Color Color, GTA::Font^ Font) {
		DrawText(Text, Drawing::RectangleF(X, Y, 0.0f, 0.0f), TextAlignment::NoClip, Color, Font);
	}
	void Graphics::DrawText(String^ Text, float X, float Y, GTA::Font^ Font) {
		DrawText(Text, X, Y, Font->Color, Font);
	}
	void Graphics::DrawText(String^ Text, float X, float Y, Drawing::Color Color) {
		DrawText(Text, X, Y, Color, pDefaultFont);
	}
	void Graphics::DrawText(String^ Text, float X, float Y) {
		DrawText(Text, X, Y, pDefaultFont->Color, pDefaultFont);
	}

	Drawing::Rectangle ShiftRect(Drawing::Rectangle rect, int shiftX, int shiftY) {
		return Drawing::Rectangle(rect.X+shiftX, rect.Y+shiftY, rect.Width, rect.Height);
	}

	void Graphics::DrawText(String^ Text, Drawing::RectangleF Area, TextAlignment Alignment, Drawing::Color Color, GTA::Font^ Font) {
		int FontID = Font->GetD3DObjectID(true);
		if (FontID < 0) return;

		Drawing::Rectangle pArea = ConvertToPixel(Area);

		if (Font->Effect != FontEffect::None) {
			int eCol = Font->EffectColor.ToArgb();
			int eSiz = Font->EffectSize;
			if ( (Font->Effect == FontEffect::Shadow) || (Font->Effect == FontEffect::Edge) ) {
				Direct3D::DrawString(Text, ShiftRect(pArea,-eSiz,+eSiz), Alignment, eCol, FontID);
			}
			if (Font->Effect == FontEffect::Edge) {
				Direct3D::DrawString(Text, ShiftRect(pArea,-eSiz,-eSiz), Alignment, eCol, FontID);
				Direct3D::DrawString(Text, ShiftRect(pArea,+eSiz,-eSiz), Alignment, eCol, FontID);
				Direct3D::DrawString(Text, ShiftRect(pArea,+eSiz,+eSiz), Alignment, eCol, FontID);
			}
		}

		Direct3D::DrawString(Text, pArea, Alignment, Color.ToArgb(), FontID);
	}
	void Graphics::DrawText(String^ Text, Drawing::RectangleF Area, TextAlignment Alignment, GTA::Font^ Font) {
		DrawText(Text, Area, Alignment, Font->Color, Font);
	}
	void Graphics::DrawText(String^ Text, Drawing::RectangleF Area, TextAlignment Alignment, Drawing::Color Color) {
		DrawText(Text, Area, Alignment, Color, pDefaultFont);
	}
	void Graphics::DrawText(String^ Text, Drawing::RectangleF Area, TextAlignment Alignment) {
		DrawText(Text, Area, Alignment, pDefaultFont->Color, pDefaultFont);
	}
	void Graphics::DrawText(String^ Text, Drawing::RectangleF Area) {
		DrawText(Text, Area, TextAlignment::WordBreak, pDefaultFont->Color, pDefaultFont);
	}


	void Graphics::DrawRectangle(Drawing::RectangleF rect, Drawing::Color Color) {
		Direct3D::DrawBoxFilled(ConvertToPixelF(rect), Color.ToArgb());
	}
	void Graphics::DrawRectangle(float CenterX, float CenterY, float Width, float Height, Drawing::Color Color) {
		DrawRectangle(Drawing::RectangleF(CenterX - Width*0.5f, CenterY - Height*0.5f, Width, Height), Color);
	}


	void Graphics::DrawLine(float X1, float Y1, float X2, float Y2, float Width, Drawing::Color Color) {
		Direct3D::DrawLine(ToPixelX(X1), ToPixelY(Y1), ToPixelX(X2), ToPixelY(Y2), ToPixelX(Width), Color.ToArgb());
	}
	void Graphics::DrawLine(Drawing::PointF Point1, Drawing::PointF Point2, float Width, Drawing::Color Color) {
		DrawLine(Point1.X, Point1.Y, Point2.X, Point2.Y, Width, Color);
	}


	void Graphics::DrawSprite(GTA::Texture^ Texture, GTA::Matrix Matrix, Drawing::Color Color) {
		int color = Color.ToArgb();
		Vector3 posTL = Vector3::TransformCoordinate(Vector3(0.0f, 0.0f, 0.0f), Matrix);
		Vector3 posTR = Vector3::TransformCoordinate(Vector3(1.0f, 0.0f, 0.0f), Matrix);
		Vector3 posBL = Vector3::TransformCoordinate(Vector3(0.0f, 1.0f, 0.0f), Matrix);
		Vector3 posBR = Vector3::TransformCoordinate(Vector3(1.0f, 1.0f, 0.0f), Matrix);
		Direct3D::DrawSprite(Texture, ConvertToPixel(posTL), ConvertToPixel(posTR), ConvertToPixel(posBL), ConvertToPixel(posBR), color, color, color, color);
	}
	void Graphics::DrawSprite(GTA::Texture^ Texture, GTA::Matrix Matrix) {
		DrawSprite(Texture, Matrix, Drawing::Color::White);
	}

	void Graphics::DrawSprite(GTA::Texture^ Texture, Drawing::RectangleF rect, Drawing::Color Color) {
		Direct3D::DrawSprite(Texture, ConvertToPixelF(rect), Color.ToArgb());
	}
	void Graphics::DrawSprite(GTA::Texture^ Texture, Drawing::RectangleF rect) {
		DrawSprite(Texture, rect, Drawing::Color::White);
	}

	void Graphics::DrawSprite(GTA::Texture^ Texture, float CenterX, float CenterY, float Width, float Height, float Rotation, Drawing::Color Color) {
		Matrix matrix = Matrix::Identity * Matrix::Translation(-0.5f, -0.5f, 0.0f) * Matrix::Scaling(Width, Height, 1.0f) * Matrix::RotationZ(Rotation) * Matrix::Translation(CenterX, CenterY, 0.0f);
		DrawSprite(Texture, matrix, Color);
	}
	void Graphics::DrawSprite(GTA::Texture^ Texture, float CenterX, float CenterY, float Width, float Height, float Rotation) {
		DrawSprite(Texture, CenterX, CenterY, Width, Height, Rotation, Drawing::Color::White);
	}


	Drawing::RectangleF Graphics::GetRadarRectangle(FontScaling Scaling) {
		float w = float(Game::Resolution.Width);
		float h = float(Game::Resolution.Height);
		float pixel = System::Math::Min(w * 0.156f, h * 0.2f);
		Drawing::RectangleF rect;

		rect.Width = ConvertX(pixel, FontScaling::Pixel, Scaling);
		rect.Height = ConvertY(pixel, FontScaling::Pixel, Scaling);
		rect.X = rect.Width * 0.45f;
		if (Game::Resolution.Width >= Game::Resolution.Height)
			rect.Y = ConvertY(0.75f, FontScaling::ScreenUnits, Scaling);
		else
			//rect.Y = ConvertY(h - pixel - pixel*0.5f*(w/h), FontScaling::Pixel, Scaling);
			rect.Y = ConvertY(h - pixel - h*0.05f, FontScaling::Pixel, Scaling);

		return rect;
	}



	//Vector3 Graphics::TransformFromObjectToScreen(Vector3 PositionInObject, Matrix ObjectMatrix) {
	//	return Direct3D::TransformFromObjectToScreen(PositionInObject, ObjectMatrix);
	//}
	//Vector3 Graphics::TransformFromWorldToScreen(Matrix PositionInWorld) {
	//	return Direct3D::TransformFromObjectToScreen(Vector3(), PositionInWorld);
	//}
	//Vector3 Graphics::TransformFromWorldToScreen(Vector3 PositionInWorld) {
	//	return Direct3D::TransformFromObjectToScreen(PositionInWorld, Matrix::Identity);
	//}


	float Graphics::ConvertUnitsToPixelX(float UnitsX) {
		return (UnitsX * float(Game::Resolution.Width));
	}
	float Graphics::ConvertUnitsToPixelY(float UnitsY) {
		return (UnitsY * float(Game::Resolution.Height));
	}
	//Drawing::Point Graphics::ConvertUnitsToPixel(Drawing::PointF Units) {
	//	Drawing::Point res;
	//	res.X = ConvertUnitsToPixelX(Units.X);
	//	res.Y = ConvertUnitsToPixelY(Units.Y);
	//	return res;
	//}

	float Graphics::ConvertPixelToUnitsX(float PixelX) {
		return (PixelX / float(Game::Resolution.Width));
	}
	float Graphics::ConvertPixelToUnitsY(float PixelY) {
		return (PixelY / float(Game::Resolution.Height));
	}
	//Drawing::PointF Graphics::ConvertPixelToUnits(Drawing::Point Pixel) {
	//	Drawing::PointF res;
	//	res.X = ConvertPixelToUnitsX(Pixel.X);
	//	res.Y = ConvertPixelToUnitsY(Pixel.Y);
	//	return res;
	//}

	float Graphics::ConvertFontToUnits(float FontSize) {
		return (FontSize * 0.05f);
	}
	float Graphics::ConvertFontToPixelX(float FontSize) {
		return ConvertUnitsToPixelX(ConvertFontToUnits(FontSize));
	}
	float Graphics::ConvertFontToPixelY(float FontSize) {
		return ConvertUnitsToPixelY(ConvertFontToUnits(FontSize));
	}

	float Graphics::ConvertUnitsToFont(float Units) {
		return (Units / 0.05f);
	}
	float Graphics::ConvertPixelToFontX(float Pixel) {
		return ConvertUnitsToFont(ConvertPixelToUnitsX(Pixel));
	}
	float Graphics::ConvertPixelToFontY(float Pixel) {
		return ConvertUnitsToFont(ConvertPixelToUnitsY(Pixel));
	}

	float Graphics::ConvertX(float value, FontScaling SourceScaling, FontScaling TargetScaling) {
		if (SourceScaling == TargetScaling) return value;

		switch (SourceScaling) {

			case FontScaling::ScreenUnits: switch (TargetScaling) {
				case FontScaling::FontSize:	return Graphics::ConvertUnitsToFont(value);
				case FontScaling::Pixel:		return Graphics::ConvertUnitsToPixelX(value);
				default:								return value;
			}

			case FontScaling::Pixel: switch (TargetScaling) {
				case FontScaling::FontSize:		return Graphics::ConvertPixelToFontX(value);
				case FontScaling::ScreenUnits:	return Graphics::ConvertPixelToUnitsX(value);
				default:									return value;
			}

			default:	switch (TargetScaling) { // FontSize
				case FontScaling::ScreenUnits:	return Graphics::ConvertFontToUnits(value);
				case FontScaling::Pixel:			return Graphics::ConvertFontToPixelX(value);
				default:									return value;
			}

		}
	}
	float Graphics::ConvertY(float value, FontScaling SourceScaling, FontScaling TargetScaling) {
		if (SourceScaling == TargetScaling) return value;

		switch (SourceScaling) {

			case FontScaling::ScreenUnits: switch (TargetScaling) {
				case FontScaling::FontSize:	return Graphics::ConvertUnitsToFont(value);
				case FontScaling::Pixel:		return Graphics::ConvertUnitsToPixelY(value);
				default:								return value;
			}

			case FontScaling::Pixel: switch (TargetScaling) {
				case FontScaling::FontSize:		return Graphics::ConvertPixelToFontY(value);
				case FontScaling::ScreenUnits:	return Graphics::ConvertPixelToUnitsY(value);
				default:									return value;
			}

			default:	switch (TargetScaling) { // FontSize
				case FontScaling::ScreenUnits:	return Graphics::ConvertFontToUnits(value);
				case FontScaling::Pixel:			return Graphics::ConvertFontToPixelY(value);
				default:									return value;
			}

		}
	}

	float Graphics::ToPixelX(float value) {
		return ConvertX(value, pScaling, FontScaling::Pixel);
	}
	float Graphics::ToPixelY(float value) {
		return ConvertY(value, pScaling, FontScaling::Pixel);
	}

	Drawing::RectangleF Graphics::Convert(Drawing::RectangleF rect, FontScaling SourceScaling, FontScaling TargetScaling) {
		return Drawing::RectangleF(
			ConvertX(rect.Left,   SourceScaling, TargetScaling), 
			ConvertY(rect.Top,    SourceScaling, TargetScaling),
			ConvertX(rect.Width,  SourceScaling, TargetScaling),
			ConvertY(rect.Height, SourceScaling, TargetScaling));
	}
	Drawing::Rectangle Graphics::ConvertToPixel(Drawing::RectangleF rect) {
		return Drawing::Rectangle(
			(int)ConvertX(rect.Left,   pScaling, FontScaling::Pixel), 
			(int)ConvertY(rect.Top,    pScaling, FontScaling::Pixel),
			(int)ConvertX(rect.Width,  pScaling, FontScaling::Pixel),
			(int)ConvertY(rect.Height, pScaling, FontScaling::Pixel));
	}
	Drawing::RectangleF Graphics::ConvertToPixelF(Drawing::RectangleF rect) {
		return Drawing::RectangleF(
			ConvertX(rect.Left,   pScaling, FontScaling::Pixel), 
			ConvertY(rect.Top,    pScaling, FontScaling::Pixel),
			ConvertX(rect.Width,  pScaling, FontScaling::Pixel),
			ConvertY(rect.Height, pScaling, FontScaling::Pixel));
	}
	Vector3 Graphics::ConvertToPixel(Vector3 pos) {
		return Vector3(ConvertX(pos.X, pScaling, FontScaling::Pixel), ConvertY(pos.Y, pScaling, FontScaling::Pixel), pos.Z);
	}
	Drawing::PointF Graphics::Convert(Drawing::PointF pt, FontScaling SourceScaling, FontScaling TargetScaling) {
		return Drawing::PointF( ConvertX(pt.X, SourceScaling, TargetScaling), ConvertY(pt.Y, SourceScaling, TargetScaling) );
	}
	Drawing::SizeF Graphics::Convert(Drawing::SizeF sz, FontScaling SourceScaling, FontScaling TargetScaling) {
		return Drawing::SizeF( ConvertX(sz.Width, SourceScaling, TargetScaling), ConvertY(sz.Height, SourceScaling, TargetScaling) );
	}

}