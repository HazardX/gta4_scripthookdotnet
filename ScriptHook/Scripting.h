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

#pragma once

#include "NativeInvoke.h"
#include "ScriptingTypes.h"
#include "ScriptingEnums.h"
#include "ScriptingHelpers.h"

namespace Scripting
{
    // These are properly documented functions that were moved from ScriptingDirty.h and cleaned up
    // Beware... not all of them are tested.

    // If you need to add your own functions, add it to a separate file in your own project, not here!
    // This file may be updated very often as new functions are documented.

    // Player
    static void AddScore(Player playerIndex, i32 score) { NativeInvoke::Invoke<ScriptVoid>("ADD_SCORE", playerIndex, score); }
    static void AllowPlayerToCarryNonMissionObjects(Player playerIndex, b8 allow) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_PLAYER_TO_CARRY_NON_MISSION_OBJECTS", playerIndex, allow); }
    static void AlterWantedLevel(Player playerIndex,  u32 level) { NativeInvoke::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL", playerIndex, level); }
    static void AlterWantedLevelNoDrop(Player playerIndex, u32 level) { NativeInvoke::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL_NO_DROP", playerIndex, level); }
    static void ApplyWantedLevelChangeNow(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("APPLY_WANTED_LEVEL_CHANGE_NOW", playerIndex); }
    static void ChangePlayerModel(Player playerIndex, eModel model) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PLAYER_MODEL", playerIndex, model); }
    static void ClearPlayerHasDamagedAtLeastOnePed(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
    static Player ConvertIntToPlayerIndex(u32 playerId) { return NativeInvoke::Invoke<Player>("CONVERT_INT_TO_PLAYERINDEX", playerId); }
    static void ClearWantedLevel(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_WANTED_LEVEL", playerIndex); }
    static void CreatePlayer(u32 playerId, f32 x, f32 y, f32 z, Player *pPlayerIndex) { NativeInvoke::Invoke<ScriptVoid>("CREATE_PLAYER", playerId, x, y, z, pPlayerIndex); }
    static void DisablePlayerLockon(Player playerIndex, b8 disabled) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_PLAYER_LOCKON", playerIndex, disabled); }
    static void DisablePlayerSprint(Player playerIndex, b8 disabled) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_PLAYER_SPRINT", playerIndex, disabled); }
    static void GetPlayerChar(Player playerIndex, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_PLAYER_CHAR", playerIndex, pPed); }
    static void GetPlayerGroup(Player playerIndex, Group *pGroup) { NativeInvoke::Invoke<ScriptVoid>("GET_PLAYER_GROUP", playerIndex, pGroup); }
    static u32 GetPlayerId() { return NativeInvoke::Invoke<u32>("GET_PLAYER_ID"); }
    static void GetPlayersLastCarNoSave(Vehicle* pVehicle) { NativeInvoke::Invoke<ScriptVoid>("GET_PLAYERS_LAST_CAR_NO_SAVE", pVehicle); }
    static void GetPlayerMaxArmour(Player playerIndex, u32 *pMaxArmour) { NativeInvoke::Invoke<ScriptVoid>("GET_PLAYER_MAX_ARMOUR", playerIndex, pMaxArmour); }
    static const ch *GetPlayerName(Player playerIndex) { return NativeInvoke::Invoke<const ch *>("GET_PLAYER_NAME", playerIndex); }
    static eModel GetPlayerSettingsModelChoice() { return NativeInvoke::Invoke<eModel>("GET_PLAYERSETTINGS_MODEL_CHOICE"); }
    static ScriptAny GetPlayerToPlaceBombInCar(Vehicle vehicle) { return NativeInvoke::Invoke<ScriptAny>("GET_PLAYER_TO_PLACE_BOMB_IN_CAR", vehicle); }
    static u32 GetTimeSincePlayerDroveAgainstTraffic(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC", playerIndex); }
    static u32 GetTimeSincePlayerDroveOnPavement(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT", playerIndex); }
    static u32 GetTimeSincePlayerHitBuilding(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_BUILDING", playerIndex); }
    static u32 GetTimeSincePlayerHitCar(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_CAR", playerIndex); }
    static u32 GetTimeSincePlayerHitObject(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_OBJECT", playerIndex); }
    static u32 GetTimeSincePlayerHitPed(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_PED", playerIndex); }
    static u32 GetTimeSincePlayerRanLight(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_RAN_LIGHT", playerIndex); }
    static b8 HasPlayerCollectedPickup(Player playerIndex, Pickup pikcup) { return NativeInvoke::Invoke<b8>("HAS_PLAYER_COLLECTED_PICKUP", playerIndex, pikcup); }
    static b8 HasPlayerDamagedAtLeastOnePed(Player playerIndex) { return NativeInvoke::Invoke<b8>("HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
    static b8 IsPlayerClimbing(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_CLIMBING", playerIndex); }
    static b8 IsPlayerControlOn(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_CONTROL_ON", playerIndex); }
    static b8 IsPlayerDead(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_DEAD", playerIndex); }
    static b8 IsPlayerFreeAimingAtChar(Player playerIndex, Ped ped) { return NativeInvoke::Invoke<b8>("IS_PLAYER_FREE_AIMING_AT_CHAR", playerIndex, ped); }
    static b8 IsPlayerFreeForAmbientTask(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_FREE_FOR_AMBIENT_TASK", playerIndex); }
    static b8 IsPlayerPlaying(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_PLAYING", playerIndex); }
    static b8 IsPlayerPressingHorn(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_PRESSING_HORN", playerIndex); }
    static b8 IsPlayerTargettingAnything(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_ANYTHING", playerIndex); }
    static b8 IsPlayerTargettingChar(Player playerIndex, Ped ped) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_CHAR", playerIndex, ped); }
    static b8 IsPlayerTargettingObject(Player playerIndex, Object obj) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_OBJECT", playerIndex, obj); }
    static b8 IsScoreGreater(Player playerIndex, u32 score) { return NativeInvoke::Invoke<b8>("IS_SCORE_GREATER", playerIndex, score); }
    static b8 IsWantedLevelGreater(Player playerIndex, u32 level) { return NativeInvoke::Invoke<b8>("IS_WANTED_LEVEL_GREATER", playerIndex, level); }
    static b8 PlayerHasChar(Player playerIndex) { return NativeInvoke::Invoke<b8>("PLAYER_HAS_CHAR", playerIndex); }
    static b8 PlayerHasFlashingStarsAboutToDrop(Player playerIndex) { return NativeInvoke::Invoke<b8>("PLAYER_HAS_FLASHING_STARS_ABOUT_TO_DROP", playerIndex); }
    static b8 PlayerHasGreyedOutStars(Player playerIndex) { return NativeInvoke::Invoke<b8>("PLAYER_HAS_GREYED_OUT_STARS", playerIndex); }
    static void RegisterPlayerRespawnCoords(Player playerIndex, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_PLAYER_RESPAWN_COORDS", playerIndex, x, y, z); }
    static void SetEveryoneIgnorePlayer(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_EVERYONE_IGNORE_PLAYER", playerIndex, value); }
    static void SetPlayerCanBeHassledByGangs(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_BE_HASSLED_BY_GANGS", playerIndex, value); }
    static void SetPlayerCanDoDriveBy(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_DO_DRIVE_BY", playerIndex, value); }
    static void SetPlayerCanUseCover(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_USE_COVER", playerIndex, value); }
    static void SetPlayerControl(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL", playerIndex, value); }
    static void SetPlayerControlAdvanced(Player playerIndex, b8 unknown1, b8 unknown2, b8 unknown3) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL_ADVANCED", playerIndex, unknown1, unknown2, unknown3); }
    static void SetPlayerFastReload(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_FAST_RELOAD", playerIndex, value); }
    static void SetPlayerGroupToFollowAlways(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_GROUP_TO_FOLLOW_ALWAYS", playerIndex, value); }
    static void SetPlayerInvincible(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_INVINCIBLE", playerIndex, value); }
    static void SetPlayerMoodNormal(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_MOOD_NORMAL", playerIndex); }
    static void SetPlayerMoodPissedOff(Player playerIndex, u32 unknown150) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_MOOD_PISSED_OFF", playerIndex, unknown150); }
    static void SetPlayerNeverGetsTired(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_NEVER_GETS_TIRED", playerIndex, value); }
    static void SetPlayerSettingsModelVariationsChoice(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYERSETTINGS_MODEL_VARIATIONS_CHOICE", playerIndex); }
    static void SetPoliceIgnorePlayer(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_POLICE_IGNORE_PLAYER", playerIndex, value); }
    static void StoreScore(Player playerIndex, u32* value) { NativeInvoke::Invoke<ScriptVoid>("STORE_SCORE", playerIndex, value); }
    static void StoreWantedLevel(Player playerIndex, u32* value) { NativeInvoke::Invoke<ScriptVoid>("STORE_WANTED_LEVEL", playerIndex, value); }
    static void RemovePlayerHelmet(Player playerIndex, b8 remove) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PLAYER_HELMET", playerIndex, remove); }

    // Ped
    static void AddAmmoToChar(Ped ped, eWeapon weapon, u32 amount) { NativeInvoke::Invoke<ScriptVoid>("ADD_AMMO_TO_CHAR", ped, weapon, amount); }
    static void AddArmourToChar(Ped ped, u32 amount) { NativeInvoke::Invoke<ScriptVoid>("ADD_ARMOUR_TO_CHAR", ped, amount); }
    static void ApplyForceToPed(Ped ped, u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { NativeInvoke::Invoke<ScriptVoid>("APPLY_FORCE_TO_PED", ped, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
    static void AttachPedToCar(Ped ped, Vehicle vehicle, u32 unknown0_0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 unknown1_276, f32 unknown2_0, u32 unknown3_0, u32 unknown4_0) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_PED_TO_CAR", ped, vehicle, unknown0_0, offsetX, offsetY, offsetZ, unknown1_276, unknown2_0, unknown3_0, unknown4_0); }
    static void BlockCharGestureAnims(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_CHAR_GESTURE_ANIMS", ped, value); }
    static void BlockPedWeaponSwitching(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_PED_WEAPON_SWITCHING", ped, value); }
    static void CancelCurrentlyPlayingAmbientSpeech(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH", ped); }
    static void ClearAllCharProps(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ALL_CHAR_PROPS", ped); }
    static void ClearCharLastDamageBone(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_BONE", ped); }
    static void ClearCharLastDamageEntity(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_ENTITY", ped); }
    static void ClearCharLastWeaponDamage(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_WEAPON_DAMAGE", ped); }	
    static void ClearCharProp(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_PROP", ped, unknown); }
    static void ClearCharSecondaryTask(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_SECONDARY_TASK", ped); }
    static void ClearCharTasks(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS", ped); }
    static void ClearCharTasksImmediately(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS_IMMEDIATELY", ped); }
    static void ClearRoomForChar(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_CHAR", ped); }
    static void CreateChar(u32 type, eModel model, f32 x, f32 y, f32 z, Ped *pPed, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CHAR", type, model, x, y, z, pPed, unknownTrue); }
    static void CreateRandomChar(f32 x, f32 y, f32 z, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR", x, y, z, pPed); }
    static void CreateRandomCharAsDriver(Vehicle vehicle, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR_AS_DRIVER", vehicle, pPed); }
    static void CreateRandomFemaleChar(f32 x, f32 y, f32 z, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_FEMALE_CHAR", x, y, z, pPed); }
    static void CreateRandomMaleChar(f32 x, f32 y, f32 z, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_MALE_CHAR", x, y, z, pPed); }
    static void DamageChar(Ped ped, u32 hitPoints, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DAMAGE_CHAR", ped, hitPoints, unknown); }
    static void DamagePedBodyPart(Ped ped, ePedBodyPart part, u32 hitPoints) { NativeInvoke::Invoke<ScriptVoid>("DAMAGE_PED_BODY_PART", ped, part, hitPoints); }
    static void DeleteChar(Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("DELETE_CHAR", pPed); }
    static void DetachPed(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DETACH_PED", ped, unknown); }
    static void DetachPedFromWithinCar(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DETACH_PED_FROM_WITHIN_CAR", ped, unknown); }
    static b8 DoesCharExist(Ped ped) { return NativeInvoke::Invoke<b8>("DOES_CHAR_EXIST", ped); }
    static void DropObject(Ped ped, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("DROP_OBJECT", ped, unknownTrue); }
    static void ExplodeCharHead(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("EXPLODE_CHAR_HEAD", ped); }
    static void ExtinguishCharFire(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("EXTINGUISH_CHAR_FIRE", ped); }
    static void FirePedWeapon(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("FIRE_PED_WEAPON", ped, x, y, z); }
    static void ForceCharToDropWeapon(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("FORCE_CHAR_TO_DROP_WEAPON", ped); }
    static ScriptAny ForcePedPinnedDown(Ped ped, b8 force, u32 timerMaybe) { return NativeInvoke::Invoke<ScriptAny>("FORCE_PED_PINNED_DOWN", ped, force, timerMaybe); }
    static void ForcePedToFleeWhilstDrivingVehicle(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("FORCE_PED_TO_FLEE_WHILST_DRIVING_VEHICLE", ped, vehicle); }
    static void FreezeCharPosition(Ped ped, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION", ped, frozen); }
    static void FreezeCharPositionAndDontLoadCollision(Ped ped, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION_AND_DONT_LOAD_COLLISION", ped, frozen); }
    static void GetAmmoInCharWeapon(Ped ped, eWeapon weapon, u32 *pAmmo) { NativeInvoke::Invoke<ScriptVoid>("GET_AMMO_IN_CHAR_WEAPON", ped, weapon, pAmmo); }
    static b8 GetAmmoInClip(Ped ped, eWeapon weapon, u32 *pAmmo) { return NativeInvoke::Invoke<b8>("GET_AMMO_IN_CLIP", ped, weapon, pAmmo); }
    static const ch *GetAnimGroupFromChar(Ped ped) { return NativeInvoke::Invoke<const ch *>("GET_ANIM_GROUP_FROM_CHAR", ped); }
    static void GetCharCoordinates(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_COORDINATES", ped, pX, pY, pZ); }
    static void GetCharHealth(Ped ped, u32 *pHealth) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_HEALTH", ped, pHealth); }
    static void GetCharAnimCurrentTime(Ped ped, const ch *animGroup, const ch *animName, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_ANIM_CURRENT_TIME", ped, animGroup, animName, pValue); }
    static void GetCharAnimTotalTime(Ped ped, const ch *animGroup, const ch *animName, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_ANIM_TOTAL_TIME", ped, animGroup, animName, pValue); }
    static void GetCharArmour(Ped ped, u32 *pArmour) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_ARMOUR", ped, pArmour); }
    static u32 GetCharDrawableVariation(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<ScriptAny>("GET_CHAR_DRAWABLE_VARIATION", ped, component); }
    static void GetCharExtractedDisplacement(Ped ped, b8 unknown, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_EXTRACTED_DISPLACEMENT", ped, unknown, pX, pY, pZ); }
    static void GetCharHeading(Ped ped, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_HEADING", ped, pValue); }
    static void GetCharHeightAboveGround(Ped ped, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_HEIGHT_ABOVE_GROUND", ped, pValue); }
    static ScriptAny GetCharLastDamageBone(Ped ped, ePedBone *pBone) { return NativeInvoke::Invoke<ScriptAny>("GET_CHAR_LAST_DAMAGE_BONE", ped, pBone); }
    static b8 GetCharMeleeActionFlag0(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG0", ped); }
    static b8 GetCharMeleeActionFlag1(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG1", ped); }
    static void GetCharModel(Ped ped, eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_MODEL", ped, pModel); }
    static u32 GetCharMoney(Ped ped) { return NativeInvoke::Invoke<u32>("GET_CHAR_MONEY", ped); }
    static void GetCharPropIndex(Ped ped, b8 unknown, u32 *pIndex) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_PROP_INDEX", ped, unknown, pIndex); }
    static b8 GetCharReadyToBeExecuted(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_READY_TO_BE_EXECUTED", ped); }
    static b8 GetCharReadyToBeStunned(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_READY_TO_BE_STUNNED", ped); }
    static void GetCharSpeed(Ped ped, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_SPEED", ped, pValue); }
    static u32 GetCharTextureVariation(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", ped, component); }
    static void GetCharVelocity(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_VELOCITY", ped, pX, pY, pZ); }
    static void GetCharWeaponInSlot(Ped ped, eWeaponSlot slot, eWeapon *pWeapon, ScriptAny *pUnknown1, ScriptAny *pUnknown2) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_WEAPON_IN_SLOT", ped, slot, pWeapon, pUnknown1, pUnknown2); }
    static b8 GetCharWillCowerInsteadOfFleeing(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", ped); }
    static ScriptAny GetCurrentCharWeapon(Ped ped, eWeapon *pWeapon) { return NativeInvoke::Invoke<ScriptAny>("GET_CURRENT_CHAR_WEAPON", ped, pWeapon); }
    static u32 GetDamageToPedBodyPart(Ped ped, ePedBodyPart part) { return NativeInvoke::Invoke<u32>("GET_DAMAGE_TO_PED_BODY_PART", ped, part); }
    static void GetDeadCharCoordinates(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_DEAD_CHAR_COORDINATES", ped, pX, pY, pZ); }
    static void GetDeadCharPickupCoords(Ped ped, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_DEAD_CHAR_PICKUP_COORDS", ped, pX, pY, pZ); }
    static void GetKeyForCharInRoom(Ped ped, eInteriorRoomKey *pKey) { NativeInvoke::Invoke<ScriptVoid>("GET_KEY_FOR_CHAR_IN_ROOM", ped, pKey); }
    static ScriptAny GetMaxAmmo(Ped ped, eWeapon weapon, u32 *pMaxAmmo) { return NativeInvoke::Invoke<ScriptAny>("GET_MAX_AMMO", ped, weapon, pMaxAmmo); }
    static void GetMaxAmmoInClip(Ped ped, eWeapon weapon, u32 *pMaxAmmo) { NativeInvoke::Invoke<ScriptVoid>("GET_MAX_AMMO_IN_CLIP", ped, weapon, pMaxAmmo); }
    static u32 GetNumberOfCharDrawableVariations(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS", ped, component); }
    static u32 GetNumberOfCharTextureVariations(Ped ped, ePedComponent component, u32 unknown1) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS", ped, component, unknown1); }
    static Object GetObjectPedIsHolding(Ped ped) { return NativeInvoke::Invoke<Object>("GET_OBJECT_PED_IS_HOLDING", ped); }
    static void GetOffsetFromCharInWorldCoords(Ped ped, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_CHAR_IN_WORLD_COORDS", ped, x, y, z, pOffX, pOffY, pOffZ); }
    static ePedClimbState GetPedClimbState(Ped ped) { return NativeInvoke::Invoke<ePedClimbState>("GET_PED_CLIMB_STATE", ped); }
    static void GetPedBonePosition(Ped ped, ePedBone bone, f32 x, f32 y, f32 z, Vector3 *pPosition) { NativeInvoke::Invoke<ScriptVoid>("GET_PED_BONE_POSITION", ped, bone, x, y, z, pPosition); }
    static void GetPedGroupIndex(Ped ped, u32* pIndex) { NativeInvoke::Invoke<ScriptVoid>("GET_PED_GROUP_INDEX", ped, pIndex); }
    static void GetPedType(Ped ped, ePedType *pType) { NativeInvoke::Invoke<ScriptVoid>("GET_PED_TYPE", ped, pType); }
    static void GivePedHelmet(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PED_HELMET", ped); }
    static void GiveWeaponToChar(Ped ped, eWeapon weapon, u32 ammo, b8 unknown0) { NativeInvoke::Invoke<ScriptVoid>("GIVE_WEAPON_TO_CHAR", ped, weapon, ammo, unknown0); }
    static b8 HasCharBeenDamagedByCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CAR", ped, vehicle); }
    static b8 HasCharBeenDamagedByChar(Ped ped, Ped otherChar, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CHAR", ped, otherChar, unknownFalse); }
    static b8 HasCharBeenDamagedByWeapon(Ped ped, eWeapon weapon) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_WEAPON", ped, weapon); }
    static b8 HasCharGotWeapon(Ped ped, eWeapon weapon) { return NativeInvoke::Invoke<b8>("HAS_CHAR_GOT_WEAPON", ped, weapon); }
    static b8 HasCharSpottedChar(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR", ped, otherChar); }
    static b8 HasCharSpottedCharInFront(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR_IN_FRONT", ped, otherChar); }
    static b8 IsAmbientSpeechPlaying(Ped ped) { return NativeInvoke::Invoke<b8>("IS_AMBIENT_SPEECH_PLAYING", ped); }
    static b8 IsCharArmed(Ped ped, eWeaponSlot slot) { return NativeInvoke::Invoke<b8>("IS_CHAR_ARMED", ped, slot); }
    static b8 IsCharDead(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_DEAD", ped); }
    static b8 IsCharDucking(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_DUCKING", ped); }
    static b8 IsCharFacingChar(Ped ped, Ped otherChar, f32 angle) { return NativeInvoke::Invoke<b8>("IS_CHAR_FACING_CHAR", ped, otherChar, angle); }
    static b8 IsCharFatallyInjured(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_FATALLY_INJURED", ped); }
    static b8 IsCharGesturing(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GESTURING", ped); }
    static b8 IsCharGettingInToACar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GETTING_IN_TO_A_CAR", ped); }
    static b8 IsCharGettingUp(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GETTING_UP", ped); }
    static b8 IsCharHealthGreater(Ped ped, u32 health) { return NativeInvoke::Invoke<b8>("IS_CHAR_HEALTH_GREATER", ped, health); }
    static b8 IsCharInAir(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AIR", ped); }	
    static b8 IsCharInAngledArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_2D", ped, x1, y1, x2, y2, unknown, unknownFalse); }
    static b8 IsCharInAngledArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
    static b8 IsCharInAnyBoat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_BOAT", ped); }
    static b8 IsCharInAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_CAR", ped); }
    static b8 IsCharInAnyHeli(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_HELI", ped); }
    static b8 IsCharInAnyPlane(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_PLANE", ped); }
    static b8 IsCharInAnyPoliceVehicle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_POLICE_VEHICLE", ped); }
    static b8 IsCharInAnyTrain(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_TRAIN", ped); }
    static b8 IsCharInArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_2D", ped, x1, y1, x2, y2, unknownFalse); }
    static b8 IsCharInArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
    static b8 IsCharInAreaOnFoot2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_ON_FOOT_2D", ped, x1, y1, x2, y2, unknownFalse); }
    static b8 IsCharInCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_CAR", ped, vehicle); }
    static b8 IsCharInFlyingVehicle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_FLYING_VEHICLE", ped); }
    static b8 IsCharInMeleeCombat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_MELEE_COMBAT", ped); }
    static b8 IsCharInModel(Ped ped, eModel model) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_MODEL", ped, model); }
    static b8 IsCharInTaxi(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_TAXI", ped); }
    static b8 IsCharInWater(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_WATER", ped); }
    static b8 IsCharInjured(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_INJURED", ped); }
    static b8 IsCharMale(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_MALE", ped); }
    static b8 IsCharModel(Ped ped, eModel model) { return NativeInvoke::Invoke<b8>("IS_CHAR_MODEL", ped, model); }
    static b8 IsCharOnAnyBike(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_ANY_BIKE", ped); }
    static b8 IsCharOnFire(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_FIRE", ped); }
    static b8 IsCharOnFoot(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_FOOT", ped); }
    static b8 IsCharOnScreen(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_SCREEN", ped); }
    static b8 IsCharPlayingAnim(Ped ped, ch *animSet, ch *animName) { return NativeInvoke::Invoke<b8>("IS_CHAR_PLAYING_ANIM", ped, animSet, animName); }
    static b8 IsCharShooting(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SHOOTING", ped); }
    static b8 IsCharShootingInArea(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_SHOOTING_IN_AREA", ped, x1, y1, x2, y2, unknownFalse); }
    static b8 IsCharSittingIdle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IDLE", ped); }
    static b8 IsCharSittingInAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IN_ANY_CAR", ped); }
    static b8 IsCharSittingInCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IN_CAR", ped, vehicle); }
    static b8 IsCharStopped(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_STOPPED", ped); }
    static b8 IsCharStuckUnderCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_STUCK_UNDER_CAR", ped); }
    static b8 IsCharSwimming(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SWIMMING", ped); }
    static b8 IsCharTouchingChar(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_CHAR", ped, otherChar); }
    static b8 IsCharTouchingObject(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT", ped, obj); }
    static b8 IsCharTouchingObjectOnFoot(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT_ON_FOOT", ped, obj); }
    static b8 IsCharTouchingVehicle(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_VEHICLE", p0, p1); }
    static b8 IsCharTryingToEnterALockedCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_TRYING_TO_ENTER_A_LOCKED_CAR", ped); }
    static b8 IsCharUsingAnyScenario(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_USING_ANY_SCENARIO", ped); }
    static b8 IsCharUsingScenario(Ped ped, const ch *scenarioName) { return NativeInvoke::Invoke<b8>("IS_CHAR_USING_SCENARIO", ped, scenarioName); }
    static b8 IsCharVisible(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_VISIBLE", ped); }
    static b8 IsCharWaitingForWorldCollision(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_WAITING_FOR_WORLD_COLLISION", ped); }
    static b8 IsPedAMissionPed(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_A_MISSION_PED", ped); }
    static b8 IsPedAttachedToAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_ATTACHED_TO_ANY_CAR", ped); }
    static b8 IsPedAttachedToObject(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_PED_ATTACHED_TO_OBJECT", ped, obj); }
    static b8 IsPedBeingJacked(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_BEING_JACKED", ped); }
    static b8 IsPedDoingDriveby(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_DOING_DRIVEBY", ped); }
    static b8 IsPedFleeing(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_FLEEING", ped); }
    static b8 IsPedHoldingAnObject(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_HOLDING_AN_OBJECT", ped); }
    static b8 IsPedInCombat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_COMBAT", ped); }
    static b8 IsPedInCover(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_COVER", ped); }
    static b8 IsPedInGroup(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_GROUP", ped); }
    static b8 IsPedJacking(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_JACKING", ped); }
    static b8 IsPedLookingAtPed(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("IS_PED_LOOKING_AT_PED", ped, otherChar); }
    static b8 IsPedRagdoll(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_RAGDOLL", ped); }
    static b8 IsPedRetreating(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_RETREATING", ped); }
    static b8 IsScriptedSpeechPlaying(Ped ped) { return NativeInvoke::Invoke<b8>("IS_SCRIPTED_SPEECH_PLAYING", ped); }
    static void MarkCharAsNoLongerNeeded(Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("MARK_CHAR_AS_NO_LONGER_NEEDED", pPed); }
    static void ModifyCharMoveState(Ped ped, ePedMoveState state) { NativeInvoke::Invoke<ScriptVoid>("MODIFY_CHAR_MOVE_STATE", ped, state); }
    static void RemoveAllCharWeapons(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_ALL_CHAR_WEAPONS", ped); }
    static void RemoveCharDefensiveArea(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_DEFENSIVE_AREA", ped); }
    static void RemoveCharElegantly(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_ELEGANTLY", ped); }
    static void RemoveCharFromGroup(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_FROM_GROUP", ped); }
    static void ReviveInjuredPed(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REVIVE_INJURED_PED", ped); }
    static void SayAmbientSpeech(Ped ped, ch *phraseName, ScriptAny unknown0_1, ScriptAny unknown1_1, ScriptAny unknown2_0) { NativeInvoke::Invoke<ScriptVoid>("SAY_AMBIENT_SPEECH", ped, phraseName, unknown0_1, unknown1_1, unknown2_0); }
    static ScriptAny SetAmmoInClip(Ped ped, eWeapon weapon, u32 ammo) { return NativeInvoke::Invoke<ScriptAny>("SET_AMMO_IN_CLIP", ped, weapon, ammo); }
    static void SetBlockingOfNonTemporaryEvents(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_BLOCKING_OF_NON_TEMPORARY_EVENTS", ped, value); }
    static void SetCharAccuracy(Ped ped, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ACCURACY", ped, value); }
    static void SetCharAmmo(Ped ped, eWeapon weapon, u32 ammo) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_AMMO", ped, weapon, ammo); }
    static void SetCharAsEnemy(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_AS_ENEMY", ped, value); }
    static void SetCharAsMissionChar(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_AS_MISSION_CHAR", ped); }
    static void SetCharCanBeKnockedOffBike(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_KNOCKED_OFF_BIKE", ped, value); }
    static void SetCharCanBeShotInVehicle(Ped ped, b8 enabled) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_SHOT_IN_VEHICLE", ped, enabled); }
    static void SetCharCantBeDraggedOut(Ped ped, b8 enabled) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CANT_BE_DRAGGED_OUT", ped, enabled); }
    static void SetCharComponentVariation(Ped ped, ePedComponent component, u32 modelVariation, u32 textureVariation) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_COMPONENT_VARIATION", ped, component, modelVariation, textureVariation); }
    static void SetCharCoordinates(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_COORDINATES", ped, x, y, z); }
    static void SetCharDefaultComponentVariation(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DEFAULT_COMPONENT_VARIATION", ped); }
    static void SetCharDesiredHeading(Ped ped, f32 heading) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DESIRED_HEADING", ped, heading); }
    static void SetCharDropsWeaponsWhenDead(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DROPS_WEAPONS_WHEN_DEAD", ped, value); }
    static void SetCharDruggedUp(Ped ped, b8 drugged) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DRUGGED_UP", ped, drugged); }
    static void SetCharFireDamageMultiplier(Ped ped, f32 multiplier) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_FIRE_DAMAGE_MULTIPLIER", ped, multiplier); }
    static void SetCharGravity(Ped ped, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_GRAVITY", ped, value); }
    static void SetCharHeading(Ped ped, f32 heading) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_HEADING", ped, heading); }
    static void SetCharHealth(Ped ped, u32 health) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_HEALTH", ped, health); }
    static void SetCharInvincible(Ped ped, b8 enable) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_INVINCIBLE", ped, enable); }
    static void SetCharIsTargetPriority(Ped ped, b8 enable) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_IS_TARGET_PRIORITY", ped, enable); }
    static void SetCharMaxHealth(Ped ped, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MAX_HEALTH", ped, value); }
    static void SetCharMoney(Ped ped, u32 amount) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MONEY", ped, amount); }
    static void SetCharNeverLeavesGroup(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_NEVER_LEAVES_GROUP", ped, value); }
    static void SetCharProofs(Ped ped, b8 unknown0, b8 fallingDamage, b8 unknown1, b8 unknown2, b8 unknown3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_PROOFS", ped, unknown0, fallingDamage, unknown1, unknown2, unknown3); }
    static void SetCharPropIndex(Ped ped, ePedPropType propType, u32 index) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_PROP_INDEX", ped, propType, index); }
    static void SetCharRandomComponentVariation(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_RANDOM_COMPONENT_VARIATION", ped); }
    static void SetCharSphereDefensiveArea(Ped ped, f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_SPHERE_DEFENSIVE_AREA", ped, x, y, z, radius); }
    static void SetCharSuffersCriticalHits(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_SUFFERS_CRITICAL_HITS", ped, value); }
    static void SetCharVelocity(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_VELOCITY", ped, x, y, z); }
    static void SetCharVisible(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_VISIBLE", ped, value); }
    static void SetCharWantedByPolice(Ped ped, b8 wanted) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WANTED_BY_POLICE", ped, wanted); }
    static void SetCharWillDoDrivebys(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_DO_DRIVEBYS", ped, value); }
    static void SetCharWillFlyThroughWindscreen(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN", ped, value); }
    static void SetCharWillMoveWhenInjured(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_MOVE_WHEN_INJURED", ped, value); }
    static void SetCharWillUseCarsInCombat(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_CARS_IN_COMBAT", ped, value); }
    static void SetCharWillUseCover(Ped ped, CoverPoint coverPoint) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_COVER", ped, coverPoint); }
    static void SetCurrentCharWeapon(Ped ped, eWeapon w, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("SET_CURRENT_CHAR_WEAPON", ped, w, unknownTrue); }
    static void SetGroupCharDucksWhenAimedAt(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT", ped, value); }
    static void SetIgnoreLowPriorityShockingEvents(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS", ped, value); }
    static void SetPedDiesWhenInjured(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_DIES_WHEN_INJURED", ped, value); }
    static void SetPedIsBlindRaging(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_IS_BLIND_RAGING", ped, value); }
    static void SetPedIsDrunk(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_IS_DRUNK", ped, value); }
    static void SetPedPathMayDropFromHeight(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_PATH_MAY_DROP_FROM_HEIGHT", ped, value); }
    static void SetPedPathMayUseClimbovers(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_CLIMBOVERS", ped, value); }
    static void SetPedPathMayUseLadders(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_LADDERS", ped, value); }
    static void SetRoomForCharByKey(Ped ped, eInteriorRoomKey key) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_CHAR_BY_KEY", ped, key); }
    static void SetSenseRange(Ped ped, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_SENSE_RANGE", ped, value); }
    static void SwitchPedToAnimated(Ped ped, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_PED_TO_ANIMATED", ped, unknownTrue); }
    static ScriptAny SwitchPedToRagdoll(Ped ped, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("SWITCH_PED_TO_RAGDOLL", ped, p1, p2, p3, p4, p5, p6); }    
    static void RemovePedHelmet(Ped ped, b8 removed) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PED_HELMET", ped, removed); }
    static void RemoveWeaponFromChar(Ped ped, eWeapon weapon) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_WEAPON_FROM_CHAR", ped, weapon); }
    static void UnlockRagdoll(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("UNLOCK_RAGDOLL", ped, value); }
    static void WarpCharFromCarToCoord(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_COORD", ped, x, y, z); }
    static void WarpCharIntoCar(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR", ped, vehicle); }
    static void WarpCharIntoCarAsPassenger(Ped ped, Vehicle vehicle, u32 seatIndex) { NativeInvoke::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR_AS_PASSENGER", ped, vehicle, seatIndex); }
    static void WarpCharFromCarToCar(Ped ped, Vehicle vehicle, u32 seatIndex) { NativeInvoke::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_CAR", ped, vehicle, seatIndex); }


    // Ped Tasks
    static void SetCharKeepTask(Ped ped, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_KEEP_TASK", ped, value); }
    static void SetDriveTaskCruiseSpeed(Ped ped, f32 speed) { NativeInvoke::Invoke<ScriptVoid>("SET_DRIVE_TASK_CRUISE_SPEED", ped, speed); }
    static void TaskAchieveHeading(Ped ped, f32 heading) { NativeInvoke::Invoke<ScriptVoid>("TASK_ACHIEVE_HEADING", ped, heading); }
    static void TaskAimGunAtChar(Ped ped, Ped targetPed, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_AIM_GUN_AT_CHAR", ped, targetPed, duration); } 
    static void TaskAimGunAtCoord(Ped ped, f32 tX, f32 tY, f32 tZ, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_AIM_GUN_AT_COORD", ped, tX, tY, tZ, duration); }
    static void TaskCarDriveWander(Ped ped, Vehicle vehicle, f32 speed, eVehicleDrivingStyle drivingStyle) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_DRIVE_WANDER", ped, vehicle, speed, drivingStyle); }
    static void TaskCarMission(Ped ped, Vehicle vehicle, ScriptHandle targetEntity, u32 missionType, f32 speed, eVehicleDrivingStyle drivingStyle, u32 unknown6_10, u32 unknown7_5) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_MISSION", ped, vehicle, targetEntity, missionType, speed, drivingStyle, unknown6_10, unknown7_5); } // target is whatever missiontype requires (ie. vehicle or just 0). missiontypes: 5=wait(), 21=drivetoplayer()
    static void TaskCarMissionNotAgainstTraffic(Ped ped, Vehicle vehicle, ScriptHandle targetEntity, u32 missionType, f32 speed, eVehicleDrivingStyle  drivingStyle, u32 unknown6_10, u32 unknown7_5) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_MISSION_NOT_AGAINST_TRAFFIC", ped, vehicle, targetEntity, missionType, speed, drivingStyle, unknown6_10, unknown7_5); }
    static void TaskCarMissionCoorsTarget(Ped ped, Vehicle vehicle, f32 x, f32 y, f32 z, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_MISSION_COORS_TARGET", ped, vehicle, x, y, z, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
    static void TaskCarMissionCoorsTargetNotAgainstTraffic(Ped ped, Vehicle vehicle, f32 x, f32 y, f32 z, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC", ped, vehicle, x, y, z, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
    static void TaskCarMissionPedTarget(Ped ped, Vehicle vehicle, Ped target, u32 unknown0_4, f32 speed, u32 unknown2_1, u32 unknown3_5, u32 unknown4_10) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_MISSION_PED_TARGET", ped, vehicle, target, unknown0_4, speed, unknown2_1, unknown3_5, unknown4_10); }
    static void TaskCarTempAction(Ped ped, Vehicle vehicle, u32 action, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_TEMP_ACTION", ped, vehicle, action, duration); } // action 6 = wait?
    static void TaskCombat(Ped ped, Ped target) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT", ped, target); }
    static void TaskCombatHatedTargetsAroundChar(Ped ped, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_AROUND_CHAR", ped, radius); }
    static void TaskCombatHatedTargetsAroundCharTimed(Ped ped, f32 radius, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_AROUND_CHAR_TIMED", ped, radius, duration); }
    static void TaskCombatTimed(Ped ped, Char target, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT_TIMED", ped, target, duration); }
    static void TaskDie(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("TASK_DIE", ped); }
    static void TaskEnterCarAsDriver(Ped ped, Vehicle vehicle, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_ENTER_CAR_AS_DRIVER", ped, vehicle, duration); }
    static void TaskEnterCarAsPassenger(Ped ped, Vehicle vehicle, u32 duration, u32 seatIndex) { NativeInvoke::Invoke<ScriptVoid>("TASK_ENTER_CAR_AS_PASSENGER", ped, vehicle, duration, seatIndex); }
    static void TaskEveryoneLeaveCar(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("TASK_EVERYONE_LEAVE_CAR", vehicle); }
    static void TaskFollowNavMeshToCoord(Ped ped, f32 x, f32 y, f32 z, u32 unknown0_2, u32 unknown1_minus1, f32 unknown2_1) { NativeInvoke::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_TO_COORD", ped, x, y, z, unknown0_2, unknown1_minus1, unknown2_1); }
    static void TaskFollowNavMeshToCoordNoStop(Ped ped, f32 x, f32 y, f32 z,u32 unknown0_2, u32 unknown1_minus1, f32 unknown2_1) { NativeInvoke::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_TO_COORD_NO_STOP", ped, x, y, z, unknown0_2, unknown1_minus1, unknown2_1); }
    static void TaskGoStraightToCoord(Ped ped, f32 x, f32 y, f32 z, u32 unknown2, u32 unknown45000) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_STRAIGHT_TO_COORD", ped, x, y, z, unknown2, unknown45000); }
    static void TaskGotoCharOffset(Ped ped, Ped target, u32 duration, f32 offsetRight, f32 offsetFront) { NativeInvoke::Invoke<ScriptVoid>("TASK_GOTO_CHAR_OFFSET", ped, target, duration, offsetRight, offsetFront); }
    static void TaskGuardCurrentPosition(Ped ped, f32 unknown0_15, f32 unknown1_10, u32 unknown2_1) { NativeInvoke::Invoke<ScriptVoid>("TASK_GUARD_CURRENT_POSITION", ped, unknown0_15, unknown1_10, unknown2_1); }
    static void TaskHandsUp(Ped ped, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_HANDS_UP", ped, duration); }
    static void TaskHeliMission(Ped ped, Vehicle heli, u32 uk0_0, u32 uk1_0, f32 pX, f32 pY, f32 pZ, u32 uk2_4, f32 speed, u32 uk3_5, f32 uk4_minus1, u32 uk5_round_z_plus_1, u32 uk6_40) { NativeInvoke::Invoke<ScriptVoid>("TASK_HELI_MISSION", ped, heli, uk0_0, uk1_0, pX, pY, pZ, uk2_4, speed, uk3_5, uk4_minus1, uk5_round_z_plus_1, uk6_40); }
    static void TaskLeaveAnyCar(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_ANY_CAR", ped); }
    static void TaskLeaveCar(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_CAR", ped, vehicle); }
    static void TaskLeaveCarDontCloseDoor(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_CAR_DONT_CLOSE_DOOR", ped, vehicle); }
    static void TaskLeaveCarImmediately(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_CAR_IMMEDIATELY", ped, vehicle); }
    static void TaskLookAtChar(Ped ped, Ped targetPed, u32 duration, u32 unknown_0) { NativeInvoke::Invoke<ScriptVoid>("TASK_LOOK_AT_CHAR", ped, targetPed, duration, unknown_0); }
    static void TaskLookAtCoord(Ped ped, f32 x, f32 y, f32 z, u32 duration, u32 unknown_0) { NativeInvoke::Invoke<ScriptVoid>("TASK_LOOK_AT_COORD", ped, x, y, z, duration, unknown_0); }
    static void TaskLookAtObject(Ped ped, Object targetObject, u32 duration, u32 unknown_0) { NativeInvoke::Invoke<ScriptVoid>("TASK_LOOK_AT_OBJECT", ped, targetObject, duration, unknown_0); }
    static void TaskLookAtVehicle(Ped ped, Vehicle targetVehicle, u32 duration, u32 unknown_0) { NativeInvoke::Invoke<ScriptVoid>("TASK_LOOK_AT_VEHICLE", ped, targetVehicle, duration, unknown_0); }
    static void TaskOpenDriverDoor(Ped ped, Vehicle vehicle, u32 unknown0) { NativeInvoke::Invoke<ScriptVoid>("TASK_OPEN_DRIVER_DOOR", ped, vehicle, unknown0); }
    static void TaskOpenPassengerDoor(Ped ped, Vehicle vehicle, u32 seatIndex, u32 unknown0) { NativeInvoke::Invoke<ScriptVoid>("TASK_OPEN_PASSENGER_DOOR", ped, vehicle, seatIndex, unknown0); }
    static void TaskPause(Ped ped, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_PAUSE", ped, duration); }
    static void TaskPlayAnimWithFlags(Ped ped, const ch *animName, const ch *animSet, f32 unknown0_8, u32 unknown1_0, u32 flags) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_WITH_FLAGS", ped, animName, animSet, unknown0_8, unknown1_0, flags); }
    static void TaskSetCharDecisionMaker(Ped ped, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("TASK_SET_CHAR_DECISION_MAKER", ped, dm); }
    static void TaskSetCombatDecisionMaker(Ped ped, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("TASK_SET_COMBAT_DECISION_MAKER", ped, dm); }
    static void TaskSmartFleeChar(Ped ped, Ped fleeFromPed, f32 unknown0_100, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_SMART_FLEE_CHAR", ped, fleeFromPed, unknown0_100, duration); }
    static void TaskSmartFleeCharPreferringPavements(Ped ped, Ped fleeFromPed, f32 unknown0_100, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_SMART_FLEE_CHAR_PREFERRING_PAVEMENTS", ped, fleeFromPed, unknown0_100, duration); }
    static void TaskSmartFleePoint(Ped ped, f32 x, f32 y, f32 z, f32 unknown0_100, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_SMART_FLEE_POINT", ped, x, y, x, unknown0_100, duration); }
    static void TaskStandStill(Ped ped, int duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_STAND_STILL", ped, duration); }
    static void TaskSwapWeapon(Ped ped, eWeapon weapon) { NativeInvoke::Invoke<ScriptVoid>("TASK_SWAP_WEAPON", ped, weapon); }
    static void TaskTurnCharToFaceChar(Ped ped, Ped targetPed) { NativeInvoke::Invoke<ScriptVoid>("TASK_TURN_CHAR_TO_FACE_CHAR", ped, targetPed); }
    static void TaskTurnCharToFaceCoord(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("TASK_TURN_CHAR_TO_FACE_COORD", ped, x, y, z); }
    static void TaskUseMobilePhone(Ped ped, b8 use) { NativeInvoke::Invoke<ScriptVoid>("TASK_USE_MOBILE_PHONE", ped, use); }
    static void TaskUseMobilePhoneTimed(Ped ped, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("TASK_USE_MOBILE_PHONE_TIMED", ped, duration); }
    static void TaskWanderStandard(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("TASK_WANDER_STANDARD", ped); }
    static void TaskWarpCharIntoCarAsDriver(Ped ped, Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("TASK_WARP_CHAR_INTO_CAR_AS_DRIVER", ped, vehicle); }
    static void TaskWarpCharIntoCarAsPassenger(Ped ped, Vehicle vehicle, u32 seatIndex) { NativeInvoke::Invoke<ScriptVoid>("TASK_WARP_CHAR_INTO_CAR_AS_PASSENGER", ped, vehicle, seatIndex); }

    // Task Sequence
    static void OpenSequenceTask(TaskSequence *pTaskSequence) { NativeInvoke::Invoke<ScriptVoid>("OPEN_SEQUENCE_TASK", pTaskSequence); }
    static void CloseSequenceTask(TaskSequence taskSequence) { NativeInvoke::Invoke<ScriptVoid>("CLOSE_SEQUENCE_TASK", taskSequence); }
    static void TaskPerformSequence(Ped ped, TaskSequence taskSequence) { NativeInvoke::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE", ped, taskSequence); }
    static void ClearSequenceTask(TaskSequence taskSequence) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_SEQUENCE_TASK", taskSequence); }

    // Ped Search
    static void AllowScenarioPedsToBeReturnedByNextCommand(b8 value) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND", value); }
    static void BeginCharSearchCriteria() { NativeInvoke::Invoke<ScriptVoid>("BEGIN_CHAR_SEARCH_CRITERIA"); }
    static void EndCharSearchCriteria() { NativeInvoke::Invoke<ScriptVoid>("END_CHAR_SEARCH_CRITERIA"); }
    static b8 GetClosestChar(f32 x, f32 y, f32 z, f32 radius, u32 unknown1, u32 unknown2, Ped *pPed) { return NativeInvoke::Invoke<b8>("GET_CLOSEST_CHAR", x, y, z, radius, unknown1, unknown2, pPed); }
    static void GetRandomCharInAreaOffsetNoSave(f32 x, f32 y, f32 z, f32 sx, f32 sy, f32 sz, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CHAR_IN_AREA_OFFSET_NO_SAVE", x, y, z, sx, sy, sz, pPed); }
    static void SearchCriteriaConsiderPedsWithFlagTrue(u32 flagId) { NativeInvoke::Invoke<ScriptVoid>("SEARCH_CRITERIA_CONSIDER_PEDS_WITH_FLAG_TRUE", flagId); }
    static void SearchCriteriaRejectPedsWithFlagTrue(u32 flagId) { NativeInvoke::Invoke<ScriptVoid>("SEARCH_CRITERIA_REJECT_PEDS_WITH_FLAG_TRUE", flagId); }

    // Ped Groups
    static void CreateGroup(b8 unknownFalse, Group *pGroup, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_GROUP", unknownFalse, pGroup, unknownTrue); }
    static b8 DoesGroupExist(Group group) { return NativeInvoke::Invoke<b8>("DOES_GROUP_EXIST", group); }
    static void GetGroupLeader(Group group, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_GROUP_LEADER", group, pPed); }
    static void GetGroupMember(Group group, u32 index, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_GROUP_MEMBER", group, index, pPed); }
    static void GetGroupSize(Group group, u32 *pStartIndex, u32 *pCount) { NativeInvoke::Invoke<ScriptVoid>("GET_GROUP_SIZE", group, pStartIndex, pCount); }
    static b8 IsGroupLeader(Ped ped, Group group) { return NativeInvoke::Invoke<b8>("IS_GROUP_LEADER", ped, group); }
    static b8 IsGroupMember(Ped ped, Group g) { return NativeInvoke::Invoke<b8>("IS_GROUP_MEMBER", ped, g); }
    static void RemoveGroup(Group group) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_GROUP", group); }
    static void SetGroupFollowStatus(Group group, u32 status) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_FOLLOW_STATUS", group, status); }
    static void SetGroupFormation(Group group, u32 formation) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_FORMATION", group, formation); }
    static void SetGroupFormationSpacing(Group group, f32 space) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_FORMATION_SPACING", group, space); }
    static void SetGroupLeader(Group group, Ped leader) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_LEADER", group, leader); }
    static void SetGroupMember(Group group, Ped member) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_MEMBER", group, member); }
    static void SetGroupSeparationRange(Group group, f32 seperation) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_SEPARATION_RANGE", group, seperation); }

    // Ped Relationships
    static void AllowGangRelationshipsToBeChangedByNextCommand(b8 value) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_GANG_RELATIONSHIPS_TO_BE_CHANGED_BY_NEXT_COMMAND", value); }
    static void SetCharNotDamagedByRelationshipGroup(Ped ped, u32 relationshipGroup, b8 enable) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_NOT_DAMAGED_BY_RELATIONSHIP_GROUP", ped, relationshipGroup, enable); }
    static void SetCharRelationship(Ped ped, u32 relationshipLevel, u32 relationshipGroup) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_RELATIONSHIP", ped, relationshipLevel, relationshipGroup); }
    static void SetCharRelationshipGroup(Ped ped, u32 relationshipGroup) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_RELATIONSHIP_GROUP", ped, relationshipGroup); }
    static void SetRelationship(u32 relationshipLevel, u32 relationshipGroup1, u32 relationshipGroup2) { NativeInvoke::Invoke<ScriptVoid>("SET_RELATIONSHIP", relationshipLevel, relationshipGroup1, relationshipGroup2); }

    // Vehicle
    static void AddUpsideDownCarCheck(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("ADD_UPSIDEDOWN_CAR_CHECK", vehicle); }
    static void AnchorBoat(Vehicle boat, b8 anchor) { NativeInvoke::Invoke<ScriptVoid>("ANCHOR_BOAT", boat, anchor); }
    static void ApplyForceToCar(Vehicle vehicle, u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { NativeInvoke::Invoke<ScriptVoid>("APPLY_FORCE_TO_CAR", vehicle, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
    static b8 AreTaxiLightsOn(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("ARE_TAXI_LIGHTS_ON", vehicle); }
    static void BreakCarDoor(Vehicle vehicle, eVehicleDoor door, b8 unknownFalse) { NativeInvoke::Invoke<ScriptVoid>("BREAK_CAR_DOOR", vehicle, door, unknownFalse); }
    static void BurstCarTyre(Vehicle vehicle, eVehicleTyre tyre) { NativeInvoke::Invoke<ScriptVoid>("BURST_CAR_TYRE", vehicle, tyre); }
    static void CreateCar(u32 nameHash, f32 x, f32 y, f32 z, Vehicle *pVehicle, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CAR", nameHash, x, y, z, pVehicle, unknownTrue); }
    static void CreateCharAsPassenger(Vehicle vehicle, ePedType charType, eModel model, u32 passengerIndex, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CHAR_AS_PASSENGER", vehicle, charType, model, passengerIndex, pPed); }
    static void CreateCharInsideCar(Vehicle vehicle, ePedType charType, eModel model, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CHAR_INSIDE_CAR", vehicle, charType, model, pPed); }
    static void ChangeCarColour(Vehicle vehicle, ColourIndex colour1, ColourIndex colour2) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_CAR_COLOUR", vehicle, colour1, colour2); }
    static void ClearCarLastDamageEntity(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CAR_LAST_DAMAGE_ENTITY", vehicle); }
    static void ClearCarLastWeaponDamage(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CAR_LAST_WEAPON_DAMAGE", vehicle); }
    static void ClearRoomForCar(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_CAR", vehicle); }
    static void CloseAllCarDoors(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("CLOSE_ALL_CAR_DOORS", vehicle); }
    static void ControlCarDoor(Vehicle vehicle, eVehicleDoor door, u32 unknown_maybe_open, f32 angle) { NativeInvoke::Invoke<ScriptVoid>("CONTROL_CAR_DOOR", vehicle, door, unknown_maybe_open, angle); }
    static b8 CreateEmergencyServicesCar(eModel model, f32 x, f32 y, f32 z) { return NativeInvoke::Invoke<b8>("CREATE_EMERGENCY_SERVICES_CAR", model, x, y, z); }
    static void CreateRandomCharAsPassenger(Vehicle vehicle, u32 seat, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR_AS_PASSENGER", vehicle, seat, pPed); }
    static void DeleteCar(Vehicle *pVehicle) { NativeInvoke::Invoke<ScriptVoid>("DELETE_CAR", pVehicle); }
    static void DetachCar(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("DETACH_CAR", vehicle); }
    static b8 DoesCarHaveRoof(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("DOES_CAR_HAVE_ROOF", vehicle); }
    static b8 DoesCarHaveStuckCarCheck(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("DOES_CAR_HAVE_STUCK_CAR_CHECK", vehicle); }
    static b8 DoesVehicleExist(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("DOES_VEHICLE_EXIST", vehicle); }
    static void EnablePedHelmet(Ped ped, b8 enable) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_PED_HELMET", ped, enable); }
    static void ExplodeCar(Vehicle vehicle, b8 unknownTrue, b8 unknownFalse) { NativeInvoke::Invoke<ScriptVoid>("EXPLODE_CAR", vehicle, unknownTrue, unknownFalse); }
    static void ExtinguishCarFire(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("EXTINGUISH_CAR_FIRE", vehicle); }
    static void FixCar(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("FIX_CAR", vehicle); }
    static void FixCarTyre(Vehicle vehicle, eVehicleTyre tyre) { NativeInvoke::Invoke<ScriptVoid>("FIX_CAR_TYRE", vehicle, tyre); }
    static void ForceVehicleLights(Vehicle vehicle, eVehicleLights lights) { NativeInvoke::Invoke<ScriptVoid>("FORCE_CAR_LIGHTS", vehicle, lights); }
    static void FreezeCarPosition(Vehicle vehicle, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CAR_POSITION", vehicle, frozen); }
    static void FreezeCarPositionAndDontLoadCollision(Vehicle vehicle, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CAR_POSITION_AND_DONT_LOAD_COLLISION", vehicle, frozen); }
    static void GetCarCharIsUsing(Ped ped, Vehicle *pVehicle) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_CHAR_IS_USING", ped, pVehicle); }
    static void GetCarColours(Vehicle vehicle, ColourIndex *pColour1, ColourIndex *pColour2) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_COLOURS", vehicle, pColour1, pColour2); }
    static void GetCarCoordinates(Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_COORDINATES", vehicle, pX, pY, pZ); }
    static void GetCarDeformationAtPos(Vehicle vehicle, f32 x, f32 y, f32 z, Vector3 *pDeformation) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_DEFORMATION_AT_POS", vehicle, x, y, z, pDeformation); }
    static void GetCarDoorLockStatus(Vehicle vehicle, eVehicleDoorLock *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_DOOR_LOCK_STATUS", vehicle, pValue); }
    static void GetCarForwardX(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_FORWARD_X", vehicle, pValue); }
    static void GetCarForwardY(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_FORWARD_Y", vehicle, pValue); }
    static void GetCarHeading(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_HEADING", vehicle, pValue); }
    static void GetCarHealth(Vehicle vehicle, u32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_HEALTH", vehicle, pValue); }
    static void GetCarModel(Vehicle vehicle, eModel *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_MODEL", vehicle, pValue); }
    static void GetCarPitch(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_PITCH", vehicle, pValue); }
    static void GetCarRoll(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_ROLL", vehicle, pValue); }
    static void GetCarSpeed(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_SPEED", vehicle, pValue); }
    static void GetCarSpeedVector(Vehicle vehicle, Vector3 *pVector, b8 unknownFalse) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_SPEED_VECTOR", vehicle, pVector, unknownFalse); }
    static void GetCarUprightValue(Vehicle vehicle, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_UPRIGHT_VALUE", vehicle, pValue); }
    static void GetCharInCarPassengerSeat(Vehicle vehicle, u32 seatIndex, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_IN_CAR_PASSENGER_SEAT", vehicle, seatIndex, pPed); }
    static Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, u32 unknown0_0, u32 unknown1_70) { return NativeInvoke::Invoke<Vehicle>("GET_CLOSEST_CAR", x, y, z, radius, unknown0_0, unknown1_70); }
    static b8 GetClosestCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return NativeInvoke::Invoke<b8>("GET_CLOSEST_CAR_NODE", x, y, z, pResX, pResY, pResZ); }
    static b8 GetClosestCarNodeWithHeading(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return NativeInvoke::Invoke<b8>("GET_CLOSEST_CAR_NODE_WITH_HEADING", x, y, z, pResX, pResY, pResZ, pHeading); }
    static b8 GetClosestMajorCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return NativeInvoke::Invoke<b8>("GET_CLOSEST_MAJOR_CAR_NODE", x, y, z, pResX, pResY, pResZ); }
    static b8 GetNthClosestCarNodeWithHeading(f32 x, f32 y, f32 z, u32 nodeNum,  f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return NativeInvoke::Invoke<b8>("GET_NTH_CLOSEST_CAR_NODE_WITH_HEADING", x, y, z, nodeNum, pResX, pResY, pResZ, pHeading); }
    static b8 GetNthClosestCarNodeWithHeadingOnIsland(f32 x, f32 y, f32 z, u32 nodeNum, u32 areaId, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading, u32 *pUnknownMaybeAreaId) { return NativeInvoke::Invoke<b8>("GET_NTH_CLOSEST_CAR_NODE_WITH_HEADING_ON_ISLAND", x, y, z, nodeNum, areaId, pResX, pResY, pResZ, pHeading, pUnknownMaybeAreaId); }
    static void GetDeadCarCoordinates(Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_DEAD_CAR_COORDINATES", vehicle, pX, pY, pZ); }
    static void GetDoorAngleRatio(Vehicle vehicle, eVehicleDoor door, f32 *pAngleRatio) { NativeInvoke::Invoke<ScriptVoid>("GET_DOOR_ANGLE_RATIO", vehicle, door, pAngleRatio); }
    static void GetDriverOfCar(Vehicle vehicle, Ped *pPed) { NativeInvoke::Invoke<ScriptVoid>("GET_DRIVER_OF_CAR", vehicle, pPed); }
    static f32 GetEngineHealth(Vehicle vehicle) { return NativeInvoke::Invoke<f32>("GET_ENGINE_HEALTH", vehicle); }
    static void GetExtraCarColours(Vehicle vehicle, ColourIndex *pColour1, ColourIndex *pColour2) { NativeInvoke::Invoke<ScriptVoid>("GET_EXTRA_CAR_COLOURS", vehicle, pColour1, pColour2); }
    static f32 GetHeightOfVehicle(Vehicle vehicle, f32 x, f32 y, f32 z, b8 unknownTrue1, b8 unknownTrue2) { return NativeInvoke::Invoke<f32>("GET_HEIGHT_OF_VEHICLE", vehicle, x, y, z, unknownTrue1, unknownTrue2); }
    static void GetKeyForCarInRoom(Vehicle vehicle, u32 *pKey) { NativeInvoke::Invoke<ScriptVoid>("GET_KEY_FOR_CAR_IN_ROOM", vehicle, pKey); }
    static void GetMaximumNumberOfPassengers(Vehicle vehicle, u32 *pMax) { NativeInvoke::Invoke<ScriptVoid>("GET_MAXIMUM_NUMBER_OF_PASSENGERS", vehicle, pMax); }
    static void GetNearestCableCar(f32 x, f32 y, f32 z, f32 radius, Vehicle *pVehicle) { NativeInvoke::Invoke<ScriptVoid>("GET_NEAREST_CABLE_CAR", x, y, z, radius, pVehicle); }
    static void GetNumCarColours(Vehicle vehicle, u32 *pNumColours) { NativeInvoke::Invoke<ScriptVoid>("GET_NUM_CAR_COLOURS", vehicle, pNumColours); }
    static void GetNumberOfPassengers(Vehicle vehicle, u32 *pNumPassengers) { NativeInvoke::Invoke<ScriptVoid>("GET_NUMBER_OF_PASSENGERS", vehicle, pNumPassengers); }
    static void GetOffsetFromCarGivenWorldCoords(Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_CAR_GIVEN_WORLD_COORDS", vehicle, x, y, z, pOffX, pOffY, pOffZ); }
    static void GetOffsetFromCarInWorldCoords(Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_CAR_IN_WORLD_COORDS", vehicle, x, y, z, pOffX, pOffY, pOffZ); }
    static f32 GetPetrolTankHealth(Vehicle vehicle) { return NativeInvoke::Invoke<f32>("GET_PETROL_TANK_HEALTH", vehicle); }
    static void GetRandomCarModelInMemory(b8 unknownTrue, u32 *pHash, ScriptAny *pUnknown) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CAR_MODEL_IN_MEMORY", unknownTrue, pHash, pUnknown); }
    static void GetVehicleDirtLevel(Vehicle vehicle, f32* pIntensity) { NativeInvoke::Invoke<ScriptVoid>("GET_VEHICLE_DIRT_LEVEL", vehicle, pIntensity); }
    static b8 HasCarBeenDamagedByCar(Vehicle vehicle, Vehicle otherCar) { return NativeInvoke::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_CAR", vehicle, otherCar); }
    static b8 HasCarBeenDamagedByChar(Vehicle vehicle, Ped ped) { return NativeInvoke::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_CHAR", vehicle, ped); }
    static b8 HasCarBeenDamagedByWeapon(Vehicle vehicle, eWeapon weapon) { return NativeInvoke::Invoke<b8>("HAS_CAR_BEEN_DAMAGED_BY_WEAPON", vehicle, weapon); }
    static b8 HasCarBeenResprayed(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("HAS_CAR_BEEN_RESPRAYED", vehicle); }
    static b8 IsBigVehicle(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_BIG_VEHICLE", vehicle); }
    static b8 IsCarAMissionCar(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_A_MISSION_CAR", vehicle); }
    static b8 IsCarAttached(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_ATTACHED", vehicle); }
    static b8 IsCarDead(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_DEAD", vehicle); }
    static b8 IsCarDoorDamaged(Vehicle vehicle, eVehicleDoor door) { return NativeInvoke::Invoke<b8>("IS_CAR_DOOR_DAMAGED", vehicle, door); }
    static b8 IsCarDoorFullyOpen(Vehicle vehicle, eVehicleDoor door) { return NativeInvoke::Invoke<b8>("IS_CAR_DOOR_FULLY_OPEN", vehicle, door); }
    static b8 IsCarInAirProper(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_IN_AIR_PROPER", vehicle); }
    static b8 IsCarInArea2D(Vehicle vehicle, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CAR_IN_AREA_2D", vehicle, x1, y1, x2, y2, unknownFalse); }
    static b8 IsCarInArea3D(Vehicle vehicle, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CAR_IN_AREA_3D", vehicle, x1, y1, z1, x2, y2, z2, unknownFalse); }
    static b8 IsCarInWater(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_IN_WATER", vehicle); }
    static b8 IsCarModel(Vehicle vehicle, eModel model) { return NativeInvoke::Invoke<b8>("IS_CAR_MODEL", vehicle, model); }
    static b8 IsCarOnFire(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_ON_FIRE", vehicle); }
    static b8 IsCarOnScreen(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_ON_SCREEN", vehicle); }
    static b8 IsCarPassengerSeatFree(Vehicle vehicle, u32 seatIndex) { return NativeInvoke::Invoke<b8>("IS_CAR_PASSENGER_SEAT_FREE", vehicle, seatIndex); }
    static b8 IsCarSirenOn(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_SIREN_ON", vehicle); }
    static b8 IsCarStopped(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_STOPPED", vehicle); }
    static b8 IsCarStoppedAtTrafficLights(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_STOPPED_AT_TRAFFIC_LIGHTS", vehicle); }
    static b8 IsCarStuckOnRoof(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_STUCK_ON_ROOF", vehicle); }
    static b8 IsCarTouchingCar(Vehicle vehicle, Vehicle otherCar) { return NativeInvoke::Invoke<b8>("IS_CAR_TOUCHING_CAR", vehicle, otherCar); }
    static b8 IsCarTyreBurst(Vehicle vehicle, eVehicleTyre tyre) { return NativeInvoke::Invoke<b8>("IS_CAR_TYRE_BURST", vehicle, tyre); }
    static b8 IsCarUpright(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_UPRIGHT", vehicle); }
    static b8 IsCarUpsidedown(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_UPSIDEDOWN", vehicle); }
    static b8 IsCarWaitingForWorldCollision(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_WAITING_FOR_WORLD_COLLISION", vehicle); }
    static b8 IsVehDriveable(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_VEH_DRIVEABLE", vehicle); }
    static b8 IsVehWindowIntact(Vehicle vehicle, eVehicleWindow window) { return NativeInvoke::Invoke<b8>("IS_VEH_WINDOW_INTACT", vehicle, window); }
    static b8 IsVehicleExtraTurnedOn(Vehicle vehicle, eVehicleExtra extra) { return NativeInvoke::Invoke<b8>("IS_VEHICLE_EXTRA_TURNED_ON", vehicle, extra); }
    static b8 IsVehicleOnAllWheels(Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_VEHICLE_ON_ALL_WHEELS", vehicle); }
    static void KnockPedOffBike(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("KNOCK_PED_OFF_BIKE", vehicle); }
    static void LockCarDoors(Vehicle vehicle, eVehicleDoorLock value) { NativeInvoke::Invoke<ScriptVoid>("LOCK_CAR_DOORS", vehicle, value); }
    static void MarkCarAsConvoyCar(Vehicle vehicle, b8 convoyCar) { NativeInvoke::Invoke<ScriptVoid>("MARK_CAR_AS_CONVOY_CAR", vehicle, convoyCar); }
    static void MarkCarAsNoLongerNeeded(Vehicle *pVehicle) { NativeInvoke::Invoke<ScriptVoid>("MARK_CAR_AS_NO_LONGER_NEEDED", pVehicle); }
    static void OpenCarDoor(Vehicle vehicle, eVehicleDoor door) { NativeInvoke::Invoke<ScriptVoid>("OPEN_CAR_DOOR", vehicle, door); }
    static void PopCarBoot(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("POP_CAR_BOOT", vehicle); }
    static void RemoveVehicleWindow(Vehicle vehicle, eVehicleWindow window) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CAR_WINDOW", vehicle, window); }
    static void RemoveStuckCarCheck(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_STUCK_CAR_CHECK", vehicle); }
    static void RemoveUpsidedownCarCheck(Vehicle vehicle) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_UPSIDEDOWN_CAR_CHECK", vehicle); }
    static void SetCarCoordinates(Vehicle vehicle, f32 pX, f32 pY, f32 pZ) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_COORDINATES", vehicle, pX, pY, pZ); }
    static void SetCarHealth(Vehicle vehicle, u32 pValue) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_HEALTH", vehicle, pValue); }
    static void SetPetrolTankHealth(Vehicle vehicle, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PETROL_TANK_HEALTH", vehicle, value); }
    static void SetCarCanBeDamaged(Vehicle vehicle, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_CAN_BE_DAMAGED", vehicle, value); }
    static void SetCarCanBeVisiblyDamaged(Vehicle vehicle, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_CAN_BE_VISIBLY_DAMAGED", vehicle, value); }
    static void SetCarForwardSpeed(Vehicle vehicle, f32 speed) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_FORWARD_SPEED", vehicle, speed); }
    static void SetCarHeading(Vehicle vehicle, f32 dir) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_HEADING", vehicle, dir); }
    static ScriptAny SetCarOnGroundProperly(Vehicle vehicle) { return NativeInvoke::Invoke<ScriptAny>("SET_CAR_ON_GROUND_PROPERLY", vehicle); }
    static void SetCarProofs(Vehicle vehicle, b8 bulletProof, b8 fireProof, b8 explosionProof, b8 collisionProof, b8 meleeProof) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_PROOFS", vehicle, bulletProof, fireProof, explosionProof, collisionProof, meleeProof); }
    static void SetCarStrong(Vehicle vehicle, b8 strong) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_STRONG", vehicle, strong); }
    static void SetCarVisible(Vehicle vehicle, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_VISIBLE", vehicle, value); }
    static void SetExtraCarColours(Vehicle vehicle, ColourIndex colour1, ColourIndex colour2) { NativeInvoke::Invoke<ScriptVoid>("SET_EXTRA_CAR_COLOURS", vehicle, colour1, colour2); }
    static void SetEngineHealth(Vehicle vehicle, f32 health) { NativeInvoke::Invoke<ScriptVoid>("SET_ENGINE_HEALTH", vehicle, health); }
    static void SetVehHazardLights(Vehicle vehicle, b8 on) { NativeInvoke::Invoke<ScriptVoid>("SET_VEH_HAZARDLIGHTS", vehicle, on); }
    static void SetVehicleDirtLevel(Vehicle vehicle, f32 intensity) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_DIRT_LEVEL", vehicle, intensity); }
    static void ShutCarDoor(Vehicle vehicle, eVehicleDoor door) { NativeInvoke::Invoke<ScriptVoid>("SHUT_CAR_DOOR", vehicle, door); }
    static void SoundCarHorn(Vehicle vehicle, u32 duration) { NativeInvoke::Invoke<ScriptVoid>("SOUND_CAR_HORN", vehicle, duration); }
    static void WashVehicleTextures(Vehicle vehicle, u32 intensity) { NativeInvoke::Invoke<ScriptVoid>("WASH_VEHICLE_TEXTURES", vehicle, intensity); }

    // Train
    static void CreateMissionTrain(u32 unknown1, f32 x, f32 y, f32 z, b8 unknown2, Train *pTrain) { NativeInvoke::Invoke<ScriptVoid>("CREATE_MISSION_TRAIN", unknown1, x, y, z, unknown2, pTrain); }
    static void DeleteMissionTrain(Train *pTrain) { NativeInvoke::Invoke<ScriptVoid>("DELETE_MISSION_TRAIN", pTrain); }
    static eTrainStation GetCurrentStationForTrain(Train train) { return NativeInvoke::Invoke<eTrainStation>("GET_CURRENT_STATION_FOR_TRAIN", train); }
    static eTrainStation GetNextStationForTrain(Train train) { return NativeInvoke::Invoke<eTrainStation>("GET_NEXT_STATION_FOR_TRAIN", train); }
    static const ch *GetStationName(Train train, eTrainStation station) { return NativeInvoke::Invoke<const ch *>("GET_STATION_NAME", train, station); }
    static void MarkMissionTrainAsNoLongerNeeded(Train train) { NativeInvoke::Invoke<ScriptVoid>("MARK_MISSION_TRAIN_AS_NO_LONGER_NEEDED", train); }
    static void MarkMissionTrainsAsNoLongerNeeded() { NativeInvoke::Invoke<ScriptVoid>("MARK_MISSION_TRAINS_AS_NO_LONGER_NEEDED"); }

    // Object
    static void AddObjectToInteriorRoomByKey(Object obj, eInteriorRoomKey roomKey) { NativeInvoke::Invoke<ScriptVoid>("ADD_OBJECT_TO_INTERIOR_ROOM_BY_KEY", obj, roomKey); }
    static void ApplyForceToObject(Object obj, u32 uk0_3, f32 pX, f32 pY, f32 pZ, f32 spinX, f32 spinY, f32 spinZ, u32 uk4_0, u32 uk5_1, u32 uk6_1, u32 uk7_1) { NativeInvoke::Invoke<ScriptVoid>("APPLY_FORCE_TO_OBJECT", obj, uk0_3, pX, pY, pZ, spinX, spinY, spinZ, uk4_0, uk5_1, uk6_1, uk7_1); }
    static void AttachObjectToCar(Object obj, Vehicle v, u32 unknown0_0, f32 pX, f32 pY, f32 pZ, f32 rX, f32 rY, f32 rZ) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_CAR", obj, v, unknown0_0, pX, pY, pZ, rX, rY, rZ); }
    static void AttachObjectToPed(Object obj, Ped c, ePedBone bone, f32 pX, f32 pY, f32 pZ, f32 rX, f32 rY, f32 rZ, u32 unknown1_0) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_PED", obj, c, bone, pX, pY, pZ, rX, rY, rZ, unknown1_0); }
    static void ClearObjectLastDamageEntity(Object obj) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_OBJECT_LAST_DAMAGE_ENTITY", obj); }
    static void ClearRoomForObject(Object obj) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_OBJECT", obj); }
    static void CreateObject(eModel model, f32 x, f32 y, f32 z, Object *pObj, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_OBJECT", model, x, y, z, pObj, unknownTrue); }
    static void CreateObjectNoOffset(eModel model, f32 x, f32 y, f32 z, Object *pObj, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_OBJECT_NO_OFFSET", model, x, y, z, pObj, unknownTrue); }
    static void DeleteObject(Object *pObj) { NativeInvoke::Invoke<ScriptVoid>("DELETE_OBJECT", pObj); }
    static void DetachObject(Object obj, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DETACH_OBJECT", obj, unknown); }
    static b8 DoesObjectExist(Object obj) { return NativeInvoke::Invoke<b8>("DOES_OBJECT_EXIST", obj); }
    static b8 DoesObjectHavePhysics(Object obj) { return NativeInvoke::Invoke<b8>("DOES_OBJECT_HAVE_PHYSICS", obj); }
    static b8 DoesObjectOfTypeExistAtCoords(f32 x, f32 y, f32 z, f32 radius, eModel model) { return NativeInvoke::Invoke<b8>("DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS", x, y, z, radius, model); }
    static void ExtinguishObjectFire(Object obj) { NativeInvoke::Invoke<ScriptVoid>("EXTINGUISH_OBJECT_FIRE", obj); }
    static void FreezeObjectPosition(Object obj, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_OBJECT_POSITION", obj, frozen); }
    static Vehicle GetCarObjectIsAttachedTo(Object obj) { return NativeInvoke::Invoke<Vehicle>("GET_CAR_OBJECT_IS_ATTACHED_TO", obj); }
    static void GetObjectCoordinates(Object obj, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_COORDINATES", obj, pX, pY, pZ); }
    static f32 GetObjectFragmentDamageHealth(Object obj, b8 unknown) { return NativeInvoke::Invoke<f32>("GET_OBJECT_FRAGMENT_DAMAGE_HEALTH", obj, unknown); }
    static void GetObjectHeading(Object obj, f32 *pHeading) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_HEADING", obj, pHeading); }
    static void GetObjectHealth(Object obj, f32 *pHealth) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_HEALTH", obj, pHealth); }
    static void GetObjectModel(Object obj, eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_MODEL", obj, pModel); }
    static void GetObjectRotationVelocity(Object obj, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_ROTATION_VELOCITY", obj, pX, pY, pZ); }
    static void GetObjectSpeed(Object obj, f32 *pSpeed) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_SPEED", obj, pSpeed); }
    static void GetObjectVelocity(Object obj, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_VELOCITY", obj, pX, pY, pZ); }
    static void GetOffsetFromObjectInWorldCoords(Object obj, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_OBJECT_IN_WORLD_COORDS", obj, x, y, z, pOffX, pOffY, pOffZ); }
    static Ped GetPedObjectIsAttachedTo(Object obj) { return NativeInvoke::Invoke<Ped>("GET_PED_OBJECT_IS_ATTACHED_TO", obj); }
    static b8 HasObjectBeenDamaged(Object obj) { return NativeInvoke::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED", obj); }
    static b8 HasObjectBeenDamagedByCar(Object obj, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED_BY_CAR", obj, vehicle); }
    static b8 HasObjectBeenDamagedByChar(Object obj, Ped ped) { return NativeInvoke::Invoke<b8>("HAS_OBJECT_BEEN_DAMAGED_BY_CHAR", obj, ped); }
    static b8 HasObjectBeenUprooted(Object obj) { return NativeInvoke::Invoke<b8>("HAS_OBJECT_BEEN_UPROOTED", obj); }
    static b8 HasObjectCollidedWithAnything(Object obj) { return NativeInvoke::Invoke<b8>("HAS_OBJECT_COLLIDED_WITH_ANYTHING", obj); }
    static b8 HasPoolObjectCollidedWithCushion(Object obj) { return NativeInvoke::Invoke<b8>("HAS_POOL_OBJECT_COLLIDED_WITH_CUSHION", obj); }
    static b8 HasPoolObjectCollidedWithObject(Object obj, Object otherObj) { return NativeInvoke::Invoke<b8>("HAS_POOL_OBJECT_COLLIDED_WITH_OBJECT", obj, otherObj); }
    static b8 IsObjectAttached(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_ATTACHED", obj); }
    static b8 IsObjectInWater(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_IN_WATER", obj); }
    static b8 IsObjectOnFire(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_ON_FIRE", obj); }
    static b8 IsObjectOnScreen(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_ON_SCREEN", obj); }
    static b8 IsObjectStatic(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_STATIC", obj); }
    static b8 IsObjectUpright(Object obj, f32 angle) { return NativeInvoke::Invoke<b8>("IS_OBJECT_UPRIGHT", obj, angle); }
    static b8 IsObjectWithinBrainActivationRange(Object obj) { return NativeInvoke::Invoke<b8>("IS_OBJECT_WITHIN_BRAIN_ACTIVATION_RANGE", obj); }
    static void LoadAllObjectsNow() { NativeInvoke::Invoke<ScriptVoid>("LOAD_ALL_OBJECTS_NOW"); }
    static void MakeObjectTargettable(Object obj, b8 targettable) { NativeInvoke::Invoke<ScriptVoid>("MAKE_OBJECT_TARGETTABLE", obj, targettable); }
    static void MarkObjectAsNoLongerNeeded(Object *pObj) { NativeInvoke::Invoke<ScriptVoid>("MARK_OBJECT_AS_NO_LONGER_NEEDED", pObj); }
    static void SetObjectCollision(Object obj, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_COLLISION", obj, value); }
    static void SetObjectCoordinates(Object obj, f32 pX, f32 pY, f32 pZ) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_COORDINATES", obj, pX, pY, pZ); }
    static void SetObjectHeading(Object obj, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_HEADING", obj, value); }
    static void SetObjectVisible(Object obj, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_VISIBLE", obj, value); }
    static ScriptAny StartObjectFire(Object obj) { return NativeInvoke::Invoke<ScriptAny>("START_OBJECT_FIRE", obj); }

    // Models
    static b8 HasModelLoaded(eModel model) { return NativeInvoke::Invoke<b8>("HAS_MODEL_LOADED", model); }
    static void RequestModel(eModel model) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_MODEL", model); }
    static void GetCurrentBasicCopModel(eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_BASIC_COP_MODEL", pModel); }
    static void GetCurrentBasicPoliceCarModel(eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_BASIC_POLICE_CAR_MODEL", pModel); }
    static void GetCurrentCopModel(eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_COP_MODEL", pModel); }
    static void GetCurrentPoliceCarModel(eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_POLICE_CAR_MODEL", pModel); }
    static void GetCurrentTaxiCarModel(eModel *pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_TAXI_CAR_MODEL", pModel); }
    static const ch *GetDisplayNameFromVehicleModel(eModel model) { return NativeInvoke::Invoke<const ch *>("GET_DISPLAY_NAME_FROM_VEHICLE_MODEL", model); }
    static void GetModelDimensions(eModel model, Vector3 *pMinVector, Vector3 *pMaxVector) { NativeInvoke::Invoke<ScriptVoid>("GET_MODEL_DIMENSIONS", model, pMinVector, pMaxVector); }
    static const ch *GetModelNameForDebug(eModel model) { return NativeInvoke::Invoke<const ch *>("GET_MODEL_NAME_FOR_DEBUG", model); }
    static b8 IsThisModelABike(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_BIKE", model); }
    static b8 IsThisModelABoat(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_BOAT", model); }
    static b8 IsThisModelACar(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_CAR", model); }
    static b8 IsThisModelAHeli(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_HELI", model); }
    static b8 IsThisModelAPed(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_PED", model); }
    static b8 IsThisModelAPlane(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_PLANE", model); }
    static b8 IsThisModelATrain(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_TRAIN", model); }
    static b8 IsThisModelAVehicle(eModel model) { return NativeInvoke::Invoke<b8>("IS_THIS_MODEL_A_VEHICLE", model); }
    static void MarkModelAsNoLongerNeeded(eModel model) { NativeInvoke::Invoke<ScriptVoid>("MARK_MODEL_AS_NO_LONGER_NEEDED", model); }

    // Interiors
    static void ActivateInterior(Interior interior, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_INTERIOR", interior, unknownTrue); }
    static void GetInteriorAtCoords(f32 x, f32 y, f32 z, Interior *pInterior) { NativeInvoke::Invoke<ScriptVoid>("GET_INTERIOR_AT_COORDS", x, y, z, pInterior); }
    static void GetInteriorFromCar(Vehicle vehicle, Interior *pInterior) { NativeInvoke::Invoke<ScriptVoid>("GET_INTERIOR_FROM_CAR", vehicle, pInterior); }
    static void GetInteriorFromChar(Ped ped, Interior *pInterior) { NativeInvoke::Invoke<ScriptVoid>("GET_INTERIOR_FROM_CHAR", ped, pInterior); }
    static void GetInteriorHeading(Interior interior, f32 *pHeading) { NativeInvoke::Invoke<ScriptVoid>("GET_INTERIOR_HEADING", interior, pHeading); }
    static void GetOffsetFromInteriorInWorldCoords(Interior interior, f32 x, f32 y, f32 z, f32 *pOffset) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_INTERIOR_IN_WORLD_COORDS", interior, x, y, z, pOffset); }
    static void GetRoomKeyFromObject(Object obj, eInteriorRoomKey *pRoomKey) { NativeInvoke::Invoke<ScriptVoid>("GET_ROOM_KEY_FROM_OBJECT", obj, pRoomKey); }
    static void RequestInteriorModels(eModel model, const ch *interiorName) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_INTERIOR_MODELS", model, interiorName); }

    // Decision Maker
    static void AddCharDecisionMakerEventResponse(DecisionMaker dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { NativeInvoke::Invoke<ScriptVoid>("ADD_CHAR_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
    static void AddCombatDecisionMakerEventResponse(DecisionMaker dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { NativeInvoke::Invoke<ScriptVoid>("ADD_COMBAT_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
    static void AddGroupDecisionMakerEventResponse(DecisionMaker dm, u32 eventid, u32 responseid, f32 param1, f32 param2, f32 param3, f32 param4, u32 unknown0_1, u32 unknown1_1) { NativeInvoke::Invoke<ScriptVoid>("ADD_GROUP_DECISION_MAKER_EVENT_RESPONSE", dm, eventid, responseid, param1, param2, param3, param4, unknown0_1, unknown1_1); }
    static void ClearCharDecisionMakerEventResponse(DecisionMaker dm, u32 eventid) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
    static void ClearCombatDecisionMakerEventResponse(DecisionMaker dm, u32 eventid) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_COMBAT_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
    static void ClearGroupDecisionMakerEventResponse(DecisionMaker dm, u32 eventid) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_GROUP_DECISION_MAKER_EVENT_RESPONSE", dm, eventid); }
    static void CopyCharDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_CHAR_DECISION_MAKER", type, pDM); }
    static void CopyCombatDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_COMBAT_DECISION_MAKER", type, pDM); }
    static void CopyGroupCharDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_GROUP_CHAR_DECISION_MAKER", type, pDM); }
    static void CopyGroupCombatDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_GROUP_COMBAT_DECISION_MAKER", type, pDM); }
    static void CopySharedCharDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_SHARED_CHAR_DECISION_MAKER", type, pDM); }
    static void CopySharedCombatDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("COPY_SHARED_COMBAT_DECISION_MAKER", type, pDM); }
    static b8 DoesDecisionMakerExist(DecisionMaker dm) { return NativeInvoke::Invoke<b8>("DOES_DECISION_MAKER_EXIST", dm); }
    static void LoadCharDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("LOAD_CHAR_DECISION_MAKER", type, pDM); }
    static void LoadCombatDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("LOAD_COMBAT_DECISION_MAKER", type, pDM); }
    static void LoadGroupDecisionMaker(u32 type, DecisionMaker *pDM) { NativeInvoke::Invoke<ScriptVoid>("LOAD_GROUP_DECISION_MAKER", type, pDM); }
    static void RemoveDecisionMaker(DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_DECISION_MAKER", dm); }
    static void SetCharDecisionMaker(Ped ped, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DECISION_MAKER", ped, dm); }
    static void SetCharDecisionMakerToDefault(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DECISION_MAKER_TO_DEFAULT", ped); }
    static void SetCombatDecisionMaker(Ped ped, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("SET_COMBAT_DECISION_MAKER", ped, dm); }
    static void SetDecisionMakerAttributeCanChangeTarget(DecisionMaker dm, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_CAN_CHANGE_TARGET", dm, value); }
    static void SetDecisionMakerAttributeCaution(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_CAUTION", dm, value); }
    static void SetDecisionMakerAttributeFireRate(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_FIRE_RATE", dm, value); }
    static void SetDecisionMakerAttributeLowHealth(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_LOW_HEALTH", dm, value); }
    static void SetDecisionMakerAttributeMovementStyle(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_MOVEMENT_STYLE", dm, value); }
    static void SetDecisionMakerAttributeNavigationStyle(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_NAVIGATION_STYLE", dm, value); }
    static void SetDecisionMakerAttributeRetreatingBehaviour(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_RETREATING_BEHAVIOUR", dm, value); }
    static void SetDecisionMakerAttributeSightRange(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_SIGHT_RANGE", dm, value); }
    static void SetDecisionMakerAttributeStandingStyle(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_STANDING_STYLE", dm, value); }
    static void SetDecisionMakerAttributeTargetInjuredReaction(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TARGET_INJURED_REACTION", dm, value); }
    static void SetDecisionMakerAttributeTargetLossResponse(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TARGET_LOSS_RESPONSE", dm, value); }
    static void SetDecisionMakerAttributeTeamwork(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_TEAMWORK", dm, value); }
    static void SetDecisionMakerAttributeWeaponAccuracy(DecisionMaker dm, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_DECISION_MAKER_ATTRIBUTE_WEAPON_ACCURACY", dm, value); }
    static void SetGroupCharDecisionMaker(Group group, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_CHAR_DECISION_MAKER", group, dm); }
    static void SetGroupCombatDecisionMaker(Group group, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_COMBAT_DECISION_MAKER", group, dm); }
    static void SetGroupDecisionMaker(Group group, DecisionMaker dm) { NativeInvoke::Invoke<ScriptVoid>("SET_GROUP_DECISION_MAKER", group, dm); }

    // Blips
    static void AddBlipForCar(Vehicle vehicle, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_CAR", vehicle, pBlip); }
    static void AddBlipForChar(Ped ped, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_CHAR", ped, pBlip); }
    static void AddBlipForContact(f32 x, f32 y, f32 z, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_CONTACT", x, y, z, pBlip); }
    static void AddBlipForCoord(f32 x, f32 y, f32 z, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_COORD", x, y, z, pBlip); }
    static void AddBlipForObject(Object obj, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_OBJECT", obj, pBlip); }
    static void AddBlipForPickup(Pickup pickup, Blip *pBlip) { NativeInvoke::Invoke<ScriptVoid>("ADD_BLIP_FOR_PICKUP", pickup, pBlip); }
    static void AddSimpleBlipForPickup(Pickup pickup) { NativeInvoke::Invoke<ScriptVoid>("ADD_SIMPLE_BLIP_FOR_PICKUP", pickup); }
    static void ChangeBlipAlpha(Blip blip, ScriptAny alpha) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_ALPHA", blip, alpha); }
    static void ChangeBlipColour(Blip blip, ColourIndex colour) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_COLOUR", blip, colour); }
    static void ChangeBlipDisplay(Blip blip, eBlipDisplay display) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_DISPLAY", blip, display); }
    static void ChangeBlipNameFromAscii(Blip blip, const ch *blipName) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_NAME_FROM_ASCII", blip, blipName); }
    static void ChangeBlipNameFromTextFile(Blip blip, const ch *gxtName) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_NAME_FROM_TEXT_FILE", blip, gxtName); }
    static void ChangeBlipPriority(Blip blip, eBlipPriority priority) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_PRIORITY", blip, priority); }
    static void ChangeBlipScale(Blip blip, f32 scale) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_SCALE", blip, scale); }
    static void ChangeBlipSprite(Blip blip, eBlipSprite sprite) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_BLIP_SPRITE", blip, sprite); }
    static void DimBlip(Blip blip, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("DIM_BLIP", blip, unknownTrue); }
    static b8 DoesBlipExist(Blip blip) { return NativeInvoke::Invoke<b8>("DOES_BLIP_EXIST", blip); }
    static void FlashBlip(Blip blip, b8 on) { NativeInvoke::Invoke<ScriptVoid>("FLASH_BLIP", blip, on); }
    static void FlashBlipAlt(Blip blip, b8 on) { NativeInvoke::Invoke<ScriptVoid>("FLASH_BLIP_ALT", blip, on); }
    static void GetBlipColour(Blip blip, ColourIndex *pColour) { NativeInvoke::Invoke<ScriptVoid>("GET_BLIP_COLOUR", blip, pColour); }
    static void GetBlipCoords(Blip blip, Vector3 *pVector) { NativeInvoke::Invoke<ScriptVoid>("GET_BLIP_COORDS", blip, pVector); }
    static eBlipType GetBlipInfoIdType(Blip blip) { return NativeInvoke::Invoke<eBlipType>("GET_BLIP_INFO_ID_TYPE", blip); }
    static Vehicle GetBlipInfoIdCarIndex(Blip blip) { return NativeInvoke::Invoke<Vehicle>("GET_BLIP_INFO_ID_CAR_INDEX", blip); }
    static u32 GetBlipInfoIdDisplay(Blip blip) { return NativeInvoke::Invoke<b8>("GET_BLIP_INFO_ID_DISPLAY", blip); }
    static Object GetBlipInfoIdObjectIndex(Blip blip) { return NativeInvoke::Invoke<Object>("GET_BLIP_INFO_ID_OBJECT_INDEX", blip); }
    static Ped GetBlipInfoIdPedIndex(Blip blip) { return NativeInvoke::Invoke<Ped>("GET_BLIP_INFO_ID_PED_INDEX", blip); }
    static Pickup GetBlipInfoIdPickupIndex(Blip blip) { return NativeInvoke::Invoke<Pickup>("GET_BLIP_INFO_ID_PICKUP_INDEX", blip); }
    static const ch *GetBlipName(Blip blip) { return NativeInvoke::Invoke<const ch *>("GET_BLIP_NAME", blip); }
    static eBlipSprite GetBlipSprite(Blip blip) { return NativeInvoke::Invoke<eBlipSprite>("GET_BLIP_SPRITE", blip); }
    static Blip GetFirstBlipInfoId(eBlipSprite type) { return NativeInvoke::Invoke<Blip>("GET_FIRST_BLIP_INFO_ID", type); }
    static Blip GetNextBlipInfoId(eBlipSprite type) { return NativeInvoke::Invoke<Blip>("GET_NEXT_BLIP_INFO_ID", type); }
    static b8 IsBlipShortRange(Blip blip) { return NativeInvoke::Invoke<b8>("IS_BLIP_SHORT_RANGE", blip); }
    static void RemoveBlip(Blip blip) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_BLIP", blip); }
    static void SetBlipAsFriendly(Blip blip, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_BLIP_AS_FRIENDLY", blip, value); }
    static void SetBlipAsShortRange(Blip blip, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_BLIP_AS_SHORT_RANGE", blip, value); }
    static void SetRoute(Blip blip, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_ROUTE", blip, value); }

    // Pickups
    static void AddPickupToInteriorRoomByName(Pickup pickup, const ch *roomName) { NativeInvoke::Invoke<ScriptVoid>("ADD_PICKUP_TO_INTERIOR_ROOM_BY_NAME", pickup, roomName); }
    static void CreateMoneyPickup(f32 x, f32 y, f32 z, u32 amount, b8 unknownTrue, Pickup *pPickup) { NativeInvoke::Invoke<ScriptVoid>("CREATE_MONEY_PICKUP", x, y, z, amount, unknownTrue, pPickup); }
    static void CreatePickup(eModel model, ePickupType pickupType, f32 x, f32 y, f32 z, Pickup *pPickup, b8 unknownFalse) { NativeInvoke::Invoke<ScriptVoid>("CREATE_PICKUP", model, pickupType, x, y, z, pPickup, unknownFalse); }
    static void CreatePickupRotate(eModel model, ePickupType pickupType, u32 unknown, f32 x, f32 y, f32 z, f32 rX, f32 rY, f32 rZ, Pickup *pPickup) { NativeInvoke::Invoke<ScriptVoid>("CREATE_PICKUP_ROTATE", model, pickupType, unknown, x, y, z, rX, rY, rZ, pPickup); }
    static void CreatePickupWithAmmo(eModel model, ePickupType pickupType, u32 unknown, f32 x, f32 y, f32 z, Pickup *pPickup) { NativeInvoke::Invoke<ScriptVoid>("CREATE_PICKUP_WITH_AMMO", model, pickupType, unknown, x, y, z, pPickup); }
    static b8 DoesPickupExist(Pickup pickup) { return NativeInvoke::Invoke<b8>("DOES_PICKUP_EXIST", pickup); }
    static void GetPickupCoordinates(Pickup pickup, f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_PICKUP_COORDINATES", pickup, pX, pY, pZ); }
    static b8 HasPickupBeenCollected(Pickup pickup) { return NativeInvoke::Invoke<b8>("HAS_PICKUP_BEEN_COLLECTED", pickup); }
    static void PickupsPassTime(u32 time) { NativeInvoke::Invoke<ScriptVoid>("PICKUPS_PASS_TIME", time); }
    static void RemovePickup(Pickup pickup) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PICKUP", pickup); }
    static void RemoveTemporaryRadarBlipsForPickups() { NativeInvoke::Invoke<ScriptVoid>("REMOVE_TEMPORARY_RADAR_BLIPS_FOR_PICKUPS"); }

    // Camera
    static b8 CamIsSphereVisible(Camera camera, f32 pX, f32 pY, f32 pZ, f32 radius) { return NativeInvoke::Invoke<b8>("CAM_IS_SPHERE_VISIBLE", camera, pX, pY, pZ, radius); }
    static void CreateCam(u32 camtype_usually14, Camera *camera) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CAM", camtype_usually14, camera); }
    static void DestroyCam(Camera camera) { NativeInvoke::Invoke<ScriptVoid>("DESTROY_CAM", camera); }
    static b8 DoesCamExist(Camera camera) { return NativeInvoke::Invoke<b8>("DOES_CAM_EXIST", camera); }
    static void SetCamActive(Camera camera, bool value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_ACTIVE", camera, value); }
    static void GetCamFov(Camera camera, f32 *fov) { NativeInvoke::Invoke<ScriptVoid>("GET_CAM_FOV", camera, fov); }
    static void GetCamPos(Camera camera,  f32 *pX, f32 *pY, f32 *pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CAM_POS", camera, pX, pY, pZ); }
    static void GetCamRot(Camera camera, f32 *angleX, f32 *angleY, f32 *angleZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CAM_ROT", camera, angleX, angleY, angleZ); }
    static void GetGameCam(Camera *camera) { NativeInvoke::Invoke<ScriptVoid>("GET_GAME_CAM", camera); }
    static void GetGameCamChild(Camera *camera) { NativeInvoke::Invoke<ScriptVoid>("GET_GAME_CAM_CHILD", camera); }
    static bool IsCamActive(Camera camera) { return NativeInvoke::Invoke<bool>("IS_CAM_ACTIVE", camera); }
    static bool IsCamInterpolating() { return NativeInvoke::Invoke<bool>("IS_CAM_INTERPOLATING"); }
    static bool IsCamPropagating(Camera camera) { return NativeInvoke::Invoke<bool>("IS_CAM_PROPAGATING", camera); }
    static void SetCamBehindPed(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_BEHIND_PED", ped); }
    static void SetCamFov(Camera camera, f32 fov) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_FOV", camera, fov); }
    static void SetCamInFrontOfPed(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_IN_FRONT_OF_PED", ped); }
    static void SetCamPos(Camera camera, f32 pX, f32 pY, f32 pZ) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_POS", camera, pX, pY, pZ); }
    static void SetCamPropagate(Camera camera, bool value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_PROPAGATE", camera, value); }
    static void SetCamRot(Camera camera, f32 angleX, f32 angleY, f32 angleZ) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_ROT", camera, angleX, angleY, angleZ); }
    static void SetCamTargetPed(Camera camera, Ped ped) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_TARGET_PED", camera, ped); }

    // Network
    static b8 NetworkIsGameRanked() { return NativeInvoke::Invoke<b8>("NETWORK_IS_GAME_RANKED"); }
    static b8 NetworkIsSessionStarted() { return NativeInvoke::Invoke<b8>("NETWORK_IS_SESSION_STARTED"); }

    // World
    static b8 AreAllNavmeshRegionsLoaded() { return NativeInvoke::Invoke<b8>("ARE_ALL_NAVMESH_REGIONS_LOADED"); }
    static void ClearArea(f32 x, f32 y, f32 z, f32 radius, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_AREA", x, y, z, radius, unknown); }
    static void ClearAreaOfCars(f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_AREA_OF_CARS", x, y, z, radius); }
    static void ClearAreaOfChars(f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_AREA_OF_CHARS", x, y, z, radius); }
    static void ClearAreaOfCops(f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_AREA_OF_COPS", x, y, z, radius); }
    static void ClearAreaOfObjects(f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_AREA_OF_OBJECTS", x, y, z, radius); }
    static void ClearPedNonCreationArea() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_PED_NON_CREATION_AREA"); }
    static void ClearPedNonRemovalArea() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_PED_NON_REMOVAL_AREA"); }
    static void ExtinguishFireAtPoint(f32 x, f32 y, f32 z, f32 radius) { NativeInvoke::Invoke<ScriptVoid>("EXTINGUISH_FIRE_AT_POINT", x, y, z, radius); }
    static void ForceWeather(eWeather weather) { NativeInvoke::Invoke<ScriptVoid>("FORCE_WEATHER", weather); }
    static void ForceWeatherNow(eWeather weather) { NativeInvoke::Invoke<ScriptVoid>("FORCE_WEATHER_NOW", weather); }
    static void ForceWind(f32 wind) { NativeInvoke::Invoke<ScriptVoid>("FORCE_WIND", wind); }
    static void FreezePositionOfClosestObjectOfType(f32 x, f32 y, f32 z, f32 radius, eModel model, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_POSITION_OF_CLOSEST_OBJECT_OF_TYPE", x, y, z, radius, model, frozen); }
    static Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, b8 unknownFalse, u32 unknown70) { return NativeInvoke::Invoke<Vehicle>("GET_CLOSEST_CAR", x, y, z, radius, unknownFalse, unknown70); }
    static b8 GetClosestChar(f32 x, f32 y, f32 z, f32 radius, b8 unknown1, b8 unknown2, Ped *pPed) { return NativeInvoke::Invoke<b8>("GET_CLOSEST_CHAR", x, y, z, radius, unknown1, unknown2, pPed); }
    static void GetCurrentWeather(eWeather *pWeather) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_WEATHER", pWeather); }
    static ScriptAny GetGroundZFor3DCoord(f32 x, f32 y, f32 z, f32 *pGroundZ) { return NativeInvoke::Invoke<ScriptAny>("GET_GROUND_Z_FOR_3D_COORD", x, y, z, pGroundZ); }
    static u32 GetNumberOfFiresInRange(f32 x, f32 y, f32 z, f32 radius) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_FIRES_IN_RANGE", x, y, z, radius); }
    static void GetSafePickupCoords(f32 x, f32 y, f32 z, f32 *pSafeX, f32 *pSafeY, f32 *pSafeZ) { NativeInvoke::Invoke<ScriptVoid>("GET_SAFE_PICKUP_COORDS", x, y, z, pSafeX, pSafeY, pSafeZ); }
    static b8 GetSafePositionForChar(f32 x, f32 y, f32 z, b8 unknownTrue, f32 *pSafeX, f32 *pSafeY, f32 *pSafeZ) { return NativeInvoke::Invoke<b8>("GET_SAFE_POSITION_FOR_CHAR", x, y, z, unknownTrue, pSafeX, pSafeY, pSafeZ); }
    static b8 HasClosestObjectOfTypeBeenDamagedByChar(f32 x, f32 y, f32 z, f32 radius, eModel objectModel, Ped ped) { return NativeInvoke::Invoke<b8>("HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_DAMAGED_BY_CHAR", x, y, z, radius, objectModel, ped); }
    static b8 IsAreaOccupied(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknownFalse1, b8 unknownTrue, b8 unknownFalse2, b8 unknownFalse3, b8 unknownFalse4) { return NativeInvoke::Invoke<b8>("IS_AREA_OCCUPIED", x1, y1, z1, x2, y2, z2, unknownFalse1, unknownTrue, unknownFalse2, unknownFalse3, unknownFalse4); }
    static b8 IsBulletInArea(f32 x, f32 y, f32 z, f32 radius, b8 unknownTrue) { return NativeInvoke::Invoke<b8>("IS_BULLET_IN_AREA", x, y, z, radius, unknownTrue); }
    static b8 IsBulletInBox(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknown) { return NativeInvoke::Invoke<b8>("IS_BULLET_IN_BOX", x1, y1, z1, x2, y2, z2, unknown); }
    static b8 IsPointObscuredByAMissionEntity(f32 pX, f32 pY, f32 pZ, f32 sizeX, f32 sizeY, f32 sizeZ) { return NativeInvoke::Invoke<b8>("IS_POINT_OBSCURED_BY_A_MISSION_ENTITY", pX, pY, pZ, sizeX, sizeY, sizeZ); }
    static void LoadScene(f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("LOAD_SCENE", x, y, z); }
    static void RemoveAllPickupsOfType(ePickupType type) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_ALL_PICKUPS_OF_TYPE", type); }
    static void RequestCollisionAtPosn(f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_COLLISION_AT_POSN", x, y, z); }
    static void SwitchAmbientPlanes(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_AMBIENT_PLANES", on); }	
    static void SwitchArrowAboveBlippedPickups(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_ARROW_ABOVE_BLIPPED_PICKUPS", on); }
    static void SwitchRandomBoats(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_RANDOM_BOATS", on); }
    static void SwitchRandomTrains(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_RANDOM_TRAINS", on); }
    static void SwitchGarbageTrucks(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_GARBAGE_TRUCKS", on); }
    static void SwitchMadDrivers(b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_MAD_DRIVERS", on); }

    // Garages
    static void CloseGarage(const ch *garageName) { NativeInvoke::Invoke<ScriptVoid>("CLOSE_GARAGE", garageName); }
    static b8 IsCarInGarageArea(const ch *garageName, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CAR_IN_GARAGE_AREA", garageName, vehicle); }
    static ScriptAny IsGarageClosed(const ch *garageName) { return NativeInvoke::Invoke<ScriptAny>("IS_GARAGE_CLOSED", garageName); }
    static ScriptAny IsGarageOpen(const ch *garageName) { return NativeInvoke::Invoke<ScriptAny>("IS_GARAGE_OPEN", garageName); }
    static void OpenGarage(const ch *name) { NativeInvoke::Invoke<ScriptVoid>("OPEN_GARAGE", name); }

    // Text (GXT stuff)
    static void DisplayText(f32 x, f32 y, const ch *gxtName) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT", x, y, gxtName); }
    static void DisplayTextWith2Numbers(f32 x, f32 y, const ch *gxtName, i32 number1, i32 number2) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_2_NUMBERS", x, y, gxtName, number1, number2); }
    static void DisplayTextWithFloat(f32 x, f32 y, const ch *gxtName, f32 value, u32 unknown) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_FLOAT", x, y, gxtName, value, unknown); }
    static void DisplayTextWithLiteralString(f32 x, f32 y, const ch *gxtName, const ch *literalStr) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_LITERAL_STRING", x, y, gxtName, literalStr); }
    static void DisplayTextWithNumber(f32 x, f32 y, const ch *gxtName, i32 value) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_NUMBER", x, y, gxtName, value); }
    static void DisplayTextWithString(f32 x, f32 y, const ch *gxtName, const ch *gxtStringName) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_STRING", x, y, gxtName, gxtStringName); }
    static void DisplayTextWithTwoLiteralStrings(f32 x, f32 y, const ch *gxtName, const ch *literalStr1, const ch *literalStr2) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_TWO_LITERAL_STRINGS", x, y, gxtName, literalStr1, literalStr2); }
    static void DisplayTextWithTwoStrings(f32 x, f32 y, const ch *gxtName, const ch *gxtStringName1, const ch *gxtStringName2) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_TEXT_WITH_TWO_STRINGS", x, y, gxtName, gxtStringName1, gxtStringName2); }
    static u32 GetLengthOfStringWithThisTextLabel(const ch *gxtName) { return NativeInvoke::Invoke<u32>("GET_LENGTH_OF_STRING_WITH_THIS_TEXT_LABEL", gxtName); }
    static const ch *GetFirstNCharactersOfString(const ch *gxtName, u32 chars) { return NativeInvoke::Invoke<const ch *>("GET_FIRST_N_CHARACTERS_OF_STRING", gxtName, chars); }
    static void GetMobilePhoneRenderId(u32 *pRenderId) { NativeInvoke::Invoke<ScriptVoid>("GET_MOBILE_PHONE_RENDER_ID", pRenderId); }
    static const ch *GetNthIntegerInString(const ch *gxtName, u32 index) { return NativeInvoke::Invoke<const ch *>("GET_NTH_INTEGER_IN_STRING", gxtName, index); }
    static void GetScriptRenderTargetRenderId(u32 *pRenderId) { NativeInvoke::Invoke<ScriptVoid>("GET_SCRIPT_RENDERTARGET_RENDER_ID", pRenderId); }
    static const ch *GetStringFromHashKey(u32 hashKey) { return NativeInvoke::Invoke<const ch *>("GET_STRING_FROM_HASH_KEY", hashKey); }
    static ScriptAny GetStringWidth(const ch *gxtName) { return NativeInvoke::Invoke<ScriptAny>("GET_STRING_WIDTH", gxtName); }
    static ScriptAny GetStringWidthWithNumber(const ch *gxtName, i32 number) { return NativeInvoke::Invoke<ScriptAny>("GET_STRING_WIDTH_WITH_NUMBER", gxtName, number); }
    static ScriptAny GetStringWidthWithString(const ch *gxtName, const ch *literalString) { return NativeInvoke::Invoke<ScriptAny>("GET_STRING_WIDTH_WITH_STRING", gxtName, literalString); }
    static b8 HasAdditionalTextLoaded(u32 textIndex) { return NativeInvoke::Invoke<b8>("HAS_ADDITIONAL_TEXT_LOADED", textIndex); }
    static b8 HasThisAdditionalTextLoaded(const ch *textName, u32 textIndex) { return NativeInvoke::Invoke<b8>("HAS_THIS_ADDITIONAL_TEXT_LOADED", textName, textIndex); }
    static b8 IsFontLoaded(eTextFont font) { return NativeInvoke::Invoke<b8>("IS_FONT_LOADED", font); }
    static b8 IsStreamingAdditionalText(u32 textIndex) { return NativeInvoke::Invoke<b8>("IS_STREAMING_ADDITIONAL_TEXT", textIndex); }
    static void LoadAdditionalText(const ch *textName, u32 textIndex) { NativeInvoke::Invoke<ScriptVoid>("LOAD_ADDITIONAL_TEXT", textName, textIndex); }
    static void LoadTextFont(eTextFont font) { NativeInvoke::Invoke<ScriptVoid>("LOAD_TEXT_FONT", font); }
    static void PrintStringWithLiteralStringNow(const char* gxt, const char* text, u32 ms, u32 unknown1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_STRING_WITH_LITERAL_STRING_NOW", gxt, text, ms, unknown1); }
    static void RequestAdditionalText(const ch *textName, u32 textIndex) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_ADDITIONAL_TEXT", textName, textIndex); }
    static void SetTextScale(f32 w, f32 h) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_SCALE", w, h); }
    static void SetTextBackground(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_BACKGROUND", value); }
    static void SetTextCentre(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_CENTRE", value); }
    static void SetTextColour(u8 r, u8 g, u8 b, u8 a) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_COLOUR", r, g, b, a); }
    static void SetTextDrawBeforeFade(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_DRAW_BEFORE_FADE", value); }
    static void SetTextDropshadow(b8 displayShadow, u8 r, u8 g, u8 b, u8 a) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_DROPSHADOW", displayShadow, r, g, b, a); }
    static void SetTextEdge(b8 displayEdge, u8 r, u8 g, u8 b, u8 a) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_EDGE", displayEdge, r, g, b, a); }
    static void SetTextFont(eTextFont font) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_FONT", font); }
    static void SetTextJustify(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_JUSTIFY", value); }
    static void SetTextLineDisplay(u32 unk1, u32 unk2) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_LINE_DISPLAY", unk1, unk2); }
    static void SetTextLineHeightMult(f32 lineHeight) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_LINE_HEIGHT_MULT", lineHeight); }
    static void SetTextProportional(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_PROPORTIONAL", value); }
    static void SetTextRenderId(u32 renderId) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_RENDER_ID", renderId); }
    static void SetTextRightJustify(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_RIGHT_JUSTIFY", value); }
    static void SetTextToUseTextFileColours(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_TO_USE_TEXT_FILE_COLOURS", value); }
    static void SetTextUseUnderscore(b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_USE_UNDERSCORE", value); }
    static void SetTextWrap(f32 unk1, f32 unk2) { NativeInvoke::Invoke<ScriptVoid>("SET_TEXT_WRAP", unk1, unk2); }

    // Textures
    static Texture GetTexture(TextureDict dictionary, const ch *textureName) { return NativeInvoke::Invoke<Texture>("GET_TEXTURE", dictionary, textureName); }
    static Texture GetTextureFromStreamedTxd(const ch *txdName, const ch *textureName) { return NativeInvoke::Invoke<Texture>("GET_TEXTURE_FROM_STREAMED_TXD", txdName, textureName); }
    static TextureDict GetTxd(const ch *txdName) { return NativeInvoke::Invoke<TextureDict>("GET_TXD", txdName); }
    static b8 HasStreamedTxdLoaded(const ch *txdName) { return NativeInvoke::Invoke<b8>("HAS_STREAMED_TXD_LOADED", txdName); }
    static TextureDict LoadTxd(const ch *txdName) { return NativeInvoke::Invoke<TextureDict>("LOAD_TXD", txdName); }
    static void MarkStreamedTxdAsNoLongerNeeded(const ch *txdName) { NativeInvoke::Invoke<ScriptVoid>("MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED", txdName); }
    static void ReleaseTexture(Texture texture) { NativeInvoke::Invoke<ScriptVoid>("RELEASE_TEXTURE", texture); }
    static void RequestStreamedTxd(const ch *txdName, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_STREAMED_TXD", txdName, unknown); }
    static void RemoveTxd(TextureDict txd) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_TXD", txd); }

    // Stats
    static void DecrementIntStat(eIntStatistic stat, u32 amount) { NativeInvoke::Invoke<ScriptVoid>("DECREMENT_INT_STAT", stat, amount); }
    static u32 GetIntStat(eIntStatistic stat) { return NativeInvoke::Invoke<u32>("GET_INT_STAT", stat); }
    static void IncrementFloatStatNoMessage(eFloatStatistic stat, f32 value) { NativeInvoke::Invoke<ScriptVoid>("INCREMENT_FLOAT_STAT_NO_MESSAGE", stat, value); }
    static void IncrementIntStat(eIntStatistic stat, u32 value) { NativeInvoke::Invoke<ScriptVoid>("INCREMENT_INT_STAT", stat, value); }
    static void IncrementIntStatNoMessage(eIntStatistic stat, u32 value) { NativeInvoke::Invoke<ScriptVoid>("INCREMENT_INT_STAT_NO_MESSAGE", stat, value); }
    static void SetIntStat(eIntStatistic stat, u32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_INT_STAT", stat, value); }

    // Pad (controls)
    static b8 GetPadPitchRoll(u32 padIndex, f32 *pPitch, f32 *pRoll) { return NativeInvoke::Invoke<b8>("GET_PAD_PITCH_ROLL", padIndex, pPitch, pRoll); }
    static void GetPositionOfAnalogueSticks(u32 padIndex, u32 *pLeftX, u32 *pLeftY, u32 *pRightX, u32 *pRightY) { NativeInvoke::Invoke<ScriptVoid>("GET_POSITION_OF_ANALOGUE_STICKS", padIndex, pLeftX, pLeftY, pRightX, pRightY); }
    static b8 IsButtonJustPressed(u32 padIndex, ePadButton button) { return NativeInvoke::Invoke<b8>("IS_BUTTON_JUST_PRESSED", padIndex, button); }
    static b8 IsButtonPressed(u32 padIndex, ePadButton button) { return NativeInvoke::Invoke<b8>("IS_BUTTON_PRESSED", padIndex, button); }

    // Sound
    static eSound GetSoundId() { return NativeInvoke::Invoke<eSound>("GET_SOUND_ID"); }
    static b8 HasSoundFinished(eSound sound) { return NativeInvoke::Invoke<b8>("HAS_SOUND_FINISHED", sound); }
    static void PlayAudioEvent(ch *name) { NativeInvoke::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT", name); }
    static void PlaySoundFrontend(eSound sound, ch *soundName) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND_FRONTEND", sound, soundName); }
    static void SetVariableOnSound(eSound sound, ch *varname, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_VARIABLE_ON_SOUND", sound, varname, value); }
    static void StopSound(eSound sound) { NativeInvoke::Invoke<ScriptVoid>("STOP_SOUND", sound); }
    static void ReleaseSoundId(eSound sound) { NativeInvoke::Invoke<ScriptVoid>("RELEASE_SOUND_ID", sound); }

    // Time
    static void ForceTimeOfDay(u32 hour, u32 minute) { NativeInvoke::Invoke<ScriptVoid>("FORCE_TIME_OF_DAY", hour, minute); }
    static void ForwardToTimeOfDay(u32 hour, u32 minute) { NativeInvoke::Invoke<ScriptVoid>("FORWARD_TO_TIME_OF_DAY", hour, minute); }
    static void GetCurrentDate(u32 *day, u32 *month) { NativeInvoke::Invoke<ScriptVoid>("GET_CURRENT_DATE", day, month); }
    static u32 GetCurrentDayOfWeek() { return NativeInvoke::Invoke<u32>("GET_CURRENT_DAY_OF_WEEK"); }
    static u32 GetHoursOfDay() { return NativeInvoke::Invoke<u32>("GET_HOURS_OF_DAY"); }
    static u32 GetMinutesOfDay() { return NativeInvoke::Invoke<u32>("GET_MINUTES_OF_DAY"); }
    static u32 GetMinutesToTimeOfDay(u32 hour, u32 minute) { return NativeInvoke::Invoke<u32>("GET_MINUTES_TO_TIME_OF_DAY", hour, minute); }
    static void GetTimeOfDay(u32 *hour, u32 *minute) { NativeInvoke::Invoke<ScriptVoid>("GET_TIME_OF_DAY", hour, minute); }
    static void ReleaseTimeOfDay() { NativeInvoke::Invoke<ScriptVoid>("RELEASE_TIME_OF_DAY"); }
    static void SetTimeOfDay(u32 hour, u32 minute) { NativeInvoke::Invoke<ScriptVoid>("SET_TIME_OF_DAY", hour, minute); }
    static void SetTimeOneDayBack() { NativeInvoke::Invoke<ScriptVoid>("SET_TIME_ONE_DAY_BACK"); }
    static void SetTimeOneDayForward() { NativeInvoke::Invoke<ScriptVoid>("SET_TIME_ONE_DAY_FORWARD"); }
    static void SetTimeScale(f32 scale) { NativeInvoke::Invoke<ScriptVoid>("SET_TIME_SCALE", scale); }

    // Fires
    static b8 IsScriptFireExtinguished(FireId fire) { return NativeInvoke::Invoke<b8>("IS_SCRIPT_FIRE_EXTINGUISHED", fire); }
    static void RemoveScriptFire(FireId fire) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_SCRIPT_FIRE", fire); }
    static FireId StartCarFire(Vehicle vehicle) { return NativeInvoke::Invoke<ScriptAny>("START_CAR_FIRE", vehicle); }
    static FireId StartCharFire(Ped ped) { return NativeInvoke::Invoke<ScriptAny>("START_CHAR_FIRE", ped); }
    static FireId StartScriptFire(f32 x, f32 y, f32 z, u8 numGenerationsAllowed = 0, u32 strength = 1) { return NativeInvoke::Invoke<u32>("START_SCRIPT_FIRE", x, y, z, numGenerationsAllowed, strength); }

    // Radio
    static void DisableFrontEndRadio() { NativeInvoke::Invoke<ScriptVoid>("DISABLE_FRONTEND_RADIO"); }
    static void EnableFrontEndRadio() { NativeInvoke::Invoke<ScriptVoid>("ENABLE_FRONTEND_RADIO"); }
    static void FreezeRadioStation(const ch *stationName) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_RADIO_STATION", stationName); }
    static eRadioStation GetPlayerRadioStationIndex() { return NativeInvoke::Invoke<eRadioStation>("GET_PLAYER_RADIO_STATION_INDEX"); }
    static const ch *GetPlayerRadioStationName() { return NativeInvoke::Invoke<const ch *>("GET_PLAYER_RADIO_STATION_NAME"); }
    static b8 IsRadioRetuning() { return NativeInvoke::Invoke<b8>("IS_RADIO_RETUNING"); }
    static void RetuneRadioToStationIndex(eRadioStation radioStation) { NativeInvoke::Invoke<ScriptVoid>("RETUNE_RADIO_TO_STATION_INDEX", radioStation); }

    // Game/Misc
    static void AbortAllGarageActivity() { NativeInvoke::Invoke<ScriptVoid>("ABORT_ALL_GARAGE_ACTIVITY"); }
    static void ActivateCheat(eCheat cheat) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_CHEAT", cheat); }
    static void ActivateFrontEnd() { NativeInvoke::Invoke<u32>("ACTIVATE_FRONTEND"); }
    static void ActivateSaveMenu() { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_SAVE_MENU"); }
    static void AddExplosion(f32 x, f32 y, f32 z, u32 p3, f32 p4, u32 p5, u32 p6, f32 p7) { NativeInvoke::Invoke<ScriptVoid>("ADD_EXPLOSION", x, y, z, p3, p4, p5, p6, p7); }
    static void AllowEmergencyServices(b8 allow) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_EMERGENCY_SERVICES", allow); }
    static void AllowGameToPauseForStreaming(b8 allow) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_GAME_TO_PAUSE_FOR_STREAMING", allow); }
    static void AllowStuntJumpsToTrigger(b8 allow) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_STUNT_JUMPS_TO_TRIGGER", allow); }
    static b8 AreWidescreenBordersActive() { return NativeInvoke::Invoke<b8>("ARE_WIDESCREEN_BORDERS_ACTIVE"); }
    static ScriptAny AwardAchievement(eAchievement achievement) { return NativeInvoke::Invoke<ScriptAny>("AWARD_ACHIEVEMENT", achievement); }
    static b8 CanPhoneBeSeenOnScreen() { return NativeInvoke::Invoke<b8>("CAN_PHONE_BE_SEEN_ON_SCREEN"); }
    static void CancelOverrideRestart() { NativeInvoke::Invoke<ScriptVoid>("CANCEL_OVERRIDE_RESTART"); }
    static void ClearShakePlayerPadWhenControllerDisabled() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_SHAKE_PLAYERPAD_WHEN_CONTROLLER_DISABLED"); }
    static void ClearTimeCycleModifier() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_TIMECYCLE_MODIFIER"); }
    static void DeactivateFrontEnd() { NativeInvoke::Invoke<ScriptVoid>("DEACTIVATE_FRONTEND"); }
    static b8 DidSaveCompleteSuccessfully() { return NativeInvoke::Invoke<b8>("DID_SAVE_COMPLETE_SUCCESSFULLY"); }
    static void DisablePauseMenu(b8 disabled) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_PAUSE_MENU", disabled); }
    static void DisablePoliceScanner() { NativeInvoke::Invoke<ScriptVoid>("DISABLE_POLICE_SCANNER"); }
    static void DisplayAmmo(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_AMMO", display); }
    static void DisplayAreaName(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_AREA_NAME", display); }
    static void DisplayCash(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_CASH", display); }
    static void DisplayFrontEndMapBlips(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_FRONTEND_MAP_BLIPS", display); }
    static void DisplayHUD(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_HUD", display); }
    static void DisplayRadar(b8 display) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_RADAR", display); }
    static void DisplaySniperScopeThisFrame() { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_SNIPER_SCOPE_THIS_FRAME"); }
    static void DoAutoSave() { NativeInvoke::Invoke<ScriptVoid>("DO_AUTO_SAVE"); }
    static void DoScreenFadeIn(u32 timeMS) { NativeInvoke::Invoke<ScriptVoid>("DO_SCREEN_FADE_IN", timeMS); }
    static void DoScreenFadeInUnhacked(u32 timeMS) { NativeInvoke::Invoke<ScriptVoid>("DO_SCREEN_FADE_IN_UNHACKED", timeMS); }
    static void DoScreenFadeOut(u32 timeMS) { NativeInvoke::Invoke<ScriptVoid>("DO_SCREEN_FADE_OUT", timeMS); }
    static void DoScreenFadeOutUnhacked(u32 timeMS) { NativeInvoke::Invoke<ScriptVoid>("DO_SCREEN_FADE_OUT_UNHACKED", timeMS); }
	static void DrawRect(f32 x1, f32 y1, f32 x2, f32 y2, u8 r, u8 g, u8 b, u8 a) { NativeInvoke::Invoke<ScriptVoid>("DRAW_RECT", x1, y1, x2, y2, r, g, b, a); }
    static void EnableMaxAmmoCap(b8 enable) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_MAX_AMMO_CAP", enable); }
    static void EnablePoliceScanner() { NativeInvoke::Invoke<ScriptVoid>("ENABLE_POLICE_SCANNER"); }
    static void EnableSceneStreaming(b8 enable) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_SCENE_STREAMING", enable); }
    static void FakeDeathArrest() { NativeInvoke::Invoke<ScriptVoid>("FAKE_DEATHARREST"); }
    static void FindStreetNameAtPosition(f32 pX, f32 pY, f32 pZ, u32 *strHash0, u32 *strHash1) { NativeInvoke::Invoke<ScriptVoid>("FIND_STREET_NAME_AT_POSITION", pX, pY, pZ, strHash0, strHash1); }
    static void FireSingleBullet(f32 x, f32 y, f32 z, f32 targetX, f32 targetY, f32 targetZ, u32 unknown) { NativeInvoke::Invoke<ScriptVoid>("FIRE_SINGLE_BULLET", x, y, z, targetX, targetY, targetZ, unknown); }
    static void FlashWeaponIcon(b8 on) { NativeInvoke::Invoke<ScriptVoid>("FLASH_WEAPON_ICON", on); }
    static void ForceInitialPlayerStation(const ch *stationName) { NativeInvoke::Invoke<ScriptVoid>("FORCE_INITIAL_PLAYER_STATION", stationName); }
    static void ForceLoadingScreen(b8 force) { NativeInvoke::Invoke<ScriptVoid>("FORCE_LOADING_SCREEN", force); }
    static void GetCorrectedColour(u32 r, u32 g, u32 b, u32 *pR, u32 *pG, u32 *pB) { NativeInvoke::Invoke<ScriptVoid>("GET_CORRECTED_COLOUR", r, g, b, pR, pG, pB); }
    static b8 GetCreateRandomCops() { return NativeInvoke::Invoke<b8>("GET_CREATE_RANDOM_COPS"); }
    static u32 GetCurrentEpisode() { return NativeInvoke::Invoke<u32>("GET_CURRENT_EPISODE"); }
    static eLanguage GetCurrentLanguage() { return NativeInvoke::Invoke<eLanguage>("GET_CURRENT_LANGUAGE"); }
    static u32 GetEpisodeIndexFromSummons() { return NativeInvoke::Invoke<ScriptAny>("GET_EPISODE_INDEX_FROM_SUMMONS"); }
    static f32 GetFloatStat(eFloatStatistic stat) { return NativeInvoke::Invoke<f32>("GET_FLOAT_STAT", stat); }
    static void GetFrameTime(f32 *time) { NativeInvoke::Invoke<ScriptVoid>("GET_FRAME_TIME", time); }
    static void GetGameTimer(u32 *pTimer) { NativeInvoke::Invoke<ScriptVoid>("GET_GAME_TIMER", pTimer); }
    static u32 GetHashKey(const ch *value) { return NativeInvoke::Invoke<ScriptAny>("GET_HASH_KEY", value); }
    static void GetHUDColour(eHUDType type, u32 *pR, u32 *pG, u32 *pB, ScriptAny *pUnknown) { NativeInvoke::Invoke<ScriptVoid>("GET_HUD_COLOUR", type, pR, pG, pB, pUnknown); }
    static u32 GetIdOfThisThread() { return NativeInvoke::Invoke<u32>("GET_ID_OF_THIS_THREAD"); }
    static b8 GetIsDepositAnimRunning() { return NativeInvoke::Invoke<b8>("GET_IS_DEPOSIT_ANIM_RUNNING"); }
    static b8 GetIsHiDef() { return NativeInvoke::Invoke<b8>("GET_IS_HIDEF"); }
    static b8 GetIsWidescreen() { return NativeInvoke::Invoke<b8>("GET_IS_WIDESCREEN"); }
    static eMapArea GetMapAreaFromCoords(f32 x, f32 y, f32 z) { return NativeInvoke::Invoke<eMapArea>("GET_MAP_AREA_FROM_COORDS", x, y, z); }
    static b8 GetMissionFlag() { return NativeInvoke::Invoke<b8>("GET_MISSION_FLAG"); }
    static void GetMaxWantedLevel(u32 *pMaxWantedLevel) { NativeInvoke::Invoke<ScriptVoid>("GET_MAX_WANTED_LEVEL", pMaxWantedLevel); }
    static const ch *GetNameOfInfoZone(f32 x, f32 y, f32 z) { return NativeInvoke::Invoke<const ch *>("GET_NAME_OF_INFO_ZONE", x, y, z); }
    static const ch *GetNameOfZone(f32 x, f32 y, f32 z) { return NativeInvoke::Invoke<const ch *>("GET_NAME_OF_ZONE", x, y, z); }
    static u32 GetNumStreamingRequests() { return NativeInvoke::Invoke<u32>("GET_NUM_STREAMING_REQUESTS"); }
    static u32 GetNumberOfInstancesOfStreamedScript(const ch *scriptName) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT", scriptName); }
    static u32 GetNumberOfPlayers() { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_PLAYERS"); }
    static u32 GetTimeSinceLastArrest() { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_LAST_ARREST"); }
    static u32 GetTimeSinceLastDeath() { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_LAST_DEATH"); }
    static b8 HasAchievementBeenPassed(eAchievement achievement) { return NativeInvoke::Invoke<b8>("HAS_ACHIEVEMENT_BEEN_PASSED", achievement); }
    static b8 HasDeathArrestExecuted() { return NativeInvoke::Invoke<b8>("HAS_DEATHARREST_EXECUTED"); }
    static b8 HasResprayHappened() { return NativeInvoke::Invoke<b8>("HAS_RESPRAY_HAPPENED"); }
    static b8 HasScriptLoaded(const ch *scriptName) { return NativeInvoke::Invoke<b8>("HAS_SCRIPT_LOADED", scriptName); }
    static b8 HaveAnimsLoaded(const ch *animName) { return NativeInvoke::Invoke<b8>("HAVE_ANIMS_LOADED", animName); }
    static b8 HaveRequestedPathNodesBeenLoaded(u32 requestId) { return NativeInvoke::Invoke<b8>("HAVE_REQUESTED_PATH_NODES_BEEN_LOADED", requestId); }
    static void HideHelpTextThisFrame() { NativeInvoke::Invoke<ScriptVoid>("HIDE_HELP_TEXT_THIS_FRAME"); }
    static void HideHUDAndRadarThisFrame() { NativeInvoke::Invoke<ScriptVoid>("HIDE_HUD_AND_RADAR_THIS_FRAME"); }
    static b8 IsAussieVersion() { return NativeInvoke::Invoke<b8>("IS_AUSSIE_VERSION"); }
    static b8 IsAutoAimingOn() { return NativeInvoke::Invoke<b8>("IS_AUTO_AIMING_ON"); }
    static b8 IsAutoSaveInProgress() { return NativeInvoke::Invoke<b8>("IS_AUTO_SAVE_IN_PROGRESS"); }
    static b8 IsInteriorScene() { return NativeInvoke::Invoke<b8>("IS_INTERIOR_SCENE"); }
    static b8 IsFrontEndFading() { return NativeInvoke::Invoke<b8>("IS_FRONTEND_FADING"); }
    static b8 IsGameInControlOfMusic() { return NativeInvoke::Invoke<b8>("IS_GAME_IN_CONTROL_OF_MUSIC"); }
    static b8 IsGermanVersion() { return NativeInvoke::Invoke<b8>("IS_GERMAN_VERSION"); }
    static b8 IsHelpMessageBeingDisplayed() { return NativeInvoke::Invoke<b8>("IS_HELP_MESSAGE_BEING_DISPLAYED"); }
    static b8 IsHintRunning() { return NativeInvoke::Invoke<b8>("IS_HINT_RUNNING"); }
    static b8 IsHUDPreferenceSwitchedOn() { return NativeInvoke::Invoke<b8>("IS_HUD_PREFERENCE_SWITCHED_ON"); }
    static b8 IsHUDReticuleComplex() { return NativeInvoke::Invoke<b8>("IS_HUD_RETICULE_COMPLEX"); }
    static b8 IsInSpectatorMode() { return NativeInvoke::Invoke<b8>("IS_IN_SPECTATOR_MODE"); }
    static b8 IsLookInverted() { return NativeInvoke::Invoke<b8>("IS_LOOK_INVERTED"); }
    static b8 IsMemoryCardInUse() { return NativeInvoke::Invoke<b8>("IS_MEMORY_CARD_IN_USE"); }
    static b8 IsMessageBeingDisplayed() { return NativeInvoke::Invoke<b8>("IS_MESSAGE_BEING_DISPLAYED"); }
    static b8 IsMinigameInProgress() { return NativeInvoke::Invoke<b8>("IS_MINIGAME_IN_PROGRESS"); }
    static b8 IsMissionCompletePlaying() { return NativeInvoke::Invoke<b8>("IS_MISSION_COMPLETE_PLAYING"); }
    static b8 IsMobilePhoneCallOngoing() { return NativeInvoke::Invoke<b8>("IS_MOBILE_PHONE_CALL_ONGOING"); }
    static b8 IsMobilePhoneRadioActive() { return NativeInvoke::Invoke<b8>("IS_MOBILE_PHONE_RADIO_ACTIVE"); }
    static b8 IsPauseMenuActive() { return NativeInvoke::Invoke<b8>("IS_PAUSE_MENU_ACTIVE"); }
    static b8 IsPayNSprayActive() { return NativeInvoke::Invoke<b8>("IS_PAY_N_SPRAY_ACTIVE"); }
    static b8 IsPlayerBeingArrested() { return NativeInvoke::Invoke<b8>("IS_PLAYER_BEING_ARRESTED"); }
    static b8 IsPlayerOnline() { return NativeInvoke::Invoke<b8>("IS_PLAYER_ONLINE"); }
    static b8 IsScreenFadedIn() { return NativeInvoke::Invoke<b8>("IS_SCREEN_FADED_IN"); }
    static b8 IsScreenFadedOut() { return NativeInvoke::Invoke<b8>("IS_SCREEN_FADED_OUT"); }
    static b8 IsScreenFading() { return NativeInvoke::Invoke<b8>("IS_SCREEN_FADING"); }
    static b8 IsScreenFadingIn() { return NativeInvoke::Invoke<b8>("IS_SCREEN_FADING_IN"); }
    static b8 IsScreenFadingOut() { return NativeInvoke::Invoke<b8>("IS_SCREEN_FADING_OUT"); }
    static b8 IsSniperInverted() { return NativeInvoke::Invoke<b8>("IS_SNIPER_INVERTED"); }
    static b8 IsSystemUIShowing() { return NativeInvoke::Invoke<b8>("IS_SYSTEM_UI_SHOWING"); }
    static b8 IsThisAMinigameScript() { return NativeInvoke::Invoke<b8>("IS_THIS_A_MINIGAME_SCRIPT"); }
    static b8 IsThreadActive(u32 threadId) { return NativeInvoke::Invoke<b8>("IS_THREAD_ACTIVE", threadId); }
    static u32 LoadAllPathNodes(bool value) { return NativeInvoke::Invoke<ScriptAny>("LOAD_ALL_PATH_NODES", value); }
    static void MarkScriptAsNoLongerNeeded(const ch *scriptName) { NativeInvoke::Invoke<ScriptVoid>("MARK_SCRIPT_AS_NO_LONGER_NEEDED", scriptName); }
    static void PauseGame() { NativeInvoke::Invoke<ScriptVoid>("PAUSE_GAME"); }
    static void PlayMovie() { NativeInvoke::Invoke<ScriptVoid>("PLAY_MOVIE"); }
    static void PopulateNow() { NativeInvoke::Invoke<ScriptVoid>("POPULATE_NOW"); }
    static void RequestAnims(const ch *animName) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_ANIMS", animName); }
    static void ReleaseMovie() { NativeInvoke::Invoke<ScriptVoid>("RELEASE_MOVIE"); }
    static void ReleaseWeather() { NativeInvoke::Invoke<ScriptVoid>("RELEASE_WEATHER"); }
    static void RemoveAnims(const ch *animName) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_ANIMS", animName); }
    static void RemoveCoverPoint(CoverPoint coverPoint) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_COVER_POINT", coverPoint); }
    static void RemoveIpl(const ch *iplName) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_IPL", iplName); }
    static void RequestIpl(const ch *iplName) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_IPL", iplName); }
    static void SetCameraControlsDisabledWithPlayerControls(bool value) { NativeInvoke::Invoke<ScriptVoid>("SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS", value); }
    static void SetMissionFlag(b8 isMission) { NativeInvoke::Invoke<ScriptVoid>("SET_MISSION_FLAG", isMission); }
    static void SetFloatStat(eFloatStatistic stat, f32 value) { NativeInvoke::Invoke<ScriptVoid>("SET_FLOAT_STAT", stat, value); }
    static void SetRadarZoom(f32 zoom) { NativeInvoke::Invoke<ScriptVoid>("SET_RADAR_ZOOM", zoom); }
    static void SetTimerA(u32 value) { NativeInvoke::Invoke<ScriptVoid>("SETTIMERA", value); }
    static void SetTimerB(u32 value) { NativeInvoke::Invoke<ScriptVoid>("SETTIMERB", value); }
    static void SetWantedMultiplier(f32 multiplier) { NativeInvoke::Invoke<ScriptVoid>("SET_WANTED_MULTIPLIER", multiplier); }
    //static void TerminateThisScript() { NativeInvoke::Invoke<ScriptVoid>("TERMINATE_THIS_SCRIPT"); }	// Don't use this from a NativeThread (NativeFiberThread overrides this function)
    static u32 TimerA() { return NativeInvoke::Invoke<u32>("TIMERA"); }
    static u32 TimerB() { return NativeInvoke::Invoke<u32>("TIMERB"); }
    static u32 TimeStep() { return NativeInvoke::Invoke<u32>("TIMESTEP"); }
    static void UnlockLazlowStation() { NativeInvoke::Invoke<ScriptVoid>("UNLOCK_LAZLOW_STATION"); }
    static void UnregisterScriptWithAudio() { NativeInvoke::Invoke<ScriptVoid>("UNREGISTER_SCRIPT_WITH_AUDIO"); }
    static void UnPauseGame() { NativeInvoke::Invoke<ScriptVoid>("UNPAUSE_GAME"); }
    //static void Wait(u32 timeInMs) { NativeInvoke::Invoke<ScriptVoid>("WAIT", timeInMs); }	// Don't use this from a NativeThread (NativeFiberThread overrides this function)

    // General
    static f32 AbsF(f32 value) { return NativeInvoke::Invoke<f32>("ABSF", value); }		// Prefer using function from <math.h> instead for performance
    static f32 AbsI(f32 value) { return NativeInvoke::Invoke<f32>("ABSI", value); }		// Prefer using function from <math.h> instead for performance
    static f32 ASin(f32 value) { return NativeInvoke::Invoke<f32>("ASIN", value); }		// Prefer using function from <math.h> instead for performance
    static f32 ATan(f32 value) { return NativeInvoke::Invoke<f32>("ATAN", value); }		// Prefer using function from <math.h> instead for performance
    static i32 Ceil(f32 value) { return NativeInvoke::Invoke<i32>("CEIL", value); }		// Prefer using function from <math.h> instead for performance
    static f32 Cos(f32 value) { return NativeInvoke::Invoke<f32>("COS", value); }		// Prefer using function from <math.h> instead for performance
    static f32 ToFloat(u32 value) { return NativeInvoke::Invoke<f32>("TO_FLOAT", value); }	// Prefer casting instead for performance
    static u32 Floor(f32 value) { return NativeInvoke::Invoke<u32>("FLOOR", value); }		// Prefer using function from <math.h> instead for performance
    static void GenerateRandomFloatInRange(f32 min, f32 max, f32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GENERATE_RANDOM_FLOAT_IN_RANGE", min, max, pValue); }
    static void GenerateRandomIntInRange(u32 min, u32 max, u32 *pValue) { NativeInvoke::Invoke<ScriptVoid>("GENERATE_RANDOM_INT_IN_RANGE", min, max, pValue); }
    static void GetAngleBetween2DVectors(f32 x1, f32 y1, f32 x2, f32 y2, f32 *pResult) { NativeInvoke::Invoke<ScriptVoid>("GET_ANGLE_BETWEEN_2D_VECTORS", x1, y1, x2, y2, pResult); }
    static void GetDistanceBetweenCoords2D(f32 x1, f32 y1, f32 x2, f32 y2, f32 *pDist) { NativeInvoke::Invoke<ScriptVoid>("GET_DISTANCE_BETWEEN_COORDS_2D", x1, y1, x2, y2, pDist); }
    static void GetDistanceBetweenCoords3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 *pDist) { NativeInvoke::Invoke<ScriptVoid>("GET_DISTANCE_BETWEEN_COORDS_3D", x1, y1, z1, x2, y2, z2, pDist); }
    static const ch *GetFirstNCharactersOfLiteralString(const ch *literalString, u32 chars) { return NativeInvoke::Invoke<const ch *>("GET_FIRST_N_CHARACTERS_OF_LITERAL_STRING", literalString, chars); }
    static void GetHeadingFromVector2D(f32 x, f32 y, f32 *pHeading) { NativeInvoke::Invoke<ScriptVoid>("GET_HEADING_FROM_VECTOR_2D", x, y, pHeading); }
    static u32 GetLengthOfLiteralString(const ch *literalString) { return NativeInvoke::Invoke<u32>("GET_LENGTH_OF_LITERAL_STRING", literalString); }
    static b8 IsStringNull(const ch *str) { return NativeInvoke::Invoke<b8>("IS_STRING_NULL", str); }
    static f32 Sin(f32 value) { return NativeInvoke::Invoke<f32>("SIN", value); }		// Prefer using function from <math.h> instead for performance
    static f32 Sqrt(f32 value) { return NativeInvoke::Invoke<f32>("SQRT", value); }		// Prefer using function from <math.h> instead for performance
    static f32 Tan(f32 value) { return NativeInvoke::Invoke<f32>("TAN", value); }		// Prefer using function from <math.h> instead for performance

}