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

namespace unmanaged {

	#pragma unmanaged

	//class scrNativeCallContext3
	//{
	//protected:
	//	ptr m_pReturn;
	//	u32 m_nArgCount;
	//	ptr m_pArgs;
	//	
	//	u32 m_nDataCount;
	//	//f32 m_fData[Count];		// probably only in subclasses?
	//};

	class NativeContext3 : public GameTypes::scrNativeCallContext {

	private:

		// Configuration
		enum {
			MaxNativeParams = 16,
			MaxReturnParams = 16,
			ArgSize = sizeof(u32),
		};
		
		// Anything temporary that we need
		u8 m_TempStack[MaxNativeParams * ArgSize];
		//u8 m_TempStackReturn[MaxReturnParams * ArgSize];

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

		NativeContext3() {
			m_pArgs = &m_TempStack;
			m_pReturn = &m_TempStack; //&m_TempStackReturn;		// It's okay to point both args and return at 
										// the same pointer. The game should handle this.
			m_nArgCount = 0;
			m_nDataCount = 0;
		}

		void Reset() {
			m_nArgCount = 0;
			m_nDataCount = 0;
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

		static void Invoke(ch* name, NativeContext3* cxt);
		static void Invoke(int nameptr, array<System::Byte>^ args, int argnum, NativeContext3* cxt);

		u8* GetResult();

		template <typename T>
		inline T GetResult()	{
			ReadVectorDataBack();
			return *ptr_cast<T>(m_TempStack); //*ptr_cast<T>(m_TempStackReturn);
		}

	};

	#pragma managed

namespace Native {

	class Function {

		public:

		template <typename R>
		static inline R Invoke(ch *name) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1>
		static inline R Invoke(ch *name, T1 p1) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2>
		static inline R Invoke(ch *name, T1 p1, T2 p2) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
					typename T5>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
					typename T5, typename T6>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
					typename T5, typename T6, typename T7>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);
			cxt->Push(p12);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12, T13 p13) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);
			cxt->Push(p12);
			cxt->Push(p13);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);
			cxt->Push(p12);
			cxt->Push(p13);
			cxt->Push(p14);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);
			cxt->Push(p12);
			cxt->Push(p13);
			cxt->Push(p14);
			cxt->Push(p15);

			NativeContext3::Invoke(name, cxt);
			return cxt->GetResult<R>();
		}


		template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
		static inline R Invoke(ch *name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15, T16 p16) {
			NativeContext3* cxt = GTA::Native::Function::cxt3;
			cxt->Reset();

			cxt->Push(p1);
			cxt->Push(p2);
			cxt->Push(p3);
			cxt->Push(p4);
			cxt->Push(p5);
			cxt->Push(p6);
			cxt->Push(p7);
			cxt->Push(p8);
			cxt->Push(p9);
			cxt->Push(p10);
			cxt->Push(p11);
			cxt->Push(p12);
			cxt->Push(p13);
			cxt->Push(p14);
			cxt->Push(p15);
			cxt->Push(p16);

			NativeContext3::Invoke(name, cxt);
			return cxt.GetResult<R>();
		}
	};

}
}