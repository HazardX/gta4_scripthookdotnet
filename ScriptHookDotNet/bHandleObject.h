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
namespace base {

	CLASS_ATTRIBUTES
	[System::SerializableAttribute]
	public ref class HandleObject abstract :
		base::Object,
		base::iHandleObject,
		System::IEquatable<HandleObject^> {

	protected:
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		int pHandle;

	internal:

		HandleObject(int Handle) {
			pHandle = Handle;
		}

		property int Handle { 
			virtual int get() = base::iHandleObject::Handle::get {
				return pHandle;
			}
		}

	private:

		[System::NonSerializedAttribute]
		System::Object^ pMetadata;

	public:

		/// <summary>
		/// Allows you to store Metadata on an object. Metadata can be read back as long as the object exists. 
		/// Usage: object.Metadata.MyValueName = MyData
		/// </summary>
		/// <param name="ValueName">Name of the stored Metadata.</param>
		[System::Runtime::CompilerServices::Dynamic]
		property System::Object^ Metadata {
			virtual System::Object^ get();
		}

		
		/// <summary>
		/// Read only explicit local OR global Metadata from the object.
		/// </summary>
		/// <param name="ValueName">Name of the stored Metadata.</param>
		/// <param name="Global">Global Metadata is accessible by all scripts.</param>
		generic<typename T>
		[Obsolete("Use this instead: result = object.Metadata.Global.MyValueName")]
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		T GetMetadata(System::String^ ValueName, bool Global);

		
		/// <summary>
		/// Read Metadata from the object. The Metadata may be local or global. Local Metadtata has preference.
		/// </summary>
		/// <param name="ValueName">Name of the stored Metadata.</param>
		generic<typename T>
		[Obsolete("Use this instead: result = object.Metadata.MyValueName")]
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		T GetMetadata(System::String^ ValueName);

		/// <summary>
		/// Checks if explicit local OR global Metadata exists on the object.
		/// </summary>
		/// <param name="ValueName">Name of the stored Metadata.</param>
		/// <param name="Global">Global Metadata is accessible by all scripts.</param>
		[Obsolete("Use this instead: result = object.Metadata.Global.Contains(\"MyValueName\")")]
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		bool HasMetadata(System::String^ ValueName, bool Global);

		/// <summary>
		/// Checks if Metadata exists on the object. The Metadata may be local or global. Local Metadtata has preference.
		/// </summary>
		/// <param name="ValueName">Name of the stored Metadata.</param>
		[Obsolete("Use this instead: result = object.Metadata.Contains(\"MyValueName\")")]
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		bool HasMetadata(System::String^ ValueName);

		/// <summary>
		/// Store Metadata for the object. Metadata can be read back as long as the object exists.
		/// </summary>
		/// <param name="ValueName">Name of the Metadata to store.</param>
		/// <param name="Global">Global Metadata is accessible by all scripts.</param>
		/// <param name="Value">Value of the Metadata to store.</param>
		generic<typename T>
		[Obsolete("Use this instead: object.Metadata.MyValueName = MyData")]
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		void SetMetadata(System::String^ ValueName, bool Global, T Value);

		virtual bool Equals(base::HandleObject^ obj) {
			if (Object::ReferenceEquals(obj,nullptr)) return false;
			return (pHandle == obj->Handle);
		}
		virtual bool Equals(base::iHandleObject^ obj) {
			if (Object::ReferenceEquals(obj,nullptr)) return false;
			return (pHandle == obj->Handle);
		}
		static bool operator == ( HandleObject^ left, HandleObject^ right ) {
			if (Object::ReferenceEquals(left,nullptr)) return Object::ReferenceEquals(right,nullptr);
			return left->Equals(right);
		}
		static bool operator != ( HandleObject^ left, HandleObject^ right ) {
			return !(left == right);
		}

		virtual int GetHashCode() override {
			return pHandle;
		}

	};

}
}