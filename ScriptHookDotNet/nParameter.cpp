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

#include "nParameter.h"

#include "NativeContext2.h"
#include "Blip.h"
#include "Camera.h"
#include "ContentCache.h"
#include "Group.h"
#include "Object.h"
#include "Ped.h"
#include "Pickup.h"
#include "Player.h"
#include "Vehicle.h"

#pragma managed


namespace GTA {
namespace Native{

	// CLASS PARAMETER

	//protected:

		Parameter::Parameter() {
			pType = vtype::var_void;
		}

		vtype Parameter::GetType(System::Type^ type) {
			if (type == int::typeid)
				return vtype::var_int;
			else if (type == float::typeid)
				return vtype::var_float;
			else if (type == bool::typeid)
				return vtype::var_bool;
			else if (type == String::typeid)
				return vtype::var_string;
			else if (type == GTA::Ped::typeid)
				return vtype::var_ped;
			else if (type == GTA::Vehicle::typeid)
				return vtype::var_vehicle;
			else if (type == GTA::Model::typeid)
				return vtype::var_model;
			else if (type == GTA::Player::typeid)
				return vtype::var_player;
			else if (type == GTA::Group::typeid)
				return vtype::var_group;
			else if (type == GTA::Object::typeid)
				return vtype::var_object;
			else if (type == GTA::Pickup::typeid)
				return vtype::var_pickup;
			else if (type == GTA::Blip::typeid)
				return vtype::var_blip;
			else if (type == GTA::Camera::typeid)
				return vtype::var_camera;
			else if (type == GTA::Vector3::typeid)
				return vtype::var_vector3;

			else if (type == Parameter::typeid)
				return vtype::xvar_parameter;
			else if (type == Pointer::typeid)
				return vtype::xvar_pointer;

			else
				return vtype::var_void;
		}



	//internal:

		Parameter::Parameter(System::Type^ type) {
			SetType(type);
		}
		Parameter::Parameter(vtype type, int data) {
			pType = type;
			pData = data;
		}
		Parameter::Parameter(vtype type, u8* data, int len) {
			pType = type;
			setDataB(data,len);
		}
		Parameter::~Parameter() {
			freeDataB();
		}

		void Parameter::setDataB(u8* data, int len) {
			setDataBLen(len);
			memcpy(pDataB,data,len);
		}

		int Parameter::getDataBLen(vtype type) {
			switch (type) {
				case vtype::var_vector3:
					return 12;
			}
			return 0;
		}

		void Parameter::setDataBLen(int length) {
			freeDataB();
			if (length<=0) return;
			pDataB = (u8*)malloc(length);
			if (pDataB == NULL) throw gcnew OutOfMemoryException();
			pDataBLen = length;
			for (int i = 0; i<length; i++) {
				pDataB[i] = 0x00;
			}
		}

		void Parameter::freeDataB() {
			if (pDataB != NULL) free(pDataB);
			pDataBLen = 0;
		}

		bool Parameter::isPointer::get() {
			return false;
		}
		void Parameter::Push(Scripting::NativeContext2* cxt) {
			pIndex = cxt->ArgCount();
			if (pDataB == NULL)
				cxt->Push(pData);
			else
				cxt->Push(pDataB, pDataBLen);
		}

		void Parameter::SetType(System::Type^ type) {
			freeDataB();
			pType = GetType(type);
			int datlen = getDataBLen(pType);
			if (datlen>0) setDataBLen(datlen);
		}


	//public:

		Parameter::Parameter(int value) {
			SetValue(value);
		}
		Parameter::Parameter(float value) {
			SetValue(value);
		}
		Parameter::Parameter(bool value) {
			SetValue(value);
		}
		Parameter::Parameter(String^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Ped^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Vehicle^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Model value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Player^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Group^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Object^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Pickup^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Blip^ value) {
			SetValue(value);
		}
		Parameter::Parameter(GTA::Camera^ value) {
			SetValue(value);
		}
		Parameter::Parameter(Parameter^ value) {
			SetValue(value);
		}
		Parameter::Parameter(Object^ value) {
			SetValue(value);
		}
		//Parameter(System::Type^ type) {
		//	SetType(type);
		//}

