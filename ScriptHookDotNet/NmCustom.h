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
	public ref class CustomMessage : public BaseMessage {

	public:

		CustomMessage(nmMessageID MessageID)
			:BaseMessage(MessageID){
		}

		property nmMessageID MessageID {
			nmMessageID get() {
				return pMessageID;
			}
		}

		/// <summary>
		/// Start the Euphoria animation. Maximum duration is 65535 milliseconds. Calling this will disable previous Euphoria animations.
		/// </summary>
		void SendTo(GTA::Ped^ TargetPed, int Duration) {
			pApplyTo(TargetPed,Duration);
		}

		/// <summary>
		/// Start the Euphoria animation. It will run up to a maximum of 65 seconds, or until the first previous Euphoria animation ends. Previous Euphoria animations will NOT be disabled.
		/// </summary>
		void SendTo(GTA::Ped^ TargetPed) {
			pApplyTo(TargetPed);
		}

		void Abort(GTA::Ped^ TargetPed) {
			General::Abort(TargetPed,pMessageID);
		}

	};

	public ref class CustomHelper : public BaseHelper {

	public:

		CustomHelper(GTA::Ped^ Ped, nmMessageID MessageID)
			:BaseHelper(Ped, MessageID){
		}

		/// <summary>
		/// Start the Euphoria animation. Maximum duration is 65535 milliseconds. Calling this will disable previous Euphoria animations.
		/// </summary>
		void Start(int Duration) {
			pStart(Duration);
		}
		/// <summary>
		/// Start the Euphoria animation. It will run up to a maximum of 65 seconds, or until the first previous Euphoria animation ends. Previous Euphoria animations will NOT be disabled.
		/// </summary>
		void Start() {
			pStart();
		}

	};

}
}