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

#include "Game.h"

#include "ContentCache.h"
#include "NetThread.h"
#include "RemoteScriptDomain.h"
#include "ScriptDomain.h"
#include "Script.h"
#include "vGlobals.h"

#pragma managed

namespace GTA {

	static Game::Game() {
		try {
			Diagnostics::FileVersionInfo^ fi = Diagnostics::FileVersionInfo::GetVersionInfo(pExecutableFile);
			pVersion = (GTA::GameVersion) ((fi->FileMajorPart << 24) | (fi->FileMinorPart << 16) | (fi->FileBuildPart << 8) | (fi->FilePrivatePart));
		} catch(...) {
			pVersion = GTA::GameVersion::UnknownVersion;
		}
		pGlobals = gcnew value::Globals();
	}

	void Game::PerFrame() {
		pResolution = System::Drawing::Size(0,0);
	}

	GTA::GameEpisode Game::CurrentEpisode::get() {
		return (GTA::GameEpisode)Scripting::GetCurrentEpisode();
	}

	GTA::base::Console^ Game::Console::get() {
		return NetHook::Console;
	}
	GTA::base::Mouse^ Game::Mouse::get() {
		return NetHook::Mouse;
	}

	System::Drawing::Size Game::Resolution::get(){
		if (pResolution.Width > 0) return pResolution;
		u32 x = 0; u32 y = 0;
		Scripting::GetScreenResolution(&x,&y);
		pResolution = System::Drawing::Size(x,y);
		return pResolution;
	}
	bool Game::isFullscreen::get(){
		return (Resolution == WinForms::SystemInformation::PrimaryMonitorSize);
		//u32 x = 0; u32 y = 0; u32 x2 = 0; u32 y2 = 0;
		//Scripting::GetScreenResolution(&x,&y);
		//Scripting::GetPhysicalScreenResolution(&x,&y);
		//return ((x == x2) && (y == y2));
	}

	bool Game::isMultiplayer::get(){
		return Scripting::NetworkIsSessionStarted(); //IsPlayerOnline();
	}
	bool Game::isRankedMultiplayer::get(){
		return Scripting::NetworkIsGameRanked();
	}
	//bool Game::isModdingAllowed::get(){
	//	if (!isMultiplayer) return true;
	//	if (isRankedMultiplayer) return false;
	//	if (Scripting::IsInLanMode() == 1) return true;
	//	GTA::GameMode mode = MultiplayerGameMode;
	//	if (mode == GameMode::FreeMode) return true;
	//	if (mode == GameMode::PartyMode) return true;
	//	return false;
	//}
	GTA::NetworkMode Game::NetworkMode::get(){
		if (!isMultiplayer) return GTA::NetworkMode::Singleplayer;
		if (isRankedMultiplayer) return GTA::NetworkMode::MultiplayerLiveRanked;
		if (Scripting::IsInLanMode() == 1)
			return GTA::NetworkMode::MultiplayerLAN;
		else
			return GTA::NetworkMode::MultiplayerLive;
	}
	GTA::GameMode Game::MultiplayerGameMode::get(){
		return (GTA::GameMode)Scripting::NetworkGetGameMode();
	}

	int Game::PlayerCount::get(){
		return Scripting::GetNumberOfPlayers();
	}
	bool Game::isPlayerActive(int PlayerID) {
		return Scripting::IsNetworkPlayerActive(PlayerID);
	}
	GTA::Player^ Game::LocalPlayer::get() {
		return ContentCache::GetPlayer(Scripting::GetPlayerId());
	}
	array<GTA::Player^>^ Game::PlayerList::get() {
		if ((!isMultiplayer) || (PlayerCount == 1)) return gcnew array<GTA::Player^>(1){LocalPlayer};
		List<GTA::Player^>^ list = gcnew List<GTA::Player^>();
		for (int i = 0; i < 32; i++) {
			if (isPlayerActive(i))
				list->Add(ContentCache::GetPlayer(i));
		}
		return list->ToArray();
	}

