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

#include "vWeapon.h"

#include "Ped.h"

#pragma managed

namespace GTA {
namespace value {

	Weapon::Weapon(Ped^ Owner, GTA::Weapon ID) {
		pOwner = Owner;
		pID = ID;
	}

	GTA::WeaponSlot Weapon::Slot::get() {
		if (pID <= GTA::Weapon::Unarmed) return GTA::WeaponSlot::Unarmed;
		i32 slot = 0;
		Scripting::GetWeaponTypeSlot((i32)pID,&slot);
		return (GTA::WeaponSlot)slot;
	}
	bool Weapon::isPresent::get() {
		if (pID == GTA::Weapon::None) return false;
		if (pID == GTA::Weapon::Unarmed) return true;
		OBJECT_NON_EXISTING_CHECK(pOwner,false);
		return (Scripting::HasCharGotWeapon(pOwner->Handle,(Scripting::eWeapon)pID));
	}

	int Weapon::Ammo::get() {
		if (pID == GTA::Weapon::None) return 0;
		if (pID == GTA::Weapon::Unarmed) return 1;
		OBJECT_NON_EXISTING_CHECK(pOwner,0);
		if (isPresent) {
			u32 ammo = 0;
			Scripting::GetAmmoInCharWeapon(pOwner->Handle,(Scripting::eWeapon)pID,&ammo);
			return ammo;
		} else {
			return 0;
		}
	}
	void Weapon::Ammo::set(int value) {
		if (pID <= GTA::Weapon::Unarmed) return;
		OBJECT_NON_EXISTING_CHECK(pOwner);
		if (isPresent) {
			Scripting::SetCharAmmo(pOwner->Handle,(Scripting::eWeapon)pID,value);
		} else {
			Scripting::GiveWeaponToChar(pOwner->Handle,(Scripting::eWeapon)pID,value,0);
		}
	}
	int Weapon::AmmoInClip::get() {
		if (pID == GTA::Weapon::None) return 0;
		if (pID == GTA::Weapon::Unarmed) return 1;
		OBJECT_NON_EXISTING_CHECK(pOwner,0);
		if (Scripting::HasCharGotWeapon(pOwner->Handle,(Scripting::eWeapon)pID)){
			u32 ammo = 0;
			Scripting::GetAmmoInClip(pOwner->Handle,(Scripting::eWeapon)pID,&ammo);
			return ammo;
		} else {
			return 0;
		}
	}
	void Weapon::AmmoInClip::set(int value) {
		if (pID <= GTA::Weapon::Unarmed) return;
		OBJECT_NON_EXISTING_CHECK(pOwner);
		if (!unmanaged::Native::HasCharGotWeapon(pOwner->Handle,(Scripting::eWeapon)pID)){
			Scripting::GiveWeaponToChar(pOwner->Handle,(Scripting::eWeapon)pID,1,0);
		}
		Scripting::SetAmmoInClip(pOwner->Handle,(Scripting::eWeapon)pID,value);
	}
	int Weapon::MaxAmmo::get() {
		if (pID == GTA::Weapon::None) return 0;
		if (pID == GTA::Weapon::Unarmed) return 1;
		OBJECT_NON_EXISTING_CHECK(pOwner,0);
		u32 ammo = 0;
		Scripting::GetMaxAmmo(pOwner->Handle,(Scripting::eWeapon)pID,&ammo);
		return ammo;
	}
	int Weapon::MaxAmmoInClip::get() {
		if (pID == GTA::Weapon::None) return 0;
		if (pID == GTA::Weapon::Unarmed) return 1;
		OBJECT_NON_EXISTING_CHECK(pOwner,0);
		u32 ammo = 0;
		Scripting::GetMaxAmmoInClip(pOwner->Handle,(Scripting::eWeapon)pID,&ammo);
		return ammo;
	}

	void Weapon::Select() {
		if (pID == GTA::Weapon::None) return;
		OBJECT_NON_EXISTING_CHECK(pOwner);
		Scripting::eWeapon w = (Scripting::eWeapon)pID;
		if (!Scripting::HasCharGotWeapon(pOwner->Handle,w)) {
			Scripting::GiveWeaponToChar(pOwner->Handle,w,1,0);
		}
		unmanaged::Native::SetCurrentCharWeapon(pOwner->Handle,w,true);
	}
	void Weapon::Remove() {
		if (pID <= GTA::Weapon::Unarmed) return;
		OBJECT_NON_EXISTING_CHECK(pOwner);
		Scripting::RemoveWeaponFromChar(pOwner->Handle,(Scripting::eWeapon)pID);
	}


	Weapon::operator GTA::Weapon (Weapon^ source) {
		return source->pID;
	}

	bool Weapon::operator == (Weapon^ left, Weapon^ right) {
		if isNULL(left) return isNULL(right);
		if isNULL(right) return false;
		return (left->pID == right->pID);
	}
	bool Weapon::operator != (Weapon^ left, Weapon^ right) {
		return !(left == right);
	}

	bool Weapon::operator == (GTA::Weapon left, Weapon^ right) {
		if isNULL(right) return (left == GTA::Weapon::Unarmed);
		return (left == right->pID);
	}
	bool Weapon::operator != (GTA::Weapon left, Weapon^ right) {
		return !(left == right);
	}

	bool Weapon::operator == (Weapon^ left, GTA::Weapon right) {
		if isNULL(left) return (right == GTA::Weapon::Unarmed);
		return (right == left->pID);
	}
	bool Weapon::operator != (Weapon^ left, GTA::Weapon right) {
		return !(left == right);
	}

}
}