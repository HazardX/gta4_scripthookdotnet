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
#include "NativeThread.h"

class ScriptingHelpers;

class DllExport NativeFiberThread : 
	public NativeThread
{
friend class ScriptingHelpers;

private:
	b8 m_bKillRequested;
	ptr m_pPrimaryFiber;
	ptr m_pScriptFiber;
	u32 m_nWaitTick;

	static void _stdcall FiberStart(ptr parameter);

	virtual void RunTick() {}	// We don't use this function anymore, 
								// all the magic is now done in RunScript

protected:
	GameTypes::eThreadState Reset(u32 scriptHash, ptr pArgs, u32 argCount);
	GameTypes::eThreadState Run(u32 opsToExecute);

	virtual void RunScript() = 0;	// To be overridden
	
	void Wait(u32 timeMS);			// Override the Wait native
	void TerminateThisScript();		// Override the TerminateThisScript native
	
	b8 IsThreadAlive();

public:
	NativeFiberThread();
	~NativeFiberThread();

	void Kill();
};