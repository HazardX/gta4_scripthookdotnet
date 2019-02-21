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

	using namespace System;
	using namespace System::IO;

	private enum class ScriptState {
		Empty,
		NoneFound,
		Loading,
		Loaded, //Loaded and aborted are the same, just required for flow control
		Starting,
		Running,
		Aborting,
		Aborted,
	};

	private enum class ScriptAction {
		Idle,
		LoadScripts,
		StartScripts,
		RestartScripts,
		AbortScripts,
		RemoveAllScripts,
		ReloadAndStartScripts,
	};

	[FlagsAttribute]
	public enum class AnimationFlags {
		None = 0,
		Unknown01 = 1,
		Unknown02 = 2,
		Unknown03 = 4,
		Unknown04 = 8,
		Unknown05 = 16,
		Unknown06 = 32,
		Unknown07 = 64,
		Unknown08 = 128,
		Unknown09 = 256,
		Unknown10 = 512,
		Unknown11 = 1024,
		Unknown12 = 2048,
		//Unknown = Unknown12 | Unknown11 | Unknown09, //2048+1024+256
	};

	public enum class BorderType {
		None,
		Raised,
		Lowered,
	};

	public enum class ExplosionType {
		Default,
		Molotov,
		Rocket,
	};

	public enum class GarageType {
		Unknown3 = 3,
		Unknown4 = 4,
	};

	public enum class NetworkMode {
		Singleplayer,
		MultiplayerLAN,
		MultiplayerLive,
		MultiplayerLiveRanked,
	};

	public enum class GameMode {
		None = -1,
		Deathmatch = 0,
		TeamDeathmatch = 1,
		MafiyaWork  = 2,
		TeamMafiyaWork = 3,
		TeamCarJackCity = 4,
		CarJackCity = 5,
		Race = 6,
		GTARace = 7,
		PartyMode = 8,
		Unknown_9 = 9, 
		CopsAndCrooks = 10, 
		Unknown_11 = 11,  
		TurfWar = 12,
		DealBreaker = 13,
		HangmansNOOSE = 14,
		BombDaBaseII = 15,
		FreeMode = 16,
	};

	public enum class GroundType {
		NextBelowCurrent,
		NextAboveCurrent,
		Closest,
		Lowest,
		Highest,
	};

	public enum class TextAlignment {
		//Left,
		//Centered,
		//JustifyLeft,
		////JustifyRight,

		/// <summary>
		/// Align the text to the top.
		/// </summary>
		Top = 0, //DT_TOP,

		/// <summary>
		/// Align the text to the left.
		/// </summary>
		Left = 0, //DT_LEFT,

		/// <summary>
		/// Align the text to the center.
		/// </summary>
		Center = 1, //DT_CENTER,

		/// <summary>
		/// Align the text to the right.
		/// </summary>
		Right = 2, //DT_RIGHT,

		/// <summary>
		/// Vertically align the text to the center.
		/// </summary>
		VerticalCenter = 4, //DT_VCENTER,

		/// <summary>
		/// Align the text to the bottom.
		/// </summary>
		Bottom = 8, //DT_BOTTOM,

		/// <summary>
		/// Allow word breaks.
		/// </summary>
		WordBreak = 16, //DT_WORDBREAK,

		/// <summary>
		/// Force all text to a single line.
		/// </summary>
		SingleLine = 32, //DT_SINGLELINE,

		/// <summary>
		/// Expand tab characters.
		/// </summary>
		ExpandTabs = 64, //DT_EXPANDTABS,

		/// <summary>
		/// Don't clip the text.
		/// </summary>
		NoClip = 256, //DT_NOCLIP,

		///// <summary>
		///// Rendering the text in right-to-left reading order.
		///// </summary>
		//RtlReading = 0x20000, //DT_RTLREADING,
	};


	public enum class FontEffect {
		None,
		Shadow,
		Edge,
	};

	public enum class FontScaling {
		/// <summary>
		/// A value between 0 and 20, where 20 equals full screen size
		/// </summary>
		FontSize,
		/// <summary>
		/// A value between 0 and 1, where 1 equals full screen size
		/// </summary>
		ScreenUnits,
		/// <summary>
		/// A value between 0 and the maximum screen resolution (check Game.Resolution to get the size)
		/// </summary>
		Pixel,
	};

	//public enum class FontStyle {
	//	StandardAllUpper = 0,
	//	Digital = 1,
	//	WideNumbers = 3,
	//	ChalkNumbers = 4,
	//	ThinAllUpper = 5,
	//	Standard = 8,
	//};

	public enum class Bone {
		//Back = 1223,
		//Body = 1201,
		//Head = 1216, //1205,
		//LeftArm = 1218,
		//LeftBody = 1203,
		//LeftEar = 1205,
		//LeftHand = 1219,
		//LeftHip = 1202,
		//LeftShoulder = 1217,
		//Neck = 1204,
		//RightArm = 1225,
		//RightFoot = 1200,
		//RightHand = 1232,
		//RightShoulder = 1224,

		Root					= 0,
		Pelvis					= 0x1A1,
		Spine					= 0x4B2,
		Spine1					= 0x4B3,
		Spine2					= 0x36A0,
		Spine3					= 0x36A1,
		Neck					= 0x4B4,
		Head					= 0x4B5,
		NeckRoll				= 0x37A0,

		LeftClavicle			= 0x4C0, 
		LeftUpperarm			= 0x4C1,
		LeftForearm				= 0x4C2,
		LeftHand				= 0x4C3,
		LeftFinger0				= 0x35D0,
		LeftFinger01			= 0x35D1,
		LeftFinger02			= 0x35D2,
		LeftFinger1				= 0x35D3,
		LeftFinger11			= 0x35D4,
		LeftFinger12			= 0x35D5,
		LeftFinger2				= 0x35D6,
		LeftFinger21			= 0x35D7,
		LeftFinger22			= 0x35D8,
		LeftFinger3				= 0x35D9,
		LeftFinger31			= 0x35E0,
		LeftFinger32			= 0x35E1,
		LeftFinger4				= 0x35E2,
		LeftFinger41			= 0x35E3,
		LeftFinger42			= 0x35E4,
		LeftForearmTwist		= 0x38A1,
		LeftForearmTwist1		= 0x38A2,
		LeftUpperarmRoll		= 0x38A0,
		LeftArmRoll				= 0x3DF1,
		LeftThigh				= 0x1A2,
		LeftCalf				= 0x1A3,
		LeftFoot				= 0x1A4,
		LeftToe					= 0x1A5,
		LeftCalfRoll			= 0x38B0,

		RightClavicle			= 0x4C7,
		RightUpperarm			= 0x4C8,
		RightForearm			= 0x4C9,
		RightHand				= 0x4D0,
		RightFinger0			= 0x35B0,
		RightFinger01			= 0x35B1,
		RightFinger02			= 0x35B2,
		RightFinger1			= 0x35B3,
		RightFinger11			= 0x35B4,
		RightFinger12			= 0x35B5,
		RightFinger2			= 0x35B6,
		RightFinger21			= 0x35B7,
		RightFinger22			= 0x35B8,
		RightFinger3			= 0x35B9,
		RightFinger31			= 0x35C0,
		RightFinger32			= 0x35C1,
		RightFinger4			= 0x35C2,
		RightFinger41			= 0x35C3,
		RightFinger42			= 0x35C4,
		RightForearmTwist		= 0x39A1,
		RightForearmTwist1		= 0x39A2,
		RightUpperarmRoll		= 0x39A0,
		RightArmRoll			= 0x3E01,
		RightThigh				= 0x1A7,
		RightCalf				= 0x1A8,
		RightFoot				= 0x1A9,
		RightToe				= 0x4B0,
		RightCalfRoll			= 0x39B0,

		FaceLeftBrowJointA		= 0x78F7,
		FaceLeftBrowJointB		= 0x78F8,
		FaceLeftLidJoint		= 0x78F9,
		FaceLeftCheekJoint		= 0x78FB,
		FaceLeftEyeJoint		= 0x78FC,
		FaceLeftCornerJointA	= 0x7903,
		FaceLeftCornerJointB	= 0x79F4,
		FaceLeftJawJointA		= 0x7904,
		FaceLeftJawJointB		= 0x7905,
		FaceLeftLipUpJointA		= 0x7906,

		FaceRightBrowJointA		= 0x7907,
		FaceRightBrowJointB		= 0x7908,
		FaceRightLidJoint		= 0x7909,
		FaceRightCheekJoint		= 0x790A,
		FaceRightEyeJoint		= 0x790B,
		FaceRightCornerJointA	= 0x790C,
		FaceRightCornerJointB	= 0x79F3,
		FaceRightJawJointA		= 0x7913,
		FaceRightJawJointB		= 0x7914,
		FaceRightLipUpJointA	= 0x7915,

		FaceCentralLowLidJoint	= 0x78FA,
		FaceCentralJawJointA	= 0x7916,

		HDFaceCentralBrow			= 0x7F94, 
		HDFaceCentralJaw			= 0x7F9B,
		HDFaceLeftLowerLip			= 0x7FA7,
		HDFaceRightLowerLip			= 0x7FA6,
		HDFaceLeftBrow				= 0x7F9A,
		HDFaceLeftMouthCorner		= 0x7FA5,
		HDFaceLeftEyeball			= 0x7F98,
		HDFaceLeftEyelid			= 0x7F99,
		HDFaceLeftUpperLip			= 0x7F9D,
		HDFaceRightBrow				= 0x7F95,
		HDFaceRightMouthCorner		= 0x7FA4,
		HDFaceRightEyeball			= 0x7F97,
		HDFaceRightEyelid			= 0x7F96,
		HDFaceRightUpperLip			= 0x7F9C,
		HDFaceLeftBrowJointB		= 0x0A917,
		HDFaceLeftBrowJointA		= 0x0A905,
		HDFaceForehead				= 0x0A8F6,
		HDFaceLeftEyeJoint			= 0x0A8F7,
		HDFaceLeftUpperCheekJoint	= 0x0A8F8,
		HDFaceLeftLipCornerJoint	= 0x0A8F9,
		HDFaceLeftLowCheekJoint		= 0x0A8FA,
		HDFaceLeftUpperLipJoint		= 0x0A8FB,
		HDFaceLeftUpperLidJoint		= 0x0A8FC,
		HDFaceLeftLowerLidJoint		= 0x0A903,
		HDFaceRightBrowJointA		= 0x0A904,
		HDFaceRightEyeJoint			= 0x0A916,
		HDFaceRightUpperLidJoint	= 0x0A906,
		HDFaceRightLowerLidJoint	= 0x0A907,
		HDFaceRightBrowJointB		= 0x0A908,
		HDFaceRightUpperCheekJoint	= 0x0A909,
		HDFaceRightUpperLipJoint	= 0x0A90A,
		HDFaceRightLipCornerJoint	= 0x0A90B,
		HDFaceRightLowCheekJoint	= 0x0A90C,
		HDFaceCentralJawJoint		= 0x0A913,
		HDFaceRightLowerLipJoint	= 0x0A914,
		HDFaceLeftLowerLipJoint		= 0x0A915,
		HDFaceTogueJointA			= 0x0A8F5,
		HDFaceTogueJointB			= 0x0A8F4,
		HDFaceCentralJawPoint		= 0x0C944,
		HDFaceRightLowerLipPoint	= 0x0C947,
		HDFaceLeftLowerLipPoint		= 0x0C948,
		HDFaceLeftUpperLipPoint		= 0x0C946,
		HDFaceRightUpperLipPoint	= 0x0C945,

		Extra1					= 0x0B064,
		Extra2					= 0x0B065,
		Extra3					= 0x0B066,
		Unknown					= 0x0FFFFFFFF
	};

	public enum class Gender {
		//irrelevant,
		Male,
		Female,
	};

	public enum class CursorType {
		Arrow,
		UpDown,
		LeftRight,
		TopLeftToBottomRight,
		TopRightToBottomLeft,
	};

	public enum class Weather {
		ExtraSunny,
		Sunny,
		SunnyAndWindy,
		Cloudy,
		Raining,
		Drizzle,
		Foggy,
		ThunderStorm,
		ExtraSunny2,
		SunnyAndWindy2,
	};

	public enum class PickupType {
		None = 0,
		Weapon = 22,
	};

	public enum class RadioStation {
		VIBE,
		LibertyRock,
		JAZZ,
		MASSIVE,
		K109,
		WKKT,
		LCHC,
		TheJourney,
		FUSION,
		BEAT,
		RadioBroker,
		Vladivostok,
		PLR,
		SanJuanSounds,
		ElectroChoc,
		Classics,
		IF99,
		TUFF,
		IndependanceFM,
		Integrity
	};

	public enum class Weapon {
		None = -1,
		Unarmed = 0,
		Melee_BaseballBat = 1,
		Melee_PoolCue = 2,
		Melee_Knife = 3,
		Thrown_Grenade = 4,
		Thrown_Molotov = 5,
		Misc_Rocket = 6,
		Handgun_Glock = 7,
		Misc_Unused0 = 8,
		Handgun_DesertEagle = 9,
		Shotgun_Basic = 10,
		Shotgun_Baretta = 11,
		SMG_Uzi = 12,
		SMG_MP5 = 13,
		Rifle_AK47 = 14,
		Rifle_M4 = 15,
		SniperRifle_Basic = 16,
		SniperRifle_M40A1 = 17,
		Heavy_RocketLauncher = 18,

		Heavy_FlameThrower = 19,
		Heavy_Minigun = 20,
		Episodic_01 = 21,
		Episodic_02 = 22,
		Episodic_03 = 23,
		Episodic_04 = 24,
		Episodic_05 = 25,
		Episodic_06 = 26,
		Episodic_07 = 27,
		Episodic_08 = 28,
		Episodic_09 = 29,
		Episodic_10 = 30,
		Episodic_11 = 31,
		Episodic_12 = 32,
		Episodic_13 = 33,
		Episodic_14 = 34,
		Episodic_15 = 35,
		Episodic_16 = 36,
		Episodic_17 = 37,
		Episodic_18 = 38,
		Episodic_19 = 39,
		Episodic_20 = 40,
		Episodic_21 = 41,
		Episodic_22 = 42,
		Episodic_23 = 43,
		Episodic_24 = 44,
		Misc_Camera = 45,
		Misc_Object = 46,
		Misc_LastWeaponType = 47,
		Misc_Armor = 48,
		Misc_RammedByCar = 49,
		Misc_RunOverByCar = 50,
		Misc_Explosion = 51,
		Misc_UziDriveby = 52,
		Misc_Drowning = 53,
		Misc_Fall = 54,
		Misc_Unidentified = 55,
		Misc_AnyMelee = 56,
		Misc_AnyWeapon = 57,

		TBOGT_GrenadeLauncher = 21,
		TBOGT_Pistol44 = 29,
		TBOGT_ExplosiveShotgun = 30,
		TBOGT_NormalShotgun = 31,
		TBOGT_AssaultSMG = 32,
		TBOGT_GoldenSMG = 33,
		TBOGT_AdvancedMG = 34,
		TBOGT_AdvancedSniper = 35,
		TBOGT_StickyBomb = 36,
		TBOGT_Parachute = 41,

		TLAD_GrenadeLauncher = 21,
		TLAD_AssaultShotgun = 22,
		TLAD_Poolcue = 24,
		TLAD_SawedOffShotgun = 26,
		TLAD_Automatic9mm = 27,
		TLAD_PipeBomb = 28,
	};

	public enum class WeaponSlot {
		Unarmed,
		Melee,
		Handgun,
		Shotgun,
		SMG,
		Rifle,
		Sniper,
		Heavy,
		Thrown,
		Special,
		Gift,
		Parachute,
		DetonatorUnknown
	};

	public enum class VehicleDoor	{
		LeftFront,
		RightFront,
		LeftRear,
		RightRear,
		Hood,
		Trunk,
	};

	public enum class DoorLock	{
		None = 0,
		CanOpenFromInside = 3,
		ImpossibleToOpen = 4,
	};

	public enum class DrivingStyle	{
		Normal = 0,					// 0 - Normal driving, stop for traffic lights
		IgnoreLightsAndLanes = 1,	// 1 - Ignore traffic lights, drive around traffic
		IgnoreStreets = 2,			// 2 - Ignore streets, try to drive directly to point
		IgnoreLights = 3,			// 3 - Ignore traffic lights, stay in lane
	};

	public enum class VehicleSeat	{
		None = -3,
		AnyPassengerSeat = -2,
		Driver = -1,
		RightFront = 0,
		LeftRear = 1,
		RightRear = 2,
	};

	public enum class VehicleWindow	{
		LeftFront,
		RightFront,
		LeftRear,
		RightRear,
		Front,
		Rear
	};

	public enum class VehicleWheel	{
		/// <summary>
		/// Left Front Wheel. Front Wheel for bikes.
		/// </summary>
		FrontLeft = 0,
		/// <summary>
		/// Right Front Wheel. Unused for bikes.
		/// </summary>
		FrontRight = 1,
		/// <summary>
		/// Left Central Wheel. Unused for bikes and 4-wheeled vehicles.
		/// </summary>
		CenterLeft = 2,
		/// <summary>
		/// Right Central Wheel. Unused for bikes and 4-wheeled vehicles.
		/// </summary>
		CenterRight = 3,
		/// <summary>
		/// Left Rear Wheel. Rear Wheel for bikes.
		/// </summary>
		RearLeft = 4,
		/// <summary>
		/// Right Rear Wheel. Unused for bikes.
		/// </summary>
		RearRight = 5,
	};

	[FlagsAttribute]
	public enum class VehicleType {
		None       = 0,
		Unknown_1  = 1,
		Unknown_2  = 2,
		Unknown_3  = 4,
		Unknown_4  = 8,
		Unknown_5  = 16,
		Unknown_6  = 32,
		Unknown_7  = 64,
		Unknown_8  = 128,

		AllCivil   = 64 | 4 | 2,
		All        = 255,
	};

	public enum class PedComponent {	// This is a complete guess and needs to be properly tested and verified...
		Head,		      // head
		UpperBody,   	// uppr
		LowerBody,	   // lowr
		Bags,				// suse
		Hand,		      // hand
		Feet,				// feet
		Jacket,			// jack
		Hair,				// hair
		Unknown_SUS2,	// sus2
		Teeth,	      // teef
		Face,				// face
	};

	public enum class PedProp {
		UNKNOWN_0,
		UNKNOWN_1,
	};

	public enum class PedFlag {
		none,
		bowling,
		pool,
		basketball,
		drivespoorcar,
		drivesaveragecar,
		drivesrichcar,
		drivesbigcar,
		drivesmotorcycle,
		drivesboat,
		onfoot,
		argue,
		smoker,
		phoneuser,
		buydrugs,
		givebummoney,
		insultbum,
		replytoho,
		taketaxi,
		watchfight,
		late,
		softjack,
		murdershakefist,
		murdercallpolice,
		murderrunaway,
		murderattack,
		taxidriver,
		policeofficer,
		swat,
		fbi,
		dea,
		csi,
		paramedic,
		fireman,
		prostitute,
		pimp,
		bum,
		cancarryweapons,
		likesart,
		dislikesart,
		tourist,
		office,
		gardening,
		jewish,
		criminal,
	};

	public enum class BlipColor {
		White = 0,
		DarkRed = 1,
		DarkGreen = 2,
		Cyan = 3,
		Grey = 4,
		Yellow = 5,
		Orange = 6,
		Purple = 7,
		Green = 8,
		Red = 9,
		LightRed = 10,
		LightOrange = 11,
		DarkTurquoise = 12,
		Turquoise = 13,
		LightYellow = 14,
		// ...
	};

	public enum class BlipDisplay	{
		Hidden = 0,
		ArrowOnly = 1,
		MapOnly = 2,
		ArrowAndMap = 4,
	};

	public enum class BlipIcon	{
		Misc_Destination,
		Misc_Destination1,
		Misc_Destination2,
		Misc_Objective,
		Misc_Objective4,
		Misc_Objective5,
		Misc_Player,
		Misc_North,
		Misc_Waypoint,
		Weapon_Pistol,
		Weapon_Shotgun,
		Weapon_SMG,
		Weapon_Rifle,
		Weapon_Rocket,
		Weapon_Grenade,
		Weapon_Molotov,
		Weapon_Sniper,
		Weapon_BaseballBat,
		Weapon_Knife,
		Pickup_Health,
		Pickup_Armor,
		Building_BurgerShot,
		Building_CluckinBell,
		Person_Vlad,
		Building_Internet,
		Person_Manny,
		Person_LittleJacob,
		Person_Roman,
		Person_Faustin,
		Building_Safehouse,
		Misc_TaxiRank,
		Person_Bernie,
		Person_Brucie,
		Person_Unknown,
		Person_Dwayne,
		Person_Elizabeta,
		Person_Gambetti,
		Person_JimmyPegorino,
		Person_Derrick,
		Person_Francis,
		Person_Gerry,
		Person_Katie,
		Person_Packie,
		Person_PhilBell,
		Person_PlayboyX,
		Person_RayBoccino,
		Misc_8BALL,
		Activity_Bar,
		Activity_BoatTour,
		Activity_Bowling,
		Building_ClothShop,
		Activity_Club,
		Activity_Darts,
		Person_Dwayne_Red,
		Activity_Date,
		Person_PlayboyX_Red,
		Activity_HeliTour,
		Activity_Restaurant,
		Building_TrainStation,
		Building_WeaponShop,
		Building_PoliceStation,
		Building_FireStation,
		Building_Hospital,
		Person_Male,
		Person_Female,
		Misc_FinishLine,
		Activity_StripClub,
		Misc_ConsoleGame,
		Misc_CopCar,
		Person_Dimitri,
		Activity_ComedyClub,
		Activity_CabaretClub,
		Misc_Ransom,
		Misc_CopHeli,
		Person_Michelle,
		Building_PayNSpray,
		Person_Assassin,
		Misc_Revenge,	
		Misc_Deal,
		Building_Garage,
		Person_Lawyer,
		Misc_Trophy,
		Misc_MultiplayerTutorial,
		Building_TrainStation3,
		Building_TrainStation8,
		Building_TrainStationA,
		Building_TrainStationB,
		Building_TrainStationC,
		Building_TrainStationE,
		Building_TrainStationJ,
		Building_TrainStationK,
		Building_CarWash,
		Person_UnitedLibertyPaper,
		Misc_Boss,
		Misc_Base	
	};

	public enum class BlipType	{
		Vehicle = 1,
		Ped = 2,		
		Object = 3,
		Coordinate = 4,
		Contact = 5,			
		Pickup = 6,
		Unknown = 7,
		Pickup2 = 8,
		// ...
	};

	public enum class GameEpisode {
		/// <summary>
		/// GTA IV Main Game
		/// </summary>
		GTAIV = 0,
		/// <summary>
		/// Episode "The Lost And Damned"
		/// </summary>
		TLAD = 1,
		/// <summary>
		/// Episode "The Ballad Of Gay Tony"
		/// </summary>
		TBOGT = 2,
	};

	public enum class GameKey {
		Sprint = 1,
		Jump = 2,
		EnterCar = 3,
		Attack = 4,
		LookBehind  = 7,
		NextWeapon = 8,
		LastWeapon = 9,

		Crouch = 20,
		Phone = 21,
		Action = 23,
		SeekCover = 28,
		Reload = 29,

		SoundHorn = 54,

		Esc = 61,

		NavDown = 64,
		NavUp = 65,
		NavLeft = 66,
		NavRight = 67,
		NavLeave = 76,
		NavEnter = 77,
		NavBack = 78,

		RadarZoom = 86,
		Aim = 87,

		//NotMouseUp = 88,
		//NotMouseLeft = 89,
		//NotForward = 90,
		//NotLeft = 91,

		MoveForward = 1090,
		MoveBackward = 1091,
		MoveLeft = 1092,
		MoveRight = 1093,
	};

	[FlagsAttribute]
	public enum class GameKeyDirection {
		None = 0,
		Forward = 1,
		Backwards = 2,
		Left = 4,
		Right = 8,
		ForwardLeft = Forward | Left,
		ForwardRight = Forward | Right,
		BackwardsLeft = Backwards | Left,
		BackwardsRight = Backwards | Right,
	};	

	public enum class PedType {
		CivMale,
		CivFemale,
		Cop,
		AlbanianGang,
		AngelsOfDeath,
		TheLost,
		ItalianMafia,
		RussianMob,
		Gang_RussianGang,
		Gang_IrishGang,
		Gang_Jamaican,
		Gang_AfricanAmerican,
		Gang_Korean,
		Gang_ChineseJapanese,
		Gang_PuertoRican,
		Dealer,     // maybe?
		Paramedic,
		Fireman,
		Criminal,   // maybe?
		Bum,        // maybe?
		Prostitute, // maybe?
	};

	public enum class RelationshipGroup {
		Player,
		Civillian_Male,
		Civillian_Female,
		Cop,
		Gang_Albanian,
		Gang_Biker1,
		Gang_Biker2,
		Gang_Italian,
		Gang_Russian1,
		Gang_Russian2,
		Gang_Irish,
		Gang_Jamaican,
		Gang_AfricanAmerican,
		Gang_Korean,
		Gang_ChineseJapanese,
		Gang_PuertoRican,
		Dealer,
		Medic,
		Fireman,
		Criminal,
		Bum,
		Prostitute,
		Special,
		Mission_1,
		Mission_2,
		Mission_3,
		Mission_4,
		Mission_5,
		Mission_6,
		Mission_7,
		Mission_8,
		NetworkPlayer_01,
		NetworkPlayer_02,
		NetworkPlayer_03,
		NetworkPlayer_04,
		NetworkPlayer_05,
		NetworkPlayer_06,
		NetworkPlayer_07,
		NetworkPlayer_08,
		NetworkPlayer_09,
		NetworkPlayer_10,
		NetworkPlayer_11,
		NetworkPlayer_12,
		NetworkPlayer_13,
		NetworkPlayer_14,
		NetworkPlayer_15,
		NetworkPlayer_16,
		NetworkPlayer_17,
		NetworkPlayer_18,
		NetworkPlayer_19,
		NetworkPlayer_20,
		NetworkPlayer_21,
		NetworkPlayer_22,
		NetworkPlayer_23,
		NetworkPlayer_24,
		NetworkPlayer_25,
		NetworkPlayer_26,
		NetworkPlayer_27,
		NetworkPlayer_28,
		NetworkPlayer_29,
		NetworkPlayer_30,
		NetworkPlayer_31,
		NetworkPlayer_32,
		NetworkTeam_1,
		NetworkTeam_2,
		NetworkTeam_3,
		NetworkTeam_4,
		NetworkTeam_5,
		NetworkTeam_6,
		NetworkTeam_7,
		NetworkTeam_8,
	};

	public enum class Relationship {
		Hate = 5,
		Dislike = 4,
		Neutral = 3,   // unsure
		Like = 2,
		Respect = 1,
		Companion = 0, // unsure
	};

	public enum class IntegerStatistic {
		MISSIONS_PASSED = 253,									//Missions passed
		MISSIONS_FAILED = 254,									//Missions failed
		MISSIONS_ATTEMPTED = 255,								//Missions attempted
		REPLAYS_USED = 256,									//Replays used
		PEOPLE_KILLED = 257,									//People killed
		NUMBER_OF_TAXI_FARES_COMPLETED = 258,					//Number of Taxi Fares completed
		TIMES_CHEATED = 259,									//Times cheated
		DAYS_PASSED = 260,										//Days passed
		TIMES_DIED = 261,										//Times died
		PEOPLE_RUN_DOWN = 262,									//People run down
		FLIPS_DONE_IN_A_VEHICLE = 264,							//Flips done in a vehicle
		MOST_VEHICLE_AIR_SPINS = 265,							//Most vehicle air spins
		AIR_LAUNCHES = 266,									//Air launches
		HELICOPTER_TOURS_TAKEN = 267,							//Helicopter tours taken
		TAXIS_HAILED = 268,									//Taxis hailed
		STUNT_JUMPS_FOUND = 269,								//Stunt jumps found
		STUNT_JUMPS_COMPLETED = 270,							//Stunt jumps completed
		KILLS_SINCE_LAST_SAVE = 271,							//Kills since last save
		FIRES_STARTED = 272,									//Fires started
		CRIMINALS_KILLED = 273,								//Criminals killed
		CARS_STOLEN = 274,										//Cars stolen
		BIKES_STOLEN = 275,									//Bikes stolen
		BOATS_STOLEN = 276,									//Boats stolen
		HELICOPTERS_STOLEN = 277,								//Helicopters stolen
		STARS_ATTAINED = 278,									//Stars attained
		STARS_EVADED = 279,									//Stars evaded
		VEHICLES_EXPORTED = 280,								//Vehicles exported
		NUMBER_OF_BRIDGES_FLOWN_UNDER = 281,					//Number of bridges flown under
		PAY_N_SPRAY_VISITS = 282,								//Pay 'n' Spray visits
		TIMES_GOT_DRUNK = 283,									//Times got drunk
		DRUG_PACKAGES_DELIVERED = 284,							//Drug packages delivered
		CARS_SOLD_TO_STEVIE = 285,								//Cars sold to Stevie
		RANDOM_CHARACTERS_MET = 286,							//Random characters met
		BULLETS_FIRED = 287,									//Bullets fired
		BULLETS_HIT = 288,										//Bullets hit
		KILLS_BY_HEADSHOTS = 289,								//Kills by headshots
		MELEE_KILLS = 290,										//Melee kills
		ARMED_KILLS = 291,										//Armed kills
		SUCCESSFUL_COUNTERS = 292,								//Successful counters
		NUMBER_OF_EXPLOSIONS = 293,							//Number of explosions
		CARS_EXPLODED = 294,									//Cars exploded
		BIKES_EXPLODED = 295,									//Bikes exploded
		BOATS_EXPLODED = 296,									//Boats exploded
		HELICOPTERS_EXPLODED = 297,							//Helicopters exploded
		TIRES_POPPED_BY_GUNSHOT = 298,							//Tires popped by gunshot
		WEAPONS_PICKED_UP = 299,								//Weapons picked up
		TEXTS_RECEIVED = 300,									//Texts received
		CALLS_MADE_FROM_PHONE = 301,							//Calls made from phone
		CALLS_RECEIVED_ON_PHONE = 302,							//Calls received on phone
		PROSTITUTE_VISITS = 303,								//Prostitute visits
		TRAMPS_GIVEN_MONEY_TO = 304,							//Tramps given money to
		EMAILS_SENT = 305,										//Emails sent
		MEALS_EATEN = 306,										//Meals eaten
		HOTDOGS_EATEN = 307,									//Hotdogs eaten
		BURGERS_EATEN = 308,									//Burgers eaten
		NUTS_EATEN = 309,										//Nuts eaten
		BINOCULARS_USED = 310,									//Binoculars used
		PLAYER_DIED_BY_MELEE = 311,							//Player died by melee
		PLAYER_SHOT_TO_DEATH = 312,							//Player shot to death
		PLAYER_WAS_BLOWN_UP = 313,								//Player was blown up
		PLAYER_WAS_ROADKILL = 314,								//Player was roadkill
		SCORED_WITH_GIRL = 315,								//Scored with girl
		POOL_WINS = 316,										//Pool wins
		POOL_DEFEATS = 317,									//Pool defeats
		POOL_CLEARANCES_FROM_BREAK = 318,						//Pool clearances from break
		DARTS_WINS = 319,										//Darts wins
		DARTS_DEFEATS = 320,									//Darts defeats
		DARTS_180S_HIT = 321,									//Darts 180's hit
		DARTS_BULLSEYE = 322,									//Darts bullseye
		DARTS_SHORTEST_CHECK_OUT = 323,						//Darts shortest check out
		BOWLING_HIGH_SCORE = 324,								//Bowling high score
		BOWLING_WINS = 325,									//Bowling wins
		BOWLING_DRAWS = 326,									//Bowling draws
		BOWLING_DEFEATS = 327,									//Bowling defeats
		BOWLING_SPARES = 328,									//Bowling spares
		BOWLING_PERFECTS = 329,								//Bowling perfects
		BOWLING_STRIKES = 330,									//Bowling strikes
		NUMBER_OF_RACES_LOST = 331,							//Number of races lost
		NUMBER_OF_RACES_WON = 332,								//Number of races won
		SOUTH_BROKER_WINS = 333,								//South Broker wins
		SOUTH_BROKER_RACES = 334,								//South Broker races
		AIRPORT_RUN_WINS = 335,								//Airport Run wins
		AIRPORT_RUN_RACES = 336,								//Airport Run races
		DUKES_BOULEVARD_WINS = 337,							//Dukes Boulevard wins
		DUKES_BOULEVARD_RACES = 338,							//Dukes Boulevard races
		SOUTH_ALGONQUIN_WINS = 339,							//South Algonquin wins
		SOUTH_ALGONQUIN_RACES = 340,							//South Algonquin races
		STAR_JUNCTION_WINS = 341,								//Star Junction wins
		STAR_JUNCTION_RACES = 342,								//Star Junction races
		ROAD_TO_BOHAN_WINS = 343,								//Road to Bohan wins
		ROAD_TO_BOHAN_RACES = 344,								//Road to Bohan races
		NORTH_ALDERNEY_WINS = 345,								//North Alderney wins
		NORTH_ALDERNEY_RACES = 346,							//North Alderney races
		ELEVATED_WINS = 347,									//Elevated wins
		ELEVATED_RACES = 348,									//Elevated races
		SOUTH_ALDERNEY_WINS = 349,								//South Alderney wins
		SOUTH_ALDERNEY_RACES = 350,							//South Alderney races
		QUB3D_HIGH_SCORE = 351,								//QUB3D high score
		BOATING_DESTINATIONS = 352,							//Boating destinations
		HELI_RIDE_DESTINATIONS = 353,							//Heli ride destinations
		ACTIVITIES_WITH_ROMAN = 354,							//Activities with Roman
		ACTIVITIES_WITH_JACOB = 355,							//Activities with Jacob
		ACTIVITIES_WITH_BRUCIE = 356,							//Activities with Brucie
		ACTIVITIES_WITH_DWAYNE = 357,							//Activities with Dwayne
		ACTIVITIES_WITH_PACKIE = 358,							//Activities with Packie
		VIGILANTE_LEVELS_DONE = 359,							//Vigilante levels done
		MOST_WANTED_COMPLETED = 360,							//Most wanted completed
		PIGEONS_EXTERMINATED = 361,							//Pigeons exterminated
		FIRST_AID_COLLECTED = 362,								//First aid collected
		ISLANDS_UNLOCKED = 363,								//Islands unlocked
		TOTAL_DATES = 364,										//Total dates
		SUCCESSFUL_DATES = 365,								//Successful dates
		BAD_DATES = 366,										//Bad dates
		GIRLS_DUMPED = 367,									//Girls dumped
		EMAILS_RECEIVED = 368,									//Emails received
		PHOTOS_TAKEN = 369,									//Photos taken
		MOCAP_CUTSCENES_SKIPPED = 370,							//Mocap cutscenes skipped
		MOCAP_CUTSCENES_WATCHED = 371,							//Mocap cutscenes watched
		CUTSCENES_SKIPPED = 372,								//Cutscenes skipped
		CUTSCENES_WATCHED = 373,								//Cutscenes watched
		SODA_DRUNK = 374,										//Soda drunk
		KILLS_WITH_UNARMED = 375,								//Kills with Unarmed
		KILLS_WITH_BASEBALL_BAT = 376,							//Kills with Baseball Bat
		KILLS_WITH_POOLCUE = 376,								//Kills with Poolcue
		KILLS_WITH_KNIFE = 378,								//Kills with Knife
		KILLS_WITH_GRENADE = 379,								//Kills with Grenade
		KILLS_WITH_MOLOTOV = 380,								//Kills with Molotov
		KILLS_WITH_ROCKET = 381,								//Kills with Rocket
		KILLS_WITH_PISTOL = 382,								//Kills with Pistol
		KILLS_WITH_COMBAT_PISTOL = 383,						//Kills with Combat Pistol
		KILLS_WITH_PUMP_SHOTGUN = 384,							//Kills with Pump Shotgun
		KILLS_WITH_COMBAT_SHOTGUN = 385,						//Kills with Combat Shotgun
		KILLS_WITH_MICRO_SMG = 386,							//Kills with Micro-SMG
		KILLS_WITH_SMG = 387,									//Kills with SMG
		KILLS_WITH_ASSAULT_RIFLE = 388,						//Kills with Assault Rifle
		KILLS_WITH_CARBINE_RIFLE = 389,						//Kills with Carbine Rifle
		KILLS_WITH_COMBAT_SNIPER = 390,						//Kills with Combat Sniper
		KILLS_WITH_SNIPER_RIFLE = 391,							//Kills with Sniper Rifle
		KILLS_WITH_RPG = 392,									//Kills with RPG
		KILLS_WITH_FLAME_THROWER = 393,						//Kills with Flame Thrower
		KILLS_WITH_MINIGUN = 394,								//Kills with Minigun
		KILLS_WITH_EPISODIC_1 = 395,							//Kills with Episodic 1
		KILLS_WITH_EPISODIC_2 = 396,							//Kills with Episodic 2
		KILLS_WITH_EPISODIC_3 = 397,							//Kills with Episodic 3
		KILLS_WITH_EPISODIC_4 = 398,							//Kills with Episodic 4
		KILLS_WITH_EPISODIC_5 = 399,							//Kills with Episodic 5
		KILLS_WITH_EPISODIC_6 = 400,							//Kills with Episodic 6
		KILLS_WITH_EPISODIC_7 = 401,							//Kills with Episodic 7
		KILLS_WITH_EPISODIC_8 = 402,							//Kills with Episodic 8
		KILLS_WITH_EPISODIC_9 = 403,							//Kills with Episodic 9
		KILLS_WITH_EPISODIC_10 = 404,							//Kills with Episodic 10
		KILLS_WITH_EPISODIC_11 = 405,							//Kills with Episodic 11
		KILLS_WITH_EPISODIC_12 = 406,							//Kills with Episodic 12
		KILLS_WITH_EPISODIC_13 = 407,							//Kills with Episodic 13
		KILLS_WITH_EPISODIC_14 = 408,							//Kills with Episodic 14
		KILLS_WITH_EPISODIC_15 = 409,							//Kills with Episodic 15
		KILLS_WITH_EPISODIC_16 = 410,							//Kills with Episodic 16
		KILLS_WITH_EPISODIC_17 = 411,							//Kills with Episodic 17
		KILLS_WITH_EPISODIC_18 = 412,							//Kills with Episodic 18
		KILLS_WITH_EPISODIC_19 = 413,							//Kills with Episodic 19
		KILLS_WITH_EPISODIC_20 = 414,							//Kills with Episodic 20
		KILLS_WITH_EPISODIC_21 = 415,							//Kills with Episodic 21
		KILLS_WITH_EPISODIC_22 = 416,							//Kills with Episodic 22
		KILLS_WITH_EPISODIC_23 = 417,							//Kills with Episodic 23
		KILLS_WITH_EPISODIC_24 = 418,							//Kills with Episodic 24
		TIMES_BUSTED = 419,									//Times busted
		SAVES_MADE = 420,										//Saves made
		TOTAL_LEGITIMATE_KILLS = 421,							//Total legitimate kills
		FLYING_SKILL = 422,									//Flying skill
		PROGRESS_WITH_DENISE = 423,							//Progress with Denise
		PROGRESS_WITH_MICHELLE = 424,							//Progress with Michelle
		PROGRESS_WITH_HELENA = 425,							//Progress with Helena
		PROGRESS_WITH_BARBARA = 426,							//Progress with Barbara
		PROGRESS_WITH_KATIE = 427,								//Progress with Katie
		PROGRESS_WITH_MILLIE = 428,							//Progress with Millie
		PIMPING_LEVEL = 429,									//Pimping level
		RESPECT_MISSION = 430,									//Respect Mission
		RESPECT_MISSION_TOTAL = 431,							//Respect Mission Total
		KILLS_SINCE_LAST_CHECKPOINT = 432,						//Kills since last checkpoint
		TOTAL_MISSIONS = 433,									//Total missions
		ENERGY = 434,											//Energy
		ARMOR = 435,											//Armour
		DRIVING_SKILL = 436,									//Driving skill
		BIKE_SKILL = 437,										//Bike skill
		LUCK = 438,											//Luck
		CYCLE_SKILL = 439,										//Cycle skill
		UNDERWATER_BREATH_STAMINA = 440,						//Underwater breath stamina
		CALORIES = 441,										//Calories
		PEOPLE_SAVED_IN_AN_AMBULANCE = 442,					//People saved in an Ambulance
		CRIMINALS_KILLED_ON_VIGILANTE_MISSION = 443,			//Criminals killed on Vigilante Mission
		HIGHEST_PARAMEDIC_MISSION_LEVEL = 444,					//Highest Paramedic Mission level
		HIGHEST_FIREFIGHTER_MISSION_LEVEL = 445,				//Highest Firefighter Mission level
		TOTAL_FIRES_EXTINGUISHED = 446,						//Total fires extinguished
		KGS_OF_EXPLOSIVES_USED = 447,							//Kgs of explosives used
		NUMBER_OF_POLICE_BRIBES = 448,							//Number of Police bribes
		FIRES_STARTED_INT = 449,								//Fires started
		HIGHEST_NUMBER_OF_PEDS_KILLED_IN_ONE_SPREE = 450,						//Highest number of peds killed in one spree
		HIGHEST_NUMBER_OF_COPS_KILLED_IN_ONE_SPREE = 451,						//Highest number of cops killed in one spree
		HIGHEST_NUMBER_OF_VEHICLES_DESTROYED_IN_ONE_SPREE = 452,				//Highest number of vehicles destroyed in one spree
		HIGHEST_NUMBER_OF_COP_CARS_DESTROYED_IN_ONE_SPREE = 453,				//Highest number of cop cars destroyed in one spree
		HIGHEST_NUMBER_OF_PED_KILLS_ON_SPREE = 454,							//Highest number of ped kills on spree
		HIGHEST_NUMBER_OF_POLICE_KILLS_ON_SPREE = 455,							//Highest number of police kills on spree
		HIGHEST_NUMBER_OF_CIVILIAN_VEHICLES_DESTROYED_ON_SPREE = 456,			//Highest number of civilian vehicles destroyed on spree
		HIGHEST_NUMBER_OF_COP_VEHICLES_DESTROYED_ON_SPREE = 457,				//Highest number of cop vehicles destroyed on spree
		HIGHEST_NUMBER_OF_TANKS_DESTROYED_ON_SPREE = 458,						//Highest number of tanks destroyed on spree
		RAMPAGES_ATTEMPTED = 459,								//Rampages attempted
		RAMPAGES_PASSED = 460,									//Rampages passed
		PEOPLE_WASTED_BY_OTHERS = 461,							//People wasted by others
		NUMBER_OF_VEHICLES_IMPORTED = 462,						//Number of vehicles imported
		GANG_MEMBERS_RECRUITED = 463,							//Gang members recruited
		ENEMY_GANG_MEMBERS_KILLED = 464,						//Enemy gang members killed
		FRIENDLY_GANG_MEMBERS_KILLED = 465,					//Friendly gang members killed
		RECRUITED_GANG_MEMBERS_KILLED = 466,					//Recruited gang members killed
		TIME_SPENT_LOOKING_THROUGH_TELESCOPE = 467,			//Time spent looking through telescope
		PLANES_EXPLODED = 468,									//Planes exploded
		NUMBER_OF_EXOTIC_EXPORTS_DONE = 469,					//Number of Exotic Exports done
		ADDICTION_LEVEL = 473,									//Addiction level
		FAVORITE_RADIO_STATION = 474,							//Favorite radio station
		LEAST_FAVORITE_STATION = 475,							//Least favorite station
		FAVORITE_TRANSPORT = 476,								//Favorite transport
		FAVORITE_CAR = 477,									//Favorite car
		FAVORITE_BIKE = 478,									//Favorite bike
		FAVORITE_BOAT = 479,									//Favorite boat
		FAVORITE_HELICOPTER = 480,								//Favorite helicopter
		MILES_TRAVELLED = 481,									//Miles travelled
		PLAYER_IMAGE = 482,									//Player image
		FAVORITE_CAR_COLOR = 483,								//Favorite car color
		TOP_VEHICLE_SPEED = 484,								//Top Vehicle Speed
		FAVORITE_ACTIVITY = 486,								//Favorite activity
		NIKO_AND_ROMAN_HANGOUT = 487,							//Niko and Roman hangout
		NIKO_AND_JACOB_HANGOUT = 488,							//Niko and Jacob hangout
		NIKO_AND_BRUCIE_HANGOUT = 489,							//Niko and Brucie hangout
		NIKO_AND_DWAYNE_HANGOUT = 490,							//Niko and Dwayne hangout
		NIKO_AND_PACKIE_HANGOUT = 491,							//Niko and Packie hangout
		FAVORITE_SHOP = 492,									//Favorite shop
		FAVORITE_INTERNET_SITE = 493,							//Favorite internet site
		LAST_MISSION_NAME = 494,								//Last mission name
		VEHICLES_BLOWN_UP = 500,								//Vehicles blown up
		HEALTH = 501,											//Health
		GANG_MEMBER_COUNT = 502,								//Gang member count
	};

	public enum class FloatStatistic	{
		GAME_PROGRESS = 0,										//Game progress
		ROMAN_LIKE = 1,										//Roman like
		ROMAN_RESPECT = 2,										//Roman respect
		ROMAN_MISSION_PROGRESS = 3,							//Roman mission progress
		VLAD_MISSION_PROGRESS = 4,								//Vlad mission progress
		JACOB_LIKE = 5,										//Jacob like
		JACOB_RESPECT = 6,										//Jacob respect
		JACOB_MISSION_PROGRESS = 7,							//Jacob mission progress
		FAUSTIN_MISSION_PROGRESS = 8,							//Faustin mission progress
		MANNY_MISSION_PROGRESS = 9,							//Manny mission progress
		ELIZABETA_MISSION_PROGRESS = 10,						//Elizabeta mission progress
		DWAYNE_LIKE = 11,										//Dwayne like
		DWAYNE_RESPECT = 12,									//Dwayne respect
		DWAYNE_MISSION_PROGRESS = 13,							//Dwayne mission progress
		BRUCIE_LIKE = 14,										//Brucie like
		BRUCIE_RESPECT = 15,									//Brucie respect
		BRUCIE_MISSION_PROGRESS = 16,							//Brucie mission progress
		PLAYBOY_MISSION_PROGRESS = 17,							//Playboy mission progress
		FRANCIS_MISSION_PROGRESS = 18,							//Francis mission progress
		ULPC_MISSION_PROGRESS = 19,							//U.L.P.C. mission progress
		PACKIE_LIKE = 20,										//Packie like
		PACKIE_RESPECT = 21,									//Packie respect
		PACKIE_MISSION_PROGRESS = 22,							//Packie mission progress
		RAY_MISSION_PROGRESS = 23,								//Ray mission progress
		GERRY_MISSION_PROGRESS = 24,							//Gerry mission progress
		DERRICK_MISSION_PROGRESS = 25,							//Derrick mission progress
		BERNIE_MISSION_PROGRESS = 26,							//Bernie mission progress
		BELL_MISSION_PROGRESS = 27,							//Bell mission progress
		GAMBETTI_MISSION_PROGRESS = 28,						//Gambetti mission progress
		JIMMY_MISSION_PROGRESS = 29,							//Jimmy mission progress
		CARMEN_ORTIZ_FONDNESS = 30,							//Carmen Ortiz fondness
		CARMEN_TRUST = 31,										//Carmen trust
		ALEX_CHILTON_FONDNESS = 32,							//Alex Chilton fondness
		ALEX_TRUST = 33,										//Alex trust
		KIKI_JENKINS_FONDNESS = 34,							//Kiki Jenkins fondness
		KIKI_TRUST = 35,										//Kiki trust
		MICHELLE_FONDNESS = 36,								//Michelle fondness
		MICHELLE_TRUST = 37,									//Michelle trust
		KATE_FONDNESS = 38,									//Kate fondness
		KATE_TRUST = 39,										//Kate trust
		SHOOTING_ACCURACY = 40,								//Shooting accuracy
		KILLS_PERCENT_IN_FREE_AIM = 41,						//Kills % in free aim
		BIKE_OR_CAR_AVERAGE_SPEED = 42,						//Bike/Car Average speed
		PLAYING_TIME = 44,										//Playing time
		LONGEST_COP_CHASE_TIME = 45,							//Longest cop chase time
		TIME_WANTED_ON_6_STARS = 46,							//Time wanted on 6 stars
		LAST_COP_CHASE_TIME = 47,								//Last cop chase time
		TIME_SPENT_IN_THE_WATER = 49,							//Time spent in the water
		TIME_SPENT_SHOPPING = 50,								//Time spent shopping
		TIME_SPENT_IN_COVER = 51,								//Time spent in cover
		POOL_PLAYED_TIME = 52,									//Pool played time
		DARTS_TIME_PLAYED = 53,								//Darts time played
		BOWLING_TIME_PLAYED = 54,								//Bowling time played
		TOTAL_RACE_TIME = 55,									//Total race time
		SOUTH_BROKER_RECORD = 56,								//South Broker record
		AIRPORT_RUN_RECORD = 57,								//Airport Run record
		DUKES_BOULEVARD_RECORD = 58,							//Dukes Boulevard record
		SOUTH_ALGONQUIN_RECORD = 59,							//South Algonquin record
		STAR_JUNCTION_RECORD = 60,								//Star Junction record
		ROAD_TO_BOHAN_RECORD = 61,								//Road to Bohan record
		NORTH_ALDERNEY_RECORD = 62,							//North Alderney record
		ELEVATED_RECORD = 63,									//Elevated record
		SOUTH_ALDERNEY_RECORD = 64,							//South Alderney record
		QUB3D_TIME_PLAYED = 65,								//QUB3D time played
		BOATING_TIME = 66,										//Boating time
		HELI_RIDE_TIME = 67,									//Heli ride time
		TIME_SPENT_ON_INTERNET = 68,							//Time spent on internet
		TIME_SPENT_CALLING = 69,								//Time spent calling
		TIME_SPENT_WALKING = 70,								//Time spent walking
		TIME_SPENT_DRIVING_CAR = 71,							//Time spent driving car
		TIME_SPENT_DRIVING_HELI = 72,							//Time spent driving heli
		TIME_SPENT_DRIVING_BIKE = 73,							//Time spent driving bike
		TIME_SPENT_DRIVING_BOAT = 74,							//Time spent driving boat
		TIME_SPENT_SWIMING = 75,								//Time spent swiming
		MILES_BY_HELICOPTER = 76,								//Miles by helicopter
		MILES_BY_CAR = 77,										//Miles by car
		MILES_BY_BIKE = 78,									//Miles by bike
		MILES_BY_BOAT = 79,									//Miles by boat
		MILES_ON_FOOT = 80,									//Miles on foot
		MILES_SWAM = 81,										//Miles swam
		LONGEST_2WHEEL_STUNT = 82,								//Longest 2wheel stunt
		LONGEST_BIKE_STOPPIE = 83,								//Longest bike stoppie
		LONGEST_BIKE_WHEELIE = 84,								//Longest bike wheelie
		MILES_BY_TRAIN = 85,									//Miles by train
		MILES_AS_TAXI_PASSENGER = 86,							//Miles as taxi passenger
		FARTHEST_JUMP_DISTANCE = 87,							//Farthest jump distance
		HIGHEST_JUMP_REACHED = 88,								//Highest jump reached
		LONGEST_FREE_FALL = 89,								//Longest free fall
		SPENT_ON_PAY_N_SPRAY = 90,								//Spent on Pay 'n' Spray
		SPENT_ON_DATES = 91,									//Spent on dates
		SPENT_BUYING_CLOTHES = 92,								//Spent buying clothes
		MONEY_FROM_MISSIONS = 93,								//Made from missions
		SPENT_IN_BARS_AND_CLUBS = 94,							//Spent in bars & clubs
		SPENT_ON_PROSTITUTES = 95,								//Spent on prostitutes
		SPENT_IN_STRIP_CLUBS = 96,								//Spent in strip clubs
		SPENT_ON_FOOD = 97,									//Spent on food
		SPENT_ON_TAXIS = 98,									//Spent on taxis
		MONEY_LOST_ON_STREET_RACES = 99,						//Money lost on street races
		MONEY_FROM_VIGILANTE = 100,								//Made from vigilante
		SPENT_ON_COP_BRIDES = 101,								//Spent on cop brides
		SPENT_ON_HEALTH_CARE = 102,							//Spent on health care
		GIVEN_TO_TRAMPS = 103,									//Given to tramps
		SPENT_ON_VENDORS = 104,								//Spent on vendors
		SPENT_ON_BINOCULARS = 105,								//Spent on binoculars
		SPENT_IN_GUN_SHOP = 106,								//Spent in gun shop
		MOST_SPENT_ON_A_DATE = 107,							//Most spent on a date
		CURRENT_MONEY = 108,									//Current money
		MADE_FROM_STREET_RACES = 109,							//Made from street races
		TOTAL_PROGRESS = 110,									//Total progress
		LONGEST_STOPPIE_TIME = 111,							//Longest stoppie time
		LONGEST_WHEELIE_TIME = 112,							//Longest wheelie time
		LONGEST_2WHEEL_TIME = 113,								//Longest 2wheel time
		FLIGHT_TIME = 114,										//Flight time
		RESPECT_TOTAL = 115,									//Respect total
		MONEY_FROM_USJS = 116,							//Money made from USJs
		PICKED_UP_ON_STREET = 117,								//Picked up on street
		LONGEST_NON_STOP_GAME = 118,							//Longest non-stop game
		MONEY_FROM_VEHICLE_THEFTS = 119,						//Made from vehicle thefts
		MONEY_FROM_RANDOM_PEDS = 120,							//Made from random peds
	};

	public enum class ShootMode {
		AimOnly = 0,
		SingleShot = 1,
		SingleShotKeepAim = 2,
		Burst = 3,
		Continuous = 4,
		//Continuous = 5,
	};

	public enum class FormStartPosition {
		Random,
		CenterScreen,
		Fixed,
	};

	public enum class GameVersion : unsigned int {
		UnknownVersion = 0,
		v1000 = 0x01000000,
		v1010 = 0x01000100,
		v1020 = 0x01000200,
		v1030 = 0x01000300,
		v1040 = 0x01000400,
		v1050 = 0x01000004,
		v1060 = 0x01000600,
		v1070 = 0x01000700,
		v1110 = 0x01010100, // EFLC
		v1120 = 0x01010200, // EFLC
	};

	private enum class cppHookVersion : unsigned int {
		UnknownVersion = 0,
		v0_4_0 = 0x0400, // 0.4.0
		v0_5_1 = 0x0510, // 0.5.1
	};

	private enum class ScriptEvent {
		ConsoleCommand,
		KeyDown,
		KeyUp,
		MouseDown,
		MouseUp,
		PhoneNumberDialed,
		ScriptCommand,
	};
	private enum class RemoteEvent {
		NativeCall,
		NativeInvoke,
		DisplayText,
		GetValidPedHandles,
		GetValidVehicleHandles,
		GetValidObjectHandles,
		ConsoleEvent,
		SetMouseEnabled,
		TryToDisableMouse,
		GetGlobalInteger,
		GetGlobalFloat,
		GetVehicleRPM,

		AddNewDirect3DObject, // does NOT require a Direct3D device!

		DRAWING_EVENTS = 10000,
		DrawPolygons = 10002,
		DrawString = 10003,
		//GetImageInfo = 10004,
		//TransformFromObjectToScreen = 10005,
	};
	private enum class RemoteProcessingTask {
		TeleportTo,
		Spawn,
		PrintScriptHelp,
	};

}