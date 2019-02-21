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

#include "nFunction.h"

#include "NativeContext2.h"
#include "RemoteScriptDomain.h"
#include "nParameter.h"
#include "nTemplate.h"

#pragma managed

namespace GTA {
namespace Native {

	static Function::Function(){
		cxt = new Scripting::NativeContext2;
		cxt3 = new unmanaged::NativeContext3;
		stringsToUnpin = gcnew List<IntPtr>();
	}

	Function::~Function() {
		delete cxt;
		delete cxt3;
		Cleanup();
	}

	char* Function::GetStringPointer(String^ input) {
		char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(input).ToPointer();
		stringsToUnpin->Add( IntPtr(stringPointer) );
		return stringPointer;
	}
	int Function::GetAddress(System::String^ name) {
		int res = 0;
		char* ptr = PinStringA(name);
		try {
			res = Scripting::NativeContext2::GetAddress(ptr); //GetModelHash(ptr);
		} finally {
			FreeString(ptr);
		}
		return res - int(NetHook::BaseAddress);
	}

	void Function::BaseCall(String^ Name, array<Parameter^>^ Arguments) {
		cxt->Reset();

		try {

			for (int i = 0; i < Arguments->Length; i++){
				Arguments[i]->Push(cxt);
			}
			Scripting::NativeContext2::Invoke(GetStringPointer(Name),cxt);

			for (int i = 0; i < Arguments->Length; i++){
				Arguments[i]->AfterExec(cxt);
			}

		} catchScriptErrors (RemoteScriptDomain::Instance->CurrentScript, "native call to '"+Name+"'",)
	}

	System::Object^ Function::Call(String^ Name, System::Type^ ReturnType, ... array<Parameter^>^ Arguments) {

		if (!NetHook::isPrimary) {
			RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(RemoteEvent::NativeCall, gcnew Template(Name, ReturnType, Arguments));
			return RemoteScriptDomain::Instance->LastRemoteEventResult;
		}

		BaseCall(Name, Arguments);

		System::Object^ res;
		try {	

			res = GetResult(ReturnType);

		} catchScriptErrors (RemoteScriptDomain::Instance->CurrentScript, "return from native call to '"+Name+"'",)
		finally {
			Cleanup();
		}
		
		return res;
	}

	generic <typename ReturnType>
	ReturnType Function::Call(String^ Name, ... array<Parameter^>^ Arguments) {
		return (ReturnType)Call(Name, ReturnType::typeid, Arguments);
	}

	void Function::Call(String^ Name, ... array<Parameter^>^ Arguments) {
		ALTERNATE_LOCAL_EVENT(RemoteEvent::NativeCall, gcnew Template(Name, Arguments),,return;)

		BaseCall(Name, Arguments);
		Cleanup();
	}



	void Function::Push(int value) {
		cxt->Push(value);
	}
	void Function::Push(float value) {
		cxt->Push(value);
	}
	void Function::Push(String^ value) {
		cxt->Push(GetStringPointer(value)); // do NOT use PushPtr, since this one is already a pointer
	}

	void Function::PushPtr(int value){
		cxt->PushPtr(value);
	}
	void Function::PushPtr(float value){
		cxt->PushPtr(value);
	}
	void Function::PushPtr(String^ value) {
		Push(value); // Strings are always pointers
	}
	void Function::PushPtr(GTA::Vector3 value){
		Scripting::Vector3 val;
		val.X = value.X; val.Y = value.Y; val.Z = value.Z;
		cxt->PushPtr(val);
	}

	int Function::GetArgumentIntPtr(int index) {
		return cxt->GetArgumentPtr<int>(index);
	}
	float Function::GetArgumentFloatPtr(int index) {
		return cxt->GetArgumentPtr<float>(index);
	}
	GTA::Vector3 Function::GetArgumentVector3Ptr(int index) {
		Scripting::Vector3 res = cxt->GetArgumentPtr<Scripting::Vector3>(index);
		return GTA::Vector3(res.X,res.Y,res.Z);
	}

	void Function::Invoke(String^ name) {
		bool bFail = false;
      char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
		try {
			Scripting::NativeContext2::Invoke(stringPointer, cxt);
		} catch (...) {
			bFail = true;
		} finally {
			Marshal::FreeHGlobal(IntPtr(stringPointer));
		}
		if (bFail) throw gcnew InvalidOperationException(String::Concat( "Native call to function ", name, " was invalid!" ));
	}

	System::Object^ Function::GetResult(System::Type^ ReturnType) {
		Parameter^ p = gcnew Parameter(ReturnType);
		p->pData = cxt->GetResult<int>();
		return p->Value;
	}

	generic <typename ReturnType>
	ReturnType Function::GetResult() {
		return (ReturnType)GetResult(ReturnType::typeid);
	}

	int Function::GetIntResult(){
		return cxt->GetResult<int>();
	}
	float Function::GetFloatResult(){
		return cxt->GetResult<float>();
	}
	String^ Function::GetStringResult(){
		return gcnew String(cxt->GetResult<const char*>());
	}
	GTA::Vector3 Function::GetVector3Result(){
		Scripting::Vector3 res = cxt->GetResult<Scripting::Vector3>();
		return GTA::Vector3(res.X,res.Y,res.Z);
	}

	void Function::Cleanup() {
		for (int i = stringsToUnpin->Count-1; i>=0; i--) {
			Marshal::FreeHGlobal(stringsToUnpin->default[i]);
		}
		stringsToUnpin->Clear();
		cxt->Reset();
	}

}
}