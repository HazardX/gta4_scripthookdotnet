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

#include "vTasks.h"

#include "AnimationSet.h"
#include "Object.h"
#include "Ped.h"
#include "TaskSequence.h"
#include "Vehicle.h"

#pragma managed

namespace GTA {
namespace value {

	Tasks::Tasks(Ped^ ped) {
		this->ped = ped;
	}
	
	void Tasks::AimAt(Vector3 target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskAimGunAtCoord(ped->Handle, target.X, target.Y, target.Z, duration);
	}
	void Tasks::AimAt(Ped^ target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskAimGunAtChar(ped->Handle, target->Handle, duration);
	}
	void Tasks::CruiseWithVehicle(GTA::Vehicle^ Vehicle, float SpeedMph, bool ObeyTrafficLaws) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(Vehicle);
		Scripting::TaskCarDriveWander(ped->Handle, Vehicle->Handle, SpeedMph, (ObeyTrafficLaws ? 1 : 2));
	}
	void Tasks::Die() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskDie(ped->Handle);
	}


	void Tasks::DrivePointRoute(GTA::Vehicle^ Vehicle, float Speed, ... array<Vector3>^ RoutePoints) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(Vehicle);
		if (isNULL(RoutePoints) || (RoutePoints->Length == 0)) return;
		Scripting::TaskFlushRoute();
		for (int i = 0; i < RoutePoints->Length; i++) {
			Scripting::TaskExtendRoute(RoutePoints[i].X, RoutePoints[i].Y, RoutePoints[i].Z);
		}
		Scripting::TaskDrivePointRoute(ped->Handle, Vehicle->Handle, Speed);
	}

	// use enum DrivingStyle instead?

	// MissionIDs for TaskCarMission: 5(wait), 12(follow) and 21(drive to player)

	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(Vehicle);
		OBJECT_NON_EXISTING_CHECK(TargetPed);
		if (!AllowToDriveRoadsWrongWay)
			Scripting::TaskCarMissionPedTargetNotAgainstTraffic(ped->Handle, Vehicle->Handle, TargetPed->Handle, 4, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 5, 10);
		else
			Scripting::TaskCarMissionPedTarget(ped->Handle, Vehicle->Handle, TargetPed->Handle, 4, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 5, 10);
	}
	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle, TargetPed, SpeedMph, ObeyTrafficLaws, true);
	}

	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(Vehicle);
		OBJECT_NON_EXISTING_CHECK(TargetVehicle);
		if (!AllowToDriveRoadsWrongWay)
			Scripting::TaskCarMissionNotAgainstTraffic(ped->Handle, Vehicle->Handle, TargetVehicle->Handle, 1, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 10, 5);
		else
			Scripting::TaskCarMission(ped->Handle, Vehicle->Handle, TargetVehicle->Handle, 1, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 10, 5);
	}
	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle, TargetVehicle, SpeedMph, ObeyTrafficLaws, true);
	}

	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, Vector3 Target, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(Vehicle);
		if (!AllowToDriveRoadsWrongWay)
			Scripting::TaskCarMissionCoorsTargetNotAgainstTraffic(ped->Handle, Vehicle->Handle, Target.X, Target.Y, Target.Z, 4, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 5, 10);
		else
			Scripting::TaskCarMissionCoorsTarget(ped->Handle, Vehicle->Handle, Target.X, Target.Y, Target.Z, 4, SpeedMph, (ObeyTrafficLaws ? 1 : 2), 5, 10);
	}
	void Tasks::DriveTo(GTA::Vehicle^ Vehicle, Vector3 Target, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle, Target, SpeedMph, ObeyTrafficLaws, false);
	}

	void Tasks::DriveTo(Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		DriveTo(Vehicle::AnyVehicle, TargetPed, SpeedMph, ObeyTrafficLaws, AllowToDriveRoadsWrongWay);
	}
	void Tasks::DriveTo(Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle::AnyVehicle, TargetPed, SpeedMph, ObeyTrafficLaws);
	}
	void Tasks::DriveTo(GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		DriveTo(Vehicle::AnyVehicle, TargetVehicle, SpeedMph, ObeyTrafficLaws, AllowToDriveRoadsWrongWay);
	}
	void Tasks::DriveTo(GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle::AnyVehicle, TargetVehicle, SpeedMph, ObeyTrafficLaws);
	}
	void Tasks::DriveTo(Vector3 Target, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay) {
		DriveTo(Vehicle::AnyVehicle, Target, SpeedMph, ObeyTrafficLaws, AllowToDriveRoadsWrongWay);
	}
	void Tasks::DriveTo(Vector3 Target, float SpeedMph, bool ObeyTrafficLaws) {
		DriveTo(Vehicle::AnyVehicle, Target, SpeedMph, ObeyTrafficLaws);
	}
	//void Tasks::EnterVehicle(GTA::Vehicle^ vehicle, int PassengerSeat) {
	//	Scripting::TaskEnterCarAsPassenger(ped->Handle, vehicle->Handle, PassengerSeat, 0);
	//}
	//void Tasks::EnterVehicle(GTA::Vehicle^ vehicle) {
	//	Scripting::TaskEnterCarAsDriver(ped->Handle, vehicle->Handle, 0);
	//}
	void Tasks::EnterVehicle() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskEnterCarAsPassenger(ped->Handle, 0, 0, -2);
	}
	void Tasks::EnterVehicle(GTA::Vehicle^ vehicle, GTA::VehicleSeat Seat) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(vehicle);
		if (Seat <= VehicleSeat::None) return;
		if (Seat == VehicleSeat::Driver)
			Scripting::TaskEnterCarAsDriver(ped->Handle, vehicle->Handle, 0);
		else
			Scripting::TaskEnterCarAsPassenger(ped->Handle, vehicle->Handle, 0, (i32)Seat);
	}

	void Tasks::FightAgainst(Ped^ target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskCombatTimed(ped->Handle, target->Handle, duration);
	}
	void Tasks::FightAgainst(Ped^ target) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskCombat(ped->Handle, target->Handle);
	}
	void Tasks::FightAgainstHatedTargets(float radius, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskCombatHatedTargetsAroundCharTimed(ped->Handle, radius, duration);
	}
	void Tasks::FightAgainstHatedTargets(float radius) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskCombatHatedTargetsAroundChar(ped->Handle, radius);
	}
	void Tasks::FleeFromChar(Ped^ target, bool onPavements, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		if (onPavements)
			Scripting::TaskSmartFleeCharPreferringPavements(ped->Handle, target->Handle, 100.0f, duration);
		else
			Scripting::TaskSmartFleeChar(ped->Handle, target->Handle, 100.0f, duration);
	}
	void Tasks::FleeFromChar(Ped^ target, bool onPavements) {
		FleeFromChar(target, onPavements, -1);
	}
	void Tasks::FleeFromChar(Ped^ target) {
		FleeFromChar(target, false, -1);
	}

	void Tasks::GoTo(Ped^ TargetPed, float OffsetRight, float OffsetFront, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(TargetPed);
		Scripting::TaskGotoCharOffset(ped->Handle, TargetPed->Handle, duration, OffsetRight, OffsetFront);
	}
	void Tasks::GoTo(Ped^ TargetPed, float OffsetRight, float OffsetFront) {
		GoTo(TargetPed, OffsetRight, OffsetFront, -1);
	}
	void Tasks::GoTo(Ped^ TargetPed) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(TargetPed);
		Scripting::TaskGotoCharOffset(ped->Handle, TargetPed->Handle, -1, 0.0f, 0.0f);
	}
	void Tasks::GoTo(Vector3 Position, bool IgnorePaths) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (IgnorePaths)
			Scripting::TaskGoStraightToCoord(ped->Handle, Position.X, Position.Y, Position.Z, 2, -1);
		else
			Scripting::TaskFollowNavMeshToCoord(ped->Handle,Position.X, Position.Y, Position.Z, 2, -1, 1.0f);
	}
	void Tasks::GoTo(Vector3 Position) {
		GoTo(Position, false);
	}
	void Tasks::RunTo(Vector3 Position, bool IgnorePaths) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (IgnorePaths)
			Scripting::TaskGoStraightToCoord(ped->Handle, Position.X, Position.Y, Position.Z, 4, -1);
		else
			Scripting::TaskFollowNavMeshToCoord(ped->Handle,Position.X, Position.Y, Position.Z, 4, -1, 1.0f);
	}
	void Tasks::RunTo(Vector3 Position) {
		RunTo(Position, false);
	}

	void Tasks::GuardCurrentPosition() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskGuardCurrentPosition(ped->Handle, 15.0f, 10.0f, 1);
	}
	void Tasks::HandsUp(int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (duration<0) duration=MAX_DURATION;
		Scripting::TaskHandsUp(ped->Handle, duration);
	}
	void Tasks::LandHelicopter(Vehicle^ heli, Vector3 Position) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(heli);
		Scripting::TaskHeliMission(ped->Handle, heli->Handle, 0, 0, Position.X, Position.Y, Position.Z, 5, 0.0f, 0, -1.0f, -1, -1);
	}
	void Tasks::LeaveVehicle(Vehicle^ vehicle, bool CloseDoor) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(vehicle);
		if (CloseDoor)
			Scripting::TaskLeaveCar(ped->Handle,vehicle->Handle);
		else
			Scripting::TaskLeaveCarDontCloseDoor(ped->Handle,vehicle->Handle);
	}
	void Tasks::LeaveVehicle() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskLeaveAnyCar(ped->Handle);
	}
	void Tasks::LeaveVehicleImmediately(Vehicle^ vehicle) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(vehicle);
		Scripting::TaskLeaveCarImmediately(ped->Handle,vehicle->Handle);
	}
	
	void Tasks::LookAt(GTA::Vector3 target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskLookAtCoord(ped->Handle, target.X, target.Y, target.Z, duration, 0);
	}
	void Tasks::LookAt(GTA::Object^ target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskLookAtObject(ped->Handle, target->Handle, duration, 0);
	}
	void Tasks::LookAt(GTA::Vehicle^ target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskLookAtVehicle(ped->Handle, target->Handle, duration, 0);
	}
	void Tasks::LookAt(GTA::Ped^ target, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskLookAtChar(ped->Handle, target->Handle, duration, 0);
	}
	void Tasks::PlayAnimation(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed, AnimationFlags Flags) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (System::Object::ReferenceEquals(AnimationSet,nullptr)) return;
		if (!AnimationSet->LoadToMemoryNow()) return;
		char* pAnimName = PinStringA(AnimationName);
		char* pAnimSet = PinStringA(AnimationSet->Name);
		try {
			Scripting::TaskPlayAnimWithFlags(ped->Handle, pAnimName, pAnimSet, Speed, -1, (u32)Flags);
		} finally {
			FreeString(pAnimSet);
			FreeString(pAnimName);
		}
	}
	void Tasks::PlayAnimation(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed) {
		PlayAnimation(AnimationSet, AnimationName, Speed, AnimationFlags::None);
	}
	void Tasks::PutAwayMobilePhone() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskUseMobilePhone(ped->Handle, false);
	}
	void Tasks::ShootAt(Ped^ target, ShootMode mode, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskShootAtChar(ped->Handle, target->Handle, duration, (i32)mode);
	}
	void Tasks::ShootAt(Ped^ target, ShootMode mode) {
		ShootAt(target, mode, -1);
	}
	void Tasks::StandStill(int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (duration<0) duration=MAX_DURATION;
		Scripting::TaskStandStill(ped->Handle,duration);
	}
	void Tasks::SwapWeapon(GTA::Weapon Weapon) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskSwapWeapon(ped->Handle,(Scripting::eWeapon)Weapon);
	}
	void Tasks::StartScenario(String^ ScenarioName, Vector3 Position) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		char* ptr = PinStringA(ScenarioName);
		Scripting::TaskStartScenarioAtPosition(ped->Handle, ptr, Position.X, Position.Y, Position.Z, 0);
		FreeString(ptr);
	}
	void Tasks::TurnTo(Vector3 Position) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskTurnCharToFaceCoord(ped->Handle, Position.X, Position.Y, Position.Z);
	}
	void Tasks::TurnTo(Ped^ target) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		Scripting::TaskTurnCharToFaceChar(ped->Handle, target->Handle);
	}
	void Tasks::UseMobilePhone() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskUseMobilePhone(ped->Handle, true);
	}
	void Tasks::UseMobilePhone(int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskUseMobilePhoneTimed(ped->Handle, duration);
	}
	void Tasks::Wait(int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		if (duration<0) duration=MAX_DURATION;
		Scripting::TaskPause(ped->Handle,duration);
	}
	void Tasks::WalkRelativeToPed(Ped^ target, float OffsetToRight, float OffsetToFront, int duration) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(target);
		if (duration<0) duration=-1;
		Scripting::TaskGotoCharOffset(ped->Handle, target->Handle, duration, OffsetToRight, OffsetToFront);
	}
	void Tasks::WanderAround() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		Scripting::TaskWanderStandard(ped->Handle);
	}
	//void Tasks::WarpIntoVehicle(GTA::Vehicle^ vehicle, int PassengerSeat) {
	//	Scripting::TaskWarpCharIntoCarAsPassenger(ped->Handle, vehicle->Handle, PassengerSeat);
	//}
	//void Tasks::WarpIntoVehicle(GTA::Vehicle^ vehicle) {
	//	Scripting::TaskWarpCharIntoCarAsDriver(ped->Handle, vehicle->Handle);
	//}
	void Tasks::WarpIntoVehicle(GTA::Vehicle^ vehicle, GTA::VehicleSeat Seat) {
		if (Seat <= VehicleSeat::None) return;
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		OBJECT_NON_EXISTING_CHECK(vehicle);
		if (Seat == VehicleSeat::Driver)
			Scripting::TaskWarpCharIntoCarAsDriver(ped->Handle, vehicle->Handle);
		else
			Scripting::TaskWarpCharIntoCarAsPassenger(ped->Handle, vehicle->Handle, (u32)Seat);
	}

	// PED TASK FUNCTIONS

	PedTasks::PedTasks(Ped^ ped)
		: Tasks(ped) {
	}

	void PedTasks::AlwaysKeepTask::set(bool value) {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		unmanaged::Native::SetCharKeepTask(ped->Handle,value);
	}

	void PedTasks::ClearAll() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		unmanaged::Native::ClearCharTasks(ped->Handle);
	}
	void PedTasks::ClearAllImmediately() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		unmanaged::Native::ClearCharTasksImmediately(ped->Handle);
	}
	void PedTasks::ClearSecondary() {
		OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(ped);
		unmanaged::Native::ClearCharSecondaryTask(ped->Handle);
	}

	void PedTasks::PerformSequence(TaskSequence^ sequence) {
		if (sequence == nullptr) return;
		sequence->Perform(ped);
	}

}
}