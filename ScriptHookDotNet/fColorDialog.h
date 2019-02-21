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

	value class Color;

namespace Forms {

	CLASS_ATTRIBUTES
	public ref class ColorDialog : public GTA::Forms::Form {

	private:
		Drawing::Color pSelectedColorRGB;
		int pSelectedColorID;
		bool pBlockChange;
		bool bSwatchesVisible;
		bool pAllowScrollbars;
		bool pAllowAlpha;

		int GetColorIdAt(Drawing::Point pt);
		Drawing::Rectangle GetColorRect(int ID);

		static int ColSize = 16;
		static int ColCols = 16;
		static int ColRows = 9;

		Scrollbar^ scrR;
		Scrollbar^ scrG;
		Scrollbar^ scrB;
		Scrollbar^ scrA;
		Button^ butOK;
		Button^ butCancel;
		Button^ butSwitch;

		void InitializeComponent();
		void ScrollbarChanged(System::Object^ sender, EventArgs^ e);
		void AdjustScrollbars();
		
		void butSwitch_Click(System::Object^ sender, GTA::MouseEventArgs^ e);
		
	public:
		event EventHandler^ SelectedColorChanged;

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;
		virtual void OnSelectedColorChanged(EventArgs^ e) {
			SelectedColorChanged(this, e);
		}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(ColCols*ColSize + 64 + 8*3,TitleSize + ColRows*ColSize + 28 + 8*3);
			}
		}

		property int SelectedColorID {
			int get() {
				return pSelectedColorID;
			}
			void set(int value);
		}

	public protected:
		virtual void OnMouseDown(GTA::MouseEventArgs^ e) override;

	public:
		ColorDialog();

		property Drawing::Color SelectedColorRGB {
			Drawing::Color get() {
				return pSelectedColorRGB;
			}
			void set(Drawing::Color value) {
				if (pSelectedColorRGB == value) return;
				pSelectedColorRGB = value;
				OnSelectedColorChanged(EventArgs::Empty);
			}
		}
		property GTA::ColorIndex SelectedColorGTA {
			GTA::ColorIndex get();
			void set(GTA::ColorIndex value);
		}
		property bool AllowScrollbars {
			bool get() {
				return pAllowScrollbars;
			}
			void set(bool value);
		}
		property bool AllowAlpha {
			bool get() {
				return pAllowAlpha;
			}
			void set(bool value);
		}

		void SwitchToScrollbars();
		void SwitchToPredefined();

	};

}
}