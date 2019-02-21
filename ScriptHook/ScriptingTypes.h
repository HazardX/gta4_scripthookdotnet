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

#define DefineScriptHandle(name) typedef int name; //struct : ScriptHandle {} name
#define DefineInheritedScriptHandle(name, baseName) typedef int name; //struct : baseName {} name

namespace Scripting
{

	typedef u32 ScriptVoid;		// We shall use ScriptVoid instead of explicit void because some 
								// of our template code return values.

	typedef u32 ScriptAny;		// ScriptAny for any types that we don't know yet :)

	typedef struct _ScriptHandle
	{
	private:
		u32 Handle;				// Handles are usually just uint32s

	public:
		_ScriptHandle() : Handle(0) {}
        _ScriptHandle(u32 handle) : Handle(handle) {}
		inline b8 IsNull() { return Handle == 0; }
		inline b8 IsValid() { return Handle != 0; }
		inline u32 Get() { return Handle; }

		// The comparison operation is only valid for handles of the same type!
		inline b8 operator == (const _ScriptHandle &other) { return Handle == other.Handle; }
		inline b8 operator != (const _ScriptHandle &other) { return Handle != other.Handle; }

		inline b8 operator == (const u32 handle) { return Handle == handle; }
		inline b8 operator != (const u32 handle) { return Handle != handle; }
	} ScriptHandle;

	// Explicitly defined handles
	// Use structs instead of just typedefing as ScriptHandle to enforce a bit of type-safety

	typedef u32 Player;		// Left as u32 for legacy support
   typedef u32 FireId;

	DefineScriptHandle(Ped);
	DefineScriptHandle(Vehicle);
	DefineScriptHandle(Cam);
	DefineScriptHandle(CarGenerator);
	DefineScriptHandle(Group);
	DefineInheritedScriptHandle(Train, Vehicle);
	DefineScriptHandle(Pickup);
	DefineScriptHandle(Object);
	DefineScriptHandle(Interior);
	DefineScriptHandle(Blip);
	DefineScriptHandle(Texture);
	DefineScriptHandle(TextureDict);
	DefineScriptHandle(CoverPoint);
	DefineScriptHandle(DecisionMaker);
    DefineScriptHandle(Camera);
    DefineScriptHandle(TaskSequence);

	// For legacy script support...
	typedef Ped Char;
	typedef Vehicle Car;

    // See http://www.gtamodding.com/index.php?title=Carcols.dat#GTA4 for more info
    typedef int ColourIndex;	// 0 thru 133 inclusive
    
	// Some real structures... these are never passed in directly, but only
	// by reference.

	typedef struct { f32 X, Y, Z; } Vector3;

}
