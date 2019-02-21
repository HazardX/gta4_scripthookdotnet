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
	public ref class Tasks abstract {

	protected:
		Ped^ ped;
		static int const MAX_DURATION = 3600000; // 1 hour

	internal:
		Tasks(Ped^ ped);
		
	public:
		void AimAt(Vector3 target, int duration);
		void AimAt(Ped^ target, int duration);
		void CruiseWithVehicle(GTA::Vehicle^ Vehicle, float SpeedMph, bool ObeyTrafficLaws);
		void Die();
		void DrivePointRoute(GTA::Vehicle^ Vehicle, float Speed, ... array<Vector3>^ RoutePoints);
		void DriveTo(Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws);
		void DriveTo(GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws);
		void DriveTo(Vector3 Target, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(Vector3 Target, float SpeedMph, bool ObeyTrafficLaws);
		void DriveTo(GTA::Vehicle^ Vehicle, Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(GTA::Vehicle^ Vehicle, Ped^ TargetPed, float SpeedMph, bool ObeyTrafficLaws);
		void DriveTo(GTA::Vehicle^ Vehicle, GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(GTA::Vehicle^ Vehicle, GTA::Vehicle^ TargetVehicle, float SpeedMph, bool ObeyTrafficLaws);
		void DriveTo(GTA::Vehicle^ Vehicle, Vector3 Target, float SpeedMph, bool ObeyTrafficLaws, bool AllowToDriveRoadsWrongWay);
		void DriveTo(GTA::Vehicle^ Vehicle, Vector3 Target, float SpeedMph, bool ObeyTrafficLaws);
		//void EnterVehicle(GTA::Vehicle^ Vehicle, int PassengerSeat); 
		//void EnterVehicle(GTA::Vehicle^ Vehicle); 
		void EnterVehicle(); 
		void EnterVehicle(GTA::Vehicle^ Vehicle, GTA::VehicleSeat Seat); 
		void FightAgainst(Ped^ target, int duration);
		void FightAgainst(Ped^ target);
		void FightAgainstHatedTargets(float radius, int duration);
		void FightAgainstHatedTargets(float radius);
		void FleeFromChar(Ped^ target, bool onPavements, int duration);
		void FleeFromChar(Ped^ target, bool onPavements);
		void FleeFromChar(Ped^ target);
		void GoTo(Ped^ TargetPed, float OffsetRight, float OffsetFront, int duration);
		void GoTo(Ped^ TargetPed, float OffsetRight, float OffsetFront);
		void GoTo(Ped^ TargetPed);
		void GoTo(Vector3 Position, bool IgnorePaths);
		void GoTo(Vector3 Position);
		void GuardCurrentPosition();
		void HandsUp(int duration);
		void LandHelicopter(Vehicle^ vehicle, Vector3 Position);
		void LeaveVehicle(Vehicle^ vehicle, bool CloseDoor);
		void LeaveVehicle();
		void LeaveVehicleImmediately(Vehicle^ vehicle);
		void LookAt(GTA::Vector3 target, int duration);
		void LookAt(GTA::Object^ target, int duration);
		void LookAt(GTA::Vehicle^ target, int duration);
		void LookAt(GTA::Ped^ target, int duration);
		void PlayAnimation(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed, AnimationFlags Flags);
		void PlayAnimation(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed);
		void PutAwayMobilePhone();
		void RunTo(Vector3 Position, bool IgnorePaths);
		void RunTo(Vector3 Position);
		void ShootAt(Ped^ target, ShootMode mode, int duration);
		void ShootAt(Ped^ target, ShootMode mode);
		void StandStill(int duration);
		void SwapWeapon(GTA::Weapon Weapon);
		void StartScenario(String^ ScenarioName, Vector3 Position); // "Vehicle_LookingInBoot"
		void TurnTo(Vector3 Position);
		void TurnTo(Ped^ target);
		void UseMobilePhone();
		void UseMobilePhone(int duration);
		void Wait(int duration);
		void WanderAround();
		//void WarpIntoVehicle(GTA::Vehicle^ Vehicle, int PassengerSeat); 
		//void WarpIntoVehicle(GTA::Vehicle^ Vehicle); 
		void WarpIntoVehicle(GTA::Vehicle^ Vehicle, GTA::VehicleSeat Seat); 

	internal: // does not work
		void WalkRelativeToPed(Ped^ target, float OffsetToRight, float OffsetToFront, int duration);

	};

	CLASS_ATTRIBUTES
	public ref class PedTasks sealed : public Tasks {

	internal:
		PedTasks(Ped^ ped);
		
	public:
		property bool AlwaysKeepTask { 
			void set(bool value);
		}

		void ClearAll();
		void ClearAllImmediately();
		void ClearSecondary();
		void PerformSequence(TaskSequence^ sequence);

	};

}
}