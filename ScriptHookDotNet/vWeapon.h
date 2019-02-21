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
	public ref class Weapon sealed {

	private:
		Ped^ pOwner;
		GTA::Weapon pID;

	internal:
		Weapon(Ped^ Owner, GTA::Weapon ID);

	public:

		property GTA::Weapon Type {
			GTA::Weapon get() {
				return pID;
			}
		}
		property GTA::WeaponSlot Slot {
			GTA::WeaponSlot get();
		}
		property bool isPresent {
			bool get();
		}

		property int Ammo {
			int get();
			void set(int value);
		}
		property int AmmoInClip {
			int get();
			void set(int value);
		}
		property int MaxAmmo {
			int get();
		}
		property int MaxAmmoInClip {
			int get();
		}

		void Select();
		void Remove();

		static operator GTA::Weapon (Weapon^ source);

		static bool operator == ( Weapon^ left, Weapon^ right );
		static bool operator != ( Weapon^ left, Weapon^ right );

		static bool operator == ( GTA::Weapon left, Weapon^ right );
		static bool operator != ( GTA::Weapon left, Weapon^ right );

		static bool operator == ( Weapon^ left, GTA::Weapon right );
		static bool operator != ( Weapon^ left, GTA::Weapon right );

	};

}
}