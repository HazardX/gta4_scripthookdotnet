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

namespace Scripting {

	//class scrNativeCallContext2
	//{
	//protected:
	//	ptr m_pReturn;
	//	u32 m_nArgCount;
	//	ptr m_pArgs;
	//	
	//	u32 m_nDataCount;
	//	//f32 m_fData[Count];		// probably only in subclasses?
	//};

	class NativeContext2 : public GameTypes::scrNativeCallContext {

private:

	// Configuration
	enum {
		MaxNativeParams = 16,
		MaxPointerParams = MaxNativeParams + 4, // 2 parameters can be vector3
		MaxReturnParams = 16,
		ArgSize = sizeof(u32),
	};
	
	// Anything temporary that we need
	u8 m_TempStack[MaxNativeParams * ArgSize];
	u8 m_TempStackPtr[MaxPointerParams * ArgSize];
	u8 m_TempStackReturn[MaxReturnParams * ArgSize];

	u32 ptrPos;

	typedef void (_cdecl *NativeCall)(GameTypes::scrNativeCallContext *cxt);

	void ReadVectorDataBack() {
		// Copy back any vector results
		while(m_nDataCount > 0) {
			m_nDataCount--;
			Vector3 *pVec3 = m_pOriginalData[m_nDataCount];
			Vector4 *pVec4 = &m_TemporaryData[m_nDataCount];
			pVec3->X = pVec4->X;
			pVec3->Y = pVec4->Y;
			pVec3->Z = pVec4->Z;
		}
	}

public:

	NativeContext2()	{
		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStackReturn; //&m_TempStack;		// It's okay to point both args and return at 
									// the same pointer. The game should handle this.
		m_nArgCount = 0;
		m_nDataCount = 0;
		ptrPos = 0;
	}

	void Reset() {
		m_nArgCount = 0;
		m_nDataCount = 0;
		ptrPos = 0;
	}

	int ArgCount() {
		return m_nArgCount;
	}


	void SetArgument(int index, u8* value, u32 len);

	template <typename T>
	inline void SetArgument(int index, T value) {
		SetArgument(index, (u8*)&value, sizeof(T));
	}


	void Push(u8* value, u32 len);

	template <typename T>
	inline void Push(T value) {
		Push((u8*)&value, sizeof(T));
	}


	void PushPtr(u8* value, u32 len);

	template <typename T>
	inline void PushPtr(T value) {
		PushPtr((u8*)&value, sizeof(T));
	}


	u8* GetArgumentPtr(int index);
	void GetArgumentPtr(int index, u8* trg, u32 len);

	template <typename T>
	inline T GetArgumentPtr(int index) {
		u8* ptr = GetArgumentPtr(index);
		return *ptr_cast<T>(ptr);
	}


	static void Invoke(ch* name, NativeContext2* cxt);


	u8* GetResult();

	template <typename T>
	inline T GetResult()	{
		ReadVectorDataBack();
		return *ptr_cast<T>(m_TempStackReturn); //*ptr_cast<T>(m_TempStack);
	}

	static int GetAddress(ch* name);

};

}