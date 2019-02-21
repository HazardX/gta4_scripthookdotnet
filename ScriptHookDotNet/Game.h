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

	public ref class Game sealed {

	private:
		static Game();
		Game() { }

		static value::Globals^ pGlobals;

		static String^ pInstallFolder = System::Windows::Forms::Application::StartupPath;
		static String^ pExecutableFile = System::Windows::Forms::Application::ExecutablePath;
		static GTA::GameVersion pVersion;

		static Drawing::Size pResolution;

		static void GetMovement(int* x, int* y);
		

	internal:
		static property bool isRankedMultiplayer {
			bool get();
		}
		//static property bool isModdingAllowed {
		//	bool get();
		//}

		static property bool CanWaitNow {
			bool get();
		}

		static void PerFrame();

		static bool isPlayerActive(int PlayerID);

#ifdef DEBUG
	public: 
#else
	internal:
#endif

		static void Test();
		static void Log(String^ Text);

	public:
		static property String^ InstallFolder {
			String^ get() {
				return pInstallFolder;
			}
		}
		static property String^ ExecutableFile {
			String^ get() {
				return pExecutableFile;
			}
		}
		static property GTA::GameVersion Version {
			GTA::GameVersion get() {
				return pVersion;
			}
		}
		static property GTA::GameEpisode CurrentEpisode {
			GTA::GameEpisode get();
		}
		static property GTA::base::Console^ Console {
			GTA::base::Console^ get();
		}
		static property GTA::base::Mouse^ Mouse {
			GTA::base::Mouse^ get();
		}
		static property value::Globals^ Globals {
			value::Globals^ get();
		}

		static property System::Drawing::Size Resolution {
			System::Drawing::Size get();
		}
		static property bool isFullscreen {
			bool get();
		}

		static property bool isMultiplayer {
			bool get();
		}
		static property GTA::NetworkMode NetworkMode {
			GTA::NetworkMode get();
		}
		static property GTA::GameMode MultiplayerGameMode {
			GTA::GameMode get();
		}
		static property int PlayerCount {
			int get();
		}
		static property int GameTime {
			int get();
		}
		static property float LastFrameTime {
			float get();
		}
		static property float FPS {
			float get();
		}
		static property GTA::Player^ LocalPlayer {
			GTA::Player^ get();
		}
		static property array<GTA::Player^>^ PlayerList {
			array<GTA::Player^>^ get();
		}
		static property GTA::Camera^ DefaultCamera {
			GTA::Camera^ get();
		}
		static property GTA::Camera^ CurrentCamera {
			GTA::Camera^ get();
		}

		//static property int MaxWantedLevel {
		//	int get();
		//	void set(int value);
		//}
		static property GTA::RadioStation RadioStation {
			GTA::RadioStation get();
			void set(GTA::RadioStation value);
		}

		static property bool isMinigameInProgress {
			bool get();
			void set(bool value);
		}


		static property bool AllowEmergencyServices {
			void set(bool value);
		}
		static property bool DisableMaxAmmoLimit {
			void set(bool value);
		}
		static property bool LoadAllPathNodes {
			void set(bool value);
		}
		static property bool MadDrivers {
			void set(bool value);
		}
		static property float RadarZoom {
			void set(float value);
		}
		static property float TimeScale {
			void set(float value);
		}
		static property float WantedMultiplier {
			void set(float value);
		}

		static Blip^ GetWaypoint();
		static bool isKeyPressed(System::Windows::Forms::Keys Key);
		static bool isGameKeyPressed(GameKey Key);
		static property GameKeyDirection CurrentGameKeyDirection { GameKeyDirection get(); }

		static void DisplayText(String^ Text, int Duration); 
		static void DisplayText(String^ Text); 

		static void DoAutoSave();
		static void FadeScreenIn(int time);
		static void FadeScreenIn(int time, bool WaitUntilDone);
		static void FadeScreenOut(int time);
		static void FadeScreenOut(int time, bool WaitUntilDone);
		static void PlayAudioEvent(String^ EventName);
		static void PlayGameSound(String^ SoundName);
		static void PlayFrontendSound(String^ SoundName);
		static void PlayPhoneKeypadTone(int KeyNum, bool ShortDialTone);
		static void PlayPhoneKeypadTone(int KeyNum);
		static void ShowSaveMenu();

		static void PlayCreditsMusic();
		static void StopCreditsMusic();
		static void PreviewRingtone(int RingtoneID);
		static void StopRingtonePreview();

		static void SendChatMessage(String^ Text);

		static int GetIntegerStatistic(IntegerStatistic stat);
		static void SetIntegerStatistic(IntegerStatistic stat, int value);
		static float GetFloatStatistic(FloatStatistic stat);
		static void SetFloatStatistic(FloatStatistic stat, float value);

		static bool isScriptRunning(String^ ScriptName);

		static Script^ GetScript(String^ GUID);
		static Script^ GetScript(Guid GUID);
		//static void SendScriptCommand(GTA::Script^ Script, String^ Command, ... array<System::Object^>^ Parameter);
		//static void SendScriptCommand(Guid ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter);
		//static bool isScriptRunning(String^ GUID);
		static bool isScriptRunning(Guid GUID);

		static void Pause();
		static void Unpause();
		static property bool Paused{
			bool get();
			void set(bool value);
		}
		static void WaitInCurrentScript(int ms);

		static int GenerateHash(String^ input);
 
		static GTA::Vector3 HeadingToDirection(float Heading);

		/// <summary>
		/// Returns whether the given object still exists in game.
		/// </summary>
		static bool Exists(base::Object^ o);

		//generic <typename R, typename T1, typename T2>
		//static inline R Invoke(String^ name, T1 p1, T2 p2);
		
	};

}