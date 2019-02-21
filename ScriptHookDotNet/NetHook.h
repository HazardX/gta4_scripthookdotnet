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

namespace GTA{

	using namespace System::Reflection;
	using namespace System::CodeDom::Compiler;

	CLASS_ATTRIBUTES
	private ref class NetHook sealed {

	public:
		static String^ Version = "1.7.1.7";
		static String^ ProgramName = "ScriptHookDotNet";
#ifdef DEBUG
		static String^ VersionName = String::Concat( ProgramName, " v", Version, " DEBUGGING BETA" ); //Version.ToString("F3",Globalization::CultureInfo::InvariantCulture)
#else
		static String^ VersionName = String::Concat( ProgramName, " v", Version, " BETA" );
#endif
		//static GameVersion MinGameVersion = GameVersion::v1010;
		static GameVersion MaxGameVersion = GameVersion::v1070;
		static Dictionary<GameVersion,cppHookVersion>^ SupportedGameVersions;

		static NetHook();

	private:

		NetHook() { }

		static u32 pBaseAddress;
		static bool bPrimary = false;
		static GTA::ScriptDomain^ pScriptDomain;
		static String^ myDllFile = Assembly::GetAssembly(GTA::Script::typeid)->Location;
		static bool bInsideScript = false;
		static int pHModule = 0;

		static System::Random^ pRandom = gcnew System::Random();

		static String^ pDisplayText = "";
		static DateTime pDisplayTextUntil = DateTime::MinValue;
		static GTA::Graphics^ pGraphics;
		static GTA::Forms::FormHost^ pFormHost;
	
		//static GTA::ManagerThread^ ManagerThread;
		static GTA::base::Console^ pConsole;
		static GTA::base::Mouse^ pMouse;
		static GTA::KeyWatchDog^ pKeys;
		static GTA::KeyboardLayout^ pKeyboardLayout;

		//static System::Object^ syncrootLog = gcnew System::Object();

		static Assembly^ MyResolveEventHandler(System::Object^ sender, ResolveEventArgs^ args);
		static void CatchUnhandledExceptions(System::Object^ o, UnhandledExceptionEventArgs^ eventArgs);


		static String^ GetVersionName(GameVersion version) {
			if (version == GameVersion::UnknownVersion) return "UNKNOWN";
			u32 mask = 0x000000FF;
			return String::Concat( (((u32)version>>24)&mask), ".", (((u32)version>>16)&mask), ".", (((u32)version>>8)&mask), ".", ((u32)version&mask) );
		}
		static String^ GetVersionName(cppHookVersion version) {
			if (version == cppHookVersion::UnknownVersion) return "UNKNOWN";
			u32 mask = 0x0000000F;
			return String::Concat( (((u32)version>>12)&mask), ".", (((u32)version>>8)&mask), ".", (((u32)version>>4)&mask) );
		}

		static void KeyDown(Object^ sender, KeyEventArgs^ e);
		static void KeyUp(Object^ sender, KeyEventArgs^ e);
		static void ConsoleCommand(Object^ sender, ConsoleEventArgs^ e);
		static void ConsoleOpened(Object^ sender, EventArgs^ e);
		static void ConsoleClosed(Object^ sender, EventArgs^ e);

		static bool bDialing = false;
		static bool bPhoneError = false;
		static String^ pLastPhoneNumber = String::Empty;
		static DateTime pLastPhoneNumberChange = DateTime::MinValue;
		static TimeSpan pDialingDoneTime = TimeSpan(0,0,3);
		static void CheckPhone();

	public:

		static property u32 BaseAddress {
			u32 get() {
				return pBaseAddress;
			}
		}
		static property GTA::base::Console^ Console {
			GTA::base::Console^ get() {
				return pConsole;
			}
		}
		static property GTA::Console^ LocalConsole {
			GTA::Console^ get() {
				return (GTA::Console^)pConsole;
			}
		}
		static property GTA::KeyboardLayout^ KeyboardLayout {
			GTA::KeyboardLayout^ get() {
				return pKeyboardLayout;
			}
		}
		static property GTA::ScriptDomain^ ScriptDomain {
			GTA::ScriptDomain^ get() {
				return pScriptDomain;
			}
		}
		static property GTA::Forms::FormHost^ FormHost {
			GTA::Forms::FormHost^ get() {
				return pFormHost;
			}
		}
		static property GTA::base::Mouse^ Mouse {
			GTA::base::Mouse^ get() {
				return pMouse;
			}
		}
		static property GTA::Forms::Mouse^ LocalMouse {
			GTA::Forms::Mouse^ get() {
				return (GTA::Forms::Mouse^)pMouse;
			}
		}
		static property bool isPrimary {
			bool get() {
				return bPrimary;
			}
		}
		static property bool isScriptDomain {
			bool get() {
#ifdef USE_APPDOMAINS
				return !bPrimary;
#else
				return true;
#endif
			}
		}
		static property bool isInsideScript {
			bool get();
		}
		static property bool CanScriptsRunNow {
			bool get();
		}

		static property System::Random^ Random {
			System::Random^ get() {
				return pRandom;
			}
		}

		static void Initialize(bool isPrimary, int hModule);
		static void GameEnded();
		static void Terminate();
		static void Minimize();

		static void Tick();
		static void Draw();
		static void CreateScriptDomain();
		static void UnloadScriptDomain();
		static void ReloadScriptDomain();

		static void GameReloaded();
		static void GameTerminated();

		static void RequestScriptAction(ScriptAction action);
		static void DisplayText(String^ Text, int Duration);
		static System::Object^ RaiseEventInLocalScriptDomain(RemoteEvent EventID, ... array<System::Object^>^ Arguments);

		static bool isKeyPressed(System::Windows::Forms::Keys Key);
		static void TryToDisableMouse();

		static void Log(String^ Text);
		static void Log(String^ Text, Exception^ ex);
		static void Log(Exception^ ex);
		static void Log(String^ Text, bool InsertEmptyLine, bool Truncate);

		private:

		static void LogInner(Exception^ ex);
		static System::Threading::Mutex^ LogMutex = gcnew System::Threading::Mutex(false, "SHDN_Log_Mutex");
		static System::Threading::Mutex^ CallMutex = gcnew System::Threading::Mutex(false);
		
	};

}