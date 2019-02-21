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
	public ref class Ped sealed :
		public base::HandleObject,
		public base::iComplexObject,
		public base::iMissionObject {

	private:
		[NonSerializedAttribute]
		value::PedAnimation^ pAnimation;

		[NonSerializedAttribute]
		value::PedSkin^ pSkin;

		[NonSerializedAttribute]
		value::PedTasks^ pTasks;

		[NonSerializedAttribute]
		value::WeaponCollection^ pWeapons;

		[NonSerializedAttribute]
		value::Euphoria^ pEuphoria;
		//Dictionary<GTA::Weapon,GTA::value::Weapon^>^ pWeaponCache;

	internal:
		Ped(int Handle);

		void SetHandle(int Handle);
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
		/// Gets or sets the interior room the ped currently is at. It needs to be set correctly for the ped to be visible inside the room.
		/// </summary>
		property Room CurrentRoom {
			virtual Room get();
			virtual void set(Room value);
		}
		property GTA::Model Model {
			virtual GTA::Model get();
		}
		property bool Visible {
			//bool get();
			virtual void set(bool value);
		}
		property bool isOnFire {
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
		/// Applies a force given in world coordinates to the ped.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction, Vector3 Rotation);
		/// <summary>
		/// Applies a force given in world coordinates to the ped.
		/// </summary>
		virtual void ApplyForce(Vector3 Direction);

		/// <summary>
		/// Applies a force that is relative to the current orientation of the ped.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction, Vector3 Rotation);
		/// <summary>
		/// Applies a force that is relative to the current orientation of the ped.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		virtual void ApplyForceRelative(Vector3 Direction);
		
		property GTA::Gender Gender {
			GTA::Gender get();
		}
		//property int Type {
		//	int get();
		//}
		property String^ Voice {
			void set(String^ value);
		}

		property GTA::value::PedSkin^ Skin {
			GTA::value::PedSkin^ get();
			//void set(GTA::PedSkin^ value);
		}
		
		/// <summary>
		/// Gets or sets the current health of the ped. 1 to 100 is the normal range. 
		/// Can be greater than 100 for Peds with incresed MaxHealth.
		/// -99 to 0 is injured. -100 is completely dead.
		/// </summary>
		property int Health {
			int get();
			void set(int value);
		}
		/// <summary>
		/// Gets or sets the maximum health for NPCs. Default is 100.
		/// </summary>
		property int MaxHealth {
			void set(int value);
		}
		/// <summary>
		/// Gets or sets the current health of the ped. 0 to 100 is the normal range.
		/// </summary>
		property int Armor{
			int get();
			void set(int value);
		}
		property int Money {
			int get();
			void set(int value);
		}

		property float HeightAboveGround {
			float get();
		}
		property bool isAlive {
			bool get();
		}
		property bool isAliveAndWell {
			bool get();
		}
		property bool isDead {
			bool get();
		}
		//property bool isFatallyInjured {
		//	bool get();
		//}
		property bool isGettingIntoAVehicle {
			bool get();
		}
		property bool isGettingUp {
			bool get();
		}

		/// <summary>
		/// Gets whether the ped is currently available for idle animations. Has some overhead, don't call it every frame.
		/// </summary>
		property bool isIdle {
			bool get();
		}
		property bool isInAir {
			bool get();
		}
		property bool isInCombat {
			bool get();
		}
		property bool isInGroup {
			bool get();
		}
		property bool isInjured {
			bool get();
		}
		property bool isInMeleeCombat {
			bool get();
		}
		property bool isInWater {
			bool get();
		}
		[Obsolete("Please use the property isRequiredForMission instead!")]
		property bool isMissionCharacter {
			bool get();
		}
		property bool isOnScreen {
			bool get();
		}
		property bool isRagdoll { 
			bool get();
			void set(bool value);
		}
		property bool isShooting {
			bool get();
		}
		property bool isSwimming {
			bool get();
		}
		
	

		/// <summary>
		/// Tasks control the behaviour of peds.
		/// </summary>
		property value::PedTasks^ Task {
			value::PedTasks^ get();
		}
		/// <summary>
		/// Provides control over ped animations.
		/// </summary>
		property value::PedAnimation^ Animation {
			value::PedAnimation^ get();
		}
		/// <summary>
		/// Contains several classes to access weapon functionality.
		/// </summary>
		property value::WeaponCollection^ Weapons {
			value::WeaponCollection^ get();
		}
		/// <summary>
		/// Provides some easy to use Euphoria/NaturalMotion objects.
		/// </summary>
		property value::Euphoria^ Euphoria {
			value::Euphoria^ get();
		}


		/// <summary>
		/// Gets the currently used vehicle of the ped. Returns Nothing when no vehicle is used.
		/// </summary>
		property GTA::Vehicle^ CurrentVehicle { 
			GTA::Vehicle^ get();
		}

		property int Accuracy { 
			void set(int value);
		}
		property bool AlwaysDiesOnLowHealth { 
			void set(bool value);
		}

		/// <summary>
		/// Sets whether permanent events - like responding to an aggressor - that may abort currently assigned tasks should be blocked.
		/// </summary>
		property bool BlockPermanentEvents { 
			void set(bool value);
		}

		property bool BlockWeaponSwitching { 
			void set(bool value);
		}
		property bool BlockGestures { 
			void set(bool value);
		}
		property bool CanBeDraggedOutOfVehicle { 
			void set(bool value);
		}
		property bool CanBeKnockedOffBike { 
			void set(bool value);
		}
		property bool CanSwitchWeapons { 
			void set(bool value);
		}
		property bool CowerInsteadOfFleeing { 
			void set(bool value);
		}
		property bool DuckWhenAimedAtByGroupMember { 
			void set(bool value);
		}
		//property bool Drunk { 
		//	void set(bool value);
		//}

		/// <summary>
		/// Sets whether the ped should be considered an enemy of the player.
		/// </summary>
		property bool Enemy { 
			void set(bool value);
		}
		property float FireDamageMultiplier { 
			void set(float value);
		}
		property float GravityMultiplier { 
			void set(float value);
		}
		//property bool IgnoreMinorShockingEvents { 
		//	void set(bool value);
		//}
		property bool Invincible { 
			void set(bool value);
		}
		property bool PreventRagdoll { 
			void set(bool value);
		}
		property bool PriorityTargetForEnemies { 
			void set(bool value);
		}
		property float SenseRange { 
			void set(float value);
		}
		property bool WantedByPolice { 
			void set(bool value);
		}
		property bool WillDoDrivebys { 
			void set(bool value);
		}
		property bool WillFlyThroughWindscreen { 
			void set(bool value);
		}
		property bool WillUseCarsInCombat { 
			void set(bool value);
		}

		property GTA::PedType PedType { 
			GTA::PedType get();
		}

		property GTA::RelationshipGroup RelationshipGroup { 
			GTA::RelationshipGroup get();
			void set(GTA::RelationshipGroup value);
		}
		void ChangeRelationship(GTA::RelationshipGroup group, Relationship level);
		void CantBeDamagedByRelationshipGroup(GTA::RelationshipGroup group, bool value);
		
		Blip^ AttachBlip();

		/// <summary>
		/// Attaches the ped to a vehicle WITHOUT physics!
		/// </summary>
		void AttachTo(Vehicle^ vehicle, GTA::Vector3 Offset);
		void Detach();
		bool isAttachedToVehicle();

		bool HasBeenDamagedBy(GTA::Weapon weapon);
		bool HasBeenDamagedBy(Vehicle^ vehicle);
		bool HasBeenDamagedBy(Ped^ ped);

		bool isInVehicle(Vehicle^ vehicle);
		bool isInVehicle();
		bool isSittingInVehicle(Vehicle^ vehicle);
		bool isSittingInVehicle();
		//bool isEnteringOrLeavingVehicle(Vehicle^ vehicle);
		//bool isEnteringOrLeavingVehicle();

		bool isTouching(GTA::Object^ object);
		bool isTouching(Vehicle^ vehicle);
		bool isTouching(Ped^ ped);

		bool isInArea(Vector3 Corner1, Vector3 Corner2, bool IgnoreHeight);

		GTA::Vector3 GetBonePosition(GTA::Bone Bone);

		/// <summary>
		/// Returns the given offset in world coordinates.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		GTA::Vector3 GetOffsetPosition(GTA::Vector3 Offset);

		void SetPathfinding(bool AllowClimbovers, bool AllowLadders, bool AllowDropFromHeight);
		void SetDefaultVoice();

		void GiveFakeNetworkName(System::String^ Name, System::Drawing::Color Color);
		void RemoveFakeNetworkName();

		void FleeByVehicle(GTA::Vehicle^ Vehicle);
		void ForceHelmet(bool enable);
		void ForceRagdoll(int Duration, bool TryToStayUpright);
		void SetDefensiveArea(Vector3 Position, float Radius);
		void MakeProofTo(bool Bullets, bool Fire, bool Explosions, bool FallingDamage, bool MeleeAttacks);
		void ShootAt(Vector3 Position);
		void WarpIntoVehicle(GTA::Vehicle^ Vehicle, VehicleSeat Seat); 

		void DropCurrentWeapon();
		void LeaveGroup();
		void LeaveVehicle();
		void RandomizeOutfit();
		//void SwitchToRagdoll();
		void BecomeMissionCharacter();

		void CancelAmbientSpeech();
		void SayAmbientSpeech(String^ PhraseID);
		void StartKillingSpree(bool alsoAttackPlayer);

		//void WalkAwayAndDespawn();
		virtual void NoLongerNeeded();
		//virtual bool Exists() override;
		void Die();
		virtual void Delete();

		Player^ GetControllingPlayer();

		static operator Ped^ (Player^ source);
		//static operator Scripting::Ped (Ped^ source);

		//public:
		////internal:

		//int GetPropIndex(PedProp proptype) {
		//	u32 index;
		//	Scripting::GetCharPropIndex2(pHandle, (u32)proptype, &index);
		//	return index;
		//}
		//void SetPropIndex(PedProp proptype, int index) {
		//	Scripting::SetCharPropIndex(pHandle, (u32)proptype, index);
		//}

		//int GetComponentModel(PedComponent component) {
		//	return Scripting::GetCharDrawableVariation(pHandle, (Scripting::ePedComponent)component);
		//}
		//void SetComponentModel(PedComponent component, int model) {
		//	//u32 texture = Scripting::GetCharTextureVariation(pHandle, (Scripting::ePedComponent)component);
		//	Scripting::SetCharComponentVariation(pHandle, (u32)component, model, 0); // changing model resets texture
		//}

		//int GetComponentTexture(PedComponent component) {
		//	return Scripting::GetCharTextureVariation(pHandle, (Scripting::ePedComponent)component);
		//}
		//void SetComponentTexture(PedComponent component, int texture) {
		//	u32 model = Scripting::GetCharDrawableVariation(pHandle, (Scripting::ePedComponent)component);
		//	Scripting::SetCharComponentVariation(pHandle, (u32)component, model, texture);
		//}

	};

}