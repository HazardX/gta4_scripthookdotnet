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
#include "dEventArgs.h"
#include "dControlDesigner.h"

#pragma managed

namespace GTA {
namespace Design {

	System::ComponentModel::Design::IComponentChangeService^ ControlDesigner::ComponentChangeService::get() {
		return (System::ComponentModel::Design::IComponentChangeService^)GetService(System::ComponentModel::Design::IComponentChangeService::typeid);
	}
   System::ComponentModel::Design::IDesignerHost^ ControlDesigner::DesignerHost::get() {
		return (System::ComponentModel::Design::IDesignerHost^)GetService(System::ComponentModel::Design::IDesignerHost::typeid);
	}
   System::ComponentModel::Design::Serialization::IDesignerSerializationService^ ControlDesigner::DesignerSerializationService::get() {
		return (System::ComponentModel::Design::Serialization::IDesignerSerializationService^)GetService(System::ComponentModel::Design::Serialization::IDesignerSerializationService::typeid);
	}
   System::ComponentModel::Design::IMenuCommandService^ ControlDesigner::MenuCommandService::get() {
		return (System::ComponentModel::Design::IMenuCommandService^)GetService(System::ComponentModel::Design::IMenuCommandService::typeid);
	}
   System::ComponentModel::Design::ISelectionService^ ControlDesigner::SelectionService::get() {
		return (System::ComponentModel::Design::ISelectionService^)GetService(System::ComponentModel::Design::ISelectionService::typeid);
	}
   System::Drawing::Design::IToolboxService^ ControlDesigner::ToolboxService::get() {
		return (System::Drawing::Design::IToolboxService^)GetService(System::Drawing::Design::IToolboxService::typeid);
	}

	GTA::Forms::Control^ ControlDesigner::Control::get() {
		return (GTA::Forms::Control^)Component;
	}


	void ControlDesigner::Initialize(System::ComponentModel::IComponent^ component) {
		System::ComponentModel::Design::ComponentDesigner::Initialize(component);
      System::ComponentModel::Design::IDesignerHost^ host = DesignerHost;

		if isNotNULL(host) {
         host->LoadComplete += gcnew EventHandler(this, &ControlDesigner::OnDesignerLoadCompleteInternal);
			host->Activated += gcnew EventHandler(this, &ControlDesigner::OnDesignerActivatedInternal);
			host->Deactivated += gcnew EventHandler(this, &ControlDesigner::OnDesignerDeactivatedInternal);
		}

      System::ComponentModel::Design::IComponentChangeService^ cs  = ComponentChangeService;
		if isNotNULL(cs) {
			cs->ComponentRemoved += gcnew System::ComponentModel::Design::ComponentEventHandler(this, &ControlDesigner::OnComponentRemoved);
		}
	}

	void ControlDesigner::OnDesignerLoadCompleteInternal(System::Object^ sender, EventArgs^ e) {
      System::ComponentModel::Design::IDesignerHost^ host = (System::ComponentModel::Design::IDesignerHost^)sender;
      host->LoadComplete -= gcnew EventHandler(this, &ControlDesigner::OnDesignerLoadCompleteInternal);
      OnDesignerLoadComplete(gcnew DesignerHostEventArgs(host));
	}
	void ControlDesigner::OnDesignerLoadComplete(DesignerHostEventArgs^ e) {
	}

	void ControlDesigner::OnDesignerActivatedInternal(System::Object^ sender, EventArgs^ e) {
      System::ComponentModel::Design::IDesignerHost^ host = (System::ComponentModel::Design::IDesignerHost^)sender;
      OnDesignerActivated(gcnew DesignerHostEventArgs(host));
	}
	void ControlDesigner::OnDesignerActivated(DesignerHostEventArgs^ e) {
	}

	void ControlDesigner::OnDesignerDeactivatedInternal(System::Object^ sender, EventArgs^ e) {
      System::ComponentModel::Design::IDesignerHost^ host = (System::ComponentModel::Design::IDesignerHost^)sender;
      OnDesignerDeactivated(gcnew DesignerHostEventArgs(host));
	}
	void ControlDesigner::OnDesignerDeactivated(DesignerHostEventArgs^ e) {
	}



	void ControlDesigner::!ControlDesigner() {
		//if (disposing) {
         System::ComponentModel::Design::IDesignerHost^ host = DesignerHost;
			if isNotNULL(host) {
				host->Activated -= gcnew EventHandler(this, &ControlDesigner::OnDesignerActivatedInternal);
            host->Deactivated -= gcnew EventHandler(this, &ControlDesigner::OnDesignerDeactivatedInternal);
			}
			System::ComponentModel::Design::IComponentChangeService^ cs = ComponentChangeService;
			if isNotNULL(cs) {
				cs->ComponentRemoved -= gcnew System::ComponentModel::Design::ComponentEventHandler(this, &ControlDesigner::OnComponentRemoved);
			}
		//}
			//System::ComponentModel::Design::ComponentDesigner::!ComponentDesigner();
	}

   // Because we are connecting ourself to another control on the design surface, we
   // must listen to remove events.  If the control we're painting to is being removed,
   // we need to detatch the paint event we added.
	void ControlDesigner::OnComponentRemoved(System::Object^ sender, System::ComponentModel::Design::ComponentEventArgs^ e) {
		//if (e.Component == ParentControl) {
		//   ParentControl = nullptr;
		//}
	}

   // We override PreFilterProperties so we can offer our "Control" property in windows
   // forms based designers.
	void ControlDesigner::PreFilterProperties(System::Collections::IDictionary^ properties) {
		System::ComponentModel::Design::ComponentDesigner::PreFilterProperties(properties);
		//if (pHasParentControl) {
		//	properties["ParentControl"] = System::ComponentModel::TypeDescriptor::CreateProperty(this->GetType(), "ParentControl", Control::typeid);
		//}
		properties["(Name)"] = System::ComponentModel::TypeDescriptor::CreateProperty(this->GetType(), "Name", String::typeid);
	}

}
}