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
	public ref class GrabHelper : public CustomHelper {

	public:

		GrabHelper(GTA::Ped^ Ped)
			:CustomHelper(Ped, nmMessageID::nm161_grab){
		}

		property bool isLeftHandGrabbed {
			bool get() {
				return GetFeedback(nmString::nm188_LeftArmGrab,0);
			}
		}
		property bool isRightHandGrabbed {
			bool get() {
				return GetFeedback(nmString::nm162_RightArmGrab,0);
			}
		}
		property bool isGrabbed {
			bool get() {
				return (isLeftHandGrabbed || isRightHandGrabbed);
			}
		}

		property float GrabStrength {
			void set(float value) {
				SetValue(nmString::nm164_grabStrength,value);
			}
		}
		property float GrabDistance {
			void set(float value) {
				SetValue(nmString::nm179_grabDist,value);
			}
		}

		property Euphoria::GrabMethod GrabMethod {
			void set(Euphoria::GrabMethod value) {
				switch (value) {
					case Euphoria::GrabMethod::Line:
						SetValue(nmString::nm172_surfaceGrab,false);
						SetValue(nmString::nm171_linegrab,true);
						break;
					case Euphoria::GrabMethod::Surface:
						SetValue(nmString::nm171_linegrab,false);
						SetValue(nmString::nm172_surfaceGrab,true);
						break;
					default:
						SetValue(nmString::nm171_linegrab,false);
						SetValue(nmString::nm172_surfaceGrab,false);
						break;
				}
			}
		}

		property bool UseLeftHand {
			void set(bool value) {
				SetValue(nmString::nm175_useLeft,value);
			}
		}
		property bool UseRightHand {
			void set(bool value) {
				SetValue(nmString::nm176_useRight,value);
			}
		}
		property bool DontLetGo {
			void set(bool value) {
				SetValue(nmString::nm178_dontLetGo,value);
			}
		}

		property base::HandleObject^ ItemToGrab {
			void set(base::HandleObject^ value) {
				SetValue(nmString::nm177_instanceIndex,value);
			}
		}

		property int MaxDuration {
			void set(int value) {
				SetValue(nmString::nm185_grabHoldMaxTimer,value);
			}
		}

		/// <summary>
		/// The Offset from ItemToGrab, that defines the area where to grab. LineGrab uses offsets 1+2, SurfaceGrab uses offsets 1-4.
		/// </summary>
		property Vector3 Offset1 {
			void set(Vector3 value) {
				SetValue(nmString::nm165_pos1,value);
			}
		}
		/// <summary>
		/// The Offset from ItemToGrab, that defines the area where to grab. LineGrab uses offsets 1+2, SurfaceGrab uses offsets 1-4.
		/// </summary>
		property Vector3 Offset2 {
			void set(Vector3 value) {
				SetValue(nmString::nm166_pos2,value);
			}
		}
		/// <summary>
		/// The Offset from ItemToGrab, that defines the area where to grab. LineGrab uses offsets 1+2, SurfaceGrab uses offsets 1-4.
		/// </summary>
		property Vector3 Offset3 {
			void set(Vector3 value) {
				SetValue(nmString::nm167_pos3,value);
			}
		}
		/// <summary>
		/// The Offset from ItemToGrab, that defines the area where to grab. LineGrab uses offsets 1+2, SurfaceGrab uses offsets 1-4.
		/// </summary>
		property Vector3 Offset4 {
			void set(Vector3 value) {
				SetValue(nmString::nm168_pos4,value);
			}
		}


	};

}
}