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
namespace Euphoria {

	public enum class GrabMethod {
		Line,
		Surface,
	};

	public enum class nmMessageID : int {
		nm000_stopAllBehaviours = 0,
		nm008_bodyRelax = 8,
		nm014_configureBalance = 14,
		nm023_defineAttachedObject = 23,
		nm028_setStiffness = 28,
		nm041_bodyWrithe = 41,
		nm059_armsWindmillAdaptive = 59,
		nm067_pedalLegs = 67,
		nm079_bodyBalance = 79,
		nm114_leanInDirection = 114,
		nm119_leanToPosition = 119,
		nm124_leanTowardsObject = 124,
		nm130_braceForImpact = 130,
		nm145_upperBodyFlinch = 145,
		nm161_grab = 161,
		nm189_catchFall = 189,
		nm198_shot = 198,
		nm234_shotRelax = 234,
		nm237_headLook = 237,
		nm246_highFall = 246,
		nm267_stayUpright = 267,
		nm270_rollDownStairs = 270,
		nm289_fallOverWall = 289,
		nm299_pointArm = 299,
	};

	public enum class nmString : int {
		nm000_stopAllBehaviours, //FUNC
		nm001,
		nm002_start,
		nm003_activePose,
		nm004,
		nm005_mask,
		nm006_incomingTransforms,
		nm007,

		nm008_bodyRelax, //FUNC
		nm009,
		nm010_relaxation,
		nm011_mask,
		nm012_holdPose,
		nm013_damping,

		nm014_configureBalance, //FUNC
		nm015,
		nm016_stepHeight,
		nm017_legStiffness,
		nm018_taperKneeStrength,
		nm019_balanceAbortThreshold,
		nm020_stepClampScale,
		nm021_configureBalanceReset,
		nm022,

		nm023_defineAttachedObject, //FUNC
		nm024,
		nm025_partIndex,
		nm026_worldPos,
		nm027_objectMass,

		nm028_setStiffness, //FUNC
		nm029,
		nm030_mask,
		nm031_bodyStiffness,
		nm032_damping,
		nm033_bodyRollUp,
		nm034_Roll_Up,
		nm035_mask,
		nm036_stiffness,
		nm037_legPush,
		nm038_armReachAmount,
		nm039_useArmToSlowDown,
		nm040_asymmetricalLegs,

		nm041_bodyWrithe, //FUNC
		nm042,
		nm043_armStiffness,
		nm044_legStiffness,
		nm045_backStiffness,
		nm046_legPeriod,
		nm047_armPeriod,
		nm048_backPeriod,
		nm049_legDamping,
		nm050_armDamping,
		nm051_backDamping,
		nm052_legAmplitude,
		nm053_armAmplitude,
		nm054_backAmplitude,
		nm055_kneeAmplitude,
		nm056_elbowAmplitude,
		nm057_mask,
		nm058_rollOverFlag,

		nm059_armsWindmillAdaptive, //FUNC
		nm060,
		nm061_armStiffness,
		nm062_bodyStiffness,
		nm063_period,
		nm064_amplitude,
		nm065_phase,
		nm066_disableOnImpact, //true

		nm067_pedalLegs, //FUNC
		nm068,
		nm069_backPedal,
		nm070_legStiffness,
		nm071_pedalLeftLeg,
		nm072_pedalRightLeg,
		nm073_radius,
		nm074_angularSpeed,
		nm075_pedalOffset,
		nm076_speedAsymmetry,
		nm077_adaptivePedal4Dragging,
		nm078_angSpeedMultiplier4Dragging,

