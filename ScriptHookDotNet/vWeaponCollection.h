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
namespace value {

	CLASS_ATTRIBUTES
	public ref class WeaponCollection sealed {

	private:
		Ped^ ped;
		Dictionary<GTA::Weapon,GTA::value::Weapon^>^ pWeaponCache;

	internal:
		WeaponCollection(Ped^ ped);

		array<int>^ GetAmmoArray();
		void SetAmmoArray(array<int>^ ammo);

	public:

		value::Weapon^ FromType(GTA::Weapon Weapon);
		value::Weapon^ inSlot(GTA::WeaponSlot WeaponSlot);

		property value::Weapon^ default[GTA::Weapon] {
			value::Weapon^ get(GTA::Weapon weapon);
		}
		property value::Weapon^ Current {
			value::Weapon^ get();
		}
		property GTA::Weapon CurrentType {
			GTA::Weapon get();
		}
		void Select(GTA::Weapon weapon);
		void RemoveAll();


		property value::Weapon^ Unarmed {
			value::Weapon^ get() { return FromType(GTA::Weapon::Unarmed); }
		}
		property value::Weapon^ BaseballBat {
			value::Weapon^ get() { return FromType(GTA::Weapon::Melee_BaseballBat); }
		}
		property value::Weapon^ Knife {
			value::Weapon^ get() { return FromType(GTA::Weapon::Melee_Knife); }
		}
		property value::Weapon^ Grenades {
			value::Weapon^ get() { return FromType(GTA::Weapon::Thrown_Grenade); }
		}
		property value::Weapon^ MolotovCocktails {
			value::Weapon^ get() { return FromType(GTA::Weapon::Thrown_Molotov); }
		}
		property value::Weapon^ Glock {
			value::Weapon^ get() { return FromType(GTA::Weapon::Handgun_Glock); }
		}
		property value::Weapon^ DesertEagle {
			value::Weapon^ get() { return FromType(GTA::Weapon::Handgun_DesertEagle); }
		}
		property value::Weapon^ BasicShotgun {
			value::Weapon^ get() { return FromType(GTA::Weapon::Shotgun_Basic); }
		}
		property value::Weapon^ BarettaShotgun {
			value::Weapon^ get() { return FromType(GTA::Weapon::Shotgun_Baretta); }
		}
		property value::Weapon^ Uzi {
			value::Weapon^ get() { return FromType(GTA::Weapon::SMG_Uzi); }
		}
		property value::Weapon^ MP5 {
			value::Weapon^ get() { return FromType(GTA::Weapon::SMG_MP5); }
		}
		property value::Weapon^ AssaultRifle_AK47 {
			value::Weapon^ get() { return FromType(GTA::Weapon::Rifle_AK47); }
		}
		property value::Weapon^ AssaultRifle_M4 {
			value::Weapon^ get() { return FromType(GTA::Weapon::Rifle_M4); }
		}
		property value::Weapon^ BasicSniperRifle {
			value::Weapon^ get() { return FromType(GTA::Weapon::SniperRifle_Basic); }
		}
		property value::Weapon^ SniperRifle_M40A1 {
			value::Weapon^ get() { return FromType(GTA::Weapon::SniperRifle_M40A1); }
		}
		property value::Weapon^ RocketLauncher {
			value::Weapon^ get() { return FromType(GTA::Weapon::Heavy_RocketLauncher); }
		}

		property value::Weapon^ AnyMelee {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Melee); }
		}
		property value::Weapon^ AnyHandgun {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Handgun); }
		}
		property value::Weapon^ AnyShotgun {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Shotgun); }
		}
		property value::Weapon^ AnySMG {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::SMG); }
		}
		property value::Weapon^ AnyAssaultRifle {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Rifle); }
		}
		property value::Weapon^ AnySniperRifle {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Sniper); }
		}
		property value::Weapon^ AnyHeavyWeapon {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Heavy); }
		}
		property value::Weapon^ AnyThrown {
			value::Weapon^ get() { return inSlot(GTA::WeaponSlot::Thrown); }
		}

		static operator GTA::Weapon (WeaponCollection^ source);
		static operator GTA::value::Weapon^ (WeaponCollection^ source);

		//static bool operator == ( WeaponCollection^ left, WeaponCollection^ right );
		//static bool operator != ( WeaponCollection^ left, WeaponCollection^ right );

		//static bool operator == ( value::Weapon^ left, WeaponCollection^ right );
		//static bool operator != ( value::Weapon^ left, WeaponCollection^ right );

		//static bool operator == ( WeaponCollection^ left, value::Weapon^ right );
		//static bool operator != ( WeaponCollection^ left, value::Weapon^ right );

		//static bool operator == ( GTA::Weapon left, WeaponCollection^ right );
		//static bool operator != ( GTA::Weapon left, WeaponCollection^ right );

		//static bool operator == ( WeaponCollection^ left, GTA::Weapon right );
		//static bool operator != ( WeaponCollection^ left, GTA::Weapon right );

	};

}
}