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
#include "GameTypes.h"

class ScriptHookController;

class DllExport NativeThread : 
	protected GameTypes::GtaThread
{
    friend ScriptHookController;

private:
    GameTypes::GtaThread *m_pOriginalThread;
	i32 m_nThreadIndex;

protected:
	ch m_szThreadName[24];

	GameTypes::eThreadState Reset(u32 scriptHash, ptr pArgs, u32 argCount);
	GameTypes::eThreadState Run(u32 opsToExecute);
	GameTypes::eThreadState Tick(u32 opsToExecute);

	virtual void RunTick() = 0;
    void InitializeHook(GameTypes::GtaThread *originalThread, i32 threadIndex, u32 threadId);
    b8 IsHooked();

public:
	NativeThread();
	~NativeThread();

	virtual void Start();
	void Kill();
	void SetName(ch *szName);
};