		nm079_bodyBalance, //FUNC
		nm080_balance,
		nm081_bodyStiffness, // 8.4
		nm082_damping,	// 0.7
		nm083_elbow, // 1.95
		nm084_shoulder, // 1.4
		nm085_maxSteps, // 65535
		nm086_useHeadLook,
		nm087_headLookPos,
		nm088_headLookInstanceIndex,
		nm089_headLookAlwaysTimeout, // 8.7
		nm090_somersaultAngle,
		nm091_somersaultAngleThreshold, // 0.1
		nm092_sideSomersaultAngle,
		nm093_sideSomersaultAngleThreshold, // 0.1
		nm094_returningToBalanceArmsOut, // 1.0
		nm095_armsOutOnPush, // True
		nm096_armsOutStraightenElbows,
		nm097_armsOutMinLean2,
		nm098_bodyTurnTimeout,		// 0.6
		nm099_angVelMultiplier,
		nm100_angVelThreshold,
		nm101_armsOutOnPushMultiplier, // 0.8
		nm102_armsOutOnPushTimeout, // 999.0
		nm103_useBodyTurn,
		nm104_elbowAngleOnContact,
		nm105_bendElbowsTime,
		nm106_bendElbowsGait, // -0.3
		nm107_headLookAtVelProb,
		nm108_turnOffProb,		// 0.0
		nm109_turn2VelProb,		// 0.2
		nm110_turnAwayProb,		// 0.0
		nm111_turnLeftProb,		// 0.1
		nm112_turnRightProb,		// 0.1
		nm113_turn2TargetProb,	// 0.6

		nm114_leanInDirection, //FUNC
		nm115,
		nm116_dir,
		nm117_leanAmount,
		nm118_applyAsForce,

		nm119_leanToPosition, //FUNC
		nm120,
		nm121_pos,
		nm122_leanAmount,
		nm123_applyAsForce,

		nm124_leanTowardsObject, //FUNC
		nm125,
		nm126_offset,
		nm127_leanAmount,
		nm128_instanceIndex,
		nm129_applyAsForce,

		nm130_braceForImpact, //FUNC
		nm131,
		nm132_pos,
		nm133_look,
		nm134_instanceIndex,
		nm135_braceDistance,
		nm136_reachAbsorbtionTime,
		nm137_targetPredictionTime,
		nm138_bodyStiffness,
		nm139_grabDontLetGo,
		nm140_grabStrength,
		nm141_grabDistance,
		nm142_grabReachAngle,
		nm143_grabHoldTimer,
		nm144_legStiffness,

		nm145_upperBodyFlinch, //FUNC
		nm146,
		nm147_pos,
		nm148_leftHanded,
		nm149_rightHanded,
		nm150_handDistanceVertical,
		nm151_handDistanceLeftRight,
		nm152_handDistanceFrontBack,
		nm153_bodyStiffness,
		nm154_bodyDamping,
		nm155_backBendAmount,
		nm156_useLeftArm,
		nm157_useRightArm,
		nm158_noiseScale,
		nm159_newHit,
		nm160_turnTowards,

		nm161_grab, //FUNC
		nm162_RightArmGrab,
		nm163_bodyStiffness,
		nm164_grabStrength,
		nm165_pos1,
		nm166_pos2,
		nm167_pos3,
		nm168_pos4,
		nm169_normalL,
		nm170_normalR,
		nm171_linegrab,
		nm172_surfaceGrab,
		nm173_justbrace,
		nm174_tryToPullUp,
		nm175_useLeft,
		nm176_useRight,
		nm177_instanceIndex,
		nm178_dontLetGo,
		nm179_grabDist,
		nm180_reachAngle,
		nm181_oneSideReachAngle,
		nm182_pullUpStrengthLeft,
		nm183_pullUpStrengthRight,
		nm184_pullUpTime,
		nm185_grabHoldMaxTimer,
		nm186_instancePartIndex,
		nm187,
		nm188_LeftArmGrab,

		nm189_catchFall, //FUNC
		nm190_Catch_Fall_2,
		nm191_legsStiffness,
		nm192_armsStiffness,
		nm193_torsoStiffness,
		nm194_backwardsMinArmOffset,
		nm195_forwardMaxArmOffset,
		nm196_zAxisSpinReduction,
		nm197_useHeadLook,

