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

#include "Font.h"

#include "D3D_Device.h"
#include "Graphics.h"

#pragma managed

namespace GTA {

	void Font::InitValues() {
		//pFont = gcnew Drawing::Font((System::String^)"Arial", 11.0f, Drawing::FontStyle::Bold, Drawing::GraphicsUnit::Pixel);
		pFontFamilyName = "Arial";
		pHeight = 0.5f; //14
		bBold = true;
		bItalic = false;
		pColor = Drawing::Color::White;
		pEffect = FontEffect::Edge;
		pEffectSize = 1;
		pEffectColor = Drawing::Color::Black;
		pScaling = FontScaling::FontSize;

		inherited = nullptr;
		pInternalPointer = 0;
		pD3DObjectID = -1;
		bChanged = true;
	}

	Font::Font() {
		InitValues();
	}
	Font::Font(Font^ inheritedFont) {
		InitValues();
		inherited = inheritedFont;
	}

	Font::Font(String^ FontFamily, float Height, FontScaling Scaling, bool Bold, bool Italic) {
		InitValues();
		pFontFamilyName = FontFamily;
		pHeight = Height;
		pScaling = Scaling;
		bBold = Bold;
		bItalic = Italic;
		bChanged = true;
	}
	Font::Font(String^ FontFamily, float Height, FontScaling Scaling) {
		InitValues();
		pFontFamilyName = FontFamily;
		pHeight = Height;
		pScaling = Scaling;
		bChanged = true;
	}
	Font::Font(float Height, FontScaling Scaling, bool Bold, bool Italic) {
		InitValues();
		pHeight = Height;
		pScaling = Scaling;
		bBold = Bold;
		bItalic = Italic;
		bChanged = true;
	}
	Font::Font(float Height, FontScaling Scaling) {
		InitValues();
		pHeight = Height;
		pScaling = Scaling;
		bChanged = true;
	}

	Font::Font(Drawing::Font^ WindowsFont) {
		Font::Font(WindowsFont->FontFamily->Name, (float)WindowsFont->Height, FontScaling::Pixel, WindowsFont->Bold, WindowsFont->Italic);
	}

	Font::Font(Font^ BaseFont, float NewHeight, FontScaling NewScaling) {
		InitValues();
		pFontFamilyName = BaseFont->FontFamily;
		bBold = BaseFont->Bold;
		bItalic = BaseFont->Italic;
		pColor = BaseFont->Color;
		pEffect = BaseFont->Effect;
		pEffectSize = BaseFont->EffectSize;
		pEffectColor = BaseFont->EffectColor;
		pHeight = NewHeight;
		pScaling = NewScaling;
		bChanged = true;
	}


	Font::~Font() { // Dispose
		//Unload(true); DO NOT unload it here! unload does not work in the remote script domain!
		this->!Font();
	}
	Font::!Font() { // Finalize
		//Unload(true);
	}

	Drawing::Font^ Font::WindowsFont::get() {
		return gcnew Drawing::Font(FontFamily, Graphics::ConvertY(Height,pScaling,FontScaling::Pixel), (Bold ? Drawing::FontStyle::Bold : Drawing::FontStyle::Regular) | (Italic ? Drawing::FontStyle::Italic : Drawing::FontStyle::Regular), Drawing::GraphicsUnit::Pixel);
	}
	//void Font::WindowsFont::set(Drawing::Font^ value) {
	//	FontFamily = value->FontFamily->Name;
	//	Height = (float)value->Height;
	//	Bold = value->Bold;
	//	Italic = value->Italic;
	//	Scaling = FontScaling::Pixel;
	//}

	float Font::GetLineHeight(FontScaling Scaling) {
		float val = Height * 1.1f; //((LineHeight);
		return Graphics::ConvertY(val,this->Scaling,Scaling);
	}



	void Font::Unload(bool permanent) {
		if (pInternalPointer != 0) {
			Direct3D::Release(this);
			pInternalPointer = 0;
		}
		if (permanent) {
			pD3DObjectID = -1;
			bChanged = true;
		}
	}

	void Font::Reload() {
		Unload(false);
		try {
			pInternalPointer = Direct3D::NewFontInternal((int)Graphics::ConvertY(pHeight,pScaling,FontScaling::Pixel), 0, bBold ? 700 : 400, 0, bItalic, 1, 0, 0, 0, pFontFamilyName);
		} catchErrors("Font.GetInternalPointer: Error while creating new font", pInternalPointer = 0; )
	}

	int Font::GetInternalPointer(bool retrieveNew) {
		if ( (pInternalPointer == 0) && (retrieveNew) ) Reload();
		return pInternalPointer;
	}

