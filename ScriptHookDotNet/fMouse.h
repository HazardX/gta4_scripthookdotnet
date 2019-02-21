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

	CLASS_ATTRIBUTES
	private ref class Mouse : base::Mouse {

	private:
		////static String^ TXD = "network";
		////static String^ TEX = "MOUSECURSOR";
		//Texture^ TexArrow;
		//Texture^ TexUpDown;
		bool bEnabled;
		Drawing::PointF pPosition;
		Drawing::PointF pMovement;
		System::Windows::Forms::MouseButtons pButtons;
		CursorType pCursor;

		Drawing::PointF GetMovement();
		//array<bool>^ buttonstate;

	internal:
		Mouse();

		void Check();
		void Draw(Graphics^ g);
		//void CheckButton(System::Windows::Forms::Keys Key);
		void CheckButtonDown(System::Windows::Forms::Keys Key);
		void CheckButtonUp(System::Windows::Forms::Keys Key);
		void DoButtonDown(System::Windows::Forms::MouseButtons Button);
		void DoButtonUp(System::Windows::Forms::MouseButtons Button);

	public:
		event MouseEventHandler^ ButtonDown;
		event MouseEventHandler^ ButtonUp;

		property bool Enabled {
			virtual bool get() override {
				return bEnabled;
			}
			virtual void set(bool value) override;
		}
		property CursorType Cursor {
			CursorType get() {
				return pCursor;
			}
			void set(CursorType value) {
				pCursor = value;
			}
		}
		property Drawing::PointF Position {
			virtual Drawing::PointF get() override {
				return pPosition;
			}
		}
		property Drawing::PointF Movement {
			virtual Drawing::PointF get() override {
				return pMovement;
			}
		}
		property System::Windows::Forms::MouseButtons PressedButtons {
			virtual System::Windows::Forms::MouseButtons get() override {
				return pButtons;
			}
		}

		virtual bool isButtonDown(System::Windows::Forms::MouseButtons Button) override {
			return ((pButtons & Button) == Button);
		}

	};

	CLASS_ATTRIBUTES
	private ref class RemoteMouse : base::Mouse {

	private:
		bool bEnabled;
		Drawing::PointF pPosition;
		Drawing::PointF pMovement;
		System::Windows::Forms::MouseButtons pButtons;

	internal:
		RemoteMouse() {
			bEnabled = false;
			pPosition = Drawing::PointF(0.5f, 0.5f);
			pMovement = Drawing::PointF(0.0f, 0.0f);
			pButtons = System::Windows::Forms::MouseButtons::None;
		}

		void SetValues(bool Enabled, Drawing::PointF Position, Drawing::PointF Movement, System::Windows::Forms::MouseButtons Buttons) {
			bEnabled = Enabled;
			pPosition = Position;
			pMovement = Movement;
			pButtons = Buttons;
		}

	public:

		property bool Enabled {
			virtual bool get() override {
				return bEnabled;
			}
			virtual void set(bool value) override;
		}
		property Drawing::PointF Position {
			virtual Drawing::PointF get() override {
				return pPosition;
			}
		}
		property Drawing::PointF Movement {
			virtual Drawing::PointF get() override {
				return pMovement;
			}
		}
		property System::Windows::Forms::MouseButtons PressedButtons {
			virtual System::Windows::Forms::MouseButtons get() override {
				return pButtons;
			}
		}

		virtual bool isButtonDown(System::Windows::Forms::MouseButtons Button) override {
			return ((pButtons & Button) == Button);
		}

	};

}
}