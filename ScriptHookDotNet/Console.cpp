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

#include "stdafx.h"

/*#include "NetHook.h"
#include "RemoteScriptDomain.h"
#include "bConsole.h"*/

#include "Console.h"

#include "Font.h"
#include "Game.h"
#include "Graphics.h"
#include "KeyboardLayout.h"
#include "RemoteScriptDomain.h"
#include "fMouse.h"

#pragma managed

namespace GTA {

	//VkKeyScan ASCII -> virtual key

	Console::Console() {
		bActive = false;
		pInput = String::Empty;
		pLog = gcnew List<String^>();
		pLastCommands = gcnew List<String^>();
		OldSelect = 0;
		LineOffset = 0;

		//LineDist = 0.028f;
		//pWidth = WIDTH;
		pHeightPercentage = MIN_HEIGHT;
		pHeight = 0;
		pBorder = 8.0f; //0.005f;

		pBackColor = Drawing::Color::FromArgb(160,0,0,0);
		pForeColor = Drawing::Color::FromArgb(160, 0, 255, 0);
		pFont = gcnew Font("Courier New", 18.0f, FontScaling::Pixel);
		pFont->Color = Drawing::Color::FromArgb(0, 255, 0);
		//pFont->FontFamily = "Courier New";
		//pFont->Scaling = FontScaling::Pixel;
		//pFont->Width = -1.0f; //0.375f; //0.3375f; //0.3f;
		//pFont->Height = 18; //0.5f; //0.45f; //0.4f; // screen size: 0,023333333333333333333333333333333
		//pFont->LineHeight = 1.2f;
		//pFont->Effect = FontEffect::None;
		//pFont->Effect = FontEffect::Edge;
		//pFont->EffectSize = 1;
		//pFont->EffectColor = Drawing::Color::Black;
		//pFont->Scaling = FontScaling::Pixels;
		//pFont->WrapLineAt = 2.0f;

		//String^ lang = System::Globalization::CultureInfo::CurrentCulture->TwoLetterISOLanguageName->ToLower();
		//if (lang == "de") {
		//	KeyboardLayout = gcnew KeyboardLayoutDE();
		//} else {
		//	KeyboardLayout = gcnew KeyboardLayoutUS();
		//}

		scrollOffset = -1;

		//try {
		NetHook::LocalMouse->ButtonDown += gcnew MouseEventHandler(this, &GTA::Console::MouseDown);
		NetHook::LocalMouse->ButtonUp += gcnew MouseEventHandler(this, &GTA::Console::MouseUp);
		//} catchErrors("Error in Console constructor",)
	}

	WinForms::Keys Console::ActivationKey::get() {
		return (WinForms::Keys)NetHook::KeyboardLayout->ConsoleKey;
	}

	int Console::LinesPerScreen::get() {
		return int((pHeight-pBorder) / pFont->GetLineHeight(FontScaling::Pixel)) - 1; // Remove one for the input line
	}
	int Console::LineCount::get() {
		return pLog->Count;
	}

	int Console::ArrayIndexToPos(int Index) { // 0 = oldest, Count-1 = newest
		return (MAX_COMMANDS - pLastCommands->Count) + Index;
	}
	int Console::NewestToArrayIndex(int Index) { // 0 = newest
		return pLastCommands->Count - Index - 1;
	}

	int Console::FirstLineOnScreen() {
		int res = LastLineOnScreen() - LinesPerScreen + 1;
		if (res < 0) res = 0;
		return res;
	}
	int Console::LastLineOnScreen() {
		int res = LineCount-LineOffset-1;
		if (res < 0) res = 0;
		return res;
	}
	int Console::LinesOnScreen::get() {
		return (LastLineOnScreen()-FirstLineOnScreen()+1);
	}


	float Console::LineScrollPos(int LineID) {
		return (float(LineID)/float(LineCount))*pHeight;
	}

	int Console::posToLineOffset(int posY) {
		int lines = LineCount;
		int lps = LinesPerScreen;
		if (lines <= lps) return 0;
		float height = pHeightPercentage * Game::Resolution.Height;	
		float pos = float(posY) / height;
		if (pos <= 0.0f) return lines; //pos = 0.0f;
		if (pos >= 1.0f) return 0; //pos = 1.0f;
		int res = int((1.0f - pos) * float(lines));
		if (res > (lines - lps)) res = (lines - lps);
		return res;
	}

	//void Console::Tick() {
	//	if (!bActive) return;

	//	//if (pHeightPercentage > 0.9F)
	//	//	Graphics->HideHUD();
	//	//else
	//	//	Graphics->HideHelpText();
	//}

