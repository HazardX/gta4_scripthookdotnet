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

#include "Vehicle.h"

#include "Blip.h"
#include "ContentCache.h"
#include "Game.h"
#include "MemoryAccess.h"
#include "Ped.h"
#include "vTasks.h"
#include "vVehicleDoor.h"
#include "vVehicleExtra.h"

#pragma managed

namespace GTA{

	Vehicle::Vehicle(int Handle)
		:HandleObject(Handle){
		//pHandle = Handle;
	}

	//GetDisplayNameFromVehicleModel

	//IntPtr Vehicle::Handle::get(){
	//	return IntPtr(pHandle);
	//}

	int Vehicle::MemoryAddress::get(){
		return unmanaged::MemoryAccess::GetAddressOfVehicle(pHandle);
	}
	Vector3 Vehicle::Position::get(){
		NON_EXISTING_CHECK(V3_NaN);
		//float x,y,z;
		//unmanaged::Native::GetCarCoordinates(pHandle,&x,&y,&z);
		//return Vector3(x,y,z);
		return unmanaged::MemoryAccess::GetPositionOfVehicle(pHandle);
	}
	void Vehicle::Position::set(Vector3 value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCarCoordinates(pHandle,value.X,value.Y,value.Z);
	}

	float Vehicle::Heading::get(){
		NON_EXISTING_CHECK(0.0f);
		f32 val;
		Scripting::GetCarHeading(pHandle,&val);
		return val;
	}
	void Vehicle::Heading::set(float value){
		NON_EXISTING_CHECK();
		Scripting::SetCarHeading(pHandle,value);
	}
	Vector3 Vehicle::Direction::get(){
		return Game::HeadingToDirection(Heading);
	}

	Vector3 Vehicle::Rotation::get(){
		return RotationQuaternion.ToRotation();
	}
	void Vehicle::Rotation::set(Vector3 value){
		NON_EXISTING_CHECK();
		RotationQuaternion = Quaternion::FromRotation(value);
	}

	Quaternion Vehicle::RotationQuaternion::get(){
		NON_EXISTING_CHECK(Quaternion());
		float x,y,z,w;
		Scripting::GetVehicleQuaternion(pHandle,&x,&y,&z,&w);
		return Quaternion(x,y,z,w);
	}
	void Vehicle::RotationQuaternion::set(Quaternion value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetVehicleQuaternion(pHandle,value.X,value.Y,value.Z,value.W);
	}

	Room Vehicle::CurrentRoom::get(){
		NON_EXISTING_CHECK(Room(0,0));
		Scripting::Interior ii = 0;
		u32 rk = 0;
		Scripting::GetInteriorFromCar(pHandle,&ii);
		Scripting::GetKeyForCarInRoom(pHandle,&rk);
		return Room(force_cast<int>(rk),force_cast<int>(ii));
	}
	void Vehicle::CurrentRoom::set(Room value) {
		NON_EXISTING_CHECK();
		Scripting::SetRoomForCarByKey( pHandle, force_cast<Scripting::eInteriorRoomKey>(value.InteriorID) );
	}

	float Vehicle::CurrentRPM::get() {
		NON_EXISTING_CHECK(0.0f);
		return unmanaged::MemoryAccess::GetVehicleRPM(pHandle);
	}

