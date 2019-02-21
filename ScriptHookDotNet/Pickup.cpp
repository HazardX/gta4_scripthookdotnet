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

#include "Pickup.h"

#include "ContentCache.h"
#include "Blip.h"
#include "Ped.h"

#pragma managed

namespace GTA{

	Pickup::Pickup(int Handle)
		:HandleObject(Handle) {
	}

	Vector3 Pickup::Position::get(){
		NON_EXISTING_CHECK(V3_NaN);
		float x,y,z;
		Scripting::GetPickupCoordinates(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void Pickup::Position::set(Vector3 value){
		NON_EXISTING_CHECK();
		//Scripting::SetPickupCoordinates(pHandle,value.X,value.Y,value.Z);
		throw gcnew NotImplementedException("It is not possible to change a pickup position");
	}

	Room Pickup::CurrentRoom::get() {
		NON_EXISTING_CHECK(Room(0,0));
		//Scripting::eInterior ii;
		u32 rk;
		//Scripting::GetInteriorFromPickup(pHandle,&ii);
		Scripting::GetRoomKeyFromPickup(pHandle,&rk);
		return Room(force_cast<int>(rk),force_cast<int>(0));
	}
	void Pickup::CurrentRoom::set(Room value) {
		NON_EXISTING_CHECK();
		Scripting::AddPickupToInteriorRoomByKey(pHandle,force_cast<u32>(value.RoomKey));
	}

	void Pickup::CollectableByCar::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetPickupCollectableByCar(pHandle,value);
	}

	bool Pickup::HasBeenCollected::get() {
		NON_EXISTING_CHECK(false);
		return Scripting::HasPickupBeenCollected(pHandle);
	}

	void Pickup::GiveToPed(Ped^ ped) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(ped);
		Scripting::GivePedPickupObject(ped->Handle, pHandle, true);
	}

	Blip^ Pickup::AttachBlip() {
		NON_EXISTING_CHECK(nullptr);
		return Blip::AddBlip(this);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Pickup::InternalCheckExists() {
		if (pHandle == 0) return false;
		try {
			return unmanaged::Native::DoesPickupExist(pHandle);
		} catch (...) {
			return false;
		}
	}

	void Pickup::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		Scripting::RemovePickup(pHandle);
	}

	// STATIC

	GTA::Pickup^ Pickup::CreatePickup(Vector3 Position, GTA::Model Model, PickupType Type, Vector3 Rotation) {
		if (!Model.LoadToMemoryNow()) return nullptr;
		int res = 0;
		unmanaged::Native::CreatePickupRotate(Model.Hash, (int)Type, 0, Position.X, Position.Y, Position.Z, Rotation.X, Rotation.Y, Rotation.Z, &res);
		Model.AllowDisposeFromMemory();
		if (res == 0) return nullptr;
		return ContentCache::GetPickup(res);
	}
	GTA::Pickup^ Pickup::CreatePickup(Vector3 Position, GTA::Model Model, PickupType Type) {
		if (!Model.LoadToMemoryNow()) return nullptr;
		int res = 0;
		unmanaged::Native::CreatePickup(Model.Hash, (int)Type, Position.X, Position.Y, Position.Z, &res, false);
		Model.AllowDisposeFromMemory();
		if (res == 0) return nullptr;
		return ContentCache::GetPickup(res);
	}

	GTA::Pickup^ Pickup::CreateWeaponPickup(Vector3 Position, GTA::Weapon Weapon, int Ammo, Vector3 Rotation) {
		GTA::Model model = Model::GetWeaponModel(Weapon);
		if (!model.LoadToMemoryNow()) return nullptr;
		int res = 0;
		unmanaged::Native::CreatePickupRotate(model.Hash, (int)PickupType::Weapon, Ammo, Position.X, Position.Y, Position.Z, Rotation.X, Rotation.Y, Rotation.Z, &res);
		model.AllowDisposeFromMemory();
		if (res == 0) return nullptr;
		return ContentCache::GetPickup(res);
	}
	GTA::Pickup^ Pickup::CreateWeaponPickup(Vector3 Position, GTA::Weapon Weapon, int Ammo) {
		GTA::Model model = Model::GetWeaponModel(Weapon);
		if (!model.LoadToMemoryNow()) return nullptr;
		int res = 0;
		unmanaged::Native::CreatePickupWithAmmo(model.Hash, (int)PickupType::Weapon, Ammo, Position.X, Position.Y, Position.Z, &res);
		model.AllowDisposeFromMemory();
		if (res == 0) return nullptr;
		return ContentCache::GetPickup(res);
	}

	GTA::Pickup^ Pickup::CreateMoneyPickup(Vector3 Position, int MoneyAmount) {
		int res = 0;
		unmanaged::Native::CreateMoneyPickup(Position.X, Position.Y, Position.Z, MoneyAmount, true, &res);
		if (res == 0) return nullptr;
		return ContentCache::GetPickup(res);
	}

}