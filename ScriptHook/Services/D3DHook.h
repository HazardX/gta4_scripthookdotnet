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

/*****************************************************************************\

 Direct3D Hook Service
 
 This service allows you to hook into the game's Direct3D rendering calls
 and do your own rendering after the game has completed its rendering.

 To use:

   ID3DHookService *service = 
              static_cast<ID3DHookService *>( 
                         ScriptHookManager::RequestService("D3DHook");
                      );
   service->AddDeviceHook( &myHook );

\*****************************************************************************/

#pragma once

#include "../Service.h"
#include <d3d9.h>

class DllExport ID3DDeviceHook
{
public:
    typedef IDirect3DDevice9 ID3DDevice;
    typedef D3DPRESENT_PARAMETERS PresentParameters;

    // Executed once during service start up
    // Create resources that will live through a reset here (i.e. D3DPOOL_MANAGED)
    virtual void OnCreateDevice(ID3DDevice *pDevice, PresentParameters *pPresentParameters) = 0;

    /// Executed once during service start up, and for every time the device is reset
    // Create resources that will live through a reset here (i.e. D3DPOOL_DEFAULT)
    virtual void OnResetDevice(ID3DDevice *pDevice, PresentParameters *pPresentParameters) = 0;

    // Executed once during service shut down, and for every time the device is lost
    // Release/delete you created in OnResetDevice here
    virtual void OnLostDevice(ID3DDevice *pDevice) = 0;

    // Executed once during service shut down
    // Release/delete you created in OnCreateDevice here
    virtual void OnDestroyDevice(ID3DDevice *pDevice) = 0;

    // Executed for every frame that is rendered
    virtual void OnRender(ID3DDevice *pDevice) = 0;
};

class DllExport ID3DHookService
    : public IService
{
public:
    virtual void AddDeviceHook(ID3DDeviceHook *pHook) = 0;
    virtual void RemoveDeviceHook(ID3DDeviceHook *pHook) = 0;
};