	void Vehicle::FreezePosition::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::FreezeCarPosition(pHandle,value);
	}

	void Vehicle::CanBeDamaged::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCarCanBeDamaged(pHandle,value);
	}
	void Vehicle::CanBeVisiblyDamaged::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCarCanBeVisiblyDamaged(pHandle,value);
	}
	void Vehicle::CanTiresBurst::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCanBurstCarTyres(pHandle,value);
	}

	float Vehicle::Dirtyness::get(){
		NON_EXISTING_CHECK(0.0f);
		f32 res;
		Scripting::GetVehicleDirtLevel(pHandle,&res);
		return res;
	}
	void Vehicle::Dirtyness::set(float value){
		NON_EXISTING_CHECK();
		Scripting::SetVehicleDirtLevel(pHandle,value);
	}

	GTA::DoorLock Vehicle::DoorLock::get() {
		NON_EXISTING_CHECK(GTA::DoorLock::None);
		Scripting::eVehicleDoorLock stat;
		Scripting::GetCarDoorLockStatus(pHandle,&stat);
		return (GTA::DoorLock)stat;
	}
	void Vehicle::DoorLock::set(GTA::DoorLock value) {
		NON_EXISTING_CHECK();
		Scripting::LockCarDoors(pHandle, (u32)value);
	}
	
	float Vehicle::EngineHealth::get(){
		NON_EXISTING_CHECK(0.0f);
		return Scripting::GetEngineHealth(pHandle);
	}
	void Vehicle::EngineHealth::set(float value){
		NON_EXISTING_CHECK();
		Scripting::SetEngineHealth(pHandle,value);
		if (value <= 0.0F) Scripting::SetCarEngineOn(pHandle, false, true);
	}

	bool Vehicle::EngineRunning::get(){
		NON_EXISTING_CHECK(false);
		return (CurrentRPM > 0.0f);
	}
	void Vehicle::EngineRunning::set(bool value){
		NON_EXISTING_CHECK();
		if (value)
			Scripting::SetCarEngineOn(pHandle,true,false); //true,true
		else
			Scripting::SetCarEngineOn(pHandle,false,false);
	}

	void Vehicle::HazardLightsOn::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetVehHazardLights(pHandle,value);
	}

	void Vehicle::InteriorLightOn::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetVehInteriorlight(pHandle,value);
	}

	int Vehicle::Health::get(){
		NON_EXISTING_CHECK(0);
		u32 val;
		unmanaged::Native::GetCarHealth(pHandle,&val);
		return val;
	}
	void Vehicle::Health::set(int value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCarHealth(pHandle,value);
	}

	//float Vehicle::Height::get(){
	//	Vector3 v = Model.GetDimensions();
	//	return v.Z;
	//}
	//float Vehicle::HeightOffset::get(){
	//	Vector3 pos = Position;
	//	return (pos.Z - World::GetGroundZ(pos)); // we assume that pos is in the center of the model. thus pos-ground equals roof-pos.
	//}

	bool Vehicle::isAlive::get(){
		NON_EXISTING_CHECK(false);
		return !Scripting::IsCarDead(pHandle);
	}

	bool Vehicle::isOnAllWheels::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsVehicleOnAllWheels(pHandle);
	}

	bool Vehicle::isOnFire::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarOnFire(pHandle);
	}
	void Vehicle::isOnFire::set(bool value){
		NON_EXISTING_CHECK();
		if (value) {
			int fire = Scripting::StartCarFire(pHandle);
			if (fire == 0) return;
			ContentCache::GetFire(fire, true);
		} else {
			Scripting::ExtinguishCarFire(pHandle);
		}
	}

	bool Vehicle::isRequiredForMission::get() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarAMissionCar(pHandle);
	}
	void Vehicle::isRequiredForMission::set(bool value){
		NON_EXISTING_CHECK();
		if (value)
			Scripting::SetCarAsMissionCar(pHandle);
		else
			NoLongerNeeded();
	}

	bool Vehicle::isOnScreen::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarOnScreen(pHandle);
	}
	bool Vehicle::isDriveable::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsVehDriveable(pHandle);
	}

	bool Vehicle::isUpright::get(){
		NON_EXISTING_CHECK(true);
		return Scripting::IsCarUpright(pHandle);
	}
	bool Vehicle::isUpsideDown::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarUpsidedown(pHandle);
	}

	bool Vehicle::LightsOn::get() {
		NON_EXISTING_CHECK(false);
		int adr = unmanaged::MemoryAccess::GetAddressOfVehicle(pHandle);
		if (adr == 0) return false;
		byte lightsOn = *(byte*)(adr + 0xF65);
		if (lightsOn == 1 || lightsOn == 129) { return true; }
		return false;
	}

	GTA::Model Vehicle::Model::get() {
		NON_EXISTING_CHECK(nullptr);
		int model = 0;
		unmanaged::Native::GetCarModel(pHandle, &model);
		return GTA::Model(model);
	}

	String^ Vehicle::Name::get(){
		NON_EXISTING_CHECK(String::Empty);
		int model;
		unmanaged::Native::GetCarModel(pHandle, &model);
		return gcnew String(Scripting::GetDisplayNameFromVehicleModel((Scripting::eModel)model));
	}

	void Vehicle::NeedsToBeHotwired::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetNeedsToBeHotwired(pHandle,value);
	}

	int Vehicle::PassengerSeats::get(){
		NON_EXISTING_CHECK(0);
		u32 val;
		Scripting::GetMaximumNumberOfPassengers(pHandle,&val);
		return val;
	}

	float Vehicle::PetrolTankHealth::get(){
		NON_EXISTING_CHECK(0.0f);
		return Scripting::GetPetrolTankHealth(pHandle);
	}
	void Vehicle::PetrolTankHealth::set(float value){
		NON_EXISTING_CHECK();
		Scripting::SetPetrolTankHealth(pHandle,value);
	}

	void Vehicle::PreviouslyOwnedByPlayer::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetHasBeenOwnedByPlayer(pHandle,value);
	}

	bool Vehicle::SirenActive::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarSirenOn(pHandle);
	}
	void Vehicle::SirenActive::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SwitchCarSiren(pHandle, value);
	}

	void Vehicle::AllowSirenWithoutDriver::set(bool value){
		NON_EXISTING_CHECK();
		Scripting::SetSirenWithNoDriver(pHandle, value);
	}

	float Vehicle::Speed::get(){
		NON_EXISTING_CHECK(0.0f);
		float s;
		unmanaged::Native::GetCarSpeed(pHandle,&s);
		return s;
	}
	void Vehicle::Speed::set(float value){
		NON_EXISTING_CHECK();
		if (Model.isTrain) {
			unmanaged::Native::SetTrainSpeed(pHandle,value);
			unmanaged::Native::SetTrainCruiseSpeed(pHandle,value);
		} else {
			unmanaged::Native::SetCarForwardSpeed(pHandle,value);
		}
	}

	//float Vehicle::TrainSpeed::get(){
	//	return Speed;
	//}
	//void Vehicle::TrainSpeed::set(float value){
	//	unmanaged::Native::SetTrainSpeed(pHandle,value);
	//	unmanaged::Native::SetTrainCruiseSpeed(pHandle,value);
	//}

	Vector3 Vehicle::Velocity::get(){
		NON_EXISTING_CHECK(V3_NULL);
		//Scripting::Vector3 m;
		//Scripting::GetCarSpeedVector(pHandle,&m,false);
		//return Vector3(m.X,m.Y,m.Z);
		return Direction * Speed;
	}
	void Vehicle::Velocity::set(Vector3 value){
		NON_EXISTING_CHECK();
		ApplyForce(value-Velocity);
	}

	void Vehicle::Visible::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetCarVisible(pHandle,value);
	}

	

	//[TypeConverter(Design::ColorConverter::typeid)] 
	GTA::ColorIndex Vehicle::Color::get(){
		NON_EXISTING_CHECK(GTA::ColorIndex(0));
		int c1,c2;
		Scripting::GetCarColours(pHandle,&c1,&c2);
		return GTA::ColorIndex((int)c1);
	}
	//[TypeConverter(Design::ColorConverter::typeid)] 
	void Vehicle::Color::set(GTA::ColorIndex value){
		NON_EXISTING_CHECK();
		int c1,c2;
		Scripting::GetCarColours(pHandle,&c1,&c2);
		c1 = (Scripting::ColourIndex)value.Index;
		Scripting::ChangeCarColour(pHandle,c1,c2);
	}

	GTA::ColorIndex Vehicle::FeatureColor1::get(){
		NON_EXISTING_CHECK(GTA::ColorIndex(0));
		int c1,c2;
		Scripting::GetCarColours(pHandle,&c1,&c2);
		return GTA::ColorIndex((int)c2);
	}
	void Vehicle::FeatureColor1::set(GTA::ColorIndex value){
		NON_EXISTING_CHECK();
		int c1,c2;
		Scripting::GetCarColours(pHandle,&c1,&c2);
		c2 = (Scripting::ColourIndex)value.Index;
		Scripting::ChangeCarColour(pHandle,c1,c2);
	}

	GTA::ColorIndex Vehicle::SpecularColor::get(){
		NON_EXISTING_CHECK(GTA::ColorIndex(0));
		int c1,c2;
		Scripting::GetExtraCarColours(pHandle,&c1,&c2);
		return GTA::ColorIndex((int)c1);
	}
	void Vehicle::SpecularColor::set(GTA::ColorIndex value){
		NON_EXISTING_CHECK();
		int c1,c2;
		Scripting::GetExtraCarColours(pHandle,&c1,&c2);
		c1 = (Scripting::ColourIndex)value.Index;
		Scripting::SetExtraCarColours(pHandle,c1,c2);
	}

	GTA::ColorIndex Vehicle::FeatureColor2::get(){
		NON_EXISTING_CHECK(GTA::ColorIndex(0));
		int c1,c2;
		Scripting::GetExtraCarColours(pHandle,&c1,&c2);
		return GTA::ColorIndex((int)c2);
	}
	void Vehicle::FeatureColor2::set(GTA::ColorIndex value){
		NON_EXISTING_CHECK();
		int c1,c2;
		Scripting::GetExtraCarColours(pHandle,&c1,&c2);
		c2 = (Scripting::ColourIndex)value.Index;
		Scripting::SetExtraCarColours(pHandle,c1,c2);
	}

	value::VehicleDoor^ Vehicle::Door(GTA::VehicleDoor index) {
		NON_EXISTING_CHECK(nullptr);
		GTA::value::VehicleDoor^ res;
		if isNULL(pDoorCache) {
			pDoorCache = gcnew Dictionary<GTA::VehicleDoor,GTA::value::VehicleDoor^>();
		} else {
			if (pDoorCache->TryGetValue(index, res)) return res;
		}
		res = gcnew GTA::value::VehicleDoor(this, index);
		pDoorCache->Add(index, res);
		return res;
	}
	value::VehicleExtra^ Vehicle::Extras(int index) {
		NON_EXISTING_CHECK(nullptr);
		GTA::value::VehicleExtra^ res;
		if isNULL(pExtraCache) {
			pExtraCache = gcnew Dictionary<int,GTA::value::VehicleExtra^>();
		} else {
			if (pExtraCache->TryGetValue(index, res)) return res;
		}
		res = gcnew GTA::value::VehicleExtra(this, index);
		pExtraCache->Add(index, res);
		return res;
	}

	GTA::Ped^ Vehicle::CreatePedOnSeat(VehicleSeat Seat) {
		NON_EXISTING_CHECK(nullptr);
		//if (Seat == VehicleSeat::AnyPassengerSeat) Seat = GetFreeSeat(); // AnyPassengerSeat WORKS
		if (Seat <= VehicleSeat::None) return nullptr;
		if (!isSeatFree(Seat)) return nullptr;
		int ped;
		if (Seat == VehicleSeat::Driver)
			unmanaged::Native::CreateRandomCharAsDriver(pHandle,&ped);
		else
			unmanaged::Native::CreateRandomCharAsPassenger(pHandle,(int)Seat,&ped);
		if (ped == 0) return nullptr;
		return ContentCache::GetPed(ped);
	}
	GTA::Ped^ Vehicle::CreatePedOnSeat(VehicleSeat Seat, GTA::Model model, RelationshipGroup Type) {
		NON_EXISTING_CHECK(nullptr);
		//if (Seat == VehicleSeat::AnyPassengerSeat) Seat = GetFreeSeat(); // AnyPassengerSeat WORKS
		if (Seat <= VehicleSeat::None) return nullptr;
		if (!isSeatFree(Seat)) return nullptr;
		model.LoadToMemoryNow();
		int ped;
		if (Seat == VehicleSeat::Driver)
			unmanaged::Native::CreateCharInsideCar(pHandle,(Scripting::ePedType)Type,(Scripting::eModel)model.Hash,&ped);
		else
			unmanaged::Native::CreateCharAsPassenger(pHandle,(Scripting::ePedType)Type,(Scripting::eModel)model.Hash,(int)Seat,&ped);
		model.AllowDisposeFromMemory();
		if (ped == 0) return nullptr;
		return ContentCache::GetPed(ped);
	}
	GTA::Ped^ Vehicle::CreatePedOnSeat(VehicleSeat Seat, GTA::Model model) {
		NON_EXISTING_CHECK(nullptr);
		GTA::Ped^ res = CreatePedOnSeat(Seat,model,RelationshipGroup::Civillian_Male);
		if isNULL(res) return nullptr;
		if (res->Gender == Gender::Female) res->RelationshipGroup = RelationshipGroup::Civillian_Female;
		return res;
	}
	//GTA::Ped^ Vehicle::GetPassenger(int SeatIndex) {
	//	int ped;
	//	Scripting::GetCharInCarPassengerSeat(pHandle,SeatIndex,&ped);
	//	if (ped == 0) return nullptr;
	//	return gcnew GTA::Ped(ped);
	//}
	//GTA::Ped^ Vehicle::GetDriver() {
	//	int ped;
	//	Scripting::GetDriverOfCar(pHandle,&ped);
	//	if (ped == 0) return nullptr;
	//	return gcnew GTA::Ped(ped);
	//}
	GTA::Ped^ Vehicle::GetPedOnSeat(VehicleSeat Seat) {
		NON_EXISTING_CHECK(nullptr);
		int ped;
		if (Seat <= VehicleSeat::None) return nullptr;
		if (Seat == VehicleSeat::Driver)
			unmanaged::Native::GetDriverOfCar(pHandle,&ped);
		else if (Scripting::IsCarPassengerSeatFree(pHandle,(u32)Seat))
			return nullptr;
		else
			unmanaged::Native::GetCharInCarPassengerSeat(pHandle,(u32)Seat,&ped);
		if (ped == 0) return nullptr;
		return ContentCache::GetPed(ped);
	}

	bool Vehicle::isSeatFree(VehicleSeat Seat) {
		NON_EXISTING_CHECK(false);
		if (Seat <= VehicleSeat::None) return false;
		if (Seat == VehicleSeat::AnyPassengerSeat) {
			for (int i = 0; i < PassengerSeats; i++) {
				if (isSeatFree((VehicleSeat)i)) return true;
			}
			return false;
		} else if (Seat == VehicleSeat::Driver) {
			int ped;
			unmanaged::Native::GetDriverOfCar(pHandle,&ped);
			return (ped == 0);
		} else {
			return Scripting::IsCarPassengerSeatFree(pHandle,(u32)Seat);
		}
	}

	bool Vehicle::isTouching(Vehicle^ vehicle) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCarTouchingCar(pHandle, vehicle->Handle);
	}

	Blip^ Vehicle::AttachBlip() {
		NON_EXISTING_CHECK(nullptr);
		return Blip::AddBlip(this);
	}

	VehicleSeat Vehicle::GetFreeSeat() {
		NON_EXISTING_CHECK(VehicleSeat::None);
		if (isSeatFree(VehicleSeat::Driver)) return VehicleSeat::Driver;
		return GetFreePassengerSeat();
	}
	VehicleSeat Vehicle::GetFreePassengerSeat() {
		NON_EXISTING_CHECK(VehicleSeat::None);
		int count = PassengerSeats;
		for (int i = 0; i<count; i++) {
			if (isSeatFree((VehicleSeat)i)) return (VehicleSeat)i;
		}
		return VehicleSeat::None;
	}


	GTA::Vector3 Vehicle::GetOffsetPosition(GTA::Vector3 Offset) {
		NON_EXISTING_CHECK(V3_NaN);
		float x = 0.0f; float y = 0.0f; float z = 0.0f;
		Scripting::GetOffsetFromCarInWorldCoords(pHandle, Offset.X, Offset.Y, Offset.Z, &x, &y, &z);
		return GTA::Vector3(x,y,z);
	}
	GTA::Vector3 Vehicle::GetOffset(GTA::Vector3 Position) {
		NON_EXISTING_CHECK(V3_NULL);
		float x = 0.0f; float y = 0.0f; float z = 0.0f;
		Scripting::GetOffsetFromCarGivenWorldCoords(pHandle, Position.X, Position.Y, Position.Z, &x, &y, &z);
		return GTA::Vector3(x,y,z);
	}

	void Vehicle::ApplyForce(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToCar(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 0, 1, 1);
	}
	void Vehicle::ApplyForce(Vector3 Direction) {
		ApplyForce(Direction,Vector3());
	}

	void Vehicle::ApplyForceRelative(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToCar(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 1, 1, 1);
	}
	void Vehicle::ApplyForceRelative(Vector3 Direction) {
		ApplyForceRelative(Direction,Vector3());
	}


	bool Vehicle::IsTireBurst(GTA::VehicleWheel wheel) {
		NON_EXISTING_CHECK(false);
		return Scripting::IsCarTyreBurst(pHandle, (Scripting::eVehicleTyre)wheel);
	}
	void Vehicle::BurstTire(GTA::VehicleWheel wheel) {
		NON_EXISTING_CHECK();
		Scripting::BurstCarTyre(pHandle, (Scripting::eVehicleTyre)wheel);
	}
	void Vehicle::FixTire(GTA::VehicleWheel wheel) {
		NON_EXISTING_CHECK();
		// The native call below fixes the tire but the model still remains bursted so we do 
		// this from memory to make sure the model is replaced
		u32 offset = 0;
		switch (wheel)
		{
		case GTA::VehicleWheel::FrontLeft:
			offset = 0x1680;
			break;
		case GTA::VehicleWheel::FrontRight:
			offset = 0x1960;
			break;
		case GTA::VehicleWheel::CenterLeft:
			offset = 0x1C40;
			break;
		case GTA::VehicleWheel::CenterRight:
			offset = 0x1DB0;
			break;
		case GTA::VehicleWheel::RearLeft:
			offset = 0x17F0;
			break;
		case GTA::VehicleWheel::RearRight:
			offset = 0x1AD0;
			break;
		}
		if (offset == 0) return;
		*(float*)(unmanaged::MemoryAccess::GetAddressOfVehicle(pHandle) + offset) = 1000;
		Scripting::FixCarTyre(pHandle, (Scripting::eVehicleTyre)wheel);
	}



	void Vehicle::CloseAllDoors() {
		NON_EXISTING_CHECK();
		Scripting::CloseAllCarDoors(pHandle);
	}
	void Vehicle::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		int car = pHandle;
		unmanaged::Native::DeleteCar(&car);
	}
	void Vehicle::EveryoneLeaveVehicle() {
		NON_EXISTING_CHECK();
		Scripting::TaskEveryoneLeaveCar(pHandle);
	}
	void Vehicle::PassengersLeaveVehicle(bool Immediately) {
		NON_EXISTING_CHECK();
		Ped^ p;
		int seats = PassengerSeats;
		for (int seat = 0; seat < seats; seat++) {
			p = GetPedOnSeat((VehicleSeat)seat);
			if isNotNULL(p) { 
				if (Immediately)
					p->Task->LeaveVehicleImmediately(this);
				else
					p->Task->LeaveVehicle(this,true);
			}
		}
	}
	void Vehicle::PassengersLeaveVehicle() {
		PassengersLeaveVehicle(false);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Vehicle::InternalCheckExists() {
		if (pHandle == 0) return false;
		//if (MemoryAddress == 0) return false;
		//if (int( *(u8*)(MemoryAddress + 0x08)) == 0) return false;
		try {
			if (Position == GTA::Vector3::Zero) return false;
			return unmanaged::Native::DoesVehicleExist(pHandle);
		} catch (...) {
			return false;
		}
	}

	void Vehicle::Explode() {
		NON_EXISTING_CHECK();
		unmanaged::Native::ExplodeCar(pHandle, true, false);
	}
	void Vehicle::NoLongerNeeded() {
		NON_EXISTING_CHECK_RELAXED();
		int h = pHandle;
		unmanaged::Native::MarkCarAsNoLongerNeeded(&h);
	}
	void Vehicle::PlaceOnGroundProperly() {
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCarOnGroundProperly(pHandle);
	}
	void Vehicle::PlaceOnNextStreetProperly() {
		NON_EXISTING_CHECK();
		float tX, tY, tZ, tH;
		Vector3 p = Position;
		for (int i = 1; i<40; i++) {
			Scripting::GetNthClosestCarNodeWithHeading(p.X,p.Y,p.Z,i,&tX,&tY,&tZ,&tH);
			if (!Scripting::IsPointObscuredByAMissionEntity(tX,tY,tZ,5.0f,5.0f,5.0f)) {
				Heading = tH;
				Position = Vector3(tX,tY,tZ);
				PlaceOnGroundProperly();
				return;
			}
		}
	}
	void Vehicle::Repair() {
		NON_EXISTING_CHECK();
		unmanaged::Native::FixCar(pHandle);
	}
	void Vehicle::MakeProofTo(bool Bullets, bool Fire, bool Explosions, bool Collisions, bool MeleeAttacks) {
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCarProofs(pHandle, Bullets, Fire, Explosions, Collisions, MeleeAttacks);
	}
	void Vehicle::SoundHorn(int duration) {
		NON_EXISTING_CHECK();
		Scripting::SoundCarHorn(pHandle,duration);
	}
	void Vehicle::Wash() {
		NON_EXISTING_CHECK();
		Dirtyness = 0.0;
		Scripting::WashVehicleTextures(pHandle,255);
	}
		
	//bool Vehicle::operator == (Vehicle^ left, Vehicle^ right) {
	//	return (left->Handle == right->Handle);
	//}
	//bool Vehicle::operator != (Vehicle^ left, Vehicle^ right) {
	//	return !(left == right);
	//}
}