		void Parameter::SetValue(int value) {
			pData = value;
			pType = vtype::var_int;
		}
		void Parameter::SetValue(float value) {
			pData = force_cast<int>(value); //*reinterpret_cast<int*>(&value);
			pType = vtype::var_float;
		}
		void Parameter::SetValue(bool value) {
			pData = (value ? 1 : 0);
			pType = vtype::var_bool;
		}
		void Parameter::SetValue(String^ value) {
			pData = reinterpret_cast<int>(Function::GetStringPointer(value));
			pType = vtype::var_string;
		}
		void Parameter::SetValue(GTA::Ped^ value) {
			pData = value->Handle;
			pType = vtype::var_ped;
		}
		void Parameter::SetValue(GTA::Vehicle^ value) {
			pData = value->Handle;
			pType = vtype::var_vehicle;
		}
		void Parameter::SetValue(GTA::Model value) {
			pData = value.Hash;
			pType = vtype::var_model;
		}
		void Parameter::SetValue(GTA::Player^ value) {
			pData = value->Index;
			pType = vtype::var_player;
		}
		void Parameter::SetValue(GTA::Group^ value) {
			pData = value->Handle;
			pType = vtype::var_group;
		}
		void Parameter::SetValue(GTA::Object^ value) {
			pData = value->Handle;
			pType = vtype::var_object;
		}
		void Parameter::SetValue(GTA::Pickup^ value) {
			pData = value->Handle;
			pType = vtype::var_pickup;
		}
		void Parameter::SetValue(GTA::Blip^ value) {
			pData = value->Handle;
			pType = vtype::var_blip;
		}
		void Parameter::SetValue(GTA::Camera^ value) {
			pData = value->Handle;
			pType = vtype::var_camera;
		}
		void Parameter::SetValue(GTA::Vector3 value) {
			Scripting::Vector3 v;
			v.X=value.X; v.Y=value.Y; v.Z=value.Z;
			setDataB<Scripting::Vector3>(v);
			pType = vtype::var_vector3;
		}
		void Parameter::SetValue(Parameter^ value) {
			pData = value->pData;
			pType = value->pType;
		}

		void Parameter::SetValue(System::Object^ value) {
			if (System::Object::ReferenceEquals(value, nullptr)) {
				pType = vtype::var_void;
				pData = 0;
				return;
			}
			switch (GetType(value->GetType())) {
				case vtype::var_int:
					SetValue(safe_cast<int>(value));
					break;
				case vtype::var_float:
					SetValue(safe_cast<float>(value));
					break;
				case vtype::var_bool:
					SetValue(safe_cast<bool>(value));
					break;
				case vtype::var_string:
					SetValue(safe_cast<String^>(value));
					break;
				case vtype::var_ped:
					SetValue(safe_cast<GTA::Ped^>(value));
					break;
				case vtype::var_vehicle:
					SetValue(safe_cast<GTA::Vehicle^>(value));
					break;
				case vtype::var_model:
					SetValue(safe_cast<GTA::Model>(value));
					break;
				case vtype::var_player:
					SetValue(safe_cast<GTA::Player^>(value));
					break;
				case vtype::var_group:
					SetValue(safe_cast<GTA::Group^>(value));
					break;
				case vtype::var_object:
					SetValue(safe_cast<GTA::Object^>(value));
					break;
				case vtype::var_pickup:
					SetValue(safe_cast<GTA::Pickup^>(value));
					break;
				case vtype::var_blip:
					SetValue(safe_cast<GTA::Blip^>(value));
					break;
				case vtype::var_camera:
					SetValue(safe_cast<GTA::Camera^>(value));
					break;
				case vtype::var_vector3:
					SetValue(safe_cast<GTA::Vector3>(value));
					break;

				case vtype::xvar_parameter:
					SetValue( (safe_cast<Parameter^>(value))->Value );
					break;
				case vtype::xvar_pointer:
					SetValue( (safe_cast<Pointer^>(value))->Value );
					break;
						
				default:
					pType = vtype::var_void;
					pData = 0;
					throw gcnew InvalidCastException( String::Concat( "Invalid cast from ", value->GetType()->FullName, " to Native.Parameter" ) );
			}
		}

