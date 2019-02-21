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

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Globalization;

namespace Design {

	[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
	public ref class ControlDesigner : public System::ComponentModel::Design::ComponentDesigner {

	private:

		void OnDesignerLoadCompleteInternal(System::Object^ sender, EventArgs^ e);
		void OnDesignerActivatedInternal(System::Object^ sender, EventArgs^ e);
		void OnDesignerDeactivatedInternal(System::Object^ sender, EventArgs^ e);
		void OnComponentRemoved(System::Object^ sender, System::ComponentModel::Design::ComponentEventArgs^ e);
		
	internal:

		property System::ComponentModel::Design::IComponentChangeService^ ComponentChangeService {
         System::ComponentModel::Design::IComponentChangeService^ get();
		}
		property System::ComponentModel::Design::IDesignerHost^ DesignerHost {
          System::ComponentModel::Design::IDesignerHost^ get();
		}
		property System::ComponentModel::Design::Serialization::IDesignerSerializationService^ DesignerSerializationService {
			System::ComponentModel::Design::Serialization::IDesignerSerializationService^ get();
		}
		property System::ComponentModel::Design::IMenuCommandService^ MenuCommandService {
          System::ComponentModel::Design::IMenuCommandService^ get();
		}
		property System::ComponentModel::Design::ISelectionService^ SelectionService {
          System::ComponentModel::Design::ISelectionService^ get();
		}
		property System::Drawing::Design::IToolboxService^ ToolboxService {
          System::Drawing::Design::IToolboxService^ get();
		}

		property GTA::Forms::Control^ Control {
          GTA::Forms::Control^ get();
		}

	protected:

		!ControlDesigner();

		[System::ComponentModel::DisplayName("(Name)")]
		[System::ComponentModel::Browsable(true)]
		[System::ComponentModel::DesignOnly(true)]
		[System::ComponentModel::DesignerSerializationVisibility(System::ComponentModel::DesignerSerializationVisibility::Hidden)]
      property String^ Name {
			String^ get() {
            return Component->Site->Name;
			}
			void set(String^ value) {
            Component->Site->Name = value;
			}
		}

		property bool AutoAddToolboxItem {
			virtual bool get() { return true; }
		}
		property String^ FullTypeName {
			virtual String^ get() { return Component->GetType()->FullName; }
		}
		property String^ ToolboxIconName {
			virtual String^ get() { return FullTypeName+".bmp"; }
		}

		virtual void OnDesignerLoadComplete(DesignerHostEventArgs^ e);
		virtual void OnDesignerActivated(DesignerHostEventArgs^ e);
		virtual void OnDesignerDeactivated(DesignerHostEventArgs^ e);

		virtual void PreFilterProperties(System::Collections::IDictionary^ properties) override;

	public:
		ControlDesigner() {}
		~ControlDesigner() { this->!ControlDesigner(); }

		virtual void Initialize(System::ComponentModel::IComponent^ component) override;

	};

}
}