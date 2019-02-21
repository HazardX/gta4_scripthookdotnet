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
	[System::ComponentModel::DefaultEventAttribute("ValueChanged")]
	public ref class Scrollbar : public GTA::Forms::Control {

	private:
		Drawing::Color pDownColor;
		//Drawing::Color pArrowColor;
		int pValue;
		int pMinValue;
		int pMaxContentValue;
		int pContentSize;

		int pDownOn; // 1 = grabhandle, 2 = minus, 3 = plus
		int pWasDownOn;
		int pMouseOffset;

		bool bHorizontal;
		bool pHasGrabHandle;
		int pLongSideSize;
		int pShortSideSize;
		int pButtonSize;
		int pHandleBarSize;
		int pGrabHandleSize;
		int pGrabHandleOffset;
		static int pGrabHandleMargin = 2;
		Drawing::Rectangle pButtonRectMinus;
		Drawing::Rectangle pButtonRectPlus;
		Drawing::Rectangle pButtonRectGrabHandle;
		Drawing::Rectangle pSpaceRectMinus;
		Drawing::Rectangle pSpaceRectPlus;

	public:
		Scrollbar() {
			pDownColor = Drawing::Color::FromArgb(30, 0, 0, 0);
			//pArrowColor = Drawing::Color::FromArgb(240, 48, 64, 192);
			pDownOn = 0;
			pValue = 1;
			pMinValue = 1;
			pMaxContentValue = 100;
			pContentSize = 10;
		}

		//property Drawing::Color ArrowColor {
		//	Drawing::Color get() {
		//		return pArrowColor;
		//	}
		//	void set(Drawing::Color value) {
		//		pArrowColor = value;
		//	}
		//}
		
		property int MinValue {
			int get() {
				return pMinValue;
			}
			void set(int value) {
				pMinValue = value;
				if (pValue < value) Value = value;
			}
		}
		property int MaxContentValue {
			int get() {
				return pMaxContentValue;
			}
			void set(int value) {
				pMaxContentValue = value;
				if (pValue > MaxValue) Value = MaxValue;
			}
		}
		property int MaxValue {
			int get() {
				return pMaxContentValue - pContentSize + 1;
			}
			void set(int value) {
				pMaxContentValue = value + pContentSize - 1;
				if (pValue > value) Value = value;
			}
		}
		property int ContentSize {
			int get() {
				return pContentSize;
			}
			void set(int value) {
				if (value < 1) value = 1;
				pContentSize = value;
				if (pValue > MaxValue) Value = MaxValue;
			}
		}
		property int Value {
			int get() {
				return pValue;
			}
			void set(int value);
		}

		event EventHandler^ ValueChanged;

	public protected:

		virtual void OnMouseDown(GTA::MouseEventArgs^ e) override;
		virtual void OnDragRelease(GTA::MouseEventArgs^ e) override;
		virtual void OnClick(GTA::MouseEventArgs^ e) override;

	internal:
		virtual void OnDragging(GTA::MouseEventArgs^ e) override;

	protected:
		virtual void OnValueChanged(EventArgs^ e) {
			ValueChanged(this, e);
		}

		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(16,128);
			}
		}

	private:

		property bool HasSpaceRectMinus {
			bool get() {
				if (!pHasGrabHandle) return false;
				if (bHorizontal)
					return (pSpaceRectMinus.Width > 0);
				else
					return (pSpaceRectMinus.Height > 0);
			}
		}
		property bool HasSpaceRectPlus {
			bool get() {
				if (!pHasGrabHandle) return false;
				if (bHorizontal)
					return (pSpaceRectPlus.Width > 0);
				else
					return (pSpaceRectPlus.Height > 0);
			}
		}

		property int SmallChange {
			int get() {
				return 1;
			}
		}
		property int LargeChange {
			int get() {
				if (pContentSize <= 1) return 1;
				return (pContentSize - 1);
			}
		}

		void UpdateBarLayout() {
			bHorizontal = Size.Width > Size.Height;
			if (bHorizontal) {
				pLongSideSize = Size.Width;
				pShortSideSize = Size.Height;
			} else {
				pLongSideSize = Size.Height;
				pShortSideSize = Size.Width;
			}
			pHasGrabHandle = (pLongSideSize > (pShortSideSize*2));
			if (pHasGrabHandle) {
				pButtonSize = pShortSideSize;
				pHandleBarSize = pLongSideSize - (pButtonSize*2);
				pGrabHandleSize = int( (float(ContentSize) / float(MaxContentValue - MinValue)) * float(pHandleBarSize-pGrabHandleMargin*2) );
				if (pGrabHandleSize < 8) pGrabHandleSize = 8;
				pGrabHandleOffset = pGrabHandleMargin + int( (float(Value - MinValue) / float(MaxValue - MinValue)) * float(pHandleBarSize-pGrabHandleSize-pGrabHandleMargin*2) );
			} else {
				pButtonSize = pLongSideSize/2;
				pHandleBarSize = 0;
				pButtonRectGrabHandle = Drawing::Rectangle();
				pSpaceRectMinus = Drawing::Rectangle();
				pSpaceRectPlus = Drawing::Rectangle();
				pGrabHandleSize = 0;
				pGrabHandleOffset = 0;
			}

			pButtonRectMinus.Location = ScreenRectangle.Location;
			if (bHorizontal) {
				pButtonRectMinus.Height = pShortSideSize;
				pButtonRectMinus.Width = pButtonSize;
				pButtonRectPlus.Y = pButtonRectMinus.Y;
				pButtonRectPlus.X = pButtonRectMinus.X + (pLongSideSize - pButtonSize);
				pButtonRectPlus.Height = pShortSideSize;
				pButtonRectPlus.Width = pButtonSize;
				if (pHasGrabHandle) {
					pButtonRectGrabHandle.Height = pShortSideSize;
					pButtonRectGrabHandle.Width = pGrabHandleSize;
					pButtonRectGrabHandle.Y = pButtonRectMinus.Y;
					pButtonRectGrabHandle.X = pButtonRectMinus.Right + pGrabHandleOffset;

					pSpaceRectMinus.Y = pButtonRectMinus.Y;
					pSpaceRectMinus.X = pButtonRectMinus.Right;
					pSpaceRectMinus.Height = pShortSideSize;
					pSpaceRectMinus.Width = pButtonRectGrabHandle.X - pSpaceRectMinus.X;

					pSpaceRectPlus.Y = pButtonRectMinus.Y;
					pSpaceRectPlus.X = pButtonRectGrabHandle.Right;
					pSpaceRectPlus.Height = pShortSideSize;
					pSpaceRectPlus.Width = pButtonRectPlus.X - pSpaceRectPlus.X;
				}
			} else {
				pButtonRectMinus.Width = pShortSideSize;
				pButtonRectMinus.Height = pButtonSize;
				pButtonRectPlus.X = pButtonRectMinus.X;
				pButtonRectPlus.Y = pButtonRectMinus.Y + (pLongSideSize - pButtonSize);
				pButtonRectPlus.Width = pShortSideSize;
				pButtonRectPlus.Height = pButtonSize;
				if (pHasGrabHandle) {
					pButtonRectGrabHandle.Width = pShortSideSize;
					pButtonRectGrabHandle.Height = pGrabHandleSize;
					pButtonRectGrabHandle.X = pButtonRectMinus.X;
					pButtonRectGrabHandle.Y = pButtonRectMinus.Bottom + pGrabHandleOffset;

					pSpaceRectMinus.X = pButtonRectMinus.X;
					pSpaceRectMinus.Y = pButtonRectMinus.Bottom;
					pSpaceRectMinus.Width = pShortSideSize;
					pSpaceRectMinus.Height = pButtonRectGrabHandle.Y - pSpaceRectMinus.Y;

					pSpaceRectPlus.X = pButtonRectMinus.X;
					pSpaceRectPlus.Y = pButtonRectGrabHandle.Bottom;
					pSpaceRectPlus.Width = pShortSideSize;
					pSpaceRectPlus.Height = pButtonRectPlus.Y - pSpaceRectPlus.Y;
				}
			}
		}
		
	};

}
}