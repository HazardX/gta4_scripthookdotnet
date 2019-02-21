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

	CLASS_ATTRIBUTES
	public ref class BodyBalanceHelper : public CustomHelper {

	public:

		BodyBalanceHelper(GTA::Ped^ Ped)
			:CustomHelper(Ped, nmMessageID::nm079_bodyBalance){
		}

		property bool isBalanced {
			bool get() {
				return !GetFeedback(nmString::nm080_balance,1);
			}
		}

		property float Stiffness {
			void set(float value) {
				SetValue(nmString::nm081_bodyStiffness,value);
			}
		}
		property float Damping {
			void set(float value) {
				SetValue(nmString::nm082_damping,value);
			}
		}

		property int MaxSteps {
			void set(int value) {
				SetValue(nmString::nm085_maxSteps,value);
			}
		}

		//nm083_elbow, // 1.95
		//nm084_shoulder, // 1.4
		//nm086_useHeadLook,
		//nm087_headLookPos,
		//nm088_headLookInstanceIndex,
		//nm089_headLookAlwaysTimeout, // 8.7
		//nm090_somersaultAngle,
		//nm091_somersaultAngleThreshold, // 0.1
		//nm092_sideSomersaultAngle,
		//nm093_sideSomersaultAngleThreshold, // 0.1
		//nm094_returningToBalanceArmsOut, // 1.0
		//nm095_armsOutOnPush, // True
		//nm096_armsOutStraightenElbows,
		//nm097_armsOutMinLean2,
		//nm098_bodyTurnTimeout,		// 0.6
		//nm099_angVelMultiplier,
		//nm100_angVelThreshold,
		//nm101_armsOutOnPushMultiplier, // 0.8
		//nm102_armsOutOnPushTimeout, // 999.0
		//nm103_useBodyTurn,
		//nm104_elbowAngleOnContact,
		//nm105_bendElbowsTime,
		//nm106_bendElbowsGait, // -0.3
		//nm107_headLookAtVelProb,
		//nm108_turnOffProb,		// 0.0
		//nm109_turn2VelProb,		// 0.2
		//nm110_turnAwayProb,		// 0.0
		//nm111_turnLeftProb,		// 0.1
		//nm112_turnRightProb,		// 0.1
		//nm113_turn2TargetProb,	// 0.6

	};

}
}