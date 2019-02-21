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

namespace GTA {
	value class Vector3;
}
namespace Scripting {
	class NativeContext2;
}
namespace unmanaged {
	class NativeContext3;
}

#pragma managed

namespace GTA {

	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;

namespace Native{

	ref class Parameter;

	CLASS_ATTRIBUTES
	public ref class Function sealed {

	private:
		Function(){};
		static Function();

		static Scripting::NativeContext2* cxt; // = new NativeContext2;
		static List<IntPtr>^ stringsToUnpin; // = gcnew List<IntPtr>();
		//static bool bInit = false;
		static void BaseCall(String^ Name, array<Parameter^>^ Arguments);

	internal:

		static unmanaged::NativeContext3* cxt3; // = new NativeContext3;

		static char* GetStringPointer(String^ input);

		static void Push(int value);
		static void Push(float value);
		static void Push(String^ value);

		static void PushPtr(int value);
		static void PushPtr(float value);
		static void PushPtr(String^ value);
		static void PushPtr(GTA::Vector3 value);
		//static void PushPtr();

		//static void SetArgument(int index, int value);
		//static void SetArgument(int index, float value);
		//static void SetArgument(int index, String^ value);

		//static void SetArgumentPtr(int index, int value);
		//static void SetArgumentPtr(int index, float value);
		//static void SetArgumentPtr(int index, String^ value);
		//static void SetArgumentPtr(int index);

		//static int GetArgumentInt(int index);
		//static float GetArgumentFloat(int index);
		//static String^ GetArgumentString(int index);

		static int GetArgumentIntPtr(int index);
		static float GetArgumentFloatPtr(int index);
		static GTA::Vector3 GetArgumentVector3Ptr(int index);

		static void Invoke(String^ name);
		//static int Invoke(String^ name, ... array<int>^ args);

		static System::Object^ GetResult(System::Type^ ReturnType);
		generic <typename ReturnType>
		static ReturnType GetResult();
		static int GetIntResult();
		static float GetFloatResult();
		static String^ GetStringResult();
		static GTA::Vector3 GetVector3Result();

		static void Cleanup();

		static System::Object^ Call(String^ Name, System::Type^ ReturnType, ... array<Parameter^>^ Arguments);

	public:
		~Function();

		static void Call(String^ Name, ... array<Parameter^>^ Arguments);

		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		static int GetAddress(System::String^ name);

		generic <typename ReturnType>
		static ReturnType Call(String^ Name, ... array<Parameter^>^ Arguments);

	};

}
}