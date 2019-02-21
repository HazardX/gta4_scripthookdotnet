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

/*#include <stdio.h>
#include <string.h>

#include "../ScriptHook/GameTypes.h"*/
#include "NativeContext2.h"

 
namespace Scripting {

	void NativeContext2::SetArgument(int index, u8* value, u32 len)	{
		if (len > ArgSize) {	// We only accept sized 4 or less arguments... that means no double/f64 or large structs are allowed.
			throw "Argument has an invalid size";
		}
		else if (len < ArgSize) {	// Ensure we don't have any stray data
			*ptr_cast<u32>(m_TempStack + ArgSize * index) = 0;
		}
		memcpy(m_TempStack + ArgSize * index, value, len);
	}

	void NativeContext2::Push(u8* value, u32 len) {
		SetArgument(m_nArgCount, value, len);
		m_nArgCount++;
	}

	void NativeContext2::PushPtr(u8* value, u32 len) {
		memcpy(m_TempStackPtr + ptrPos, value, len);
		Push<int>((int)(m_TempStackPtr + ptrPos));
		ptrPos += len;
	}

	u8* NativeContext2::GetArgumentPtr(int index)	{
		int ptr = *ptr_cast<int>(m_TempStack + ArgSize * index);
		return (u8*)ptr;
	}
	void NativeContext2::GetArgumentPtr(int index, u8* trg, u32 len)	{
		u8* ptr = GetArgumentPtr(index);
		memcpy(trg,ptr,len);
	}

	void NativeContext2::Invoke(ch* name, NativeContext2* cxt)	{
		//u32 hash = Game::GetInstance()->Hash(name);
		//ptr fn = Game::GetInstance()->Script_FindNativeAddress(hash);
		ptr fn = Game::GetNativeAddress(name);

		if (fn != 0) {
			NativeCall call = (NativeCall)fn;
			call(cxt);
		}
	}

	u8* NativeContext2::GetResult() {
		ReadVectorDataBack();
		return m_TempStackReturn;
	}

	int NativeContext2::GetAddress(ch* name) {
		return (int)(Game::GetNativeAddress(name)); //GetModelHash(ptr);
	}

}
//}