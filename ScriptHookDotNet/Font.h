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
#pragma managed

namespace GTA {

	CLASS_ATTRIBUTES
	[Serializable]
	public ref class Font sealed
		: public base::iD3DObject {

	private:

		String^ pFontFamilyName;
		float pHeight;
		bool bBold;
		bool bItalic;
		Drawing::Color pColor;
		FontEffect pEffect;
		int pEffectSize;
		Drawing::Color pEffectColor;
		FontScaling pScaling;

		[NonSerialized]
		Font^ inherited;
		bool bChanged;
		int pInternalPointer;
		int pD3DObjectID;

		void InitValues();

	protected:
		!Font(); // Finalize

	internal:
		Font(Font^ inheritedFont);
		void DestroyInheritance();
		int GetInternalPointer(bool retrieveNew);
		virtual int GetD3DObjectID(bool retrieveNew) = base::iD3DObject::GetD3DObjectID;
		virtual void Unload(bool permanent) = base::iD3DObject::Unload;
		virtual void Reload() = base::iD3DObject::Reload;
	
	public:
		Font(Drawing::Font^ WindowsFont);
		Font(Font^ BaseFont, float NewHeight, FontScaling NewScaling);
		Font(String^ FontFamily, float Height, FontScaling Scaling, bool Bold, bool Italic);
		Font(String^ FontFamily, float Height, FontScaling Scaling);
		Font(float Height, FontScaling Scaling, bool Bold, bool Italic);
		Font(float Height, FontScaling Scaling);
		Font();
		~Font(); // Dispose

		property Drawing::Font^ WindowsFont {
			Drawing::Font^ get();
			//void set(Drawing::Font^ value);
		}

		property bool Bold {
			bool get() {
				if isNotNULL(inherited) return inherited->Bold;
				return bBold;
			}
			//void set(bool value) {
			//	DestroyInheritance();
			//	bBold = value;
			//	bChanged = true;
			//}
		}
		property bool Italic {
			bool get() {
				if isNotNULL(inherited) return inherited->Italic;
				return bItalic;
			}
			//void set(bool value) {
			//	DestroyInheritance();
			//	bItalic = value;
			//	bChanged = true;
			//}
		}
		property String^ FontFamily {
			String^ get() {
				if isNotNULL(inherited) return inherited->FontFamily;
				return pFontFamilyName;
			}
			//void set(String^ value) {
			//	DestroyInheritance();
			//	pFontFamilyName = value;
			//	bChanged = true;
			//}
		}
		property float Height {
			float get() {
				if isNotNULL(inherited) return inherited->Height;
				return pHeight;
			}
			//void set(float value) {
			//	DestroyInheritance();
			//	pHeight = value;
			//	bChanged = true;
			//}
		}
		property FontScaling Scaling {
			FontScaling get() {
				if isNotNULL(inherited) return inherited->Scaling;
				return pScaling;
			}
			//void set(FontScaling value) {
			//	DestroyInheritance();
			//	pScaling = value;
			//	bChanged = true;
			//}
		}
		property Drawing::Color Color {
			Drawing::Color get() {
				if isNotNULL(inherited) return inherited->Color;
				return pColor;
			}
			void set(Drawing::Color value) {
				DestroyInheritance();
				pColor = value;
			}
		}
		property FontEffect Effect {
			FontEffect get() {
				if isNotNULL(inherited) return inherited->Effect;
				return pEffect;
			}
			void set(FontEffect value) {
				DestroyInheritance();
				pEffect = value;
			}
		}
		property int EffectSize {
			int get() {
				if isNotNULL(inherited) return inherited->EffectSize;
				return pEffectSize;
			}
			void set(int value) {
				DestroyInheritance();
				pEffectSize = value;
			}
		}
		property Drawing::Color EffectColor {
			Drawing::Color get() {
				if isNotNULL(inherited) return inherited->EffectColor;
				return pEffectColor;
			}
			void set(Drawing::Color value) {
				DestroyInheritance();
				pEffectColor = value;
			}
		}

		float GetLineHeight(FontScaling Scaling); //pFont.SizeInPoints;

	};

}