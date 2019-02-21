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

#include "vWeaponCollection.h"

#include "Ped.h"
#include "vWeapon.h"

#pragma managed

namespace GTA {
namespace value {

	WeaponCollection::WeaponCollection(Ped^ ped) {
		this->ped = ped;
	}

	value::Weapon^ WeaponCollection::default::get(GTA::Weapon weapon) {
		return FromType(weapon);
	}

	array<int>^ WeaponCollection::GetAmmoArray() {
		OBJECT_NON_EXISTING_CHECK(ped,gcnew array<int>(0));
		array<int>^ ammo = gcnew array<int>(19);
		u32 amount;
		ammo[0] = 0;
		for (int i = 1; i < 19; i++) {
			if (Scripting::HasCharGotWeapon(ped->Handle,i)) {
				amount = 0;
				if (i > 3) Scripting::GetAmmoInCharWeapon(ped->Handle,i,&amount);
				ammo[i] = (int)amount;
			} else {
				ammo[i] = -1;
			}
		}
		return ammo;
	}
	void WeaponCollection::SetAmmoArray(array<int>^ ammo) {
		if ( isNULL(ammo) || (ammo->Length < 19) ) return;
		OBJECT_NON_EXISTING_CHECK(ped);
		for (int i = 1; i < 19; i++) {
			if (ammo[i] >= 0)	Scripting::GiveWeaponToChar(ped->Handle,i,ammo[i],0);
		}
	}


	value::Weapon^ WeaponCollection::Current::get() {
		return FromType(CurrentType);
	}
	GTA::Weapon WeaponCollection::CurrentType::get() {
		OBJECT_NON_EXISTING_CHECK(ped,GTA::Weapon::None);
		Scripting::eWeapon w;
		Scripting::GetCurrentCharWeapon(ped->Handle,&w);
		return (GTA::Weapon)w;
	}

	value::Weapon^ WeaponCollection::FromType(GTA::Weapon weapon) {
		GTA::value::Weapon^ w;
		if isNULL(pWeaponCache) {
			pWeaponCache = gcnew Dictionary<GTA::Weapon,GTA::value::Weapon^>();
		} else {
			if (pWeaponCache->TryGetValue(weapon, w)) return w;
		}
		w = gcnew GTA::value::Weapon(ped, weapon);
		pWeaponCache->Add(weapon, w);
		return w;
	}
	value::Weapon^ WeaponCollection::inSlot(GTA::WeaponSlot WeaponSlot) {
		if (WeaponSlot == GTA::WeaponSlot::Unarmed) return Unarmed;
		OBJECT_NON_EXISTING_CHECK(ped,Unarmed);
		Scripting::eWeapon w;
		Scripting::ScriptAny p4, p5;
		Scripting::GetCharWeaponInSlot(ped->Handle, (Scripting::eWeaponSlot)WeaponSlot, &w, &p4, &p5);
		if (int(w) <= 0) return FromType(GTA::Weapon::None);
		return FromType((GTA::Weapon)w);
	}

	void WeaponCollection::Select(GTA::Weapon weapon) {
		FromType(weapon)->Select();
	}
	void WeaponCollection::RemoveAll() {
		OBJECT_NON_EXISTING_CHECK(ped);
		Scripting::RemoveAllCharWeapons(ped->Handle);
	}
	

	// CONVERSION
	WeaponCollection::operator GTA::Weapon (WeaponCollection^ source) {
		OBJECT_NON_EXISTING_CHECK(source->ped,GTA::Weapon::None);
		Scripting::eWeapon w;
		Scripting::GetCurrentCharWeapon(source->ped->Handle,&w);
		return (GTA::Weapon)w;
	}
	WeaponCollection::operator GTA::value::Weapon^ (WeaponCollection^ source) {
		return source->Current;
	}

	//// COMPARE: WeaponCollection
	//bool WeaponCollection::operator == (WeaponCollection^ left, WeaponCollection^ right) {
	//	if isNULL(left) return isNULL(right);
	//	if isNULL(right) return false;
	//	return (left->CurrentType == right->CurrentType);
	//}
	//bool WeaponCollection::operator != (WeaponCollection^ left, WeaponCollection^ right) {
	//	return !(left == right);
	//}

	//// COMPARE: value::Weapon
	//bool WeaponCollection::operator == (value::Weapon^ left, WeaponCollection^ right) {
	//	if isNULL(right) return ( isNULL(left) || (left->Type == GTA::Weapon::Unarmed) );
	//	if isNULL(left) return (right->CurrentType == GTA::Weapon::Unarmed);
	//	return (left->Type == right->CurrentType);
	//}
	//bool WeaponCollection::operator != (value::Weapon^ left, WeaponCollection^ right) {
	//	return !(left == right);
	//}

	//bool WeaponCollection::operator == (WeaponCollection^ left, value::Weapon^ right) {
	//	return (right == left);
	//}
	//bool WeaponCollection::operator != (WeaponCollection^ left, value::Weapon^ right) {
	//	return !(left == right);
	//}

	//// COMPARE: GTA::Weapon
	//bool WeaponCollection::operator == (GTA::Weapon left, WeaponCollection^ right) {
	//	if isNULL(right) return (left == GTA::Weapon::Unarmed);
	//	return (left == right->CurrentType);
	//}
	//bool WeaponCollection::operator != (GTA::Weapon left, WeaponCollection^ right) {
	//	return !(left == right);
	//}

	//bool WeaponCollection::operator == (WeaponCollection^ left, GTA::Weapon right) {
	//	if isNULL(left) return (right == GTA::Weapon::Unarmed);
	//	return (right == left->CurrentType);
	//}
	//bool WeaponCollection::operator != (WeaponCollection^ left, GTA::Weapon right) {
	//	return !(left == right);
	//}

}
}