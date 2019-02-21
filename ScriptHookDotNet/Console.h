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
	private ref class Console sealed : base::Console {

	private:
		bool bActive;
		//Keys pActivationKey;
		String^ pInput;
		Font^ pFont;
		Drawing::Color pBackColor;
		Drawing::Color pForeColor;
		//float LineDist;
		List<String^>^ pLog;
		List<String^>^ pLastCommands;
		int OldSelect;
		int LineOffset;
		static const int MAX_COMMANDS = 20;
		static const int MAX_LOG_LINES = 200;
		static const float WIDTH = 1.0f;
		static const float MIN_HEIGHT = 0.25f;
		static const float STEP_HEIGHT = 0.25f;
		static const float MAX_HEIGHT = 0.75f;
		//float pWidth;
		float pHeight;
		float pHeightPercentage;
		float pBorder;
		static array<System::Char>^ splitChars = gcnew array<System::Char>(2) {'\n', '\r'};
		static array<System::String^>^ splitStrings = gcnew array<System::String^>(1) {Environment::NewLine};

		Drawing::RectangleF scrollRect;
		int scrollOffset;

		int ArrayIndexToPos(int Index);
		int NewestToArrayIndex(int Index);
		//System::String^ KeyToString(Keys key);

		List<String^>^ ParseString(String^ input);
		String^ ParseSlashChar(Byte input);

		void SendCommand();
		void AddPrintLine(String^ Text);
		int FirstLineOnScreen();
		int LastLineOnScreen();
		int posToLineOffset(int posY);

	internal:

		Console();
		void PressKey(WinForms::Keys key);
		void MouseDown(System::Object^ sender, GTA::MouseEventArgs^ e);
		void MouseUp(System::Object^ sender, GTA::MouseEventArgs^ e);
		//void Tick();
		void PerFrameDrawing(GTA::Graphics^ Graphics);
		void AddOldCommand(String^ CommandLine);
 
	public:
		event ConsoleEventHandler^ Command;
		event EventHandler^ Opened;
		event EventHandler^ Closed;

		property bool isActive {
			virtual bool get() override {
				return bActive;
			}
		}
		property float Height {
			float get() {
				return pHeight;
			}
		}
		property WinForms::Keys ActivationKey {
			WinForms::Keys get();
		}
		property int LinesOnScreen {
			int get();
		}
		property int LinesPerScreen {
			int get();
		}
		property int LineCount {
			int get();
		}
		float LineScrollPos(int LineID);

		void ScrollToStart();
		void ScrollToEnd();

		virtual void Open(String^ DefaultInput) override;
		virtual void Open() override;

		virtual void Close() override;

		virtual void SendCommand(String^ CommandLine) override;
		virtual void Print(String^ Text) override;

	protected:

		virtual void OnCommand(ConsoleEventArgs^ e) {
			Command(this,e);
		}

	};

	CLASS_ATTRIBUTES
	private ref class RemoteConsole sealed : base::Console  {
	public:

		property bool isActive {
			virtual bool get() override;
		}

		virtual void Open(String^ DefaultInput) override;
		virtual void Open() override;

		virtual void Close() override;

		virtual void SendCommand(String^ CommandLine) override;
		virtual void Print(String^ Text) override;

	};

}