	void Console::PerFrameDrawing(GTA::Graphics^ Graphics) {
		if (!bActive) return;

		Graphics->Scaling = FontScaling::Pixel;

		float lh = pFont->GetLineHeight(FontScaling::Pixel); //FontScaling::ScreenUnits); //LineDist * (600.0f/float(Game::Resolution.Height));
		float scrWidth = 16.0f; //Graphics::ConvertPixelToUnitsX(16);

		Drawing::Size res = Game::Resolution;
		pHeight = pHeightPercentage * res.Height;

		if (scrollOffset >= 0) LineOffset = posToLineOffset(NetHook::Mouse->PositionPixel.Y + scrollOffset);

		Graphics->DrawRectangle(Drawing::RectangleF(0.0f,0.0f,float(res.Width),pHeight),pBackColor);
		scrollRect = Drawing::RectangleF(res.Width-scrWidth,LineScrollPos(FirstLineOnScreen()),scrWidth,LineScrollPos(LinesOnScreen));
		Graphics->DrawRectangle(scrollRect,pForeColor);

		bool blink = (DateTime::Now.Millisecond < 500); //((DateTime::Now.Second % 2) == 0);
		float pos = pHeight - lh - (pBorder * 0.5F);
		Graphics->DrawText(" > " + pInput->Replace("~","~~") + (blink ? "_" : String::Empty), pBorder, pos, pFont);
					
		if (pLog->Count > 0) {
			for (int i = pLog->Count-1-LineOffset; i >= 0; i--) {
				pos -= lh;
				if (pos < 0.0f) break;
				if(pLog->default[i]->Length>0) Graphics->DrawText(pLog->default[i], pBorder, pos, pFont);
			}
		}
		//NetHook::DisplayText("FL: " + FirstLineOnScreen() + " LL: " + LastLineOnScreen() + " LC: " + LineCount,1000);
	}

	void Console::MouseDown(System::Object^ sender, GTA::MouseEventArgs^ e) {
		if (!bActive) return;
		Drawing::Point pos = e->PixelLocation;
		if (!scrollRect.Contains(pos)) return;
		scrollOffset = int(scrollRect.Bottom) - pos.Y;
	}
	void Console::MouseUp(System::Object^ sender, GTA::MouseEventArgs^ e) {
		scrollOffset = -1;
	}

	void Console::PressKey(WinForms::Keys key) {
		WinForms::Keys code = key & WinForms::Keys::KeyCode;
		if (code == ActivationKey) {
			if (bActive)
				Close();
			else
				Open();
			return;
		}
		if (!bActive) return;
		if ((code == WinForms::Keys::Enter) || (code == WinForms::Keys::Return)) {
			SendCommand();
			return;

		} else if (code == WinForms::Keys::Escape) {
			Close();
			return;

		} else if (code == WinForms::Keys::Back) {
			if (pInput->Length >0) pInput = pInput->Substring(0,pInput->Length-1);
			return;

		} else if ((code == WinForms::Keys::Up) && (OldSelect < pLastCommands->Count)) {
			OldSelect++;
			pInput = pLastCommands->default[NewestToArrayIndex(OldSelect-1)];
			return;

		} else if ((code == WinForms::Keys::Down) && (OldSelect > 0)) {
			OldSelect--;
			if (OldSelect == 0)
				pInput = String::Empty;
			else
				pInput = pLastCommands->default[NewestToArrayIndex(OldSelect-1)];
			return;

		} else if (key == (WinForms::Keys::Add|WinForms::Keys::Shift)) {
			if (pHeightPercentage >= MAX_HEIGHT) {
				pHeightPercentage = 1.0f;
				//pWidth = WIDTH;
			} else {
				pHeightPercentage += STEP_HEIGHT;
			}
			return;

		} else if (key == (WinForms::Keys::Subtract|WinForms::Keys::Shift)) {
			if (pHeightPercentage > MIN_HEIGHT) {
				pHeightPercentage -= STEP_HEIGHT;
				//pWidth = WIDTH;
			} else {
				Close();
			}
			return;

		} else if (code == WinForms::Keys::PageUp) {
			if (int(key & WinForms::Keys::Shift) != 0) {
				ScrollToStart();
			} else {
				LineOffset += (LinesPerScreen-1);
				int maxpos = pLog->Count-LinesPerScreen;
				if (LineOffset > maxpos) LineOffset = maxpos;
			}

		} else if (code == WinForms::Keys::PageDown) {
			if (int(key & WinForms::Keys::Shift) != 0) {
				ScrollToEnd();
			} else {
				LineOffset -= (LinesPerScreen-1);
				if (LineOffset < 0) LineOffset = 0;
			}

		//} else if (code == WinForms::Keys::Home) {
		//	ScrollToStart();

		} else if (code == WinForms::Keys::End) {
			ScrollToEnd();

		}

		pInput += NetHook::KeyboardLayout->ParseKey(key);
	}

	void Console::ScrollToStart() {
		LineOffset = pLog->Count-LinesPerScreen;
	}
	void Console::ScrollToEnd() {
		LineOffset = 0;
	}

