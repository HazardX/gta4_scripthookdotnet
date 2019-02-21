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

namespace GTA{

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class Pickup sealed :
		public base::HandleObject,
		public base::iPositioned,
		public base::iInteriorObject,
		public base::iDeletable {

	internal:
		Pickup(int Handle);

		virtual bool InternalCheckExists() override;

	public:

		property Vector3 Position {
			virtual Vector3 get();
			private: virtual void set(Vector3 value) sealed = base::iPositioned::Position::set;
		}
		/// <summary>
		/// Gets or sets the interior room the pickup currently is at. It needs to be set correctly for the pickup to be visible inside the room.
		/// </summary>
		property Room CurrentRoom {
			virtual Room get();
			virtual void set(Room value);
		}

		property bool CollectableByCar {
			void set(bool value);
		}

		property bool HasBeenCollected {
			bool get();
		}

		void GiveToPed(Ped^ ped);

		Blip^ AttachBlip();

		//virtual bool Exists() override;

		virtual void Delete();

		static GTA::Pickup^ CreatePickup(Vector3 Position, GTA::Model Model, PickupType Type, Vector3 Rotation);
		static GTA::Pickup^ CreatePickup(Vector3 Position, GTA::Model Model, PickupType Type);
		static GTA::Pickup^ CreateWeaponPickup(Vector3 Position, GTA::Weapon Weapon, int Ammo, Vector3 Rotation);
		static GTA::Pickup^ CreateWeaponPickup(Vector3 Position, GTA::Weapon Weapon, int Ammo);
		static GTA::Pickup^ CreateMoneyPickup(Vector3 Position, int MoneyAmount);

	};

}