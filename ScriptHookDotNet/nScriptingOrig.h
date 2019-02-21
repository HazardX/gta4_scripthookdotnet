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
//#include "import_unmanaged.h"
//#include "NativeContext3.h"

#pragma managed

namespace unmanaged {
namespace Native {

	typedef int ScriptVoid;		// We shall use ScriptVoid instead of explicit void because some of our template code return values.
	typedef int ScriptAny;		// ScriptAny for any types that we don't know yet :)

	typedef int Player;
	typedef int Ped;
	typedef int Vehicle;
	typedef int Cam;
	typedef int CarGenerator;
	typedef int Group;
	typedef int Train;
	typedef int Pickup;
	typedef int Object;
	typedef int Interior;
	typedef int Blip;
	typedef int Texture;
	typedef int TextureDict;
	typedef int CoverPoint;
	typedef int Fire;

	typedef int eWeapon;
	typedef int eWeaponSlot;
	typedef int eModel;
	typedef int eIntStatistic;
	typedef int eFloatStatistic;
	typedef int ePickupType;
	typedef int ePedType;
	typedef int ePedBodyPart;
	typedef int ePedComponent;
	typedef int ePedRace;
	typedef int ePedBone;
	typedef int ePedClimbState;
	typedef int ePedMoveState;
	typedef int eCheat;
	typedef int eAchievement;
	typedef int eVehicleDoor;
	typedef int eVehicleDoorLock;
	typedef int eVehicleTyre;
	typedef int eVehicleLights;
	typedef int eVehicleWindow;
	typedef int eVehicleExtra;
	typedef int eBlipDisplay;
	typedef int eBlipPriority;
	typedef int eBlipSprite;
	typedef int eBlipType;
	typedef int eWeather;
	typedef int eLanguage;
	typedef int eHUDType;
	typedef int eMapArea;
	typedef int eSound;
	typedef int eTrainStation;
	typedef int eRadioStation;
	typedef int eInteriorRoomKey;
	typedef int ePadButton;
	typedef int eTextFont;
	typedef int eColour;

	// For legacy script support...
	//typedef Ped Char;
	//typedef Vehicle Car;

	// Some real structures... these are never passed in directly, but only by reference.
	typedef int ColourIndex;
	typedef struct { float X, Y, Z; } Vector3;

