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
#include "stdafx.h"

#include "vVehicleDoor.h"

#include "Vehicle.h"

#pragma managed

namespace GTA {
namespace value {

	VehicleDoor::VehicleDoor(Vehicle^ vehicle, GTA::VehicleDoor door) {
		this->vehicle = vehicle;
		this->door = door;
	}

	GTA::VehicleDoor VehicleDoor::Index::get() {
		return door;
	}

	bool VehicleDoor::isDamaged::get() {
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCarDoorDamaged(vehicle->Handle,(Scripting::eVehicleDoor)door);
	}

	float VehicleDoor::Angle::get() {
		OBJECT_NON_EXISTING_CHECK(vehicle,0.0f);
		f32 a;
		Scripting::GetDoorAngleRatio(vehicle->Handle, (Scripting::eVehicleDoor)door, &a);
		return a;
	}
	void VehicleDoor::Angle::set(float value) {
		OBJECT_NON_EXISTING_CHECK(vehicle);
		if (value > 1.0f) value = 1.0f;
		if (value > 0.001f)
			Scripting::ControlCarDoor(vehicle->Handle, (u32)door, 1, value);
		else 
			Close();
	}

	bool VehicleDoor::isFullyOpen::get() {
		OBJECT_NON_EXISTING_CHECK(vehicle,false);
		return Scripting::IsCarDoorFullyOpen(vehicle->Handle,(Scripting::eVehicleDoor)door);
	}

	bool VehicleDoor::isOpen::get() {
		return (Angle > 0.001f);
	}
	void VehicleDoor::isOpen::set(bool value) {
		if (value)
			Open();
		else 
			Close();
	}

	void VehicleDoor::Open() {
		OBJECT_NON_EXISTING_CHECK(vehicle);
		Scripting::OpenCarDoor(vehicle->Handle,(Scripting::eVehicleDoor)door);
	}
	void VehicleDoor::Close() {
		OBJECT_NON_EXISTING_CHECK(vehicle);
		Scripting::ShutCarDoor(vehicle->Handle,(Scripting::eVehicleDoor)door);
	}
	void VehicleDoor::Break() {
		OBJECT_NON_EXISTING_CHECK(vehicle);
		Scripting::BreakCarDoor(vehicle->Handle,(Scripting::eVehicleDoor)door, false);
	}

	VehicleDoor::operator GTA::VehicleDoor (GTA::value::VehicleDoor^ source) {
		return source->door;
	}

}
}