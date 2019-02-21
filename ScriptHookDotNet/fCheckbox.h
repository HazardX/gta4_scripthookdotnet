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
namespace Forms {

	using namespace Drawing;

	CLASS_ATTRIBUTES
	[System::ComponentModel::DefaultEventAttribute("CheckedChanged")]
	public ref class Checkbox : public GTA::Forms::Control {

	private:
		Drawing::Color pCheckColor;
		bool bChecked;

	public:
		event EventHandler^ CheckedChanged;

	public protected:

		virtual void OnMouseDown(GTA::MouseEventArgs^ e) override;

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;
		virtual void OnCheckedChanged(EventArgs^ e) {
			CheckedChanged(this, e);
		}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(128,32);
			}
		}

	public:
		Checkbox() {
			pCheckColor = Drawing::Color::FromArgb(240, 48, 64, 192);
			bChecked = false;
		}

		property Drawing::Color CheckColor {
			Drawing::Color get() {
				return pCheckColor;
			}
			void set(Drawing::Color value) {
				pCheckColor = value;
			}
		}

		property bool Checked {
			bool get() {
				return bChecked;
			}
			void set(bool value) {
				if (bChecked == value) return;
				bChecked = value;
				OnCheckedChanged(EventArgs::Empty);
			}
		}

	};

}
}