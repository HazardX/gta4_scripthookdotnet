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

#include "fFormHost.h"

#include "Font.h"
#include "Graphics.h"
#include "RemoteScriptDomain.h"
#include "Script.h"

#pragma managed

namespace GTA {
namespace Forms {

	FormHost::FormHost(GTA::Script^ Script) {
		pScript = Script;
		pForms = gcnew List<Form^>();
		pDragControl = nullptr;
		bRemote = NetHook::isScriptDomain;
	}

	void FormHost::Add(Form^ form) {
		if isNULL(form) return;
		if (pForms->Contains(form)) return;
		pForms->Insert(0,form);
		
		if (isInRemoteScriptDomain || isInPrimaryDomain)
			NetHook::Mouse->Enabled = true;
		else if (isInScript)
			RemoteScriptDomain::Instance->FormHost->Add(form);

	}
	void FormHost::Remove(Form^ form) {
		if isNULL(form) return;
		pForms->Remove(form);
		if (System::Object::ReferenceEquals(form, pModalForm)) pModalForm = nullptr;
		if (isInRemoteScriptDomain || isInPrimaryDomain)
			NetHook::TryToDisableMouse();
		else if (isInScript)
			RemoteScriptDomain::Instance->FormHost->Remove(form);
	}

	void FormHost::MoveToTop(Form^ form) {
		if (!System::Object::ReferenceEquals(form, pForms[0])) {
			pForms->Remove(form);
			pForms->Insert(0, form);
			pInputFocus = nullptr;
		}
		if (isInScript) RemoteScriptDomain::Instance->FormHost->MoveToTop(form);
	}
	bool FormHost::isOnTop(Form^ form) {
		if (!System::Object::ReferenceEquals(form, pForms[0])) return false;
		if ( (isInScript) && (!RemoteScriptDomain::Instance->FormHost->isOnTop(form)) ) return false;
		return true;
	}

	Form^ FormHost::GetFormAt(Drawing::PointF pos) {
		return GetFormAt( Drawing::Point((int)Graphics::ConvertUnitsToPixelX(pos.X),(int) Graphics::ConvertUnitsToPixelY(pos.Y)) );
	}
	Form^ FormHost::GetFormAt(Drawing::Point pos) {
		for (int i = 0; i < pForms->Count; i++) {
			if (pForms[i]->isPointInside(pos, false)) return pForms[i];
		}
		return nullptr;
	}
	Control^ FormHost::GetControlAt(Drawing::PointF pos) {
		return GetControlAt( Drawing::Point((int)Graphics::ConvertUnitsToPixelX(pos.X), (int)Graphics::ConvertUnitsToPixelY(pos.Y)) );
	}
	Control^ FormHost::GetControlAt(Drawing::Point pos) {
		Form^ f = GetFormAt(pos);
		if isNULL(f) return nullptr;
		return f->GetControlAt(pos);
	}

	void FormHost::TriggerPaint(GraphicsEventArgs^ e) {
		if (isInScript) return;
		//if isNotNULL(pDragControl) pDragControl->OnDragging(gcnew MouseEventArgs(true,NetHook::Mouse->Position,pDragButton));
		try {
			if (pForms->Count > 0) {
				//if (VERBOSE) NetHook::Log("Rendering " + pForms->Count.ToString() + " Forms now!");
				for (int i = pForms->Count-1; i > 0; i--) {
					if (NetHook::isScriptDomain) RemoteScriptDomain::Instance->SetCurrentScript(pForms[i]->Script);
					//pForms[i]->TriggerBackgroundPaint(e);
					e->Graphics->Scaling = FontScaling::Pixel;
					pForms[i]->TriggerPaint(e);
					pForms[i]->TriggerBackgroundPaint(e);
				}
				if (NetHook::isScriptDomain) RemoteScriptDomain::Instance->SetCurrentScript(pForms[0]->Script);
				e->Graphics->Scaling = FontScaling::Pixel;
				pForms[0]->TriggerPaint(e);
				RemoteScriptDomain::Instance->SetCurrentScript(nullptr);
			}
		} catchScriptErrors (pScript, "Form drawing", if isNotNULL(pScript) pScript->Abort(); )
	}

	void FormHost::TriggerDragging() {
		if isNotNULL(pDragControl) pDragControl->OnDragging(gcnew MouseEventArgs(true,NetHook::Mouse->Position,pDragButton));
	}

	void FormHost::TriggerMouseDown(GTA::MouseEventArgs^ e) {
		if isNotNULL(pDragControl) pDragControl->OnDragRelease(e);
		Form^ f = GetFormAt(e->PixelLocation);
		if isNULL(f) {
			pDragControl = nullptr;
			return;
		}
		if (NetHook::isScriptDomain && isNotNULL(Script)) {
			Form^ globalf = RemoteScriptDomain::Instance->FormHost->GetFormAt(e->PixelLocation);
			if (!System::Object::ReferenceEquals(f, globalf)) return;
		}
		if (!isOnTop(f)) {
			if (isNotNULL(pModalForm) && (!Object::ReferenceEquals(f, pModalForm)) ) return; // another form is modal, do not allow stealing focus
			MoveToTop(f);
			return;
		}
		Control^ c = f->GetControlAt(e->PixelLocation);
		pDragControl = c;
		pDragButton = e->Button;
		if (!System::Object::ReferenceEquals(c, pInputFocus)) {
			pInputFocus = c;
			if isNotNULL(pInputFocus) pInputFocus->OnGotFocus(EventArgs::Empty);
		}
		if isNULL(c) return;
		c->OnMouseDown(e);
	}
	void FormHost::TriggerMouseUp(GTA::MouseEventArgs^ e) {
		Control^ c = GetControlAt(e->PixelLocation);
		if isNotNULL(c){
			c->OnMouseUp(e);
			if (System::Object::ReferenceEquals(pDragControl, c) && (e->Button == pDragButton)) {
				c->OnClick(e);
			}
		}
		if isNotNULL(pDragControl) pDragControl->OnDragRelease(e);
		pDragControl = nullptr;
	}

	void FormHost::TriggerKeyDown(GTA::KeyEventArgs^ e) {
		if isNULL(pInputFocus) return;
		pInputFocus->OnKeyDown(e);
	}
	void FormHost::TriggerKeyUp(GTA::KeyEventArgs^ e) {
		if isNULL(pInputFocus) return;
		pInputFocus->OnKeyUp(e);
	}

}
}