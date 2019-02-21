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
	[System::ComponentModel::DefaultEventAttribute("Opened")]
	public ref class Form : public GTA::Forms::Control {

	private:
		GTA::Script^ pScript;
		Drawing::Color pTitleBackColor;
		GTA::Font^ pSymbolFont;
		int pTitleSize;
		int pBorder;
		Windows::Forms::DialogResult pDialogResult;
		bool pBlockVisibleChanged;
		FormStartPosition pStartPosition;

		bool bDragClose;
		bool bDragTitle;
		Drawing::Point pDragOffset;

		Drawing::Color pDisabledBackColor;
		Drawing::Color pDisabledTitleColor;
		Drawing::Color pDisabledFontColor;

		Button^ pAcceptButton;
		Button^ pCancelButton;

		void AcceptButton_Click(System::Object^ sender, MouseEventArgs^ e);
		void CancelButton_Click(System::Object^ sender, MouseEventArgs^ e);

		FormHost^ GetFormHost();

	public:
		event EventHandler^ Closed;
		event EventHandler^ Opened;

	internal:
		virtual void OnDragging(GTA::MouseEventArgs^ e) override;

		virtual Form^ GetForm() override {
			return this;
		}

		virtual void InitEarlyValues() override;

		void TriggerBackgroundPaint(GTA::GraphicsEventArgs^ e);

		property GTA::Script^ Script {
			GTA::Script^ get() { return pScript; }
		}

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;
		virtual void OnVisibleChanged(EventArgs^ e) override;

		//virtual void OnLoad(EventArgs^ e) {
		//	Load(this, e);
		//}
		virtual void OnClosed(EventArgs^ e) {
			Closed(this, e);
		}
		virtual void OnOpened(EventArgs^ e) {
			Opened(this, e);
		}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(640,480);
			}
		}

		/// <summary>
		/// Allows access to resources embedded in the script
		/// </summary>
		property value::Resources^ Resources {
			value::Resources^ get();
		}

	public protected:
		virtual void OnMouseDown(GTA::MouseEventArgs^ e) override;
		virtual void OnDragRelease(GTA::MouseEventArgs^ e) override;

	public:
		Form();

		property Drawing::Color TitleBackColor {
			Drawing::Color get() {
				return pTitleBackColor;
			}
			void set(Drawing::Color value) {
				pTitleBackColor = value;
			}
		}
		property int TitleSize {
			int get() {
				return pTitleSize;
			}
			void set(int value);
		}

		property FormStartPosition StartPosition {
			FormStartPosition get() {
				return pStartPosition;
			}
			void set(FormStartPosition value) {
				pStartPosition = value;
			}
		}

		property Windows::Forms::DialogResult DialogResult {
			Windows::Forms::DialogResult get() {
				return pDialogResult;
			}
			void set(Windows::Forms::DialogResult value) {
				pDialogResult = value;
			}
		}

		property Drawing::Rectangle ClientRectangle {
			virtual Drawing::Rectangle get() override {
				return Drawing::Rectangle(pBorder, pTitleSize+pBorder, Size.Width-pBorder-pBorder, Size.Height-pTitleSize-pBorder-pBorder);
			}
		}

		property Button^ AcceptButton {
			Button^ get() {
				return pAcceptButton;
			}
			void set(Button^ value);
		}
		property Button^ CancelButton {
			Button^ get() {
				return pCancelButton;
			}
			void set(Button^ value);
		}

		void Close();
		void Show();
		Windows::Forms::DialogResult ShowDialog();

	};

}
}