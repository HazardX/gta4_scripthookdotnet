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
#include "Service.h"
#include <vector>
#include <windows.h>

class NativeThread;
class IScriptHookController;

class DllExport ScriptHookManager
{
public:
    // Version
    static u32 GetScriptHookVersion();

    // Threads
	static void RegisterThread(NativeThread *thread);
    static void RegisterThread(NativeThread *thread, HMODULE hMod);     // Using this is recommended if you dynamically allocated the thread

    static void UnregisterThread(NativeThread *thread);

    static void StartThread(NativeThread *thread);     // Start a thread manually
    
    // Services
    static void RegisterService(IService *service);
    static IService * RequestService(const ch *name);
    
    template<class T>
    static T * RequestService(const ch *name)
    {
        return static_cast<T*>( RequestService(name) );
    }

    // Internal
    static IScriptHookController * GetController();
};