	void Console::Open() {
		if (bActive) return;
		//if (!Game::isModdingAllowed) {
		//	Game::DisplayText("Console deactivated in this multiplayer gamemode!", 5000);
		//	return;
		//}
		ScrollToEnd();
		bActive = true;
		Opened(this, EventArgs::Empty);
	}
	void Console::Open(String^ DefaultInput) {
		if (bActive) return;
		Open();
		pInput = DefaultInput;
	}
	void Console::Close() {
		if (!bActive) return;
		bActive = false;
		Closed(this, EventArgs::Empty);
	}

	void Console::SendCommand() {
		if (isNULL(pInput) || (pInput->Length == 0)) return;
		SendCommand(pInput);
		pInput = String::Empty;
		OldSelect = 0;
		ScrollToEnd();
	}

	void Console::SendCommand(String^ CommandLine) {
		if (isNULL(CommandLine) || (CommandLine->Length == 0)) return;
		List<String^>^ params = ParseString(CommandLine->Trim());
		if (params->Count > 0) {
			String^ cmd = params->default[0];
			params->RemoveAt(0);

			AddOldCommand(CommandLine); // before OnCommand because it should add other commands afterwards
			Print("> " +  CommandLine);
			OnCommand(gcnew ConsoleEventArgs(cmd,params->ToArray()));
		}
	}

	void Console::AddOldCommand(String^ CommandLine) {
		if (isNULL(CommandLine) || (CommandLine->Length == 0)) return;
		if ( (pLastCommands->Count > 0) && (pLastCommands->default[pLastCommands->Count-1] == CommandLine) ) return;
		pLastCommands->Add(CommandLine);
		if (pLastCommands->Count > MAX_COMMANDS) pLastCommands->RemoveAt(0);
	}

	void Console::Print(String^ Text) {
		if (isNULL(Text) || (Text->Length == 0)) { 
			AddPrintLine(String::Empty);
			return;
		}
		//array<String^>^ ary = Text->Split(splitChars, StringSplitOptions::RemoveEmptyEntries);
		//array<String^>^ ary = Text->Split(splitStrings, StringSplitOptions::None);
		array<String^>^ ary = Text->Replace("\r","")->Split(splitChars, StringSplitOptions::None);
		for (int i = 0; i < ary->Length; i++) {
			AddPrintLine(ary[i]);
		}
	}
	void Console::AddPrintLine(String^ Text) {
		if (Text->Length < 100) {
			pLog->Add(Text->Replace("~","~~"));
			if (pLog->Count > MAX_LOG_LINES)	pLog->RemoveAt(0);
		} else {
			int sPos = Text->LastIndexOf(" ",98,99);
			if (sPos<0) sPos = 98;
			AddPrintLine(Text->Substring(0,sPos+1));
			AddPrintLine(Text->Substring(sPos+1));
		}
	}

	List<String^>^ Console::ParseString(String^ input) {
		array<Byte>^ str = System::Text::Encoding::ASCII->GetBytes(input);
		List<String^>^ list = gcnew List<String^>();
		System::Text::StringBuilder^ word = gcnew System::Text::StringBuilder();
		bool bInstr = false;
		for (int i = 0; i < input->Length; i++) {
			switch (str[i]) {

				case 0x20: //space
					if (bInstr) {
						word->Append(input->default[i]);
					} else {
						if (word->Length > 0) {
							list->Add(word->ToString());
							word->Length = 0;
						}
					}
					break;

				case 0x5C: //backslash
					i++;
					if (i<input->Length)
						word->Append(ParseSlashChar(str[i]));
					break;

				case 0x22: // "
					if (bInstr) {
						bInstr = false;
					} else {
						if (word->Length == 0)
							bInstr = true;
						else
							word->Append(input->default[i]);
					}
					break;

				default:
					word->Append(input->default[i]);
					break;
	
			}
		}

		if (word->Length > 0) list->Add(word->ToString());
		return list;
	}

	String^ Console::ParseSlashChar(Byte input) {
		switch (input) {
			case 'n': return Environment::NewLine;
			case 't': return "\t";
			case 'r': return String::Empty;
		}
		return ((System::Char)(char)input).ToString();
	}

	// ### REMOTE CONSOLE ###

	bool RemoteConsole::isActive::get() {
		//RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"isActive");
		//return (bool)RemoteScriptDomain::Instance->LastRemoteEventResult;
		return RemoteScriptDomain::Instance->isConsoleActive;
	}

	void RemoteConsole::Open() {
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"Open");
	}
	void RemoteConsole::Open(String^ DefaultInput) {
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"Open",(System::Object^)DefaultInput);
	}

	void RemoteConsole::Close() {
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"Close");
	}

	void RemoteConsole::Print(String^ Text) {
		RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"Print",(System::Object^)Text);
	}

	void RemoteConsole::SendCommand(String^ CommandLine) {
		if (isNULL(CommandLine) || (CommandLine->Length == 0)) return;
		NetHook::RaiseEventInLocalScriptDomain(RemoteEvent::ConsoleEvent,"SendCommand",(System::Object^)CommandLine);
	}

}