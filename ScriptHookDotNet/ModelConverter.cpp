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

#include "Model.h"
#include "ModelConverter.h"

using namespace System;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::ComponentModel::Design::Serialization;
using namespace System::Globalization;
using namespace System::Reflection;

namespace GTA {
	namespace Design {

	bool ModelConverter::CanConvertTo(ITypeDescriptorContext^ context, Type^ destinationType)	{
		//if( destinationType == String::typeid )
		//	return true;
		//else
		return ExpandableObjectConverter::CanConvertTo(context, destinationType);
	}

	bool ModelConverter::CanConvertFrom(ITypeDescriptorContext^ context, Type^ sourceType)	{
		if( sourceType == String::typeid )
			return true;
		else
			return ExpandableObjectConverter::CanConvertFrom(context, sourceType);
	}

	Object^ ModelConverter::ConvertTo(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value, Type^ destinationType) {
		if( destinationType == nullptr )
			throw gcnew ArgumentNullException( "destinationType" );

		if( culture == nullptr )
			culture = CultureInfo::CurrentCulture;

		//Model^ model = dynamic_cast<Model^>( value );

		//if( destinationType == String::typeid && model != nullptr )
		//{
		//	String^ separator = culture->TextInfo->ListSeparator + " ";
		//	TypeConverter^ converter = TypeDescriptor::GetConverter(float::typeid);
		//	array<String^>^ stringArray = gcnew array<String^>( 3 );

		//	stringArray[0] = converter->ConvertToString( context, culture, vector->X );
		//	stringArray[1] = converter->ConvertToString( context, culture, vector->Y );
		//	stringArray[2] = converter->ConvertToString( context, culture, vector->Z );

		//	return String::Join( separator, stringArray );
		//}

		return ExpandableObjectConverter::ConvertTo(context, culture, value, destinationType);
	}

	Object^ ModelConverter::ConvertFrom(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value) {
		if( culture == nullptr )
			culture = CultureInfo::CurrentCulture;

		String^ string = dynamic_cast<String^>( value );
		if( string != nullptr ) {
			string = string->Trim();
			return gcnew Model(string);
		}

		return ExpandableObjectConverter::ConvertFrom(context, culture, value);
	}

	bool ModelConverter::GetCreateInstanceSupported(ITypeDescriptorContext^ context)	{
		return true;
	}

	Object^ ModelConverter::CreateInstance(ITypeDescriptorContext^ context, Collections::IDictionary^ propertyValues) {
		if( propertyValues == nullptr )
			throw gcnew ArgumentNullException( "propertyValues" );
		return gcnew Model( safe_cast<String^>( propertyValues["Name"] ) );
	}
}
}