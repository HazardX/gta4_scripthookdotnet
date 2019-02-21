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

#include "../Service.h"

class DllExport IKeyboardHookHandler
{
public:
    struct KeyEventArgs
    {
        u32 VirtualKey;
        u16 RepeatCount;
        u8 ScanCode;
        b8 IsExtendedKey;
        b8 IsAltPressed;
        b8 WasKeyDownBefore;
        b8 IsKeyUpNow;
    };

    virtual void OnKeyboardHookEvent( const KeyEventArgs &args ) = 0;
};

class DllExport IKeyboardHookService
    : public IService
{
public:
    virtual void AddHandler( IKeyboardHookHandler *handler ) = 0;
    virtual void RemoveHandler( IKeyboardHookHandler *handler ) = 0;

    virtual b8 IsInExclusiveMode() = 0;
    virtual b8 RequestExclusiveAccess( IKeyboardHookHandler *handler ) = 0;
    virtual void ReleaseExclusiveAccess() = 0;
    
};

