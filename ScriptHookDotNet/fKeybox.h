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
	[System::ComponentModel::DefaultEventAttribute("SelectedKeyChanged")]
	public ref class Keybox : public GTA::Forms::Control {

	private:
		//int pEdgeSize;
		//int pEdgeAlpha;
		//Drawing::Color pEdgeColorLight;
		//Drawing::Color pEdgeColorDark;
		System::Windows::Forms::Keys pSelectedKey;
		System::Windows::Forms::Keys pCurrentKey;
		bool bAwaitKey;

	public: // Events
		event GTA::KeyEventHandler^ SelectedKeyChanged;

	public protected:
		virtual void OnClick(GTA::MouseEventArgs^ e) override;
		virtual void OnKeyDown(GTA::KeyEventArgs^ e) override;
		virtual void OnKeyUp(GTA::KeyEventArgs^ e) override;

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;
		virtual void OnSelectedKeyChanged(GTA::KeyEventArgs^ e) {
			SelectedKeyChanged(this, e);
		}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(192,32);
			}
		}

	public:
		Keybox() {
			//pEdgeSize = 2;
			//pEdgeAlpha = 100;
			BackColor = Drawing::Color::FromArgb(50, 255, 255, 255);
			//pEdgeColorLight = Drawing::Color::FromArgb(pEdgeAlpha, 255, 255, 255);
			//pEdgeColorDark = Drawing::Color::FromArgb(pEdgeAlpha, 0, 0, 0);
			pSelectedKey = System::Windows::Forms::Keys::None;
			bAwaitKey = false;
		}

		property System::Windows::Forms::Keys SelectedKey {
			System::Windows::Forms::Keys get() {
				return pSelectedKey;
			}
			void set(System::Windows::Forms::Keys value) {
				if (pSelectedKey == value) return;
				pSelectedKey = value;
				OnSelectedKeyChanged(gcnew GTA::KeyEventArgs(value));
			}
		}

	};

}
}