	// Player
	static void AddScore(Player playerIndex, i32 score) { Native::Function::Invoke<ScriptVoid>("ADD_SCORE", playerIndex, score); }
	static void AllowPlayerToCarryNonMissionObjects(Player playerIndex, b8 allow) { Native::Function::Invoke<ScriptVoid>("ALLOW_PLAYER_TO_CARRY_NON_MISSION_OBJECTS", playerIndex, allow); }
	static void AlterWantedLevel(Player playerIndex,  u32 level) { Native::Function::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL", playerIndex, level); }
	static void AlterWantedLevelNoDrop(Player playerIndex, u32 level) { Native::Function::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL_NO_DROP", playerIndex, level); }
	static void ApplyWantedLevelChangeNow(Player playerIndex) { Native::Function::Invoke<ScriptVoid>("APPLY_WANTED_LEVEL_CHANGE_NOW", playerIndex); }
	static void ChangePlayerModel(Player playerIndex, eModel model) { Native::Function::Invoke<ScriptVoid>("CHANGE_PLAYER_MODEL", playerIndex, model); }
	static void ClearPlayerHasDamagedAtLeastOnePed(Player playerIndex) { Native::Function::Invoke<ScriptVoid>("CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
	static Player ConvertIntToPlayerIndex(u32 playerId) { return Native::Function::Invoke<Player>("CONVERT_INT_TO_PLAYERINDEX", playerId); }
	static void ClearWantedLevel(Player playerIndex) { Native::Function::Invoke<ScriptVoid>("CLEAR_WANTED_LEVEL", playerIndex); }
	static void CreatePlayer(u32 playerId, f32 x, f32 y, f32 z, Player *pPlayerIndex) { Native::Function::Invoke<ScriptVoid>("CREATE_PLAYER", playerId, x, y, z, pPlayerIndex); }
	static void DisablePlayerLockon(Player playerIndex, b8 disabled) { Native::Function::Invoke<ScriptVoid>("DISABLE_PLAYER_LOCKON", playerIndex, disabled); }
	static void DisablePlayerSprint(Player playerIndex, b8 disabled) { Native::Function::Invoke<ScriptVoid>("DISABLE_PLAYER_SPRINT", playerIndex, disabled); }
	static void GetPlayerChar(Player playerIndex, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("GET_PLAYER_CHAR", playerIndex, pPed); }
	static u32 GetPlayerId() { return Native::Function::Invoke<u32>("GET_PLAYER_ID"); }
	static void GetPlayerGroup(Player playerIndex, Group *pGroup) { Native::Function::Invoke<ScriptVoid>("GET_PLAYER_GROUP", playerIndex, pGroup); }
	static void GetPlayerMaxArmour(Player playerIndex, u32 *pMaxArmour) { Native::Function::Invoke<ScriptVoid>("GET_PLAYER_MAX_ARMOUR", playerIndex, pMaxArmour); }
	static const ch *GetPlayerName(Player playerIndex) { return Native::Function::Invoke<const ch *>("GET_PLAYER_NAME", playerIndex); }
	static u32 GetTimeSincePlayerDroveAgainstTraffic(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC", playerIndex); }
	static u32 GetTimeSincePlayerDroveOnPavement(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT", playerIndex); }
	static u32 GetTimeSincePlayerHitBuilding(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_BUILDING", playerIndex); }
	static u32 GetTimeSincePlayerHitCar(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_CAR", playerIndex); }
	static u32 GetTimeSincePlayerHitObject(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_OBJECT", playerIndex); }
	static u32 GetTimeSincePlayerHitPed(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_PED", playerIndex); }
	static u32 GetTimeSincePlayerRanLight(Player playerIndex) { return Native::Function::Invoke<u32>("GET_TIME_SINCE_PLAYER_RAN_LIGHT", playerIndex); }
	static b8 HasPlayerDamagedAtLeastOnePed(Player playerIndex) { return Native::Function::Invoke<b8>("HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
	static b8 IsPlayerClimbing(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_CLIMBING", playerIndex); }
	static b8 IsPlayerControlOn(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_CONTROL_ON", playerIndex); }
	static b8 IsPlayerDead(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_DEAD", playerIndex); }
	static b8 IsPlayerFreeAimingAtChar(Player playerIndex, Ped ped) { return Native::Function::Invoke<b8>("IS_PLAYER_FREE_AIMING_AT_CHAR", playerIndex, ped); }
	static b8 IsPlayerFreeForAmbientTask(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_FREE_FOR_AMBIENT_TASK", playerIndex); }
	static b8 IsPlayerPlaying(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_PLAYING", playerIndex); }
	static b8 IsPlayerPressingHorn(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_PRESSING_HORN", playerIndex); }
	static b8 IsPlayerTargettingAnything(Player playerIndex) { return Native::Function::Invoke<b8>("IS_PLAYER_TARGETTING_ANYTHING", playerIndex); }
	static b8 IsPlayerTargettingChar(Player playerIndex, Ped ped) { return Native::Function::Invoke<b8>("IS_PLAYER_TARGETTING_CHAR", playerIndex, ped); }
	static b8 IsPlayerTargettingObject(Player playerIndex, Object obj) { return Native::Function::Invoke<b8>("IS_PLAYER_TARGETTING_OBJECT", playerIndex, obj); }
	static b8 IsScoreGreater(Player playerIndex, u32 score) { return Native::Function::Invoke<b8>("IS_SCORE_GREATER", playerIndex, score); }
	static b8 IsWantedLevelGreater(Player playerIndex, u32 level) { return Native::Function::Invoke<b8>("IS_WANTED_LEVEL_GREATER", playerIndex, level); }
	static b8 PlayerHasChar(Player playerIndex) { return Native::Function::Invoke<b8>("PLAYER_HAS_CHAR", playerIndex); }
	static b8 PlayerHasFlashingStarsAboutToDrop(Player playerIndex) { return Native::Function::Invoke<b8>("PLAYER_HAS_FLASHING_STARS_ABOUT_TO_DROP", playerIndex); }
	static b8 PlayerHasGreyedOutStars(Player playerIndex) { return Native::Function::Invoke<b8>("PLAYER_HAS_GREYED_OUT_STARS", playerIndex); }
	static void RegisterPlayerRespawnCoords(Player playerIndex, f32 x, f32 y, f32 z) { Native::Function::Invoke<ScriptVoid>("REGISTER_PLAYER_RESPAWN_COORDS", playerIndex, x, y, z); }
	static void SetPlayerCanBeHassledByGangs(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_CAN_BE_HASSLED_BY_GANGS", playerIndex, value); }
	static void SetPlayerCanDoDriveBy(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_CAN_DO_DRIVE_BY", playerIndex, value); }
	static void SetPlayerCanUseCover(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_CAN_USE_COVER", playerIndex, value); }
	static void SetPlayerControl(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_CONTROL", playerIndex, value); }
	static void SetPlayerControlAdvanced(Player playerIndex, b8 unknown1, b8 unknown2, b8 unknown3) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_CONTROL_ADVANCED", playerIndex, unknown1, unknown2, unknown3); }
	static void SetPlayerGroupToFollowAlways(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_GROUP_TO_FOLLOW_ALWAYS", playerIndex, value); }
	static void SetPlayerInvincible(Player playerIndex, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_INVINCIBLE", playerIndex, value); }
	static void SetPlayerMoodNormal(Player playerIndex) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_MOOD_NORMAL", playerIndex); }
	static void SetPlayerMoodPissedOff(Player playerIndex, u32 unknown150) { Native::Function::Invoke<ScriptVoid>("SET_PLAYER_MOOD_PISSED_OFF", playerIndex, unknown150); }
	static void RemovePlayerHelmet(Player playerIndex, b8 remove) { Native::Function::Invoke<ScriptVoid>("REMOVE_PLAYER_HELMET", playerIndex, remove); }

	// Char
	static void AddAmmoToChar(Ped ped, eWeapon weapon, i32 amount) { Native::Function::Invoke<ScriptVoid>("ADD_AMMO_TO_CHAR", ped, weapon, amount); }
	static void AddArmourToChar(Ped ped, i32 amount) { Native::Function::Invoke<ScriptVoid>("ADD_ARMOUR_TO_CHAR", ped, amount); }
	static void ClearAllCharProps(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_ALL_CHAR_PROPS", ped); }
	static void ClearCharLastDamageBone(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_BONE", ped); }
	static void ClearCharLastDamageEntity(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_ENTITY", ped); }
	static void ClearCharLastWeaponDamage(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_WEAPON_DAMAGE", ped); }	
	static void ClearCharProp(Ped ped, b8 unknown) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_PROP", ped, unknown); }
	static void ClearCharSecondaryTask(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_SECONDARY_TASK", ped); }
	static void ClearCharTasks(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS", ped); }
	static void ClearCharTasksImmediately(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS_IMMEDIATELY", ped); }
	static void ClearRoomForChar(Ped ped) { Native::Function::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_CHAR", ped); }
	static void CreateChar(u32 type, eModel model, f32 x, f32 y, f32 z, Ped *pPed, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("CREATE_CHAR", type, model, x, y, z, pPed, unknownTrue); }
	static void CreateRandomChar(f32 x, f32 y, f32 z, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR", x, y, z, pPed); }
	static void CreateRandomCharAsDriver(Vehicle vehicle, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR_AS_DRIVER", vehicle, pPed); }
	static void CreateRandomFemaleChar(f32 x, f32 y, f32 z, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_RANDOM_FEMALE_CHAR", x, y, z, pPed); }
	static void CreateRandomMaleChar(f32 x, f32 y, f32 z, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_RANDOM_MALE_CHAR", x, y, z, pPed); }
	static void DamageChar(Ped ped, u32 hitPoints, b8 unknown) { Native::Function::Invoke<ScriptVoid>("DAMAGE_CHAR", ped, hitPoints, unknown); }
	static void DamagePedBodyPart(Ped ped, ePedBodyPart part, u32 hitPoints) { Native::Function::Invoke<ScriptVoid>("DAMAGE_PED_BODY_PART", ped, part, hitPoints); }
	static void DeleteChar(Ped *pPed) { Native::Function::Invoke<ScriptVoid>("DELETE_CHAR", pPed); }
	static void DetachPed(Ped ped, b8 unknown) { Native::Function::Invoke<ScriptVoid>("DETACH_PED", ped, unknown); }
	static void DetachPedFromWithinCar(Ped ped, b8 unknown) { Native::Function::Invoke<ScriptVoid>("DETACH_PED_FROM_WITHIN_CAR", ped, unknown); }
	static b8 DoesCharExist(Ped ped) { return Native::Function::Invoke<b8>("DOES_CHAR_EXIST", ped); }
	static void DropObject(Ped ped, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("DROP_OBJECT", ped, unknownTrue); }
	static void ExplodeCharHead(Ped ped) { Native::Function::Invoke<ScriptVoid>("EXPLODE_CHAR_HEAD", ped); }
	static void ExtinguishCharFire(Ped ped) { Native::Function::Invoke<ScriptVoid>("EXTINGUISH_CHAR_FIRE", ped); }
	static void FirePedWeapon(Ped ped, f32 x, f32 y, f32 z) { Native::Function::Invoke<ScriptVoid>("FIRE_PED_WEAPON", ped, x, y, z); }
	static void ForceCharToDropWeapon(Ped ped) { Native::Function::Invoke<ScriptVoid>("FORCE_CHAR_TO_DROP_WEAPON", ped); }
	static ScriptAny ForcePedPinnedDown(Ped ped, b8 force, u32 timerMaybe) { return Native::Function::Invoke<ScriptAny>("FORCE_PED_PINNED_DOWN", ped, force, timerMaybe); }
	static void FreezeCharPosition(Ped ped, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION", ped, frozen); }
	static void FreezeCharPositionAndDontLoadCollision(Ped ped, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION_AND_DONT_LOAD_COLLISION", ped, frozen); }
	static void GetAmmoInCharWeapon(Ped ped, eWeapon weapon, u32 *pAmmo) { Native::Function::Invoke<ScriptVoid>("GET_AMMO_IN_CHAR_WEAPON", ped, weapon, pAmmo); }
	static b8 GetAmmoInClip(Ped ped, eWeapon weapon, u32 *pAmmo) { return Native::Function::Invoke<b8>("GET_AMMO_IN_CLIP", ped, weapon, pAmmo); }
	static const ch *GetAnimGroupFromChar(Ped ped) { return Native::Function::Invoke<const ch *>("GET_ANIM_GROUP_FROM_CHAR", ped); }
	static void GetCharCoordinates(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_COORDINATES", ped, pX, pY, pZ); }
	static void GetCharHealth(Ped ped, i32 *pHealth) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_HEALTH", ped, pHealth); }
	static void GetCharAnimCurrentTime(Ped ped, const ch *animGroup, const ch *animName, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_ANIM_CURRENT_TIME", ped, animGroup, animName, pValue); }
	static void GetCharAnimTotalTime(Ped ped, const ch *animGroup, const ch *animName, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_ANIM_TOTAL_TIME", ped, animGroup, animName, pValue); }
	static void GetCharArmour(Ped ped, i32 *pArmour) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_ARMOUR", ped, pArmour); }
	static u32 GetCharDrawableVariation(Ped ped, ePedComponent component) { return Native::Function::Invoke<ScriptAny>("GET_CHAR_DRAWABLE_VARIATION", ped, component); }
	static void GetCharExtractedDisplacement(Ped ped, b8 unknown, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_EXTRACTED_DISPLACEMENT", ped, unknown, pX, pY, pZ); }
	static void GetCharHeading(Ped ped, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_HEADING", ped, pValue); }
	static void GetCharHeightAboveGround(Ped ped, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_HEIGHT_ABOVE_GROUND", ped, pValue); }
	static ScriptAny GetCharLastDamageBone(Ped ped, ePedBone *pBone) { return Native::Function::Invoke<ScriptAny>("GET_CHAR_LAST_DAMAGE_BONE", ped, pBone); }
	static b8 GetCharMeleeActionFlag0(Ped ped) { return Native::Function::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG0", ped); }
	static b8 GetCharMeleeActionFlag1(Ped ped) { return Native::Function::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG1", ped); }
	static void GetCharModel(Ped ped, eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_MODEL", ped, pModel); }
	static u32 GetCharMoney(Ped ped) { return Native::Function::Invoke<u32>("GET_CHAR_MONEY", ped); }
	static void GetCharPropIndex(Ped ped, b8 unknown, u32 *pIndex) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_PROP_INDEX", ped, unknown, pIndex); }
	static b8 GetCharReadyToBeExecuted(Ped ped) { return Native::Function::Invoke<b8>("GET_CHAR_READY_TO_BE_EXECUTED", ped); }
	static b8 GetCharReadyToBeStunned(Ped ped) { return Native::Function::Invoke<b8>("GET_CHAR_READY_TO_BE_STUNNED", ped); }
	static void GetCharSpeed(Ped ped, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_SPEED", ped, pValue); }
	static u32 GetCharTextureVariation(Ped ped, ePedComponent component) { return Native::Function::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", ped, component); }
	static void GetCharVelocity(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_VELOCITY", ped, pX, pY, pZ); }
	static void GetCharWeaponInSlot(Ped ped, eWeaponSlot slot, eWeapon *pWeapon, ScriptAny *pUnknown1, ScriptAny *pUnknown2) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_WEAPON_IN_SLOT", ped, slot, pWeapon, pUnknown1, pUnknown2); }
	static b8 GetCharWillCowerInsteadOfFleeing(Ped ped) { return Native::Function::Invoke<b8>("GET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", ped); }
	static ScriptAny GetCurrentCharWeapon(Ped ped, eWeapon *pWeapon) { return Native::Function::Invoke<ScriptAny>("GET_CURRENT_CHAR_WEAPON", ped, pWeapon); }
	static u32 GetDamageToPedBodyPart(Ped ped, ePedBodyPart part) { return Native::Function::Invoke<u32>("GET_DAMAGE_TO_PED_BODY_PART", ped, part); }
	static void GetDeadCharCoordinates(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_DEAD_CHAR_COORDINATES", ped, pX, pY, pZ); }
	static void GetDeadCharPickupCoords(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_DEAD_CHAR_PICKUP_COORDS", ped, pX, pY, pZ); }
	static void GetKeyForCharInRoom(Ped ped, eInteriorRoomKey *pKey) { Native::Function::Invoke<ScriptVoid>("GET_KEY_FOR_CHAR_IN_ROOM", ped, pKey); }
	static ScriptAny GetMaxAmmo(Ped ped, eWeapon weapon, u32 *pMaxAmmo) { return Native::Function::Invoke<ScriptAny>("GET_MAX_AMMO", ped, weapon, pMaxAmmo); }
	static void GetMaxAmmoInClip(Ped ped, eWeapon weapon, u32 *pMaxAmmo) { Native::Function::Invoke<ScriptVoid>("GET_MAX_AMMO_IN_CLIP", ped, weapon, pMaxAmmo); }
	static u32 GetNumberOfCharDrawableVariations(Ped ped, ePedComponent component) { return Native::Function::Invoke<u32>("GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS", ped, component); }
	static u32 GetNumberOfCharTextureVariations(Ped ped, ePedComponent component, u32 unknown1) { return Native::Function::Invoke<u32>("GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS", ped, component, unknown1); }
	static Object GetObjectPedIsHolding(Ped ped) { return Native::Function::Invoke<Object>("GET_OBJECT_PED_IS_HOLDING", ped); }
	static void GetOffsetFromCharInWorldCoords(Ped ped, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Native::Function::Invoke<ScriptVoid>("GET_OFFSET_FROM_CHAR_IN_WORLD_COORDS", ped, x, y, z, pOffX, pOffY, pOffZ); }
	static ePedClimbState GetPedClimbState(Ped ped) { return Native::Function::Invoke<ePedClimbState>("GET_PED_CLIMB_STATE", ped); }
	static void GetPedType(Ped ped, ePedType *pType) { Native::Function::Invoke<ScriptVoid>("GET_PED_TYPE", ped, pType); }
	static b8 HasCharBeenDamagedByCar(Ped ped, Vehicle vehicle) { return Native::Function::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CAR", ped, vehicle); }
	static b8 HasCharBeenDamagedByChar(Ped ped, Ped otherChar, b8 unknownFalse) { return Native::Function::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CHAR", ped, otherChar, unknownFalse); }
	static b8 HasCharBeenDamagedByWeapon(Ped ped, eWeapon weapon) { return Native::Function::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_WEAPON", ped, weapon); }
	static b8 HasCharGotWeapon(Ped ped, eWeapon weapon) { return Native::Function::Invoke<b8>("HAS_CHAR_GOT_WEAPON", ped, weapon); }
	static b8 HasCharSpottedChar(Ped ped, Ped otherChar) { return Native::Function::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR", ped, otherChar); }
	static b8 HasCharSpottedCharInFront(Ped ped, Ped otherChar) { return Native::Function::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR_IN_FRONT", ped, otherChar); }
	static b8 IsCharArmed(Ped ped, eWeaponSlot slot) { return Native::Function::Invoke<b8>("IS_CHAR_ARMED", ped, slot); }
	static b8 IsCharDead(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_DEAD", ped); }
	static b8 IsCharDucking(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_DUCKING", ped); }
	static b8 IsCharFacingChar(Ped ped, Ped otherChar, f32 angle) { return Native::Function::Invoke<b8>("IS_CHAR_FACING_CHAR", ped, otherChar, angle); }
	static b8 IsCharFatallyInjured(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_FATALLY_INJURED", ped); }
	static b8 IsCharGesturing(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_GESTURING", ped); }
	static b8 IsCharGettingInToACar(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_GETTING_IN_TO_A_CAR", ped); }
	static b8 IsCharGettingUp(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_GETTING_UP", ped); }
	static b8 IsCharHealthGreater(Ped ped, u32 health) { return Native::Function::Invoke<b8>("IS_CHAR_HEALTH_GREATER", ped, health); }
	static b8 IsCharInAir(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_AIR", ped); }	
	static b8 IsCharInAngledArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_2D", ped, x1, y1, x2, y2, unknown, unknownFalse); }
	static b8 IsCharInAngledArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
	static b8 IsCharInAnyBoat(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_BOAT", ped); }
	static b8 IsCharInAnyCar(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_CAR", ped); }
	static b8 IsCharInAnyHeli(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_HELI", ped); }
	static b8 IsCharInAnyPlane(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_PLANE", ped); }
	static b8 IsCharInAnyPoliceVehicle(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_POLICE_VEHICLE", ped); }
	static b8 IsCharInAnyTrain(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_ANY_TRAIN", ped); }
	static b8 IsCharInArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_IN_AREA_2D", ped, x1, y1, x2, y2, unknownFalse); }
	static b8 IsCharInArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_IN_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
	static b8 IsCharInAreaOnFoot2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_IN_AREA_ON_FOOT_2D", ped, x1, y1, x2, y2, unknownFalse); }
	static b8 IsCharInCar(Ped ped, Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CHAR_IN_CAR", ped, vehicle); }
	static b8 IsCharInFlyingVehicle(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_FLYING_VEHICLE", ped); }
	static b8 IsCharInMeleeCombat(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_MELEE_COMBAT", ped); }
	static b8 IsCharInModel(Ped ped, eModel model) { return Native::Function::Invoke<b8>("IS_CHAR_IN_MODEL", ped, model); }
	static b8 IsCharInTaxi(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_TAXI", ped); }
	static b8 IsCharInWater(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_IN_WATER", ped); }
	static b8 IsCharInjured(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_INJURED", ped); }
	static b8 IsCharMale(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_MALE", ped); }
	static b8 IsCharModel(Ped ped, eModel model) { return Native::Function::Invoke<b8>("IS_CHAR_MODEL", ped, model); }
	static b8 IsCharOnAnyBike(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_ON_ANY_BIKE", ped); }
	static b8 IsCharOnFire(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_ON_FIRE", ped); }
	static b8 IsCharOnFoot(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_ON_FOOT", ped); }
	static b8 IsCharOnScreen(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_ON_SCREEN", ped); }
	static b8 IsCharShooting(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_SHOOTING", ped); }
	static b8 IsCharShootingInArea(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CHAR_SHOOTING_IN_AREA", ped, x1, y1, x2, y2, unknownFalse); }
	static b8 IsCharSittingIdle(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_SITTING_IDLE", ped); }
	static b8 IsCharSittingInAnyCar(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_SITTING_IN_ANY_CAR", ped); }
	static b8 IsCharSittingInCar(Ped ped, Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CHAR_SITTING_IN_CAR", ped, vehicle); }
	static b8 IsCharStopped(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_STOPPED", ped); }
	static b8 IsCharStuckUnderCar(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_STUCK_UNDER_CAR", ped); }
	static b8 IsCharSwimming(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_SWIMMING", ped); }
	static b8 IsCharTouchingChar(Ped ped, Ped otherChar) { return Native::Function::Invoke<b8>("IS_CHAR_TOUCHING_CHAR", ped, otherChar); }
	static b8 IsCharTouchingObject(Ped ped, Object obj) { return Native::Function::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT", ped, obj); }
	static b8 IsCharTouchingObjectOnFoot(Ped ped, Object obj) { return Native::Function::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT_ON_FOOT", ped, obj); }
	static b8 IsCharTouchingVehicle(ScriptAny p0, ScriptAny p1) { return Native::Function::Invoke<b8>("IS_CHAR_TOUCHING_VEHICLE", p0, p1); }
	static b8 IsCharTryingToEnterALockedCar(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_TRYING_TO_ENTER_A_LOCKED_CAR", ped); }
	static b8 IsCharUsingAnyScenario(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_USING_ANY_SCENARIO", ped); }
	static b8 IsCharUsingScenario(Ped ped, const ch *scenarioName) { return Native::Function::Invoke<b8>("IS_CHAR_USING_SCENARIO", ped, scenarioName); }
	static b8 IsCharVisible(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_VISIBLE", ped); }
	static b8 IsCharWaitingForWorldCollision(Ped ped) { return Native::Function::Invoke<b8>("IS_CHAR_WAITING_FOR_WORLD_COLLISION", ped); }
	static b8 IsPedAMissionPed(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_A_MISSION_PED", ped); }
	static b8 IsPedAttachedToAnyCar(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_ATTACHED_TO_ANY_CAR", ped); }
	static b8 IsPedAttachedToObject(Ped ped, Object obj) { return Native::Function::Invoke<b8>("IS_PED_ATTACHED_TO_OBJECT", ped, obj); }
	static b8 IsPedBeingJacked(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_BEING_JACKED", ped); }
	static b8 IsPedDoingDriveby(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_DOING_DRIVEBY", ped); }
	static b8 IsPedFleeing(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_FLEEING", ped); }
	static b8 IsPedHoldingAnObject(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_HOLDING_AN_OBJECT", ped); }
	static b8 IsPedInCombat(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_IN_COMBAT", ped); }
	static b8 IsPedInCover(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_IN_COVER", ped); }
	static b8 IsPedInGroup(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_IN_GROUP", ped); }
	static b8 IsPedJacking(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_JACKING", ped); }
	static b8 IsPedLookingAtPed(Ped ped, Ped otherChar) { return Native::Function::Invoke<b8>("IS_PED_LOOKING_AT_PED", ped, otherChar); }
	static b8 IsPedRagdoll(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_RAGDOLL", ped); }
	static b8 IsPedRetreating(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_RETREATING", ped); }
	static void MarkCharAsNoLongerNeeded(Ped *pPed) { Native::Function::Invoke<ScriptVoid>("MARK_CHAR_AS_NO_LONGER_NEEDED", pPed); }
	static void ModifyCharMoveState(Ped ped, ePedMoveState state) { Native::Function::Invoke<ScriptVoid>("MODIFY_CHAR_MOVE_STATE", ped, state); }
	static void RemoveAllCharWeapons(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_ALL_CHAR_WEAPONS", ped); }
	static void RemoveCharDefensiveArea(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_CHAR_DEFENSIVE_AREA", ped); }
	static void RemoveCharElegantly(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_CHAR_ELEGANTLY", ped); }
	static void RemoveCharFromGroup(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_CHAR_FROM_GROUP", ped); }
	static ScriptAny SetAmmoInClip(Ped ped, eWeapon weapon, u32 ammo) { return Native::Function::Invoke<ScriptAny>("SET_AMMO_IN_CLIP", ped, weapon, ammo); }
	static void SetCharHealth(Ped ped, i32 health) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_HEALTH", ped, health); }
	static void SetCharWillUseCover(Ped ped, CoverPoint coverPoint) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_COVER", ped, coverPoint); }
	static void SetRoomForCharByKey(Ped ped, eInteriorRoomKey key) { Native::Function::Invoke<ScriptVoid>("SET_ROOM_FOR_CHAR_BY_KEY", ped, key); }
	static void RemovePedHelmet(Ped ped, b8 removed) { Native::Function::Invoke<ScriptVoid>("REMOVE_PED_HELMET", ped, removed); }
	static void RemoveWeaponFromChar(Ped ped, eWeapon weapon) { Native::Function::Invoke<ScriptVoid>("REMOVE_WEAPON_FROM_CHAR", ped, weapon); }

	// Ped Groups
	static void CreateGroup(b8 unknownFalse, Group *pGroup, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("CREATE_GROUP", unknownFalse, pGroup, unknownTrue); }
	static b8 DoesGroupExist(Group group) { return Native::Function::Invoke<b8>("DOES_GROUP_EXIST", group); }
	static void GetGroupLeader(Group group, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("GET_GROUP_LEADER", group, pPed); }
	static void GetGroupMember(Group group, u32 index, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("GET_GROUP_MEMBER", group, index, pPed); }
	static void GetGroupSize(Group group, u32 *pStartIndex, u32 *pCount) { Native::Function::Invoke<ScriptVoid>("GET_GROUP_SIZE", group, pStartIndex, pCount); }
	static b8 IsGroupLeader(Ped ped, Group group) { return Native::Function::Invoke<b8>("IS_GROUP_LEADER", ped, group); }
	static b8 IsGroupMember(Ped ped, Group g) { return Native::Function::Invoke<b8>("IS_GROUP_MEMBER", ped, g); }
	static void RemoveGroup(Group group) { Native::Function::Invoke<ScriptVoid>("REMOVE_GROUP", group); }

	// Car
	static void AddUpsideDownCarCheck(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("ADD_UPSIDEDOWN_CAR_CHECK", vehicle); }
	static void AnchorBoat(Vehicle boat, b8 anchor) { Native::Function::Invoke<ScriptVoid>("ANCHOR_BOAT", boat, anchor); }
	static b8 AreTaxiLightsOn(Vehicle vehicle) { return Native::Function::Invoke<b8>("ARE_TAXI_LIGHTS_ON", vehicle); }
	static void BreakCarDoor(Vehicle vehicle, eVehicleDoor door, b8 unknownFalse) { Native::Function::Invoke<ScriptVoid>("BREAK_CAR_DOOR", vehicle, door, unknownFalse); }
	static void BurstCarTyre(Vehicle vehicle, eVehicleTyre tyre) { Native::Function::Invoke<ScriptVoid>("BURST_CAR_TYRE", vehicle, tyre); }
	static void CreateCar(u32 nameHash, f32 x, f32 y, f32 z, Vehicle *pVehicle, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("CREATE_CAR", nameHash, x, y, z, pVehicle, unknownTrue); }
	static void CreateCharAsPassenger(Vehicle vehicle, ePedType charType, eModel model, i32 passengerIndex, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_CHAR_AS_PASSENGER", vehicle, charType, model, passengerIndex, pPed); }
	static void CreateCharInsideCar(Vehicle vehicle, ePedType charType, eModel model, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("CREATE_CHAR_INSIDE_CAR", vehicle, charType, model, pPed); }
	static void ChangeCarColour(Vehicle vehicle, ColourIndex colour1, ColourIndex colour2) { Native::Function::Invoke<ScriptVoid>("CHANGE_CAR_COLOUR", vehicle, colour1, colour2); }
	static void ClearCarLastDamageEntity(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("CLEAR_CAR_LAST_DAMAGE_ENTITY", vehicle); }
	static void ClearCarLastWeaponDamage(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("CLEAR_CAR_LAST_WEAPON_DAMAGE", vehicle); }
	static void ClearRoomForCar(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_CAR", vehicle); }
	static void CloseAllCarDoors(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("CLOSE_ALL_CAR_DOORS", vehicle); }
	static b8 CreateEmergencyServicesCar(eModel model, f32 x, f32 y, f32 z) { return Native::Function::Invoke<b8>("CREATE_EMERGENCY_SERVICES_CAR", model, x, y, z); }
	static void DeleteCar(Vehicle *pVehicle) { Native::Function::Invoke<ScriptVoid>("DELETE_CAR", pVehicle); }
	static void DetachCar(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("DETACH_CAR", vehicle); }
	static b8 DoesCarHaveRoof(Vehicle vehicle) { return Native::Function::Invoke<b8>("DOES_CAR_HAVE_ROOF", vehicle); }
	static b8 DoesCarHaveStuckCarCheck(Vehicle vehicle) { return Native::Function::Invoke<b8>("DOES_CAR_HAVE_STUCK_CAR_CHECK", vehicle); }
	static b8 DoesVehicleExist(Vehicle vehicle) { return Native::Function::Invoke<b8>("DOES_VEHICLE_EXIST", vehicle); }
	static void EnablePedHelmet(Ped ped, b8 enable) { Native::Function::Invoke<ScriptVoid>("ENABLE_PED_HELMET", ped, enable); }
	static void ExplodeCar(Vehicle vehicle, b8 unknownTrue, b8 unknownFalse) { Native::Function::Invoke<ScriptVoid>("EXPLODE_CAR", vehicle, unknownTrue, unknownFalse); }
	static void ExtinguishCarFire(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("EXTINGUISH_CAR_FIRE", vehicle); }
	static void FixCar(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("FIX_CAR", vehicle); }
	static void FixCarTyre(Vehicle vehicle, eVehicleTyre tyre) { Native::Function::Invoke<ScriptVoid>("FIX_CAR_TYRE", vehicle, tyre); }
	static void ForceVehicleLights(Vehicle vehicle, eVehicleLights lights) { Native::Function::Invoke<ScriptVoid>("FORCE_CAR_LIGHTS", vehicle, lights); }
	static void FreezeCarPosition(Vehicle vehicle, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_CAR_POSITION", vehicle, frozen); }
	static void FreezeCarPositionAndDontLoadCollision(Vehicle vehicle, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_CAR_POSITION_AND_DONT_LOAD_COLLISION", vehicle, frozen); }
	static void GetCarCharIsUsing(Ped ped, Vehicle *pVehicle) { Native::Function::Invoke<ScriptVoid>("GET_CAR_CHAR_IS_USING", ped, pVehicle); }
	static void GetCarColours(Vehicle vehicle, ColourIndex *pColour1, ColourIndex *pColour2) { Native::Function::Invoke<ScriptVoid>("GET_CAR_COLOURS", vehicle, pColour1, pColour2); }
	static void GetCarCoordinates(Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_CAR_COORDINATES", vehicle, pX, pY, pZ); }
	static void GetCarDeformationAtPos(Vehicle vehicle, f32 x, f32 y, f32 z, Vector3 *pDeformation) { Native::Function::Invoke<ScriptVoid>("GET_CAR_DEFORMATION_AT_POS", vehicle, x, y, z, pDeformation); }
	static void GetCarDoorLockStatus(Vehicle vehicle, eVehicleDoorLock *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_DOOR_LOCK_STATUS", vehicle, pValue); }
	static void GetCarForwardX(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_FORWARD_X", vehicle, pValue); }
	static void GetCarForwardY(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_FORWARD_Y", vehicle, pValue); }
	static void GetCarHeading(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_HEADING", vehicle, pValue); }
	static void GetCarHealth(Vehicle vehicle, u32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_HEALTH", vehicle, pValue); }
	static void GetCarModel(Vehicle vehicle, eModel *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_MODEL", vehicle, pValue); }
	static void GetCarPitch(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_PITCH", vehicle, pValue); }
	static void GetCarRoll(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_ROLL", vehicle, pValue); }
	static void GetCarSpeed(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_SPEED", vehicle, pValue); }
	static void GetCarSpeedVector(Vehicle vehicle, Vector3 *pVector, b8 unknownFalse) { Native::Function::Invoke<ScriptVoid>("GET_CAR_SPEED_VECTOR", vehicle, pVector, unknownFalse); }
	static void GetCarUprightValue(Vehicle vehicle, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GET_CAR_UPRIGHT_VALUE", vehicle, pValue); }
	static void GetCharInCarPassengerSeat(Vehicle vehicle, u32 seatIndex, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_IN_CAR_PASSENGER_SEAT", vehicle, seatIndex, pPed); }
	static void GetDeadCarCoordinates(Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_DEAD_CAR_COORDINATES", vehicle, pX, pY, pZ); }
	static void GetDoorAngleRatio(Vehicle vehicle, eVehicleDoor door, f32 *pAngleRatio) { Native::Function::Invoke<ScriptVoid>("GET_DOOR_ANGLE_RATIO", vehicle, door, pAngleRatio); }
	static void GetDriverOfCar(Vehicle vehicle, Ped *pPed) { Native::Function::Invoke<ScriptVoid>("GET_DRIVER_OF_CAR", vehicle, pPed); }
	static f32 GetEngineHealth(Vehicle vehicle) { return Native::Function::Invoke<f32>("GET_ENGINE_HEALTH", vehicle); }
	static void GetExtraCarColours(Vehicle vehicle, ColourIndex *pColour1, ColourIndex *pColour2) { Native::Function::Invoke<ScriptVoid>("GET_EXTRA_CAR_COLOURS", vehicle, pColour1, pColour2); }
	static f32 GetHeightOfVehicle(Vehicle vehicle, f32 x, f32 y, f32 z, b8 unknownTrue1, b8 unknownTrue2) { return Native::Function::Invoke<f32>("GET_HEIGHT_OF_VEHICLE", vehicle, x, y, z, unknownTrue1, unknownTrue2); }
	static void GetKeyForCarInRoom(Vehicle vehicle, u32 *pKey) { Native::Function::Invoke<ScriptVoid>("GET_KEY_FOR_CAR_IN_ROOM", vehicle, pKey); }
	static void GetMaximumNumberOfPassengers(Vehicle vehicle, u32 *pMax) { Native::Function::Invoke<ScriptVoid>("GET_MAXIMUM_NUMBER_OF_PASSENGERS", vehicle, pMax); }
	static void GetNearestCableCar(f32 x, f32 y, f32 z, f32 radius, Vehicle *pVehicle) { Native::Function::Invoke<ScriptVoid>("GET_NEAREST_CABLE_CAR", x, y, z, radius, pVehicle); }
	static void GetNumCarColours(Vehicle vehicle, u32 *pNumColours) { Native::Function::Invoke<ScriptVoid>("GET_NUM_CAR_COLOURS", vehicle, pNumColours); }
	static void GetNumberOfPassengers(Vehicle vehicle, u32 *pNumPassengers) { Native::Function::Invoke<ScriptVoid>("GET_NUMBER_OF_PASSENGERS", vehicle, pNumPassengers); }
	static void GetOffsetFromCarGivenWorldCoords(Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Native::Function::Invoke<ScriptVoid>("GET_OFFSET_FROM_CAR_GIVEN_WORLD_COORDS", vehicle, x, y, z, pOffX, pOffY, pOffZ); }
	static void GetOffsetFromCarInWorldCoords(Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Native::Function::Invoke<ScriptVoid>("GET_OFFSET_FROM_CAR_IN_WORLD_COORDS", vehicle, x, y, z, pOffX, pOffY, pOffZ); }
	static f32 GetPetrolTankHealth(Vehicle vehicle) { return Native::Function::Invoke<f32>("GET_PETROL_TANK_HEALTH", vehicle); }
	static void GetRandomCarModelInMemory(b8 unknownTrue, u32 *pHash, ScriptAny *pUnknown) { Native::Function::Invoke<ScriptVoid>("GET_RANDOM_CAR_MODEL_IN_MEMORY", unknownTrue, pHash, pUnknown); }
	static b8 HasCarBeenDamagedByCar(Vehicle vehicle, Vehicle otherCar) { return Native::Function::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_CAR", vehicle, otherCar); }
	static b8 HasCarBeenDamagedByChar(Vehicle vehicle, Ped ped) { return Native::Function::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_CHAR", vehicle, ped); }
	static b8 HasCarBeenDamagedByWeapon(Vehicle vehicle, eWeapon weapon) { return Native::Function::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_WEAPON", vehicle, weapon); }
	static b8 HasCarBeenResprayed(Vehicle vehicle) { return Native::Function::Invoke<b8>("HAS_CAR_BEEN_RESPRAYED", vehicle); }
	static b8 IsBigVehicle(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_BIG_VEHICLE", vehicle); }
	static b8 IsCarAMissionCar(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_A_MISSION_CAR", vehicle); }
	static b8 IsCarAttached(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_ATTACHED", vehicle); }
	static b8 IsCarDead(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_DEAD", vehicle); }
	static b8 IsCarDoorDamaged(Vehicle vehicle, eVehicleDoor door) { return Native::Function::Invoke<b8>("IS_CAR_DOOR_DAMAGED", vehicle, door); }
	static b8 IsCarDoorFullyOpen(Vehicle vehicle, eVehicleDoor door) { return Native::Function::Invoke<b8>("IS_CAR_DOOR_FULLY_OPEN", vehicle, door); }
	static b8 IsCarInAirProper(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_IN_AIR_PROPER", vehicle); }
	static b8 IsCarInArea2D(Vehicle vehicle, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CAR_IN_AREA_2D", vehicle, x1, y1, x2, y2, unknownFalse); }
	static b8 IsCarInArea3D(Vehicle vehicle, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u8 unknownFalse) { return Native::Function::Invoke<b8>("IS_CAR_IN_AREA_3D", vehicle, x1, y1, z1, x2, y2, z2, unknownFalse); }
	static b8 IsCarInWater(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_IN_WATER", vehicle); }
	static b8 IsCarModel(Vehicle vehicle, eModel model) { return Native::Function::Invoke<b8>("IS_CAR_MODEL", vehicle, model); }
	static b8 IsCarOnFire(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_ON_FIRE", vehicle); }
	static b8 IsCarOnScreen(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_ON_SCREEN", vehicle); }
	static b8 IsCarPassengerSeatFree(Vehicle vehicle, u32 seatIndex) { return Native::Function::Invoke<b8>("IS_CAR_PASSENGER_SEAT_FREE", vehicle, seatIndex); }
	static b8 IsCarSirenOn(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_SIREN_ON", vehicle); }
	static b8 IsCarStopped(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_STOPPED", vehicle); }
	static b8 IsCarStoppedAtTrafficLights(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_STOPPED_AT_TRAFFIC_LIGHTS", vehicle); }
	static b8 IsCarStuckOnRoof(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_STUCK_ON_ROOF", vehicle); }
	static b8 IsCarTouchingCar(Vehicle vehicle, Vehicle otherCar) { return Native::Function::Invoke<b8>("IS_CAR_TOUCHING_CAR", vehicle, otherCar); }
	static b8 IsCarTyreBurst(Vehicle vehicle, eVehicleTyre tyre) { return Native::Function::Invoke<b8>("IS_CAR_TYRE_BURST", vehicle, tyre); }
	static b8 IsCarUpright(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_UPRIGHT", vehicle); }
	static b8 IsCarUpsidedown(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_UPSIDEDOWN", vehicle); }
	static b8 IsCarWaitingForWorldCollision(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_WAITING_FOR_WORLD_COLLISION", vehicle); }
	static b8 IsVehDriveable(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_VEH_DRIVEABLE", vehicle); }
	static b8 IsVehWindowIntact(Vehicle vehicle, eVehicleWindow window) { return Native::Function::Invoke<b8>("IS_VEH_WINDOW_INTACT", vehicle, window); }
	static b8 IsVehicleExtraTurnedOn(Vehicle vehicle, eVehicleExtra extra) { return Native::Function::Invoke<b8>("IS_VEHICLE_EXTRA_TURNED_ON", vehicle, extra); }
	static b8 IsVehicleOnAllWheels(Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_VEHICLE_ON_ALL_WHEELS", vehicle); }
	static void KnockPedOffBike(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("KNOCK_PED_OFF_BIKE", vehicle); }
	static void LockCarDoors(Vehicle vehicle, eVehicleDoor doors) { Native::Function::Invoke<ScriptVoid>("LOCK_CAR_DOORS", vehicle, doors); }
	static void MarkCarAsConvoyCar(Vehicle vehicle, b8 convoyCar) { Native::Function::Invoke<ScriptVoid>("MARK_CAR_AS_CONVOY_CAR", vehicle, convoyCar); }
	static void MarkCarAsNoLongerNeeded(Vehicle *pVehicle) { Native::Function::Invoke<ScriptVoid>("MARK_CAR_AS_NO_LONGER_NEEDED", pVehicle); }
	static void OpenCarDoor(Vehicle vehicle, eVehicleDoor door) { Native::Function::Invoke<ScriptVoid>("OPEN_CAR_DOOR", vehicle, door); }
	static void PopCarBoot(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("POP_CAR_BOOT", vehicle); }
	static void RemoveVehicleWindow(Vehicle vehicle, eVehicleWindow window) { Native::Function::Invoke<ScriptVoid>("REMOVE_CAR_WINDOW", vehicle, window); }
	static void RemoveStuckCarCheck(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("REMOVE_STUCK_CAR_CHECK", vehicle); }
	static void RemoveUpsidedownCarCheck(Vehicle vehicle) { Native::Function::Invoke<ScriptVoid>("REMOVE_UPSIDEDOWN_CAR_CHECK", vehicle); }
	static void SetEngineHealth(Vehicle vehicle, f32 health) { Native::Function::Invoke<ScriptVoid>("SET_ENGINE_HEALTH", vehicle, health); }
	static void ShutCarDoor(Vehicle vehicle, eVehicleDoor door) { Native::Function::Invoke<ScriptVoid>("SHUT_CAR_DOOR", vehicle, door); }

	// Train
	static void CreateMissionTrain(u32 unknown1, f32 x, f32 y, f32 z, b8 unknown2, Train *pTrain) { Native::Function::Invoke<ScriptVoid>("CREATE_MISSION_TRAIN", unknown1, x, y, z, unknown2, pTrain); }
	static void DeleteMissionTrain(Train *pTrain) { Native::Function::Invoke<ScriptVoid>("DELETE_MISSION_TRAIN", pTrain); }
	static eTrainStation GetCurrentStationForTrain(Train train) { return Native::Function::Invoke<eTrainStation>("GET_CURRENT_STATION_FOR_TRAIN", train); }
	static eTrainStation GetNextStationForTrain(Train train) { return Native::Function::Invoke<eTrainStation>("GET_NEXT_STATION_FOR_TRAIN", train); }
	static const ch *GetStationName(Train train, eTrainStation station) { return Native::Function::Invoke<const ch *>("GET_STATION_NAME", train, station); }
	static void MarkMissionTrainAsNoLongerNeeded(Train train) { Native::Function::Invoke<ScriptVoid>("MARK_MISSION_TRAIN_AS_NO_LONGER_NEEDED", train); }
	static void MarkMissionTrainsAsNoLongerNeeded() { Native::Function::Invoke<ScriptVoid>("MARK_MISSION_TRAINS_AS_NO_LONGER_NEEDED"); }

	// Object
	static void ClearObjectLastDamageEntity(Object obj) { Native::Function::Invoke<ScriptVoid>("CLEAR_OBJECT_LAST_DAMAGE_ENTITY", obj); }
	static void ClearRoomForObject(Object obj) { Native::Function::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_OBJECT", obj); }
	static void CreateObject(eModel model, f32 x, f32 y, f32 z, Object *pObj, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("CREATE_OBJECT", model, x, y, z, pObj, unknownTrue); }
	static void CreateObjectNoOffset(eModel model, f32 x, f32 y, f32 z, Object *pObj, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("CREATE_OBJECT_NO_OFFSET", model, x, y, z, pObj, unknownTrue); }
	static void DeleteObject(Object *pObj) { Native::Function::Invoke<ScriptVoid>("DELETE_OBJECT", pObj); }
	static void DetachObject(Object obj, b8 unknown) { Native::Function::Invoke<ScriptVoid>("DETACH_OBJECT", obj, unknown); }
	static b8 DoesObjectExist(Object obj) { return Native::Function::Invoke<b8>("DOES_OBJECT_EXIST", obj); }
	static b8 DoesObjectHavePhysics(Object obj) { return Native::Function::Invoke<b8>("DOES_OBJECT_HAVE_PHYSICS", obj); }
	static b8 DoesObjectOfTypeExistAtCoords(f32 x, f32 y, f32 z, f32 radius, eModel model) { return Native::Function::Invoke<b8>("DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS", x, y, z, radius, model); }
	static void FreezeObjectPosition(Object obj, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_OBJECT_POSITION", obj, frozen); }
	static Vehicle GetCarObjectIsAttachedTo(Object obj) { return Native::Function::Invoke<Vehicle>("GET_CAR_OBJECT_IS_ATTACHED_TO", obj); }
	static void GetObjectCoordinates(Object obj, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_COORDINATES", obj, pX, pY, pZ); }
	static f32 GetObjectFragmentDamageHealth(Object obj, b8 unknown) { return Native::Function::Invoke<f32>("GET_OBJECT_FRAGMENT_DAMAGE_HEALTH", obj, unknown); }
	static void GetObjectHeading(Object obj, f32 *pHeading) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_HEADING", obj, pHeading); }
	static void GetObjectHealth(Object obj, f32 *pHealth) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_HEALTH", obj, pHealth); }
	static void GetObjectModel(Object obj, eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_MODEL", obj, pModel); }
	static void GetObjectRotationVelocity(Object obj, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_ROTATION_VELOCITY", obj, pX, pY, pZ); }
	static void GetObjectSpeed(Object obj, f32 *pSpeed) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_SPEED", obj, pSpeed); }
	static void GetObjectVelocity(Object obj, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_OBJECT_VELOCITY", obj, pX, pY, pZ); }
	static void GetOffsetFromObjectInWorldCoords(Object obj, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Native::Function::Invoke<ScriptVoid>("GET_OFFSET_FROM_OBJECT_IN_WORLD_COORDS", obj, x, y, z, pOffX, pOffY, pOffZ); }
	static Ped GetPedObjectIsAttachedTo(Object obj) { return Native::Function::Invoke<Ped>("GET_PED_OBJECT_IS_ATTACHED_TO", obj); }
	static b8 HasObjectBeenDamaged(Object obj) { return Native::Function::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED", obj); }
	static b8 HasObjectBeenDamagedByCar(Object obj, Vehicle vehicle) { return Native::Function::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED_BY_CAR", obj, vehicle); }
	static b8 HasObjectBeenDamagedByChar(Object obj, Ped ped) { return Native::Function::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED_BY_CHAR", obj, ped); }
	static b8 HasObjectBeenUprooted(Object obj) { return Native::Function::Invoke<b8>("HAS_OBJECT_BEEN_UPROOTED", obj); }
	static b8 HasObjectCollidedWithAnything(Object obj) { return Native::Function::Invoke<b8>("HAS_OBJECT_COLLIDED_WITH_ANYTHING", obj); }
	static b8 HasPoolObjectCollidedWithCushion(Object obj) { return Native::Function::Invoke<b8>("HAS_POOL_OBJECT_COLLIDED_WITH_CUSHION", obj); }
	static b8 HasPoolObjectCollidedWithObject(Object obj, Object otherObj) { return Native::Function::Invoke<b8>("HAS_POOL_OBJECT_COLLIDED_WITH_OBJECT", obj, otherObj); }
	static b8 IsObjectInWater(Object obj) { return Native::Function::Invoke<b8>("IS_OBJECT_IN_WATER", obj); }
	static b8 IsObjectOnFire(Object obj) { return Native::Function::Invoke<b8>("IS_OBJECT_ON_FIRE", obj); }
	static b8 IsObjectOnScreen(Object obj) { return Native::Function::Invoke<b8>("IS_OBJECT_ON_SCREEN", obj); }
	static b8 IsObjectStatic(Object obj) { return Native::Function::Invoke<b8>("IS_OBJECT_STATIC", obj); }
	static b8 IsObjectUpright(Object obj, f32 angle) { return Native::Function::Invoke<b8>("IS_OBJECT_UPRIGHT", obj, angle); }
	static b8 IsObjectWithinBrainActivationRange(Object obj) { return Native::Function::Invoke<b8>("IS_OBJECT_WITHIN_BRAIN_ACTIVATION_RANGE", obj); }
	static void LoadAllObjectsNow() { Native::Function::Invoke<ScriptVoid>("LOAD_ALL_OBJECTS_NOW"); }
	static void MakeObjectTargettable(Object obj, b8 targettable) { Native::Function::Invoke<ScriptVoid>("MAKE_OBJECT_TARGETTABLE", obj, targettable); }
	static void MarkObjectAsNoLongerNeeded(Object *pObj) { Native::Function::Invoke<ScriptVoid>("MARK_OBJECT_AS_NO_LONGER_NEEDED", pObj); }

	// Models
	static b8 HasCollisionForModelLoaded(eModel model) { return Native::Function::Invoke<b8>("HAS_COLLISION_FOR_MODEL_LOADED", model); }
	static b8 HasModelLoaded(eModel model) { return Native::Function::Invoke<b8>("HAS_MODEL_LOADED", model); }
	static void RequestCollisionForModel(eModel model) { Native::Function::Invoke<ScriptVoid>("REQUEST_COLLISION_FOR_MODEL", model); }
	static void RequestModel(eModel model) { Native::Function::Invoke<ScriptVoid>("REQUEST_MODEL", model); }
	static void GetCurrentBasicCopModel(eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_BASIC_COP_MODEL", pModel); }
	static void GetCurrentBasicPoliceCarModel(eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_BASIC_POLICE_CAR_MODEL", pModel); }
	static void GetCurrentCopModel(eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_COP_MODEL", pModel); }
	static void GetCurrentPoliceCarModel(eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_POLICE_CAR_MODEL", pModel); }
	static void GetCurrentTaxiCarModel(eModel *pModel) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_TAXI_CAR_MODEL", pModel); }
	static const ch *GetDisplayNameFromVehicleModel(eModel model) { return Native::Function::Invoke<const ch *>("GET_DISPLAY_NAME_FROM_VEHICLE_MODEL", model); }
	static void GetModelDimensions(eModel model, Vector3 *pMinVector, Vector3 *pMaxVector) { Native::Function::Invoke<ScriptVoid>("GET_MODEL_DIMENSIONS", model, pMinVector, pMaxVector); }
	static const ch *GetModelNameForDebug(eModel model) { return Native::Function::Invoke<const ch *>("GET_MODEL_NAME_FOR_DEBUG", model); }
	static b8 IsThisModelABike(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_BIKE", model); }
	static b8 IsThisModelABoat(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_BOAT", model); }
	static b8 IsThisModelACar(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_CAR", model); }
	static b8 IsThisModelAHeli(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_HELI", model); }
	static b8 IsThisModelAPed(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_PED", model); }
	static b8 IsThisModelAPlane(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_PLANE", model); }
	static b8 IsThisModelATrain(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_TRAIN", model); }
	static b8 IsThisModelAVehicle(eModel model) { return Native::Function::Invoke<b8>("IS_THIS_MODEL_A_VEHICLE", model); }
	static void MarkModelAsNoLongerNeeded(eModel model) { Native::Function::Invoke<ScriptVoid>("MARK_MODEL_AS_NO_LONGER_NEEDED", model); }

	// Interiors
	static void ActivateInterior(Interior interior, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("ACTIVATE_INTERIOR", interior, unknownTrue); }
	static void GetInteriorAtCoords(f32 x, f32 y, f32 z, Interior *pInterior) { Native::Function::Invoke<ScriptVoid>("GET_INTERIOR_AT_COORDS", x, y, z, pInterior); }
	static void GetInteriorFromCar(Vehicle vehicle, Interior *pInterior) { Native::Function::Invoke<ScriptVoid>("GET_INTERIOR_FROM_CAR", vehicle, pInterior); }
	static void GetInteriorFromChar(Ped ped, Interior *pInterior) { Native::Function::Invoke<ScriptVoid>("GET_INTERIOR_FROM_CHAR", ped, pInterior); }
	static void GetInteriorHeading(Interior interior, f32 *pHeading) { Native::Function::Invoke<ScriptVoid>("GET_INTERIOR_HEADING", interior, pHeading); }
	static void GetOffsetFromInteriorInWorldCoords(Interior interior, f32 x, f32 y, f32 z, f32 *pOffset) { Native::Function::Invoke<ScriptVoid>("GET_OFFSET_FROM_INTERIOR_IN_WORLD_COORDS", interior, x, y, z, pOffset); }
	static void GetRoomKeyFromObject(Object obj, eInteriorRoomKey *pRoomKey) { Native::Function::Invoke<ScriptVoid>("GET_ROOM_KEY_FROM_OBJECT", obj, pRoomKey); }
	static void RequestInteriorModels(eModel model, const ch *interiorName) { Native::Function::Invoke<ScriptVoid>("REQUEST_INTERIOR_MODELS", model, interiorName); }

	// Blips
	static void AddBlipForCar(Vehicle vehicle, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_CAR", vehicle, pBlip); }
	static void AddBlipForChar(Ped ped, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_CHAR", ped, pBlip); }
	static void AddBlipForContact(f32 x, f32 y, f32 z, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_CONTACT", x, y, z, pBlip); }
	static void AddBlipForCoord(f32 x, f32 y, f32 z, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_COORD", x, y, z, pBlip); }
	static void AddBlipForObject(Object obj, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_OBJECT", obj, pBlip); }
	static void AddBlipForPickup(Pickup pickup, Blip *pBlip) { Native::Function::Invoke<ScriptVoid>("ADD_BLIP_FOR_PICKUP", pickup, pBlip); }
	static void AddSimpleBlipForPickup(Pickup pickup) { Native::Function::Invoke<ScriptVoid>("ADD_SIMPLE_BLIP_FOR_PICKUP", pickup); }
	static void ChangeBlipAlpha(Blip blip, f32 alpha) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_ALPHA", blip, alpha); }
	static void ChangeBlipColour(Blip blip, ColourIndex colour) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_COLOUR", blip, colour); }
	static void ChangeBlipDisplay(Blip blip, eBlipDisplay display) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_DISPLAY", blip, display); }
	static void ChangeBlipNameFromAscii(Blip blip, const ch *blipName) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_NAME_FROM_ASCII", blip, blipName); }
	static void ChangeBlipNameFromTextFile(Blip blip, const ch *gxtName) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_NAME_FROM_TEXT_FILE", blip, gxtName); }
	static void ChangeBlipPriority(Blip blip, eBlipPriority priority) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_PRIORITY", blip, priority); }
	static void ChangeBlipScale(Blip blip, f32 scale) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_SCALE", blip, scale); }
	static void ChangeBlipSprite(Blip blip, eBlipSprite sprite) { Native::Function::Invoke<ScriptVoid>("CHANGE_BLIP_SPRITE", blip, sprite); }
	static void DimBlip(Blip blip, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("DIM_BLIP", blip, unknownTrue); }
	static b8 DoesBlipExist(Blip blip) { return Native::Function::Invoke<b8>("DOES_BLIP_EXIST", blip); }
	static void FlashBlip(Blip blip, b8 on) { Native::Function::Invoke<ScriptVoid>("FLASH_BLIP", blip, on); }
	static void FlashBlipAlt(Blip blip, b8 on) { Native::Function::Invoke<ScriptVoid>("FLASH_BLIP_ALT", blip, on); }
	static void GetBlipColour(Blip blip, ColourIndex *pColour) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COLOUR", blip, pColour); }
	static void GetBlipCoords(Blip blip, Vector3 *pVector) { Native::Function::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pVector); }
	static eBlipType GetBlipInfoIdType(Blip blip) { return Native::Function::Invoke<eBlipType>("GET_BLIP_INFO_ID_TYPE", blip); }
	static Vehicle GetBlipInfoIdCarIndex(Blip blip) { return Native::Function::Invoke<Vehicle>("GET_BLIP_INFO_ID_CAR_INDEX", blip); }
	static b8 GetBlipInfoIdDisplay(Blip blip) { return Native::Function::Invoke<b8>("GET_BLIP_INFO_ID_DISPLAY", blip); }
	static Object GetBlipInfoIdObjectIndex(Blip blip) { return Native::Function::Invoke<Object>("GET_BLIP_INFO_ID_OBJECT_INDEX", blip); }
	static Ped GetBlipInfoIdPedIndex(Blip blip) { return Native::Function::Invoke<Ped>("GET_BLIP_INFO_ID_PED_INDEX", blip); }
	static Pickup GetBlipInfoIdPickupIndex(Blip blip) { return Native::Function::Invoke<Pickup>("GET_BLIP_INFO_ID_PICKUP_INDEX", blip); }
	static const ch *GetBlipName(Blip blip) { return Native::Function::Invoke<const ch *>("GET_BLIP_NAME", blip); }
	static eBlipSprite GetBlipSprite(Blip blip) { return Native::Function::Invoke<eBlipSprite>("GET_BLIP_SPRITE", blip); }
	static Blip GetFirstBlipInfoId(eBlipType type) { return Native::Function::Invoke<Blip>("GET_FIRST_BLIP_INFO_ID", type); }
	static Blip GetNextBlipInfoId(eBlipType type) { return Native::Function::Invoke<Blip>("GET_NEXT_BLIP_INFO_ID", type); }
	static b8 IsBlipShortRange(Blip blip) { return Native::Function::Invoke<b8>("IS_BLIP_SHORT_RANGE", blip); }
	static void RemoveBlip(Blip blip) { Native::Function::Invoke<ScriptVoid>("REMOVE_BLIP", blip); }

	// Pickups
	static void AddPickupToInteriorRoomByName(Pickup pickup, const ch *roomName) { Native::Function::Invoke<ScriptVoid>("ADD_PICKUP_TO_INTERIOR_ROOM_BY_NAME", pickup, roomName); }
	static void CreateMoneyPickup(f32 x, f32 y, f32 z, u32 amount, b8 unknownTrue, Pickup *pPickup) { Native::Function::Invoke<ScriptVoid>("CREATE_MONEY_PICKUP", x, y, z, amount, unknownTrue, pPickup); }
	static void CreatePickup(eModel model, ePickupType pickupType, f32 x, f32 y, f32 z, Pickup *pPickup, b8 unknownFalse) { Native::Function::Invoke<ScriptVoid>("CREATE_PICKUP", model, pickupType, x, y, z, pPickup, unknownFalse); }
	static void CreatePickupRotate(eModel model, ePickupType pickupType, u32 unknown, f32 x, f32 y, f32 z, f32 rX, f32 rY, f32 rZ, Pickup *pPickup) { Native::Function::Invoke<ScriptVoid>("CREATE_PICKUP_ROTATE", model, pickupType, unknown, x, y, z, rX, rY, rZ, pPickup); }
	static void CreatePickupWithAmmo(eModel model, ePickupType pickupType, u32 unknown, f32 x, f32 y, f32 z, Pickup *pPickup) { Native::Function::Invoke<ScriptVoid>("CREATE_PICKUP_WITH_AMMO", model, pickupType, unknown, x, y, z, pPickup); }
	static b8 DoesPickupExist(Pickup pickup) { return Native::Function::Invoke<b8>("DOES_PICKUP_EXIST", pickup); }
	static void GetPickupCoordinates(Pickup pickup, f32 *pX, f32 *pY, f32 *pZ) { Native::Function::Invoke<ScriptVoid>("GET_PICKUP_COORDINATES", pickup, pX, pY, pZ); }
	static b8 HasPickupBeenCollected(Pickup pickup) { return Native::Function::Invoke<b8>("HAS_PICKUP_BEEN_COLLECTED", pickup); }
	static void PickupsPassTime(u32 time) { Native::Function::Invoke<ScriptVoid>("PICKUPS_PASS_TIME", time); }
	static void RemovePickup(Pickup pickup) { Native::Function::Invoke<ScriptVoid>("REMOVE_PICKUP", pickup); }
	static void RemoveTemporaryRadarBlipsForPickups() { Native::Function::Invoke<ScriptVoid>("REMOVE_TEMPORARY_RADAR_BLIPS_FOR_PICKUPS"); }

	// World
	static void ClearArea(f32 x, f32 y, f32 z, f32 radius, b8 unknown) { Native::Function::Invoke<ScriptVoid>("CLEAR_AREA", x, y, z, radius, unknown); }
	static void ClearAreaOfCars(f32 x, f32 y, f32 z, f32 radius) { Native::Function::Invoke<ScriptVoid>("CLEAR_AREA_OF_CARS", x, y, z, radius); }
	static void ClearAreaOfChars(f32 x, f32 y, f32 z, f32 radius) { Native::Function::Invoke<ScriptVoid>("CLEAR_AREA_OF_CHARS", x, y, z, radius); }
	static void ClearAreaOfCops(f32 x, f32 y, f32 z, f32 radius) { Native::Function::Invoke<ScriptVoid>("CLEAR_AREA_OF_COPS", x, y, z, radius); }
	static void ClearAreaOfObjects(f32 x, f32 y, f32 z, f32 radius) { Native::Function::Invoke<ScriptVoid>("CLEAR_AREA_OF_OBJECTS", x, y, z, radius); }
	static void ClearPedNonCreationArea() { Native::Function::Invoke<ScriptVoid>("CLEAR_PED_NON_CREATION_AREA"); }
	static void ClearPedNonRemovalArea() { Native::Function::Invoke<ScriptVoid>("CLEAR_PED_NON_REMOVAL_AREA"); }
	static void ExtinguishFireAtPoint(f32 x, f32 y, f32 z, f32 radius) { Native::Function::Invoke<ScriptVoid>("EXTINGUISH_FIRE_AT_POINT", x, y, z, radius); }
	static void ForceTimeOfDay(u32 hour, u32 minute) { Native::Function::Invoke<ScriptVoid>("FORCE_TIME_OF_DAY", hour, minute); }
	static void ForceWeather(eWeather weather) { Native::Function::Invoke<ScriptVoid>("FORCE_WEATHER", weather); }
	static void ForceWeatherNow(eWeather weather) { Native::Function::Invoke<ScriptVoid>("FORCE_WEATHER_NOW", weather); }
	static void ForceWind(f32 wind) { Native::Function::Invoke<ScriptVoid>("FORCE_WIND", wind); }
	static void ForwardToTimeOfDay(u32 hour, u32 minute) { Native::Function::Invoke<ScriptVoid>("FORWARD_TO_TIME_OF_DAY", hour, minute); }
	static void FreezePositionOfClosestObjectOfType(f32 x, f32 y, f32 z, f32 radius, eModel model, b8 frozen) { Native::Function::Invoke<ScriptVoid>("FREEZE_POSITION_OF_CLOSEST_OBJECT_OF_TYPE", x, y, z, radius, model, frozen); }
	static Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, b8 unknownFalse, u32 unknown70) { return Native::Function::Invoke<Vehicle>("GET_CLOSEST_CAR", x, y, z, radius, unknownFalse, unknown70); }
	static b8 GetClosestChar(f32 x, f32 y, f32 z, f32 radius, b8 unknown1, b8 unknown2, Ped *pPed) { return Native::Function::Invoke<b8>("GET_CLOSEST_CHAR", x, y, z, radius, unknown1, unknown2, pPed); }
	static void GetCurrentWeather(eWeather *pWeather) { Native::Function::Invoke<ScriptVoid>("GET_CURRENT_WEATHER", pWeather); }
	static ScriptAny GetGroundZFor3DCoord(f32 x, f32 y, f32 z, f32 *pGroundZ) { return Native::Function::Invoke<ScriptAny>("GET_GROUND_Z_FOR_3D_COORD", x, y, z, pGroundZ); }
	static u32 GetNumberOfFiresInRange(f32 x, f32 y, f32 z, f32 radius) { return Native::Function::Invoke<u32>("GET_NUMBER_OF_FIRES_IN_RANGE", x, y, z, radius); }
	static void GetSafePickupCoords(f32 x, f32 y, f32 z, f32 *pSafeX, f32 *pSafeY, f32 *pSafeZ) { Native::Function::Invoke<ScriptVoid>("GET_SAFE_PICKUP_COORDS", x, y, z, pSafeX, pSafeY, pSafeZ); }
	static b8 GetSafePositionForChar(f32 x, f32 y, f32 z, b8 unknownTrue, f32 *pSafeX, f32 *pSafeY, f32 *pSafeZ) { return Native::Function::Invoke<b8>("GET_SAFE_POSITION_FOR_CHAR", x, y, z, unknownTrue, pSafeX, pSafeY, pSafeZ); }
	static b8 HasClosestObjectOfTypeBeenDamagedByChar(f32 x, f32 y, f32 z, f32 radius, eModel objectModel, Ped ped) { return Native::Function::Invoke<b8>("HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_DAMAGED_BY_CHAR", x, y, z, radius, objectModel, ped); }
	static b8 IsAreaOccupied(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknownFalse1, b8 unknownTrue, b8 unknownFalse2, b8 unknownFalse3, b8 unknownFalse4) { return Native::Function::Invoke<b8>("IS_AREA_OCCUPIED", x1, y1, z1, x2, y2, z2, unknownFalse1, unknownTrue, unknownFalse2, unknownFalse3, unknownFalse4); }
	static b8 IsBulletInArea(f32 x, f32 y, f32 z, f32 radius, b8 unknownTrue) { return Native::Function::Invoke<b8>("IS_BULLET_IN_AREA", x, y, z, radius, unknownTrue); }
	static b8 IsBulletInBox(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknown) { return Native::Function::Invoke<b8>("IS_BULLET_IN_BOX", x1, y1, z1, x2, y2, z2, unknown); }
	static void RemoveAllPickupsOfType(ePickupType type) { Native::Function::Invoke<ScriptVoid>("REMOVE_ALL_PICKUPS_OF_TYPE", type); }
	static void SwitchAmbientPlanes(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_AMBIENT_PLANES", on); }	
	static void SwitchArrowAboveBlippedPickups(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_ARROW_ABOVE_BLIPPED_PICKUPS", on); }
	static void SwitchRandomBoats(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_RANDOM_BOATS", on); }
	static void SwitchRandomTrains(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_RANDOM_TRAINS", on); }
	static void SwitchGarbageTrucks(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_GARBAGE_TRUCKS", on); }
	static void SwitchMadDrivers(b8 on) { Native::Function::Invoke<ScriptVoid>("SWITCH_MAD_DRIVERS", on); }

	// Garages
	static void CloseGarage(const ch *garageName) { Native::Function::Invoke<ScriptVoid>("CLOSE_GARAGE", garageName); }
	static b8 IsCarInGarageArea(const ch *garageName, Vehicle vehicle) { return Native::Function::Invoke<b8>("IS_CAR_IN_GARAGE_AREA", garageName, vehicle); }
	static b8 IsGarageClosed(const ch *garageName) { return Native::Function::Invoke<b8>("IS_GARAGE_CLOSED", garageName); }
	static b8 IsGarageOpen(const ch *garageName) { return Native::Function::Invoke<b8>("IS_GARAGE_OPEN", garageName); }
	static void OpenGarage(const ch *name) { Native::Function::Invoke<ScriptVoid>("OPEN_GARAGE", name); }

	// Text (GXT stuff)
	static void DisplayText(f32 x, f32 y, const ch *gxtName) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT", x, y, gxtName); }
	static void DisplayTextWith2Numbers(f32 x, f32 y, const ch *gxtName, i32 number1, i32 number2) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_2_NUMBERS", x, y, gxtName, number1, number2); }
	static void DisplayTextWithFloat(f32 x, f32 y, const ch *gxtName, f32 value, u32 unknown) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_FLOAT", x, y, gxtName, value, unknown); }
	static void DisplayTextWithLiteralString(f32 x, f32 y, const ch *gxtName, const ch *literalStr) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_LITERAL_STRING", x, y, gxtName, literalStr); }
	static void DisplayTextWithNumber(f32 x, f32 y, const ch *gxtName, i32 value) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_NUMBER", x, y, gxtName, value); }
	static void DisplayTextWithString(f32 x, f32 y, const ch *gxtName, const ch *gxtStringName) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_STRING", x, y, gxtName, gxtStringName); }
	static void DisplayTextWithTwoLiteralStrings(f32 x, f32 y, const ch *gxtName, const ch *literalStr1, const ch *literalStr2) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_TWO_LITERAL_STRINGS", x, y, gxtName, literalStr1, literalStr2); }
	static void DisplayTextWithTwoStrings(f32 x, f32 y, const ch *gxtName, const ch *gxtStringName1, const ch *gxtStringName2) { Native::Function::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_TWO_STRINGS", x, y, gxtName, gxtStringName1, gxtStringName2); }
	static u32 GetLengthOfStringWithThisTextLabel(const ch *gxtName) { return Native::Function::Invoke<u32>("GET_LENGTH_OF_STRING_WITH_THIS_TEXT_LABEL", gxtName); }
	static const ch *GetFirstNCharactersOfString(const ch *gxtName, u32 chars) { return Native::Function::Invoke<const ch *>("GET_FIRST_N_CHARACTERS_OF_STRING", gxtName, chars); }
	static const ch *GetNthIntegerInString(const ch *gxtName, u32 index) { return Native::Function::Invoke<const ch *>("GET_NTH_INTEGER_IN_STRING", gxtName, index); }
	static const ch *GetStringFromHashKey(u32 hashKey) { return Native::Function::Invoke<const ch *>("GET_STRING_FROM_HASH_KEY", hashKey); }
	static b8 HasAdditionalTextLoaded(u32 textIndex) { return Native::Function::Invoke<b8>("HAS_ADDITIONAL_TEXT_LOADED", textIndex); }
	static b8 HasThisAdditionalTextLoaded(const ch *textName, u32 textIndex) { return Native::Function::Invoke<b8>("HAS_THIS_ADDITIONAL_TEXT_LOADED", textName, textIndex); }
	static b8 IsStreamingAdditionalText(u32 textIndex) { return Native::Function::Invoke<b8>("IS_STREAMING_ADDITIONAL_TEXT", textIndex); }
	static void LoadAdditionalText(const ch *textName, u32 textIndex) { Native::Function::Invoke<ScriptVoid>("LOAD_ADDITIONAL_TEXT", textName, textIndex); }
	static void LoadTextFont(eTextFont font) { Native::Function::Invoke<ScriptVoid>("LOAD_TEXT_FONT", font); }
	static void RequestAdditionalText(const ch *textName, u32 textIndex) { Native::Function::Invoke<ScriptVoid>("REQUEST_ADDITIONAL_TEXT", textName, textIndex); }

	// Textures
	static Texture GetTexture(TextureDict dictionary, const ch *textureName) { return Native::Function::Invoke<Texture>("GET_TEXTURE", dictionary, textureName); }
	static Texture GetTextureFromStreamedTxd(const ch *txdName, const ch *textureName) { return Native::Function::Invoke<Texture>("GET_TEXTURE_FROM_STREAMED_TXD", txdName, textureName); }
	static TextureDict GetTxd(const ch *txdName) { return Native::Function::Invoke<TextureDict>("GET_TXD", txdName); }
	static b8 HasStreamedTxdLoaded(const ch *txdName) { return Native::Function::Invoke<b8>("HAS_STREAMED_TXD_LOADED", txdName); }
	static TextureDict LoadTxd(const ch *txdName) { return Native::Function::Invoke<TextureDict>("LOAD_TXD", txdName); }
	static void MarkStreamedTxdAsNoLongerNeeded(const ch *txdName) { Native::Function::Invoke<ScriptVoid>("MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED", txdName); }
	static void ReleaseTexture(Texture texture) { Native::Function::Invoke<ScriptVoid>("RELEASE_TEXTURE", texture); }
	static void RequestStreamedTxd(const ch *txdName, b8 unknown) { Native::Function::Invoke<ScriptVoid>("REQUEST_STREAMED_TXD", txdName, unknown); }
	static void RemoveTxd(TextureDict txd) { Native::Function::Invoke<ScriptVoid>("REMOVE_TXD", txd); }

	// Stats
	static void DecrementIntStat(eIntStatistic stat, u32 amount) { Native::Function::Invoke<ScriptVoid>("DECREMENT_INT_STAT", stat, amount); }
	static u32 GetIntStat(eIntStatistic stat) { return Native::Function::Invoke<u32>("GET_INT_STAT", stat); }
	static void IncrementFloatStatNoMessage(eFloatStatistic stat, f32 value) { Native::Function::Invoke<ScriptVoid>("INCREMENT_FLOAT_STAT_NO_MESSAGE", stat, value); }
	static void IncrementIntStat(eIntStatistic stat, u32 value) { Native::Function::Invoke<ScriptVoid>("INCREMENT_INT_STAT", stat, value); }
	static void IncrementIntStatNoMessage(eIntStatistic stat, u32 value) { Native::Function::Invoke<ScriptVoid>("INCREMENT_INT_STAT_NO_MESSAGE", stat, value); }
	static void SetIntStat(eIntStatistic stat, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_INT_STAT", stat, value); }

	// Pad (controls)
	static b8 GetPadPitchRoll(u32 padIndex, f32 *pPitch, f32 *pRoll) { return Native::Function::Invoke<b8>("GET_PAD_PITCH_ROLL", padIndex, pPitch, pRoll); }
	static void GetPositionOfAnalogueSticks(u32 padIndex, u32 *pLeftX, u32 *pLeftY, u32 *pRightX, u32 *pRightY) { Native::Function::Invoke<ScriptVoid>("GET_POSITION_OF_ANALOGUE_STICKS", padIndex, pLeftX, pLeftY, pRightX, pRightY); }
	static b8 IsButtonJustPressed(u32 padIndex, ePadButton button) { return Native::Function::Invoke<b8>("IS_BUTTON_JUST_PRESSED", padIndex, button); }
	static b8 IsButtonPressed(u32 padIndex, ePadButton button) { return Native::Function::Invoke<b8>("IS_BUTTON_PRESSED", padIndex, button); }

	// Sound
	static eSound GetSoundId() { return Native::Function::Invoke<eSound>("GET_SOUND_ID"); }
	static b8 HasSoundFinished(eSound sound) { return Native::Function::Invoke<b8>("HAS_SOUND_FINISHED", sound); }
	static void StopSound(eSound sound) { Native::Function::Invoke<ScriptVoid>("STOP_SOUND", sound); }

	// Game/Misc
	static void AbortAllGarageActivity() { Native::Function::Invoke<ScriptVoid>("ABORT_ALL_GARAGE_ACTIVITY"); }
	static void ActivateCheat(eCheat cheat) { Native::Function::Invoke<ScriptVoid>("ACTIVATE_CHEAT", cheat); }
	static void ActivateFrontEnd() { Native::Function::Invoke<u32>("ACTIVATE_FRONTEND"); }
	static void ActivateSaveMenu() { Native::Function::Invoke<ScriptVoid>("ACTIVATE_SAVE_MENU"); }
	static void AllowEmergencyServices(b8 allow) { Native::Function::Invoke<ScriptVoid>("ALLOW_EMERGENCY_SERVICES", allow); }
	static void AllowGameToPauseForStreaming(b8 allow) { Native::Function::Invoke<ScriptVoid>("ALLOW_GAME_TO_PAUSE_FOR_STREAMING", allow); }
	static void AllowStuntJumpsToTrigger(b8 allow) { Native::Function::Invoke<ScriptVoid>("ALLOW_STUNT_JUMPS_TO_TRIGGER", allow); }
	static b8 AreWidescreenBordersActive() { return Native::Function::Invoke<b8>("ARE_WIDESCREEN_BORDERS_ACTIVE"); }
	static ScriptAny AwardAchievement(eAchievement achievement) { return Native::Function::Invoke<ScriptAny>("AWARD_ACHIEVEMENT", achievement); }
	static b8 CanPhoneBeSeenOnScreen() { return Native::Function::Invoke<b8>("CAN_PHONE_BE_SEEN_ON_SCREEN"); }
	static void CancelOverrideRestart() { Native::Function::Invoke<ScriptVoid>("CANCEL_OVERRIDE_RESTART"); }
	static void ClearShakePlayerPadWhenControllerDisabled() { Native::Function::Invoke<ScriptVoid>("CLEAR_SHAKE_PLAYERPAD_WHEN_CONTROLLER_DISABLED"); }
	static void ClearTimeCycleModifier() { Native::Function::Invoke<ScriptVoid>("CLEAR_TIMECYCLE_MODIFIER"); }
	static void DeactivateFrontEnd() { Native::Function::Invoke<ScriptVoid>("DEACTIVATE_FRONTEND"); }
	static b8 DidSaveCompleteSuccessfully() { return Native::Function::Invoke<b8>("DID_SAVE_COMPLETE_SUCCESSFULLY"); }
	static void DisableFrontEndRadio() { Native::Function::Invoke<ScriptVoid>("DISABLE_FRONTEND_RADIO"); }
	static void DisablePauseMenu(b8 disabled) { Native::Function::Invoke<ScriptVoid>("DISABLE_PAUSE_MENU", disabled); }
	static void DisablePoliceScanner() { Native::Function::Invoke<ScriptVoid>("DISABLE_POLICE_SCANNER"); }
	static void DisplayAmmo(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_AMMO", display); }
	static void DisplayAreaName(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_AREA_NAME", display); }
	static void DisplayCash(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_CASH", display); }
	static void DisplayFrontEndMapBlips(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_FRONTEND_MAP_BLIPS", display); }
	static void DisplayHUD(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_HUD", display); }
	static void DisplayRadar(b8 display) { Native::Function::Invoke<ScriptVoid>("DISPLAY_RADAR", display); }
	static void DisplaySniperScopeThisFrame() { Native::Function::Invoke<ScriptVoid>("DISPLAY_SNIPER_SCOPE_THIS_FRAME"); }
	static void DoAutoSave() { Native::Function::Invoke<ScriptVoid>("DO_AUTO_SAVE"); }
	static void DoScreenFadeIn(u32 timeMS) { Native::Function::Invoke<ScriptVoid>("DO_SCREEN_FADE_IN", timeMS); }
	static void DoScreenFadeInUnhacked(u32 timeMS) { Native::Function::Invoke<ScriptVoid>("DO_SCREEN_FADE_IN_UNHACKED", timeMS); }
	static void DoScreenFadeOut(u32 timeMS) { Native::Function::Invoke<ScriptVoid>("DO_SCREEN_FADE_OUT", timeMS); }
	static void DoScreenFadeOutUnhacked(u32 timeMS) { Native::Function::Invoke<ScriptVoid>("DO_SCREEN_FADE_OUT_UNHACKED", timeMS); }
	static void EnableFrontEndRadio() { Native::Function::Invoke<ScriptVoid>("ENABLE_FRONTEND_RADIO"); }
	static void EnableMaxAmmoCap(b8 enable) { Native::Function::Invoke<ScriptVoid>("ENABLE_MAX_AMMO_CAP", enable); }
	static void EnablePoliceScanner() { Native::Function::Invoke<ScriptVoid>("ENABLE_POLICE_SCANNER"); }
	static void EnableSceneStreaming(b8 enable) { Native::Function::Invoke<ScriptVoid>("ENABLE_SCENE_STREAMING", enable); }
	static void FakeDeathArrest() { Native::Function::Invoke<ScriptVoid>("FAKE_DEATHARREST"); }
	static void FireSingleBullet(f32 x, f32 y, f32 z, f32 targetX, f32 targetY, f32 targetZ, u32 unknown) { Native::Function::Invoke<ScriptVoid>("FIRE_SINGLE_BULLET", x, y, z, targetX, targetY, targetZ, unknown); }
	static void FlashWeaponIcon(b8 on) { Native::Function::Invoke<ScriptVoid>("FLASH_WEAPON_ICON", on); }
	static void ForceInitialPlayerStation(const ch *stationName) { Native::Function::Invoke<ScriptVoid>("FORCE_INITIAL_PLAYER_STATION", stationName); }
	static void ForceLoadingScreen(b8 force) { Native::Function::Invoke<ScriptVoid>("FORCE_LOADING_SCREEN", force); }
	static void FreezeRadioStation(const ch *stationName) { Native::Function::Invoke<ScriptVoid>("FREEZE_RADIO_STATION", stationName); }
	static void GetCorrectedColour(u32 r, u32 g, u32 b, u32 *pR, u32 *pG, u32 *pB) { Native::Function::Invoke<ScriptVoid>("GET_CORRECTED_COLOUR", r, g, b, pR, pG, pB); }
	static b8 GetCreateRandomCops() { return Native::Function::Invoke<b8>("GET_CREATE_RANDOM_COPS"); }
	static u32 GetCurrentDayOfWeek() { return Native::Function::Invoke<u32>("GET_CURRENT_DAY_OF_WEEK"); }
	static u32 GetCurrentEpisode() { return Native::Function::Invoke<u32>("GET_CURRENT_EPISODE"); }
	static eLanguage GetCurrentLanguage() { return Native::Function::Invoke<eLanguage>("GET_CURRENT_LANGUAGE"); }
	static u32 GetEpisodeIndexFromSummons() { return Native::Function::Invoke<ScriptAny>("GET_EPISODE_INDEX_FROM_SUMMONS"); }
	static void GetGameTimer(u32 *pTimer) { Native::Function::Invoke<ScriptVoid>("GET_GAME_TIMER", pTimer); }
	static u32 GetHashKey(const ch *value) { return Native::Function::Invoke<ScriptAny>("GET_HASH_KEY", value); }
	static u32 GetHoursOfDay() { return Native::Function::Invoke<u32>("GET_HOURS_OF_DAY"); }
	static void GetHUDColour(eHUDType type, u32 *pR, u32 *pG, u32 *pB, ScriptAny *pUnknown) { Native::Function::Invoke<ScriptVoid>("GET_HUD_COLOUR", type, pR, pG, pB, pUnknown); }
	static u32 GetIdOfThisThread() { return Native::Function::Invoke<u32>("GET_ID_OF_THIS_THREAD"); }
	static b8 GetIsDepositAnimRunning() { return Native::Function::Invoke<b8>("GET_IS_DEPOSIT_ANIM_RUNNING"); }
	static b8 GetIsHiDef() { return Native::Function::Invoke<b8>("GET_IS_HIDEF"); }
	static b8 GetIsWidescreen() { return Native::Function::Invoke<b8>("GET_IS_WIDESCREEN"); }
	static eMapArea GetMapAreaFromCoords(f32 x, f32 y, f32 z) { return Native::Function::Invoke<eMapArea>("GET_MAP_AREA_FROM_COORDS", x, y, z); }
	static u32 GetMinutesOfDay() { return Native::Function::Invoke<u32>("GET_MINUTES_OF_DAY"); }
	static u32 GetMinutesToTimeOfDay(u32 hour, u32 minute) { return Native::Function::Invoke<u32>("GET_MINUTES_TO_TIME_OF_DAY", hour, minute); }
	static b8 GetMissionFlag() { return Native::Function::Invoke<b8>("GET_MISSION_FLAG"); }
	static void GetMaxWantedLevel(u32 *pMaxWantedLevel) { Native::Function::Invoke<ScriptVoid>("GET_MAX_WANTED_LEVEL", pMaxWantedLevel); }
	static const ch *GetNameOfInfoZone(f32 x, f32 y, f32 z) { return Native::Function::Invoke<const ch *>("GET_NAME_OF_INFO_ZONE", x, y, z); }
	static const ch *GetNameOfZone(f32 x, f32 y, f32 z) { return Native::Function::Invoke<const ch *>("GET_NAME_OF_ZONE", x, y, z); }
	static u32 GetNumStreamingRequests() { return Native::Function::Invoke<u32>("GET_NUM_STREAMING_REQUESTS"); }
	static u32 GetNumberOfInstancesOfStreamedScript(const ch *scriptName) { return Native::Function::Invoke<u32>("GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT", scriptName); }
	static eRadioStation GetPlayerRadioStationIndex() { return Native::Function::Invoke<eRadioStation>("GET_PLAYER_RADIO_STATION_INDEX"); }
	static const ch *GetPlayerRadioStationName() { return Native::Function::Invoke<const ch *>("GET_PLAYER_RADIO_STATION_NAME"); }
	static u32 GetTimeSinceLastArrest() { return Native::Function::Invoke<u32>("GET_TIME_SINCE_LAST_ARREST"); }
	static u32 GetTimeSinceLastDeath() { return Native::Function::Invoke<u32>("GET_TIME_SINCE_LAST_DEATH"); }
	static b8 HasAchievementBeenPassed(eAchievement achievement) { return Native::Function::Invoke<b8>("HAS_ACHIEVEMENT_BEEN_PASSED", achievement); }
	static b8 HasDeathArrestExecuted() { return Native::Function::Invoke<b8>("HAS_DEATHARREST_EXECUTED"); }
	static b8 HasResprayHappened() { return Native::Function::Invoke<b8>("HAS_RESPRAY_HAPPENED"); }
	static b8 HasScriptLoaded(const ch *scriptName) { return Native::Function::Invoke<b8>("HAS_SCRIPT_LOADED", scriptName); }
	static b8 HaveAnimsLoaded(const ch *animName) { return Native::Function::Invoke<b8>("HAVE_ANIMS_LOADED", animName); }
	static void HideHelpTextThisFrame() { Native::Function::Invoke<ScriptVoid>("HIDE_HELP_TEXT_THIS_FRAME"); }
	static void HideHUDAndRadarThisFrame() { Native::Function::Invoke<ScriptVoid>("HIDE_HUD_AND_RADAR_THIS_FRAME"); }
	static b8 IsAussieVersion() { return Native::Function::Invoke<b8>("IS_AUSSIE_VERSION"); }
	static b8 IsAutoAimingOn() { return Native::Function::Invoke<b8>("IS_AUTO_AIMING_ON"); }
	static b8 IsAutoSaveInProgress() { return Native::Function::Invoke<b8>("IS_AUTO_SAVE_IN_PROGRESS"); }
	static b8 IsInteriorScene() { return Native::Function::Invoke<b8>("IS_INTERIOR_SCENE"); }
	static b8 IsFrontEndFading() { return Native::Function::Invoke<b8>("IS_FRONTEND_FADING"); }
	static b8 IsGameInControlOfMusic() { return Native::Function::Invoke<b8>("IS_GAME_IN_CONTROL_OF_MUSIC"); }
	static b8 IsGermanVersion() { return Native::Function::Invoke<b8>("IS_GERMAN_VERSION"); }
	static b8 IsHelpMessageBeingDisplayed() { return Native::Function::Invoke<b8>("IS_HELP_MESSAGE_BEING_DISPLAYED"); }
	static b8 IsHintRunning() { return Native::Function::Invoke<b8>("IS_HINT_RUNNING"); }
	static b8 IsHUDPreferenceSwitchedOn() { return Native::Function::Invoke<b8>("IS_HUD_PREFERENCE_SWITCHED_ON"); }
	static b8 IsHUDReticuleComplex() { return Native::Function::Invoke<b8>("IS_HUD_RETICULE_COMPLEX"); }
	static b8 IsInSpectatorMode() { return Native::Function::Invoke<b8>("IS_IN_SPECTATOR_MODE"); }
	static b8 IsLookInverted() { return Native::Function::Invoke<b8>("IS_LOOK_INVERTED"); }
	static b8 IsMemoryCardInUse() { return Native::Function::Invoke<b8>("IS_MEMORY_CARD_IN_USE"); }
	static b8 IsMessageBeingDisplayed() { return Native::Function::Invoke<b8>("IS_MESSAGE_BEING_DISPLAYED"); }
	static b8 IsMinigameInProgress() { return Native::Function::Invoke<b8>("IS_MINIGAME_IN_PROGRESS"); }
	static b8 IsMissionCompletePlaying() { return Native::Function::Invoke<b8>("IS_MISSION_COMPLETE_PLAYING"); }
	static b8 IsMobilePhoneCallOngoing() { return Native::Function::Invoke<b8>("IS_MOBILE_PHONE_CALL_ONGOING"); }
	static b8 IsMobilePhoneRadioActive() { return Native::Function::Invoke<b8>("IS_MOBILE_PHONE_RADIO_ACTIVE"); }
	static b8 IsPauseMenuActive() { return Native::Function::Invoke<b8>("IS_PAUSE_MENU_ACTIVE"); }
	static b8 IsPayNSprayActive() { return Native::Function::Invoke<b8>("IS_PAY_N_SPRAY_ACTIVE"); }
	static b8 IsPlayerBeingArrested() { return Native::Function::Invoke<b8>("IS_PLAYER_BEING_ARRESTED"); }
	static b8 IsRadioRetuning() { return Native::Function::Invoke<b8>("IS_RADIO_RETUNING"); }
	static b8 IsScreenFadedIn() { return Native::Function::Invoke<b8>("IS_SCREEN_FADED_IN"); }
	static b8 IsScreenFadedOut() { return Native::Function::Invoke<b8>("IS_SCREEN_FADED_OUT"); }
	static b8 IsScreenFading() { return Native::Function::Invoke<b8>("IS_SCREEN_FADING"); }
	static b8 IsScreenFadingIn() { return Native::Function::Invoke<b8>("IS_SCREEN_FADING_IN"); }
	static b8 IsScreenFadingOut() { return Native::Function::Invoke<b8>("IS_SCREEN_FADING_OUT"); }
	static b8 IsSniperInverted() { return Native::Function::Invoke<b8>("IS_SNIPER_INVERTED"); }
	static b8 IsSystemUIShowing() { return Native::Function::Invoke<b8>("IS_SYSTEM_UI_SHOWING"); }
	static b8 IsThisAMinigameScript() { return Native::Function::Invoke<b8>("IS_THIS_A_MINIGAME_SCRIPT"); }
	static b8 IsThreadActive(u32 threadId) { return Native::Function::Invoke<b8>("IS_THREAD_ACTIVE", threadId); }
	static void MarkScriptAsNoLongerNeeded(const ch *scriptName) { Native::Function::Invoke<ScriptVoid>("MARK_SCRIPT_AS_NO_LONGER_NEEDED", scriptName); }
	static void PauseGame() { Native::Function::Invoke<ScriptVoid>("PAUSE_GAME"); }
	static void PlayMovie() { Native::Function::Invoke<ScriptVoid>("PLAY_MOVIE"); }
	static void PopulateNow() { Native::Function::Invoke<ScriptVoid>("POPULATE_NOW"); }
	static void RequestAnims(const ch *animName) { Native::Function::Invoke<ScriptVoid>("REQUEST_ANIMS", animName); }
	static void ReleaseMovie() { Native::Function::Invoke<ScriptVoid>("RELEASE_MOVIE"); }
	static void ReleaseTimeOfDay() { Native::Function::Invoke<ScriptVoid>("RELEASE_TIME_OF_DAY"); }
	static void ReleaseWeather() { Native::Function::Invoke<ScriptVoid>("RELEASE_WEATHER"); }
	static void RemoveAnims(const ch *animName) { Native::Function::Invoke<ScriptVoid>("REMOVE_ANIMS", animName); }
	static void RemoveCoverPoint(CoverPoint coverPoint) { Native::Function::Invoke<ScriptVoid>("REMOVE_COVER_POINT", coverPoint); }
	static void RemoveIpl(const ch *iplName) { Native::Function::Invoke<ScriptVoid>("REMOVE_IPL", iplName); }
	static void RemoveScriptFire(Fire fire) { Native::Function::Invoke<ScriptVoid>("REMOVE_SCRIPT_FIRE", fire); }
	static void RequestIpl(const ch *iplName) { Native::Function::Invoke<ScriptVoid>("REQUEST_IPL", iplName); }
	static void SetTimerA(u32 value) { Native::Function::Invoke<ScriptVoid>("SETTIMERA", value); }
	static void SetTimerB(u32 value) { Native::Function::Invoke<ScriptVoid>("SETTIMERB", value); }
	//static void TerminateThisScript() { Native::Function::Invoke<ScriptVoid>("TERMINATE_THIS_SCRIPT"); }	// Don't use this from a NativeThread (NativeFiberThread overrides this function)
	static u32 TimerA() { return Native::Function::Invoke<u32>("TIMERA"); }
	static u32 TimerB() { return Native::Function::Invoke<u32>("TIMERB"); }
	static u32 TimeStep() { return Native::Function::Invoke<u32>("TIMESTEP"); }
	static void UnlockLazlowStation() { Native::Function::Invoke<ScriptVoid>("UNLOCK_LAZLOW_STATION"); }
	static void UnregisterScriptWithAudio() { Native::Function::Invoke<ScriptVoid>("UNREGISTER_SCRIPT_WITH_AUDIO"); }
	static void UnPauseGame() { Native::Function::Invoke<ScriptVoid>("UNPAUSE_GAME"); }
	//static void Wait(u32 timeInMs) { Native::Function::Invoke<ScriptVoid>("WAIT", timeInMs); }	// Don't use this from a NativeThread (NativeFiberThread overrides this function)

	// General
	static f32 AbsF(f32 value) { return Native::Function::Invoke<f32>("ABSF", value); }		// Prefer using function from <math.h> instead for performance
	static f32 AbsI(f32 value) { return Native::Function::Invoke<f32>("ABSI", value); }		// Prefer using function from <math.h> instead for performance
	static f32 ASin(f32 value) { return Native::Function::Invoke<f32>("ASIN", value); }		// Prefer using function from <math.h> instead for performance
	static f32 ATan(f32 value) { return Native::Function::Invoke<f32>("ATAN", value); }		// Prefer using function from <math.h> instead for performance
	static i32 Ceil(f32 value) { return Native::Function::Invoke<i32>("CEIL", value); }		// Prefer using function from <math.h> instead for performance
	static f32 Cos(f32 value) { return Native::Function::Invoke<f32>("COS", value); }		// Prefer using function from <math.h> instead for performance
	static f32 ToFloat(u32 value) { return Native::Function::Invoke<f32>("TO_FLOAT", value); }	// Prefer casting instead for performance
	static u32 Floor(f32 value) { return Native::Function::Invoke<u32>("FLOOR", value); }		// Prefer using function from <math.h> instead for performance
	static void GenerateRandomFloatInRange(f32 min, f32 max, f32 *pValue) { Native::Function::Invoke<ScriptVoid>("GENERATE_RANDOM_FLOAT_IN_RANGE", min, max, pValue); }
	static void GenerateRandomIntInRange(u32 min, u32 max, u32 *pValue) { Native::Function::Invoke<ScriptVoid>("GENERATE_RANDOM_INT_IN_RANGE", min, max, pValue); }
	static void GetAngleBetween2DVectors(f32 x1, f32 y1, f32 x2, f32 y2, f32 *pResult) { Native::Function::Invoke<ScriptVoid>("GET_ANGLE_BETWEEN_2D_VECTORS", x1, y1, x2, y2, pResult); }
	static void GetDistanceBetweenCoords2D(f32 x1, f32 y1, f32 x2, f32 y2, f32 *pDist) { Native::Function::Invoke<ScriptVoid>("GET_DISTANCE_BETWEEN_COORDS_2D", x1, y1, x2, y2, pDist); }
	static void GetDistanceBetweenCoords3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 *pDist) { Native::Function::Invoke<ScriptVoid>("GET_DISTANCE_BETWEEN_COORDS_3D", x1, y1, z1, x2, y2, z2, pDist); }
	static const ch *GetFirstNCharactersOfLiteralString(const ch *literalString, u32 chars) { return Native::Function::Invoke<const ch *>("GET_FIRST_N_CHARACTERS_OF_LITERAL_STRING", literalString, chars); }
	static void GetHeadingFromVector2D(f32 x, f32 y, f32 *pHeading) { Native::Function::Invoke<ScriptVoid>("GET_HEADING_FROM_VECTOR_2D", x, y, pHeading); }
	static u32 GetLengthOfLiteralString(const ch *literalString) { return Native::Function::Invoke<u32>("GET_LENGTH_OF_LITERAL_STRING", literalString); }
	static b8 IsStringNull(const ch *str) { return Native::Function::Invoke<b8>("IS_STRING_NULL", str); }
	static f32 Sin(f32 value) { return Native::Function::Invoke<f32>("SIN", value); }		// Prefer using function from <math.h> instead for performance
	static f32 Sqrt(f32 value) { return Native::Function::Invoke<f32>("SQRT", value); }		// Prefer using function from <math.h> instead for performance
	static f32 Tan(f32 value) { return Native::Function::Invoke<f32>("TAN", value); }		// Prefer using function from <math.h> instead for performance

}
}