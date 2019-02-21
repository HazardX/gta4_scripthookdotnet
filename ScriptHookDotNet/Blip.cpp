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

/*#include "Ped.h"
#include "Vehicle.h"
#include "Object.h"
#include "Pickup.h"
#include "MemoryAccess.h"
#include "ContentCache.h"*/

#include "Blip.h"

#include "ContentCache.h"
#include "Object.h"
#include "MemoryAccess.h"
#include "Ped.h"
#include "Pickup.h"
#include "Vehicle.h"

#pragma managed

namespace GTA{

	Blip::Blip(int Handle)
		:HandleObject(Handle) {
		//pHandle = Handle;
	}

	//int Blip::Handle::get(){
	//	return pHandle;
	//}

	int Blip::MemoryAddress::get(){
		return unmanaged::MemoryAccess::GetAddressOfBlip(pHandle);
	}

	GTA::Vector3 Blip::Position::get(){
		NON_EXISTING_CHECK(V3_NaN);
		u32 id;
		f32 x, y, z;

		//Scripting::Vector3 v;
		//Scripting::GetBlipCoords((int)pHandle,&v);
		//return Vector3(v.X,v.Y,v.Z);
		//GTA::Vector3 v = GTA::Vector3();
		//Scripting::GetBlipCoords((int)pHandle,&v);
		//return v;


		switch (Type) {
			case BlipType::Vehicle:
				id = Scripting::GetBlipInfoIdCarIndex(pHandle);
				if (!Scripting::DoesVehicleExist(id)) return Vector3();
				Scripting::GetCarCoordinates(id,&x,&y,&z);
				return GTA::Vector3(x,y,z);

			case BlipType::Ped:
				id = Scripting::GetBlipInfoIdPedIndex(pHandle);
				if (!Scripting::DoesCharExist(id)) return Vector3();
				Scripting::GetCharCoordinates(id,&x,&y,&z);
				return GTA::Vector3(x,y,z);

			case BlipType::Object:
				id = Scripting::GetBlipInfoIdObjectIndex(pHandle);
				if (!Scripting::DoesObjectExist(id)) return Vector3();
				Scripting::GetObjectCoordinates(id,&x,&y,&z);
				return GTA::Vector3(x,y,z);

			case BlipType::Coordinate:
			case BlipType::Contact: 
				if (!Scripting::DoesBlipExist(pHandle)) return Vector3();

				return unmanaged::MemoryAccess::GetPositionOfBlip(pHandle);

				//Scripting::Vector3 v;
				//Scripting::VECTOR4 v;
				//v.x=0.0f; v.y=0.0f; v.z=0.0f; v.w=0.0f;
				//Scripting::GetBlipCoords(pHandle,&v);
				//return GTA::Vector3(v.x,v.y,v.z);
				//GTA::Vector3 v = GTA::Vector3();
				//Scripting::GetBlipCoords((int)pHandle,&v);
				//return v;
				
				//Scripting::Vector3 v = NativeContext2::Invoke<Scripting::Vector3>("GET_BLIP_INFO_ID_POSITION", pHandle); //Scripting::GetBlipInfoIdPosition(pHandle);
				//Scripting::Vector3 v; // = Scripting::Vector3();
				//Scripting::Vector3 v = Scripting::GetBlipInfoIdPosition2(pHandle);
				//return GTA::Vector3(val,val,val);
				//float ary[3];
				//Scripting::GetBlipCoords(pHandle,v);
				//return GTA::Vector3(v->X,v->Y,v->Z);
				//Scripting::GetBlipInfoIdPosition(pHandle,&v);
				//return Vector3(v.X,v.Y,v.Z);
				////return GTA::Vector3(ary[0],ary[1],ary[2]);
				
				//Scripting::GetBlipCoords(pHandle,&x,&y,&z);
				//Scripting::GetBlipInfoIdPosition(pHandle,&x,&y,&z);
				//return GTA::Vector3(x,y,z);

			case BlipType::Pickup:
				id = Scripting::GetBlipInfoIdPickupIndex(pHandle);
				if (!Scripting::DoesPickupExist(id)) return Vector3();
				Scripting::GetPickupCoordinates(id,&x,&y,&z);
				return GTA::Vector3(x,y,z);
		}
		return GTA::Vector3();
	}
	void Blip::Position::set(GTA::Vector3 value){
		throw gcnew Exception("Blip position can't be set");
	}

	base::Object^ Blip::GetAttachedItem() {
		NON_EXISTING_CHECK(nullptr);
		u32 id;
		switch (Type) {
			case BlipType::Vehicle:
				id = Scripting::GetBlipInfoIdCarIndex(pHandle);
				if (!Scripting::DoesVehicleExist(id)) return nullptr;
				return ContentCache::GetVehicle(id);

			case BlipType::Ped:
				id = Scripting::GetBlipInfoIdPedIndex(pHandle);
				if (!Scripting::DoesCharExist(id)) return nullptr;
				return ContentCache::GetPed(id);

			case BlipType::Object:
				id = Scripting::GetBlipInfoIdObjectIndex(pHandle);
				if (!Scripting::DoesObjectExist(id)) return nullptr;
				return ContentCache::GetObject(id);

			case BlipType::Pickup:
				id = Scripting::GetBlipInfoIdPickupIndex(pHandle);
				if (!Scripting::DoesPickupExist(id)) return nullptr;
				return ContentCache::GetPickup(id);
		}
		return nullptr;
	}

