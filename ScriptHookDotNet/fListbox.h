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
	public value class ListboxItem : System::IEquatable<ListboxItem> {

	private:
		System::Object^ pValue;
		String^ pDisplayText;

	public:
		ListboxItem(System::Object^ Value, String^ DisplayText) {
			pValue = Value;
			pDisplayText = DisplayText;
		}
		ListboxItem(System::Object^ Value) {
			pValue = Value;
			pDisplayText = String::Empty;
		}

		property System::Object^ Value {
			System::Object^ get() {
				return pValue;
			}
		}
		property String^ DisplayText {
			String^ get() {
				if ( isNotNULL(pDisplayText) && (pDisplayText->Length > 0) ) return pDisplayText;
				if isNULL(pValue) return "{NULL}";
				return pValue->ToString();
			}
		}

		virtual bool Equals(ListboxItem other) { //System::IEquatable<ListboxItem>::Equals
			if isNULL(other) return false;
			if isNULL(pValue) return isNULL(other.pValue);
			if isNULL(other.pValue) return false;
			return pValue->Equals(other.pValue);
		}

	};

	CLASS_ATTRIBUTES
	[System::ComponentModel::DefaultEventAttribute("SelectedIndexChanged")]
	public ref class Listbox : public GTA::Forms::Control {

	public: 

		ref class ItemCollection : base::Collection<ListboxItem> {
		public:
			void Add(System::Object^ Value, String^ DisplayText) {
				base::Collection<ListboxItem>::Add(ListboxItem(Value, DisplayText));
			}
			void Add(System::Object^ Value) {
				base::Collection<ListboxItem>::Add(ListboxItem(Value));
			}

			void Remove(System::Object^ Value) {
				for (int i = Count-1; i>=0; i--) {
					if isNULL(this[i].Value)
						if isNULL(Value) RemoveAt(i);
					else
						if (this[i].Value->Equals(Value)) RemoveAt(i);
				}
			}

			int IndexOf(System::Object^ Value) {
				if isNULL(Value) {
					for (int i = 0; i < Count; i++) {
						if isNULL(this[i].Value) return i;
					}
				} else {
					for (int i = 0; i < Count; i++) {
						if (Value->Equals(this[i].Value)) return i;
					}
				}
				return -1;
			}
		
		};

	private:
		ItemCollection^ pItems;
		bool pBorder;
		int pSelectedIndex;
		Scrollbar^ scr;
		int pScrollbarSize;
		Drawing::Color pSelectionColor;

		void ResizeScrollbar();

	public:
		Listbox();

		event EventHandler^ SelectedIndexChanged;

	public protected:

		virtual void OnMouseDown(GTA::MouseEventArgs^ e) override;

	protected:
		virtual void OnPaint(GTA::GraphicsEventArgs^ e) override;
		virtual void OnResize(EventArgs^ e) override {
			ResizeScrollbar();
			Control::OnResize(e);
		}

		virtual void OnSelectedIndexChanged(EventArgs^ e) {
			SelectedIndexChanged(this, e);
		}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() override {
				return Drawing::Size(128,128);
			}
		}

	public:

		property ItemCollection^ Items {
			ItemCollection^ get() {
				if isNULL(pItems) pItems = gcnew ItemCollection();
				return pItems;
			}
		}

		property bool Border {
			bool get() { return pBorder; }
			void set(bool value) { pBorder = value; }
		}
		property int ScrollbarSize {
			int get() { return pScrollbarSize; }
			void set(int value) {
				if (pScrollbarSize == value) return;
				pScrollbarSize = value;
				ResizeScrollbar();
			}
		}
		property Drawing::Color SelectionColor {
			Drawing::Color get() {
				return pSelectionColor;
			}
			void set(Drawing::Color value) {
				pSelectionColor = value;
			}
		}

		property int SelectedIndex {
			int get() { return pSelectedIndex; }
			void set(int value) {
				if (pSelectedIndex == value) return;
				pSelectedIndex = value;
				OnSelectedIndexChanged(EventArgs::Empty);
			}
		}
		property ListboxItem SelectedItem {
			ListboxItem get() {
				if ( (pSelectedIndex < 0) || (pSelectedIndex >= Items->Count) ) return ListboxItem();
				return Items[pSelectedIndex];
			}
		}
		property System::Object^ SelectedValue {
			System::Object^ get() { return SelectedItem.Value; }
			void set(System::Object^ value) { SelectedIndex = Items->IndexOf(value); }
		}

	};

}
}