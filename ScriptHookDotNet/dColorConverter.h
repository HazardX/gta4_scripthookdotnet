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
using namespace System::ComponentModel;
using namespace System::ComponentModel::Design;
using namespace System::ComponentModel::Design::Serialization;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Globalization;

namespace Design {

	[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
	public ref class ColorConverter : public TypeConverter {

		private:
			static bool bInit = false;
			//static Dictionary<String^, MethodInfo^>^ Methods;
			//static List<String^>^ MethodNames;
			static TypeConverter::StandardValuesCollection^ stdval;

			//static void GetStaticMethods(Type^ enumType, Type^ returnType);

		public:
			ColorConverter();
			
			virtual bool CanConvertFrom(ITypeDescriptorContext^ context, Type^ sourceType) override;
			virtual bool CanConvertTo(ITypeDescriptorContext^ context, Type^ destinationType) override;

			virtual Object^ ConvertFrom(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value) override;
			virtual Object^ ConvertTo(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value, Type^ destinationType) override;
			
			virtual StandardValuesCollection^ GetStandardValues(ITypeDescriptorContext^ context) override;
			virtual bool GetStandardValuesSupported(ITypeDescriptorContext^ context) override;
			virtual bool GetStandardValuesExclusive(ITypeDescriptorContext^ context) override;

	};

}
}
