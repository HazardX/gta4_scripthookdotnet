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

//#include "dColorConverter.h"

#include "sColorIndex.h"

#pragma managed

namespace GTA {

	String^ ColorIndex::GetNameOf(int Index) {
		if ((Index<0) || (Index>=colnamary->Length)) return "Unknown";
		return colnamary[Index];
	}

	ColorIndex ColorIndex::FromKnownName(String^ Name) {
		for (int i = 0; i<colnamary->Length; i++) {
			if (Name->Equals(colnamary[i], StringComparison::InvariantCultureIgnoreCase))
				return ColorIndex(i);
		}
		return ColorIndex(0);
	}

	ColorIndex::ColorIndex(int ColorIndex) {
		//if ((ColorIndex<0) || (ColorIndex>133)) ColorIndex = 0;
		this->pIndex = ColorIndex;
	}
	//Color::Color(System::Drawing::Color color) {
	//	
	//}

	int ColorIndex::Index::get() {
		return pIndex;
	}
	String^ ColorIndex::Name::get() {
		return GetNameOf(pIndex);
	}

	int ColorIndex::R::get() {
		return ToColor().R;
	}
	int ColorIndex::G::get() {
		return ToColor().G;
	}
	int ColorIndex::B::get() {
		return ToColor().B;
	}

	int ColorIndex::ToARGB() {
		if ((pIndex<0) || (pIndex>133)) return 0;
		return (colary[pIndex] | 0xFF000000);
	}
	System::Drawing::Color ColorIndex::ToColor() {
		return System::Drawing::Color::FromArgb(ToARGB());
	}

	//Color Color::FromARGB(int ARGB) {
	//	return Color(0);
	//}
	//Color Color::FromColor(System::Drawing::Color color) {
	//	return Color(0);
	//}

	ColorIndex::operator ColorIndex (int source) {
		return ColorIndex(source);
	}
	ColorIndex::operator System::Drawing::Color (ColorIndex source) {
		return source.ToColor();
	}
	//Color::operator Color (System::Drawing::Color source) {
	//	return Color(0);
	//}

	String^ ColorIndex::ToString() {
		return Name;
	}

}