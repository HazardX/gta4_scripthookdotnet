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
#pragma managed

namespace GTA {
namespace Forms {

	CLASS_ATTRIBUTES
	private ref class FormHost sealed {

	private:
		GTA::Script^ pScript;
		List<Form^>^ pForms;
		Control^ pDragControl;
		Control^ pInputFocus;
		Windows::Forms::MouseButtons pDragButton;
		bool bRemote;
		Form^ pModalForm;

	internal:
		FormHost(GTA::Script^ Script);

		//static property Form^ FocusForm {
		//	Form^ get() { return pFocusForm; }
		//}

	public:
		property bool isInPrimaryDomain {
			bool get() {
				if isNotNULL(pScript) return false;
				return !bRemote;
			}
		}
		property bool isInRemoteScriptDomain {
			bool get() {
				if isNotNULL(pScript) return false;
				return bRemote;
			}
		}
		property bool isInScript {
			bool get() {
				return isNotNULL(pScript);
			}
		}
		property Form^ TopmostForm {
			Form^ get() {
				if (pForms->Count == 0) return nullptr;
				return pForms[0];
			}
		}

		property int FormCount {
			int get() {
				return pForms->Count;
			}
		}
		property GTA::Script^ Script {
			GTA::Script^ get() { return pScript; }
		}

		void Add(Form^ form);
		void Remove(Form^ form);
		void MoveToTop(Form^ form);
		bool isOnTop(Form^ form);

		void SetModalForm(Form^ form) {
			pModalForm = form;
		}

		Form^ GetFormAt(Drawing::PointF ScreenLocation);
		Form^ GetFormAt(Drawing::Point ScreenPoint);
		Control^ GetControlAt(Drawing::PointF ScreenLocation);
		Control^ GetControlAt(Drawing::Point ScreenPoint);

		void TriggerPaint(GraphicsEventArgs^ e);
		void TriggerMouseDown(GTA::MouseEventArgs^ e);
		void TriggerMouseUp(GTA::MouseEventArgs^ e);
		void TriggerKeyDown(GTA::KeyEventArgs^ e);
		void TriggerKeyUp(GTA::KeyEventArgs^ e);
		void TriggerDragging();

	};

}
}