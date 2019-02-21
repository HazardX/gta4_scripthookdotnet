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

#include "Ped.h"

#include "Blip.h"
#include "ContentCache.h"
#include "Game.h"
#include "MemoryAccess.h",
#include "Object.h"
#include "Player.h"
#include "Vehicle.h"
#include "NmCommands.h"
#include "vEuphoria.h"
#include "vPedSkin.h"
#include "vPedAnimation.h"
#include "vTasks.h"
#include "vWeaponCollection.h"

#pragma managed

namespace GTA{

	// CONSTRUCTORS

	Ped::Ped(int Handle)	
		:HandleObject(Handle) {
		//pTasks = gcnew value::PedTasks(this);
	}

	void Ped::SetHandle(int Handle) {
		ContentCache::RemovePed(this);
		pHandle = Handle;
		ResetExists();
		ContentCache::AddPed(this);
	}

	//Ped::Ped(Vector3 Position)	: WorldObject(0){
	//	int ped;
	//	Scripting::CreateRandomChar(Position.X,Position.Y,Position.Z,&ped);
	//	pHandle = ped;
	//}

	//Ped::Ped(Vector3 Position, Gender gender) : WorldObject(0) {
	//	int ped;
	//	if (gender == Gender::Male) {
	//		Scripting::CreateRandomMaleChar(Position.X,Position.Y,Position.Z,&ped);
	//	} else {
	//		Scripting::CreateRandomFemaleChar(Position.X,Position.Y,Position.Z,&ped);
	//	}
	//	pHandle = ped;
	//}

	// PROPERTIES

	//IntPtr Ped::Handle::get(){
	//	return IntPtr(pHandle);
	//}

	int Ped::MemoryAddress::get(){
		return unmanaged::MemoryAccess::GetAddressOfPed(pHandle);
	}

	GTA::Model Ped::Model::get() {
		NON_EXISTING_CHECK(nullptr);
		int model = 0;
		unmanaged::Native::GetCharModel(pHandle, &model);
		return GTA::Model(model);
	}
	GTA::value::PedSkin^ Ped::Skin::get() {
		NON_EXISTING_CHECK(pSkin);
		if isNULL(pSkin) pSkin = gcnew GTA::value::PedSkin(this);
		return pSkin;
	}
	//void Ped::Skin::set(GTA::PedSkin^ value){
	//	value->ToPed(this);
	//}

