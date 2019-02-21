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

#include "sModel.h"

#include "Game.h"

#pragma managed

namespace GTA{

	Model::Model(int Hash){
		pHash = Hash;
		pName = String::Empty;
	}
	Model::Model(UInt32 Hash){
		pHash = force_cast<int>(Hash);
		pName = String::Empty;
	}
	Model::Model(String^ ModelName){
		pName = ModelName;
		char* ptr = PinStringA(ModelName);
		try {
			pHash = force_cast<int>(Scripting::GetHashKey(ptr)); //GetModelHash(ptr);
		} finally {
			FreeString(ptr);
		}
	}

	unsigned int Model::Handle::get(){
		return force_cast<unsigned int>(pHash);
	}
	int Model::Hash::get(){
		return pHash;
	}

	//String^ Model::Name::get() {
	//	//GetStringFromHashKey(pHash)
	//	//if (pName == "") pName = gcnew String( Scripting::GetModelNameForDebug((Scripting::eModel)pHash) );
	//	if (pName == "") pName = gcnew String( Scripting::GetStringFromHashKey((Scripting::eModel)pHash) );
	//	return pName;
	//}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Model::isInMemory::get() {
		try {
			return Scripting::HasModelLoaded((Scripting::eModel)pHash);
		} catch(...) {
			return false;
		}
	}
	bool Model::isCollisionDataInMemory::get() {
		return Scripting::HasCollisionForModelLoaded((Scripting::eModel)pHash);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Model::isValid::get() {
		if (pHash == 0) return false;
		try {
			Scripting::HasModelLoaded((Scripting::eModel)pHash); // just a dummy to trigger an exception
			return true;
		} catch(...) {
			return false;
		}
	}

	//void Model::LoadToMemory(bool PriorizeRequest) {
	//	if (PriorizeRequest) Scripting::PrioritizeStreamingRequest();
	//	Scripting::RequestModel((Scripting::eModel)pHash);
	//}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void Model::LoadToMemory() {
		if (pHash == 0) return;
		try {
		   Scripting::RequestModel((Scripting::eModel)pHash);
		} catch (...) { }
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Model::LoadToMemoryNow(int timeout) {
		if (pHash == 0) return false;
		try {
			Scripting::RequestModel((Scripting::eModel)pHash);
			if (isInMemory) return true;

			if (Game::CanWaitNow) {

				DateTime maxtime;
				if (timeout >= 0)
					maxtime = DateTime::Now + TimeSpan(0,0,0,0,timeout);
				else
					maxtime = DateTime::MaxValue;

				while (!isInMemory) {
					Game::WaitInCurrentScript(0);
					Scripting::RequestModel((Scripting::eModel)pHash);
					if (DateTime::Now > maxtime) return false;
				}

			} else {
				return false;
			}
		} catch (...) { return false; }
		return true;
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void Model::LoadCollisionDataToMemory() {
		if (pHash == 0) return;
		try {
		   Scripting::RequestCollisionForModel((Scripting::eModel)pHash);
		} catch (...) { }
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	bool Model::LoadCollisionDataToMemoryNow(int timeout) {
		if (pHash == 0) return false;
		try {
			Scripting::RequestCollisionForModel((Scripting::eModel)pHash);
			if (isCollisionDataInMemory) return true;

			if (Game::CanWaitNow) {

				DateTime maxtime;
				if (timeout >= 0)
					maxtime = DateTime::Now + TimeSpan(0,0,0,0,timeout);
				else
					maxtime = DateTime::MaxValue;

				while (!isCollisionDataInMemory) {
					Game::WaitInCurrentScript(0);
					Scripting::RequestCollisionForModel((Scripting::eModel)pHash);
					if (DateTime::Now > maxtime) return false;
				}

			} else {
				return false;
			}
		} catch (...) { return false; }
		return true;
	}

	void Model::AllowDisposeFromMemory() {
		if (pHash == 0) return;
		Scripting::MarkModelAsNoLongerNeeded((Scripting::eModel)pHash);
	}

	void Model::GetDimensions(GTA::Vector3% MinVector, GTA::Vector3% MaxVector) {
		Scripting::Vector3 v1,v2;
		v1.X=0.0f; v1.Y=0.0f; v1.Z=0.0f;
		v2.X=0.0f; v2.Y=0.0f; v2.Z=0.0f;
		Scripting::GetModelDimensions((Scripting::eModel)pHash, &v1, &v2);
		MinVector.X = v1.X; MinVector.Y = v1.Y; MinVector.Z = v1.Z;
		MaxVector.X = v2.X; MaxVector.Y = v2.Y; MaxVector.Z = v2.Z;
	}

	GTA::Vector3 Model::GetDimensions() {
		Scripting::Vector3 v1,v2;
		v1.X=0.0f; v1.Y=0.0f; v1.Z=0.0f;
		v2.X=0.0f; v2.Y=0.0f; v2.Z=0.0f;
		Scripting::GetModelDimensions((Scripting::eModel)pHash, &v1, &v2);
		return GTA::Vector3(v2.X - v1.X, v2.Y - v1.Y, v2.Z - v1.Z);
	}


	bool Model::isBike::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelABike((Scripting::eModel)pHash);
	}
	bool Model::isBoat::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelABoat((Scripting::eModel)pHash);
	}
	bool Model::isCar::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelACar((Scripting::eModel)pHash);
	}
	bool Model::isHelicopter::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelAHeli((Scripting::eModel)pHash);
	}
	bool Model::isPed::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelAPed((Scripting::eModel)pHash);
	}
	bool Model::isPlane::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelAPlane((Scripting::eModel)pHash);
	}
	bool Model::isTrain::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelATrain((Scripting::eModel)pHash);
	}
	bool Model::isVehicle::get() {
		if (pHash == 0) return false;
		return Scripting::IsThisModelAVehicle((Scripting::eModel)pHash);
	}



	Model Model::BasicCopModel::get() {
		Scripting::eModel val;
		Scripting::GetCurrentBasicCopModel(&val);
		return Model( (int)val );
	}
	Model Model::CurrentCopModel::get() {
		Scripting::eModel val;
		Scripting::GetCurrentCopModel(&val);
		return Model( (int)val );
	}
	Model Model::BasicPoliceCarModel::get() {
		Scripting::eModel val;
		Scripting::GetCurrentBasicPoliceCarModel(&val);
		return Model( (int)val );
	}
	Model Model::CurrentPoliceCarModel::get() {
		Scripting::eModel val;
		Scripting::GetCurrentPoliceCarModel(&val);
		return Model( (int)val );
	}
	Model Model::TaxiCarModel::get(){
		Scripting::eModel val;
		Scripting::GetCurrentTaxiCarModel(&val);
		return Model( (int)val );
	}

	Model Model::GetWeaponModel(GTA::Weapon weapon) {
		i32 val;
		Scripting::GetWeaponTypeModel((i32)weapon, &val);
		return Model( (int)val );
	}

	bool Model::operator == (Model left, Model right) {
		return (left.pHash == right.pHash);
	}
	bool Model::operator != (Model left, Model right) {
		return !(left == right);
	}
	Model::operator Model (String^ source) {
		return Model(source);
	}
	Model::operator Model (int source) {
		return Model(source);
	}
	Model::operator Model (UInt32 source) {
		return Model(source);
	}

	Model Model::FromString(String^ string) {
		return Helper::StringToModel(string, Model(0));
	}

	String^ Model::ToString() {
		if (isNULL(pName) || (pName->Length == 0))
			return ("0x"+Helper::ToHex(pHash));
		else
			return pName;
	}

}