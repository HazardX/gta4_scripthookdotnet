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

#include "Object.h"

#include "ContentCache.h"
#include "Blip.h"
#include "Game.h"
#include "MemoryAccess.h"
#include "Ped.h"
#include "Vehicle.h"

#pragma managed

namespace GTA {

	GTA::Object::Object(int Handle)
		:HandleObject(Handle) {
	}

	int GTA::Object::MemoryAddress::get(){
		return unmanaged::MemoryAccess::GetAddressOfObject(pHandle);
	}

	GTA::Model GTA::Object::Model::get() {
		NON_EXISTING_CHECK(nullptr);
		Scripting::eModel model;
		Scripting::GetObjectModel(pHandle, &model);
		return GTA::Model((int)model);
	}

	Vector3 GTA::Object::Position::get(){
		NON_EXISTING_CHECK(V3_NaN);
		float x,y,z;
		Scripting::GetObjectCoordinates(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void GTA::Object::Position::set(Vector3 value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetObjectCoordinates(pHandle,value.X,value.Y,value.Z);
	}

	Vector3 GTA::Object::Rotation::get(){
		NON_EXISTING_CHECK(V3_NULL);
		//float x,y,z;
		//Scripting::GetObjectRotation(pHandle,&x,&y,&z);
		//return Vector3(x,y,z);
		return RotationQuaternion.ToRotation();
	}
	void GTA::Object::Rotation::set(Vector3 value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetObjectRotation(pHandle,value.X,value.Y,value.Z);
	}

	Quaternion GTA::Object::RotationQuaternion::get(){
		NON_EXISTING_CHECK(Quaternion());
		float x,y,z,w;
		Scripting::GetObjectQuaternion(pHandle,&x,&y,&z,&w);
		return Quaternion(x,y,z,w);
	}
	void GTA::Object::RotationQuaternion::set(Quaternion value){
		NON_EXISTING_CHECK();
		unmanaged::Native::SetObjectQuaternion(pHandle,value.X,value.Y,value.Z,value.W);
	}

	Room GTA::Object::CurrentRoom::get(){
		NON_EXISTING_CHECK(Room(0,0));
		//Scripting::eInterior ii;
		Scripting::eInteriorRoomKey rk;
		//Scripting::GetInteriorFromObject(pHandle,&ii);
		Scripting::GetRoomKeyFromObject(pHandle,&rk);
		return Room(force_cast<int>(rk),force_cast<int>(0));
	}
	void GTA::Object::CurrentRoom::set(Room value) {
		NON_EXISTING_CHECK();
		Scripting::AddObjectToInteriorRoomByKey(pHandle,force_cast<u32>(value.RoomKey));
	}

	float GTA::Object::Heading::get(){
		NON_EXISTING_CHECK(0.0f);
		f32 val;
		Scripting::GetObjectHeading(pHandle,&val);
		return val;
	}
	void GTA::Object::Heading::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetObjectHeading(pHandle,value);
	}
	Vector3 GTA::Object::Direction::get(){
		return Game::HeadingToDirection(Heading);
	}

	Vector3 GTA::Object::Velocity::get() {
		NON_EXISTING_CHECK(V3_NULL);
		float x,y,z;
		Scripting::GetObjectVelocity(pHandle,&x,&y,&z);
		return Vector3(x,y,z);
	}
	void GTA::Object::Velocity::set(Vector3 value){
		NON_EXISTING_CHECK();
		ApplyForce(value-Velocity);
	}


	bool GTA::Object::isAttachedSomewhere::get() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsObjectAttached(pHandle);
	}

	bool GTA::Object::isOnFire::get() {
		NON_EXISTING_CHECK(false);
		return Scripting::IsObjectOnFire(pHandle);
	}
	void GTA::Object::isOnFire::set(bool value) {
		NON_EXISTING_CHECK();
		if (value) {
			int fire = Scripting::StartObjectFire(pHandle);
			if (fire == 0) return;
			ContentCache::GetFire(fire, true);
		} else {
			Scripting::ExtinguishObjectFire(pHandle);
		}
	}

	void GTA::Object::Visible::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetObjectVisible(pHandle,value);
	}

	void GTA::Object::Collision::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetObjectCollision(pHandle,value);
	}
	void GTA::Object::RecordCollisions::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetObjectRecordsCollisions(pHandle,value);
	}
	void GTA::Object::Dynamic::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetObjectDynamic(pHandle,value);
	}

	void GTA::Object::FreezePosition::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::FreezeObjectPosition(pHandle,value);
	}


	GTA::Vector3 GTA::Object::GetOffsetPosition(GTA::Vector3 Offset) {
		NON_EXISTING_CHECK(V3_NULL);
		float x = 0.0f; float y = 0.0f; float z = 0.0f;
		Scripting::GetOffsetFromObjectInWorldCoords(pHandle, Offset.X, Offset.Y, Offset.Z, &x, &y, &z);
		return GTA::Vector3(x,y,z);
	}


	Blip^ GTA::Object::AttachBlip() {
		NON_EXISTING_CHECK(nullptr);
		return Blip::AddBlip(this);
	}

	void GTA::Object::AttachToPed(Ped^ ped, Bone bone, Vector3 PositionOffset, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(ped);
		CurrentRoom = ped->CurrentRoom;
		if (isAttachedSomewhere) Detach();
		Scripting::AttachObjectToPed(pHandle, ped->Handle, (u32)bone, PositionOffset.X, PositionOffset.Y, PositionOffset.Z, Rotation.X, Rotation.Y, Rotation.Z, 0);
	}
	void GTA::Object::AttachToVehicle(Vehicle^ vehicle, Vector3 PositionOffset, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(vehicle);
		//CurrentRoom = vehicle->CurrentRoom;
		if (isAttachedSomewhere) Detach();
		Scripting::AttachObjectToCar(pHandle, vehicle->Handle, 0, PositionOffset.X, PositionOffset.Y, PositionOffset.Z, Rotation.X, Rotation.Y, Rotation.Z);
	}

	void GTA::Object::ApplyForce(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToObject(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 0, 1, 1);
	}
	void GTA::Object::ApplyForce(Vector3 Direction) {
		ApplyForce(Direction,Vector3());
	}

	void GTA::Object::ApplyForceRelative(Vector3 Direction, Vector3 Rotation) {
		NON_EXISTING_CHECK();
		unmanaged::Native::ApplyForceToObject(pHandle, 3, Direction.X, Direction.Y, Direction.Z, Rotation.X, Rotation.Y, Rotation.Z, 0 , 1, 1, 1);
	}
	void GTA::Object::ApplyForceRelative(Vector3 Direction) {
		ApplyForceRelative(Direction,Vector3());
	}

	void GTA::Object::Delete() {
		NON_EXISTING_CHECK_RELAXED();
		SetExistsFalse();
		if (pHandle == 0) return;
		int obj = pHandle;
		unmanaged::Native::DeleteObject(&obj);
		//pHandle = 0;
	}
	void GTA::Object::Detach() {
		NON_EXISTING_CHECK();
		Scripting::DetachObject(pHandle,true);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool GTA::Object::InternalCheckExists() {
		if (pHandle == 0) return false;
		try {
			return unmanaged::Native::DoesObjectExist(pHandle);
		} catch (...) {
			return false;
		}
	}
	void GTA::Object::NoLongerNeeded() {
		NON_EXISTING_CHECK_RELAXED();
		int h = pHandle;
		Scripting::MarkObjectAsNoLongerNeeded(&h);
	}

}