		System::Object^ Parameter::Value::get() {
				int val;
				switch (pType) {
					case vtype::var_int:
						return pData;
					case vtype::var_float:
						val = pData;
						return *reinterpret_cast<float*>(&val);
					case vtype::var_bool:
						return (pData!=0);
					case vtype::var_string:
						if (pData==0) return String::Empty;
						return gcnew String(reinterpret_cast<char*>(pData));
					case vtype::var_ped:
						if (pData==0) return nullptr;
						return ContentCache::GetPed(pData);
					case vtype::var_vehicle:
						if (pData==0) return nullptr;
						return ContentCache::GetVehicle(pData);
					case vtype::var_model:
						return GTA::Model(pData);
					case vtype::var_player:
						//return gcnew GTA::Player(pData); // can't load from index, need id
						return nullptr;
					case vtype::var_group:
						if (pData==0) return nullptr;
						return ContentCache::GetGroup(pData, false);
					case vtype::var_object:
						if (pData==0) return nullptr;
						return ContentCache::GetObject(pData);
					case vtype::var_pickup:
						if (pData==0) return nullptr;
						return ContentCache::GetPickup(pData);
					case vtype::var_blip:
						if (pData==0) return nullptr;
						return ContentCache::GetBlip(pData, false);
					case vtype::var_camera:
						if (pData==0) return nullptr;
						return ContentCache::GetCamera(pData, false);
					case vtype::var_vector3:
						if (pDataB==NULL) return GTA::Vector3();
						Scripting::Vector3 v = getDataB<Scripting::Vector3>();
						return GTA::Vector3(v.X,v.Y,v.Z);
				}
				return nullptr;
		}
		void Parameter::Value::set(System::Object^ value) {
				SetValue(value);
		}

