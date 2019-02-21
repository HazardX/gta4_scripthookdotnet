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
namespace value {

	CLASS_ATTRIBUTES
	public ref class Euphoria sealed {

	private:
		Ped^ ped;
		Dictionary<GTA::Euphoria::nmMessageID,GTA::Euphoria::BaseHelper^>^ pHelperCache;

		generic <typename HelperType> where HelperType: GTA::Euphoria::BaseHelper 
		HelperType Euphoria::GetHelper(GTA::Euphoria::nmMessageID MessageID);

	internal:
		Euphoria(Ped^ ped);

	public:

		property GTA::Euphoria::ArmsWindmillHelper^ ArmsWindmill {
			GTA::Euphoria::ArmsWindmillHelper^ get() {
				return GetHelper<GTA::Euphoria::ArmsWindmillHelper^>(GTA::Euphoria::nmMessageID::nm059_armsWindmillAdaptive);
			}
		}

		property GTA::Euphoria::BodyBalanceHelper^ BodyBalance {
			GTA::Euphoria::BodyBalanceHelper^ get() {
				return GetHelper<GTA::Euphoria::BodyBalanceHelper^>(GTA::Euphoria::nmMessageID::nm079_bodyBalance);
			}
		}

		property GTA::Euphoria::BeingShotHelper^ BeingShot {
			GTA::Euphoria::BeingShotHelper^ get() {
				return GetHelper<GTA::Euphoria::BeingShotHelper^>(GTA::Euphoria::nmMessageID::nm198_shot);
			}
		}

		property GTA::Euphoria::GrabHelper^ Grab {
			GTA::Euphoria::GrabHelper^ get() {
				return GetHelper<GTA::Euphoria::GrabHelper^>(GTA::Euphoria::nmMessageID::nm161_grab);
			}
		}

		property GTA::Euphoria::LeanToPositionHelper^ LeanToPosition {
			GTA::Euphoria::LeanToPositionHelper^ get() {
				return GetHelper<GTA::Euphoria::LeanToPositionHelper^>(GTA::Euphoria::nmMessageID::nm119_leanToPosition);
			}
		}

		//property GTA::Euphoria::LeanTowardsObjectHelper^ LeanTowardsObject {
		//	GTA::Euphoria::LeanTowardsObjectHelper^ get() {
		//		return GetHelper<GTA::Euphoria::LeanTowardsObjectHelper^>(GTA::Euphoria::nmMessageID::nm124_leanTowardsObject);
		//	}
		//}

		property GTA::Euphoria::PedalLegsHelper^ PedalLegs {
			GTA::Euphoria::PedalLegsHelper^ get() {
				return GetHelper<GTA::Euphoria::PedalLegsHelper^>(GTA::Euphoria::nmMessageID::nm067_pedalLegs);
			}
		}

		/*
		/// <summary>
		/// Switches the Ped to Euphoria mode and tries to grab the given car. Stays in this mode for the given duration, no matter if grabbing is a success. Maximum duration is 65535 milliseconds. Aborts previous Euphoria animations.
		/// </summary>
		void GrabVehicle(Vehicle^ v, int duration);
		/// <summary>
		/// Switches the Ped to Euphoria mode and tries to grab the given car. Stays in this mode for up to 65 seconds, no matter if grabbing is a success. Aborts previous Euphoria animations.
		/// </summary>
		void GrabVehicle(Vehicle^ v) {
			GrabVehicle(v, -1);
		}*/

	};

}
}