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

#include "vDynamicMetadata.h"

#include "ContentCache.h"
#include "RemoteScriptDomain.h"
#include "Script.h"

#pragma managed

namespace GTA {
namespace value {

	DynamicMetadata::DynamicMetadata(GTA::base::HandleObject^ object, bool global) {
		pObject = object;
		bGlobal = global;
	}

	System::Object^ DynamicMetadata::Global::get(){
		if (bGlobal) return this;
		if isNULL(pGlobalMetadata) pGlobalMetadata = gcnew DynamicMetadata(pObject, true);
		return pGlobalMetadata;
	}

	bool DynamicMetadata::Contains(System::String^ MetadataName) {
		if (bGlobal) {
			return ContentCache::HasMetaData(pObject->Handle,MetadataName->ToLower());
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) return false;
			return scr->HasMetaData(pObject->Handle,MetadataName->ToLower());
		}
	}

    bool DynamicMetadata::TrySetMember(System::Dynamic::SetMemberBinder^ binder, System::Object^ value) {
		if (bGlobal) {
			ContentCache::SetMetaData(pObject->Handle,binder->Name->ToLower(),value);
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) return true;
			scr->SetMetaData(pObject->Handle,binder->Name->ToLower(),value);
		}
		return true;

	}

    bool DynamicMetadata::TryGetMember(System::Dynamic::GetMemberBinder^ binder, System::Object^% result) {
		if (bGlobal) {
			result = ContentCache::GetMetaData(pObject->Handle,binder->Name->ToLower());
		} else {
			Script^ scr = RemoteScriptDomain::Instance->CurrentScript;
			if (System::Object::ReferenceEquals(scr,nullptr)) { result = nullptr; return true; }
			result = scr->GetMetaData(pObject->Handle,binder->Name->ToLower());
		}
      return true;
	}

}
}