	int Game::GameTime::get() {
		u32 g;
		Scripting::GetGameTimer(&g);
		return g;
	}
	float Game::LastFrameTime::get() {
		f32 f;
		Scripting::GetFrameTime(&f);
		return f;
	}
	float Game::FPS::get() {
		return (1.0f/LastFrameTime);
	}

	

	GTA::Camera^ Game::DefaultCamera::get() {
		i32 cam;
		Scripting::GetGameCamChild(&cam);
		return ContentCache::GetCamera(cam, false);
	}
	GTA::Camera^ Game::CurrentCamera::get() {
		i32 cam;
		Scripting::GetRootCam(&cam);
		return ContentCache::GetCamera(cam, false);
	}

	GTA::value::Globals^ Game::Globals::get() {
		return pGlobals;
	}


	//int Game::MaxWantedLevel::get(){
	//	u32 val = 0;
	//	Scripting::GetMaxWantedLevel(&val);
	//	return val;
	//}
	//void Game::MaxWantedLevel::set(int value){
	//	Scripting::SetMaxWantedLevel(value);
	//}

	GTA::RadioStation Game::RadioStation::get(){
		return (GTA::RadioStation)Scripting::GetPlayerRadioStationIndex();
	}
	void Game::RadioStation::set(GTA::RadioStation value){
		Scripting::RetuneRadioToStationIndex((u32)value);
	}

	bool Game::isMinigameInProgress::get(){
		return Scripting::IsMinigameInProgress();
	}
	void Game::isMinigameInProgress::set(bool value){
		Scripting::SetMinigameInProgress(value);
	}


	void Game::AllowEmergencyServices::set(bool value){
		Scripting::AllowEmergencyServices(value);
	}
	void Game::DisableMaxAmmoLimit::set(bool value) {
		Scripting::EnableMaxAmmoCap(!value);
	}
	void Game::LoadAllPathNodes::set(bool value){
		Scripting::LoadAllPathNodes(value);
		//while (!Scripting::HaveRequestedPathNodesBeenLoaded(rq)) {
		//	WaitInCurrentScript(0);
		//}
	}
	void Game::MadDrivers::set(bool value) {
		Scripting::SwitchMadDrivers(value);
	}
	void Game::RadarZoom::set(float value) {
		Scripting::SetRadarZoom(value);
	}
	void Game::TimeScale::set(float value) {
		Scripting::SetTimeScale(value);
	}
	void Game::WantedMultiplier::set(float value) {
		Scripting::SetWantedMultiplier(value);
	}
	

	Blip^ Game::GetWaypoint() {
		Scripting::eBlipType bt = (Scripting::eBlipType)8; //Scripting::BLIP_TYPE_COORD;

		for (int i = 0; i<10; i++) {
		bt=(Scripting::eBlipType)i;
		
		int b = Scripting::GetFirstBlipInfoId(bt);
		while (Scripting::DoesBlipExist(b)) {
			//if (Scripting::DoesBlipExist(b)) {
				if (Scripting::GetBlipSprite(b) == 8) { //BLIP_WAYPOINT
					//DisplayText(String::Concat( "Found at ", i.ToString() ));
					return ContentCache::GetBlip(b, false);
				}
			//}
			b = Scripting::GetNextBlipInfoId(bt);
		}

		}

		return nullptr;
	}

	//void Game::ActivateMultiplayerModel() {
	//	Player^ p = LocalPlayer;
	//	p->Model = Model(Scripting::GetPlayerSettingsModelChoice());
	//	Scripting::SetPlayerSettingsModelVariationsChoice(p->Index);
	//}

