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

#include "Garage.h"

#include "Vehicle.h"
#include "World.h"

#pragma managed

namespace GTA {

	Garage::Garage(String^ Name) {
		this->pName = Name;
	}

	void Garage::DontAffectCamera::set(bool value) {
		char* ptr = PinStringA(pName);
		try {
			Scripting::SetGarageLeaveCameraAlone(ptr,value);
		} finally {
			FreeString(ptr);
		}
	}
	void Garage::Type::set(GarageType value) {
		char* ptr = PinStringA(pName);
		try {
			Scripting::ChangeGarageType(ptr,(int)value);
		} finally {
			FreeString(ptr);
		}
	}

	bool Garage::isClosed::get() {
		bool res = true;
		char* ptr = PinStringA(pName);
		try {
			res = Scripting::IsGarageClosed(ptr);
		} finally {
			FreeString(ptr);
		}
		return res;
	}
	bool Garage::isOpen::get() {
		bool res = false;
		char* ptr = PinStringA(pName);
		try {
			res = Scripting::IsGarageOpen(ptr);
		} finally {
			FreeString(ptr);
		}
		return res;
	}
	//void Garage::isOpen::set(bool value) {
	//	if (value)
	//		Open();
	//	else
	//		Close();
	//}

	void Garage::Open() {
		char* ptr = PinStringA(pName);
		try {
			Scripting::OpenGarage(ptr);
		} finally {
			FreeString(ptr);
		}
	}
	void Garage::Close() {
		char* ptr = PinStringA(pName);
		try {
			Scripting::CloseGarage(ptr);
		} finally {
			FreeString(ptr);
		}
	}

	bool Garage::isVehicleInside(Vehicle^ vehicle) {
		OBJECT_NON_EXISTING_CHECK(vehicle, false);
		bool res = false;
		char* ptr = PinStringA(pName);
		try {
			res = Scripting::IsCarInGarageArea(ptr, vehicle->Handle);
		} finally {
			FreeString(ptr);
		}
		return res;
	}

	array<Vehicle^>^ Garage::GetVehiclesInside() {
		List<Vehicle^>^ list = gcnew List<Vehicle^>();
		for each (Vehicle^ v in World::GetAllVehicles()) {
			if (isVehicleInside(v)) {
				list->Add(v);
			}
		}
		return list->ToArray();
	}

	void Garage::AbortAllGarageActivity() {
		Scripting::AbortAllGarageActivity();
	}	

}