	int Font::GetD3DObjectID(bool retrieveNew) {
		if isNotNULL(inherited) return inherited->GetD3DObjectID(retrieveNew);
		if (bChanged && retrieveNew) {
			//Direct3D::Release(pD3DObjectID); // DO NOT unload it here! unload does not work in the remote script domain!
			//pD3DObjectID = -1;
			try {
				pD3DObjectID = Direct3D::AddNewObject(this);
			} catchErrors("Font.GetD3DObjectID: Error while creating new font", pD3DObjectID = -1; )
			if (pD3DObjectID < 0) return -1;
			bChanged = false;
		}
		return pD3DObjectID;
	}

	void Font::DestroyInheritance() {
		if isNULL(inherited) return;
		pFontFamilyName = inherited->FontFamily;
		pHeight = inherited->Height;
		pScaling = inherited->Scaling;
		bBold = inherited->Bold;
		bItalic = inherited->Italic;
		pColor = inherited->Color;
		pEffect = inherited->Effect;
		pEffectSize = inherited->EffectSize;
		pEffectColor = inherited->EffectColor;
		inherited = nullptr;
		bChanged = true;
	}

}

	//float Font::GetLineHeight(FontScaling Scaling) {
	//	float val = (Height * LineHeight);
	//	return Graphics::ConvertY(val,pScaling,Scaling);
	//}

	//void Font::Activate() {
	//	Scripting::SetTextBackground(pBackground);

	//	//Scripting::SetTextColour(pColor.R,pColor.G,pColor.B,pColor.A);
	//	Scripting::SetTextFont((u32)pStyle);

	//	//Scripting::SetTextLineDisplay(0,0);
	//	Scripting::SetTextLineHeightMult(pLineHeight);
	//	Scripting::SetTextProportional(!bFixedLetterWidth);

	//	//float tempWidth = pEnforcedWidth;
	//	//System::Drawing::Size res = Game::Resolution;

	//	//switch (pScaling) {
	//	//	case FontScaling::FontSize:
	//	//		if (tempWidth < 0.0f) tempWidth = pHeight * (float(res.Height) / float(res.Width));
	//	//		Scripting::SetTextScale(tempWidth,pHeight);
	//	//		break;

	//	//	case FontScaling::ScreenUnits:
	//	//		if (tempWidth < 0.0f) tempWidth = pHeight * (float(res.Height) / float(res.Width));
	//	//		Scripting::SetTextScale(Graphics::ConvertUnitsToFont(tempWidth),Graphics::ConvertUnitsToFont(pHeight));
	//	//		break;

	//	//	case FontScaling::Pixels:
	//	//		if (tempWidth < 0.0f) tempWidth = pHeight; // * 0.75f;
	//	//		Scripting::SetTextScale(Graphics::ConvertPixelToFontX(tempWidth),Graphics::ConvertPixelToFontY(pHeight));
	//	//		break;
	//	//}

	//	Scripting::SetTextUseUnderscore(true); //pUnderline);
	//	//Scripting::SetTextWrap(pBeginNewLineAt,pWrapLineAt); // usual: 0.00, 1.00

	//	switch (pEffect) {
	//		case FontEffect::Edge:
	//			Scripting::SetTextEdge(pEffectSize,pEffectColor.R,pEffectColor.G,pEffectColor.B,pEffectColor.A);
	//			break;
	//		case FontEffect::Shadow:
	//			Scripting::SetTextDropshadow(pEffectSize,pEffectColor.R,pEffectColor.G,pEffectColor.B,pEffectColor.A);
	//			break;
	//		default: //case FontEffect::None:
	//			Scripting::SetTextDropshadow(0,0,0,0,0);
	//			break;
	//	}

	//	//switch (pAlignment) {
	//	//	case TextAlignment::Centered:
	//	//		Scripting::SetTextCentre(true);
	//	//		Scripting::SetTextJustify(false);
	//	//		Scripting::SetTextRightJustify(false);
	//	//		break;
	//	//	case TextAlignment::JustifyLeft:
	//	//		Scripting::SetTextCentre(false);
	//	//		Scripting::SetTextJustify(true);
	//	//		Scripting::SetTextRightJustify(false);
	//	//		break;
	//	//	//case TextAlignment::JustifyRight:
	//	//	//	Scripting::SetTextCentre(false);
	//	//	//	Scripting::SetTextJustify(false);
	//	//	//	Scripting::SetTextRightJustify(true);
	//	//	//	break;
	//	//	default: //case TextAlignment::Left:
	//	//		Scripting::SetTextCentre(false);
	//	//		Scripting::SetTextJustify(false);
	//	//		Scripting::SetTextRightJustify(false);
	//	//		break;
	//	//}
	//}