	bool Game::isKeyPressed(System::Windows::Forms::Keys Key){
		return NetHook::isKeyPressed(Key);
	}
	bool Game::isGameKeyPressed(GameKey Key) {
		if (int(Key) < 1000) {
			return Scripting::IsControlPressed(0, (i32)Key);
		} else {
			int x = 0; int y = 0;
			GetMovement(&x,&y);
			switch (Key) {
				case GameKey::MoveForward: return (y < -32);
				case GameKey::MoveBackward: return (y > 32);
				case GameKey::MoveLeft: return (x < -32);
				case GameKey::MoveRight: return (x > 32);
			}
			return false;
		}
	}
	void Game::GetMovement(int* x, int* y) {
		int x2 = 0; int y2 = 0;
		*x = 0; *y = 0;
		Scripting::GetPositionOfAnalogueSticks(0, x, y, &x2, &y2);
		if ((*x == 0) && (*y == 0)) Scripting::GetKeyboardMoveInput(x, y);
	}
	GameKeyDirection Game::CurrentGameKeyDirection::get() {
		int x = 0; int y = 0;
		GetMovement(&x, &y);

		GameKeyDirection dir = GameKeyDirection::None;
		if (x < -32) dir = dir | GameKeyDirection::Left;
		if (x > 32) dir = dir | GameKeyDirection::Right;
		if (y < -32) dir = dir | GameKeyDirection::Forward;
		if (y > 32) dir = dir | GameKeyDirection::Backwards;
		return dir;
	}

	void Game::DisplayText(String^ Text, int Duration) {
		NetHook::DisplayText(Text, Duration);
		//char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(Text).ToPointer();
		//Scripting::PrintStringWithLiteralStringNow("STRING",stringPointer,Duration,1);
		//Marshal::FreeHGlobal(IntPtr(stringPointer));
	}
	void Game::DisplayText(String^ Text) {
		DisplayText(Text, 2000);
	}

	
	void Game::DoAutoSave() {
		Scripting::DoAutoSave();
	}

	void Game::FadeScreenIn(int time) {
		FadeScreenIn(time,false);
	}
	void Game::FadeScreenIn(int time, bool WaitUntilDone) {
		unmanaged::Native::DoScreenFadeIn(time);
		if (WaitUntilDone) WaitInCurrentScript(time);
	}

	void Game::FadeScreenOut(int time) {
		FadeScreenOut(time,false);
	}
	void Game::FadeScreenOut(int time, bool WaitUntilDone) {
		unmanaged::Native::DoScreenFadeOut(time);
		if (WaitUntilDone) WaitInCurrentScript(time);
	}


	void Game::ShowSaveMenu() {
		Scripting::ActivateSaveMenu();
	}
	

	int Game::GetIntegerStatistic(IntegerStatistic stat) {
		return Scripting::GetIntStat((Scripting::eIntStatistic)stat);
	}
	void Game::SetIntegerStatistic(IntegerStatistic stat, int value) {
		Scripting::SetIntStat((Scripting::eIntStatistic)stat,value);
	}
	float Game::GetFloatStatistic(FloatStatistic stat) {
		return Scripting::GetFloatStat((Scripting::eFloatStatistic)stat);
	}
	void Game::SetFloatStatistic(FloatStatistic stat, float value) {
		Scripting::SetFloatStat((Scripting::eFloatStatistic)stat,value);
	}

	bool Game::isScriptRunning(String^ ScriptName) {
		char* ptr = PinStringA(ScriptName);
		try {
			if (!Scripting::DoesScriptExist(ptr)) return false;
			if (Scripting::GetNumberOfInstancesOfStreamedScript(ptr) <= 0) return false;
			return true;
		} finally {
			FreeString(ptr);
		}
	}

	Script^ Game::GetScript(Guid GUID) {
		if (NetHook::isPrimary) return nullptr;
		return RemoteScriptDomain::Instance->GetScript(GUID);
	}
	Script^ Game::GetScript(String^ GUID) {
		return GetScript(Guid(GUID));
	}
	//void Game::SendScriptCommand(GTA::Script^ Script, String^ Command, ... array<System::Object^>^ Parameter) {
	//	if (NetHook::isPrimary)
	//		NetHook::ScriptDomain->SendScriptCommand(Script->GUID, Command, Paramater);
	//	else
	//		RemoteScriptDomain::Instance->SendScriptCommand(Script, Command, Parameter);
	//}
	//void Game::SendScriptCommand(Guid ScriptGUID, String^ Command, ... array<System::Object^>^ Parameter) {
	//	if (NetHook::isPrimary)
	//		NetHook::ScriptDomain->SendScriptCommand(ScriptGUID, Command, Parameter);
	//	else
	//		RemoteScriptDomain::Instance->SendScriptCommand(ScriptGUID, Command, Parameter);
	//}
	bool Game::isScriptRunning(Guid GUID) {
		if (NetHook::isPrimary)
			return NetHook::ScriptDomain->isScriptRunning(GUID);
		else
			return RemoteScriptDomain::Instance->isScriptRunning(GUID);
	}
	//bool Game::isScriptRunning(String^ GUID) {
	//	return isScriptRunning(gcnew Guid(GUID));
	//}
	

