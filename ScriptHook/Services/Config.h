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

class DllExport IConfig
{
protected:
    virtual ~IConfig();

public:
    virtual void Release() = 0; // Delete the config object

    virtual void Load(const ch *filename) = 0;
    virtual void Save(const ch *filename) = 0;

    virtual void Set(const ch *section, const ch *key, const ch *value) = 0;
    virtual void Set(const ch *section, const ch *key, i32 value) = 0;
    virtual void Set(const ch *section, const ch *key, f32 value) = 0;

    virtual const ch * GetString(const ch *section, const ch *key, const ch *defaultValue = NULL) = 0;
    virtual i32 GetInteger(const ch *section, const ch *key, i32 defaultValue = 0) = 0;
    virtual f32 GetFloat(const ch *section, const ch *key, f32 defaultValue = 0.0f) = 0;
};

class DllExport IConfigService
    : public IService
{
public:
    enum eConfigType
    {
        ConfigTypeXml,
        ConfigTypeIni,
    };

    virtual IConfig * Create(eConfigType type) = 0;
};

