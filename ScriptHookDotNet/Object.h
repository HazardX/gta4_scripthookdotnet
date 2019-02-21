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
	public ref class Object sealed :
		public base::HandleObject,
		public base::iComplexObject {

	internal:
		Object(int Handle);

		property bool RecordCollisions {
			void set(bool value);
		}
		property bool Dynamic {
			void set(bool value);
		}

		virtual bool InternalCheckExists() override;

#ifdef DEBUG
	public:
#endif

		property int MemoryAddress {
			virtual int get() = base::iAddressableObject::MemoryAddress::get ;
		}

	public:

		property Vector3 Position {
			virtual Vector3 get();
			virtual void set(Vector3 value);
		}
		property Vector3 Rotation {
			Vector3 get();
			virtual void set(Vector3 value);
		}
		property Quaternion RotationQuaternion {
			Quaternion get();
			void set(Quaternion value);
		}
		property float Heading {
			virtual float get();
			virtual void set(float value);
		}
		property Vector3 Direction {
			virtual Vector3 get();
		}
		/// <summary>
		/// Gets or sets the interior room the object currently is at. It needs to be set correctly for the object to be visible inside the room.
		/// </summary>
		property Room CurrentRoom {
			virtual Room get();
			virtual void set(Room value);
		}
		property GTA::Model Model {
			virtual GTA::Model get();
		}
		property bool Visible {
			virtual void set(bool value);
		}
		property bool isOnFire {
			virtual bool get();
			virtual void set(bool value);
		}
		property bool FreezePosition {
			virtual void set(bool value);
		}
		property Vector3 Velocity {
			virtual Vector3 get();
			virtual void set(Vector3 value);
		}

		/// <summary>
		/// Applies a force given in world coordinates to the object.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction, Vector3 Rotation);
		/// <summary>
		/// Applies a force given in world coordinates to the object.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction);

		/// <summary>
		/// Applies a force that is relative to the current orientation of the object.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction, Vector3 Rotation);
		/// <summary>
		/// Applies a force that is relative to the current orientation of the object.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction);


		property bool isAttachedSomewhere {
			bool get();
		}
		
		property bool Collision {
			void set(bool value);
		}

		/// <summary>
		/// Returns the given offset in world coordinates.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		GTA::Vector3 GetOffsetPosition(GTA::Vector3 Offset);

		Blip^ AttachBlip();
		void AttachToPed(GTA::Ped^ Ped, GTA::Bone Bone, Vector3 PositionOffset, Vector3 Rotation);
		void AttachToVehicle(GTA::Vehicle^ Vehicle, Vector3 PositionOffset, Vector3 Rotation);
		virtual void Delete();
		void Detach();
		//virtual bool Exists() override;
		virtual void NoLongerNeeded();

	};

}