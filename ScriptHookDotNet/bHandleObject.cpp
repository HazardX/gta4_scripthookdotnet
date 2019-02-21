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

#include "bHandleObject.h"

#include "ContentCache.h"
#include "RemoteScriptDomain.h"
#include "Script.h"
#include "vDynamicMetadata.h"

#pragma managed

namespace GTA {
namespace base {

	System::Object^ HandleObject::Metadata::get() {
		if isNULL(pMetadata) pMetadata = gcnew GTA::value::DynamicMetadata(this, false);
		return pMetadata;
	}

	generic<typename T>
	T HandleObject::GetMetadata(System::String^ ValueName, bool Global) {
		if (Global) {
			return static_cast<T>(ContentCache::GetMetaData(pHandle,ValueName));
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) return T();
			return static_cast<T>(scr->GetMetaData(pHandle,ValueName));
		}
	}

	generic<typename T>
	T HandleObject::GetMetadata(System::String^ ValueName) {
		Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
		if (!System::Object::ReferenceEquals(scr,nullptr)) {
			if (scr->HasMetaData(pHandle,ValueName)) return static_cast<T>(scr->GetMetaData(pHandle,ValueName));
		}
		return static_cast<T>(ContentCache::GetMetaData(pHandle,ValueName));
	}

	bool HandleObject::HasMetadata(System::String^ ValueName, bool Global) {
		if (Global) {
			return ContentCache::HasMetaData(pHandle,ValueName);
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) return false;
			return scr->HasMetaData(pHandle,ValueName);
		}
	}
	bool HandleObject::HasMetadata(System::String^ ValueName) {
		Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
		if (!System::Object::ReferenceEquals(scr,nullptr)) {
			if (scr->HasMetaData(pHandle,ValueName)) return true;
		}
		return ContentCache::HasMetaData(pHandle,ValueName);
	}

	generic<typename T>
	void HandleObject::SetMetadata(System::String^ ValueName, bool Global, T Value) {
		if (Global) {
			ContentCache::SetMetaData(pHandle,ValueName,(System::Object^)Value);
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) return;
			scr->SetMetaData(pHandle,ValueName,(System::Object^)Value);
		}
	}

}
}