		nm198_shot, //FUNC
		nm199_Shot,
		nm200_bodyStiffness,
		nm201_bodyPart,
		nm202_crouching,
		nm203_reachForWound, // true
		nm204_fling,
		nm205_chickenArms,
		nm206_grabHoldTime,
		nm207_maxSteps,
		nm208_loosenessAmount,
		nm209_stableHandsAndNeck,
		nm210_useHeadLook,
		nm211_hitPoint,
		nm212_bulletVel,
		nm213_normal,
		nm214_headLook,
		nm215_timeBeforeReachForWound, // 0.1
		nm216_timeBeforeCollapseWoundLeg, // 2.0
		nm217_spinePainTime,
		nm218_spinePainMultiplier,
		nm219_spinePainTwistMultiplier,
		nm220_useCatchFallOnFall,
		nm221_headLookAtWoundMinTimer,
		nm222_headLookAtWoundMaxTimer,
		nm223_headLookAtHeadPosMinTimer,
		nm224_headLookAtHeadPosMaxTimer,
		nm225_melee,
		nm226_addShockSpin,
		nm227_randomizeShockSpinDirection,
		nm228_alwaysAddShockSpin,
		nm229_shockSpinMin,
		nm230_shockSpinMax,
		nm231_shockSpinLiftForceMult,
		nm232_shockSpinDecayMult,
		nm233_shockSpinScalePerComponent,

		nm234_shotRelax, //FUNC
		nm235,
		nm236_relaxPeriod,

		nm237_headLook, //FUNC
		nm238,
		nm239_damping,
		nm240_stiffness,
		nm241_instanceIndex,
		nm242_vel,
		nm243_pos,
		nm244_alwaysLook,
		nm245_alwaysEyesHorizontal,

		nm246_highFall,
		nm247_HighFall,
		nm248_bodyStiffness,
		nm249_bodydamping,
		nm250_pdStrength,
		nm251_crashOrLandCutOff,
		nm252_landCutOffVelocity,
		nm253_catchfalltime,
		nm254_armsUp,
		nm255_legRadius,
		nm256_legAngSpeed,
		nm257_armPeriod,
		nm258_armAmplitude,
		nm259_fowardRoll,
		nm260_aimAngleBase,
		nm261_sideD,
		nm262_fowardOffsetOfLegIK,
		nm263_fowardVelRotation,
		nm264_orientateBodyToFallDirection,
		nm265_useZeroPose,
		nm266_ignorWorldCollisions,

		nm267_stayUpright, //FUNC
		nm268,
		nm269_stiffness,

		nm270_rollDownStairs, //FUNC
		nm271,
		nm272_stiffness,
		nm273_damping,
		nm274_forcemag,
		nm275_asymmetry,
		nm276_m_useArmToSlowDown,
		nm277_useZeroPose,
		nm278_spinWhenInAir,
		nm279_m_legPush,
		nm280_armReachLength,
		nm281_m_armReachAmount,
		nm282_tryToAvoidHeadbuttingGround,
		nm283_useCustomRollDir,
		nm284_customRollDir,
		nm285_stiffnessDecayTime,
		nm286_stiffnessDecayTarget,
		nm287_asymmetricalLegs,
		nm288_zAxisSpinReduction,

		nm289_fallOverWall, //FUNC
		nm290,
		nm291_bodyStiffness,
		nm292_damping,
		nm293_magOfForce,
		nm294_maxDistanceFromPelToHitPoint,
		nm295_useSpecifiedPoint,
		nm296_fallOverPoint,
		nm297_fallOverEdge,
		nm298_bodyTwist,

		nm299_pointArm, //FUNC
		nm300,
		nm301_target,
		nm302_twist,
		nm303_armStraightness,
		nm304_useLeftArm,
		nm305_armStiffness,
		nm306_armDamping,
		nm307_instanceIndex,
		nm308_pointSwingLimit,
		nm309_useZeroPoseWhenNotPointing,
	};

}
}