		Parameter::operator Parameter^ (int source) {
			//return gcnew Parameter(source);
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (float source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (double source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue((float)source);
			return p;
		}
		Parameter::operator Parameter^ (bool source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (String^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Ped^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Vehicle^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Model source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		//Parameter::operator Parameter^ (GTA::Model^ source) {
		//	Parameter^ p = gcnew Parameter();
		//	p->SetValue(*source);
		//	return p;
		//}
		Parameter::operator Parameter^ (GTA::Player^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Group^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Object^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Pickup^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Blip^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		Parameter::operator Parameter^ (GTA::Camera^ source) {
			Parameter^ p = gcnew Parameter();
			p->SetValue(source);
			return p;
		}
		//Parameter::operator Parameter^ (System::Object^ source) {
		//	Parameter^ p = gcnew Parameter();
		//	p->SetValue(source);
		//	return p;
		//}
		//static operator Parameter^ (System::Type^ type) {
		//	Parameter^ p = gcnew Parameter();
		//	p->SetType(type);
		//	return p;
		//}

		String^ Parameter::ToString() {
			Object^ o = Value;
			if (o == nullptr) return String::Empty;
			return o->ToString();
		}


	// CLASS POINTER

	//internal:

		//template <typename T>
		//Pointer(T value) {
		//	SetValue(value);
		//}

		bool Pointer::isPointer::get() {
			return true;
		}
		void Pointer::Push(Scripting::NativeContext2* cxt) {
			pIndex = cxt->ArgCount();
			if (pDataB == NULL)
				cxt->PushPtr(pData);
			else
				cxt->PushPtr(pDataB, pDataBLen);
		}
		void Pointer::AfterExec(Scripting::NativeContext2* cxt) {
			if (pDataB == NULL)
				pData = cxt->GetArgumentPtr<int>(pIndex);
			else
				cxt->GetArgumentPtr(pIndex, pDataB, pDataBLen);
		}

	//public:

		Pointer::Pointer(System::Type^ type) {
			SetType(type);
		}
	
		Pointer::operator Pointer^ (int source) {
			//return gcnew Pointer(source);
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (float source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (double source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue((float)source);
			return p;
		}
		Pointer::operator Pointer^ (bool source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (String^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Ped^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Vehicle^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Model source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Player^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Group^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Object^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Pickup^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Blip^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Camera^ source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		Pointer::operator Pointer^ (GTA::Vector3 source) {
			Pointer^ p = gcnew Pointer();
			p->SetValue(source);
			return p;
		}
		//Pointer::operator Pointer^ (Object^ source) {
		//	Pointer^ p = gcnew Pointer();
		//	p->SetValue(source);
		//	return p;
		//}
		Pointer::operator Pointer^ (System::Type^ type) {
			Pointer^ p = gcnew Pointer();
			p->SetType(type);
			return p;
		}

		Pointer::operator int (Pointer^ source) {
			if (source->pType == vtype::var_int)   return (int)source->Value;
			if (source->pType == vtype::var_float) return (int)(float)source->Value;
			if (source->pType == vtype::var_bool)  return ( ((bool)source->Value) ? 1 : 0);
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to integer");
			return 0;
		}
		Pointer::operator float (Pointer^ source) {
			if (source->pType == vtype::var_float) return (float)source->Value;
			if (source->pType == vtype::var_int)   return (float)(int)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to float");
			return 0.0f;
		}
		Pointer::operator double (Pointer^ source) {
			if (source->pType == vtype::var_float) return (double)(float)source->Value;
			if (source->pType == vtype::var_int)   return (double)(int)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to float");
			return 0.0;
		}
		Pointer::operator bool (Pointer^ source) {
			if (source->pType == vtype::var_bool) return (bool)source->Value;
			if (source->pType == vtype::var_int)  return ( ((int)source->Value) != 0);
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to bool");
			return 0;
		}
		Pointer::operator String^ (Pointer^ source) {
			Object^ o = source->Value;
			if (o == nullptr) return String::Empty;
			return o->ToString();
		}
		Pointer::operator GTA::Ped^ (Pointer^ source) {
			if (source->pType == vtype::var_ped) return (GTA::Ped^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Ped");
			return nullptr;
		}
		Pointer::operator GTA::Vehicle^ (Pointer^ source) {
			if (source->pType == vtype::var_vehicle) return (GTA::Vehicle^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Vehicle");
			return nullptr;
		}
		Pointer::operator GTA::Model (Pointer^ source) {
			if (source->pType == vtype::var_model) return (GTA::Model)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Model");
			return nullptr;
		}
		Pointer::operator GTA::Group^ (Pointer^ source) {
			if (source->pType == vtype::var_group) return (GTA::Group^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Group");
			return nullptr;
		}
		Pointer::operator GTA::Object^ (Pointer^ source) {
			if (source->pType == vtype::var_object) return (GTA::Object^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Object");
			return nullptr;
		}
		Pointer::operator GTA::Pickup^ (Pointer^ source) {
			if (source->pType == vtype::var_pickup) return (GTA::Pickup^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Pickup");
			return nullptr;
		}
		Pointer::operator GTA::Blip^ (Pointer^ source) {
			if (source->pType == vtype::var_blip) return (GTA::Blip^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Blip");
			return nullptr;
		}
		Pointer::operator GTA::Camera^ (Pointer^ source) {
			if (source->pType == vtype::var_camera) return (GTA::Camera^)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Camera");
			return nullptr;
		}
		Pointer::operator GTA::Vector3 (Pointer^ source) {
			if (source->pType == vtype::var_vector3) return (GTA::Vector3)source->Value;
			throw gcnew InvalidCastException("Invalid cast from Native.Pointer of type "+GetTypeName(source->pType)+" to Vector3");
			return Vector3();
		}

		Parameter^ Pointer::ToInputParameter() {
			if (pDataB != NULL) throw gcnew InvalidOperationException("The Native.Pointer of type "+GetTypeName(pType)+" cannot be converted into a Native.Parameter");
			return gcnew Parameter(pType,pData);
		}

}
}