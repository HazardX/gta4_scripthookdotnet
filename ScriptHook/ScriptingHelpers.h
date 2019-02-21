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

#include "ScriptingTypes.h"
#include "ScriptingEnums.h"


class DllExport ScriptingHelpers
{
public:
	static Scripting::eModel GetModelHash(const ch *name);
	static void Wait(u32 timeMS);
	static void TerminateThisScript();
};

namespace Scripting
{

	// Custom helper functions

	//static inline eModel GetModelHash(const ch *name) { return ScriptingHelpers::GetModelHash(name); }

	static inline void Wait(u32 timeMS) { ScriptingHelpers::Wait(timeMS); }

	static inline void TerminateThisScript() { ScriptingHelpers::TerminateThisScript(); }

	static inline b8 IsNullHandle(ScriptHandle handle) { return handle.IsNull(); }

	static inline b8 IsValidHandle(ScriptHandle handle) { return handle.IsValid(); }

}

