/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  The contents of this file is a result of contributions from various people.

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

\*****************************************************************************/

/*****************************************************************************\

  Vast amount of changes made by Hazard (hazard_x@gmx.net / twitter.com/HazardX)
  2009-2011

\*****************************************************************************/

#pragma once
//#include "NativeContext3.h"
#include "nScriptingOrig.h"

#pragma managed

namespace unmanaged {
namespace Native {

	// INTERNAL
	//static u32 GetActiveThread() { return (u32)Game::GetInstance()->Script_GetActiveThread(); }
	//static u32 GetBaseAddress() { return Game::GetBase(); }
	//static void* GetDirect3DDevice9() { return Game::GetInstance()->GetDirect3DDevice9(); }
	static b8 DoesScriptExist(const ch* scriptname) { return Native::Function::Invoke<b8>("DOES_SCRIPT_EXIST", scriptname); }
	static b8 IsScriptRunning(const ch* scriptname) { return (DoesScriptExist(scriptname) && (GetNumberOfInstancesOfStreamedScript(scriptname)>0)); }

	// GAME
	static void AddExplosion(f32 x, f32 y, f32 z, u32 type, f32 power, b8 sound, b8 novisuals, f32 camshake) { Native::Function::Invoke<ScriptVoid>("ADD_EXPLOSION", x, y, z, type, power, sound, novisuals, camshake); }
	static void FindStreetNameAtPosition(f32 pX, f32 pY, f32 pZ, u32* strHash0, u32* strHash1) { Native::Function::Invoke<ScriptVoid>("FIND_STREET_NAME_AT_POSITION", pX, pY, pZ, strHash0, strHash1); }
	static void GetCurrentDate(u32 *day, u32 *month) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_DATE", day, month); }
	static f32 GetFloatStat(eFloatStatistic stat) { return Native::Function::Invoke<f32>("GET_FLOAT_STAT", stat); }
	static void GetFrameTime(f32* time) { Native::Function::Invoke<ScriptVoid>("GET_FRAME_TIME", time); }
	static void GetKeyboardMoveInput(i32* movex, i32* movey) { Native::Function::Invoke<ScriptVoid>("GET_KEYBOARD_MOVE_INPUT", movex, movey); }
	static void GetMouseInput(i32* x, i32* y) { Native::Function::Invoke<ScriptVoid>("GET_MOUSE_INPUT", x, y); }
	static f32 GetMouseSensitivity() { return Native::Function::Invoke<f32>("GET_MOUSE_SENSITIVITY"); }
	static void GetMouseWheel(i32 *pMWheel) { Native::Function::Invoke<f32>("GET_MOUSE_WHEEL", pMWheel); }
	static u32 GetNumberOfPlayers() { return Native::Function::Invoke<u32>("GET_NUMBER_OF_PLAYERS"); }
	static void GetPhysicalScreenResolution(u32* x, u32* y) { Native::Function::Invoke<ScriptVoid>("GET_PHYSICAL_SCREEN_RESOLUTION", x, y); }
	static void GetPositionOfAnalogueSticks(i32 padIndex, i32* stick1x, i32* stick1y, i32* stick2x, i32* stick2y) { Native::Function::Invoke<ScriptVoid>("GET_POSITION_OF_ANALOGUE_STICKS", padIndex, stick1x, stick1y, stick2x, stick2y); }
	static void GetScreenResolution(u32* x, u32* y) { Native::Function::Invoke<ScriptVoid>("GET_SCREEN_RESOLUTION", x, y); }
	static i32 GetTextInputActive() { return Native::Function::Invoke<i32>("GET_TEXT_INPUT_ACTIVE"); }
	static void GetTimeOfDay(u32* hour, u32* minute) { Native::Function::Invoke<ScriptVoid>("GET_TIME_OF_DAY", hour, minute); }
	static b8 HaveRequestedPathNodesBeenLoaded(u32 requestid) { return Native::Function::Invoke<b8>("HAVE_REQUESTED_PATH_NODES_BEEN_LOADED", requestid); }
	static b8 IsControlJustPressed(i32 padIndex, i32 control) { return Native::Function::Invoke<b8>("IS_CONTROL_JUST_PRESSED", padIndex, control); }
	static b8 IsControlPressed(i32 padIndex, i32 control) { return Native::Function::Invoke<b8>("IS_CONTROL_PRESSED", padIndex, control); }
	static b8 IsGameKeyboardKeyPressed(i32 key) { return Native::Function::Invoke<b8>("IS_GAME_KEYBOARD_KEY_PRESSED", key); }
	static b8 IsGameKeyboardNavDownPressed() { return Native::Function::Invoke<b8>("IS_GAME_KEYBOARD_NAV_DOWN_PRESSED"); }
	static b8 IsGameKeyboardNavLeftPressed() { return Native::Function::Invoke<b8>("IS_GAME_KEYBOARD_NAV_LEFT_PRESSED"); }
	static b8 IsGameKeyboardNavRightPressed() { return Native::Function::Invoke<b8>("IS_GAME_KEYBOARD_NAV_RIGHT_PRESSED"); }
	static b8 IsGameKeyboardNavUpPressed() { return Native::Function::Invoke<b8>("IS_GAME_KEYBOARD_NAV_UP_PRESSED"); }
	static i32 IsInLanMode() { return Native::Function::Invoke<i32>("IS_IN_LAN_MODE"); }
	static b8 IsKeyboardKeyPressed(i32 key) { return Native::Function::Invoke<b8>("IS_KEYBOARD_KEY_PRESSED", key); }
	//static b8 IsLookInverted() { return Native::Function::Invoke<b8>("IS_LOOK_INVERTED"); }
	static b8 IsPlayerOnline() { return Native::Function::Invoke<b8>("IS_PLAYER_ONLINE"); }
	static b8 IsPointObscuredByAMissionEntity(f32 pX, f32 pY, f32 pZ, f32 sizeX, f32 sizeY, f32 sizeZ) { return Native::Function::Invoke<b8>("IS_POINT_OBSCURED_BY_A_MISSION_ENTITY", pX, pY, pZ, sizeX, sizeY, sizeZ); }
	static b8 isScriptFireExtinguished(u32 fireid) { return Native::Function::Invoke<b8>("IS_SCRIPT_FIRE_EXTINGUISHED", fireid); }
	static b8 IsThisMachineTheServer() { return Native::Function::Invoke<b8>("IS_THIS_MACHINE_THE_SERVER"); }
	static u32 LoadAllPathNodes(bool value) { return Native::Function::Invoke<ScriptAny>("LOAD_ALL_PATH_NODES", value); }
	static void LoadScene(f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("LOAD_SCENE", pX, pY, pZ); }
	static b8 NetworkEndSession() { return Native::Function::Invoke<b8>("NETWORK_END_SESSION"); }
	static b8 NetworkEndSessionPending() { return Native::Function::Invoke<b8>("NETWORK_END_SESSION_PENDING"); }
	static i32 NetworkGetGameMode() { return Native::Function::Invoke<i32>("NETWORK_GET_GAME_MODE"); }
	static b8 NetworkIsGameRanked() { return Native::Function::Invoke<b8>("NETWORK_IS_GAME_RANKED"); }
	static b8 NetworkIsSessionStarted() { return Native::Function::Invoke<b8>("NETWORK_IS_SESSION_STARTED"); }
	static void NetworkKickPlayer(i32 playerid, b8 unknown_true) { Native::Function::Invoke<ScriptVoid>("NETWORK_KICK_PLAYER", playerid, unknown_true); }
	static void NetworkLeaveGame() { Native::Function::Invoke<ScriptVoid>("NETWORK_LEAVE_GAME"); }
	static b8 NetworkLeaveGamePending() { return Native::Function::Invoke<b8>("NETWORK_LEAVE_GAME_PENDING"); }
	static void PlayAudioEvent(ch* name) { Native::Function::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT", name); }
	//static void PlayAudioEventFromObject(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_OBJECT", p0, p1); }
	//static void PlayAudioEventFromPed(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_PED", p0, p1); }
	//static void PlayAudioEventFromVehicle(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_VEHICLE", p0, p1); }
	static void PlaySound(i32 soundid, ch* soundname) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND", soundid, soundname); }
	static void PlaySoundFromObject(i32 soundid, ch* soundname, Object o) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND_FROM_OBJECT", soundid, soundname, o); }
	static void PlaySoundFromPed(i32 soundid, ch* soundname, Ped p) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND_FROM_PED", soundid, soundname, p); }
	static void PlaySoundFromPosition(i32 soundid, ch* soundname, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND_FROM_POSITION", soundid, soundname, pX, pY, pZ); }
	static void PlaySoundFromVehicle(i32 soundid, ch* soundname, Vehicle v) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND_FROM_VEHICLE", soundid, soundname, v); }
	static void PlaySoundFrontend(i32 soundid, ch* soundname) { Native::Function::Invoke<ScriptVoid>("PLAY_SOUND_FRONTEND", soundid, soundname); }
	static void PreviewRingtone(i32 ringtone) { Native::Function::Invoke<ScriptVoid>("PREVIEW_RINGTONE", ringtone); }
	static void PrintStringWithLiteralStringNow(const char* gxt, const char* text, u32 ms, u32 unknown1) { Native::Function::Invoke<ScriptVoid>("PRINT_STRING_WITH_LITERAL_STRING_NOW", gxt, text, ms, unknown1); }
	//static void PrioritizeStreamingRequest() { Native::Function::Invoke<ScriptVoid>("PRIORITIZE_STREAMING_REQUEST"); }
	static void ReleaseSoundId(u32 sid) { Native::Function::Invoke<ScriptVoid>("RELEASE_SOUND_ID", sid); }
	static void RemoveAllScriptFires() { Native::Function::Invoke<ScriptVoid>("REMOVE_ALL_SCRIPT_FIRES"); }
	//static void RemoveScriptFire(u32 fireid) { Native::Function::Invoke<ScriptVoid>("REMOVE_SCRIPT_FIRE", fireid); }
	static void RequestCollisionAtPosn(f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("REQUEST_COLLISION_AT_POSN", pX, pY, pZ); }
	static void SetCameraControlsDisabledWithPlayerControls(bool value) { Native::Function::Invoke<ScriptVoid>("SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS", value); }
	static void SetCarDensityMultiplier(f32 mult) { Native::Function::Invoke<ScriptVoid>("SET_CAR_DENSITY_MULTIPLIER", mult); }
	static void SetFloatStat(eFloatStatistic stat, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_FLOAT_STAT", stat, value); }
	static void SetGravityOff(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_GRAVITY_OFF", value); }
	static void SetMaxWantedLevel(u32 pMaxWantedLevel) { Native::Function::Invoke<ScriptVoid>("SET_MAX_WANTED_LEVEL", pMaxWantedLevel); }
	static void SetMinigameInProgress(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_MINIGAME_IN_PROGRESS", value); }
	static void SetPedDensityMultiplier(f32 mult) { Native::Function::Invoke<ScriptVoid>("SET_PED_DENSITY_MULTIPLIER", mult); }
	static void SetRadarZoom(f32 zoom) { Native::Function::Invoke<ScriptVoid>("SET_RADAR_ZOOM", zoom); }
	static void SetStateOfClosestDoorOfType(i32 model, f32 pX, f32 pY, f32 pZ, b8 locked, f32 angle) { Native::Function::Invoke<ScriptVoid>("SET_STATE_OF_CLOSEST_DOOR_OF_TYPE", model, pX, pY, pZ, locked, angle); }
	static void SetTextInputActive(i32 active) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_INPUT_ACTIVE", active); }
	static void SetTimeOfDay(u32 hour, u32 minute) { Native::Function::Invoke<ScriptVoid>("SET_TIME_OF_DAY", hour, minute); }
	static void SetTimeOneDayBack() { Native::Function::Invoke<ScriptVoid>("SET_TIME_ONE_DAY_BACK"); }
	static void SetTimeOneDayForward() { Native::Function::Invoke<ScriptVoid>("SET_TIME_ONE_DAY_FORWARD"); }
	static void SetTimeScale(f32 scale) { Native::Function::Invoke<ScriptVoid>("SET_TIME_SCALE", scale); }
	static void SetVariableOnSound(u32 soundid, ch* varname, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_VARIABLE_ON_SOUND", soundid, varname, value); }
	static void SetWantedMultiplier(f32 mult) { Native::Function::Invoke<ScriptVoid>("SET_WANTED_MULTIPLIER", mult); }
	static void StartCustomMobilePhoneRinging(i32 unknown) { Native::Function::Invoke<ScriptVoid>("START_CUSTOM_MOBILE_PHONE_RINGING", unknown); }
	static void StartEndCreditsMusic() { Native::Function::Invoke<ScriptVoid>("START_END_CREDITS_MUSIC"); }
	static void StartMobilePhoneCalling() { Native::Function::Invoke<ScriptVoid>("START_MOBILE_PHONE_CALLING"); }
	static u32 StartScriptFire(f32 pX, f32 pY, f32 pZ, u32 unknown0_3, u32 unknown1_2) { return Native::Function::Invoke<u32>("START_SCRIPT_FIRE", pX, pY, pZ, unknown0_3, unknown1_2); }
	static void StopEndCreditsMusic() { Native::Function::Invoke<ScriptVoid>("STOP_END_CREDITS_MUSIC"); }
	static void StopMobilePhoneRinging() { Native::Function::Invoke<ScriptVoid>("STOP_MOBILE_PHONE_RINGING"); }
	static void StopPreviewRingtone() { Native::Function::Invoke<ScriptVoid>("STOP_PREVIEW_RINGTONE"); }


	// DRAWING
	static void DrawCheckpointWithAlpha(f32 pX, f32 pY, f32 pZ, f32 diameter, i32 R, i32 G, i32 B, i32 A) { Native::Function::Invoke<ScriptVoid>("DRAW_CHECKPOINT_WITH_ALPHA", pX, pY, pZ, diameter, R, G, B, A); }
	static void DrawCurvedWindow(f32 x, f32 y, f32 width, f32 height, i32 unknown_245) { Native::Function::Invoke<ScriptVoid>("DRAW_CURVED_WINDOW", x, y, width, height, unknown_245); }
	static void DrawLightWithRange(f32 pX, f32 pY, f32 pZ, i32 R, i32 G, i32 B, f32 range, f32 intensity_50) { Native::Function::Invoke<ScriptVoid>("DRAW_LIGHT_WITH_RANGE", pX, pY, pZ, R, G, B, range, intensity_50); }
	static void DrawRect(f32 centerX, f32 centerY, f32 width, f32 height, u32 R, u32 G, u32 B, u32 A) { Native::Function::Invoke<ScriptVoid>("DRAW_RECT", centerX, centerY, width, height, R, G, B, A); }
	static void DrawSprite(i32 tex, f32 posX, f32 posY, f32 sizeX, f32 sizeY, f32 rotation, i32 R, i32 G, i32 B, i32 A) { Native::Function::Invoke<ScriptVoid>("DRAW_SPRITE", tex, posX, posY, sizeX, sizeY, rotation, R, G, B, A); }
	static void DrawToplevelSprite(i32 tex, f32 posX, f32 posY, f32 sizeX, f32 sizeY, f32 rotation, i32 R, i32 G, i32 B, i32 A) { NativeInvoke::Invoke<ScriptVoid>("DRAW_TOPLEVEL_SPRITE", tex, posX, posY, sizeX, sizeY, rotation, R, G, B, A); }
	static void GetScriptRendertargetRenderId(i32* rid) { Native::Function::Invoke<ScriptVoid>("GET_SCRIPT_RENDERTARGET_RENDER_ID", rid); }
	static f32 GetWidthOfLiteralString(const ch* literalStr, f32 x, f32 y) { return Native::Function::Invoke<f32>("GET_WIDTH_OF_LITERAL_STRING", literalStr, x, y); }
	static void SetTextBackground(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_BACKGROUND", value); }
	static void SetTextCentre(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_CENTRE", value); }
	static void SetTextColour(u32 R, u32 G, u32 B, u32 A) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_COLOUR", R, G, B, A); }
	//static void SetTextDrawBeforeFade(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_DRAW_BEFORE_FADE", p0); }
	static void SetTextDropshadow(u32 size, u32 R, u32 G, u32 B, u32 A) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_DROPSHADOW", size, R, G, B, A); }
	static void SetTextEdge(u32 size, u32 R, u32 G, u32 B, u32 A) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_EDGE", size, R, G, B, A); }
	static void SetTextFont(u32 fontid) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_FONT", fontid); }
	static void SetTextJustify(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_JUSTIFY", value); }
	static void SetTextLineDisplay(u32 uk0_0, u32 uk1_0) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_LINE_DISPLAY", uk0_0, uk1_0); }
	static void SetTextLineHeightMult(f32 lineheight) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_LINE_HEIGHT_MULT", lineheight); }
	static void SetTextProportional(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_PROPORTIONAL", value); }
	//static void SetTextRenderId(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_RENDER_ID", p0); }
	static void SetTextRightJustify(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_RIGHT_JUSTIFY", value); }
	static void SetTextScale(f32 w, f32 h) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_SCALE", w, h); }
	//static void SetTextToUseTextFileColours(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_TO_USE_TEXT_FILE_COLOURS", p0); }
	static void SetTextUseUnderscore(b8 value) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_USE_UNDERSCORE", value); }
	static void SetTextWrap(f32 uk0_0, f32 uk1_2) { Native::Function::Invoke<ScriptVoid>("SET_TEXT_WRAP", uk0_0, uk1_2); }
	static void ToggleToplevelSprite(b8 on) { Native::Function::Invoke<ScriptVoid>("TOGGLE_TOPLEVEL_SPRITE", on); }


	// PLAYER
	static b8 CanPlayerStartMission(i32 playerIndex) { return Native::Function::Invoke<b8>("CAN_PLAYER_START_MISSION", playerIndex); }
	static void GetPlayersLastCarNoSave(Vehicle* vehicle) { Native::Function::Invoke<ScriptVoid>("GET_PLAYERS_LAST_CAR_NO_SAVE", vehicle); }
	static void GetPlayerRgbColour(i32 playerIndex, u32* R, u32* G, u32* B) { Native::Function::Invoke<ScriptVoid>("GET_PLAYER_RGB_COLOUR", playerIndex, R, G, B); }
	static eModel GetPlayerSettingsModelChoice() { return Native::Function::Invoke<eModel>("GET_PLAYERSETTINGS_MODEL_CHOICE"); }
	static ScriptAny GetPlayerToPlaceBombInCar(Vehicle vehicle) { return Native::Function::Invoke<ScriptAny>("GET_PLAYER_TO_PLACE_BOMB_IN_CAR", vehicle); }
	static void GivePlayerRagdollControl(i32 playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("GIVE_PLAYER_RAGDOLL_CONTROL", playerIndex, value); }
	static void IncreasePlayerMaxArmour(i32 playerIndex, i32 value) { Native::Function::Invoke<ScriptVoid>("INCREASE_PLAYER_MAX_ARMOUR", playerIndex, value); }
	static void IncreasePlayerMaxHealth(i32 playerIndex, i32 value) { Native::Function::Invoke<ScriptVoid>("INCREASE_PLAYER_MAX_HEALTH", playerIndex, value); }
	static b8 IsNetworkPlayerActive(i32 playerID) { return Native::Function::Invoke<b8>("IS_NETWORK_PLAYER_ACTIVE", playerID); }
	static b8 NetworkSendTextChat(i32 playerID, ch* message) { return Native::Function::Invoke<b8>("NETWORK_SEND_TEXT_CHAT", playerID, message); }
	static void RetuneRadioToStationIndex(i32 radioIndex) { Native::Function::Invoke<ScriptVoid>("RETUNE_RADIO_TO_STATION_INDEX", radioIndex); }
	static void SetDrawPlayerComponent(i32 component, b8 visible) { Native::Function::Invoke<ScriptVoid>("SET_DRAW_PLAYER_COMPONENT", component, visible); }
	static void SetEveryoneIgnorePlayer(i32 playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_EVERYONE_IGNORE_PLAYER", playerIndex, value); }
	static void SetPlayerFastReload(i32 playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_FAST_RELOAD", playerIndex, value); }
	static void SetPlayerNeverGetsTired(i32 playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_NEVER_GETS_TIRED", playerIndex, value); }
	static void SetPlayerSettingsModelVariationsChoice(i32 playerIndex) { Native::Function::Invoke<ScriptVoid>("SET_PLAYERSETTINGS_MODEL_VARIATIONS_CHOICE", playerIndex); }
	static void SetPoliceIgnorePlayer(i32 playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_POLICE_IGNORE_PLAYER", playerIndex, value); }
	static void StoreScore(i32 playerIndex, i32* value) { Native::Function::Invoke<ScriptVoid>("STORE_SCORE", playerIndex, value); }
	static void StoreWantedLevel(i32 playerIndex, i32* value) { Native::Function::Invoke<ScriptVoid>("STORE_WANTED_LEVEL", playerIndex, value); }
	
	
	// TEAM
	static i32 GetNoOfPlayersInTeam(i32 teamid) { return Native::Function::Invoke<i32>("GET_NO_OF_PLAYERS_IN_TEAM", teamid); }
	static i32 GetPlayerTeam(i32 playerIndex) { return Native::Function::Invoke<u32>("GET_PLAYER_TEAM", playerIndex); }
	static void GetTeamColour(i32 teamid, u32* col) { Native::Function::Invoke<ScriptVoid>("GET_TEAM_COLOUR", teamid, col); }
	static void GetTeamRGBColour(i32 teamid, u32* R, u32* G, u32* B) { Native::Function::Invoke<ScriptVoid>("GET_TEAM_RGB_COLOUR", teamid, R, G, B); }
	static void SetPlayerTeam(i32 playerindex, i32 teamid) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_TEAM", playerindex, teamid); }
	static void SetTeamColour(i32 teamid, u32 col) { Native::Function::Invoke<ScriptVoid>("SET_TEAM_COLOUR", teamid, col); }


	// PED
	static void ApplyForceToPed(Ped c, u32 uk0_3, f32 pX, f32 pY, f32 pZ, f32 spinX, f32 spinY, f32 spinZ, u32 uk4_0, u32 uk5_1, u32 uk6_1, u32 uk7_1) { Native::Function::Invoke<ScriptVoid>("APPLY_FORCE_TO_PED", c, uk0_3, pX, pY, pZ, spinX, spinY, spinZ, uk4_0, uk5_1, uk6_1, uk7_1); }
	static void AttachPedToCar(Ped c, Vehicle v, u32 unknown0_0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 unknown1_276, f32 unknown2_0, u32 unknown3_0, u32 unknown4_0) { Native::Function::Invoke<ScriptVoid>("ATTACH_PED_TO_CAR", c, v, unknown0_0, offsetX, offsetY, offsetZ, unknown1_276, unknown2_0, unknown3_0, unknown4_0); }
	static void BlockCharGestureAnims(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("BLOCK_CHAR_GESTURE_ANIMS", c, value); }
	static void BlockPedWeaponSwitching(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("BLOCK_PED_WEAPON_SWITCHING", c, value); }
	static void CancelCurrentlyPlayingAmbientSpeech(Ped c) { Native::Function::Invoke<ScriptVoid>("CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH", c); }
	static void ClearCharProp(Ped ped, u32 proptype) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_PROP", ped, proptype); }
	static void old_DetachPed(Ped ped, b8 unknown_true) { Native::Function::Invoke<ScriptVoid>("DETACH_PED", ped, unknown_true); }
	static void ForcePedToFleeWhilstDrivingVehicle(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("FORCE_PED_TO_FLEE_WHILST_DRIVING_VEHICLE", c, v); }
	//static b8 GetAmmoInClip(Ped ped, u32 weapon, u32 *pAmmo) { return Native::Function::Invoke<b8>("GET_AMMO_IN_CLIP", ped, weapon, pAmmo); }
	static void GetCharPropIndex2(Ped c, u32 proptype, u32* index) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_PROP_INDEX", c, proptype, index); }
	//static u32 GetCharDrawableVariation(Ped c, u32 comptype) { return Native::Function::Invoke<u32>("GET_CHAR_DRAWABLE_VARIATION", c, comptype); }
	//static u32 GetCharTextureVariation(Ped c, u32 comptype) { return Native::Function::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", c, comptype); }
	static void GetMaxAmmoInClip(Ped ped, u32 weapon, u32 *pMaxAmmo) { Native::Function::Invoke<ScriptVoid>("GET_MAX_AMMO_IN_CLIP", ped, weapon, pMaxAmmo); }
	static void GetPedBonePosition(Ped c, u32 boneid, f32 pX, f32 pY, f32 pZ, Vector3* position) { Native::Function::Invoke<ScriptVoid>("GET_PED_BONE_POSITION", c, boneid, pX, pY, pZ, position); }
	//static void GetPedBonePosition(Ped c, u32 boneid, f32 pX, f32 pY, f32 pZ, pVector3* position) { Native::Function::Invoke<ScriptVoid>("GET_PED_BONE_POSITION", c, boneid, pX, pY, pZ, position); }
	static void GivePedFakeNetworkName(Ped ped, char* Name, u8 r, u8 g, u8 b, u8 a) { Native::Function::Invoke<ScriptVoid>("GIVE_PED_FAKE_NETWORK_NAME", ped, Name, r, g, b, a); }
	static void GivePedHelmet(Ped c) { Native::Function::Invoke<ScriptVoid>("GIVE_PED_HELMET", c); }
	static void GiveWeaponToChar(Ped c, eWeapon weapon, u32 ammo, u32 unknown0) { Native::Function::Invoke<ScriptVoid>("GIVE_WEAPON_TO_CHAR", c, weapon, ammo, unknown0); }
	static void GetWeaponTypeModel(i32 weapon, i32* model) { Native::Function::Invoke<ScriptVoid>("GET_WEAPONTYPE_MODEL", weapon, model); }
	static void GetWeaponTypeSlot(i32 weapon, i32* slot) { Native::Function::Invoke<ScriptVoid>("GET_WEAPONTYPE_SLOT", weapon, slot); }
	static b8 IsAmbientSpeechPlaying(Ped c) { return Native::Function::Invoke<b8>("IS_AMBIENT_SPEECH_PLAYING", c); }
	static b8 IsCharPlayingAnim(Ped c, ch* animset, ch* animname) { return Native::Function::Invoke<b8>("IS_CHAR_PLAYING_ANIM", c, animset, animname); }
    //static b8 IsPedAMissionPed(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_A_MISSION_PED", ped); }
	static b8 IsScriptedSpeechPlaying(Ped c) { return Native::Function::Invoke<b8>("IS_SCRIPTED_SPEECH_PLAYING", c); }
	static void RemoveFakeNetworkNameFromPed(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_FAKE_NETWORK_NAME_FROM_PED", ped); }
	static void ReviveInjuredPed(Ped c) { Native::Function::Invoke<ScriptVoid>("REVIVE_INJURED_PED", c); }
	static void SayAmbientSpeech(Ped c, ch* phraseid, ScriptAny unknown0_1, ScriptAny unknown1_1, ScriptAny unknown2_0) { Native::Function::Invoke<ScriptVoid>("SAY_AMBIENT_SPEECH", c, phraseid, unknown0_1, unknown1_1, unknown2_0); }
	static void SetAmbientVoiceName(Ped p, ch* voicename) { Native::Function::Invoke<ScriptVoid>("SET_AMBIENT_VOICE_NAME", p, voicename); }
	static ScriptAny SetAmmoInClip(Ped ped, u32 weapon, u32 ammo) { return Native::Function::Invoke<ScriptAny>("SET_AMMO_IN_CLIP", ped, weapon, ammo); }
	static void SetBlockingOfNonTemporaryEvents(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_BLOCKING_OF_NON_TEMPORARY_EVENTS", c, value); }
	static void SetCharAccuracy(Ped c, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_ACCURACY", c, value); }
	static void SetCharAmmo(Ped c, eWeapon weapon, u32 ammo) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AMMO", c, weapon, ammo); }
	static void SetCharAsEnemy(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AS_ENEMY", c, value); }
	static void SetCharAsMissionChar(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AS_MISSION_CHAR", c); }
	static void SetCharCanBeKnockedOffBike(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_KNOCKED_OFF_BIKE", c, value); }
	static void SetCharCanBeShotInVehicle(Ped ped, b8 enabled) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_SHOT_IN_VEHICLE", ped, enabled); }
	static void SetCharCantBeDraggedOut(Ped ped, b8 enabled) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CANT_BE_DRAGGED_OUT", ped, enabled); }
	static void SetCharComponentVariation(Ped c, u32 comptype, u32 compmodel, u32 comptexture) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_COMPONENT_VARIATION", c, comptype, compmodel, comptexture); }
	static void SetCharCoordinates(Ped c, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_COORDINATES", c, pX, pY, pZ); }
	static void SetCharDefaultComponentVariation(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DEFAULT_COMPONENT_VARIATION", c); }
	static void SetCharDesiredHeading(Ped c, f32 dir) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DESIRED_HEADING", c, dir); }
	static void SetCharDropsWeaponsWhenDead(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DROPS_WEAPONS_WHEN_DEAD", c, value); }
	static void SetCharDruggedUp(Ped ped, b8 drugged) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DRUGGED_UP", ped, drugged); }
	static void SetCharFireDamageMultiplier(Ped c, f32 mult) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_FIRE_DAMAGE_MULTIPLIER", c, mult); }
	static void SetCharGravity(Ped c, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_GRAVITY", c, value); }
	static void SetCharHeading(Ped c, f32 dir) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_HEADING", c, dir); }
	static void SetCharInvincible(Ped c, b8 enable) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_INVINCIBLE", c, enable); }
	static void SetCharIsTargetPriority(Ped c, b8 enable) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_IS_TARGET_PRIORITY", c, enable); }
	static void SetCharMaxHealth(Ped c, i32 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_MAX_HEALTH", c, value); }
	static void SetCharMoney(Ped c, u32 amount) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_MONEY", c, amount); }
	static void SetCharNeverLeavesGroup(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_NEVER_LEAVES_GROUP", c, value); }
	static void SetCharProofs(Ped c, b8 unknown0, b8 FallingDamage, b8 unknown1, b8 unknown2, b8 unknown3) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_PROOFS", c, unknown0, FallingDamage, unknown1, unknown2, unknown3); }
	static void SetCharPropIndex(Ped c, u32 proptype, u32 index) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_PROP_INDEX", c, proptype, index); }
	static void SetCharRandomComponentVariation(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_RANDOM_COMPONENT_VARIATION", c); }
	static void SetCharSphereDefensiveArea(Ped c, f32 pX, f32 pY, f32 pZ, f32 radius) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_SPHERE_DEFENSIVE_AREA", c, pX, pY, pZ, radius); }
	static void SetCharSuffersCriticalHits(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_SUFFERS_CRITICAL_HITS", c, value); }
	static void SetCharVelocity(Ped c, f32 vX, f32 vY, f32 vZ) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_VELOCITY", c, vX, vY, vZ); }
	static void SetCharVisible(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_VISIBLE", c, value); }
	static void SetCharWantedByPolice(Ped c, b8 wanted) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WANTED_BY_POLICE", c, wanted); }
	static void SetCharWillCowerInsteadOfFleeing(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", c, value); }
	static void SetCharWillDoDrivebys(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_DO_DRIVEBYS", c, value); }
	static void SetCharWillFlyThroughWindscreen(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN", c, value); }
	static void SetCharWillMoveWhenInjured(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_MOVE_WHEN_INJURED", c, value); }
	static void SetCharWillUseCarsInCombat(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_CARS_IN_COMBAT", c, value); }
	static void SetCurrentCharWeapon(Ped c, eWeapon w, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("SET_CURRENT_CHAR_WEAPON", c, w, unknownTrue); }
	static void SetGroupCharDucksWhenAimedAt(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT", c, value); }
	static void SetIgnoreLowPriorityShockingEvents(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS", c, value); }
	static void SetPedDiesWhenInjured(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_DIES_WHEN_INJURED", c, value); }
	static void SetPedIsBlindRaging(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_IS_BLIND_RAGING", c, value); }
	static void SetPedIsDrunk(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_IS_DRUNK", c, value); }
	static void SetPedPathMayDropFromHeight(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_DROP_FROM_HEIGHT", c, value); }
	static void SetPedPathMayUseClimbovers(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_CLIMBOVERS", c, value); }
	static void SetPedPathMayUseLadders(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_LADDERS", c, value); }
	static void SetSenseRange(Ped c, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_SENSE_RANGE", c, value); }
	static void SetVoiceIdFromHeadComponent(Ped p, b8 unknown_false, b8 ismale) { Native::Function::Invoke<ScriptVoid>("SET_VOICE_ID_FROM_HEAD_COMPONENT", p, unknown_false, ismale); }
	static i32 StartCharFire(Ped c) { return Native::Function::Invoke<ScriptAny>("START_CHAR_FIRE", c); }
	static void SwitchPedToAnimated(Ped c, b8 instantly) { Native::Function::Invoke<ScriptVoid>("SWITCH_PED_TO_ANIMATED", c, instantly); }
	static ScriptAny SwitchPedToRagdoll(Ped c, u32 unknown1_10000, i32 duration, u32 nm_behavior, u32 unknown4_1, u32 unknown5_1, u32 unknown6_0) { return Native::Function::Invoke<ScriptAny>("SWITCH_PED_TO_RAGDOLL", c, unknown1_10000, duration, nm_behavior, unknown4_1, unknown5_1, unknown6_0); }
	static void UnlockRagdoll(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("UNLOCK_RAGDOLL", c, value); }
	static void WarpCharFromCarToCoord(Ped c, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_COORD", c, pX, pY, pZ); }
	static void WarpCharIntoCar(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR", c, v); }
	static void WarpCharIntoCarAsPassenger(Ped c, Vehicle v, u32 seat) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR_AS_PASSENGER", c, v, seat); }
	static void WarpCharFromCarToCar(Ped c, Vehicle v, u32 seat) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_CAR", c, v, seat); }

	// PED SEARCH
	static void AllowScenarioPedsToBeReturnedByNextCommand(b8 value) { Native::Function::Invoke<ScriptVoid>("ALLOW_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND", value); }
	static void BeginCharSearchCriteria() { Native::Function::Invoke<ScriptVoid>("BEGIN_CHAR_SEARCH_CRITERIA"); }
	static void EndCharSearchCriteria() { Native::Function::Invoke<ScriptVoid>("END_CHAR_SEARCH_CRITERIA"); }
	static b8 GetClosestChar(f32 x, f32 y, f32 z, f32 radius, u32 unknown1, u32 unknown2, Ped* ped) { return Native::Function::Invoke<b8>("GET_CLOSEST_CHAR", x, y, z, radius, unknown1, unknown2, ped); }
	static void GetRandomCharInAreaOffsetNoSave(f32 x, f32 y, f32 z, f32 sx, f32 sy, f32 sz, Ped* ped) { Native::Function::Invoke<ScriptVoid>("GET_RANDOM_CHAR_IN_AREA_OFFSET_NO_SAVE", x, y, z, sx, sy, sz, ped); }

	// RELATIONSHIPS
	static void AllowGangRelationshipsToBeChangedByNextCommand(b8 value) { Native::Function::Invoke<ScriptVoid>("ALLOW_GANG_RELATIONSHIPS_TO_BE_CHANGED_BY_NEXT_COMMAND", value); }
	static void SetCharNotDamagedByRelationshipGroup(Ped c, b8 enable, u32 rGroup) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_NOT_DAMAGED_BY_RELATIONSHIP_GROUP", c, enable, rGroup); }
	static void SetCharRelationship(Ped c, u32 RelationshipLevel, u32 rGroup) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_RELATIONSHIP", c, RelationshipLevel, rGroup); }
	static void SetCharRelationshipGroup(Ped c, u32 rGroup) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_RELATIONSHIP_GROUP", c, rGroup); }
	static void SetRelationship(u32 RelationshipLevel, u32 rGroup1, u32 rGroup2) { Native::Function::Invoke<ScriptVoid>("SET_RELATIONSHIP", RelationshipLevel, rGroup1, rGroup2); }
	//SET_RELATIONSHIP(5, 11, 0); -> group 11 hates playergroup
	//rGroup 0 is player??

	// VEHICLE
	static void ApplyForceToCar(Vehicle v, u32 uk0_3, f32 pX, f32 pY, f32 pZ, f32 spinX, f32 spinY, f32 spinZ, u32 uk4_0, u32 uk5_1, u32 uk6_1, u32 uk7_1) { Native::Function::Invoke<ScriptVoid>("APPLY_FORCE_TO_CAR", v, uk0_3, pX, pY, pZ, spinX, spinY, spinZ, uk4_0, uk5_1, uk6_1, uk7_1); }
	static void ControlCarDoor(Vehicle vehicle, u32 doorid, u32 unknown_maybe_open, f32 angle) { Native::Function::Invoke<ScriptVoid>("CONTROL_CAR_DOOR", vehicle, doorid, unknown_maybe_open, angle); }
	static void CreateRandomCharAsPassenger(Vehicle vehicle, u32 seat, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR_AS_PASSENGER", vehicle, seat, pPed); }
	static void GetCarModel2(Vehicle vehicle, int *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_MODEL", vehicle, pValue); }
	static Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, u32 unknown0_0, u32 cartype) { return Native::Function::Invoke<Vehicle>("GET_CLOSEST_CAR", x, y, z, radius, unknown0_0, cartype); }
	static ScriptAny GetClosestCarNode(f32 pX, f32 pY, f32 pZ, f32* resX, f32* resY, f32* resZ) { return Native::Function::Invoke<ScriptAny>("GET_CLOSEST_CAR_NODE", pX, pY, pZ, resX, resY, resZ); }
	static ScriptAny GetClosestCarNodeWithHeading(f32 pX, f32 pY, f32 pZ, f32* resX, f32* resY, f32* resZ, f32* heading) { return Native::Function::Invoke<ScriptAny>("GET_CLOSEST_CAR_NODE_WITH_HEADING", pX, pY, pZ, resX, resY, resZ, heading); }
	static ScriptAny GetClosestMajorCarNode(f32 pX, f32 pY, f32 pZ, f32* resX, f32* resY, f32* resZ) { return Native::Function::Invoke<ScriptAny>("GET_CLOSEST_MAJOR_CAR_NODE", pX, pY, pZ, resX, resY, resZ); }
	static ScriptAny GetNthClosestCarNodeWithHeading(f32 pX, f32 pY, f32 pZ, u32 nodenum, f32* resX, f32* resY, f32* resZ, f32* heading) { return Native::Function::Invoke<ScriptAny>("GET_NTH_CLOSEST_CAR_NODE_WITH_HEADING", pX, pY, pZ, nodenum, resX, resY, resZ, heading); }
	static ScriptAny GetNthClosestCarNodeWithHeadingOnIsland(f32 pX, f32 pY, f32 pZ, u32 nodenum, u32 areaid, f32* resX, f32* resY, f32* resZ, f32* heading, u32* unknown_maybe_areaid) { return Native::Function::Invoke<ScriptAny>("GET_NTH_CLOSEST_CAR_NODE_WITH_HEADING_ON_ISLAND", pX, pY, pZ, nodenum, areaid, resX, resY, resZ, heading, unknown_maybe_areaid); }
	static void GetVehicleDirtLevel(Vehicle vehicle, f32* intensity) { Native::Function::Invoke<ScriptVoid>("GET_VEHICLE_DIRT_LEVEL", vehicle, intensity); }
	static void GetVehicleQuaternion(Vehicle v, f32* pX, f32* pY, f32* pZ, f32* pW) { Native::Function::Invoke<ScriptVoid>("GET_VEHICLE_QUATERNION", v, pX, pY, pZ, pW); }
   //static b8 IsCarAMissionCar(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_A_MISSION_CAR", vehicle); }
	//static b8 IsVehicleExtraTurnedOn(Vehicle v, i32 extraid) { return Native::Function::Invoke<b8>("IS_VEHICLE_EXTRA_TURNED_ON", v, extraid); }
	static void LockCarDoors(Vehicle vehicle, u32 level) { Native::Function::Invoke<ScriptVoid>("LOCK_CAR_DOORS", vehicle, level); }
	static void SetCanBurstCarTyres(Vehicle v, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CAN_BURST_CAR_TYRES", v, value); }
	static void SetCarAsMissionCar(Vehicle v) { Native::Function::Invoke<ScriptVoid>("SET_CAR_AS_MISSION_CAR", v); }
	static void SetCarCoordinates(Vehicle vehicle, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_CAR_COORDINATES", vehicle, pX, pY, pZ); }
	static void SetCarHealth(Vehicle vehicle, u32 pValue) { Native::Function::Invoke<ScriptVoid>("SET_CAR_HEALTH", vehicle, pValue); }
	static void SetPetrolTankHealth(Vehicle vehicle, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_PETROL_TANK_HEALTH", vehicle, value); }
	static void SetCarCanBeDamaged(Vehicle vehicle, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CAR_CAN_BE_DAMAGED", vehicle, value); }
	static void SetCarCanBeVisiblyDamaged(Vehicle vehicle, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CAR_CAN_BE_VISIBLY_DAMAGED", vehicle, value); }
	//static void SetCarDoorLatched(Vehicle vehicle, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("SET_CAR_DOOR_LATCHED", p0, p1, p2, p3); }
	static void SetCarEngineOn(Vehicle veh, b8 running, b8 hardtorestart) { Native::Function::Invoke<ScriptVoid>("SET_CAR_ENGINE_ON", veh, running, hardtorestart); }
	static void SetCarForwardSpeed(Vehicle vehicle, f32 speed) { Native::Function::Invoke<ScriptVoid>("SET_CAR_FORWARD_SPEED", vehicle, speed); }
	static void SetCarHeading(Vehicle vehicle, f32 dir) { Native::Function::Invoke<ScriptVoid>("SET_CAR_HEADING", vehicle, dir); }
	static ScriptAny SetCarOnGroundProperly(Vehicle vehicle) { return Native::Function::Invoke<ScriptAny>("SET_CAR_ON_GROUND_PROPERLY", vehicle); }
	static void SetCarProofs(Vehicle vehicle, b8 bulletproof, b8 fireproof, b8 explosionproof, b8 collisionproof, b8 meleeproof) { Native::Function::Invoke<ScriptVoid>("SET_CAR_PROOFS", vehicle, bulletproof, fireproof, explosionproof, collisionproof, meleeproof); }
	static void SetCarStrong(Vehicle vehicle, b8 strong) { Native::Function::Invoke<ScriptVoid>("SET_CAR_STRONG", vehicle, strong); }
	static void SetCarVisible(Vehicle vehicle, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CAR_VISIBLE", vehicle, value); }
	static void SetExtraCarColours(Vehicle vehicle, eColour pColour1, eColour pColour2) { Native::Function::Invoke<ScriptVoid>("SET_EXTRA_CAR_COLOURS", vehicle, pColour1, pColour2); }
	static void SetHasBeenOwnedByPlayer(Vehicle vehicle, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_HAS_BEEN_OWNED_BY_PLAYER", vehicle, value); }
	static void SetNeedsToBeHotwired(Vehicle v, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_NEEDS_TO_BE_HOTWIRED", v, value); }
	static void SetRoomForCarByKey(Vehicle vehicle, eInteriorRoomKey key) { Native::Function::Invoke<ScriptVoid>("SET_ROOM_FOR_CAR_BY_KEY", vehicle, key); }
	static void SetSirenWithNoDriver(Vehicle v, b8 allow) { Native::Function::Invoke<ScriptVoid>("SET_SIREN_WITH_NO_DRIVER", v, allow); }
	static void SetTrainCruiseSpeed(Vehicle vehicle, f32 speed) { Native::Function::Invoke<ScriptVoid>("SET_TRAIN_CRUISE_SPEED", vehicle, speed); }
	static void SetTrainSpeed(Vehicle vehicle, f32 speed) { Native::Function::Invoke<ScriptVoid>("SET_TRAIN_SPEED", vehicle, speed); }
	static void SetVehHazardLights(Vehicle vehicle, b8 on) { Native::Function::Invoke<ScriptVoid>("SET_VEH_HAZARDLIGHTS", vehicle, on); }
	static void SetVehInteriorlight(Vehicle v, b8 on) { Native::Function::Invoke<ScriptVoid>("SET_VEH_INTERIORLIGHT", v, on); }
	static void SetVehicleDirtLevel(Vehicle vehicle, f32 intensity) { Native::Function::Invoke<ScriptVoid>("SET_VEHICLE_DIRT_LEVEL", vehicle, intensity); }
	static void SetVehicleQuaternion(Vehicle v, f32 pX, f32 pY, f32 pZ, f32 pW) { Native::Function::Invoke<ScriptVoid>("SET_VEHICLE_QUATERNION", v, pX, pY, pZ, pW); }
	static void SoundCarHorn(Vehicle vehicle, u32 duration) { Native::Function::Invoke<ScriptVoid>("SOUND_CAR_HORN", vehicle, duration); }
	static i32 StartCarFire(Vehicle v) { return Native::Function::Invoke<ScriptAny>("START_CAR_FIRE", v); }
	static void SwitchCarSiren(Vehicle v, b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_CAR_SIREN", v, on); }
	static void TurnOffVehicleExtra(Vehicle v, i32 extraid, b8 off) { Native::Function::Invoke<ScriptVoid>("TURN_OFF_VEHICLE_EXTRA", v, extraid, off); }
	static void WashVehicleTextures(Vehicle vehicle, u32 intensity) { Native::Function::Invoke<ScriptVoid>("WASH_VEHICLE_TEXTURES", vehicle, intensity); }
	//TURN_CAR_TO_FACE_COORD=3, False

	// GARAGE
	static void ChangeGarageType(const ch* garagename, i32 value) { Native::Function::Invoke<ScriptVoid>("CHANGE_GARAGE_TYPE", garagename, value); }
	static void SetGarageLeaveCameraAlone(const ch* garagename, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_GARAGE_LEAVE_CAMERA_ALONE", garagename, value); }
	//PLAYER_IS_INTERACTING_WITH_GARAGE
	//SET_TARGET_CAR_FOR_MISSION_GARAGE

	// OBJECTS
	static void AddObjectToInteriorRoomByKey(Object o, u32 roomkey) { Native::Function::Invoke<ScriptVoid>("ADD_OBJECT_TO_INTERIOR_ROOM_BY_KEY", o, roomkey); }
	static void ApplyForceToObject(Object o, u32 uk0_3, f32 pX, f32 pY, f32 pZ, f32 spinX, f32 spinY, f32 spinZ, u32 uk4_0, u32 uk5_1, u32 uk6_1, u32 uk7_1) { Native::Function::Invoke<ScriptVoid>("APPLY_FORCE_TO_OBJECT", o, uk0_3, pX, pY, pZ, spinX, spinY, spinZ, uk4_0, uk5_1, uk6_1, uk7_1); }
	static void AttachObjectToCar(Object o, Vehicle v, u32 unknown0_0, f32 pX, f32 pY, f32 pZ, f32 rX, f32 rY, f32 rZ) { Native::Function::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_CAR", o, v, unknown0_0, pX, pY, pZ, rX, rY, rZ); }
	static void AttachObjectToPed(Object o, Ped c, u32 boneid, f32 pX, f32 pY, f32 pZ, f32 rX, f32 rY, f32 rZ, u32 unknown1_0) { Native::Function::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_PED", o, c, boneid, pX, pY, pZ, rX, rY, rZ, unknown1_0); }
	static void ExtinguishObjectFire(Object o) { Native::Function::Invoke<ScriptVoid>("EXTINGUISH_OBJECT_FIRE", o); }
	static void GetObjectModel2(Object obj, int *pModel) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_MODEL", obj, pModel); }
	static void GetObjectQuaternion(Object obj, f32* pX, f32* pY, f32* pZ, f32* pW) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_QUATERNION", obj, pX, pY, pZ, pW); }
	static b8 IsObjectAttached(Object o) { return Native::Function::Invoke<b8>("IS_OBJECT_ATTACHED", o); }
	static void SetObjectCollision(Object o, bool value) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_COLLISION", o, value); }
	static void SetObjectCoordinates(Object o, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_COORDINATES", o, pX, pY, pZ); }
	static void SetObjectDynamic(Object o, bool value) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_DYNAMIC", o, value); }
	static void SetObjectHeading(Object o, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_HEADING", o, value); }
	static void SetObjectQuaternion(Object obj, f32 pX, f32 pY, f32 pZ, f32 pW) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_QUATERNION", obj, pX, pY, pZ, pW); }
	static void SetObjectRecordsCollisions(Object o, bool value) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_RECORDS_COLLISIONS", o, value); }
	static void SetObjectRotation(Object o, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_ROTATION", o, pX, pY, pZ); }
	static void SetObjectVisible(Object o, bool value) { Native::Function::Invoke<ScriptVoid>("SET_OBJECT_VISIBLE", o, value); }
	static i32 StartObjectFire(Object o) { return Native::Function::Invoke<ScriptAny>("START_OBJECT_FIRE", o); }

	// PICKUPS
	static void AddPickupToInteriorRoomByKey(Pickup p, u32 roomkey) { Native::Function::Invoke<ScriptVoid>("ADD_PICKUP_TO_INTERIOR_ROOM_BY_KEY", p, roomkey); }
	static void GetRoomKeyFromPickup(Pickup p, u32* roomkey) { Native::Function::Invoke<ScriptVoid>("GET_ROOM_KEY_FROM_PICKUP", p, roomkey); }
	static void GivePedPickupObject(Ped ped, Pickup pickup, b8 uk3) { Native::Function::Invoke<ScriptVoid>("GIVE_PED_PICKUP_OBJECT", ped, pickup, uk3); }
	static void SetPickupCollectableByCar(Pickup p, b8 collectable) { Native::Function::Invoke<ScriptVoid>("SET_PICKUP_COLLECTABLE_BY_CAR", p, collectable); }

	//BLIPS
	//static void GetBlipCoords(u32 blip, vp3* pVector) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pVector); }

	//static void GetBlipCoords(u32 blip, vp3* pVector) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pVector); }
	//static void GetBlipInfoIdPosition(u32 blip, vp3* pos) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_INFO_ID_POSITION", blip, pos); }
	//static void GetBlipCoords(Blip blip, f32* pX, f32* pY, f32* pZ) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pX, pY, pZ); }
	//static void GetBlipCoords(Blip blip, float* pVector) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pVector); }
	static u32 GetBlipInfoIdDisplay2(Blip blip) { return Native::Function::Invoke<b8>("GET_BLIP_INFO_ID_DISPLAY", blip); }
	//static Vector3 GetBlipInfoIdPosition(Blip blip) { return Native::Function::Invoke<Vector3>("GET_BLIP_INFO_ID_POSITION", blip); }
	//static void GetBlipInfoIdPosition(Blip blip, f32* pX, f32* pY, f32* pZ) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_INFO_ID_POSITION", blip, pX, pY, pZ); }
	//static void GetBlipInfoIdPosition(Blip blip, Vector3* pos) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_INFO_ID_POSITION", blip, pos); }
	static void SetBlipAsFriendly(Blip b, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_BLIP_AS_FRIENDLY", b, value); }
	static void SetBlipAsShortRange(Blip b, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_BLIP_AS_SHORT_RANGE", b, value); }
	static void SetRoute(Blip b, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_ROUTE", b, value); }

	// DECISION MAKER
	static void AddCharDecisionMakerEventResponse(u32 dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { Native::Function::Invoke<ScriptVoid>("ADD_CHAR_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
	static void AddCombatDecisionMakerEventResponse(u32 dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { Native::Function::Invoke<ScriptVoid>("ADD_COMBAT_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
	static void AddGroupDecisionMakerEventResponse(u32 dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { Native::Function::Invoke<ScriptVoid>("ADD_GROUP_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
	static void ClearCharDecisionMakerEventResponse(u32 dm, u32 eventid) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
	static void ClearCombatDecisionMakerEventResponse(u32 dm, u32 eventid) { Native::Function::Invoke<ScriptVoid>("CLEAR_COMBAT_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
	static void ClearGroupDecisionMakerEventResponse(u32 dm, u32 eventid) { Native::Function::Invoke<ScriptVoid>("CLEAR_GROUP_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
	static void CopyCharDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_CHAR_DECISION_MAKER", type, handle); }
	static void CopyCombatDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_COMBAT_DECISION_MAKER", type, handle); }
	static void CopyGroupCharDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_GROUP_CHAR_DECISION_MAKER", type, handle); }
	static void CopyGroupCombatDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_GROUP_COMBAT_DECISION_MAKER", type, handle); }
	static void CopySharedCharDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_SHARED_CHAR_DECISION_MAKER", type, handle); }
	static void CopySharedCombatDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("COPY_SHARED_COMBAT_DECISION_MAKER", type, handle); }
	static b8 DoesDecisionMakerExist(u32 dm) { return Native::Function::Invoke<b8>("DOES_DECISION_MAKER_EXIST", dm); }
	static void LoadCharDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("LOAD_CHAR_DECISION_MAKER", type, handle); }
	static void LoadCombatDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("LOAD_COMBAT_DECISION_MAKER", type, handle); }
	static void LoadGroupDecisionMaker(u32 type, u32* handle) { Native::Function::Invoke<ScriptVoid>("LOAD_GROUP_DECISION_MAKER", type, handle); }
	static void RemoveDecisionMaker(u32 handle) { Native::Function::Invoke<ScriptVoid>("REMOVE_DECISION_MAKER", handle); }
	static void SetCharDecisionMaker(Ped c, u32 handle) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DECISION_MAKER", c, handle); }
	static void SetCharDecisionMakerToDefault(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DECISION_MAKER_TO_DEFAULT", c); }
	static void SetCombatDecisionMaker(Ped c, u32 handle) { Native::Function::Invoke<ScriptVoid>("SET_COMBAT_DECISION_MAKER", c, handle); }
	static void SetDecisionMakerAttributeCanChangeTarget(u32 handle, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_CAN_CHANGE_TARGET", handle, value); }
	static void SetDecisionMakerAttributeCaution(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_CAUTION", handle, value); }
	static void SetDecisionMakerAttributeFireRate(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_FIRE_RATE", handle, value); }
	static void SetDecisionMakerAttributeLowHealth(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_LOW_HEALTH", handle, value); }
	static void SetDecisionMakerAttributeMovementStyle(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_MOVEMENT_STYLE", handle, value); }
	static void SetDecisionMakerAttributeNavigationStyle(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_NAVIGATION_STYLE", handle, value); }
	static void SetDecisionMakerAttributeRetreatingBehaviour(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_RETREATING_BEHAVIOUR", handle, value); }
	static void SetDecisionMakerAttributeSightRange(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_SIGHT_RANGE", handle, value); }
	static void SetDecisionMakerAttributeStandingStyle(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_STANDING_STYLE", handle, value); }
	static void SetDecisionMakerAttributeTargetInjuredReaction(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TARGET_INJURED_REACTION", handle, value); }
	static void SetDecisionMakerAttributeTargetLossResponse(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TARGET_LOSS_RESPONSE", handle, value); }
	static void SetDecisionMakerAttributeTeamwork(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TEAMWORK", handle, value); }
	static void SetDecisionMakerAttributeWeaponAccuracy(u32 handle, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_WEAPON_ACCURACY", handle, value); }
	static void SetGroupCharDecisionMaker(Ped c, u32 handle) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_CHAR_DECISION_MAKER", c, handle); }
	static void SetGroupCombatDecisionMaker(Ped c, u32 handle) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_COMBAT_DECISION_MAKER", c, handle); }
	static void SetGroupDecisionMaker(u32 unknown, u32 handle) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_DECISION_MAKER", unknown, handle); }

	
	//SET_ADVANCED_BOOL_IN_DECISION_MAKER
//TASK_SET_CHAR_DECISION_MAKER
//TASK_SET_COMBAT_DECISION_MAKER

	// SCRIPT FIRE
	static b8 DoesScriptFireExist(u32 fire) { return Native::Function::Invoke<b8>("DOES_SCRIPT_FIRE_EXIST", fire); }
	static void GetScriptFireCoords(u32 fire, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_SCRIPT_FIRE_COORDS", fire, pX, pY, pZ); }
	static i32 StartScriptFire(f32 x, f32 y, f32 z, i32 unknown0_1, i32 unknown1_1) { return Native::Function::Invoke<u32>("START_SCRIPT_FIRE", x, y, z, unknown0_1, unknown1_1); }

	// GROUPS
	static void GetPedGroupIndex(Ped p, u32* index) { Native::Function::Invoke<ScriptVoid>("GET_PED_GROUP_INDEX", p, index); }
	static void SetGroupFollowStatus(Group group, u32 status) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_FOLLOW_STATUS", group, status); }
	static void SetGroupFormation(Group group, u32 formation) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_FORMATION", group, formation); }
	static void SetGroupFormationSpacing(Group group, f32 space) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_FORMATION_SPACING", group, space); }
	static void SetGroupLeader(Group group, Ped leader) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_LEADER", group, leader); }
	static void SetGroupMember(Group group, Ped member) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_MEMBER", group, member); }
	static void SetGroupSeparationRange(Group group, f32 seperation) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_SEPARATION_RANGE", group, seperation); }
	//TASK_LEAVE_GROUP
	//LISTEN_TO_PLAYER_GROUP_COMMANDS
	//FIND_MAX_NUMBER_OF_GROUP_MEMBERS
	//SET_PLAYER_GROUP_TO_FOLLOW_ALWAYS
	//SET_PLAYER_GROUP_TO_FOLLOW_NEVER=$009ef680
	//CREATE_GROUP=$00a00710
	//REMOVE_GROUP=$009fbb50
	//GET_GROUP_SIZE=$00a00860
	//DOES_GROUP_EXIST=$009fc0e0
	//GET_PED_GROUP_INDEX=$00a00880
	//IS_PED_IN_GROUP=$009fc100
	//GET_GROUP_FORMATION=$00a008a0
	//SET_GROUP_FORMATION=$009fc120
	//GET_GROUP_FORMATION_SPACING=$00a008c0
	//SET_GROUP_FORMATION_SPACING=$009fc140
	//GET_CHAR_HIGHEST_PRIORITY_EVENT=$00a008e0
	//GET_GROUP_MEMBER=$00a009a0
	//GET_NTH_GROUP_MEMBER=$00a009c0
	//SET_GROUP_FOLLOW_STATUS=$009fc400
	//
	//GET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT=$009fc2f0
	//SET_SPECIFIC_PASSENGER_INDEX_TO_USE_IN_GROUPS=$009fd5f0

	// CAMERA
	static void ActivateScriptedCams(b8 on_1, b8 on_2) { Native::Function::Invoke<ScriptVoid>("ACTIVATE_SCRIPTED_CAMS", on_1, on_2); }
	static b8 AreAllNavmeshRegionsLoaded() { return Native::Function::Invoke<b8>("ARE_ALL_NAVMESH_REGIONS_LOADED"); }
	static void BeginCamCommands(i32* camera) { Native::Function::Invoke<ScriptVoid>("BEGIN_CAM_COMMANDS", camera); }
	static b8 CamIsSphereVisible(i32 camera, f32 pX, f32 pY, f32 pZ, f32 radius) { return Native::Function::Invoke<b8>("CAM_IS_SPHERE_VISIBLE", camera, pX, pY, pZ, radius); }
	static void CreateCam(i32 camtype_usually14, u32* camera) { Native::Function::Invoke<ScriptVoid>("CREATE_CAM", camtype_usually14, camera); }
	static void DestroyCam(i32 camera) { Native::Function::Invoke<ScriptVoid>("DESTROY_CAM", camera); }
	static b8 DoesCamExist(i32 camera) { return Native::Function::Invoke<b8>("DOES_CAM_EXIST", camera); }
	static void EndCamCommands(i32* camera) { Native::Function::Invoke<ScriptVoid>("END_CAM_COMMANDS", camera); }
	static void SetCamActive(i32 camera, bool value) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ACTIVE", camera, value); }
	static void GetCamFov(i32 camera, f32* fov) { Native::Function::Invoke<ScriptVoid>("GET_CAM_FOV", camera, fov); }
	static void GetCamPos(i32 camera,  f32* pX, f32* pY, f32* pZ) { Native::Function::Invoke<ScriptVoid>("GET_CAM_POS", camera, pX, pY, pZ); }
	static void GetCamRot(i32 camera, f32* angleX, f32* angleY, f32* angleZ) { Native::Function::Invoke<ScriptVoid>("GET_CAM_ROT", camera, angleX, angleY, angleZ); }
	static void GetGameCam(i32* camera) { Native::Function::Invoke<ScriptVoid>("GET_GAME_CAM", camera); }
	static void GetGameCamChild(i32* camera) { Native::Function::Invoke<ScriptVoid>("GET_GAME_CAM_CHILD", camera); }
	static void GetRootCam(i32* camera) { Native::Function::Invoke<ScriptVoid>("GET_ROOT_CAM", camera); }
	static bool IsCamActive(i32 camera) { return Native::Function::Invoke<bool>("IS_CAM_ACTIVE", camera); }
	static bool IsCamInterpolating() { return Native::Function::Invoke<bool>("IS_CAM_INTERPOLATING"); }
	static bool IsCamPropagating(i32 camera) { return Native::Function::Invoke<bool>("IS_CAM_PROPAGATING", camera); }
	static void PointCamAtCoord(i32 camera, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_COORD", camera, pX, pY, pZ); }
	static void PointCamAtObject(i32 camera, i32 obj) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_OBJECT", camera, obj); }
	static void PointCamAtPed(i32 camera, i32 ped) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_PED", camera, ped); }
	static void PointCamAtVehicle(i32 camera, i32 car) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_VEHICLE", camera, car); }
	static void SetCamFov(i32 camera, f32 fov) { Native::Function::Invoke<ScriptVoid>("SET_CAM_FOV", camera, fov); }
	static void SetCamInFrontOfPed(Ped ped) { Native::Function::Invoke<ScriptVoid>("SET_CAM_IN_FRONT_OF_PED", ped); }
	static void SetCamPos(i32 camera, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_CAM_POS", camera, pX, pY, pZ); }
	static void SetCamPropagate(i32 camera, bool value) { Native::Function::Invoke<ScriptVoid>("SET_CAM_PROPAGATE", camera, value); }
	static void SetCamRot(i32 camera, f32 angleX, f32 angleY, f32 angleZ) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ROT", camera, angleX, angleY, angleZ); }
	static void SetCamTargetPed(i32 camera, Ped ped) { Native::Function::Invoke<ScriptVoid>("SET_CAM_TARGET_PED", camera, ped); }
	static void SetDrunkCam(i32 camera, f32 intensity, i32 duration) { Native::Function::Invoke<ScriptVoid>("SET_DRUNK_CAM", camera, intensity, duration); }

	//static void SetCamAttachOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ATTACH_OFFSET", p0, p1, p2, p3); }
	//static void SetCamAttachOffsetIsRelative(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ATTACH_OFFSET_IS_RELATIVE", p0, p1); }
	//static void SetCamBehindPed(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_CAM_BEHIND_PED", p0); }
	//static void SetCamComponentShake(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { Native::Function::Invoke<ScriptVoid>("SET_CAM_COMPONENT_SHAKE", p0, p1, p2, p3, p4, p5, p6); }
	//static void SetCamDofFocuspoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("SET_CAM_DOF_FOCUSPOINT", p0, p1, p2, p3, p4); }
	//static void SetCamFarClip(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_FAR_CLIP", p0, p1); }
	//static void SetCamFarDof(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_FAR_DOF", p0, p1); }
	//static void SetCamInFrontOfPed(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_CAM_IN_FRONT_OF_PED", p0); }
	//static void SetCamInheritRollVehicle(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_INHERIT_ROLL_VEHICLE", p0, p1); }
	//static void SetCamInterpCustomSpeedGraph(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("SET_CAM_INTERP_CUSTOM_SPEED_GRAPH", p0); }
	//static void SetCamInterpStyleCore(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("SET_CAM_INTERP_STYLE_CORE", p0, p1, p2, p3, p4); }
	//static void SetCamInterpStyleDetailed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("SET_CAM_INTERP_STYLE_DETAILED", p0, p1, p2, p3, p4); }
	//static void SetCamMotionBlur(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_MOTION_BLUR", p0, p1); }
	//static void SetCamName(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_NAME", p0, p1); }
	//static void SetCamNearClip(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_NEAR_CLIP", p0, p1); }
	//static void SetCamNearDof(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_NEAR_DOF", p0, p1); }
	//static void SetCamPointOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("SET_CAM_POINT_OFFSET", p0, p1, p2, p3); }
	//static void SetCamPointOffsetIsRelative(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_POINT_OFFSET_IS_RELATIVE", p0, p1); }
	//static void SetCamPropagate(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_PROPAGATE", p0, p1); }
	//static void SetCamShake(ScriptAny p0, ScriptAny p1, ScriptAny p2) { Native::Function::Invoke<ScriptVoid>("SET_CAM_SHAKE", p0, p1, p2); }
	//static void SetCamSplineDuration(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_SPLINE_DURATION", p0, p1); }
	//static void SetCamSplineProgress(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_SPLINE_PROGRESS", p0, p1); }
	//static void SetCamSplineSpeedConstant(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_SPLINE_SPEED_CONSTANT", p0, p1); }
	//static void SetCamSplineSpeedGraph(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("SET_CAM_SPLINE_SPEED_GRAPH", p0, p1); }

	//SET_GAME_CAMERA_CONTROLS_ACTIVE
	//ATTACH_CAM_TO_OBJECT
	//ATTACH_CAM_TO_PED
	//ATTACH_CAM_TO_VEHICLE
	//ATTACH_CAM_TO_VIEWPORT
	//CAM_IS_SPHERE_VISIBLE
	//CAM_PROCESS
	//CAM_RESTORE
	//CAM_RESTORE_JUMPCUT
	//CAM_SEQUENCE_CLOSE
	//CAM_SEQUENCE_GET_PROGRESS
	//CAM_SEQUENCE_OPEN
	//CAM_SEQUENCE_REMOVE
	//CAM_SEQUENCE_START
	//CAM_SEQUENCE_STOP
	//CAM_SEQUENCE_WAIT
	//CAM_SET_CINEMATIC
	//CAM_SET_DOLLY_ZOOM_LOCK
	//CAM_SET_INTERP_GRAPH_POS
	//CAM_SET_INTERP_GRAPH_ROT
	//CAM_SET_INTERP_STATE_DST
	//CAM_SET_INTERP_STATE_SRC
	//CAM_SET_INTERPOLATION_DETAILS
	//CLONE_CAM
	//COUNT_SCRIPT_CAMS
	//COUNT_SCRIPT_CAMS_BY_TYPE_AND_OR_STATE
	//CREATE_CAM
	//DESTROY_ALL_CAMS
	//DESTROY_CAM
	//DETACH_CAM_FROM_VIEWPORT
	//DOES_CAM_EXIST
	//DOES_CAMERA_EXIST_WITH_NETWORK_ID
	//ENABLE_CAM_COLLISION
	//FORCE_GAME_TELESCOPE_CAM
	//FORCE_NO_CAM_PAUSE
	//GET_CAM_FAR_CLIP
	//GET_CAM_FAR_DOF
	//GET_CAM_FOV
	//GET_CAM_MOTION_BLUR
	//GET_CAM_NEAR_CLIP
	//GET_CAM_NEAR_DOF
	//GET_CAM_POS
	//GET_CAM_ROT
	//GET_CAM_STATE
	//GET_CAMERA_FROM_NETWORK_ID
	//GET_CINEMATIC_CAM
	//GET_FOLLOW_VEHICLE_CAM_SUBMODE
	//GET_FREE_CAM
	//GET_GAME_CAM
	//GET_GAME_CAM_CHILD
	//GET_ROOT_CAM
	//GET_SCRIPT_CAM
	//GET_SCRIPT_DRAW_CAM
	//HINT_CAM
	//IS_CAM_ACTIVE
	//IS_CAM_COLLIDING
	//IS_CAM_HAPPY
	//IS_CAM_INTERPOLATING
	//IS_CAM_PROPAGATING
	//IS_CAM_SEQUENCE_COMPLETE
	//IS_CAM_SHAKING
	//IS_FOLLOW_VEHICLE_CAM_OFFSET_ACTIVE
	//IS_SPECIFIC_CAM_INTERPOLATING
	//IS_SPHERE_VISIBLE_TO_ANOTHER_MACHINE
	//POINT_CAM_AT_CAM
	//POINT_CAM_AT_COORD
	//POINT_CAM_AT_OBJECT
	//POINT_CAM_AT_PED
	//POINT_CAM_AT_VEHICLE
	//POINT_FIXED_CAM
	//POINT_FIXED_CAM_AT_OBJ
	//POINT_FIXED_CAM_AT_PED
	//POINT_FIXED_CAM_AT_POS
	//POINT_FIXED_CAM_AT_VEHICLE
	//PROPAGATE_CAM_TO_NET_PLAYER
	//PROSTITUTE_CAM_ACTIVATE
	//RESET_CAM_INTERP_CUSTOM_SPEED_GRAPH
	//RESET_CAM_SPLINE_CUSTOM_SPEED_GRAPH
	//SET_CAM_ACTIVE
	//SET_CAM_ATTACH_OFFSET
	//SET_CAM_ATTACH_OFFSET_IS_RELATIVE
	//SET_CAM_BEHIND_PED
	//SET_CAM_COMPONENT_SHAKE
	//SET_CAM_DOF_FOCUSPOINT
	//SET_CAM_FAR_CLIP
	//SET_CAM_FAR_DOF
	//SET_CAM_FOV
	//SET_CAM_IN_FRONT_OF_PED
	//SET_CAM_INHERIT_ROLL_OBJECT
	//SET_CAM_INHERIT_ROLL_PED
	//SET_CAM_INHERIT_ROLL_VEHICLE
	//SET_CAM_INTERP_CUSTOM_SPEED_GRAPH
	//SET_CAM_INTERP_DETAIL_ROT_STYLE_ANGLES
	//SET_CAM_INTERP_DETAIL_ROT_STYLE_QUATS
	//SET_CAM_INTERP_STYLE_CORE
	//SET_CAM_INTERP_STYLE_DETAILED
	//SET_CAM_MOTION_BLUR
	//SET_CAM_NAME
	//SET_CAM_NEAR_CLIP
	//SET_CAM_NEAR_DOF
	//SET_CAM_POINT_OFFSET
	//SET_CAM_POINT_OFFSET_IS_RELATIVE
	//SET_CAM_POS
	//SET_CAM_PROPAGATE
	//SET_CAM_ROLL
	//SET_CAM_ROT
	//SET_CAM_SHAKE
	//SET_CAM_SPLINE_CUSTOM_SPEED_GRAPH
	//SET_CAM_SPLINE_DURATION
	//SET_CAM_SPLINE_PROGRESS
	//SET_CAM_SPLINE_SPEED_CONSTANT
	//SET_CAM_SPLINE_SPEED_GRAPH
	//SET_CAM_STATE
	//SET_CAM_TARGET_PED
	//SET_CAMERA_AUTO_SCRIPT_ACTIVATION
	//SET_CAMERA_BEGIN_CAM_COMMANDS_REQUIRED
	//SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS
	//SET_CAMERA_STATE
	//SET_DRUNK_CAM
	//SET_FIXED_CAM_POS
	//SET_FOLLOW_VEHICLE_CAM_OFFSET
	//SET_FOLLOW_VEHICLE_CAM_SUBMODE
	//SET_GAME_CAM_HEADING
	//SET_GAME_CAM_PITCH
	//SET_GAME_CAMERA_CONTROLS_ACTIVE
	//SET_PTFX_CAM_INSIDE_VEHICLE
	//SET_TELESCOPE_CAM_ANGLE_LIMITS
	//SNAPSHOT_CAM
	//STOP_PROPAGATING_CAM_TO_NET_PLAYER
	//UNATTACH_CAM
	//UNINHERIT_CAM_ROLL
	//UNPOINT_CAM
	//
	//CELL_CAM_ACTIVATE
	//CELL_CAM_IS_CHAR_VISIBLE
	//CELL_CAM_IS_CHAR_VISIBLE_NO_FACE_CHECK
	//CELL_CAM_SET_CENTRE_POS
	//CELL_CAM_SET_COLOUR_BRIGHTNESS
	//CELL_CAM_SET_ZOOM

	// NATURAL MOTION
	static b8 CheckNmFeedback(Ped ped, u32 valueid, u32 unknown2_1) { return Native::Function::Invoke<b8>("CHECK_NM_FEEDBACK", ped, valueid, unknown2_1); }
	static void CreateNmMessage(b8 activate, u32 messageid) { Native::Function::Invoke<ScriptVoid>("CREATE_NM_MESSAGE", activate, messageid); }
	static void SendNmMessage(Ped ped) { Native::Function::Invoke<ScriptVoid>("SEND_NM_MESSAGE", ped); }
	static void SetNmMessageInstanceIndex(u32 valueid, u32 uk0_always0, u32 instanceHandle, u32 uk1_always0) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_INSTANCE_INDEX", valueid, uk0_always0, instanceHandle, uk1_always0); }
	static void SetNmMessageBool(u32 valueid, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_BOOL", valueid, value); }
	static void SetNmMessageFloat(u32 valueid, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_FLOAT", valueid, value); }
	static void SetNmMessageInt(u32 valueid, i32 value) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_INT", valueid, value); }
	static void SetNmMessageString(u32 valueid, const ch* value) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_STRING", valueid, value); }
	static void SetNmMessageVec3(u32 valueid, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_NM_MESSAGE_VEC3", valueid, pX, pY, pZ); }


	//BLEND_FROM_NM_WITH_ANIM
	//CHECK_NM_FEEDBACK
	//CREATE_NM_MESSAGE
	//SEND_NM_MESSAGE
	//SET_NM_ANIM_POSE
	//SET_NM_MESSAGE_BOOL
	//SET_NM_MESSAGE_FLOAT
	//SET_NM_MESSAGE_INSTANCE_INDEX
	//SET_NM_MESSAGE_INT
	//SET_NM_MESSAGE_STRING
	//SET_NM_MESSAGE_VEC3

	// TASKS
	static void SetCharKeepTask(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_KEEP_TASK", c, value); }
	static void SetDriveTaskCruiseSpeed(Ped c, f32 speed) { Native::Function::Invoke<ScriptVoid>("SET_DRIVE_TASK_CRUISE_SPEED", c, speed); }
	static void TaskAchieveHeading(Ped c, f32 heading) { Native::Function::Invoke<ScriptVoid>("TASK_ACHIEVE_HEADING", c, heading); }
	static void TaskAimGunAtChar(Ped c, Ped target, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_AIM_GUN_AT_CHAR", c, target, duration); } 
	static void TaskAimGunAtCoord(Ped c, f32 tX, f32 tY, f32 tZ, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_AIM_GUN_AT_COORD", c, tX, tY, tZ, duration); }
	static void TaskCarDriveWander(Ped ped, Vehicle vehicle, f32 speed, u32 unknown1_1) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_DRIVE_WANDER", ped, vehicle, speed, unknown1_1); }
	static void TaskCarMission(Ped ped, Vehicle vehicle, u32 target, u32 missiontype, f32 speed, u32 drivingstyle, u32 unknown6_10, u32 unknown7_5) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION", ped, vehicle, target, missiontype, speed, drivingstyle, unknown6_10, unknown7_5); } // target is whatever missiontype requires (ie. vehicle or just 0). missiontypes: 5=wait(), 21=drivetoplayer()
	static void TaskCarMissionNotAgainstTraffic(Ped ped, Vehicle vehicle, u32 target, u32 missiontype, f32 speed, u32 drivingstyle, u32 unknown6_10, u32 unknown7_5) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION_NOT_AGAINST_TRAFFIC", ped, vehicle, target, missiontype, speed, drivingstyle, unknown6_10, unknown7_5); }
	static void TaskCarMissionCoorsTarget(Ped ped, Vehicle vehicle, f32 pX, f32 pY, f32 pZ, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION_COORS_TARGET", ped, vehicle, pX, pY, pZ, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
	static void TaskCarMissionCoorsTargetNotAgainstTraffic(Ped ped, Vehicle vehicle, f32 pX, f32 pY, f32 pZ, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC", ped, vehicle, pX, pY, pZ, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
	static void TaskCarMissionPedTarget(Ped ped, Vehicle vehicle, Ped target, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION_PED_TARGET", ped, vehicle, target, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
	static void TaskCarMissionPedTargetNotAgainstTraffic(Ped ped, Vehicle vehicle, Ped target, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_MISSION_PED_TARGET_NOT_AGAINST_TRAFFIC", ped, vehicle, target, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
	static void TaskCarTempAction(Ped ped, Vehicle vehicle, u32 action, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_TEMP_ACTION", ped, vehicle, action, duration); } // action 6 = wait?
	static void TaskCombat(Ped ped, Ped victim) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT", ped, victim); }
	static void TaskCombatHatedTargetsAroundChar(Ped c, f32 radius) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_AROUND_CHAR", c, radius); }
	static void TaskCombatHatedTargetsAroundCharTimed(Ped c, f32 radius, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_AROUND_CHAR_TIMED", c, radius, duration); }
	static void TaskCombatTimed(Ped ped, Ped victim, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT_TIMED", ped, victim, duration); }
	static void TaskDie(Ped c) { Native::Function::Invoke<ScriptVoid>("TASK_DIE", c); }
	static void TaskDrivePointRoute(Ped p, Vehicle v, f32 speed) { Native::Function::Invoke<ScriptVoid>("TASK_DRIVE_POINT_ROUTE", p, v, speed); }
	static void TaskEnterCarAsDriver(Ped ped, Vehicle vehicle, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_ENTER_CAR_AS_DRIVER", ped, vehicle, duration); }
	static void TaskEnterCarAsPassenger(Ped ped, Vehicle vehicle, i32 duration, i32 seat) { Native::Function::Invoke<ScriptVoid>("TASK_ENTER_CAR_AS_PASSENGER", ped, vehicle, duration, seat); }
	static void TaskEveryoneLeaveCar(Vehicle car) { Native::Function::Invoke<ScriptVoid>("TASK_EVERYONE_LEAVE_CAR", car); }
	static void TaskExtendRoute(f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("TASK_EXTEND_ROUTE", pX, pY, pZ); }
	static void TaskFlushRoute() { Native::Function::Invoke<ScriptVoid>("TASK_FLUSH_ROUTE"); }
	static void TaskFollowNavMeshToCoord(Ped ped, f32 pX, f32 pY, f32 pZ, i32 unknown0_2, i32 unknown1_minus1, f32 unknown2_1) { Native::Function::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_TO_COORD", ped, pX, pY, pZ, unknown0_2, unknown1_minus1, unknown2_1); }
	static void TaskFollowNavMeshToCoordNoStop(Ped ped, f32 pX, f32 pY, f32 pZ,i32 unknown0_2, i32 unknown1_minus1, f32 unknown2_1) { Native::Function::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_TO_COORD_NO_STOP", ped, pX, pY, pZ, unknown0_2, unknown1_minus1, unknown2_1); }
	static void TaskGoStraightToCoord(Ped c, f32 pX, f32 pY, f32 pZ, i32 unknown2, i32 unknown45000) { Native::Function::Invoke<ScriptVoid>("TASK_GO_STRAIGHT_TO_COORD", c, pX, pY, pZ, unknown2, unknown45000); }
	static void TaskGotoCharOffset(Ped c, Ped target, i32 duration, f32 offsetright, f32 offsetfront) { Native::Function::Invoke<ScriptVoid>("TASK_GOTO_CHAR_OFFSET", c, target, duration, offsetright, offsetfront); }
	static void TaskGuardCurrentPosition(Ped c, f32 unknown0_15, f32 unknown1_10, u32 unknown2_1) { Native::Function::Invoke<ScriptVoid>("TASK_GUARD_CURRENT_POSITION", c, unknown0_15, unknown1_10, unknown2_1); }
	static void TaskHandsUp(Ped c, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_HANDS_UP", c, duration); }
	static void TaskHeliMission(Ped c, Vehicle heli, u32 uk0_0, u32 uk1_0, f32 pX, f32 pY, f32 pZ, u32 uk2_4, f32 speed, u32 uk3_5, f32 uk4_minus1, u32 uk5_round_z_plus_1, u32 uk6_40) { Native::Function::Invoke<ScriptVoid>("TASK_HELI_MISSION", c, heli, uk0_0, uk1_0, pX, pY, pZ, uk2_4, speed, uk3_5, uk4_minus1, uk5_round_z_plus_1, uk6_40); }
	static void TaskLeaveAnyCar(Ped c) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_ANY_CAR", c); }
	static void TaskLeaveCar(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_CAR", c, v); }
	static void TaskLeaveCarDontCloseDoor(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_CAR_DONT_CLOSE_DOOR", c, v); }
	static void TaskLeaveCarImmediately(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_CAR_IMMEDIATELY", c, v); }
	static void TaskLookAtChar(Ped c, Ped target, i32 duration, u32 unknown_0) { Native::Function::Invoke<ScriptVoid>("TASK_LOOK_AT_CHAR", c, target, duration, unknown_0); }
	static void TaskLookAtCoord(Ped c, f32 tX, f32 tY, f32 tZ, i32 duration, u32 unknown_0) { Native::Function::Invoke<ScriptVoid>("TASK_LOOK_AT_COORD", c, tX, tY, tZ, duration, unknown_0); }
	static void TaskLookAtObject(Ped c, Object target, i32 duration, u32 unknown_0) { Native::Function::Invoke<ScriptVoid>("TASK_LOOK_AT_OBJECT", c, target, duration, unknown_0); }
	static void TaskLookAtVehicle(Ped c, Vehicle target, i32 duration, u32 unknown_0) { Native::Function::Invoke<ScriptVoid>("TASK_LOOK_AT_VEHICLE", c, target, duration, unknown_0); }
	static void TaskOpenDriverDoor(Ped c, Vehicle v, u32 unknown0) { Native::Function::Invoke<ScriptVoid>("TASK_OPEN_DRIVER_DOOR", c, v, unknown0); }
	static void TaskOpenPassengerDoor(Ped c, Vehicle v, i32 seatindex, u32 unknown0) { Native::Function::Invoke<ScriptVoid>("TASK_OPEN_PASSENGER_DOOR", c, v, seatindex, unknown0); }
	static void TaskPause(Ped c, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_PAUSE", c, duration); }
	static void TaskPlayAnim(Ped ped, const ch *animname, const ch *animset, f32 speed, i32 p5_0, i32 p6_0, i32 p7_0, i32 p8_0, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_PLAY_ANIM", ped, animname, animset, speed, p5_0, p6_0, p7_0, p8_0, duration); }
	static void TaskPlayAnimWithFlags(Ped ped, const ch *animname, const ch *animset, f32 speed, i32 duration, u32 flags) { Native::Function::Invoke<ScriptVoid>("TASK_PLAY_ANIM_WITH_FLAGS", ped, animname, animset, speed, duration, flags); }
	static void TaskSetCharDecisionMaker(Ped c, u32 dmhandle) { Native::Function::Invoke<ScriptVoid>("TASK_SET_CHAR_DECISION_MAKER", c, dmhandle); }
	static void TaskSetCombatDecisionMaker(Ped c, u32 dmhandle) { Native::Function::Invoke<ScriptVoid>("TASK_SET_COMBAT_DECISION_MAKER", c, dmhandle); }
	static void TaskShootAtChar(Ped c, Ped target, i32 duration, i32 mode) { Native::Function::Invoke<ScriptVoid>("TASK_SHOOT_AT_CHAR", c, target, duration, mode); } 
	static void TaskSmartFleeChar(Ped ped, Ped fleefrom, f32 unknown0_100, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_SMART_FLEE_CHAR", ped, fleefrom, unknown0_100, duration); }
	static void TaskSmartFleeCharPreferringPavements(Ped ped, Ped fleefrom, f32 unknown0_100, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_SMART_FLEE_CHAR_PREFERRING_PAVEMENTS", ped, fleefrom, unknown0_100, duration); }
	static void TaskSmartFleePoint(Ped ped, f32 pX, f32 pY, f32 pZ, f32 unknown0_100, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_SMART_FLEE_POINT", ped, pX, pY, pZ, unknown0_100, duration); }
	static void TaskStandStill(Ped c, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_STAND_STILL", c, duration); }
	static void TaskStartScenarioAtPosition(Ped ped, const ch *scenario, f32 x, f32 y, f32 z, u32 unknown0_0) { Native::Function::Invoke<ScriptVoid>("TASK_START_SCENARIO_AT_POSITION", ped, scenario, x, y, z, unknown0_0); }
	static void TaskSwapWeapon(Ped c, eWeapon weapon) { Native::Function::Invoke<ScriptVoid>("TASK_SWAP_WEAPON", c, weapon); }
	static void TaskTurnCharToFaceChar(Ped c, Ped target) { Native::Function::Invoke<ScriptVoid>("TASK_TURN_CHAR_TO_FACE_CHAR", c, target); }
	static void TaskTurnCharToFaceCoord(Ped c, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("TASK_TURN_CHAR_TO_FACE_COORD", c, pX, pY, pZ); }
	static void TaskUseMobilePhone(Ped c, b8 useit) { Native::Function::Invoke<ScriptVoid>("TASK_USE_MOBILE_PHONE", c, useit); }
	static void TaskUseMobilePhoneTimed(Ped c, i32 duration) { Native::Function::Invoke<ScriptVoid>("TASK_USE_MOBILE_PHONE_TIMED", c, duration); }
	static void TaskWanderStandard(Ped c) { Native::Function::Invoke<ScriptVoid>("TASK_WANDER_STANDARD", c); }
	static void TaskWarpCharIntoCarAsDriver(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("TASK_WARP_CHAR_INTO_CAR_AS_DRIVER", c, v); }
	static void TaskWarpCharIntoCarAsPassenger(Ped c, Vehicle v, i32 seat) { Native::Function::Invoke<ScriptVoid>("TASK_WARP_CHAR_INTO_CAR_AS_PASSENGER", c, v, seat); }

	static void OpenSequenceTask(u32 *task) { Native::Function::Invoke<ScriptVoid>("OPEN_SEQUENCE_TASK", task); }
	static void CloseSequenceTask(u32 task) { Native::Function::Invoke<ScriptVoid>("CLOSE_SEQUENCE_TASK", task); }
	static void TaskPerformSequence(Ped ped, u32 task) { Native::Function::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE", ped, task); }
	static void ClearSequenceTask(u32 task) { Native::Function::Invoke<ScriptVoid>("CLEAR_SEQUENCE_TASK", task); }

	//static void TaskCarDriveToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_DRIVE_TO_COORD", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	//static void TaskCarDriveToCoordNotAgainstTraffic(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { Native::Function::Invoke<ScriptVoid>("TASK_CAR_DRIVE_TO_COORD_NOT_AGAINST_TRAFFIC", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	//static void TaskCharSlideToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD", p0, p1, p2, p3, p4, p5); }
	//static void TaskCharSlideToCoordAndPlayAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13) { Native::Function::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD_AND_PLAY_ANIM", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	//static void TaskCharSlideToCoordHdgRate(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { Native::Function::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD_HDG_RATE", p0, p1, p2, p3, p4, p5, p6); }
	//static void TaskChatWithChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_CHAT_WITH_CHAR", p0, p1, p2, p3); }
	//static void TaskClearLookAt(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("TASK_CLEAR_LOOK_AT", p0); }
	//static void TaskClimb(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_CLIMB", p0, p1); }
	//static void TaskClimbLadder(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_CLIMB_LADDER", p0, p1); }
	//static void TaskCombatHatedTargetsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_IN_AREA", p0, p1, p2, p3, p4); }
	//static void TaskCombatRoll(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_COMBAT_ROLL", p0, p1); }
	//static void TaskCower(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("TASK_COWER", p0); }
	//static void TaskDead(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("TASK_DEAD", p0); }
	//static void TaskDriveBy(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { Native::Function::Invoke<ScriptVoid>("TASK_DRIVE_BY", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	//static void TaskDrivePointRouteAdvanced(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_DRIVE_POINT_ROUTE_ADVANCED", p0, p1, p2, p3, p4, p5); }
	//static void TaskDuck(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_DUCK", p0, p1); }
	//static void TaskEveryoneLeaveCar(ScriptAny p0) { Native::Function::Invoke<ScriptVoid>("TASK_EVERYONE_LEAVE_CAR", p0); }
	//static void TaskFleeCharAnyMeans(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { Native::Function::Invoke<ScriptVoid>("TASK_FLEE_CHAR_ANY_MEANS", p0, p1, p2, p3, p4, p5, p6, p7); }
	//static void TaskFollowNavMeshAndSlideToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { Native::Function::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_AND_SLIDE_TO_COORD", p0, p1, p2, p3, p4, p5, p6, p7); }
	//static void TaskFollowPointRoute(ScriptAny p0, ScriptAny p1, ScriptAny p2) { Native::Function::Invoke<ScriptVoid>("TASK_FOLLOW_POINT_ROUTE", p0, p1, p2); }
	//static void TaskGetOffBoat(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_GET_OFF_BOAT", p0, p1); }
	//static void TaskGoStraightToCoordRelativeToCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { Native::Function::Invoke<ScriptVoid>("TASK_GO_STRAIGHT_TO_COORD_RELATIVE_TO_CAR", p0, p1, p2, p3, p4, p5, p6); }
	//static void TaskGoToChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_GO_TO_CHAR", p0, p1, p2, p3); }
	//static void TaskGoToCoordAnyMeans(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_GO_TO_COORD_ANY_MEANS", p0, p1, p2, p3, p4, p5); }
	//static void TaskGoToCoordWhileAiming(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11) { Native::Function::Invoke<ScriptVoid>("TASK_GO_TO_COORD_WHILE_AIMING", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); }
	//static void TaskGoToCoordWhileShooting(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { Native::Function::Invoke<ScriptVoid>("TASK_GO_TO_COORD_WHILE_SHOOTING", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	//static void TaskGoToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_GO_TO_OBJECT", p0, p1, p2, p3); }
	//static void TaskGotoCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_GOTO_CAR", p0, p1, p2, p3); }
	//static void TaskGuardAngledDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13) { Native::Function::Invoke<ScriptVoid>("TASK_GUARD_ANGLED_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	//static void TaskGuardAssignedDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { Native::Function::Invoke<ScriptVoid>("TASK_GUARD_ASSIGNED_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6); }
	//static void TaskGuardSphereDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { Native::Function::Invoke<ScriptVoid>("TASK_GUARD_SPHERE_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	//static void TaskJump(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_JUMP", p0, p1); }
	//static void TaskLeaveCarAndFlee(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_CAR_AND_FLEE", p0, p1, p2, p3, p4); }
	//static void TaskLeaveCarInDirection(ScriptAny p0, ScriptAny p1, ScriptAny p2) { Native::Function::Invoke<ScriptVoid>("TASK_LEAVE_CAR_IN_DIRECTION", p0, p1, p2); }
	//static void TaskMobileConversation(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_MOBILE_CONVERSATION", p0, p1); }
	//static void TaskOpenPassengerDoor(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_OPEN_PASSENGER_DOOR", p0, p1, p2, p3); }
	//static void TaskPerformSequenceFromProgress(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE_FROM_PROGRESS", p0, p1, p2, p3); }
	//static void TaskPerformSequenceLocally(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE_LOCALLY", p0, p1); }
	//static void TaskPickupAndCarryObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_PICKUP_AND_CARRY_OBJECT", p0, p1, p2, p3, p4, p5); }
	//static void TaskPutCharDirectlyIntoCover(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_PUT_CHAR_DIRECTLY_INTO_COVER", p0, p1, p2, p3, p4); }
	//static void TaskSeekCoverFromPed(ScriptAny p0, ScriptAny p1, ScriptAny p2) { Native::Function::Invoke<ScriptVoid>("TASK_SEEK_COVER_FROM_PED", p0, p1, p2); }
	//static void TaskSeekCoverFromPos(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_SEEK_COVER_FROM_POS", p0, p1, p2, p3, p4); }
	//static void TaskSeekCoverToCoords(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { Native::Function::Invoke<ScriptVoid>("TASK_SEEK_COVER_TO_COORDS", p0, p1, p2, p3, p4, p5, p6, p7); }
	//static void TaskSeekCoverToCoverPoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_SEEK_COVER_TO_COVER_POINT", p0, p1, p2, p3, p4, p5); }
	//static void TaskSetIgnoreWeaponRangeFlag(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_SET_IGNORE_WEAPON_RANGE_FLAG", p0, p1); }
	//static void TaskShimmy(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_SHIMMY", p0, p1); }
	//static ScriptAny TaskShimmyInDirection(ScriptAny p0, ScriptAny p1) { return Native::Function::Invoke<ScriptAny>("TASK_SHIMMY_IN_DIRECTION", p0, p1); }
	//static ScriptAny TaskShimmyLetGo(ScriptAny p0) { return Native::Function::Invoke<ScriptAny>("TASK_SHIMMY_LET_GO", p0); }
	//static void TaskShootAtChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_SHOOT_AT_CHAR", p0, p1, p2, p3); }
	//static void TaskShootAtCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_SHOOT_AT_COORD", p0, p1, p2, p3, p4, p5); }
	//static void TaskShuffleToNextCarSeat(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_SHUFFLE_TO_NEXT_CAR_SEAT", p0, p1); }
	//static void TaskSitDown(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_SIT_DOWN", p0, p1, p2, p3); }
	//static void TaskSitDownInstantly(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { Native::Function::Invoke<ScriptVoid>("TASK_SIT_DOWN_INSTANTLY", p0, p1, p2, p3); }
	//static void TaskSitDownOnNearestObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { Native::Function::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_NEAREST_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	//static void TaskSitDownOnObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { Native::Function::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	//static void TaskSitDownOnSeat(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { Native::Function::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_SEAT", p0, p1, p2, p3, p4, p5, p6, p7); }
	//static void TaskStandGuard(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { Native::Function::Invoke<ScriptVoid>("TASK_STAND_GUARD", p0, p1, p2, p3, p4, p5, p6, p7); }
	//static void TaskStartScenarioAtPosition(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { Native::Function::Invoke<ScriptVoid>("TASK_START_SCENARIO_AT_POSITION", p0, p1, p2, p3, p4, p5); }
	//static void TaskStartScenarioInPlace(ScriptAny p0, ScriptAny p1, ScriptAny p2) { Native::Function::Invoke<ScriptVoid>("TASK_START_SCENARIO_IN_PLACE", p0, p1, p2); }
	//static void TaskToggleDuck(ScriptAny p0, ScriptAny p1) { Native::Function::Invoke<ScriptVoid>("TASK_TOGGLE_DUCK", p0, p1); }
	//static void TaskUseNearestScenarioToPos(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_USE_NEAREST_SCENARIO_TO_POS", p0, p1, p2, p3, p4); }
	//static void TaskUseNearestScenarioToPosWarp(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { Native::Function::Invoke<ScriptVoid>("TASK_USE_NEAREST_SCENARIO_TO_POS_WARP", p0, p1, p2, p3, p4); }
	
	// Use Tasks like this:
	//u32 pTask;
	//OpenSequenceTask(&pTask);								// begin sequence
	//TaskGoStraightToCoord(0, x, y, z, 2, 45000);		// add task to sequence, in a sequence, use 0 as ped
	//CloseSequenceTask(pTask);								// end sequence
	//TaskPerformSequence(ped, pTask);						// execute sequence
	//ClearSequenceTask(pTask);								// clear sequence

}
}