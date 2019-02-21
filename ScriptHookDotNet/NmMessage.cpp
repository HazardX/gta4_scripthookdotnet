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

#include "stdafx.h"

/*#include "Ped.h"
#include "NmCommands.h"*/

#include "NmMessage.h"

#include "Ped.h"

#pragma managed

namespace GTA {
namespace Euphoria {

	void BaseMessage::pApplyTo(GTA::Ped^ TargetPed, int EnforceRagdollDuration) {
		if (EnforceRagdollDuration != 0) General::EnforceRagdoll(TargetPed, EnforceRagdollDuration); 
		pApplyTo(TargetPed);
	}

	void BaseMessage::pApplyTo(GTA::Ped^ TargetPed) {
		if (!TargetPed->isRagdoll) General::EnforceRagdoll(TargetPed, -1); 

		unmanaged::Native::CreateNmMessage(true,(u32)pMessageID);
		
		if (isNotNULL(ListInteger) && (ListInteger->Count > 0)) {
			//NetHook::Log("SetNmMessageInt"); 
			for each (KeyValuePair<int,int> item in ListInteger) {
				Scripting::SetNmMessageInt(item.Key, item.Value);
			}
		}
		if (isNotNULL(ListBoolean) && (ListBoolean->Count > 0)) {
			//NetHook::Log("SetNmMessageBool"); 
			for each (KeyValuePair<int,bool> item in ListBoolean) {
				Scripting::SetNmMessageBool(item.Key, item.Value);
			}
		}
		if (isNotNULL(ListFloat) && (ListFloat->Count > 0)) {
			//NetHook::Log("SetNmMessageFloat"); 
			for each (KeyValuePair<int,float> item in ListFloat) {
				Scripting::SetNmMessageFloat(item.Key, item.Value);
			}
		}
		if (isNotNULL(ListString) && (ListString->Count > 0)) {
			//NetHook::Log("SetNmMessageString"); 
			for each (KeyValuePair<int,String^> item in ListString) {
				char* ptr = PinStringA(item.Value);
				Scripting::SetNmMessageString(item.Key, ptr);
				FreeString(ptr);
			}
		}
		if (isNotNULL(ListVector3) && (ListVector3->Count > 0)) {
			//NetHook::Log("SetNmMessageVec3"); 
			for each (KeyValuePair<int,GTA::Vector3> item in ListVector3) {
				Scripting::SetNmMessageVec3(item.Key, item.Value.X, item.Value.Y, item.Value.Z);
			}
		}
		if (isNotNULL(ListHandle) && (ListHandle->Count > 0)) {
			//NetHook::Log("SetNmMessageInstanceIndex"); 
			for each (KeyValuePair<int,u32> item in ListHandle) {
				Scripting::SetNmMessageInstanceIndex(item.Key, 0, item.Value, 0);
			}
		}

		//NetHook::Log("SendNmMessage"); 
		OBJECT_NON_EXISTING_CHECK(TargetPed);
		unmanaged::Native::SendNmMessage(TargetPed->Handle);
	}

	void General::Abort(GTA::Ped^ TargetPed, nmMessageID MessageID) {
		OBJECT_NON_EXISTING_CHECK(TargetPed);
		unmanaged::Native::CreateNmMessage(false,(u32)MessageID);
		unmanaged::Native::SendNmMessage(TargetPed->Handle);
	}

	void General::EnforceRagdoll(GTA::Ped^ Ped, int duration) {
		OBJECT_NON_EXISTING_CHECK(Ped);
		unmanaged::Native::SwitchPedToRagdoll(Ped->Handle, 10000, duration, 1, 1, 1, 0);  //unmanaged::Native
	}

	bool General::GetFeedback(GTA::Ped^ TargetPed, nmString FeedbackID, int FeedbackNum) {
		OBJECT_NON_EXISTING_CHECK(TargetPed,false);
		return Scripting::CheckNmFeedback(TargetPed->Handle,(u32)FeedbackID,FeedbackNum);
	}

	//void BaseHelper::pStart() {
	//	if (pPed->isRagdoll) 
	//		pApplyTo(pPed);
	//	else
	//		pApplyTo(pPed,-1);
	//}

}
}