	void Game::PlayAudioEvent(String^ EventName) {
		char* ptr = PinStringA(EventName);
		Scripting::PlayAudioEvent(ptr);
		FreeString(ptr);
	}
	//HEADLAMP_SWITCH_BEAM_ON, MOBILE_PHONE_SMS_RECIEVE

	void Game::PlayGameSound(String^ SoundName) {
		char* ptr = PinStringA(SoundName);
		Scripting::PlaySound(-1, ptr);
		FreeString(ptr);
	}
	//PHONE_PRESS_KEY, PHONE_PRESS_KEY_SPEED, PAYANDSPRAY_COMPRESSOR

	void Game::PlayFrontendSound(String^ SoundName) {
		char* ptr = PinStringA(SoundName);
		Scripting::PlaySoundFrontend(-1, ptr);
		FreeString(ptr);
	}
	//SFX_PHONE_REMOTE_HANG_UP_CLICK, FRONTEND_GAME_PHONE_DIAL_HANG_UP, MOUSE_SINGLE_CLICK

	void Game::PlayPhoneKeypadTone(int KeyNum, bool fast) {
		if ((KeyNum<0) || (KeyNum>11)) return;
		u32 sid = (u32)Scripting::GetSoundId();
		if (fast)
			Scripting::PlaySoundFrontend(sid, "PHONE_PRESS_KEY_SPEED");
		else
			Scripting::PlaySoundFrontend(sid, "PHONE_PRESS_KEY");
		switch (KeyNum) {
			case 0:
				Scripting::SetVariableOnSound(sid, "Number", 10.0f);
				break;
		   case 11:
				Scripting::SetVariableOnSound(sid, "Number", 11.0f);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				Scripting::SetVariableOnSound(sid, "Number", (float)(KeyNum-1));
				break;
		}
		Scripting::ReleaseSoundId(sid);
	}
	void Game::PlayPhoneKeypadTone(int KeyNum) {
		PlayPhoneKeypadTone(KeyNum, false);
	}

	void Game::PlayCreditsMusic() {
		Scripting::StartEndCreditsMusic();
	}
	void Game::StopCreditsMusic() {
		Scripting::StopEndCreditsMusic();
	}
	void Game::PreviewRingtone(int RingtoneID) {
		Scripting::PreviewRingtone(RingtoneID);
	}
	void Game::StopRingtonePreview() {
		Scripting::StopPreviewRingtone();
	}

	void Game::SendChatMessage(String^ Text) {
		char* ptr = PinStringA(Text);
		try {
			Scripting::NetworkSendTextChat(Scripting::GetPlayerId(), ptr);
		} finally {
			FreeString(ptr);
		}
	}

	void Game::Pause() {
		Scripting::PauseGame();
	}
	void Game::Unpause() {
		Scripting::UnPauseGame();
	}
	bool Game::Paused::get(){
		return Scripting::IsPauseMenuActive();
	}
	void Game::Paused::set(bool value){
		if (value) {
			Scripting::PauseGame();
		} else {
			Scripting::UnPauseGame();
		}
	}

	bool Game::CanWaitNow::get() {
		Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
		if isNotNULL(scr) {
			return scr->CanWaitNow;
		}
		NetThread^ trd = RemoteScriptDomain::Instance->CurrentThread;
		if isNotNULL(trd) {
			return trd->CanWaitNow;
		}
		return false;
	}

