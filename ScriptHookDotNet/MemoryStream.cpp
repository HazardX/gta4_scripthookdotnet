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

#include "MemoryStream.h"

#pragma managed

namespace GTA {

	MemoryStream::MemoryStream(__int64 BaseAddress) {
		pBaseAddress = BaseAddress;
	}

	MemoryStream::MemoryStream() {
#ifdef _YAASIL
		pBaseAddress = GTA::YAASIL::Core::BaseAddress.ToInt64(); //Scripting::GetBaseAddress();
#else
#ifdef _SHDN
		pBaseAddress = GTA::NetHook::BaseAddress; //Scripting::GetBaseAddress();
#else
		//
#endif
#endif
		if (pBaseAddress == 0) {
			pBaseAddress = reinterpret_cast<u32>( GetModuleHandle(NULL) );
			pBaseAddress -= 0x400000;
		}
	}

	bool MemoryStream::CanRead::get() {
		return true;
	}
	bool MemoryStream::CanSeek::get() {
		return true;
	}
	bool MemoryStream::CanWrite::get() {
		return true;
	}
	__int64 MemoryStream::Length::get() {
		return 0x0A000000; //0x02000000; //0x1DCD6500
	}

	__int64 MemoryStream::Position::get() {
		return pPosition;
	}
	void MemoryStream::Position::set(__int64 value) {
		pPosition = value;
		pMemPosition = (unsigned char*)(pBaseAddress + value);
	}

	void MemoryStream::Flush() {
	}

	void MemoryStream::SetLength(Int64 value) {
		throw gcnew NotSupportedException();
	}

	__int64 MemoryStream::Seek(__int64 offset, System::IO::SeekOrigin origin) {
		switch (origin) {
			case System::IO::SeekOrigin::Begin:
				Position = offset;
				return Position;
			case System::IO::SeekOrigin::Current:
				Position += offset;
				return Position;
			case System::IO::SeekOrigin::End:
				Position = Length + offset;
				return Position;
		}
		return Position;
	}

	int MemoryStream::Read(array<Byte>^ buffer, int offset, int count) {
		try {
			pin_ptr<Byte> bufferPinned = &buffer[offset];
			memcpy(bufferPinned, pMemPosition, count);
			return count;
		} catch(...) {
			return 0;
		} finally {
			Position += count;
		}
	}

	void MemoryStream::Write(array<Byte>^ buffer, int offset, int count) {
		try {
			pin_ptr<Byte> bufferPinned = &buffer[offset];
			memcpy(pMemPosition, bufferPinned, count);
		} catch(...) {
			throw gcnew Exception("Writing to game memory failed!");
		} finally {
			Position += count;
		}
	}

	int MemoryStream::ReadByte() {
		try {
			unsigned char b = *pMemPosition;
			return (int)b;
		} catch(...) {
			return -1;
		} finally {
			Position += 1;
		}
	}

	__int64 MemoryStream::FindByte(Byte value, __int64 offset) {
		unsigned char val = (unsigned char)value;
		unsigned char* pos = (unsigned char*)(pBaseAddress+offset);
		unsigned char* len = (unsigned char*)Length;
		for (pos; pos<len; pos++) {
			try {
				if (*pos == val) return (__int64)(pos-pBaseAddress);
			} catch(...) {	}
		}
		return -1;
	}

	__int64 MemoryStream::FindInteger(int value, __int64 offset) {
		return FindData((unsigned char*)&value, 4, offset);
	}

	__int64 MemoryStream::FindFloat(float value, __int64 offset) {
		return FindData((unsigned char*)&value, 4, offset);
	}

	__int64 MemoryStream::FindBytes(array<Byte>^ value, __int64 offset) {
		pin_ptr<Byte> valuePinned = &value[0];
		return FindData(valuePinned, value->Length, offset);
	}

