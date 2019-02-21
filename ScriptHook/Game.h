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

class IGame;

//class IGameVersion {
//public:
//	virtual int *Script_GetActiveThread() = 0;
//};

class DllExport Game
{
public:
    enum eVersion
    {
        VersionAutoDetect,
        Version101,
        Version102,
        Version103,
        Version104,
    };

private:
	static u32 m_nBaseAddress;

	static IGame *m_pInstance;
    static eVersion m_Version;

public:

	static void Initialize(eVersion version);

	static u32 GetBase();

	static IGame *GetInstance();

	static ptr GetNativeAddress(const ch *name);

	static ptr GetGlobalAddress(u32 index);

    static eVersion GetVersion();

	template <typename T>
	static T GetGlobalValue(u32 index)
	{
		return *ptr_cast<T>(GetGlobalAddress(index));
	}

	template <typename T>
	static void SetGlobalValue(u32 index, T value)
	{
		*ptr_cast<T>(GetGlobalAddress(index)) = value;
	}
};