	Vector3 Ped::Position::get() {
		NON_EXISTING_CHECK(V3_NaN);
		float x,y,z;
		Scripting::GetCharCoordinates(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void Ped::Position::set(Vector3 value){
		NON_EXISTING_CHECK();
		try{
		unmanaged::Native::SetCharCoordinates(pHandle,value.X,value.Y,value.Z);
		} catch(System::Exception^ ex) {
			NetHook::Log("Failed Ped mem address: " + MemoryAddress.ToString());
			throw ex;
		}
	}

	Vector3 Ped::Velocity::get() {
		NON_EXISTING_CHECK(V3_NULL);
		float x,y,z;
		Scripting::GetCharVelocity(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void Ped::Velocity::set(Vector3 value){
		NON_EXISTING_CHECK();
		Scripting::SetCharVelocity(pHandle,value.X,value.Y,value.Z);
	}

	float Ped::Heading::get(){
		NON_EXISTING_CHECK(0.0f);
		f32 val;
		Scripting::GetCharHeading(pHandle,&val);
		return val;
	}
	void Ped::Heading::set(float value){
		NON_EXISTING_CHECK();
		Scripting::SetCharHeading(pHandle,value);
	}
	Vector3 Ped::Direction::get(){
		//f32 val;
		//Scripting::GetCharHeading(pHandle,&val);
		//val = val * (float)(System::Math::PI / 180.0);
		//GTA::Vector3 res;
		//res.X = (float)-Math::Sin(val);
		//res.Y = (float)Math::Cos(val);
		//res.Z = 0.0f;
		//return res;
		return Game::HeadingToDirection(Heading);
	}

	GTA::Gender Ped::Gender::get(){
		NON_EXISTING_CHECK(GTA::Gender::Male);
		if (Scripting::IsCharMale(pHandle)) return GTA::Gender::Male;
		return GTA::Gender::Female;
	}
	//int Ped::Type::get() {
	//	Scripting::eCharType t;
	//	Scripting::GetPedType(pHandle,&t);
	//	return t;
	//}

	void Ped::Voice::set(String^ value){
		NON_EXISTING_CHECK();
		if ( isNULL(value) || (value->Length == 0) || value->Equals("default",StringComparison::InvariantCultureIgnoreCase) ) {
			SetDefaultVoice();
			return;
		}
		char* ptr = PinStringA(value);
		try {
			unmanaged::Native::SetAmbientVoiceName(pHandle,ptr);
		} finally {
			FreeString(ptr);
		}
	}

	int Ped::Health::get(){
		NON_EXISTING_CHECK(-100);
		i32 val;
		unmanaged::Native::GetCharHealth(pHandle,&val);
		return val-100;
	}
	void Ped::Health::set(int value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCharHealth(pHandle,value+100);
	}

	void Ped::MaxHealth::set(int value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCharMaxHealth(pHandle,value+100);
	}

	int Ped::Armor::get(){
		NON_EXISTING_CHECK(0);
		i32 val;
		Scripting::GetCharArmour(pHandle,&val);
		return val;
	}
	void Ped::Armor::set(int value){
		NON_EXISTING_CHECK();
		int diff = value - Armor;
		if (diff == 0) return;
		Scripting::AddArmourToChar(pHandle,diff);
	}

	int Ped::Money::get(){
		NON_EXISTING_CHECK(0);
		return Scripting::GetCharMoney(pHandle);
	}
	void Ped::Money::set(int value){
		NON_EXISTING_CHECK();
		Scripting::SetCharMoney(pHandle,value);
	}

	float Ped::HeightAboveGround::get(){
		NON_EXISTING_CHECK(0.0f);
		f32 value = 0.0f;
		Scripting::GetCharHeightAboveGround(pHandle,&value);
		return value;
	}
	bool Ped::isOnFire::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharOnFire(pHandle);
	}
	void Ped::isOnFire::set(bool value){
		NON_EXISTING_CHECK();
		if (value) {
			int fire = Scripting::StartCharFire(pHandle);
			if (fire == 0) return;
			ContentCache::GetFire(fire, true);
		} else {
			Scripting::ExtinguishCharFire(pHandle);
		}
	}

	bool Ped::isRequiredForMission::get() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedAMissionPed(pHandle);
	}
	void Ped::isRequiredForMission::set(bool value){
		NON_EXISTING_CHECK();
		if (value)
			unmanaged::Native::SetCharAsMissionChar(pHandle);
		else
			NoLongerNeeded();
	}

	bool Ped::isAlive::get(){
		NON_EXISTING_CHECK(false);
		return !isDead;
	}
	bool Ped::isAliveAndWell::get(){
		NON_EXISTING_CHECK(false);
		return ( (Exists()) && (isAlive) && (!isInjured) ); //(Health>0) &&
	}
	bool Ped::isDead::get(){
		NON_EXISTING_CHECK(true);
		return Scripting::IsCharDead(pHandle);
	}
	//bool Ped::isFatallyInjured::get(){
	//	return Scripting::IsCharFatallyInjured(pHandle);
	//}
	bool Ped::isGettingIntoAVehicle::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharGettingInToACar(pHandle);
	}
	bool Ped::isGettingUp::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharGettingUp(pHandle);
	}
	bool Ped::isIdle::get() {
		NON_EXISTING_CHECK(false);
		if (Scripting::IsCharInjured(pHandle)) return false;
		if (Scripting::IsPedRagdoll(pHandle)) return false;
		if (Scripting::IsCharInAir(pHandle)) return false;
		if (Scripting::IsCharOnFire(pHandle)) return false;
		if (Scripting::IsCharDucking(pHandle)) return false;
		if (Scripting::IsCharGesturing(pHandle)) return false;
		if (Scripting::IsCharGettingInToACar(pHandle)) return false;
		if (Scripting::IsAmbientSpeechPlaying(pHandle)) return false;
		if (Scripting::IsScriptedSpeechPlaying(pHandle)) return false;
		if (Scripting::IsCharInMeleeCombat(pHandle)) return false;
		if (Scripting::IsPedInCombat(pHandle)) return false;
		if ( (Scripting::IsCharInAnyCar(pHandle)) && (!Scripting::IsCharSittingInAnyCar(pHandle)) ) return false;
		return true;
	}
	bool Ped::isInAir::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharInAir(pHandle);
	}
	bool Ped::isInCombat::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedInCombat(pHandle);
	}
	bool Ped::isInGroup::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedInGroup(pHandle);
	}
	bool Ped::isInjured::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharInjured(pHandle);
	}
	bool Ped::isInMeleeCombat::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharInMeleeCombat(pHandle);
	}
	bool Ped::isInWater::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharInWater(pHandle);
	}
	bool Ped::isMissionCharacter::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedAMissionPed(pHandle);
	}

	bool Ped::isRagdoll::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedRagdoll(pHandle);
	}
	void Ped::isRagdoll::set(bool value) {
		NON_EXISTING_CHECK();
		if (value) {
			PreventRagdoll = false;
			unmanaged::Native::SwitchPedToRagdoll(pHandle, 10000, -1, 0, 1, 1, 0); // 10000, 10000, 0, 0, 0, 0) //10000, -1, 2, 1, 1, 0
		} else {
			unmanaged::Native::SwitchPedToAnimated(pHandle, false);
			//Scripting::UnlockRagdoll(pHandle,true);
		}
	}

	bool Ped::isOnScreen::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharOnScreen(pHandle);
	}

	bool Ped::isShooting::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharShooting(pHandle);
	}

	bool Ped::isSwimming::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharSwimming(pHandle);
	}

	void Ped::Invincible::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharInvincible(pHandle,value);
	}
	
	//bool Ped::Visible::get(){
	//	return Scripting::IsCharVisible(pHandle);
	//}
	void Ped::Visible::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharVisible(pHandle,value);
	}


	Room Ped::CurrentRoom::get(){
		NON_EXISTING_CHECK(Room(0,0));
		Scripting::Interior ii = 0;
		Scripting::eInteriorRoomKey rk;
		Scripting::GetInteriorFromChar(pHandle,&ii);
		Scripting::GetKeyForCharInRoom(pHandle,&rk);
		return Room(force_cast<int>(rk),force_cast<int>(ii));
	}
	void Ped::CurrentRoom::set(Room value) {
		NON_EXISTING_CHECK();
		Scripting::SetRoomForCharByKey( pHandle, force_cast<Scripting::eInteriorRoomKey>(value.RoomKey) );
	}

	void Ped::FreezePosition::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::FreezeCharPosition(pHandle,value);
	}

	GTA::Vehicle^ Ped::CurrentVehicle::get(){
		NON_EXISTING_CHECK(nullptr);
		int car;
		Scripting::GetCarCharIsUsing(pHandle, &car);
		if (car == 0) return nullptr;
		return ContentCache::GetVehicle(car);
	}

	Blip^ Ped::AttachBlip() {
		NON_EXISTING_CHECK(nullptr);
		return Blip::AddBlip(this);
	}

	void Ped::AttachTo(Vehicle^ vehicle, GTA::Vector3 Offset) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(vehicle);
		//float x = offset.X;
		//float y = offset.Y;
		//float z = offset.Z;
		Scripting::AttachPedToCar(pHandle, vehicle->Handle, 0, Offset.X, Offset.Y, Offset.Z, 0.0f, 0.0f, 0, 0);
	}
	void Ped::Detach() {
		NON_EXISTING_CHECK();
		Scripting::DetachPed(pHandle,true);
	}
	bool Ped::isAttachedToVehicle() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsPedAttachedToAnyCar(pHandle);
	}

	void Ped::ApplyForce(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToPed(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 0, 1, 1);
	}
	void Ped::ApplyForce(Vector3 Direction) {
		NON_EXISTING_CHECK();
		ApplyForce(Direction,Vector3());
	}

	void Ped::ApplyForceRelative(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToPed(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 1, 1, 1);
	}
	void Ped::ApplyForceRelative(Vector3 Direction) {
		NON_EXISTING_CHECK();
		ApplyForceRelative(Direction,Vector3());
	}


	//void Ped::SetInRage(bool value) {
	//	Scripting::SetPedIsBlindRaging(pHandle,value);
	//}

	void Ped::Accuracy::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharAccuracy(pHandle,value);
	}
	void Ped::AlwaysDiesOnLowHealth::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWillMoveWhenInjured(pHandle,!value);
		Scripting::SetPedDiesWhenInjured(pHandle,value);
	}
	void Ped::BlockPermanentEvents::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetBlockingOfNonTemporaryEvents(pHandle,value);
	}
	void Ped::BlockWeaponSwitching::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::BlockPedWeaponSwitching(pHandle,value);
	}
	void Ped::BlockGestures::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::BlockCharGestureAnims(pHandle,value);
	}
	void Ped::CanBeDraggedOutOfVehicle::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharCantBeDraggedOut(pHandle,!value);
	}
	void Ped::CanBeKnockedOffBike::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharCanBeKnockedOffBike(pHandle,value);
	}
	void Ped::CanSwitchWeapons::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::BlockPedWeaponSwitching(pHandle,!value);
	}
	void Ped::CowerInsteadOfFleeing::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWillCowerInsteadOfFleeing(pHandle,value);
	}
	void Ped::DuckWhenAimedAtByGroupMember::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetGroupCharDucksWhenAimedAt(pHandle,value);
	}
	//void Ped::Drunk::set(bool value) {
	//	Scripting::SetPedIsDrunk(pHandle,value);
	//}
	void Ped::Enemy::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharAsEnemy(pHandle,value);
	}
	//void Ped::IgnoreMinorShockingEvents::set(bool value) {
	//	Scripting::SetIgnoreLowPriorityShockingEvents(pHandle,value);
	//}
	//void Ped::SetDropWeaponOnDeath(bool value) {
	//	Scripting::SetCharDropsWeaponsWhenDead(pHandle,value);
	//}
	//void Ped::SetInvincible(bool value) {
	//	Scripting::SetCharInvincible(pHandle,value);
	//}
	//void Ped::SetNeverLeavesGroup(bool value) {
	//	Scripting::SetCharNeverLeavesGroup(pHandle,cbool(value));
	//}
	//void Ped::SetSuffersCriticalHits(bool value) {
	//	Scripting::SetCharSuffersCriticalHits(pHandle,value);
	//}
	void Ped::PreventRagdoll::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::UnlockRagdoll(pHandle,!value);
	}
	void Ped::PriorityTargetForEnemies::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharIsTargetPriority(pHandle,value);
	}
	void Ped::SenseRange::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetSenseRange(pHandle,value);
	}
	void Ped::WantedByPolice::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWantedByPolice(pHandle,value);
	}
	void Ped::WillDoDrivebys::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWillDoDrivebys(pHandle,value);
	}
	void Ped::WillFlyThroughWindscreen::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWillFlyThroughWindscreen(pHandle,value);
	}
	void Ped::WillUseCarsInCombat::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharWillUseCarsInCombat(pHandle,value);
	}

	GTA::PedType Ped::PedType::get() {
		NON_EXISTING_CHECK(GTA::PedType::CivMale);
		Scripting::ePedType t;
		Scripting::GetPedType(pHandle,&t);
		return (GTA::PedType)t;
	}

	GTA::RelationshipGroup Ped::RelationshipGroup::get() {
		NON_EXISTING_CHECK(GTA::RelationshipGroup::Civillian_Male);
		//Scripting::ePedType t;
		//Scripting::GetPedType(pHandle,&t);
		//return (GTA::RelationshipGroup)t;
		return (GTA::RelationshipGroup) *(int*)(MemoryAddress+0xBB4);
	}
	void Ped::RelationshipGroup::set(GTA::RelationshipGroup group) {
		NON_EXISTING_CHECK();
		//Scripting::AllowGangRelationshipsToBeChangedByNextCommand(true);
		Scripting::SetCharRelationshipGroup(pHandle,(u32)group);
	}
	void Ped::ChangeRelationship(GTA::RelationshipGroup group, Relationship level) {
		NON_EXISTING_CHECK();
		//Scripting::AllowGangRelationshipsToBeChangedByNextCommand(true);
		Scripting::SetCharRelationship(pHandle,(u32)level,(u32)group);
	}
	void Ped::CantBeDamagedByRelationshipGroup(GTA::RelationshipGroup group, bool value) {
		NON_EXISTING_CHECK();
		//Scripting::AllowGangRelationshipsToBeChangedByNextCommand(true);
		Scripting::SetCharNotDamagedByRelationshipGroup(pHandle,value,(u32)group);
	}

	void Ped::FireDamageMultiplier::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharFireDamageMultiplier(pHandle,value);
	}
	void Ped::GravityMultiplier::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetCharGravity(pHandle,value);
	}

	value::PedAnimation^ Ped::Animation::get(){
		NON_EXISTING_CHECK(pAnimation);
		if isNULL(pAnimation) pAnimation = gcnew value::PedAnimation(this);
		return pAnimation;
	}
	value::PedTasks^ Ped::Task::get(){
		//NON_EXISTING_CHECK(pTasks); // cannot be checked due to TaskSequence's use of Ped(0)
		if isNULL(pTasks) pTasks = gcnew value::PedTasks(this);
		return pTasks;
	}
	value::WeaponCollection^ Ped::Weapons::get(){
		NON_EXISTING_CHECK(pWeapons);
		if isNULL(pWeapons) pWeapons = gcnew value::WeaponCollection(this);
		return pWeapons;
	}
	value::Euphoria^ Ped::Euphoria::get(){
		NON_EXISTING_CHECK(pEuphoria);
		if isNULL(pEuphoria) pEuphoria = gcnew value::Euphoria(this);
		return pEuphoria;
	}
	//value::Weapon^ Ped::Weapon() {
	//	Scripting::eWeapon w;
	//	Scripting::GetCurrentCharWeapon(pHandle,&w);
	//	return Weapon((GTA::Weapon)w);
	//}
	//value::Weapon^ Ped::Weapon(GTA::Weapon weapon) {
	//	GTA::value::Weapon^ w;
	//	if isNULL(pWeaponCache) {
	//		pWeaponCache = gcnew Dictionary<GTA::Weapon,GTA::value::Weapon^>();
	//	} else {
	//		if (pWeaponCache->TryGetValue(weapon, w)) return w;
	//	}
	//	w = gcnew GTA::value::Weapon(this, weapon);
	//	pWeaponCache->Add(weapon, w);
	//	return w;
	//}

	bool Ped::HasBeenDamagedBy(GTA::Weapon weapon) {
		NON_EXISTING_CHECK(false);
		return Scripting::HasCharBeenDamagedByWeapon(pHandle, (Scripting::eWeapon)weapon);
	}
	bool Ped::HasBeenDamagedBy(Vehicle^ vehicle) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::HasCharBeenDamagedByCar(pHandle, vehicle->Handle);
	}
	bool Ped::HasBeenDamagedBy(Ped^ ped) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(ped,false);
		return Scripting::HasCharBeenDamagedByChar(pHandle, ped->Handle, false);
	}

	bool Ped::isInVehicle(Vehicle^ vehicle) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCharInCar(pHandle, vehicle->Handle);
	}
	bool Ped::isInVehicle() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharInAnyCar(pHandle); //IsCharInAnyCar
	}

	bool Ped::isSittingInVehicle(Vehicle^ vehicle) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCharSittingInCar(pHandle, vehicle->Handle);
	}
	bool Ped::isSittingInVehicle() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsCharSittingInAnyCar(pHandle); //IsCharInAnyCar
	}

	//bool Ped::isEnteringOrLeavingVehicle(Vehicle^ vehicle) {
	//	if (!Scripting::IsCharInCar(pHandle, vehicle->Handle)) return false;
	//	return !Scripting::IsCharSittingInCar(pHandle, vehicle->Handle);
	//}
	//bool Ped::isEnteringOrLeavingVehicle() {
	//	if (!Scripting::IsCharInAnyCar(pHandle)) return false;
	//	return !Scripting::IsCharSittingInAnyCar(pHandle);
	//}

	bool Ped::isTouching(GTA::Object^ object) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(object,false);
		return Scripting::IsCharTouchingObject(pHandle,object->Handle);
	}
	bool Ped::isTouching(Vehicle^ vehicle) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCharTouchingVehicle(pHandle,vehicle->Handle);
	}
	bool Ped::isTouching(Ped^ ped) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(ped,false);
		return Scripting::IsCharTouchingChar(pHandle,ped->Handle);
	}

	bool Ped::isInArea(Vector3 Corner1, Vector3 Corner2, bool IgnoreHeight) {
		NON_EXISTING_CHECK(false);
		if (IgnoreHeight)
			return Scripting::IsCharInArea2D(pHandle, Corner1.X, Corner1.Y, Corner2.X, Corner2.Y, false);
		else
			return Scripting::IsCharInArea3D(pHandle, Corner1.X, Corner1.Y, Corner1.Z, Corner2.X, Corner2.Y, Corner2.Z, false);
	}

	GTA::Vector3 Ped::GetBonePosition(GTA::Bone Bone) {
		NON_EXISTING_CHECK(V3_NaN);
		//f32 a,b,c;
		Scripting::Vector3 res;
		Scripting::GetPedBonePosition(pHandle,(u32)Bone,0.0f,0.0f,0.0f,&res);
		return GTA::Vector3(res.X,res.Y,res.Z);
		//float x = 0.0f;
		//float y = 0.0f;
		//float z = 0.0f;
		//Scripting::pVector3 res;
		//res.X = &x;
		//res.Y = &y;
		//res.Z = &z;
		//Scripting::GetPedBonePosition(pHandle,(u32)Bone,0.0f,0.0f,0.0f,&res);
		//return GTA::Vector3(*res.X,*res.Y,*res.Z);
	}

	GTA::Vector3 Ped::GetOffsetPosition(GTA::Vector3 Offset) {
		NON_EXISTING_CHECK(V3_NULL);
		float x = 0.0f; float y = 0.0f; float z = 0.0f;
		Scripting::GetOffsetFromCharInWorldCoords(pHandle, Offset.X, Offset.Y, Offset.Z, &x, &y, &z);
		return GTA::Vector3(x,y,z);
	}

	void Ped::SetPathfinding(bool AllowClimbovers, bool AllowLadders, bool AllowDropFromHeight) {
		NON_EXISTING_CHECK();
		Scripting::SetPedPathMayUseClimbovers(pHandle,AllowClimbovers);
		Scripting::SetPedPathMayUseLadders(pHandle,AllowLadders);
		Scripting::SetPedPathMayDropFromHeight(pHandle,AllowDropFromHeight);
	}

	// METHODS

	void Ped::GiveFakeNetworkName(System::String^ Name, System::Drawing::Color Color) {
		NON_EXISTING_CHECK();
		char* stringPointer = (char*)Marshal::StringToHGlobalAnsi(Name).ToPointer();
		Scripting::GivePedFakeNetworkName(pHandle, stringPointer, Color.R, Color.G, Color.B, Color.A);
		Marshal::FreeHGlobal(IntPtr(stringPointer));
	}

	void Ped::RemoveFakeNetworkName() {
		NON_EXISTING_CHECK();
		Scripting::RemoveFakeNetworkNameFromPed(pHandle);
	}

	void Ped::FleeByVehicle(GTA::Vehicle^ Vehicle) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(Vehicle);
		Scripting::ForcePedToFleeWhilstDrivingVehicle(pHandle,Vehicle->Handle);
	}

	void Ped::ShootAt(Vector3 Position) {
		NON_EXISTING_CHECK();
		Scripting::FirePedWeapon(pHandle, Position.X, Position.Y, Position.Z);
	}
	void Ped::ForceHelmet(bool enable) {
		NON_EXISTING_CHECK();
		if (enable) {
			Scripting::GivePedHelmet(pHandle);
		} else {
			Scripting::RemovePedHelmet(pHandle,true);
		}
	}
	void Ped::ForceRagdoll(int duration, bool TryToStayUpright) {
		NON_EXISTING_CHECK();
		PreventRagdoll = false;
		unmanaged::Native::SwitchPedToRagdoll(pHandle, 10000, duration, (TryToStayUpright ? 2 : 0), 1, 1, 0); 
		//Behavior:
		// 0 = Plain ragdoll, no movement
		// 1 = Stiff NULL position / NM Control
		// 2 = Try to stand
	}
	void Ped::SetDefensiveArea(Vector3 Position, float Radius) {
		NON_EXISTING_CHECK();
		Scripting::SetCharSphereDefensiveArea(pHandle, Position.X, Position.Y, Position.Z, Radius);
	}
	void Ped::MakeProofTo(bool Bullets, bool Fire, bool Explosions, bool FallingDamage, bool MeleeAttacks) {
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCharProofs(pHandle, Bullets, Fire, Explosions, FallingDamage, MeleeAttacks);
	}

	void Ped::WarpIntoVehicle(GTA::Vehicle^ Vehicle, VehicleSeat Seat) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(Vehicle);
		if (Seat <= VehicleSeat::None) return;
		if (Seat == VehicleSeat::Driver) {
			Scripting::WarpCharIntoCar(pHandle,Vehicle->Handle);
		} else {
			if (isInVehicle(Vehicle))
				Scripting::WarpCharFromCarToCar(pHandle,Vehicle->Handle,(int)Seat); // change seat
			else
				Scripting::WarpCharIntoCarAsPassenger(pHandle,Vehicle->Handle,(int)Seat);
		}
	}

	void Ped::DropCurrentWeapon() {
		NON_EXISTING_CHECK();
		Scripting::ForceCharToDropWeapon(pHandle);
	}
	void Ped::LeaveGroup() {
		NON_EXISTING_CHECK();
		unmanaged::Native::RemoveCharFromGroup(pHandle);
	}
	void Ped::LeaveVehicle() {
		NON_EXISTING_CHECK();
		Scripting::TaskLeaveAnyCar(pHandle);
	}
	void Ped::RandomizeOutfit() {
		NON_EXISTING_CHECK();
		Scripting::SetCharRandomComponentVariation(pHandle);
	}
	//void Ped::SwitchToRagdoll() {
	//	Scripting::SwitchPedToRagdoll(pHandle, 10000, 10000, 0, 0, 0, 0);
	//}
	void Ped::BecomeMissionCharacter() {
		NON_EXISTING_CHECK();
		Scripting::SetCharAsMissionChar(pHandle);
	}

	void Ped::CancelAmbientSpeech() {
		NON_EXISTING_CHECK();
		unmanaged::Native::CancelCurrentlyPlayingAmbientSpeech(pHandle);
	}

	void Ped::SayAmbientSpeech(String^ PhraseID) {
		NON_EXISTING_CHECK();
		CancelAmbientSpeech();
		char* ptr = PinStringA(PhraseID);
		Scripting::SayAmbientSpeech(pHandle,ptr,1,1,0);
		FreeString(ptr);
	}
	// Generic_Fuck_Off, Intimidate_Resp, Thanks, SELL_GOODS

	void Ped::StartKillingSpree(bool alsoAttackPlayer) {
		NON_EXISTING_CHECK();
		//GTA::RelationshipGroup grp = GTA::RelationshipGroup::Civillian_Male; // GTA::RelationshipGroup::Criminal
		//RelationshipGroup = grp;
		//ChangeRelationship(grp, GTA::Relationship::Like);

		int i = 1;
		if (alsoAttackPlayer) i = 0;
		for (; i <= 22; i++) {
			//if (i != (int)grp) 
			ChangeRelationship((GTA::RelationshipGroup)i, GTA::Relationship::Hate);
		}
		//BlockPermanentEvents = true;
		AlwaysDiesOnLowHealth = true;
		//CowerInsteadOfFleeing = true;
		//WantedByPolice = true;
		if (isInVehicle()) {
		   WillUseCarsInCombat = true;
         WillDoDrivebys = true;
		}

		//Weapon weap = Weapons->CurrentType;

		//TaskSequence^ ts = gcnew TaskSequence();
		//ts->AddTask->SwapWeapon(weap);
		//ts->AddTask->AimAt(Position,5000);
  //    ts->AddTask->FightAgainstHatedTargets(100.0F,65000);

		Task->ClearAll();
      Task->AlwaysKeepTask = true;
		//Task->PerformSequence(ts);
		//Task->SwapWeapon(weap);
		//Task->AimAt(Position,5000);
		Task->FightAgainstHatedTargets(20.0F);
		//BlockPermanentEvents = false;
	}


	//void Ped::WalkAwayAndDespawn() {
	//	Scripting::RemoveCharElegantly(pHandle);
	//}
	void Ped::NoLongerNeeded() {
		NON_EXISTING_CHECK_RELAXED();
		Scripting::Ped p = pHandle;
		unmanaged::Native::MarkCharAsNoLongerNeeded(&p);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Ped::InternalCheckExists() {
		if (pHandle == 0) return false;
		try {
			return unmanaged::Native::DoesCharExist(pHandle);
		} catch (...) {
			return false;
		}
	}
	void Ped::Die() {
		NON_EXISTING_CHECK();
		//Scripting::TaskDie(pHandle);
		Health = -100;
	}
	void Ped::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		int ped = pHandle;
		unmanaged::Native::DeleteChar(&ped);
		//pHandle = 0;
	}

	void Ped::SetDefaultVoice() {
		NON_EXISTING_CHECK();
		unmanaged::Native::SetVoiceIdFromHeadComponent(pHandle, false, Scripting::IsCharMale(pHandle));
	}

	Player^ Ped::GetControllingPlayer() {
		NON_EXISTING_CHECK(nullptr);
		array<Player^>^ pl = Game::PlayerList;
		for (int i = 0; i < pl->Length; i++) {
			if (this == pl[i]->Character) return pl[i];
		}
		return nullptr;
	}

	Ped::operator Ped^ (Player^ source) {
		return source->Character;
	}
	//Ped::operator Scripting::Ped (Ped^ source) {
	//	Scripting::Ped p;
	//	p.Handle = source->Handle;
	//	return p;
	//}

}