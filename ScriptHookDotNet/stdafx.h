/*
* Copyright (c) 2009-2011 Hazard (hazard_x@gmx.net / twitter.com/HazardX)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <vcclr.h>

#include "../ScriptHook/GameTypes.h"
#include "../ScriptHook/Services/D3DHook.h"
#include "../ScriptHook/NativeInvoke.h"
#include "../ScriptHook/NativeThread.h"

#include "enums.h"
#include "D3D_enums.h"
#include "NmEnums.h"

#include "include_defines.h"

#include "sVector2.h"
#include "sVector3.h"
#include "sQuaternion.h"
#include "sMatrix.h"
#include "sModel.h"
#include "sFoundScript.h"
#include "sRoom.h"
#include "dColorConverter.h"
#include "sColorIndex.h"
#include "ImageInformation.h"

#include "interfaces.h"

#include "bCollection.h"
#include "bObject.h"
#include "bHandleObject.h"
#include "bScriptChild.h"
#include "bConsole.h"
#include "bMouse.h"

#include "EventArgs.h"

#include "NativeContext3.h"
#include "nFunction.h"
#include "Scripting.h"
#include "nScripting.h"

#include "fControl.h"
#include "fForm.h"

#include "vHelper.h"
#include "NetHook.h"