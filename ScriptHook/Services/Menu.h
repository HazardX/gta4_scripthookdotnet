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
#include <d3d9.h>

class DllExport IMenuRender
{
public:
    virtual ~IMenuRender();

    virtual void RenderStart() = 0;

    virtual void RenderTitle( const ch *title ) = 0;
    virtual void RenderItem( u32 index, const ch *name, b8 selected ) = 0;

    virtual void RenderEnd() = 0;
};

class IMenu;

class DllExport IMenuHandler
{
public:
    virtual void OnMenuParentChanged( IMenu *menu, u32 parentId ) = 0;
    virtual void OnMenuSelectionChanged( IMenu *menu, u32 id ) = 0;
    virtual void OnMenuSelected( IMenu *menu, u32 id ) = 0;
};

class DllExport IMenu
{
protected:
    virtual ~IMenu();

public:
    enum
    {
        RootMenuId = 0xffffffff,
    };

    virtual void Release() = 0;

    void SetTitle( const ch *title ) { SetTitle( RootMenuId, title ); }
    void AddItem( u32 id, const ch *itemName ) { AddItem( RootMenuId, id, itemName ); }

    virtual void SetTitle( u32 id, const ch *title ) = 0;

    virtual void AddItem( u32 parentId, u32 id, const ch *itemName ) = 0;
    virtual void SetItem( u32 id, const ch *itemName ) = 0;

    virtual b8 Show() = 0;
    virtual void Hide() = 0;
    virtual b8 IsRunning() = 0;

    virtual b8 DoesSubMenuExist( u32 id ) = 0;

    virtual u32 GetSelectedItem() = 0;
    virtual void SetSelectedItem( u32 id ) = 0;

    virtual u32 GetCurrentParent() = 0;
    virtual void SetCurrentParent( u32 id ) = 0;

    virtual void SetCustomRender( IMenuRender *render ) = 0;
    virtual void SetEventHandler( IMenuHandler *handler ) = 0;
};

class DllExport IMenuService
    : public IService
{
public:
    virtual IMenu *CreateMenu() = 0;
};

