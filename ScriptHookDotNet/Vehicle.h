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
	[System::SerializableAttribute]
	public ref class Vehicle sealed :
		public base::HandleObject,
		public base::iComplexObject,
		public base::iMissionObject {

	private:
		[NonSerializedAttribute]
		Dictionary<GTA::VehicleDoor,GTA::value::VehicleDoor^>^ pDoorCache;

		//[NonSerializedAttribute]
		//Dictionary<GTA::VehicleWheel,GTA::value::VehicleWheel^>^ pWheelCache;

		[NonSerializedAttribute]
		Dictionary<int,GTA::value::VehicleExtra^>^ pExtraCache;

		[NonSerializedAttribute]
		static Vehicle^ pAnyVehicle = gcnew Vehicle(0);

	internal:
		Vehicle(int Handle);
		//property IntPtr Handle{ 
		//	IntPtr get();
		//}
		static property Vehicle^ AnyVehicle {
			Vehicle^ get() { return pAnyVehicle; }
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
		property float Heading {
			virtual float get();
			virtual void set(float value);
		}
		property Vector3 Direction {
			virtual Vector3 get();
		}
		/// <summary>
		/// Gets or sets the rotation of the vehicle. X is pitch, Y is roll, Z is yaw.
		/// Can be slightly off. Use RotationQuaternion if it should be perfectly accurate.
		/// </summary>
		property Vector3 Rotation {
			Vector3 get();
			void set(Vector3 value);
		}
		property Quaternion RotationQuaternion {
			Quaternion get();
			void set(Quaternion value);
		}
		/// <summary>
		/// Gets or sets the interior room the vehicle currently is at. It needs to be set correctly for the vehicle to be visible inside the room.
		/// </summary>
		property Room CurrentRoom {
			virtual Room get();
			virtual void set(Room value);
		}
		/// <summary>
		/// Returns a value between 0 and 1 that represents how far you push the RPM of the engine currently.
		/// </summary>
		property float CurrentRPM {
			float get();
		}
		property GTA::Model Model {
			virtual GTA::Model get();
		}
		property bool Visible {
			virtual void set(bool value);
		}
		property bool isOnFire{
			virtual bool get();
			virtual void set(bool value);
		}
		property bool isRequiredForMission {
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
		/// Applies a force given in world coordinates to the vehicle.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction, Vector3 Rotation);

		/// <summary>
		/// Applies a force given in world coordinates to the vehicle.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction);

		/// <summary>
		/// Applies a force that is relative to the current orientation of the vehicle.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction, Vector3 Rotation);
		/// <summary>
		/// Applies a force that is relative to the current orientation of the vehicle.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction);

		property bool AllowSirenWithoutDriver {
			void set(bool value);
		}

		property bool CanBeDamaged {
			void set(bool value);
		}
		property bool CanBeVisiblyDamaged {
			void set(bool value);
		}
		property bool CanTiresBurst {
			void set(bool value);
		}
		property float Dirtyness{
			float get();
			void set(float value);
		}
		property GTA::DoorLock DoorLock{
			GTA::DoorLock get();
			void set(GTA::DoorLock value); 
		}
		/// <summary>
		/// The current health of the car's engine. 1000 is maximum, 0 is broken, can go below 0 if burning. 
		/// </summary>
		property float EngineHealth{
			float get();
			void set(float value);
		}
		property bool EngineRunning {
			bool get();
			void set(bool value);
		}
		property bool HazardLightsOn {
			void set(bool value);
		}
		property bool InteriorLightOn {
			void set(bool value);
		}
		property int Health{
			int get();
			void set(int value);
		}
		///// <summary>
		///// Returns the height of the vehicle (from wheels to roof)
		///// </summary>
		//property float Height{
		//	float get();
		//}
		///// <summary>
		///// Returns the offset height of the vehicle (from center to roof)
		///// </summary>
		//property float HeightOffset{
		//	float get();
		//}
		property bool isDriveable{
			bool get();
		}
		property bool isOnAllWheels{
			bool get();
		}
		property bool isOnScreen{
			bool get();
		}
		property bool isAlive{
			bool get();
		}
		property bool isUpright{
			bool get();
		}
		property bool isUpsideDown{
			bool get();
		}
		property String^ Name {
			String^ get();
		}
		property bool LightsOn
		{
			bool get();
		}
		property bool NeedsToBeHotwired {
			void set(bool value);
		}
		property int PassengerSeats {
			int get();
		}
		/// <summary>
		/// The current health of the car's petrol tank. 1000 is maximum, 0 is broken, can go below 0 if burning. 
		/// </summary>
		property float PetrolTankHealth {
			float get();
			void set(float value);
		}
		property bool PreviouslyOwnedByPlayer {
			void set(bool value);
		}
		property bool SirenActive {
			bool get();
			void set(bool value);
		}
		property float Speed {
			float get();
			void set(float value);
		}
		//property float TrainSpeed {
		//	float get();
		//	void set(float value);
		//}
		

		/// <summary>
		/// Gets or sets the base color of the vehicle.
		/// </summary>
		property GTA::ColorIndex Color {
			GTA::ColorIndex get();
			void set(GTA::ColorIndex value);
		}
		/// <summary>
		/// Gets or sets the specular color of the vehicle. (for sun reflections, etc.)
		/// </summary>
		property GTA::ColorIndex SpecularColor {
			GTA::ColorIndex get();
			void set(GTA::ColorIndex value);
		}
		/// <summary>
		/// Gets or sets the color of some extra features for the vehicle. (stripes, etc.)
		/// </summary>
		property GTA::ColorIndex FeatureColor1 {
			GTA::ColorIndex get();
			void set(GTA::ColorIndex value);
		}
		/// <summary>
		/// Gets or sets the color of some extra features for the vehicle. (stripes, etc.)
		/// </summary>
		property GTA::ColorIndex FeatureColor2 {
			GTA::ColorIndex get();
			void set(GTA::ColorIndex value);
		}


		Blip^ AttachBlip();

		value::VehicleDoor^ Door(GTA::VehicleDoor door);
		value::VehicleExtra^ Extras(int ExtraID);
		
		GTA::Ped^ CreatePedOnSeat(VehicleSeat Seat);
		GTA::Ped^ CreatePedOnSeat(VehicleSeat Seat, GTA::Model model, RelationshipGroup Type);
		GTA::Ped^ CreatePedOnSeat(VehicleSeat Seat, GTA::Model model);

		//GTA::Ped^ GetPassenger(int SeatIndex);
		//GTA::Ped^ GetDriver();
		GTA::Ped^ GetPedOnSeat(VehicleSeat Seat);

		bool isSeatFree(VehicleSeat Seat);
		bool isTouching(Vehicle^ vehicle);

		VehicleSeat GetFreeSeat();
		VehicleSeat GetFreePassengerSeat();

		/// <summary>
		/// Returns the given offset in world coordinates.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		GTA::Vector3 GetOffsetPosition(GTA::Vector3 Offset);

		/// <summary>
		/// Returns the given position as directional offset using the following directions:
		/// positive X is right, positive Y is in front, positive Z is on Top 
		/// </summary>
		GTA::Vector3 GetOffset(GTA::Vector3 WorldPosition);	

		bool IsTireBurst(GTA::VehicleWheel wheel);
		void BurstTire(GTA::VehicleWheel wheel);
		void FixTire(GTA::VehicleWheel wheel);


		void CloseAllDoors();
		virtual void Delete();
		void EveryoneLeaveVehicle();
		void PassengersLeaveVehicle(bool Immediately);
		void PassengersLeaveVehicle();
		//virtual bool Exists() override;
		void Explode();
		virtual void NoLongerNeeded();
		void PlaceOnGroundProperly();
		void PlaceOnNextStreetProperly();
		void Repair();
		void MakeProofTo(bool Bullets, bool Fire, bool Explosions, bool Collisions, bool MeleeAttacks);
		void SoundHorn(int duration);
		void Wash();

		//static bool operator == ( Vehicle^ left, Vehicle^ right );
		//static bool operator != ( Vehicle^ left, Vehicle^ right );

	};

}