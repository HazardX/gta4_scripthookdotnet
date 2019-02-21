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

#include "NativeContext3.h"

#include "RemoteScriptDomain.h"

namespace unmanaged {

//#pragma managed

	void NativeContext3::Invoke(ch* name, NativeContext3* cxt)	{
		ptr fn = Game::GetNativeAddress(name);
		if (fn == 0) return;

		if (!GTA::NetHook::isPrimary) {
			try {

				int len = MaxNativeParams * ArgSize;
				array<System::Byte>^ data = gcnew array<System::Byte>(len+2);
				System::Runtime::InteropServices::Marshal::Copy((System::IntPtr)&cxt->m_TempStack,data, 0, len);
				GTA::RemoteScriptDomain::Instance->LastRemoteEventResult = (System::Object^)0;
				GTA::RemoteScriptDomain::Instance->RaiseEventInLocalScriptDomain(GTA::RemoteEvent::NativeInvoke,force_cast<int>(fn),data,(int)cxt->m_nArgCount);
				try {
					*ptr_cast<int>(cxt->m_TempStack) = (int)GTA::RemoteScriptDomain::Instance->LastRemoteEventResult; //m_TempStackReturn
				} catch (...) { // set return value to 0 when LastRemoteEventResult doesn't contain a valid integer
					*ptr_cast<int>(cxt->m_TempStack) = 0;																				  //m_TempStackReturn
				}
				//if (GTA::RemoteScriptDomain::Instance->LastRemoteEventError) {
				//	GTA::NetHook::Log("The last error was caused by Native.Function.Invoke of '"+ gcnew System::String(name) +"'!");
				//}

			} catch(System::Exception^ ex) {
				throw gcnew System::Exception(ex->Message + " during remote call to native function '"+gcnew System::String(name)+"'!");
			} catch(...) {
				throw gcnew System::Exception("UNKNOWN EXCEPTION during remote call to native function '"+gcnew System::String(name)+"'!");
			}
			//} catchScriptErrors(nullptr,"remote Native.Function.Invoke of '"+ gcnew System::String(name) +"'",)
		} else {
			try {

				NativeCall call = (NativeCall)fn;
				call(cxt);

			} catch(System::Exception^ ex) {
				throw gcnew System::Exception(ex->Message + " during local call to native function '"+gcnew System::String(name)+"'!");
			} catch(...) {
				throw gcnew System::Exception("UNKNOWN EXCEPTION during local call to native function '"+gcnew System::String(name)+"'!");
			}
			//} catchScriptErrors(nullptr,"local Native.Function.Invoke of '"+ gcnew System::String(name) +"'",)
		}
	}

//#pragma unmanaged

	void NativeContext3::SetArgument(int index, u8* value, u32 len)	{
		if (len > ArgSize) {	// We only accept sized 4 or less arguments... that means no double/f64 or large structs are allowed.
			throw gcnew System::Exception("Argument has an invalid size");
		}
		else if (len < ArgSize) {	// Ensure we don't have any stray data
			*ptr_cast<u32>(m_TempStack + ArgSize * index) = 0;
		}
		memcpy(m_TempStack + ArgSize * index, value, len);
	}

	void NativeContext3::Push(u8* value, u32 len) {
		SetArgument(m_nArgCount, value, len);
		m_nArgCount++;
	}

	void NativeContext3::Invoke(int nameptr, array<System::Byte>^ args, int argnum, NativeContext3* cxt) {
		ptr fn = force_cast<ptr>(nameptr);
		if (fn == NULL) return;

		cxt->Reset();

		pin_ptr<System::Byte> argsPinned = &args[0];
		memcpy(&cxt->m_TempStack[0], argsPinned, argnum*ArgSize);

		cxt->m_nArgCount = argnum;

		if (fn != 0) {
			NativeCall call = (NativeCall)fn;
			call(cxt);
		}
	}

	u8* NativeContext3::GetResult() {
		ReadVectorDataBack();
		return m_TempStack; //m_TempStackReturn
	}

}