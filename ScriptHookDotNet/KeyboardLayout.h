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
	private ref class KeyboardLayout abstract {

	private:

		String^ ParseDefaultKey(int keycode, bool shift, bool ctrl, bool alt) {
			if ( !ctrl && !alt ) {
				if (!shift) {

					// Numbers
					if ((keycode >= 48) && (keycode <= 57))  return ((System::Char)(wchar_t)(keycode)   ).ToString();

					// Numpad
					if ((keycode >= 96) && (keycode <= 105)) return ((System::Char)(wchar_t)(keycode-48)).ToString();

					// Lower Letters
					if ((keycode >= 65) && (keycode <= 90)) return System::Char::ToLower((wchar_t)keycode).ToString();

				} else {

					// Upper Letters
					if ((keycode >= 65) && (keycode <= 90)) return System::Char::ToUpper((wchar_t)keycode).ToString();

				}
			}

			// Space/Tab
			if ((keycode == 32) || (keycode == 9)) return " ";

			return String::Empty;
		}

	protected:

		virtual String^ ParseSpecificKey(int keycode, bool shift, bool ctrl, bool alt) = 0;

	public:

		KeyboardLayout(){}

		property String^ Language {
			virtual String^ get() = 0;
		}
		property int ConsoleKey {
			virtual int get() = 0;
		}

		String^ ParseKey(int keycode, bool shift, bool ctrl, bool alt) {
			String^ res = ParseDefaultKey(keycode,shift,ctrl,alt);
			if (res->Length == 0) res = ParseSpecificKey(keycode,shift,ctrl,alt);
			return res;
		}

		String^ ParseKey(WinForms::Keys key) {
			int keycode = (int)(key & WinForms::Keys::KeyCode);
			bool shift = (((int)key&(int)WinForms::Keys::Shift) != 0);
			bool ctrl = (((int)key&(int)WinForms::Keys::Control) != 0);
			bool alt = (((int)key&(int)WinForms::Keys::Alt) != 0);
			return ParseKey(keycode,shift,ctrl,alt);
		}

	};

	private ref class KeyboardLayoutUS : KeyboardLayout {

	public:

		KeyboardLayoutUS(){}

		property String^ Language {
			virtual String^ get() override {
				return "us";
			}
		}
		property int ConsoleKey {
			virtual int get() override {
				return 192;
			}
		}

	protected:

		virtual String^ ParseSpecificKey(int keycode, bool shift, bool ctrl, bool alt) override {
			if (shift) {
				switch (keycode) {
					case 48: return ")";
					case 49: return "!";
					case 50: return "@";
					case 51: return "#";
					case 52: return "$";
					case 53: return "%";
					case 54: return "^";
					case 55: return "&";
					case 56: return "*";
					case 57: return "(";
					case 186: return ":";
					case 187: return "+";
					case 188: return "<";
					case 189: return "_";
					case 190: return ">";
					case 191: return "?";
					case 192: return "~";
					case 219: return "{";
					case 220: return "|";
					case 221: return "}";
					case 222: return "\"";
					case 226: return "|";
				}

			} else if (ctrl) {

			} else if (alt) {

			} else {
				switch (keycode) {
					case 106: return "*";
					case 107: return "+";
					case 109: return "-";
					case 110: return ".";
					case 111: return "/";
					case 186: return ";";
					case 187: return "=";
					case 188: return ",";
					case 189: return "-";
					case 190: return ".";
					case 191: return "/";
					case 192: return "`";
					case 219: return "[";
					case 220: return "\\";
					case 221: return "]";
					case 222: return "'";
					case 226: return "\\";
				}
			}
			return String::Empty;
		}

	};

	private ref class KeyboardLayoutDE : KeyboardLayout {

		public:

		KeyboardLayoutDE(){}

		property String^ Language {
			virtual String^ get() override {
				return "de";
			}
		}
		property int ConsoleKey {
			virtual int get() override {
				return 220;
			}
		}

		protected:

		virtual String^ ParseSpecificKey(int keycode, bool shift, bool ctrl, bool alt) override {
			if (shift) {
				switch (keycode) {
					case 48: return "=";
					case 49: return "!";
					case 50: return "\"";
					case 51: return "§";
					case 52: return "$";
					case 53: return "%";
					case 54: return "&";
					case 55: return "/";
					case 56: return "(";
					case 57: return ")";
					case 186: return "Ü";
					case 187: return "*";
					case 188: return ";";
					case 189: return "_";
					case 190: return ":";
					case 191: return "'";
					case 192: return "Ö";
					case 219: return "?";
					case 220: return "°";
					case 221: return "'"; //`
					case 222: return "Ä";
					case 226: return ">";
				}

			} else if (ctrl && alt) {
				switch (keycode) {
					case 48: return "}";
					case 50: return "²";
					case 51: return "³";
					case 55: return "{";
					case 56: return "[";
					case 57: return "]";
					//case 69: return "€";  // doesn't work in GTA
					case 77: return "µ";
					case 81: return "@";
					case 187: return "~";
					case 192: return "Ö";
					case 219: return "\\";
					case 226: return "|";
				}

			} else if (ctrl) {

			} else if (alt) {

			} else {
				switch (keycode) {
					case 106: return "*";
					case 107: return "+";
					case 109: return "-";
					case 110: return ",";
					case 111: return "/";
					case 186: return "ü";
					case 187: return "+";
					case 188: return ",";
					case 189: return "-";
					case 190: return ".";
					case 191: return "#";
					case 192: return "ö";
					case 219: return "ß";
					case 220: return "^";
					case 221: return "'"; //´
					case 222: return "ä";
					case 226: return "<";
				}
			}
			return String::Empty;
		}

	};

}