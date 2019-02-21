/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

\*****************************************************************************/

#pragma once

#include "Types.h"

namespace GameTypes
{
	template <typename T>
	struct CSimpleCollection
	{
		T **Data;
		u16 Count;
		u16 Size;
	};

	enum eThreadState
	{
		ThreadStateIdle,
		ThreadStateRunning,
		ThreadStateKilled,
		ThreadState3,
		ThreadState4,			// Sets opsToExecute to 1100000, and state to Idle in CallNative
	};

	class scrNativeCallContext
	{
	protected:
        typedef struct { f32 X, Y, Z; } Vector3;
        typedef struct { f32 X, Y, Z, W; } Vector4;

		ptr m_pReturn;
		u32 m_nArgCount;
		ptr m_pArgs;
		
		u32 m_nDataCount;
		Vector3 *m_pOriginalData[4];
        Vector4 m_TemporaryData[4];
	};

	struct scrThreadContext
	{
		u32 ThreadId;		//00000000 m_nThreadId dd ?
		u32 ScriptHash;		//00000004 m_dwScriptHash dd ?
		eThreadState State;	//00000008 m_eThreadState dd ?
		u32 IP;				//0000000C m_nIP       dd ?
		u32 FrameSP;		//00000010 m_nFrameSP  dd ?
		u32 SP;				//00000014 m_nSP       dd ?
		u32 TimerA;			//00000018 m_nTimerA   dd ?
		u32 TimerB;			//0000001C m_nTimerB   dd ?
		u32 TimerC;			//00000020 m_nTimerC   dd ?
		f32 WaitTime;		//00000024 m_fWaitTime dd ?
		u32 _f28;			//00000028 field_28    dd ?
		u32 _f2C;			//0000002C field_2C    dd ?
		u32 _f30;			//00000030 field_30    dd ?
		u32 _f34;			//00000034 field_34    dd ?
		u32 _f38;			//00000038 field_38    dd ?
		u32 _f3C;			//0000003C field_3C    dd ?
		u32 _f40;			//00000040 field_40    dd ?
		u32 ExIP;			//00000044 ExIP        dd ?
		u32 ExFrameSP;		//00000048 ExFrameSP   dd ?
		u32 ExSP;			//0000004C ExSP        dd ?
		u32 _f50;			//00000050 field_50    dd ?
	};

	class DllExport scrThread
	{
	protected:	
										//00000000 _vmt        dd ?
		scrThreadContext m_Context;		//00000004 m_Context   scrThreadContext ?
		ptr m_pStack;					//00000058 m_pStack    dd ?
		u32 _f5C;						//0000005C field_5C    dd ?
		ptr m_pXLiveBuffer;				//00000060 m_pXLiveBuffer dd ?
		u32 _f64;						//00000064 field_64    dd ?
		u32 _f68;						//00000068 field_68    dd ?
		ch *m_pszExitMessage;			//0000006C m_pszExitMessage dd ?                   ; offset

	public:
		virtual ~scrThread() {}
		virtual eThreadState Reset(u32 scriptHash, ptr pArgs, u32 argCount) = 0;
		virtual eThreadState Run(u32 opsToExecute) = 0;
		virtual eThreadState Tick(u32 opsToExecute) = 0;
		virtual void Kill() = 0;

		scrThreadContext *GetContext() { return &m_Context; }
	};

	class DllExport GtaThread :
		public scrThread
	{
	protected:
												//00000000 _parent     scrThread ?
		ch m_szProgramName[24];					//00000070 m_szProgramName db 24 dup(?)
		u32 _f88;								//00000088 field_88    dd ?
		u32 _f8C;								//0000008C field_8C    dd ?
		u32 _f90;								//00000090 field_90    dd ?
		b8 _f94;								//00000094 field_94    db ?
		b8 _f95;								//00000095 --- db ?									// Check IDA
		b8 m_bThisScriptShouldBeSaved;			//00000096 m_bThisScriptShouldBeSaved db ?
		b8 m_bPlayerControlOnInMissionCleanup;	//00000097 m_bPlayerControlOnInMissionCleanup db ?
		b8 m_bClearHelpInMissionCleanup;		//00000098 m_bClearHelpInMissionCleanup db ?
		b8 _f99;								//00000099 field_99    db ?
		b8 m_bAllowNonMinigameTextMessages;		//0000009A m_bAllowNonMinigameTextMessages db ?
		b8 _f9B;								//0000009B field_9B    db ?
		b8 _f9C;								//0000009C --- db ?									// Check IDA
		b8 m_bCanBePaused;						//0000009D m_bCanBePaused db ?
		b8 _f9E;								//0000009E field_9E    db ?
		b8 _f9F;								//0000009F field_9F    db ?
		b8 _fA0;								//000000A0 field_A0    dd ?
		b8 m_bCanRemoveBlipsCreatedByAnyScript; //000000A4 m_bCanRemoveBlipsCreatedByAnyScript db ?
		b8 _fA5;								//000000A5             db ? ; undefined
		b8 _fA6;								//000000A6             db ? ; undefined
		b8 _fA7;								//000000A7             db ? ; undefined
		u32 _fA8;								//000000A8 field_A8    dd ?
		u32 m_nFlags;							//000000AC m_nFlags    dd ?

	};

}
