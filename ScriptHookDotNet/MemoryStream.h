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

	CLASS_ATTRIBUTES
	public ref class MemoryStream : System::IO::Stream {

	private:
		__int64 pBaseAddress;
		__int64 pPosition;
		unsigned char* pMemPosition;

	internal:

		MemoryStream(__int64 BaseAddress);

	public:
		MemoryStream();

		property __int64 BaseAddress {
			__int64 get() { return pBaseAddress; }
		}

		virtual property bool CanRead {
			bool get() override;
		}
		virtual property bool CanSeek {
			bool get() override;
		}
		virtual property bool CanWrite {
			bool get() override;
		}
		virtual property __int64 Length {
			__int64 get() override;
		}
		virtual property __int64 Position {
			__int64 get() override;
			void set(__int64 value) override;
		}

		virtual void Flush() override;
		virtual void SetLength(__int64 value) override;
		virtual __int64 Seek(__int64 offset, System::IO::SeekOrigin origin) override;
		virtual int Read(array<Byte>^ buffer, int offset, int count) override;
		virtual void Write(array<Byte>^ buffer, int offset, int count) override;
		virtual int ReadByte() override;

		__int64 FindByte(System::Byte value, __int64 offset);
		__int64 FindInteger(int value, __int64 offset);
		__int64 FindFloat(float value, __int64 offset);
		__int64 FindBytes(array<Byte>^ value, __int64 offset);

	private:

		__int64 FindData(unsigned char* value, int length, __int64 offset);
		bool ReadData(unsigned char* value, int length, __int64 offset);
		bool WriteData(unsigned char* value, int length, __int64 offset);

	public:

		generic <typename T>
		void ReadValue(T Target, __int64 offset);
		generic <typename T>
		void WriteValue(T Source, __int64 offset);

		array<Byte>^ ReadBytes(int Length, __int64 offset);
		void ReadBytes(int Length, __int64 offset, array<Byte>^ Target, int TargetOffset);
		void WriteBytes(array<Byte>^ Source, int SourceOffset, int Length, __int64 offset);
		void WriteBytes(__int64 offset, ... array<Byte>^ Bytes);

		Byte ReadByte(__int64 offset);
		void WriteByte(Byte value, __int64 offset);

		__int16 ReadInt16(__int64 offset);
		void WriteInt16(__int16 value, __int64 offset);

		__int32 ReadInt32(__int64 offset);
		void WriteInt32(__int32 value, __int64 offset);

		__int64 ReadInt64(__int64 offset);
		void WriteInt64(__int64 value, __int64 offset);

		float ReadFloat(__int64 offset);
		void WriteFloat(float value, __int64 offset);

		double ReadDouble(__int64 offset);
		void WriteDouble(double value, __int64 offset);

		void RedirectFunction(__int64 FunctionAddress, __int64 ReplacementFunctionAddress);

	};

}