	void Game::WaitInCurrentScript(int ms) {
		Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
		if isNotNULL(scr) { 
			scr->Wait(ms);
			return;
		}
		NetThread^ trd = RemoteScriptDomain::Instance->CurrentThread;
		if isNotNULL(trd) {
			return trd->Wait(ms);
		}
	}

	int Game::GenerateHash(String^ input){
		char* ptr = PinStringA(input);
		int res = force_cast<int>(Scripting::GetHashKey(ptr)); //(int)Scripting::GetModelHash(ptr);
		FreeString(ptr);
		return res;
	}

	GTA::Vector3 Game::HeadingToDirection(float Heading) {
		//Heading = Heading * (float)(System::Math::PI / 180.0);
		//GTA::Vector3 res;
		//res.X = (float)-Math::Sin(Heading);
		//res.Y = (float)Math::Cos(Heading);
		//res.Z = 0.0f;
		//return res;
		return Helper::HeadingToDirection(Heading);
	}

	bool Game::Exists(base::Object^ o) {
		if isNULL(o) return false;
		return o->Exists();
	}

	void Game::Log(String^ Text) {
		NetHook::Log(Text);
	}

	void Game::Test() {
		////u32 g;
		////f32 f;
		////Scripting::GetGameTimer(&g);
		////Scripting::GetFrameTime(&f);
		////DisplayText( String::Concat( "G ", g, " - F ", f) );

		////u32 s;
		////Scripting::StoreScore(LocalPlayer->Index, &s);
		////DisplayText( String::Concat( "SCORE ", s) );
		////u32 a,b;
		////Scripting::GetCurrentDate(&a,&b);
		////DisplayText(String::Concat( "DATE ", a, " - ", b ));
		Blip^ w = GetWaypoint();
		//if (Object::ReferenceEquals(w,nullptr)) return;

		//Vector3 p = w->Position;

		//float x = 0.0f;
		//float y = 0.0f;
		//float z = 0.0f;

		//float* ary[3] = {&x, &y, &z};

		////vp3* v = new vp3();
		////v->Count = 3;
		////v->Size = 12;
		////v->Data = ary;
		//vp3 v;
		////v->X = 0.0f;
		////v->Y = 0.0f;
		////v->Z = 0.0f;
		////v->pX = &v->X;
		////v->pY = &v->Y;
		////v->pZ = &v->Z;
		//v.Data[0] = 0.0f;
		//v.Data[1] = 0.0f;
		//v.Data[2] = 0.0f;

		//Scripting::GetBlipCoords(w->Handle,&v);
		////Scripting::GetBlipInfoIdPosition((u32)w->Handle,v);
		////v = Scripting::GetBlipInfoIdPosition((u32)w->Handle);
		////GTA::Native::Pointer^ p = gcnew GTA::Native::Pointer(int::typeid);
		////GTA::Native::Function::Call("GET_BLIP_COORDS", w->Handle, p);
		////DisplayText(String::Concat( "Waypoint D:", w->Display, " T:", w->Type.ToString(), " C:", p->Value->ToString() ));
		////float x = p.X;
		////float y = p.Y;
		////float z = p.Z;

		////DisplayText(String::Concat( "Waypoint X:", v->X, " Y:", v->Y, " Z:", v->Z, " C:", v->count ));
		////DisplayText(String::Concat( "Waypoint X:", *v->Data[0], " Y:", *v->Data[1], " Z:", *v->Data[2], " X:", x, " Y:", y, " Z:", z  ));
		//DisplayText(String::Concat( "Waypoint X:", v.Data[0], " Y:", v.Data[1], " Z:", v.Data[2] ));

		//int count = 0;

		//Scripting::eBlipType bt = (Scripting::eBlipType)8; //Scripting::BLIP_TYPE_COORD;

		//for (int i = 0; i<10; i++) {
		//bt=(Scripting::eBlipType)i;
		//
		//int b = Scripting::GetFirstBlipInfoId(bt);
		//while (Scripting::DoesBlipExist(b)) {
		//	//if (Scripting::DoesBlipExist(b)) {
		//		if (Scripting::GetBlipSprite(b) == Scripting::BLIP_WAYPOINT) {
		//			//DisplayText(String::Concat( "Found at ", i.ToString() ));
		//			//return ContentCache::GetBlip(b);
		//			count++;
		//		}
		//	//}
		//	b = Scripting::GetNextBlipInfoId(bt);
		//}

		//}

		//if isNULL(w) {
		////DisplayText(String::Concat( "Waypoint C:", count ));
		//	DisplayText(String::Concat( "BA: ", Scripting::GetBaseAddress() ));
		//} else {
		//	DisplayText(String::Concat( "BA: ", Scripting::GetBaseAddress(), "  W: ", w->Handle ));
		//}
		//NetHook::Test();
		//u32 val =  Scripting::GetGlobalAddress(0);
		//u32 val = Scripting::GetGlobalInteger(2220);
		//DisplayText(String::Concat( "WP: ", val, "   W: ", w->Handle ),10000);

		//float fdata[4];
		//fdata[0] = 0.0f;
		//fdata[1] = 0.0f;
		//fdata[2] = 0.0f;
		//fdata[3] = 0.0f;

		//float* fptr[4];
		//fptr[0] = &fdata[0];
		//fptr[1] = &fdata[1];
		//fptr[2] = &fdata[2];
		//fptr[3] = &fdata[3];

		//float** fptr2 = fptr;

		//Scripting::CFloatCollection col;
		//col.Data = fptr2;
		//col.Size = 4;
		//col.Count = 4;

		//Scripting::GetBlipCoords(w->Handle, &col);
		//DisplayText("W: " + (*((*col.Data)+0)).ToString() + ", " + (*((*col.Data)+1)).ToString() + ", " + (*((*col.Data)+2)).ToString() + ", " + (*((*col.Data)+3)).ToString() );


		//Scripting::CVECTOR3 v;
		//v.x = 0.0f;
		//v.y = 0.0f;
		//v.z = 0.0f;

		//Scripting::GetBlipCoords(w->Handle, &v);

		//DisplayText("W ("+w->Handle.ToString()+"): " + v.x.ToString() + ", " + v.y.ToString() + ", " + v.z.ToString() );

		//w->Name = "xyzMyWAYpOINTNAME";

		//int const *Blips = (int*)(0x00FB1AF0+NetHook::BaseAddress);   //Blips On The Map
		//bool isWpOn = false;
		//float Wpx, Wpy, Wpz;

		//for(int j = 0; j<100; j++) {          //I dont know the limit of the array...
		//	if (Blips[j] != 0) && {
		//		Wpx = *(float*)(Blips[j] + 0x30); 
		//		Wpy = *(float*)(Blips[j] + 0x34); 
		//		Wpz = *(float*)(Blips[j] + 0x38);
		//		if(Wpz == 0.0f) {
		//			isWpOn = true;
		//			break;        //It is waypoint. Maybe better solution like blip name.
		//		}
		//	}
		//}

		//if(isWpOn) {
		//	Vector3 v = Vector3(Wpx, Wpy, Wpz);
		//	DisplayText("Waypoint is at " + v.ToString(), 2000);
		//} else {
		//	DisplayText("Waypoint not found!", 2000);
		//}
		//int adr = unmanaged::MemoryAccess::GetAddressOfBlip(w->Handle);
		//if (adr == 0) {
		//	DisplayText("Waypoint NOT found!", 2000);
		//	return;
		//}

		//Vector3 v = unmanaged::Native::GetPositionOfBlip(w->Handle);
		//DisplayText("Waypoint ("+adr.ToString()+") is at " + v.ToString(), 2000);
	}


	//generic <typename R, typename T1, typename T2>
	//R Game::Invoke(String^ name, T1 p1, T2 p2){
	//	char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
	//	//NativeInvoke::Invoke<R,T1,T2>(stringPointer,p1,p2);

	//	NativeContext cxt;
	//	cxt.Push(p1);
	//	cxt.Push(p2);
	//	Invoke(stringPointer, &cxt);
	//	R res = cxt.GetResult<R>();

	//	Marshal::FreeHGlobal(IntPtr(stringPointer));
	//	return res;
	//}

}