	__int64 MemoryStream::FindData(unsigned char* value, int length, __int64 offset) {
		unsigned char* pos = (unsigned char*)(pBaseAddress+offset);
		unsigned char* len = (unsigned char*)Length;
		int i;
		bool found;
		for (pos; pos<len; pos++) {
			try {

				if (*pos == *value) {
					found = true;
					for (i=1; i<length; i++) {
						if (pos[i] != value[i]) {
							found = false;
							break;
						}
					}
					if (found) return (__int64)(pos-pBaseAddress);
				}

			} catch(...) {	}
		}
		return -1;
	}

	bool MemoryStream::ReadData(unsigned char* value, int length, __int64 offset) {
		try {
			memcpy(value, (unsigned char*)(pBaseAddress+offset) , length);
			return true;
		} catch(...) {
			return false;
		}
	}

	bool MemoryStream::WriteData(unsigned char* value, int length, __int64 offset) {
		try {
			memcpy( (unsigned char*)(pBaseAddress+offset), value, length);
			return true;
		} catch(...) {
			return false;
		}
	}

	// usability functions

	generic <typename T>
	void MemoryStream::ReadValue(T Target, __int64 offset) {
		ReadData( (unsigned char*)&Target, sizeof(T), offset);
	}
	generic <typename T>
	void MemoryStream::WriteValue(T Source, __int64 offset) {
		WriteData( (unsigned char*)&Source, sizeof(T), offset);
	}

	array<Byte>^ MemoryStream::ReadBytes(int Length, __int64 offset) {
		array<Byte>^ ary = gcnew array<Byte>(Length);
		ReadBytes(Length,offset,ary,0);
		return ary;
	}
	void MemoryStream::ReadBytes(int Length, __int64 offset, array<Byte>^ Target, int TargetOffset) {
		pin_ptr<Byte> TargetPinned = &Target[TargetOffset];
		ReadData((unsigned char*)TargetPinned, Length, offset);
	}
	void MemoryStream::WriteBytes(array<Byte>^ Source, int SourceOffset, int Length, __int64 offset) {
		pin_ptr<Byte> SourcePinned = &Source[SourceOffset];
		WriteData((unsigned char*)SourcePinned,Length,offset);
	}
	void MemoryStream::WriteBytes(__int64 offset, ... array<Byte>^ Bytes) {
		WriteBytes(Bytes, 0, Bytes->Length, offset);
	}

	Byte MemoryStream::ReadByte(__int64 offset) {
		return *(Byte*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteByte(Byte value, __int64 offset) {
		*(Byte*)(pBaseAddress+offset) = value;
	}

	__int16 MemoryStream::ReadInt16(__int64 offset) {
		return *(__int16*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteInt16(__int16 value, __int64 offset) {
		*(__int16*)(pBaseAddress+offset) = value;
	}

	__int32 MemoryStream::ReadInt32(__int64 offset) {
		return *(__int32*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteInt32(__int32 value, __int64 offset) {
		*(__int32*)(pBaseAddress+offset) = value;
	}

	__int64 MemoryStream::ReadInt64(__int64 offset) {
		return *(__int64*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteInt64(__int64 value, __int64 offset) {
		*(__int64*)(pBaseAddress+offset) = value;
	}

	float MemoryStream::ReadFloat(__int64 offset) {
		return *(float*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteFloat(float value, __int64 offset) {
		*(float*)(pBaseAddress+offset) = value;
	}

	double MemoryStream::ReadDouble(__int64 offset) {
		return *(double*)(pBaseAddress+offset);
	}
	void MemoryStream::WriteDouble(double value, __int64 offset) {
		*(double*)(pBaseAddress+offset) = value;
	}

	void MemoryStream::RedirectFunction(__int64 FunctionAddress, __int64 ReplacementFunctionAddress) {
		FunctionAddress += pBaseAddress;
		BYTE * patch = (BYTE *)((DWORD)FunctionAddress);
		*patch = 0xE9;	// JMP
		*(DWORD *)(patch+1) = (DWORD)(ReplacementFunctionAddress-(FunctionAddress+5));	
	}


}