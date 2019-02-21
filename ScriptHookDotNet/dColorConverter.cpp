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
#include "dColorConverter.h"

#include "sColorIndex.h"

#pragma managed

namespace GTA {
namespace Design {

		//private:

			//void ColorConverter::GetStaticMethods(Type^ enumType, Type^ returnType) {
			//	MethodAttributes attributes = (MethodAttributes::Static | MethodAttributes::Public);
			//	for each (PropertyInfo^ info in enumType->GetProperties()) {
			//		if (info->PropertyType == returnType) {
			//			MethodInfo^ getMethod = info->GetGetMethod();
			//			if ((getMethod != nullptr) && ((getMethod->Attributes & attributes) == attributes)) {
			//				MethodNames->Add(info->Name);
			//				Methods->Add(info->Name, getMethod);
			//				//array<Object^>^ index = nullptr;
			//				//hash[info->Name] = info->GetValue(nullptr, index);
			//			}
			//		}
			//	}
			//}


		//public:
			ColorConverter::ColorConverter() {
				//MethodNames = gcnew List<String^>();
				//Methods = gcnew Dictionary<String^, MethodInfo^>();
				//GetStaticMethods(GTA::Color::typeid, GTA::Color::typeid);
				//stdval = gcnew TypeConverter::StandardValuesCollection(MethodNames->ToArray());
				stdval = gcnew TypeConverter::StandardValuesCollection(ColorIndex::colnamary);
				bInit = true;
				//System::Windows::Forms::MessageBox::Show( String::Concat( MethodNames->Count, " Methods found!" ) );
			}
			
			bool ColorConverter::CanConvertFrom(ITypeDescriptorContext^ context, Type^ sourceType) {
				if (sourceType == String::typeid) return true;
				//if (sourceType == MethodInfo::typeid) return true;
				return TypeConverter::CanConvertFrom(context,sourceType);
			}
			bool ColorConverter::CanConvertTo(ITypeDescriptorContext^ context, Type^ destinationType) {
				if (destinationType == InstanceDescriptor::typeid) return true;
				if (destinationType == String::typeid) return true;
				return TypeConverter::CanConvertTo(context,destinationType);
			}

			Object^ ColorConverter::ConvertFrom(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value) {
				if ((!Object::ReferenceEquals(value,nullptr)) && (value->GetType() == String::typeid)) {
					String^ name = (String^)value; //static_cast<String^>(value)
					//if (Methods->ContainsKey(name)) {
					//	MethodInfo^ val = Methods->default[name];
					//	Object^ res = val->Invoke(nullptr,nullptr);
					//	if ((res != nullptr) && (res->GetType() == GTA::Color::typeid)) return res;
					//}
					return ColorIndex::FromKnownName(name);
				}

				//if (value->GetType() == MethodInfo::typeid) {
				//	MethodInfo^ val = static_cast<MethodInfo^>(value);
				//	Object^ res = val->Invoke(nullptr,nullptr);
				//	if ((res != nullptr) && (res->GetType() == GTA::Color::typeid)) return res;
				//}

				return TypeConverter::ConvertFrom(context,culture,value);
			}

			Object^ ColorConverter::ConvertTo(ITypeDescriptorContext^ context, CultureInfo^ culture, Object^ value, Type^ destinationType) {
				if ((!Object::ReferenceEquals(value,nullptr)) && (value->GetType() == GTA::ColorIndex::typeid)) {
					if (destinationType == InstanceDescriptor::typeid) {
						GTA::ColorIndex c = (GTA::ColorIndex)value;
						PropertyInfo^ pi = GTA::ColorIndex::typeid->GetProperty(c.Name);
						if (pi != nullptr) {
							return gcnew InstanceDescriptor(pi, nullptr);
						}

						// fallback if no method was found
						ConstructorInfo^ ctor = GTA::ColorIndex::typeid->GetConstructor(gcnew array<Type^>{int::typeid});
						if (ctor != nullptr) 
							return gcnew InstanceDescriptor(ctor, gcnew array<Object^>{c.Index});

					} else if (destinationType == String::typeid) {
						GTA::ColorIndex c = (GTA::ColorIndex)value;
						return c.Name;
					}
				}
				return TypeConverter::ConvertTo(context, culture, value, destinationType);      
			}


			TypeConverter::StandardValuesCollection^ ColorConverter::GetStandardValues(ITypeDescriptorContext^ context) {
				return stdval;
			}
			bool ColorConverter::GetStandardValuesSupported(ITypeDescriptorContext^ context) {
				return true;
			}
			bool ColorConverter::GetStandardValuesExclusive(ITypeDescriptorContext^ context) {
				return true;
			}
}
}
