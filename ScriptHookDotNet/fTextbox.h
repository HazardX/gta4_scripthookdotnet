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
	public ref class Textbox : public GTA::Forms::Control {

	private:
		int pCursorPos;
		int pMaxLength;
		bool pBorder;

	public:
		Textbox() {
			BackColor = Drawing::Color::FromArgb(50, 255, 255, 255);
			pCursorPos = 0;
			pMaxLength = -1;
			pBorder = true;
		}

	public protected:

		virtual void OnKeyDown(GTA::KeyEventArgs^ e) override;

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(128,32);
			}
		}

	public:

		property bool Border {
			bool get() { return pBorder; }
			void set(bool value) { pBorder = value; }
		}

		property int MaxLength {
			int get() { return pMaxLength; }
			void set(int value) { pMaxLength = value; }
		}

	};

}
}