	String^ Blip::Name::get(){
		NON_EXISTING_CHECK(String::Empty);
		return gcnew String(Scripting::GetBlipName(pHandle));
	}
	void Blip::Name::set(String^ value){
		NON_EXISTING_CHECK();
		char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
		Scripting::ChangeBlipNameFromAscii(pHandle,stringPointer);
		Marshal::FreeHGlobal(IntPtr(stringPointer));
	}

	BlipType Blip::Type::get(){
		NON_EXISTING_CHECK((BlipType)0);
		return (BlipType)Scripting::GetBlipInfoIdType(pHandle);
	}

	void Blip::Friendly::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetBlipAsFriendly(pHandle,value);
	}

	void Blip::Scale::set(float value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipScale(pHandle,value);
	}

	void Blip::Transparency::set(float value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipAlpha(pHandle,value);
	}

	bool Blip::ShowOnlyWhenNear::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsBlipShortRange(pHandle);
	}
	void Blip::ShowOnlyWhenNear::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetBlipAsShortRange(pHandle,value);
	}

	BlipIcon Blip::Icon::get(){
		NON_EXISTING_CHECK((BlipIcon)-1);
		return (BlipIcon)Scripting::GetBlipSprite(pHandle);
	}
	void Blip::Icon::set(BlipIcon value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipSprite(pHandle,(Scripting::eBlipSprite)value);
	}

	BlipColor Blip::Color::get(){
		NON_EXISTING_CHECK(BlipColor::White);
		Scripting::ColourIndex c;
		Scripting::GetBlipColour(pHandle,&c);
		return (BlipColor)c;
	}
	void Blip::Color::set(BlipColor value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipColour(pHandle,(Scripting::ColourIndex)value);
	}

	void Blip::SetColorRGB(Drawing::Color color) {
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipColour(pHandle,(Scripting::ColourIndex)color.ToArgb());
	}

	BlipDisplay Blip::Display::get(){
		NON_EXISTING_CHECK(BlipDisplay::Hidden);
		return (BlipDisplay)Scripting::GetBlipInfoIdDisplay2(pHandle);
	}
	void Blip::Display::set(BlipDisplay value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipDisplay(pHandle,(Scripting::eBlipDisplay)value);
	}

	void Blip::Priority::set(int value){
		NON_EXISTING_CHECK();
		Scripting::ChangeBlipPriority(pHandle,(Scripting::eBlipPriority)value);
	}

	void Blip::RouteActive::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetRoute(pHandle,value);
	}

	void Blip::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		try {
			Scripting::ChangeBlipDisplay(pHandle,(Scripting::eBlipDisplay)BlipDisplay::Hidden);
		} catch (...) {
		}
		try {
			unmanaged::Native::RemoveBlip(pHandle);
		} catch (...) {
		}
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Blip::InternalCheckExists() {
		if (pHandle == 0) return false;
		try {
			return Scripting::DoesBlipExist(pHandle);
		} catch (...) {
			return false;
		}
	}



	// STATIC

	Blip^ Blip::AddBlip(GTA::Pickup^ Target) {
		OBJECT_NON_EXISTING_CHECK(Target, nullptr);
		int b;
		unmanaged::Native::AddBlipForPickup(Target->Handle,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}
	Blip^ Blip::AddBlip(GTA::Object^ Target) {
		OBJECT_NON_EXISTING_CHECK(Target, nullptr);
		int b;
		unmanaged::Native::AddBlipForObject(Target->Handle,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}
	Blip^ Blip::AddBlip(GTA::Vector3 Target) {
		int b;
		unmanaged::Native::AddBlipForCoord(Target.X,Target.Y,Target.Z,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}
	Blip^ Blip::AddBlip(GTA::Vehicle^ Target) {
		OBJECT_NON_EXISTING_CHECK(Target, nullptr);
		int b;
		unmanaged::Native::AddBlipForCar(Target->Handle,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}
	Blip^ Blip::AddBlip(GTA::Ped^ Target) {
		OBJECT_NON_EXISTING_CHECK(Target, nullptr);
		int b;
		unmanaged::Native::AddBlipForChar(Target->Handle,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}
	Blip^ Blip::AddBlipContact(GTA::Vector3 Target) {
		int b;
		unmanaged::Native::AddBlipForContact(Target.X,Target.Y,Target.Z,&b);
		if (b == 0) return nullptr;
		return ContentCache::GetBlip(b, true);
	}

	array<Blip^>^ Blip::GetAllBlipsOfType(BlipType type) {
		Scripting::eBlipType t = (Scripting::eBlipType)type;
		List<Blip^>^ res = gcnew List<Blip^>();
		int b = Scripting::GetFirstBlipInfoId(t);
		while (b != 0) {
			if (Scripting::DoesBlipExist(b)) {
				res->Add(ContentCache::GetBlip(b, false));
			}
			b = Scripting::GetNextBlipInfoId(t);
		}
		return res->ToArray();
	}

	//bool Blip::operator == (Blip^ left, Blip^ right) {
	//	return (left->Handle == right->Handle);
	//}
	//bool Blip::operator != (Blip^ left, Blip^ right) {
	//	return !(left == right);
	//}

}