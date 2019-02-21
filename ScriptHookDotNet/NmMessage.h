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
	public ref class General sealed {
	private:
		General(){}
	public:
		static void Abort(GTA::Ped^ TargetPed, nmMessageID MessageID);
		static bool GetFeedback(GTA::Ped^ TargetPed, nmString FeedbackID, int FeedbackNum);
	internal:
		static void EnforceRagdoll(GTA::Ped^ Ped, int duration);
	};

	CLASS_ATTRIBUTES
	public ref class BaseMessage abstract {

	private:
		
		Dictionary<int,int>^ ListInteger;
		Dictionary<int,bool>^ ListBoolean;
		Dictionary<int,float>^ ListFloat;
		Dictionary<int,String^>^ ListString;
		Dictionary<int,GTA::Vector3>^ ListVector3;
		Dictionary<int,u32>^ ListHandle;

	internal:

		nmMessageID pMessageID;

		void pApplyTo(GTA::Ped^ TargetPed);
		void pApplyTo(GTA::Ped^ TargetPed, int Duration);

		BaseMessage(nmMessageID MessageID) {
			pMessageID = MessageID;
			/*ListInteger = gcnew Dictionary<int,int>();
			ListBoolean = gcnew Dictionary<int,bool>();
			ListFloat = gcnew Dictionary<int,float>();
			ListString = gcnew Dictionary<int,String^>();
			ListVector3 = gcnew Dictionary<int,GTA::Vector3>();
			ListHandle = gcnew Dictionary<int,u32>();*/
		}

	public:

		void SetValue(nmString ValueID, double Value) {
			if isNULL(ListFloat) ListFloat = gcnew Dictionary<int,float>();
			ListFloat->default[(int)ValueID] = (float)Value;
		}
		void SetValue(nmString ValueID, GTA::base::HandleObject^ Value) {
			OBJECT_NON_EXISTING_CHECK(Value);
			if isNULL(ListHandle) ListHandle = gcnew Dictionary<int,u32>();
			if isNotNULL(Value)
				ListHandle->default[(int)ValueID] = Value->Handle;
			else
				ListHandle->default[(int)ValueID] = 0;
		}

		/// <summary>
		/// For directional vectors: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		void SetValue(nmString ValueID, GTA::Vector3 Value) {
			if isNULL(ListVector3) ListVector3 = gcnew Dictionary<int,GTA::Vector3>();
			ListVector3->default[(int)ValueID] = Value;
		}
		void SetValue(nmString ValueID, String^ Value) {
			if isNULL(ListString) ListString = gcnew Dictionary<int,String^>();
			ListString->default[(int)ValueID] = Value;
		}
		void SetValue(nmString ValueID, float Value) {
			if isNULL(ListFloat) ListFloat = gcnew Dictionary<int,float>();
			ListFloat->default[(int)ValueID] = Value;
		}
		void SetValue(nmString ValueID, bool Value) {
			if isNULL(ListBoolean) ListBoolean = gcnew Dictionary<int,bool>();
			ListBoolean->default[(int)ValueID] = Value;
		}
		void SetValue(nmString ValueID, int Value) {
			if isNULL(ListInteger) ListInteger = gcnew Dictionary<int,int>();
			ListInteger->default[(int)ValueID] = Value;
		}

	};

	public ref class BaseHelper abstract : public BaseMessage {

	protected:

		GTA::Ped^ pPed;

		bool GetFeedback(nmString FeedbackID, int FeedbackNum) {
			return General::GetFeedback(pPed,FeedbackID,FeedbackNum);
		}

	internal:

		BaseHelper(GTA::Ped^ Ped, nmMessageID MessageID)
			:BaseMessage(MessageID){
			pPed = Ped;
		}

		void pStart(int Duration) {
			pApplyTo(pPed,Duration);
		}
		void pStart() {
			pApplyTo(pPed);
		}

	public:

		void Stop() {
			General::Abort(pPed,pMessageID);
		}

	};

}
}