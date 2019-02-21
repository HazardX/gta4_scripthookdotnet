/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

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

// NOTE: Don't include or use this file! 

// The function definitions in this file were generated using a script and thus do not have proper
// function signatures.

// Move the definitions out of here into Scripting.h and clean up the parameter/return types to 
// proper C++ types. Remember to only use 32-bit or smaller types -- don't use double/f64 (use 
// the lower precision f32 instead), and don't use structs that are larger than 4 bytes.

namespace ScriptingDirty
{

// Wanted to cleanup, but couldn't find params

	static ScriptAny GetEpisodeName(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_EPISODE_NAME", p0); }
	static ScriptAny GetLeftPlayerCashToReachLevel(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_LEFT_PLAYER_CASH_TO_REACH_LEVEL", p0); }
	static ScriptAny GetNumberLinesWithSubstrings(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("GET_NUMBER_LINES_WITH_SUBSTRINGS", p0, p1, p2, p3, p4); }
	static b8 HasPlayerCollectedPickup(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<b8>("HAS_PLAYER_COLLECTED_PICKUP", p0, p1); }
	static void RenderWeaponPickupsBigger(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RENDER_WEAPON_PICKUPS_BIGGER", p0); }


// Interesting ones to cleanup:

	static void GetRandomCarBackBumperInSphere(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CAR_BACK_BUMPER_IN_SPHERE", p0, p1, p2, p3, p4, p5, p6); }
	static void GetRandomCarFrontBumperInSphereNoSave(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CAR_FRONT_BUMPER_IN_SPHERE_NO_SAVE", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void GetRandomCarInSphere(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CAR_IN_SPHERE", p0, p1, p2, p3, p4, p5, p6); }
	static void GetRandomCarInSphereNoSave(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("GET_RANDOM_CAR_IN_SPHERE_NO_SAVE", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny GetStatFrontEndVisibility(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_STAT_FRONTEND_VISIBILITY", p0); }
	static ScriptAny GetStringFromString(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("GET_STRING_FROM_STRING", p0, p1, p2); }
	static ScriptAny GetTimeTilNextStation(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_TIME_TIL_NEXT_STATION", p0); }
	static void GetTrainCaboose(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_TRAIN_CABOOSE", p0, p1); }
	static void GetTrainCarriage(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GET_TRAIN_CARRIAGE", p0, p1, p2); }
	static void GetTrainPlayerWouldEnter(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_TRAIN_PLAYER_WOULD_ENTER", p0, p1); }
	static void GetVehicleQuaternion(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("GET_VEHICLE_QUATERNION", p0, p1, p2, p3, p4); }
	static ScriptAny GetWaterHeight(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("GET_WATER_HEIGHT", p0, p1, p2, p3); }
	static ScriptAny GetWaterHeightNoWaves(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("GET_WATER_HEIGHT_NO_WAVES", p0, p1, p2, p3); }
	static void GetWeaponTypeModel(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_WEAPONTYPE_MODEL", p0, p1); }
	static void GetWeaponTypeSlot(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_WEAPONTYPE_SLOT", p0, p1); }
	static void GiveDelayedWeaponToChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("GIVE_DELAYED_WEAPON_TO_CHAR", p0, p1, p2, p3); }
	static void GivePedAmbientObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PED_AMBIENT_OBJECT", p0, p1); }
	static void GivePedHelmetWithOpts(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PED_HELMET_WITH_OPTS", p0, p1); }
	static void GivePedPickupObject(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PED_PICKUP_OBJECT", p0, p1, p2); }
	static void GivePlayerRagdollControl(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PLAYER_RAGDOLL_CONTROL", p0, p1); }
	static void GrabNearbyObjectWithSpecialAttribute(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GRAB_NEARBY_OBJECT_WITH_SPECIAL_ATTRIBUTE", p0, p1); }

	static ScriptAny IsClosestObjectOfTypeSmashedOrDamaged(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("IS_CLOSEST_OBJECT_OF_TYPE_SMASHED_OR_DAMAGED", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny IsControlJustPressed(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_CONTROL_JUST_PRESSED", p0, p1); }
	static ScriptAny IsControlPressed(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_CONTROL_PRESSED", p0, p1); }
	static ScriptAny IsCopVehicleInArea3DNoSave(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("IS_COP_VEHICLE_IN_AREA_3D_NO_SAVE", p0, p1, p2, p3, p4, p5); }
	static ScriptAny IsEpisodeAvailable(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_EPISODE_AVAILABLE", p0); }
	static ScriptAny IsExplosionInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("IS_EXPLOSION_IN_AREA", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny IsExplosionInSphere(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("IS_EXPLOSION_IN_SPHERE", p0, p1, p2, p3, p4); }
	static ScriptAny IsFollowVehicleCamOffsetActive() { return NativeInvoke::Invoke<ScriptAny>("IS_FOLLOW_VEHICLE_CAM_OFFSET_ACTIVE"); }
	static ScriptAny IsGameKeyboardKeyJustPressed(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_GAME_KEYBOARD_KEY_JUST_PRESSED", p0); }
	static ScriptAny IsGameKeyboardKeyPressed(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_GAME_KEYBOARD_KEY_PRESSED", p0); }
	static ScriptAny IsHeliPartBroken(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("IS_HELI_PART_BROKEN", p0, p1, p2, p3); }

	static ScriptAny IsKeyboardKeyJustPressed(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_KEYBOARD_KEY_JUST_PRESSED", p0); }
	static ScriptAny IsKeyboardKeyPressed(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_KEYBOARD_KEY_PRESSED", p0); }

	static ScriptAny IsObjectInAngledArea3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("IS_OBJECT_IN_ANGLED_AREA_3D", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny IsObjectInArea3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("IS_OBJECT_IN_AREA_3D", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny IsObjectPlayingAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("IS_OBJECT_PLAYING_ANIM", p0, p1, p2); }
	static ScriptAny IsObjectReassignmentInProgress() { return NativeInvoke::Invoke<ScriptAny>("IS_OBJECT_REASSIGNMENT_IN_PROGRESS"); }

	static ScriptAny IsProjectileInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("IS_PROJECTILE_IN_AREA", p0, p1, p2, p3, p4, p5); }

	static ScriptAny IsSittingObjectNear(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("IS_SITTING_OBJECT_NEAR", p0, p1, p2, p3); }
	static ScriptAny IsSniperBulletInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("IS_SNIPER_BULLET_IN_AREA", p0, p1, p2, p3, p4, p5); }

	static ScriptAny IsVehStuck(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("IS_VEH_STUCK", p0, p1, p2, p3, p4); }

	static void Line(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("LINE", p0, p1, p2, p3, p4, p5); }

	static void LoadSceneForRoomByKey(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("LOAD_SCENE_FOR_ROOM_BY_KEY", p0, p1); }

	static ScriptAny LocateCar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CAR_2D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CAR_3D", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny LocateCharAnyMeans2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_2D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharAnyMeans3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_3D", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny LocateCharAnyMeansCar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_CAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharAnyMeansCar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_CAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharAnyMeansChar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_CHAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharAnyMeansChar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_CHAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharAnyMeansObject2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_OBJECT_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharAnyMeansObject3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ANY_MEANS_OBJECT_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharInCar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_2D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharInCar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_3D", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny LocateCharInCarCar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_CAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharInCarCar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_CAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharInCarChar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_CHAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharInCarChar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_CHAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharInCarObject3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_IN_CAR_OBJECT_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharOnFoot2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_2D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharOnFoot3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_3D", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny LocateCharOnFootCar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_CAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharOnFootCar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_CAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharOnFootChar2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_CHAR_2D", p0, p1, p2, p3, p4); }
	static ScriptAny LocateCharOnFootChar3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_CHAR_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateCharOnFootObject3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_CHAR_ON_FOOT_OBJECT_3D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateObject2D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_OBJECT_2D", p0, p1, p2, p3, p4, p5); }
	static ScriptAny LocateObject3D(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("LOCATE_OBJECT_3D", p0, p1, p2, p3, p4, p5, p6, p7); }

	static ScriptAny PlayObjectAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("PLAY_OBJECT_ANIM", p0, p1, p2, p3, p4, p5); }
	static void PlaySound(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND", p0, p1); }
	static void PlaySoundFromObject(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND_FROM_OBJECT", p0, p1, p2); }
	static void PlaySoundFromPed(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND_FROM_PED", p0, p1, p2); }
	static void PlaySoundFromPosition(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND_FROM_POSITION", p0, p1, p2, p3, p4); }
	static void PlaySoundFromVehicle(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PLAY_SOUND_FROM_VEHICLE", p0, p1, p2); }
	static void PlayStreamFromObject(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAY_STREAM_FROM_OBJECT", p0); }
	static void PlayStreamFromPed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAY_STREAM_FROM_PED", p0); }
	static void PlayStreamFrontEnd() { NativeInvoke::Invoke<ScriptVoid>("PLAY_STREAM_FRONTEND"); }

	static void RegisterIntStat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_INT_STAT", p0, p1); }
	static ScriptAny RegisterSaveHouse(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("REGISTER_SAVE_HOUSE", p0, p1, p2, p3, p4, p5); }

	static void RequestScript(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_SCRIPT", p0); }
	static void ResetCarWheels(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("RESET_CAR_WHEELS", p0, p1); }
	static void ResetStuckTimer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("RESET_STUCK_TIMER", p0, p1); }
	static void ResetVisiblePedDamage(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESET_VISIBLE_PED_DAMAGE", p0); }
	static void RetuneRadioDown() { NativeInvoke::Invoke<ScriptVoid>("RETUNE_RADIO_DOWN"); }
	static void RetuneRadioToStationName(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RETUNE_RADIO_TO_STATION_NAME", p0); }
	static void RetuneRadioUp() { NativeInvoke::Invoke<ScriptVoid>("RETUNE_RADIO_UP"); }
	static ScriptAny RotateObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("ROTATE_OBJECT", p0, p1, p2, p3); }
	static ScriptAny Round(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("ROUND", p0); }
	static void SetActivateObjectPhysicsAsSoonAsItIsUnfrozen(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN", p0, p1); }
	static void SetAllCarsCanBeDamaged(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ALL_CARS_CAN_BE_DAMAGED", p0); }
	static void SetAllPickupsOfTypeCollectableByCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ALL_PICKUPS_OF_TYPE_COLLECTABLE_BY_CAR", p0, p1); }
	static void SetAllRandomPedsFlee(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ALL_RANDOM_PEDS_FLEE", p0, p1); }
	static void SetAlwaysDisplayWeaponPickupMessage(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ALWAYS_DISPLAY_WEAPON_PICKUP_MESSAGE", p0); }

	static void SetAnimGroupForChar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ANIM_GROUP_FOR_CHAR", p0, p1); }
	static void SetBlipMarkerLongDistance(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_BLIP_MARKER_LONG_DISTANCE", p0, p1); }
	static void SetBlipThrottleRandomly(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_BLIP_THROTTLE_RANDOMLY", p0, p1); }
	static void SetCarAsMissionCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_AS_MISSION_CAR", p0); }
	static void SetCarCollision(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_COLLISION", p0, p1); }
	static void SetCarColourCombination(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_COLOUR_COMBINATION", p0, p1); }
	static void SetCarCoordinatesNoOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_COORDINATES_NO_OFFSET", p0, p1, p2, p3); }
	static void SetCarDensityMultiplier(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetCarDoorLatched(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_DOOR_LATCHED", p0, p1, p2, p3); }
	static void SetCarEngineOn(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_ENGINE_ON", p0, p1, p2); }
	static void SetCarHasBeenCreatedInInterior(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_HAS_BEEN_CREATED_IN_INTERIOR", p0); }
	static void SetCarInCutscene(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_IN_CUTSCENE", p0, p1); }
	static void SetCarLightMultiplier(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_LIGHT_MULTIPLIER", p0, p1); }
	static void SetCarLivery(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_LIVERY", p0, p1); }
	static void SetCarOnlyDamagedByPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_ONLY_DAMAGED_BY_PLAYER", p0, p1); }
	static void SetCarRandomRouteSeed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_RANDOM_ROUTE_SEED", p0, p1); }
	static void SetCharAllowedToDuck(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ALLOWED_TO_DUCK", p0, p1); }
	static void SetCharAngledDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ANGLED_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void SetCharAnimCurrentTime(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ANIM_CURRENT_TIME", p0, p1, p2, p3); }
	static void SetCharAnimSpeed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ANIM_SPEED", p0, p1, p2, p3); }
	static void SetCharCanSmashGlass(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CAN_SMASH_GLASS", p0, p1); }
	static void SetCharClimbAnimRate(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CLIMB_ANIM_RATE", p0, p1); }
	static void SetCharCollision(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_COLLISION", p0, p1); }
	static void SetCharCoordinatesDontWarpGang(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_COORDINATES_DONT_WARP_GANG", p0, p1, p2, p3); }
	static void SetCharCoordinatesNoOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_COORDINATES_NO_OFFSET", p0, p1, p2, p3); }
	static void SetCharCurrentWeaponVisible(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_CURRENT_WEAPON_VISIBLE", p0, p1); }
	static void SetCharDiesInstantlyInWater(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DIES_INSTANTLY_IN_WATER", p0, p1); }
	static void SetCharDrownsInSinkingVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DROWNS_IN_SINKING_VEHICLE", p0, p1); }
	static void SetCharDrownsInWater(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_DROWNS_IN_WATER", p0, p1); }
	static ScriptAny SetCharDucking(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("SET_CHAR_DUCKING", p0, p1); }
	static void SetCharForceDieInCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_FORCE_DIE_IN_CAR", p0, p1); }
	static void SetCharGestureGroup(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_GESTURE_GROUP", p0, p1); }
	static void SetCharGetOutUpsideDownCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_GET_OUT_UPSIDE_DOWN_CAR", p0, p1); }
	static void SetCharMaxTimeInWater(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MAX_TIME_IN_WATER", p0, p1); }
	static void SetCharMaxTimeUnderwater(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MAX_TIME_UNDERWATER", p0, p1); }
	static void SetCharMeleeActionFlag0(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MELEE_ACTION_FLAG0", p0, p1); }
	static void SetCharMeleeActionFlag1(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MELEE_ACTION_FLAG1", p0, p1); }
	static void SetCharMeleeMovementConstaintBox(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MELEE_MOVEMENT_CONSTAINT_BOX", p0, p1, p2, p3, p4, p5, p6); }
	static void SetCharMoveAnimSpeedMultiplier(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_MOVE_ANIM_SPEED_MULTIPLIER", p0, p1); }
	static void SetCharNeverTargetted(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_NEVER_TARGETTED", p0, p1); }
	static void SetCharOnlyDamagedByPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ONLY_DAMAGED_BY_PLAYER", p0, p1); }
	static void SetCharReadyToBeExecuted(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_READY_TO_BE_EXECUTED", p0, p1); }
	static void SetCharReadyToBeStunned(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_READY_TO_BE_STUNNED", p0, p1); }
	static void SetCharRotation(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ROTATION", p0, p1, p2, p3); }
	static void SetCharShootRate(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_SHOOT_RATE", p0, p1); }
	static void SetCharStayInCarWhenJacked(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_STAY_IN_CAR_WHEN_JACKED", p0, p1); }
	static void SetCharUsesDeafultAnimGroupWhenFleeing(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_USES_DEAFULT_ANIM_GROUP_WHEN_FLEEING", p0, p1); }
	static void SetCharWeaponSkill(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WEAPON_SKILL", p0, p1); }
	static void SetCharWillCowerInsteadOfFleeing(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", p0, p1); }
	static void SetCharWillLeaveCarInCombat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_LEAVE_CAR_IN_COMBAT", p0, p1); }
	static void SetCharWillOnlyFireWithClearLos(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_ONLY_FIRE_WITH_CLEAR_LOS", p0, p1); }
	static void SetCharWillRemainOnBoatAfterMissionEnds(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_REMAIN_ON_BOAT_AFTER_MISSION_ENDS", p0, p1); }
	static void SetCollideWithPeds(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_COLLIDE_WITH_PEDS", p0); }
	static void SetCreateRandomCops(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CREATE_RANDOM_COPS", p0); }
	static void SetCurrentMovie(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CURRENT_MOVIE", p0); }
	static void SetDeadCharCoordinates(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_DEAD_CHAR_COORDINATES", p0, p1, p2, p3); }
	static void SetDeadPedsDropWeapons(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_DEAD_PEDS_DROP_WEAPONS", p0); }
	static void SetDitchPoliceModels(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_DITCH_POLICE_MODELS", p0); }
	static void SetDoNotSpawnParkedCarsOnTop(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_DO_NOT_SPAWN_PARKED_CARS_ON_TOP", p0, p1); }
	static void SetDontActivateRagdollFromPlayerImpact(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_DONT_ACTIVATE_RAGDOLL_FROM_PLAYER_IMPACT", p0, p1); }
	static void SetDrawPlayerComponent(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_DRAW_PLAYER_COMPONENT", p0, p1); }
	static void SetDrunkCam(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_DRUNK_CAM", p0, p1, p2); }
	static void SetEnableNearClipScan(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ENABLE_NEAR_CLIP_SCAN", p0); }
	static void SetFakeWantedLevel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_FAKE_WANTED_LEVEL", p0); }
	static void SetHasBeenOwnedByPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_HAS_BEEN_OWNED_BY_PLAYER", p0, p1); }

	static void SetHeliBladesFullSpeed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_HELI_BLADES_FULL_SPEED", p0); }	
	static void SetInstantWidescreenBorders(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_INSTANT_WIDESCREEN_BORDERS", p0); }
	static void SetInterpFromGameToScript(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_INTERP_FROM_GAME_TO_SCRIPT", p0, p1); }
	static void SetMaxWantedLevel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MAX_WANTED_LEVEL", p0); }
	static void SetMinigameInProgress(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MINIGAME_IN_PROGRESS", p0); }
	static void SetMissionTrainCoordinates(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_MISSION_TRAIN_COORDINATES", p0, p1, p2, p3); }
	static void SetMobilePhonePosition(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_PHONE_POSITION", p0, p1, p2); }
	static void SetMobilePhoneRadioState(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_PHONE_RADIO_STATE", p0); }
	static void SetMobilePhoneRotation(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_PHONE_ROTATION", p0, p1, p2); }
	static void SetMobilePhoneScale(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_PHONE_SCALE", p0); }
	static void SetMobileRadioEnabledDuringGameplay(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY", p0); }
	static void SetMobileRingType(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOBILE_RING_TYPE", p0); }
	static void SetMoneyCarriedByAllNewPeds(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MONEY_CARRIED_BY_ALL_NEW_PEDS", p0); }

	static void SetMovieTime(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOVIE_TIME", p0); }
	static void SetMovieVolume(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MOVIE_VOLUME", p0); }
	static void SetNeedsToBeHotwired(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NEEDS_TO_BE_HOTWIRED", p0, p1); }
	static void SetNextDesiredMoveState(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_NEXT_DESIRED_MOVE_STATE", p0); }

	static void SetNoResprays(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_NO_RESPRAYS", p0); }

	static void SetObjectAlpha(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_ALPHA", p0, p1); }
	static void SetObjectAnimCurrentTime(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_ANIM_CURRENT_TIME", p0, p1, p2, p3); }
	static void SetObjectAnimSpeed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_ANIM_SPEED", p0, p1, p2, p3); }
	static void SetObjectAsStealable(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_AS_STEALABLE", p0, p1); }
	static void SetObjectDynamic(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_DYNAMIC", p0, p1); }
	static void SetObjectHealth(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_HEALTH", p0, p1); }
	static void SetObjectInitialVelocity(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_INITIAL_VELOCITY", p0, p1, p2, p3); }
	static void SetObjectInvincible(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_INVINCIBLE", p0, p1); }
	static void SetObjectLights(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_LIGHTS", p0, p1); }
	static void SetObjectOnlyDamagedByPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_ONLY_DAMAGED_BY_PLAYER", p0, p1); }
	static void SetObjectPhysicsParams(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_PHYSICS_PARAMS", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static void SetObjectQuaternion(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_QUATERNION", p0, p1, p2, p3, p4); }
	static void SetObjectRotation(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_ROTATION", p0, p1, p2, p3); }
	static void SetObjectScale(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_SCALE", p0, p1); }
	static void SetObjectUsedInPoolGame(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_USED_IN_POOL_GAME", p0, p1); }
	static void SetParkedCarDensityMultiplier(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PARKED_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetPedAlpha(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_ALPHA", p0, p1); }
	static void SetPedDensityMultiplier(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_DENSITY_MULTIPLIER", p0); }
	static void SetPedDontDoEvasiveDives(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_DONT_DO_EVASIVE_DIVES", p0, p1); }
	static void SetPedDontUseVehicleSpecificAnims(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_DONT_USE_VEHICLE_SPECIFIC_ANIMS", p0, p1); }
	static void SetPedEnableLegIK(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_ENABLE_LEG_IK", p0, p1); }
	static void SetPedGeneratesDeadBodyEvents(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_GENERATES_DEAD_BODY_EVENTS", p0, p1); }
	static void SetPedHeedsTheEveryoneIgnorePlayerFlag(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_HEEDS_THE_EVERYONE_IGNORE_PLAYER_FLAG", p0, p1); }
	static void SetPedNonCreationArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_NON_CREATION_AREA", p0, p1, p2, p3, p4, p5); }
	static void SetPedNonRemovalArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_NON_REMOVAL_AREA", p0, p1, p2, p3, p4, p5); }
	static void SetPedWontAttackPlayerWithoutWantedLevel(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_WONT_ATTACK_PLAYER_WITHOUT_WANTED_LEVEL", p0, p1); }
	static void SetPhoneHUDItem(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_PHONE_HUD_ITEM", p0, p1, p2); }
	static void SetPickupCollectableByCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PICKUP_COLLECTABLE_BY_CAR", p0, p1); }
	static void SetPickupsFixCars(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PICKUPS_FIX_CARS", p0); }

	static void SetPlayerCanDropWeaponsInCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_DROP_WEAPONS_IN_CAR", p0); }
	static void SetPlayerKeepsWeaponsWhenRespawned(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_KEEPS_WEAPONS_WHEN_RESPAWNED", p0); }


	static void SetPoliceFocusWillTrackCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_POLICE_FOCUS_WILL_TRACK_CAR", p0, p1); }
	static void SetPoliceRadarBlips(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_POLICE_RADAR_BLIPS", p0); }

	static void SetRandomCarDensityMultiplier(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RANDOM_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetRandomSeed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RANDOM_SEED", p0); }
	static void SetReducePedModelBudget(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_REDUCE_PED_MODEL_BUDGET", p0); }
	static void SetReduceVehicleModelBudget(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_REDUCE_VEHICLE_MODEL_BUDGET", p0); }

	static void SetRenderTrainAsDerailed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_RENDER_TRAIN_AS_DERAILED", p0, p1); }
	static void SetRocketLauncherFreebieInHeli(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ROCKET_LAUNCHER_FREEBIE_IN_HELI", p0); }

	static void SetRoomForCarByName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_CAR_BY_NAME", p0, p1); }
	static void SetRoomForCharByName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_CHAR_BY_NAME", p0, p1); }
	static void SetRotOrder(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ROT_ORDER", p0); }
	static void SetRotationForAttachedPed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_ROTATION_FOR_ATTACHED_PED", p0, p1, p2, p3); }
	static void SetScreenFade(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { NativeInvoke::Invoke<ScriptVoid>("SET_SCREEN_FADE", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static void SetSirenWithNoDriver(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_SIREN_WITH_NO_DRIVER", p0, p1); }
	static void SetSleepModeActive(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_SLEEP_MODE_ACTIVE", p0); }
	static void SetSniperZoomFactor(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_SNIPER_ZOOM_FACTOR", p0); }
	static void SetStateOfClosestDoorOfType(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_STATE_OF_CLOSEST_DOOR_OF_TYPE", p0, p1, p2, p3, p4, p5); }
	static void SetSyncWeatherAndGameTime(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_SYNC_WEATHER_AND_GAME_TIME", p0); }
	static void SetTaxiGarageRadioState(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_TAXI_GARAGE_RADIO_STATE", p0); }
	static void SetTaxiLights(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TAXI_LIGHTS", p0, p1); }

	static void SetThisScriptCanRemoveBlipsCreatedByAnyScript(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT", p0); }
	static void SetTrainAudioRolloff(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_AUDIO_ROLLOFF", p0, p1); }
	static void SetTrainCruiseSpeed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_CRUISE_SPEED", p0, p1); }
	static void SetTrainForcedToSlowDown(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_FORCED_TO_SLOW_DOWN", p0, p1); }
	static void SetTrainIsStoppedAtStation(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_IS_STOPPED_AT_STATION", p0); }
	static void SetTrainSpeed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_SPEED", p0, p1); }
	static void SetTrainStopsForStations(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_TRAIN_STOPS_FOR_STATIONS", p0, p1); }
	static void SetUseHighDOF(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_USE_HIGHDOF", p0); }
	static void SetUseLegIK(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_USE_LEG_IK", p0, p1); }


	static void SetVehAlarm(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEH_ALARM", p0, p1); }
	static void SetVehHasStrongAxles(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEH_HAS_STRONG_AXLES", p0, p1); }
	static void SetVehInteriorlight(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEH_INTERIORLIGHT", p0, p1); }
	static void SetVehicleAlpha(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_ALPHA", p0, p1); }
	static void SetVehicleCanBeTargetted(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_CAN_BE_TARGETTED", p0, p1); }
	static void SetVehicleIsConsideredByPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_IS_CONSIDERED_BY_PLAYER", p0, p1); }
	static void SetVehicleQuaternion(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_QUATERNION", p0, p1, p2, p3, p4); }
	static void SetVehicleSteerBias(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VEHICLE_STEER_BIAS", p0, p1); }

	static void SetWidescreenBorders(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_WIDESCREEN_BORDERS", p0); }
	static void SetWidescreenFormat(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_WIDESCREEN_FORMAT", p0); }
	static void SetZoneNoCops(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ZONE_NO_COPS", p0, p1); }
	static void SetZonePopulationType(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ZONE_POPULATION_TYPE", p0, p1); }
	static void SetZoneScumminess(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ZONE_SCUMMINESS", p0, p1); }
	static void ShakePad(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SHAKE_PAD", p0, p1, p2); }
	static void ShakePlayerpadWhenControllerDisabled() { NativeInvoke::Invoke<ScriptVoid>("SHAKE_PLAYERPAD_WHEN_CONTROLLER_DISABLED"); }
	static void SkipRadioForward() { NativeInvoke::Invoke<ScriptVoid>("SKIP_RADIO_FORWARD"); }

	static void SkipToNextAllowedStation(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SKIP_TO_NEXT_ALLOWED_STATION", p0); }
	static ScriptAny SlideObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("SLIDE_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void SmashCarWindow(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SMASH_CAR_WINDOW", p0, p1); }
	static ScriptAny SmashGlassOnObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("SMASH_GLASS_ON_OBJECT", p0, p1, p2, p3, p4, p5); }
	static void StartFiringAmnesty() { NativeInvoke::Invoke<ScriptVoid>("START_FIRING_AMNESTY"); }
	static ScriptAny StartNewScript(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("START_NEW_SCRIPT", p0, p1); }
	static ScriptAny StartNewScriptWithArgs(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("START_NEW_SCRIPT_WITH_ARGS", p0, p1, p2, p3); }

	static void StopCarBreaking(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("STOP_CAR_BREAKING", p0, p1); }
	static void StopMovie() { NativeInvoke::Invoke<ScriptVoid>("STOP_MOVIE"); }
	static void StopPedDoingFallOffTestsWhenShot(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STOP_PED_DOING_FALL_OFF_TESTS_WHEN_SHOT", p0); }
	static void StopPedSpeaking(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("STOP_PED_SPEAKING", p0, p1); }
	static void StopPedWeaponFiringWhenDropped(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STOP_PED_WEAPON_FIRING_WHEN_DROPPED", p0); }
	static void SuppressCarModel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SUPPRESS_CAR_MODEL", p0); }
	static void SuppressPedModel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SUPPRESS_PED_MODEL", p0); }
	static void SwapNearestBuildingModel(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWAP_NEAREST_BUILDING_MODEL", p0, p1, p2, p3, p4, p5); }
	
	static void SwitchCarSiren(Car car, b8 on) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_CAR_SIREN", car, on); }

	static ScriptAny SwitchPedToRagdollWithFall(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13) { return NativeInvoke::Invoke<ScriptAny>("SWITCH_PED_TO_RAGDOLL_WITH_FALL", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	static void SwitchRoadsBackToOriginal(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_ROADS_BACK_TO_ORIGINAL", p0, p1, p2, p3, p4, p5); }
	static void SwitchRoadsOff(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_ROADS_OFF", p0, p1, p2, p3, p4, p5); }
	static void SwitchRoadsOn(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_ROADS_ON", p0, p1, p2, p3, p4, p5); }

	static ScriptAny UsingStandardControls() { return NativeInvoke::Invoke<ScriptAny>("USING_STANDARD_CONTROLS"); }

	static ScriptAny UpdateLoadScene() { return NativeInvoke::Invoke<ScriptAny>("UPDATE_LOAD_SCENE"); }

// For later....

	static ScriptAny AbortScriptedConversation(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("ABORT_SCRIPTED_CONVERSATION", p0); }
	static void ActivateDamageTrackerOnNetworkId(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_DAMAGE_TRACKER_ON_NETWORK_ID", p0, p1); }
	static void ActivateHeliSpeedCheat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_HELI_SPEED_CHEAT", p0, p1); }
	static void ActivateNetworkSettingsMenu() { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_NETWORK_SETTINGS_MENU"); }
	static void ActivateScriptedCams(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_SCRIPTED_CAMS", p0, p1); }
	static void ActivateViewport(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ACTIVATE_VIEWPORT", p0, p1); }
	static void AddCamSplineNode(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ADD_CAM_SPLINE_NODE", p0, p1); }
	static void AddCarToMissionDeletionList(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_CAR_TO_MISSION_DELETION_LIST", p0); }
	static void AddCoverBlockingArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("ADD_COVER_BLOCKING_AREA", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void AddCoverPoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("ADD_COVER_POINT", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void AddFollowNavmeshToPhoneTask(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("ADD_FOLLOW_NAVMESH_TO_PHONE_TASK", p0, p1, p2, p3); }
	static void AddGroupToNetworkRestartNodeGroupList(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_GROUP_TO_NETWORK_RESTART_NODE_GROUP_LIST", p0); }
	static void AddHospitalRestart(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("ADD_HOSPITAL_RESTART", p0, p1, p2, p3, p4); }
	static void AddLineToConversation(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("ADD_LINE_TO_CONVERSATION", p0, p1, p2, p3, p4); }
	static void AddLineToMobilePhoneCall(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("ADD_LINE_TO_MOBILE_PHONE_CALL", p0, p1, p2); }
	static void AddNeededAtPosN(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("ADD_NEEDED_AT_POSN", p0, p1, p2); }
	static void AddNewConversationSpeaker(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("ADD_NEW_CONVERSATION_SPEAKER", p0, p1, p2); }
	static void AddNextMessageToPreviousBriefs(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_NEXT_MESSAGE_TO_PREVIOUS_BRIEFS", p0); }
	static void AddObjectToInteriorRoomByName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ADD_OBJECT_TO_INTERIOR_ROOM_BY_NAME", p0, p1); }
	static void AddPedToMissionDeletionList(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ADD_PED_TO_MISSION_DELETION_LIST", p0, p1); }
	static void AddPointToGpsRaceTrack(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_POINT_TO_GPS_RACE_TRACK", p0); }
	static void AddPoliceRestart(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("ADD_POLICE_RESTART", p0, p1, p2, p3, p4); }
	static void AddScenarioBlockingArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("ADD_SCENARIO_BLOCKING_AREA", p0, p1, p2, p3, p4, p5); }
	static void AddSpawnBlockingArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("ADD_SPAWN_BLOCKING_AREA", p0, p1, p2, p3); }
	static void AddStringToNewsScrollbar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_STRING_TO_NEWS_SCROLLBAR", p0); }
	static void AddStuckCarCheck(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("ADD_STUCK_CAR_CHECK", p0, p1, p2); }
	static void AddStuckCarCheckWithWarp(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("ADD_STUCK_CAR_CHECK_WITH_WARP", p0, p1, p2, p3, p4, p5, p6); }
	static void AddStuntJump(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13, ScriptAny p14, ScriptAny p15) { NativeInvoke::Invoke<ScriptVoid>("ADD_STUNT_JUMP", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); }
	static void AddToHtmlScriptObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ADD_TO_HTML_SCRIPT_OBJECT", p0, p1); }
	static void AddToPreviousBrief(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_TO_PREVIOUS_BRIEF", p0); }
	static void AddToPreviousBriefWithUnderscore(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_TO_PREVIOUS_BRIEF_WITH_UNDERSCORE", p0); }
	static void AddToWidgetCombo(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ADD_TO_WIDGET_COMBO", p0); }
	static ScriptAny AddWidgetFloatReadOnly(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("ADD_WIDGET_FLOAT_READ_ONLY", p0, p1); }
	static ScriptAny AddWidgetFloatSlider(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("ADD_WIDGET_FLOAT_SLIDER", p0, p1, p2, p3, p4); }
	static ScriptAny AddWidgetReadOnly(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("ADD_WIDGET_READ_ONLY", p0, p1); }
	static ScriptAny AddWidgetSlider(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("ADD_WIDGET_SLIDER", p0, p1, p2, p3, p4); }
	static ScriptAny AddWidgetToggle(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("ADD_WIDGET_TOGGLE", p0, p1); }
	static void AllocateScriptToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("ALLOCATE_SCRIPT_TO_OBJECT", p0, p1, p2, p3, p4); }
	static void AllocateScriptToRandomPed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("ALLOCATE_SCRIPT_TO_RANDOM_PED", p0, p1, p2, p3); }
	static void AllowAutoConversationLookats(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_AUTO_CONVERSATION_LOOKATS", p0, p1); }
	static void AllowLockonToFriendlyPlayers(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_LOCKON_TO_FRIENDLY_PLAYERS", p0, p1); }
	static void AllowMultipleDrivebyPickups(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_MULTIPLE_DRIVEBY_PICKUPS", p0); }
	static ScriptAny AllowOneTimeOnlyCommandsToRun() { return NativeInvoke::Invoke<ScriptAny>("ALLOW_ONE_TIME_ONLY_COMMANDS_TO_RUN"); }
	static void AllowReactionAnims(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_REACTION_ANIMS", p0, p1); }
	static void AllowTargetWhenInjured(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_TARGET_WHEN_INJURED", p0, p1); }
	static void AllowThisScriptToBePaused(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_THIS_SCRIPT_TO_BE_PAUSED", p0); }
	static void AlwaysUseHeadOnHornAnimWhenDeadInCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ALWAYS_USE_HEAD_ON_HORN_ANIM_WHEN_DEAD_IN_CAR", p0, p1); }
	static void AmbientAudioBankNoLongerNeeded() { NativeInvoke::Invoke<ScriptVoid>("AMBIENT_AUDIO_BANK_NO_LONGER_NEEDED"); }
	static void AnchorObject(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("ANCHOR_OBJECT", p0, p1, p2); }
	static ScriptAny AreEnemyPedsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("ARE_ENEMY_PEDS_IN_AREA", p0, p1, p2, p3, p4); }
	static void AttachCamToObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_CAM_TO_OBJECT", p0, p1); }
	static void AttachCamToPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_CAM_TO_PED", p0, p1); }
	static void AttachCamToVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_CAM_TO_VEHICLE", p0, p1); }
	static void AttachCarToCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_CAR_TO_CAR", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void AttachCarToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_CAR_TO_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void AttachObjectToCarPhysically(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13, ScriptAny p14) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_CAR_PHYSICALLY", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14); }
	static void AttachObjectToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_OBJECT_TO_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void AttachPedToCarPhysically(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_PED_TO_CAR_PHYSICALLY", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void AttachPedToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("ATTACH_PED_TO_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void BeginCamCommands(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("BEGIN_CAM_COMMANDS", p0); }
	static void BlendFromNmWithAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("BLEND_FROM_NM_WITH_ANIM", p0, p1, p2, p3, p4, p5, p6); }
	static void BlendOutCharMoveAnims(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("BLEND_OUT_CHAR_MOVE_ANIMS", p0); }
	static void BlockCharAmbientAnims(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_CHAR_AMBIENT_ANIMS", p0, p1); }
	static void BlockCharHeadIk(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_CHAR_HEAD_IK", p0, p1); }
	static void BlockCharVisemeAnims(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_CHAR_VISEME_ANIMS", p0, p1); }
	static void BlockCoweringInCover(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_COWERING_IN_COVER", p0, p1); }
	static void BlockPeekingInCover(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("BLOCK_PEEKING_IN_COVER", p0, p1); }
	static void CamProcess(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CAM_PROCESS", p0); }
	static void CamSetInterpGraphPos(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CAM_SET_INTERP_GRAPH_POS", p0, p1); }
	static void CamSetInterpGraphRot(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CAM_SET_INTERP_GRAPH_ROT", p0, p1); }
	static ScriptAny CanCreateRandomChar(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("CAN_CREATE_RANDOM_CHAR", p0, p1); }
	static ScriptAny CanPlayerStartMission(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CAN_PLAYER_START_MISSION", p0); }
	static ScriptAny CanRegisterMissionObject() { return NativeInvoke::Invoke<ScriptAny>("CAN_REGISTER_MISSION_OBJECT"); }
	static ScriptAny CanRegisterMissionPed() { return NativeInvoke::Invoke<ScriptAny>("CAN_REGISTER_MISSION_PED"); }
	static ScriptAny CanRegisterMissionVehicle() { return NativeInvoke::Invoke<ScriptAny>("CAN_REGISTER_MISSION_VEHICLE"); }
	static ScriptAny CanStartMissionPassedTune() { return NativeInvoke::Invoke<ScriptAny>("CAN_START_MISSION_PASSED_TUNE"); }
	static ScriptAny CanTheStatHaveString(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CAN_THE_STAT_HAVE_STRING", p0); }
	static void CellCamActivate(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CELL_CAM_ACTIVATE", p0, p1); }
	static ScriptAny CellCamIsCharVisible(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CELL_CAM_IS_CHAR_VISIBLE", p0); }
	static ScriptAny CellCamIsCharVisibleNoFaceCheck(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CELL_CAM_IS_CHAR_VISIBLE_NO_FACE_CHECK", p0); }
	static void CellCamSetCentrePos(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CELL_CAM_SET_CENTRE_POS", p0, p1); }
	static void CellCamSetZoom(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CELL_CAM_SET_ZOOM", p0); }
	static void ChangeCharSitIdleAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_CHAR_SIT_IDLE_ANIM", p0, p1, p2, p3); }
	static void ChangeGarageType(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_GARAGE_TYPE", p0, p1); }
	static void ChangePickupBlipColour(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PICKUP_BLIP_COLOUR", p0); }
	static void ChangePickupBlipDisplay(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PICKUP_BLIP_DISPLAY", p0); }
	static void ChangePickupBlipPriority(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PICKUP_BLIP_PRIORITY", p0); }
	static void ChangePickupBlipScale(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PICKUP_BLIP_SCALE", p0); }
	static void ChangePickupBlipSprite(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PICKUP_BLIP_SPRITE", p0); }
	static void ChangePlaybackToUseAI(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PLAYBACK_TO_USE_AI", p0); }
	static ScriptAny CheckNmFeedback(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("CHECK_NM_FEEDBACK", p0, p1, p2); }
	static ScriptAny CheckStuckTimer(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("CHECK_STUCK_TIMER", p0, p1, p2); }
	static void ClearAdditionalText(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ADDITIONAL_TEXT", p0, p1); }
	static void ClearAngledAreaOfCars(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ANGLED_AREA_OF_CARS", p0, p1, p2, p3, p4, p5, p6); }
	static void ClearBit(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_BIT", p0, p1); }
	static void ClearBrief() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_BRIEF"); }
	static void ClearCharRelationship(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_RELATIONSHIP", p0, p1, p2); }
	static void ClearHelp() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_HELP"); }
	static void ClearNamedCutscene(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_NAMED_CUTSCENE", p0); }
	static void ClearNetworkRestartNodeGroupList() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_NETWORK_RESTART_NODE_GROUP_LIST"); }
	static void ClearNewsScrollbar() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_NEWS_SCROLLBAR"); }
	static void ClearOnscreenCounter(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ONSCREEN_COUNTER", p0); }
	static void ClearOnscreenTimer(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ONSCREEN_TIMER", p0); }
	static void ClearPrints() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_PRINTS"); }
	static void ClearRelationship(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_RELATIONSHIP", p0, p1, p2); }
	static void ClearRoomForViewport(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_VIEWPORT", p0); }
	static void ClearScriptArrayFromScratchpad(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_SCRIPT_ARRAY_FROM_SCRATCHPAD", p0); }
	static void ClearScriptedConversionCentre() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_SCRIPTED_CONVERSION_CENTRE"); }
	static void ClearSmallPrints() { NativeInvoke::Invoke<ScriptVoid>("CLEAR_SMALL_PRINTS"); }
	static void ClearTextLabel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_TEXT_LABEL", p0); }
	static void ClearThisPrint(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_THIS_PRINT", p0); }
	static void ClearThisPrintBigNow(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_THIS_PRINT_BIG_NOW", p0); }
	static void CloseDebugFile() { NativeInvoke::Invoke<ScriptVoid>("CLOSE_DEBUG_FILE"); }
	static ScriptAny CodeWantsMobilePhoneRemoved() { return NativeInvoke::Invoke<ScriptAny>("CODE_WANTS_MOBILE_PHONE_REMOVED"); }
	static ScriptAny CodeWantsMobilePhoneRemovedForWeaponSwitching() { return NativeInvoke::Invoke<ScriptAny>("CODE_WANTS_MOBILE_PHONE_REMOVED_FOR_WEAPON_SWITCHING"); }
	static ScriptAny CompareString(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("COMPARE_STRING", p0, p1); }
	static ScriptAny CompareTwoDates(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("COMPARE_TWO_DATES", p0, p1, p2, p3); }
	static void CopyAnimations(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("COPY_ANIMATIONS", p0, p1, p2); }
	static ScriptAny CountPickupsOfType(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("COUNT_PICKUPS_OF_TYPE", p0); }
	static ScriptAny CountScriptCams() { return NativeInvoke::Invoke<ScriptAny>("COUNT_SCRIPT_CAMS"); }
	static ScriptAny CountScriptCamsByTypeAndOrState(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("COUNT_SCRIPT_CAMS_BY_TYPE_AND_OR_STATE", p0, p1, p2); }
	static void CreateCarGenerator(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13, ScriptAny p14) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CAR_GENERATOR", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14); }
	static ScriptAny CreateCheckpoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("CREATE_CHECKPOINT", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny CreateEmergencyServicesCarReturnDriver(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("CREATE_EMERGENCY_SERVICES_CAR_RETURN_DRIVER", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny CreateEmergencyServicesCarThenWalk(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("CREATE_EMERGENCY_SERVICES_CAR_THEN_WALK", p0, p1, p2, p3); }
	static ScriptAny CreateHtmlScriptObject(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CREATE_HTML_SCRIPT_OBJECT", p0); }
	static void CreateHtmlViewport(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CREATE_HTML_VIEWPORT", p0); }
	static void CreateMobilePhone(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("CREATE_MOBILE_PHONE", p0); }
	static void CreateNmMessage(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("CREATE_NM_MESSAGE", p0, p1); }
	static void CreateTemporaryRadarBlipsForPickupsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("CREATE_TEMPORARY_RADAR_BLIPS_FOR_PICKUPS_IN_AREA", p0, p1, p2, p3, p4); }
	static ScriptAny CreateWidgetGroup(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("CREATE_WIDGET_GROUP", p0); }
	static void DeactivateNetworkSettingsMenu() { NativeInvoke::Invoke<ScriptVoid>("DEACTIVATE_NETWORK_SETTINGS_MENU"); }
	static void DebugOff() { NativeInvoke::Invoke<ScriptVoid>("DEBUG_OFF"); }
	static void DeleteAllHtmlScriptObjects() { NativeInvoke::Invoke<ScriptVoid>("DELETE_ALL_HTML_SCRIPT_OBJECTS"); }
	static void DeleteAllTrains() { NativeInvoke::Invoke<ScriptVoid>("DELETE_ALL_TRAINS"); }
	static void DeleteCarGenerator(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DELETE_CAR_GENERATOR", p0); }
	static void DeleteCheckpoint(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DELETE_CHECKPOINT", p0); }
	static void DeleteHtmlScriptObject(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DELETE_HTML_SCRIPT_OBJECT", p0); }
	static void DeleteWidgetGroup(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DELETE_WIDGET_GROUP", p0); }
	static void DestroyAllCams() { NativeInvoke::Invoke<ScriptVoid>("DESTROY_ALL_CAMS"); }
	static void DestroyMobilePhone() { NativeInvoke::Invoke<ScriptVoid>("DESTROY_MOBILE_PHONE"); }
	static void DestroyThread(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DESTROY_THREAD", p0); }
	static void DestroyViewport(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DESTROY_VIEWPORT", p0); }
	static void DisableCarGenerators(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_CAR_GENERATORS", p0); }
	static void DisableCarGeneratorsWithHeli(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_CAR_GENERATORS_WITH_HELI", p0); }
	static void DisableEndCreditsFade() { NativeInvoke::Invoke<ScriptVoid>("DISABLE_END_CREDITS_FADE"); }
	static void DisableGPS(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_GPS", p0); }
	static void DisplayHelpTextThisFrame(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_HELP_TEXT_THIS_FRAME", p0, p1); }
	static void DisplayNonMinigameHelpMessages(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_NON_MINIGAME_HELP_MESSAGES", p0); }
	static void DisplayPlaybackRecordedCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_PLAYBACK_RECORDED_CAR", p0, p1); }
	static void DisplayPlayerNames(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DISPLAY_PLAYER_NAMES", p0); }
	static ScriptAny DoesGameCodeWantToLeaveNetworkSession() { return NativeInvoke::Invoke<ScriptAny>("DOES_GAME_CODE_WANT_TO_LEAVE_NETWORK_SESSION"); }
	static ScriptAny DoesObjectExistWithNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_OBJECT_EXIST_WITH_NETWORK_ID", p0); }
	static ScriptAny DoesPedExistWithNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_PED_EXIST_WITH_NETWORK_ID", p0); }
	static ScriptAny DoesScenarioExistInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("DOES_SCENARIO_EXIST_IN_AREA", p0, p1, p2, p3, p4); }
	static ScriptAny DoesScriptExist(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_SCRIPT_EXIST", p0); }
	static ScriptAny DoesTextLabelExist(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_TEXT_LABEL_EXIST", p0); }
	static ScriptAny DoesThisMinigameScriptAllowNonMinigameHelpMessages() { return NativeInvoke::Invoke<ScriptAny>("DOES_THIS_MINIGAME_SCRIPT_ALLOW_NON_MINIGAME_HELP_MESSAGES"); }
	static ScriptAny DoesVehicleExistWithNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_VEHICLE_EXIST_WITH_NETWORK_ID", p0); }
	static ScriptAny DoesViewportExist(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_VIEWPORT_EXIST", p0); }
	static ScriptAny DoesWebPageExist(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_WEB_PAGE_EXIST", p0); }
	static ScriptAny DoesWidgetGroupExist(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("DOES_WIDGET_GROUP_EXIST", p0); }
	static void DontAbortCarConversations(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("DONT_ABORT_CAR_CONVERSATIONS", p0, p1); }
	static void DontDispatchCopsForPlayer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("DONT_DISPATCH_COPS_FOR_PLAYER", p0, p1); }
	static void DontDisplayLoadingOnFadeThisFrame() { NativeInvoke::Invoke<ScriptVoid>("DONT_DISPLAY_LOADING_ON_FADE_THIS_FRAME"); }
	static void DontSuppressAnyPedModels() { NativeInvoke::Invoke<ScriptVoid>("DONT_SUPPRESS_ANY_PED_MODELS"); }
	static void DontSuppressCarModel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DONT_SUPPRESS_CAR_MODEL", p0); }
	static void DontSuppressPedModel(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("DONT_SUPPRESS_PED_MODEL", p0); }
	static void DrawCheckpoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("DRAW_CHECKPOINT", p0, p1, p2, p3, p4, p5, p6); }
	static void DrawCheckpointWithAlpha(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("DRAW_CHECKPOINT_WITH_ALPHA", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void DrawColouredCylinder(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("DRAW_COLOURED_CYLINDER", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void DrawCurvedWindow(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("DRAW_CURVED_WINDOW", p0, p1, p2, p3, p4); }
	static void DrawFrontendHelperText(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("DRAW_FRONTEND_HELPER_TEXT", p0, p1, p2); }
	static void DrawLightWithRange(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("DRAW_LIGHT_WITH_RANGE", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void DrawMovie(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("DRAW_MOVIE", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void DrawSprite(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("DRAW_SPRITE", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void DrawSpritePhoto(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("DRAW_SPRITE_PHOTO", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void EnableChaseAudio(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_CHASE_AUDIO", p0); }
	static void EnableEndCreditsFade() { NativeInvoke::Invoke<ScriptVoid>("ENABLE_END_CREDITS_FADE"); }
	static void EnableSaveHouse(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_SAVE_HOUSE", p0, p1); }
	static void EnableXboxScreenSaver(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("ENABLE_XBOX_SCREEN_SAVER", p0); }
	static void EndCamCommands(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("END_CAM_COMMANDS", p0); }
	static void EndWidgetGroup() { NativeInvoke::Invoke<ScriptVoid>("END_WIDGET_GROUP"); }
	static void EvolvePtFx(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("EVOLVE_PTFX", p0, p1, p2); }
	static void ExplodeCarInCutscene(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("EXPLODE_CAR_IN_CUTSCENE", p0, p1); }
	static void FindNearestCollectableBinBags(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("FIND_NEAREST_COLLECTABLE_BIN_BAGS", p0, p1, p2); }
	static ScriptAny FindNetworkKillerOfPlayer(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("FIND_NETWORK_KILLER_OF_PLAYER", p0); }
	static ScriptAny FindPositionInRecording(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("FIND_POSITION_IN_RECORDING", p0); }
	static void FindPrimaryPopulationZoneGroup(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("FIND_PRIMARY_POPULATION_ZONE_GROUP", p0, p1); }
	static ScriptAny FindTimePositionInRecording(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("FIND_TIME_POSITION_IN_RECORDING", p0); }
	static ScriptAny FinishWidgetCombo(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("FINISH_WIDGET_COMBO", p0, p1); }
	static void FlashRoute(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("FLASH_ROUTE", p0); }
	static void FlushAllOutOfDateRadarBlipsFromMissionCleanupList() { NativeInvoke::Invoke<ScriptVoid>("FLUSH_ALL_OUT_OF_DATE_RADAR_BLIPS_FROM_MISSION_CLEANUP_LIST"); }
	static void FlushAllSpawnBlockingAreas() { NativeInvoke::Invoke<ScriptVoid>("FLUSH_ALL_SPAWN_BLOCKING_AREAS"); }
	static void FlushCoverBlockingAreas() { NativeInvoke::Invoke<ScriptVoid>("FLUSH_COVER_BLOCKING_AREAS"); }
	static void FlushScenarioBlockingAreas() { NativeInvoke::Invoke<ScriptVoid>("FLUSH_SCENARIO_BLOCKING_AREAS"); }
	static void ForceAirDragMultForPlayersCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("FORCE_AIR_DRAG_MULT_FOR_PLAYERS_CAR", p0, p1); }
	static void ForceFullVoice(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("FORCE_FULL_VOICE", p0); }
	static void ForceHighLod(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("FORCE_HIGH_LOD", p0); }
	static void ForceNoCamPause(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("FORCE_NO_CAM_PAUSE", p0); }
	static void ForcePedToLoadCover(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("FORCE_PED_TO_LOAD_COVER", p0, p1); }
	static void ForceRadioTrack(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("FORCE_RADIO_TRACK", p0, p1, p2, p3); }
	static void ForceSpawnScenarioPedsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("FORCE_SPAWN_SCENARIO_PEDS_IN_AREA", p0, p1, p2, p3, p4); }
	static void GenerateDirections(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("GENERATE_DIRECTIONS", p0, p1, p2, p3, p4); }
	static ScriptAny GetAudibleMusicTrackTextId() { return NativeInvoke::Invoke<ScriptAny>("GET_AUDIBLE_MUSIC_TRACK_TEXT_ID"); }
	static ScriptAny GetBitsInRange(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("GET_BITS_IN_RANGE", p0, p1, p2); }
	static void GetCarModelValue(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_CAR_MODEL_VALUE", p0, p1); }
	static void GetCinematicCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_CINEMATIC_CAM", p0); }
	static ScriptAny GetClosestNetworkRestartNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("GET_CLOSEST_NETWORK_RESTART_NODE", p0, p1, p2, p3, p4); }
	static ScriptAny GetClosestRoad(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { return NativeInvoke::Invoke<ScriptAny>("GET_CLOSEST_ROAD", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void GetCoordinatesForNetworkRestartNode(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GET_COORDINATES_FOR_NETWORK_RESTART_NODE", p0, p1, p2); }
	static ScriptAny GetCurrentPlaybackNumberForCar(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_CURRENT_PLAYBACK_NUMBER_FOR_CAR", p0); }	
	static ScriptAny GetCurrentScriptedConversationLine() { return NativeInvoke::Invoke<ScriptAny>("GET_CURRENT_SCRIPTED_CONVERSATION_LINE"); }
	static ScriptAny GetCutsceneAudioTimeMs() { return NativeInvoke::Invoke<ScriptAny>("GET_CUTSCENE_AUDIO_TIME_MS"); }
	static void GetCutscenePedPosition(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_CUTSCENE_PED_POSITION", p0, p1); }
	static ScriptAny GetCutsceneSectionPlaying() { return NativeInvoke::Invoke<ScriptAny>("GET_CUTSCENE_SECTION_PLAYING"); }
	static ScriptAny GetCutsceneTime() { return NativeInvoke::Invoke<ScriptAny>("GET_CUTSCENE_TIME"); }
	static void GetDebugCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_DEBUG_CAM", p0); }
	static ScriptAny GetDestroyerOfNetworkId(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("GET_DESTROYER_OF_NETWORK_ID", p0, p1); }
	static void GetFollowVehicleCamSubmode(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_FOLLOW_VEHICLE_CAM_SUBMODE", p0); }
	static void GetFrontEndDesignValue(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GET_FRONTEND_DESIGN_VALUE", p0, p1, p2); }
	static void GetGameViewportId(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_GAME_VIEWPORT_ID", p0); }
	static ScriptAny GetGamerNetworkScore(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("GET_GAMER_NETWORK_SCORE", p0, p1, p2); }
	static void GetHelpMessageBoxSize(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_HELP_MESSAGE_BOX_SIZE", p0, p1); }
	static ScriptAny GetHostId() { return NativeInvoke::Invoke<ScriptAny>("GET_HOST_ID"); }
	static void GetKeyForViewportInRoom(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_KEY_FOR_VIEWPORT_IN_ROOM", p0, p1); }
	static ScriptAny GetLocalGamerlevelFromProfilesettings() { return NativeInvoke::Invoke<ScriptAny>("GET_LOCAL_GAMERLEVEL_FROM_PROFILESETTINGS"); }
	static ScriptAny GetLocalPlayerMPCash() { return NativeInvoke::Invoke<ScriptAny>("GET_LOCAL_PLAYER_MP_CASH"); }
	static ScriptAny GetMobilePhoneTaskSubTask(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("GET_MOBILE_PHONE_TASK_SUB_TASK", p0, p1); }
	static ScriptAny GetMotionControlPreference(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_MOTION_CONTROL_PREFERENCE", p0); }
	static void GetNetworkIdFromObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_NETWORK_ID_FROM_OBJECT", p0, p1); }
	static void GetNetworkIdFromPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_NETWORK_ID_FROM_PED", p0, p1); }
	static void GetNetworkIdFromVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_NETWORK_ID_FROM_VEHICLE", p0, p1); }
	static void GetNetworkTimer(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_NETWORK_TIMER", p0); }
	static ScriptAny GetNextClosestCarNodeWithHeadingOnIsland(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("GET_NEXT_CLOSEST_CAR_NODE_WITH_HEADING_ON_ISLAND", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny GetNoOfPlayersInTeam(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_NO_OF_PLAYERS_IN_TEAM", p0); }
	static ScriptAny GetNthClosestCarNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("GET_NTH_CLOSEST_CAR_NODE", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny GetNthClosestCarNodeFavourDirection(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("GET_NTH_CLOSEST_CAR_NODE_FAVOUR_DIRECTION", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny GetNumberOfWebPageLinks(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_NUMBER_OF_WEB_PAGE_LINKS", p0); }
	static void GetObjectFromNetworkId(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_OBJECT_FROM_NETWORK_ID", p0, p1); }
	static void GetPedFromNetworkId(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_PED_FROM_NETWORK_ID", p0, p1); }
	static ScriptAny GetPlayerRankLevelDuringMP(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_PLAYER_RANK_LEVEL_DURING_MP", p0); }
	static void GetPlayerRGBColour(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("GET_PLAYER_RGB_COLOUR", p0, p1, p2, p3); }
	static ScriptAny GetPlayerTeam(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_PLAYER_TEAM", p0); }
	static void GetPositionOfCarRecordingAtTime(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GET_POSITION_OF_CAR_RECORDING_AT_TIME", p0, p1, p2); }
	static ScriptAny GetProfileSetting(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_PROFILE_SETTING", p0); }
	static ScriptAny GetRandomCarNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("GET_RANDOM_CAR_NODE", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny GetRandomNetworkRestartNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("GET_RANDOM_NETWORK_RESTART_NODE", p0, p1, p2, p3, p4, p5); }
	static ScriptAny GetRandomNetworkRestartNodeUsingGroupList(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("GET_RANDOM_NETWORK_RESTART_NODE_USING_GROUP_LIST", p0, p1, p2, p3, p4, p5); }
	static void GetRootCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_ROOT_CAM", p0); }
	static void GetScreenViewportId(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_SCREEN_VIEWPORT_ID", p0); }
	static void GetScriptCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("GET_SCRIPT_CAM", p0); }
	static void GetScriptTaskStatus(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("GET_SCRIPT_TASK_STATUS", p0, p1, p2); }
	static void GetSequenceProgress(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_SEQUENCE_PROGRESS", p0, p1); }
	static ScriptAny GetSortedNetworkRestartNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("GET_SORTED_NETWORK_RESTART_NODE", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny GetSortedNetworkRestartNodeUsingGroupList(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("GET_SORTED_NETWORK_RESTART_NODE_USING_GROUP_LIST", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void GetSpawnCoordinatesForCarNode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("GET_SPAWN_COORDINATES_FOR_CAR_NODE", p0, p1, p2, p3, p4, p5); }
	static ScriptAny GetSpeechForEmergencyServiceCall() { return NativeInvoke::Invoke<ScriptAny>("GET_SPEECH_FOR_EMERGENCY_SERVICE_CALL"); }
	static void GetStateOfClosestDoorOfType(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("GET_STATE_OF_CLOSEST_DOOR_OF_TYPE", p0, p1, p2, p3, p4, p5); }
	static ScriptAny GetStringFromTextFile(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_STRING_FROM_TEXT_FILE", p0); }
	static ScriptAny GetTaskPlaceCarBombUnsuccessful() { return NativeInvoke::Invoke<ScriptAny>("GET_TASK_PLACE_CAR_BOMB_UNSUCCESSFUL"); }
	static void GetTeamRGBColour(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("GET_TEAM_RGB_COLOUR", p0, p1, p2, p3); }
	static ScriptAny GetTotalDurationOfCarRecording(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_TOTAL_DURATION_OF_CAR_RECORDING", p0); }
	static void GetVehicleFromNetworkId(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("GET_VEHICLE_FROM_NETWORK_ID", p0, p1); }
	static ScriptAny GetWebPageHeight(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("GET_WEB_PAGE_HEIGHT", p0); }
	static ScriptAny GetWebPageLinkAtPosn(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("GET_WEB_PAGE_LINK_AT_POSN", p0, p1, p2); }
	static ScriptAny GetWebPageLinkHref(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("GET_WEB_PAGE_LINK_HREF", p0, p1); }
	static void GivePedFakeNetworkName(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("GIVE_PED_FAKE_NETWORK_NAME", p0, p1, p2, p3, p4, p5); }
	static void HandleAudioAnimEvent(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("HANDLE_AUDIO_ANIM_EVENT", p0, p1); }
	static ScriptAny HasCarRecordingBeenLoaded(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("HAS_CAR_RECORDING_BEEN_LOADED", p0); }
	static ScriptAny HasCharAnimFinished(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("HAS_CHAR_ANIM_FINISHED", p0, p1, p2); }
	static ScriptAny HasControlOfNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("HAS_CONTROL_OF_NETWORK_ID", p0); }
	static ScriptAny HasCutsceneFinished() { return NativeInvoke::Invoke<ScriptAny>("HAS_CUTSCENE_FINISHED"); }
	static ScriptAny HasCutsceneLoaded() { return NativeInvoke::Invoke<ScriptAny>("HAS_CUTSCENE_LOADED"); }
	static ScriptAny HasFragmentRootOfClosestObjectOfTypeBeenDamaged(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("HAS_FRAGMENT_ROOT_OF_CLOSEST_OBJECT_OF_TYPE_BEEN_DAMAGED", p0, p1, p2, p3, p4); }
	static ScriptAny HasGamerChangedNetworkModelSettings() { return NativeInvoke::Invoke<ScriptAny>("HAS_GAMER_CHANGED_NETWORK_MODEL_SETTINGS"); }
	static ScriptAny HasNetworkPlayerLeftGame(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("HAS_NETWORK_PLAYER_LEFT_GAME", p0); }
	static ScriptAny HasOverridenSitIdleAnimFinished(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("HAS_OVERRIDEN_SIT_IDLE_ANIM_FINISHED", p0); }
	static ScriptAny HasReloadedWithMotionControl(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("HAS_RELOADED_WITH_MOTION_CONTROL", p0, p1); }
	static void HideCharWeaponForScriptedCutscene(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("HIDE_CHAR_WEAPON_FOR_SCRIPTED_CUTSCENE", p0, p1); }
	static void HintCam(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("HINT_CAM", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny HowLongHasNetworkPlayerBeenDeadFor(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("HOW_LONG_HAS_NETWORK_PLAYER_BEEN_DEAD_FOR", p0); }
	static void InitCutscene(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("INIT_CUTSCENE", p0); }
	static void InitDebugWidgets() { NativeInvoke::Invoke<ScriptVoid>("INIT_DEBUG_WIDGETS"); }
	static void InitFrontendHelperText() { NativeInvoke::Invoke<ScriptVoid>("INIT_FRONTEND_HELPER_TEXT"); }
	static ScriptAny IsAmbientSpeechDisabled(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_AMBIENT_SPEECH_DISABLED", p0); }
	static ScriptAny IsAnyCharShootingInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { return NativeInvoke::Invoke<ScriptAny>("IS_ANY_CHAR_SHOOTING_IN_AREA", p0, p1, p2, p3, p4, p5, p6); }
	static ScriptAny IsAnySpeechPlaying(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_ANY_SPEECH_PLAYING", p0); }
	static ScriptAny IsBitSet(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_BIT_SET", p0, p1); }
	static ScriptAny IsCharRespondingToEvent(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_CHAR_RESPONDING_TO_EVENT", p0, p1); }
	static ScriptAny IsDamageTrackerActiveOnNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_DAMAGE_TRACKER_ACTIVE_ON_NETWORK_ID", p0); }
	static ScriptAny IsDebugCameraOn() { return NativeInvoke::Invoke<ScriptAny>("IS_DEBUG_CAMERA_ON"); }
	static ScriptAny IsNetworkGamePending() { return NativeInvoke::Invoke<ScriptAny>("IS_NETWORK_GAME_PENDING"); }
	static ScriptAny IsNetworkGameRunning() { return NativeInvoke::Invoke<ScriptAny>("IS_NETWORK_GAME_RUNNING"); }
	static ScriptAny IsNetworkPlayerActive(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_NETWORK_PLAYER_ACTIVE", p0); }
	static ScriptAny IsNetworkSession() { return NativeInvoke::Invoke<ScriptAny>("IS_NETWORK_SESSION"); }
	static ScriptAny IsNonFragObjectSmashed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { return NativeInvoke::Invoke<ScriptAny>("IS_NON_FRAG_OBJECT_SMASHED", p0, p1, p2, p3, p4); }
	static ScriptAny IsPlaybackGoingOnForCar(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYBACK_GOING_ON_FOR_CAR", p0); }
	static ScriptAny IsPlayerLoggingInNp() { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYER_LOGGING_IN_NP"); }
	static ScriptAny IsPlayerOnlineGamespy() { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYER_ONLINE_GAMESPY"); }
	static ScriptAny IsPlayerOnlineNp() { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYER_ONLINE_NP"); }
	static ScriptAny IsPlayerReadyForCutscene(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYER_READY_FOR_CUTSCENE", p0); }
	static ScriptAny IsPlayerScriptControlOn(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_PLAYER_SCRIPT_CONTROL_ON", p0); }
	static ScriptAny IsRecordingGoingOnForCar(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_RECORDING_GOING_ON_FOR_CAR", p0); }
	static ScriptAny IsScriptedConversationOngoing() { return NativeInvoke::Invoke<ScriptAny>("IS_SCRIPTED_CONVERSATION_ONGOING"); }
	static ScriptAny IsSpecificCamInterpolating(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_SPECIFIC_CAM_INTERPOLATING", p0); }
	static ScriptAny IsSphereVisibleToAnotherMachine(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("IS_SPHERE_VISIBLE_TO_ANOTHER_MACHINE", p0, p1, p2, p3); }
	static ScriptAny IsStreamingPriorityRequests() { return NativeInvoke::Invoke<ScriptAny>("IS_STREAMING_PRIORITY_REQUESTS"); }
	static ScriptAny IsThisHelpMessageBeingDisplayed(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("IS_THIS_HELP_MESSAGE_BEING_DISPLAYED", p0); }
	static ScriptAny IsThisHelpMessageWithNumberBeingDisplayed(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_THIS_HELP_MESSAGE_WITH_NUMBER_BEING_DISPLAYED", p0, p1); }
	static ScriptAny IsThisHelpMessageWithStringBeingDisplayed(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("IS_THIS_HELP_MESSAGE_WITH_STRING_BEING_DISPLAYED", p0, p1); }
	static ScriptAny IsThisMachineTheServer() { return NativeInvoke::Invoke<ScriptAny>("IS_THIS_MACHINE_THE_SERVER"); }
	static ScriptAny IsThisPrintBeingDisplayed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { return NativeInvoke::Invoke<ScriptAny>("IS_THIS_PRINT_BEING_DISPLAYED", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static ScriptAny IsWorldPointWithinBrainActivationRange() { return NativeInvoke::Invoke<ScriptAny>("IS_WORLD_POINT_WITHIN_BRAIN_ACTIVATION_RANGE"); }
	static ScriptAny IsXbox360Version() { return NativeInvoke::Invoke<ScriptAny>("IS_XBOX360_VERSION"); }
	static void LaunchLocalPlayerInNetworkGame() { NativeInvoke::Invoke<ScriptVoid>("LAUNCH_LOCAL_PLAYER_IN_NETWORK_GAME"); }
	static void LoadPathNodesInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("LOAD_PATH_NODES_IN_AREA", p0, p1, p2, p3); }
	static void LoadWebPage(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("LOAD_WEB_PAGE", p0, p1); }
	static ScriptAny LocalPlayerIsReadyToStartPlaying() { return NativeInvoke::Invoke<ScriptAny>("LOCAL_PLAYER_IS_READY_TO_START_PLAYING"); }
	static ScriptAny LookAtNearbyEntityWithSpecialAttribute(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("LOOK_AT_NEARBY_ENTITY_WITH_SPECIAL_ATTRIBUTE", p0, p1, p2, p3, p4, p5); }
	static void MakePlayerSafeForCutscene(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("MAKE_PLAYER_SAFE_FOR_CUTSCENE", p0); }
	static void MissionAudioBankNoLongerNeeded() { NativeInvoke::Invoke<ScriptVoid>("MISSION_AUDIO_BANK_NO_LONGER_NEEDED"); }
	static void MuteGameworldAndPositionedRadioForTv(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV", p0); }
	static void MuteGameworldAudio(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("MUTE_GAMEWORLD_AUDIO", p0); }
	static void MutePositionedRadio(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("MUTE_POSITIONED_RADIO", p0); }
	static ScriptAny NetworkAcceptInvite(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_ACCEPT_INVITE", p0); }
	static ScriptAny NetworkAdvertiseSession(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_ADVERTISE_SESSION", p0); }
	static ScriptAny NetworkAllPartyMembersPresent() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_ALL_PARTY_MEMBERS_PRESENT"); }
	static ScriptAny NetworkAmIBlockedByPlayer(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_AM_I_BLOCKED_BY_PLAYER", p0); }
	static ScriptAny NetworkAmIMutedByPlayer(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_AM_I_MUTED_BY_PLAYER", p0); }
	static ScriptAny NetworkChangeGameMode(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_CHANGE_GAME_MODE", p0, p1, p2, p3); }
	static ScriptAny NetworkChangeGameModePending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_CHANGE_GAME_MODE_PENDING"); }
	static ScriptAny NetworkChangeGameModeSucceeded() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_CHANGE_GAME_MODE_SUCCEEDED"); }
	static ScriptAny NetworkCheckInviteArrival() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_CHECK_INVITE_ARRIVAL"); }
	static void NetworkClearInviteArrival() { NativeInvoke::Invoke<ScriptVoid>("NETWORK_CLEAR_INVITE_ARRIVAL"); }
	static ScriptAny NetworkClearSummons() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_CLEAR_SUMMONS"); }
	static ScriptAny NetworkDidInviteFriend(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_DID_INVITE_FRIEND", p0); }
	static ScriptAny NetworkEndSession() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_END_SESSION"); }
	static ScriptAny NetworkEndSessionPending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_END_SESSION_PENDING"); }
	static void NetworkFindGame(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_FIND_GAME", p0, p1, p2, p3); }
	static ScriptAny NetworkFindGamePending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_FIND_GAME_PENDING"); }
	static ScriptAny NetworkGetFriendCount() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_FRIEND_COUNT"); }
	static ScriptAny NetworkGetFriendName(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_FRIEND_NAME", p0); }
	static ScriptAny NetworkGetGameMode() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_GAME_MODE"); }
	static ScriptAny NetworkGetMaxPrivateSlots() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_MAX_PRIVATE_SLOTS"); }
	static ScriptAny NetworkGetMaxSlots() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_MAX_SLOTS"); }
	static ScriptAny NetworkGetMetPlayerName(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_MET_PLAYER_NAME", p0); }
	static ScriptAny NetworkGetNumPartyMembers() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_NUM_PARTY_MEMBERS"); }
	static ScriptAny NetworkGetNumPlayersMet() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_NUM_PLAYERS_MET"); }
	static ScriptAny NetworkGetNumUnacceptedInvites() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_NUM_UNACCEPTED_INVITES"); }
	static ScriptAny NetworkGetNumUnfilledReservations() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_NUM_UNFILLED_RESERVATIONS"); }
	static ScriptAny NetworkGetNumberOfGames() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_NUMBER_OF_GAMES"); }
	static ScriptAny NetworkGetRendezvousHostPlayerId() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_RENDEZVOUS_HOST_PLAYER_ID"); }
	static ScriptAny NetworkGetUnacceptedInviteEpisode(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_UNACCEPTED_INVITE_EPISODE", p0); }
	static ScriptAny NetworkGetUnacceptedInviteGameMode(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_UNACCEPTED_INVITE_GAME_MODE", p0); }
	static ScriptAny NetworkGetUnacceptedInviterName(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_GET_UNACCEPTED_INVITER_NAME", p0); }
	static ScriptAny NetworkHaveAcceptedInvite() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HAVE_ACCEPTED_INVITE"); }
	static ScriptAny NetworkHaveOnlinePrivileges() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HAVE_ONLINE_PRIVILEGES"); }
	static ScriptAny NetworkHaveSummons() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HAVE_SUMMONS"); }
	static ScriptAny NetworkHostGame(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HOST_GAME", p0, p1, p2, p3, p4, p5); }
	static ScriptAny NetworkHostGamePending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HOST_GAME_PENDING"); }
	static ScriptAny NetworkHostGameSucceeded() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HOST_GAME_SUCCEEDED"); }
	static ScriptAny NetworkHostRendezvous(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_HOST_RENDEZVOUS", p0, p1, p2); }
	static ScriptAny NetworkInviteFriend(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_INVITE_FRIEND", p0, p1); }
	static ScriptAny NetworkIsCommonEpisode(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_COMMON_EPISODE", p0); }
	static ScriptAny NetworkIsFriendInSameTitle(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_FRIEND_IN_SAME_TITLE", p0); }
	static ScriptAny NetworkIsFriendOnline(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_FRIEND_ONLINE", p0); }
	static ScriptAny NetworkIsInviteeOnline() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_INVITEE_ONLINE"); }
	static ScriptAny NetworkIsOperationPending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_OPERATION_PENDING"); }
	static ScriptAny NetworkIsPlayerBlockedByMe(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_PLAYER_BLOCKED_BY_ME", p0); }
	static ScriptAny NetworkIsPlayerMutedByMe(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_PLAYER_MUTED_BY_ME", p0); }
	static ScriptAny NetworkIsPlayerTalking(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_PLAYER_TALKING", p0); }
	static ScriptAny NetworkIsRendezvous() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_RENDEZVOUS"); }
	static ScriptAny NetworkIsRendezvousHost() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_RENDEZVOUS_HOST"); }
	static ScriptAny NetworkIsSessionAdvertised() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_SESSION_ADVERTISED"); }
	static ScriptAny NetworkIsSessionInvitable() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_SESSION_INVITABLE"); }
	static ScriptAny NetworkIsTvt() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_IS_TVT"); }
	static ScriptAny NetworkJoinGame(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_JOIN_GAME", p0); }
	static ScriptAny NetworkJoinGamePending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_JOIN_GAME_PENDING"); }
	static ScriptAny NetworkJoinGameSucceeded() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_JOIN_GAME_SUCCEEDED"); }
	static ScriptAny NetworkJoinSummons() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_JOIN_SUMMONS"); }
	static void NetworkKickPlayer(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_KICK_PLAYER", p0); }
	static ScriptAny NetworkLeaveGame() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_LEAVE_GAME"); }
	static ScriptAny NetworkLeaveGamePending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_LEAVE_GAME_PENDING"); }
	static ScriptAny NetworkPlayerHasDiedRecently(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_PLAYER_HAS_DIED_RECENTLY", p0); }
	static ScriptAny NetworkPlayerHasHeadset(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_PLAYER_HAS_HEADSET", p0); }
	static ScriptAny NetworkRestoreGameConfig(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_RESTORE_GAME_CONFIG", p0); }
	static ScriptAny NetworkReturnToRendezvous() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_RETURN_TO_RENDEZVOUS"); }
	static ScriptAny NetworkReturnToRendezvousPending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_RETURN_TO_RENDEZVOUS_PENDING"); }
	static ScriptAny NetworkReturnToRendezvousSucceeded() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_RETURN_TO_RENDEZVOUS_SUCCEEDED"); }
	static void NetworkSetFriendlyFireOption(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SET_FRIENDLY_FIRE_OPTION", p0); }
	static void NetworkSetHealthReticuleOption(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SET_HEALTH_RETICULE_OPTION", p0); }
	static ScriptAny NetworkSetPlayerMuted(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("NETWORK_SET_PLAYER_MUTED", p0, p1); }
	static void NetworkSetTalkerFocus(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SET_TALKER_FOCUS", p0); }
	static void NetworkSetTalkerProximity(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SET_TALKER_PROXIMITY", p0); }
	static void NetworkSetTeamOnlyChat(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SET_TEAM_ONLY_CHAT", p0); }
	static void NetworkShowFriendProfileUi(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SHOW_FRIEND_PROFILE_UI", p0); }
	static void NetworkShowMetPlayerFeedbackUi(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SHOW_MET_PLAYER_FEEDBACK_UI", p0); }
	static void NetworkShowMetPlayerProfileUi(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SHOW_MET_PLAYER_PROFILE_UI", p0); }
	static void NetworkShowPlayerProfileUi(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_SHOW_PLAYER_PROFILE_UI", p0); }
	static ScriptAny NetworkStartSession() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_START_SESSION"); }
	static ScriptAny NetworkStartSessionPending() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_START_SESSION_PENDING"); }
	static ScriptAny NetworkStartSessionSucceeded() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_START_SESSION_SUCCEEDED"); }
	static void NetworkStoreGameConfig(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("NETWORK_STORE_GAME_CONFIG", p0); }
	static ScriptAny NetworkStoreSinglePlayerGame() { return NativeInvoke::Invoke<ScriptAny>("NETWORK_STORE_SINGLE_PLAYER_GAME"); }
	static void NewMobilePhoneCall() { NativeInvoke::Invoke<ScriptVoid>("NEW_MOBILE_PHONE_CALL"); }
	static void NewScriptedConversation() { NativeInvoke::Invoke<ScriptVoid>("NEW_SCRIPTED_CONVERSATION"); }
	static void OpenDebugFile() { NativeInvoke::Invoke<ScriptVoid>("OPEN_DEBUG_FILE"); }
	static void OverrideFreezeFlags(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("OVERRIDE_FREEZE_FLAGS", p0); }
	static void OverrideNextRestart(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("OVERRIDE_NEXT_RESTART", p0, p1, p2, p3); }
	static void OverrideNumberOfParkedCars(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("OVERRIDE_NUMBER_OF_PARKED_CARS", p0); }
	static void PausePlaybackRecordedCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PAUSE_PLAYBACK_RECORDED_CAR", p0); }
	static void PauseScriptedConversation(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PAUSE_SCRIPTED_CONVERSATION", p0); }
	static void PlayAudioEventFromObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_OBJECT", p0, p1); }
	static void PlayAudioEventFromPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_PED", p0, p1); }
	static void PlayAudioEventFromVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PLAY_AUDIO_EVENT_FROM_VEHICLE", p0, p1); }
	static void PlayFireSoundFromPosition(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PLAY_FIRE_SOUND_FROM_POSITION", p0, p1, p2, p3); }
	static ScriptAny PlayerWantsToJoinNetworkGame(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("PLAYER_WANTS_TO_JOIN_NETWORK_GAME", p0); }
	static void PlayStatsInt(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PLAYSTATS_INT", p0, p1); }
	static void PlayStatsMissionCancelled(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAYSTATS_MISSION_CANCELLED", p0); }
	static void PlayStatsMissionFailed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAYSTATS_MISSION_FAILED", p0); }
	static void PlayStatsMissionPassed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAYSTATS_MISSION_PASSED", p0); }
	static void PlayStatsMissionStarted(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PLAYSTATS_MISSION_STARTED", p0); }
	static void PointCamAtCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("POINT_CAM_AT_COORD", p0, p1, p2, p3); }
	static void PointCamAtObject(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("POINT_CAM_AT_OBJECT", p0, p1); }
	static void PointCamAtPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("POINT_CAM_AT_PED", p0, p1); }
	static void PointCamAtVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("POINT_CAM_AT_VEHICLE", p0, p1); }
	static ScriptAny PreloadStream(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("PRELOAD_STREAM", p0); }
	static ScriptAny PreloadStreamWithStartOffset(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("PRELOAD_STREAM_WITH_START_OFFSET", p0, p1); }
	static void PreviewRingtone(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PREVIEW_RINGTONE", p0); }
	static void Print(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PRINT", p0, p1, p2); }
	static void PrintBig(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PRINT_BIG", p0, p1, p2); }
	static void PrintHelp(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP", p0); }
	static void PrintHelpForever(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_FOREVER", p0); }
	static void PrintHelpForeverWithNumber(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_FOREVER_WITH_NUMBER", p0, p1); }
	static void PrintHelpForeverWithString(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_FOREVER_WITH_STRING", p0, p1); }
	static void PrintHelpForeverWithStringNoSound(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_FOREVER_WITH_STRING_NO_SOUND", p0, p1); }
	static void PrintHelpWithNumber(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_WITH_NUMBER", p0, p1); }
	static void PrintHelpWithString(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_WITH_STRING", p0, p1); }
	static void PrintHelpWithStringNoSound(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("PRINT_HELP_WITH_STRING_NO_SOUND", p0, p1); }
	static void PrintNow(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PRINT_NOW", p0, p1, p2); }
	static void PrintStringInString(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PRINT_STRING_IN_STRING", p0, p1, p2, p3); }
	static void PrintStringInStringNow(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PRINT_STRING_IN_STRING_NOW", p0, p1, p2, p3); }
	static void PrintWith2Numbers(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("PRINT_WITH_2_NUMBERS", p0, p1, p2, p3, p4); }
	static void PrintWith2NumbersNow(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("PRINT_WITH_2_NUMBERS_NOW", p0, p1, p2, p3, p4); }
	static void PrintWithNumber(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PRINT_WITH_NUMBER", p0, p1, p2, p3); }
	static void PrintWithNumberBig(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PRINT_WITH_NUMBER_BIG", p0, p1, p2, p3); }
	static void PrintWithNumberNow(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("PRINT_WITH_NUMBER_NOW", p0, p1, p2, p3); }
	static void PrintFloat(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PRINTFLOAT", p0); }
	static void PrintInt(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PRINTINT", p0); }
	static void PrintNL() { NativeInvoke::Invoke<ScriptVoid>("PRINTNL"); }
	static void PrintString(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PRINTSTRING", p0); }
	static void PrintVector(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("PRINTVECTOR", p0, p1, p2); }
	static void PrioritizeStreamingRequest() { NativeInvoke::Invoke<ScriptVoid>("PRIORITIZE_STREAMING_REQUEST"); }
	static void ProcessMissionDeletionList() { NativeInvoke::Invoke<ScriptVoid>("PROCESS_MISSION_DELETION_LIST"); }
	static void ProstituteCamActivate(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("PROSTITUTE_CAM_ACTIVATE", p0); }
	static void RegisterBestPosition(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_BEST_POSITION", p0, p1); }
	static void RegisterClientBroadcastVariables(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_CLIENT_BROADCAST_VARIABLES", p0, p1, p2); }
	static void RegisterHatedTargetsAroundPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_HATED_TARGETS_AROUND_PED", p0, p1); }
	static void RegisterHatedTargetsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_HATED_TARGETS_IN_AREA", p0, p1, p2, p3, p4); }
	static void RegisterHostBroadcastVariables(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_HOST_BROADCAST_VARIABLES", p0, p1, p2); }
	static void RegisterKillInMultiplayerGame(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_KILL_IN_MULTIPLAYER_GAME", p0, p1, p2); }
	static void RegisterMissionPassed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_MISSION_PASSED", p0); }
	static void RegisterMultiplayerGameWin(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_MULTIPLAYER_GAME_WIN", p0, p1); }
	static void RegisterNetworkBestGameScores(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_NETWORK_BEST_GAME_SCORES", p0, p1, p2); }
	static void RegisterScriptWithAudio(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_SCRIPT_WITH_AUDIO", p0); }
	static void RegisterStringForFrontendStat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_STRING_FOR_FRONTEND_STAT", p0, p1); }
	static void RegisterTarget(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_TARGET", p0, p1); }
	static void RegisterTrackNumber(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_TRACK_NUMBER", p0); }
	static void RegisterWorldPointScriptBrain(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_WORLD_POINT_SCRIPT_BRAIN", p0, p1); }
	static void ReleasePathNodes() { NativeInvoke::Invoke<ScriptVoid>("RELEASE_PATH_NODES"); }
	static void ReloadWebPage(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RELOAD_WEB_PAGE", p0); }
	static void RemoveCarRecording(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CAR_RECORDING", p0); }
	static void RemoveCarsFromGeneratorsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CARS_FROM_GENERATORS_IN_AREA", p0, p1, p2, p3, p4, p5); }
	static void RemoveFakeNetworkNameFromPed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_FAKE_NETWORK_NAME_FROM_PED", p0); }
	static void RemoveProjtexFromObject(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PROJTEX_FROM_OBJECT", p0); }
	static void RemovePtfxFromPed(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PTFX_FROM_PED", p0); }
	static void RenderRaceTrack(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RENDER_RACE_TRACK", p0); }
	static void ReportTaggedRadioTrack(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REPORT_TAGGED_RADIO_TRACK", p0); }
	static ScriptAny RequestAmbientAudioBank(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("REQUEST_AMBIENT_AUDIO_BANK", p0); }
	static void RequestCarRecording(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("REQUEST_CAR_RECORDING", p0); }


//////////

	static ScriptAny RequestControlOfNetworkId(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("REQUEST_CONTROL_OF_NETWORK_ID", p0); }
	static ScriptAny RequestMissionAudioBank(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("REQUEST_MISSION_AUDIO_BANK", p0); }
	static void ReserveNetworkMissionObjectsForHost(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESERVE_NETWORK_MISSION_OBJECTS_FOR_HOST", p0); }
	static void ReserveNetworkMissionPeds(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESERVE_NETWORK_MISSION_PEDS", p0); }
	static void ReserveNetworkMissionPedsForHost(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESERVE_NETWORK_MISSION_PEDS_FOR_HOST", p0); }
	static void ReserveNetworkMissionVehicles(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESERVE_NETWORK_MISSION_VEHICLES", p0); }
	static void ReserveNetworkMissionVehiclesForHost(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("RESERVE_NETWORK_MISSION_VEHICLES_FOR_HOST", p0); }
	static void ResetCamInterpCustomSpeedGraph() { NativeInvoke::Invoke<ScriptVoid>("RESET_CAM_INTERP_CUSTOM_SPEED_GRAPH"); }
	static void RestoreScriptArrayFromScratchpad(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("RESTORE_SCRIPT_ARRAY_FROM_SCRATCHPAD", p0, p1, p2, p3); }
	static ScriptAny RestoreScriptValuesForNetworkGame(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("RESTORE_SCRIPT_VALUES_FOR_NETWORK_GAME", p0); }
	static void ResurrectNetworkPlayer(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("RESURRECT_NETWORK_PLAYER", p0, p1, p2, p3, p4); }
	static void SaveFloatToDebugFile(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SAVE_FLOAT_TO_DEBUG_FILE", p0); }
	static void SaveIntToDebugFile(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SAVE_INT_TO_DEBUG_FILE", p0); }
	static void SaveNewlineToDebugFile() { NativeInvoke::Invoke<ScriptVoid>("SAVE_NEWLINE_TO_DEBUG_FILE"); }
	static void SaveScriptArrayInScratchpad(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SAVE_SCRIPT_ARRAY_IN_SCRATCHPAD", p0, p1, p2, p3); }
	static void SaveStringToDebugFile(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SAVE_STRING_TO_DEBUG_FILE", p0); }
	static void SayAmbientSpeechWithVoice(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SAY_AMBIENT_SPEECH_WITH_VOICE", p0, p1, p2, p3, p4, p5); }
	static void ScriptAssert(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SCRIPT_ASSERT", p0); }
	static void ScriptIsMovingMobilePhoneOffscreen(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SCRIPT_IS_MOVING_MOBILE_PHONE_OFFSCREEN", p0); }
	static void ScriptIsUsingMobilePhone(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SCRIPT_IS_USING_MOBILE_PHONE", p0); }
	static void SearchCriteriaConsiderPedsWithFlagTrue(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SEARCH_CRITERIA_CONSIDER_PEDS_WITH_FLAG_TRUE", p0); }
	static void SearchCriteriaRejectPedsWithFlagTrue(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SEARCH_CRITERIA_REJECT_PEDS_WITH_FLAG_TRUE", p0); }
	static void SendNmMessage(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SEND_NM_MESSAGE", p0); }
	static void SetAllCarGeneratorsBackToActive() { NativeInvoke::Invoke<ScriptVoid>("SET_ALL_CAR_GENERATORS_BACK_TO_ACTIVE"); }
	static void SetAllMotionControlPreferencesOnOff(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ALL_MOTION_CONTROL_PREFERENCES_ON_OFF", p0); }
	static void SetAmbientVoiceName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_AMBIENT_VOICE_NAME", p0, p1); }
	static void SetArmourPickupNetworkRegenTime(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ARMOUR_PICKUP_NETWORK_REGEN_TIME", p0); }
	static void SetBit(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_BIT", p0, p1); }
	static void SetBitsInRange(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_BITS_IN_RANGE", p0, p1, p2, p3); }
	static void SetBriansMood(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_BRIANS_MOOD", p0); }
	static void SetCamAttachOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_ATTACH_OFFSET", p0, p1, p2, p3); }
	static void SetCamAttachOffsetIsRelative(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_ATTACH_OFFSET_IS_RELATIVE", p0, p1); }
	static void SetCamComponentShake(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_COMPONENT_SHAKE", p0, p1, p2, p3, p4, p5, p6); }
	static void SetCamDofFocuspoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_DOF_FOCUSPOINT", p0, p1, p2, p3, p4); }
	static void SetCamFarClip(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_FAR_CLIP", p0, p1); }
	static void SetCamFarDof(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_FAR_DOF", p0, p1); }
	static void SetCamInheritRollVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_INHERIT_ROLL_VEHICLE", p0, p1); }
	static void SetCamInterpCustomSpeedGraph(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_INTERP_CUSTOM_SPEED_GRAPH", p0); }
	static void SetCamInterpStyleCore(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_INTERP_STYLE_CORE", p0, p1, p2, p3, p4); }
	static void SetCamInterpStyleDetailed(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_INTERP_STYLE_DETAILED", p0, p1, p2, p3, p4); }
	static void SetCamMotionBlur(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_MOTION_BLUR", p0, p1); }
	static void SetCamName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_NAME", p0, p1); }
	static void SetCamNearClip(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_NEAR_CLIP", p0, p1); }
	static void SetCamNearDof(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_NEAR_DOF", p0, p1); }
	static void SetCamPointOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_POINT_OFFSET", p0, p1, p2, p3); }
	static void SetCamPointOffsetIsRelative(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_POINT_OFFSET_IS_RELATIVE", p0, p1); }
	static void SetCamShake(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_SHAKE", p0, p1, p2); }
	static void SetCamSplineDuration(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_SPLINE_DURATION", p0, p1); }
	static void SetCamSplineProgress(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_SPLINE_PROGRESS", p0, p1); }
	static void SetCamSplineSpeedConstant(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_SPLINE_SPEED_CONSTANT", p0, p1); }
	static void SetCamSplineSpeedGraph(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAM_SPLINE_SPEED_GRAPH", p0, p1); }
	static void SetCanBurstCarTyres(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAN_BURST_CAR_TYRES", p0, p1); }
	static void SetCanResprayCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAN_RESPRAY_CAR", p0, p1); }
	static void SetCanTargetCharWithoutLos(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CAN_TARGET_CHAR_WITHOUT_LOS", p0, p1); }
	static void SetCarGeneratorsActiveInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_GENERATORS_ACTIVE_IN_AREA", p0, p1, p2, p3, p4, p5, p6); }
	static void SetCarOnlyDamagedByRelationshipGroup(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP", p0, p1, p2); }
	static void SetCharInCutscene(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_IN_CUTSCENE", p0, p1); }
	static void SetCharNameDebug(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_NAME_DEBUG", p0, p1); }
	static void SetCharOnlyDamagedByRelationshipGroup(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP", p0, p1, p2); }
	static void SetCinematicButtonEnabled(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CINEMATIC_BUTTON_ENABLED", p0); }
	static void SetCutsceneExtraRoomPos(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_CUTSCENE_EXTRA_ROOM_POS", p0, p1, p2); }
	static void SetFollowPedPitchLimitDown(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_FOLLOW_PED_PITCH_LIMIT_DOWN", p0); }
	static void SetFollowPedPitchLimitUp(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_FOLLOW_PED_PITCH_LIMIT_UP", p0); }
	static void SetFollowVehicleCamOffset(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_FOLLOW_VEHICLE_CAM_OFFSET", p0, p1, p2, p3); }
	static void SetFollowVehicleCamSubmode(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_FOLLOW_VEHICLE_CAM_SUBMODE", p0); }
	static void SetFreeResprays(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_FREE_RESPRAYS", p0); }
	static void SetFreebiesInVehicle(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_FREEBIES_IN_VEHICLE", p0, p1); }
	static void SetGameCamHeading(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_GAME_CAM_HEADING", p0); }
	static void SetGameCamPitch(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_GAME_CAM_PITCH", p0); }
	static void SetGarageLeaveCameraAlone(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_GARAGE_LEAVE_CAMERA_ALONE", p0, p1); }
	static void SetGlobalInstancePriority(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_GLOBAL_INSTANCE_PRIORITY", p0); }
	static void SetGlobalRenderFlags(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_GLOBAL_RENDER_FLAGS", p0, p1, p2, p3); }
	static void SetHealthPickupNetworkRegenTime(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_HEALTH_PICKUP_NETWORK_REGEN_TIME", p0); }
	static void SetHelpMessageBoxSize(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_HELP_MESSAGE_BOX_SIZE", p0); }
	static void SetHintFov(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_HINT_FOV", p0); }
	static void SetHintTimes(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_HINT_TIMES", p0, p1, p2); }
	static void SetHintTimesDefault() { NativeInvoke::Invoke<ScriptVoid>("SET_HINT_TIMES_DEFAULT"); }
	static void SetInMPTutorial(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_IN_MP_TUTORIAL", p0); }
	static void SetInSpectatorMode(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_IN_SPECTATOR_MODE", p0); }
	static void SetInformRespectedFriends(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_INFORM_RESPECTED_FRIENDS", p0, p1, p2); }
	static void SetInterpFromScriptToGame(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_INTERP_FROM_SCRIPT_TO_GAME", p0, p1); }
	static void SetInterpInOutVehicleEnabledThisFrame(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_INTERP_IN_OUT_VEHICLE_ENABLED_THIS_FRAME", p0); }
	static void SetLoadCollisionForCarFlag(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_LOAD_COLLISION_FOR_CAR_FLAG", p0, p1); }
	static void SetLoadCollisionForCharFlag(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_LOAD_COLLISION_FOR_CHAR_FLAG", p0, p1); }
	static void SetLobbyMuteOverride(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_LOBBY_MUTE_OVERRIDE", p0); }
	static void SetLoudVehicleRadio(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_LOUD_VEHICLE_RADIO", p0, p1); }
	static void SetMask(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_MASK", p0, p1, p2, p3); }
	static void SetMessagesWaiting(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MESSAGES_WAITING", p0); }
	static void SetMsgForLoadingScreen(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MSG_FOR_LOADING_SCREEN", p0); }
	static void SetMultiplayerHUDCash(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MULTIPLAYER_HUD_CASH", p0); }
	static void SetMultiplayerHUDTime(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_MULTIPLAYER_HUD_TIME", p0); }
	static void SetNetworkIdCanMigrate(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NETWORK_ID_CAN_MIGRATE", p0, p1); }
	static void SetNetworkIdExistsOnAllMachines(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES", p0, p1); }
	static void SetNetworkIdStopCloning(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NETWORK_ID_STOP_CLONING", p0, p1); }
	static void SetNetworkPlayerAsVip(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NETWORK_PLAYER_AS_VIP", p0, p1); }
	static void SetNetworkVehicleRespotTimer(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NETWORK_VEHICLE_RESPOT_TIMER", p0, p1); }
	static void SetNmAnimPose(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_ANIM_POSE", p0, p1, p2, p3); }
	static void SetNmMessageBool(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_BOOL", p0, p1); }
	static void SetNmMessageFloat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_FLOAT", p0, p1); }
	static void SetNmMessageInstanceIndex(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_INSTANCE_INDEX", p0, p1, p2, p3); }
	static void SetNmMessageInt(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_INT", p0, p1); }
	static void SetNmMessageString(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_STRING", p0, p1); }
	static void SetNmMessageVec3(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_NM_MESSAGE_VEC3", p0, p1, p2, p3); }
	static void SetObjectProofs(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_PROOFS", p0, p1, p2, p3, p4, p5); }
	static void SetObjectRecordsCollisions(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_OBJECT_RECORDS_COLLISIONS", p0, p1); }
	static void SetOverrideNoSprintingOnPhoneInMultiplayer(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_OVERRIDE_NO_SPRINTING_ON_PHONE_IN_MULTIPLAYER", p0); }
	static void SetPedWithBrainCanBeConvertedToDummyPed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_WITH_BRAIN_CAN_BE_CONVERTED_TO_DUMMY_PED", p0, p1); }
	static void SetPlaybackSpeed(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYBACK_SPEED", p0, p1); }
	static void SetPlayerControlForNetwork(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL_FOR_NETWORK", p0, p1, p2); }
	static void SetPlayerControlOnInMissionCleanup(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL_ON_IN_MISSION_CLEANUP", p0); }
	static void SetPlayerIconColour(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_ICON_COLOUR", p0); }
	static void SetPlayerPlayerTargetting(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_PLAYER_TARGETTING", p0); }
	static void SetPlayerTeam(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_TEAM", p0, p1); }
	static void SetPlayersDropMoneyInNetworkGame(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYERS_DROP_MONEY_IN_NETWORK_GAME", p0); }
	static void SetPtfxCamInsideVehicle(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PTFX_CAM_INSIDE_VEHICLE", p0); }
	static void SetRichPresenceTemplateLobby(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATELOBBY", p0); }
	static void SetRichPresenceTemplateMP1(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP1", p0, p1, p2, p3); }
	static void SetRichPresenceTemplateMP2(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP2", p0); }
	static void SetRichPresenceTemplateMP3(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP3", p0, p1); }
	static void SetRichPresenceTemplateMP4(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP4", p0, p1); }
	static void SetRichPresenceTemplateMP5(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP5", p0, p1, p2); }
	static void SetRichPresenceTemplateMP6(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEMP6", p0, p1, p2); }
	static void SetRichPresenceTemplateParty() { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATEPARTY"); }
	static void SetRichPresenceTemplateSP1(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATESP1", p0, p1, p2); }
	static void SetRichPresenceTemplateSP2(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RICH_PRESENCE_TEMPLATESP2", p0); }
	static void SetRomansMood(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_ROMANS_MOOD", p0); }
	static void SetRoomForViewportByKey(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_VIEWPORT_BY_KEY", p0, p1); }
	static void SetRoomForViewportByName(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_VIEWPORT_BY_NAME", p0, p1); }
	static void SetScenarioPedDensityMultiplier(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_SCENARIO_PED_DENSITY_MULTIPLIER", p0, p1); }
	static void SetScriptedAnimSeatOffset(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_SCRIPTED_ANIM_SEAT_OFFSET", p0, p1); }
	static void SetScriptedConversionCentre(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_SCRIPTED_CONVERSION_CENTRE", p0, p1, p2); }
	static void SetSequenceToRepeat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_SEQUENCE_TO_REPEAT", p0, p1); }
	static void SetSpecificPassengerIndexToUseInGroups(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_SPECIFIC_PASSENGER_INDEX_TO_USE_IN_GROUPS", p0, p1); }
	static void SetSpritesDrawBeforeFade(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_SPRITES_DRAW_BEFORE_FADE", p0); }
	static void SetStatFrontEndVisibility(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_STAT_FRONTEND_VISIBILITY", p0, p1); }
	static void SetThisMachineRunningServerScript(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_THIS_MACHINE_RUNNING_SERVER_SCRIPT", p0); }
	static void SetTimecycleModifier(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_TIMECYCLE_MODIFIER", p0); }
	static void SetUsePoolGamePhysicsSettings(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SET_USE_POOL_GAME_PHYSICS_SETTINGS", p0); }
	static void SetUsesCollisionOfClosestObjectOfType(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_USES_COLLISION_OF_CLOSEST_OBJECT_OF_TYPE", p0, p1, p2, p3, p4, p5); }
	static void SetViewportPriority(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_VIEWPORT_PRIORITY", p0, p1); }
	static void SetVisibilityOfClosestObjectOfType(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SET_VISIBILITY_OF_CLOSEST_OBJECT_OF_TYPE", p0, p1, p2, p3, p4, p5); }
	static void SetVoiceIdFromHeadComponent(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_VOICE_ID_FROM_HEAD_COMPONENT", p0, p1, p2); }
	static void SetWeaponPickupNetworkRegenTime(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_WEAPON_PICKUP_NETWORK_REGEN_TIME", p0, p1); }
	static void SetWebPageLinkActive(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("SET_WEB_PAGE_LINK_ACTIVE", p0, p1, p2); }
	static void SetWebPageScroll(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SET_WEB_PAGE_SCROLL", p0, p1); }
	static void ShowSigninUi() { NativeInvoke::Invoke<ScriptVoid>("SHOW_SIGNIN_UI"); }
	static void ShutdownAndLaunchNetworkGame(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SHUTDOWN_AND_LAUNCH_NETWORK_GAME", p0); }
	static void ShutdownAndLaunchSinglePlayerGame() { NativeInvoke::Invoke<ScriptVoid>("SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME"); }
	static void SkipTimeInPlaybackRecordedCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SKIP_TIME_IN_PLAYBACK_RECORDED_CAR", p0, p1); }
	static void SkipToEndAndStopPlaybackRecordedCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SKIP_TO_END_AND_STOP_PLAYBACK_RECORDED_CAR", p0); }
	static void SkipToNextScriptedConversationLine() { NativeInvoke::Invoke<ScriptVoid>("SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE"); }
	static void StartCredits() { NativeInvoke::Invoke<ScriptVoid>("START_CREDITS"); }
	static void StartCustomMobilePhoneRinging(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("START_CUSTOM_MOBILE_PHONE_RINGING", p0); }
	static void StartCutscene() { NativeInvoke::Invoke<ScriptVoid>("START_CUTSCENE"); }
	static void StartCutsceneNow(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("START_CUTSCENE_NOW", p0); }
	static void StartEndCreditsMusic() { NativeInvoke::Invoke<ScriptVoid>("START_END_CREDITS_MUSIC"); }
	static void StartGpsRaceTrack(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("START_GPS_RACE_TRACK", p0); }
	static void StartLoadScene(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("START_LOAD_SCENE", p0, p1, p2); }
	static void StartMobilePhoneCall(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("START_MOBILE_PHONE_CALL", p0, p1, p2, p3, p4, p5); }
	static void StartMobilePhoneCalling() { NativeInvoke::Invoke<ScriptVoid>("START_MOBILE_PHONE_CALLING"); }
	static void StartNewWidgetCombo() { NativeInvoke::Invoke<ScriptVoid>("START_NEW_WIDGET_COMBO"); }
	static void StartPlaybackRecordedCar(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("START_PLAYBACK_RECORDED_CAR", p0, p1); }
	static void StartPlaybackRecordedCarUsingAi(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("START_PLAYBACK_RECORDED_CAR_USING_AI", p0, p1); }
	static ScriptAny StartPtfx(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("START_PTFX", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny StartPtfxOnObj(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("START_PTFX_ON_OBJ", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny StartPtfxOnPedBone(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { return NativeInvoke::Invoke<ScriptAny>("START_PTFX_ON_PED_BONE", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static ScriptAny StartPtfxOnVeh(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("START_PTFX_ON_VEH", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void StartScriptConversation(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("START_SCRIPT_CONVERSATION", p0, p1); }
	static void StopCredits() { NativeInvoke::Invoke<ScriptVoid>("STOP_CREDITS"); }
	static void StopEndCreditsMusic() { NativeInvoke::Invoke<ScriptVoid>("STOP_END_CREDITS_MUSIC"); }
	static void StopMobilePhoneRinging() { NativeInvoke::Invoke<ScriptVoid>("STOP_MOBILE_PHONE_RINGING"); }
	static void StopPlaybackRecordedCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STOP_PLAYBACK_RECORDED_CAR", p0); }
	static void StopPreviewRingtone() { NativeInvoke::Invoke<ScriptVoid>("STOP_PREVIEW_RINGTONE"); }
	static void StopPtfx(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STOP_PTFX", p0); }
	static void StopRecordingCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STOP_RECORDING_CAR", p0); }
	static void StopStream() { NativeInvoke::Invoke<ScriptVoid>("STOP_STREAM"); }
	static void StoreCarCharIsInNoSave(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("STORE_CAR_CHAR_IS_IN_NO_SAVE", p0, p1); }
	static ScriptAny StoreDamageTrackerForNetworkPlayer(ScriptAny p0, ScriptAny p1, ScriptAny p2) { return NativeInvoke::Invoke<ScriptAny>("STORE_DAMAGE_TRACKER_FOR_NETWORK_PLAYER", p0, p1, p2); }
	static void StoreScriptValuesForNetworkGame(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("STORE_SCRIPT_VALUES_FOR_NETWORK_GAME", p0); }
	static void StreamCutscene() { NativeInvoke::Invoke<ScriptVoid>("STREAM_CUTSCENE"); }
	static ScriptAny StringToInt(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("STRING_TO_INT", p0, p1); }
	static void SuppressFadeInAfterDeathArrest(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SUPPRESS_FADE_IN_AFTER_DEATH_ARREST", p0); }
	static void SwitchCarGenerator(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_CAR_GENERATOR", p0, p1); }
	static void SwitchOffWaypoint() { NativeInvoke::Invoke<ScriptVoid>("SWITCH_OFF_WAYPOINT"); }
	static void SwitchPedPathsOff(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_PED_PATHS_OFF", p0, p1, p2, p3, p4, p5); }
	static void SwitchPedPathsOn(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_PED_PATHS_ON", p0, p1, p2, p3, p4, p5); }
	static void SwitchPedRoadsBackToOriginal(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_PED_ROADS_BACK_TO_ORIGINAL", p0, p1, p2, p3, p4, p5); }
	static void SwitchStreaming(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("SWITCH_STREAMING", p0); }
	static void TakeCarOutOfParkedCarsBudget(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TAKE_CAR_OUT_OF_PARKED_CARS_BUDGET", p0, p1); }
	static void TaskCarDriveToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_DRIVE_TO_COORD", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static void TaskCarDriveToCoordNotAgainstTraffic(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { NativeInvoke::Invoke<ScriptVoid>("TASK_CAR_DRIVE_TO_COORD_NOT_AGAINST_TRAFFIC", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static void TaskCharSlideToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD", p0, p1, p2, p3, p4, p5); }
	static void TaskCharSlideToCoordAndPlayAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13) { NativeInvoke::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD_AND_PLAY_ANIM", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	static void TaskCharSlideToCoordHdgRate(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("TASK_CHAR_SLIDE_TO_COORD_HDG_RATE", p0, p1, p2, p3, p4, p5, p6); }
	static void TaskChatWithChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_CHAT_WITH_CHAR", p0, p1, p2, p3); }
	static void TaskClearLookAt(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TASK_CLEAR_LOOK_AT", p0); }
	static void TaskClimb(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_CLIMB", p0, p1); }
	static void TaskClimbLadder(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_CLIMB_LADDER", p0, p1); }
	static void TaskCombatHatedTargetsInArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT_HATED_TARGETS_IN_AREA", p0, p1, p2, p3, p4); }
	static void TaskCombatRoll(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_COMBAT_ROLL", p0, p1); }
	static void TaskCower(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TASK_COWER", p0); }
	static void TaskDead(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TASK_DEAD", p0); }
	static void TaskDriveBy(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("TASK_DRIVE_BY", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void TaskDrivePointRoute(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_DRIVE_POINT_ROUTE", p0, p1, p2); }
	static void TaskDrivePointRouteAdvanced(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_DRIVE_POINT_ROUTE_ADVANCED", p0, p1, p2, p3, p4, p5); }
	static void TaskDuck(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_DUCK", p0, p1); }
	static void TaskExtendRoute(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_EXTEND_ROUTE", p0, p1, p2); }
	static void TaskFleeCharAnyMeans(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("TASK_FLEE_CHAR_ANY_MEANS", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void TaskFlushRoute() { NativeInvoke::Invoke<ScriptVoid>("TASK_FLUSH_ROUTE"); }
	static void TaskFollowNavMeshAndSlideToCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("TASK_FOLLOW_NAV_MESH_AND_SLIDE_TO_COORD", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void TaskFollowPointRoute(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_FOLLOW_POINT_ROUTE", p0, p1, p2); }
	static void TaskGetOffBoat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_GET_OFF_BOAT", p0, p1); }
	static void TaskGoStraightToCoordRelativeToCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_STRAIGHT_TO_COORD_RELATIVE_TO_CAR", p0, p1, p2, p3, p4, p5, p6); }
	static void TaskGoToChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_TO_CHAR", p0, p1, p2, p3); }
	static void TaskGoToCoordAnyMeans(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_TO_COORD_ANY_MEANS", p0, p1, p2, p3, p4, p5); }
	static void TaskGoToCoordWhileAiming(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_TO_COORD_WHILE_AIMING", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); }
	static void TaskGoToCoordWhileShooting(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_TO_COORD_WHILE_SHOOTING", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskGoToObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_GO_TO_OBJECT", p0, p1, p2, p3); }
	static void TaskGotoCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_GOTO_CAR", p0, p1, p2, p3); }
	static void TaskGuardAngledDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11, ScriptAny p12, ScriptAny p13) { NativeInvoke::Invoke<ScriptVoid>("TASK_GUARD_ANGLED_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	static void TaskGuardAssignedDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("TASK_GUARD_ASSIGNED_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6); }
	static void TaskGuardSphereDefensiveArea(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10) { NativeInvoke::Invoke<ScriptVoid>("TASK_GUARD_SPHERE_DEFENSIVE_AREA", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static void TaskJump(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_JUMP", p0, p1); }
	static void TaskLeaveCarAndFlee(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_CAR_AND_FLEE", p0, p1, p2, p3, p4); }
	static void TaskLeaveCarInDirection(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_LEAVE_CAR_IN_DIRECTION", p0, p1, p2); }
	static void TaskMobileConversation(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_MOBILE_CONVERSATION", p0, p1); }
	static void TaskPerformSequenceFromProgress(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE_FROM_PROGRESS", p0, p1, p2, p3); }
	static void TaskPerformSequenceLocally(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_PERFORM_SEQUENCE_LOCALLY", p0, p1); }
	static void TaskPickupAndCarryObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_PICKUP_AND_CARRY_OBJECT", p0, p1, p2, p3, p4, p5); }
	static void TaskPlayAnim(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimFacial(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_FACIAL", p0, p1, p2, p3, p4, p5, p6); }
	static void TaskPlayAnimNonInterruptable(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_NON_INTERRUPTABLE", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimReadyToBeExecuted(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_READY_TO_BE_EXECUTED", p0, p1, p2, p3); }
	static void TaskPlayAnimSecondary(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_SECONDARY", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimSecondaryInCar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_SECONDARY_IN_CAR", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimSecondaryNoInterrupt(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_SECONDARY_NO_INTERRUPT", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimSecondaryUpperBody(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_SECONDARY_UPPER_BODY", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimUpperBody(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_UPPER_BODY", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TaskPlayAnimWithAdvancedFlags(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9, ScriptAny p10, ScriptAny p11) { NativeInvoke::Invoke<ScriptVoid>("TASK_PLAY_ANIM_WITH_ADVANCED_FLAGS", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); }
	static void TaskPutCharDirectlyIntoCover(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_PUT_CHAR_DIRECTLY_INTO_COVER", p0, p1, p2, p3, p4); }
	static void TaskSeekCoverFromPed(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_SEEK_COVER_FROM_PED", p0, p1, p2); }
	static void TaskSeekCoverFromPos(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_SEEK_COVER_FROM_POS", p0, p1, p2, p3, p4); }
	static void TaskSeekCoverToCoords(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("TASK_SEEK_COVER_TO_COORDS", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void TaskSeekCoverToCoverPoint(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_SEEK_COVER_TO_COVER_POINT", p0, p1, p2, p3, p4, p5); }
	static void TaskSetIgnoreWeaponRangeFlag(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_SET_IGNORE_WEAPON_RANGE_FLAG", p0, p1); }
	static void TaskShimmy(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_SHIMMY", p0, p1); }
	static ScriptAny TaskShimmyInDirection(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<ScriptAny>("TASK_SHIMMY_IN_DIRECTION", p0, p1); }
	static ScriptAny TaskShimmyLetGo(ScriptAny p0) { return NativeInvoke::Invoke<ScriptAny>("TASK_SHIMMY_LET_GO", p0); }
	static void TaskShootAtChar(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_SHOOT_AT_CHAR", p0, p1, p2, p3); }
	static void TaskShootAtCoord(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_SHOOT_AT_COORD", p0, p1, p2, p3, p4, p5); }
	static void TaskShuffleToNextCarSeat(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_SHUFFLE_TO_NEXT_CAR_SEAT", p0, p1); }
	static void TaskSitDown(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_SIT_DOWN", p0, p1, p2, p3); }
	static void TaskSitDownInstantly(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("TASK_SIT_DOWN_INSTANTLY", p0, p1, p2, p3); }
	static void TaskSitDownOnNearestObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_NEAREST_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void TaskSitDownOnObject(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { NativeInvoke::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_OBJECT", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static void TaskSitDownOnSeat(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("TASK_SIT_DOWN_ON_SEAT", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void TaskStandGuard(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { NativeInvoke::Invoke<ScriptVoid>("TASK_STAND_GUARD", p0, p1, p2, p3, p4, p5, p6, p7); }
	static void TaskStartScenarioAtPosition(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5) { NativeInvoke::Invoke<ScriptVoid>("TASK_START_SCENARIO_AT_POSITION", p0, p1, p2, p3, p4, p5); }
	static void TaskStartScenarioInPlace(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("TASK_START_SCENARIO_IN_PLACE", p0, p1, p2); }
	static void TaskToggleDuck(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TASK_TOGGLE_DUCK", p0, p1); }
	static void TaskUseNearestScenarioToPos(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_USE_NEAREST_SCENARIO_TO_POS", p0, p1, p2, p3, p4); }
	static void TaskUseNearestScenarioToPosWarp(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4) { NativeInvoke::Invoke<ScriptVoid>("TASK_USE_NEAREST_SCENARIO_TO_POS_WARP", p0, p1, p2, p3, p4); }
	static void TellNetPlayerToStartPlaying(ScriptAny p0, ScriptAny p1) { NativeInvoke::Invoke<ScriptVoid>("TELL_NET_PLAYER_TO_START_PLAYING", p0, p1); }
	static void TerminateAllScriptsWithThisName(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME", p0); }
	static void ThisScriptIsSafeForNetworkGame() { NativeInvoke::Invoke<ScriptVoid>("THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME"); }
	static void ThisScriptShouldBeSaved() { NativeInvoke::Invoke<ScriptVoid>("THIS_SCRIPT_SHOULD_BE_SAVED"); }
	static void TrainLeaveStation(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TRAIN_LEAVE_STATION", p0); }
	static void TriggerMissionCompleteAudio(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TRIGGER_MISSION_COMPLETE_AUDIO", p0); }
	static void TriggerPoliceReport(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("TRIGGER_POLICE_REPORT", p0); }
	static ScriptAny TriggerPtfx(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7) { return NativeInvoke::Invoke<ScriptAny>("TRIGGER_PTFX", p0, p1, p2, p3, p4, p5, p6, p7); }
	static ScriptAny TriggerPtfxOnObj(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("TRIGGER_PTFX_ON_OBJ", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static ScriptAny TriggerPtfxOnPedBone(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8, ScriptAny p9) { return NativeInvoke::Invoke<ScriptAny>("TRIGGER_PTFX_ON_PED_BONE", p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
	static ScriptAny TriggerPtfxOnVeh(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6, ScriptAny p7, ScriptAny p8) { return NativeInvoke::Invoke<ScriptAny>("TRIGGER_PTFX_ON_VEH", p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static void TurnOffRadioHUBInLobby() { NativeInvoke::Invoke<ScriptVoid>("TURN_OFF_RADIOHUD_IN_LOBBY"); }
	static void UnattachCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("UNATTACH_CAM", p0); }
	static void UnfreezeRadioStation(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("UNFREEZE_RADIO_STATION", p0); }
	static void UnlockMissionNewsStory(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("UNLOCK_MISSION_NEWS_STORY", p0); }
	static void UnpausePlaybackRecordedCar(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("UNPAUSE_PLAYBACK_RECORDED_CAR", p0); }
	static void UnpointCam(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("UNPOINT_CAM", p0); }
	static void UpdateNetworkRelativeScore(ScriptAny p0, ScriptAny p1, ScriptAny p2) { NativeInvoke::Invoke<ScriptVoid>("UPDATE_NETWORK_RELATIVE_SCORE", p0, p1, p2); }
	static void UpdateNetworkStatistics(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3) { NativeInvoke::Invoke<ScriptVoid>("UPDATE_NETWORK_STATISTICS", p0, p1, p2, p3); }
	static void UpdatePtfxOffsets(ScriptAny p0, ScriptAny p1, ScriptAny p2, ScriptAny p3, ScriptAny p4, ScriptAny p5, ScriptAny p6) { NativeInvoke::Invoke<ScriptVoid>("UPDATE_PTFX_OFFSETS", p0, p1, p2, p3, p4, p5, p6); }
	static void UseMask(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("USE_MASK", p0); }
	static void UsePlayerColourInsteadOfTeamColour(ScriptAny p0) { NativeInvoke::Invoke<ScriptVoid>("USE_PLAYER_COLOUR_INSTEAD_OF_TEAM_COLOUR", p0); }
	static void UsePreviousFontSettings() { NativeInvoke::Invoke<ScriptVoid>("USE_PREVIOUS_FONT_SETTINGS"); }
}
