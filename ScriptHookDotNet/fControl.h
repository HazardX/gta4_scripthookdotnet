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

	ref class ControlCollection;

	CLASS_ATTRIBUTES
	[System::ComponentModel::DefaultEventAttribute("Click")]
	public ref class Control abstract : System::ComponentModel::Component {

	private:
		String^ pName;
		String^ pText;
		GTA::Font^ pFont;
		bool bVisible;
		Drawing::Point pLocation;
		Drawing::Size pSize;
		ControlCollection^ pControls;
		Control^ pParent;
		Drawing::Color pBackColor;
		Drawing::Color pBorderColorLight;
		Drawing::Color pBorderColorDark;
		Drawing::Color pForeColor;

		static GTA::Font^ pDefaultFont;

	protected:
		static property GTA::Font^ DefaultFont {
			GTA::Font^ get();
		}

	internal:

		property Drawing::Color BorderColorLight {
			Drawing::Color get() {
				return pBorderColorLight;
			}
			void set(Drawing::Color value) {
				pBorderColorLight = value;
			}
		}
		property Drawing::Color BorderColorDark {
			Drawing::Color get() {
				return pBorderColorDark;
			}
			void set(Drawing::Color value) {
				pBorderColorDark = value;
			}
		}

		void DrawBorder3D(GTA::Graphics^ g, Drawing::Rectangle rect, bool Up, int Width);
		void DrawEffectLine(GTA::Graphics^ g, float Width, Drawing::Color LineColor, Drawing::Color EffectColor, ... array<Drawing::Point>^ Points);
		void DrawEffectLine(GTA::Graphics^ g, float Width, ... array<Drawing::Point>^ Points);

		Drawing::Rectangle GrowLeftRight(Drawing::Rectangle rect, int amount) {
			return Drawing::Rectangle(rect.X-amount, rect.Y, rect.Width+amount*2, rect.Height);
		}
		Drawing::Rectangle GrowLeft(Drawing::Rectangle rect, int amount) {
			return Drawing::Rectangle(rect.X-amount, rect.Y, rect.Width+amount, rect.Height);
		}
		
		void DoTick();
		void TriggerPaint(GraphicsEventArgs^ e);

		virtual void InitEarlyValues(){}

		void SetParent(Control^ Parent) {
			pParent = Parent;
		}
		virtual Form^ GetForm() {
			if isNULL(pParent) return nullptr;
			return pParent->GetForm();
		}

		property Drawing::Rectangle ScreenRectangle {
			Drawing::Rectangle get() {
				Drawing::Rectangle rect = Drawing::Rectangle(pLocation,pSize);
				if isNULL(Parent) return rect;
				return Parent->RectangleToScreen(rect);
			}
		}

		static float tosX(int ScreenPosX);
		static float tosY(int ScreenPosY);

	public:
		event EventHandler^ VisibleChanged;
		event EventHandler^ GotFocus;
		event GTA::GraphicsEventHandler^ Paint;
		event GTA::MouseEventHandler^ MouseDown;
		event GTA::MouseEventHandler^ MouseUp;
		event GTA::MouseEventHandler^ Click;
		event GTA::KeyEventHandler^ KeyDown;
		event GTA::KeyEventHandler^ KeyUp;

	internal:
		virtual void OnDragging(GTA::MouseEventArgs^ e) {}

	protected:
		virtual void OnVisibleChanged(EventArgs^ e) {
			VisibleChanged(this, e);
		}
		virtual void OnPaint(GTA::GraphicsEventArgs^ e);
		virtual void OnResize(EventArgs^ e) {}
		virtual void OnTextChanged(EventArgs^ e) {}

		property Drawing::Size DefaultSize {
			virtual Drawing::Size get() {
				return Drawing::Size(64,64);
			}
		}

	public protected:
		virtual void OnMouseDown(GTA::MouseEventArgs^ e) {
			MouseDown(this, e);
		}
		virtual void OnMouseUp(GTA::MouseEventArgs^ e) {
			MouseUp(this, e);
		}
		virtual void OnClick(GTA::MouseEventArgs^ e) {
			Click(this, e);
		}
		virtual void OnDragRelease(GTA::MouseEventArgs^ e) {}

		virtual void OnKeyDown(GTA::KeyEventArgs^ e) {
			KeyDown(this, e);
		}
		virtual void OnKeyUp(GTA::KeyEventArgs^ e) {
			KeyUp(this, e);
		}
		virtual void OnGotFocus(GTA::EventArgs^ e) {
			GotFocus(this, e);
		}

	public:
		[System::Diagnostics::DebuggerNonUserCode()]
		Control();



		property String^ Name {
			String^ get() {
				return pName;
			}
			void set(String^ value) {
				pName = value;
			}
		}
		[System::Diagnostics::DebuggerNonUserCode()]
		property String^ Text {
			String^ get() {
				if isNULL(pText) return Name;
				return pText;
			}
			void set(String^ value) {
				if ((Text == value) && (isNULL(Text) == isNULL(value))) return;
				pText = value;
				OnTextChanged(EventArgs::Empty);
			}
		}
		property bool Visible {
			bool get() {
				return bVisible;
			}
			void set(bool value);
		}
		property Drawing::Point Location {
			Drawing::Point get() {
				return pLocation;
			}
			void set(Drawing::Point value) {
				pLocation = value;
			}
		}
		property Drawing::Size Size {
			Drawing::Size get() {
				return pSize;
			}
			void set(Drawing::Size value) {
				pSize = value;
				OnResize(EventArgs::Empty);
			}
		}
		property int Width {
			int get() {
				return pSize.Width;
			}
			void set(int value) {
				Size = Drawing::Size(value,pSize.Height);
			}
		}
		property int Height {
			int get() {
				return pSize.Height;
			}
			void set(int value) {
				Size = Drawing::Size(pSize.Width, value);
			}
		}
		property Drawing::Rectangle ClientRectangle {
			virtual Drawing::Rectangle get() {
				return Drawing::Rectangle(0,0,pSize.Width,pSize.Height);
			}
		}
		property ControlCollection^ Controls {
			ControlCollection^ get() {
				return pControls;
			}
		}
		property Control^ Parent {
			Control^ get() {
				return pParent;
			}
			void set(Control^ value);
		}
		property Form^ ParentForm {
			Form^ get() {
				return GetForm();
			}
		}

		property GTA::Font^ Font {
			GTA::Font^ get();
			void set(GTA::Font^ value) {
				pFont = value;
			}
		}

		property Drawing::Color BackColor {
			Drawing::Color get() {
				return pBackColor;
			}
			void set(Drawing::Color value) {
				pBackColor = value;
			}
		}

		/// <summary>
		/// Gets or sets the Alpha value of the BackColor property. Range from 0.0 (opaque) to 1.0 (invisible).
		/// </summary>
		property float Transparency {
			float get() {
				return (float(255-pBackColor.A)/255.0f);
			}
			void set(float value) {
				if (value < 0.0f) value = 0.0f;
				if (value > 1.0f) value = 1.0f;
				pBackColor = Drawing::Color::FromArgb( (255-int(value*255.0f)) ,pBackColor);
			}
		}
		property Drawing::Color ForeColor {
			Drawing::Color get() {
				return pForeColor;
			}
			void set(Drawing::Color value) {
				pForeColor = value;
			}
		}

		Drawing::Point PointToClient(Point ScreenPoint);
		Drawing::Point PointToScreen(Point ClientPoint);
		Drawing::Rectangle RectangleToClient(Drawing::Rectangle ScreenRect) {
			return Drawing::Rectangle(PointToClient(ScreenRect.Location), ScreenRect.Size);
		}
		Drawing::Rectangle RectangleToScreen(Drawing::Rectangle ClientRect) {
			return Drawing::Rectangle(PointToScreen(ClientRect.Location), ClientRect.Size);
		}

		bool isPointInside(Point ScreenPoint, bool NotWhenInSubcontrol);
		Control^ GetControlAt(Point ScreenPoint);

	};

	CLASS_ATTRIBUTES
	public ref class ControlCollection : public base::ReadOnlyCollection<Control^> {

	private:
		Control^ pParent;

		bool ContainsName(String^ Name) {
			for (int i = 0; i < Count; i++) {
				if (Name->Equals(this->default[i]->Name, StringComparison::InvariantCultureIgnoreCase)) return true;
			}
			return false;
		}

		String^ GetDefaultName(String^ TypeName) {
			int id = 0;
			String^ NewName;
			do {
				id++;
				NewName = TypeName + id.ToString();
			} while(ContainsName(NewName));
			return NewName;
		}

		void AfterAdd(Control^ item) {
			item->Parent = pParent;
			if (item->Name->Length == 0) item->Name = GetDefaultName(item->GetType()->Name);
		}

	internal:
		ControlCollection(Control^ Parent) {
			pParent = Parent;
		}

	protected:

		virtual bool isReadOnly() override {
			return false;
		}

	public:

		property Control^ Parent {
			Control^ get() {
				return pParent;
			}
		}

		void Add(Control^ item) {
			if isNULL(item) return;
			if (Contains(item)) return;
			pAdd(item);
			AfterAdd(item);
		}
		void AddRange(System::Collections::Generic::IEnumerable<Control^>^ collection) {
			for each (Control^ c in collection) {
				Add(c);
			}
		}

		void Insert(int index, Control^ item) {
			if isNULL(item) return;
			if (Contains(item)) return;
			pInsert(index,item);
			AfterAdd(item);
		}

		bool Remove(Control^ item) {
			if isNULL(item) return false;
			if (!pRemove(item)) return false;
			item->Parent = nullptr;
			return true;
		}

		void RemoveAt(int index) {
			Remove(this->default[index]);
		}

		void Clear() {
			for (int i = Count-1; i >= 0; i--) {
				Remove(this->default[i]);
			}
			pClear();
		}

	};

}
}