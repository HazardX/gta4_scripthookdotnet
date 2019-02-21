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

#include "stdafx.h"

#include "vResources.h"

#include "Script.h"
#include "Texture.h"

#pragma managed

namespace GTA {
namespace value {

	Resources::Resources(Script^ script) {
		this->script = script;
	}

	array<Byte>^ Resources::GetData(String^ ResourceName) {
		return Helper::GetResourceData(ResourceName, script->GetType());
	}

	String^ Resources::GetText(String^ ResourceName, System::Text::Encoding^ Encoding) {
		return Helper::GetResourceString(ResourceName, script->GetType(), Encoding);
	}

	String^ Resources::GetText(String^ ResourceName) {
		return GetText(ResourceName, nullptr);
	}

	Texture^ Resources::GetTexture(String^ ResourceName) {
		return gcnew Texture( GetData(ResourceName) );
	}

}
}