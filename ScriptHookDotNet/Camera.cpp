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

#include "Camera.h"

#include "ContentCache.h"
#include "Ped.h"
#include "Object.h"
#include "Vehicle.h"

#pragma managed

namespace GTA{

	Camera::Camera(int Handle)
		:HandleObject(Handle) {
	}
	Camera::Camera()
		:HandleObject(0) {
		u32 c;
		unmanaged::Native::CreateCam(14,&c);
		pHandle = c;
		ContentCache::AddCamera(this, true);
		Deactivate();
	}

	Vector3 Camera::Position::get(){
		NON_EXISTING_CHECK(V3_NaN);
		float x,y,z;
		Scripting::GetCamPos(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void Camera::Position::set(Vector3 value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCamPos(pHandle,value.X,value.Y,value.Z);
	}

	Vector3 Camera::Rotation::get(){
		NON_EXISTING_CHECK(V3_NULL);
		float x,y,z;
		Scripting::GetCamRot(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void Camera::Rotation::set(Vector3 value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCamRot(pHandle,value.X,value.Y,value.Z);
	}

	Vector3 Camera::Direction::get(){
		return Helper::RotationToDirection(Rotation);
	}
	void Camera::Direction::set(Vector3 value){
		NON_EXISTING_CHECK();
		Rotation = Helper::DirectionToRotation(value, Rotation.Y);
	}

	float Camera::Heading::get(){
		NON_EXISTING_CHECK(0.0f);
		return Rotation.Z;
	}
	void Camera::Heading::set(float value){
		NON_EXISTING_CHECK();
		Vector3 rot = Rotation;
		rot.Z = value;
		Rotation = rot;
	}

	float Camera::Roll::get(){
		NON_EXISTING_CHECK(0.0f);
		return Rotation.Y;
	}
	void Camera::Roll::set(float value){
		NON_EXISTING_CHECK();
		Vector3 rot = Rotation;
		rot.Y = value;
		Rotation = rot;
	}

	float Camera::FOV::get(){
		NON_EXISTING_CHECK(0.0f);
		float fov;
		Scripting::GetCamFov(pHandle,&fov);
		return fov;
	}
	void Camera::FOV::set(float value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetCamFov(pHandle,value);
	}

	bool Camera::isActive::get(){
		NON_EXISTING_CHECK(false);
		return Scripting::IsCamActive(pHandle);
	}
	void Camera::isActive::set(bool value){
		NON_EXISTING_CHECK();
		if (value)
			Activate();
		else
			Deactivate();
	}

	void Camera::DrunkEffectIntensity::set(float value){
		NON_EXISTING_CHECK();
		if (value <= 0.0001f)
			unmanaged::Native::SetDrunkCam(pHandle, 0.0f, 0);
		else
			unmanaged::Native::SetDrunkCam(pHandle, value, int::MaxValue);
	}

	void Camera::TargetPed(Ped^ ped) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(ped);
		unmanaged::Native::SetCamTargetPed(pHandle,ped->Handle);
	}
	void Camera::LookAt(GTA::Object^ object) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(object);
		unmanaged::Native::PointCamAtObject(pHandle, object->Handle);
	}
	void Camera::LookAt(Vehicle^ vehicle) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(vehicle);
		unmanaged::Native::PointCamAtVehicle(pHandle, vehicle->Handle);
	}
	void Camera::LookAt(Ped^ ped) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(ped);
		unmanaged::Native::PointCamAtPed(pHandle, ped->Handle);
	}
	void Camera::LookAt(Vector3 Position) {
		NON_EXISTING_CHECK();
		unmanaged::Native::PointCamAtCoord(pHandle, Position.X, Position.Y, Position.Z);
	}

	void Camera::Activate() {
		NON_EXISTING_CHECK();
		i32 handle = pHandle;
		unmanaged::Native::ActivateScriptedCams(1,1);
		unmanaged::Native::BeginCamCommands(&handle);
		unmanaged::Native::SetCamActive(pHandle,true);
		unmanaged::Native::SetCamPropagate(pHandle,true);
	}
	bool Camera::isSphereVisible(Vector3 Position, float Radius) {
		NON_EXISTING_CHECK(false);
		return Scripting::CamIsSphereVisible(pHandle, Position.X, Position.Y, Position.Z, Radius);
	}
	void Camera::Deactivate() {
		NON_EXISTING_CHECK_RELAXED();
		i32 handle = pHandle;
		unmanaged::Native::SetCamActive(pHandle,false);
		unmanaged::Native::SetCamPropagate(pHandle,false);
		unmanaged::Native::EndCamCommands(&handle);
		unmanaged::Native::ActivateScriptedCams(0,0);
	}
	void Camera::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		if (isActive) Deactivate();
		unmanaged::Native::DestroyCam(pHandle);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Camera::InternalCheckExists() {
		if (pHandle == 0) return false;
		try {
			return Scripting::DoesCamExist(pHandle);
		} catch (...) {
			return false;
		}
	}

	//bool Camera::operator == (Camera^ left, Camera^ right) {
	//	return (left->Handle == right->Handle);
	//}
	//bool Camera::operator != (Camera^ left, Camera^ right) {
	//	return !(left == right);
	//}


	//GET_FREE_CAM
	//GET_GAME_CAM
	//GET_GAME_CAM_CHILD
	//GET_ROOT_CAM
	//GET_SCRIPT_CAM
	//GET_SCRIPT_DRAW_CAM

}