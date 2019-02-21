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

#include "World.h"

#include "ContentCache.h"
#include "MemoryAccess.h"
#include "Ped.h"
#include "Vehicle.h"

#pragma managed

namespace GTA{

	GTA::Weather World::Weather::get(){
		Scripting::eWeather w;
		Scripting::GetCurrentWeather(&w);
		return (GTA::Weather)w;
	}
	void World::Weather::set(GTA::Weather value){
		Scripting::ForceWeather((Scripting::eWeather)value);
		//Scripting::ReleaseWeather();
	}

	int World::GetDayDiff(TimeSpan time) {
      if (time.Ticks >= 0) return time.Days;
	   int d = time.Days;
      time += TimeSpan(-d, 0, 0, 0);
      if (time.Ticks < 0) return (d - 1);
      return d;
	}
	TimeSpan World::GetTimeOfDay(TimeSpan time) {
      if (time.Ticks >= 0) return TimeSpan(time.Hours, time.Minutes, time.Seconds);
      TimeSpan tod = TimeSpan(-time.Days + 1, 0, 0, 0);
      tod += time;
      return tod;
	}

	TimeSpan World::CurrentDayTime::get(){
		u32 h, m;
		Scripting::GetTimeOfDay(&h, &m);
		return TimeSpan(h,m,0);
	}
	void World::CurrentDayTime::set(TimeSpan value){
		int d = GetDayDiff(value);
		if (d > 0) {
			for (int i = 0; i < d; i++) {
				Scripting::SetTimeOneDayForward();
			}
		} else if (d < 0) {
			for (int i = 0; i > d; i--) {
				Scripting::SetTimeOneDayBack();
			}
		}
		value = GetTimeOfDay(value);
		Scripting::SetTimeOfDay(value.Hours, value.Minutes);
	}

	DateTime World::CurrentDate::get(){
		u32 month, day, hour, minute;
		Scripting::GetTimeOfDay(&hour, &minute);
		Scripting::GetCurrentDate(&day, &month);
		return DateTime(pBaseYear,month,day,hour,minute,0);
	}
	//void World::CurrentDateAndTime::set(DateTime value){
	//	TimeSpan diff = value-CurrentDateAndTime;

	//	int d = diff.Days;
	//	if (d > 0) {
	//		for (int i = 0; i < d; i++) {
	//			Scripting::SetTimeOneDayForward();
	//		}
	//		value -= TimeSpan(d,0,0,0);
	//	} else if (d < 0) {
	//		for (int i = 0; i > d; i--) {
	//			Scripting::SetTimeOneDayBack();
	//		}
	//		value += TimeSpan(-d,0,0,0);
	//	}
	//	Scripting::SetTimeOfDay(value.Hour, value.Minute);
	//}


	void World::CarDensity::set(float value){
		Scripting::SetCarDensityMultiplier(value);
	}
	void World::PedDensity::set(float value){
		Scripting::SetPedDensityMultiplier(value);
	}

	void World::GravityEnabled::set(bool value){
		Scripting::SetGravityOff(!value);
	}

	void World::OneDayForward() {
		Scripting::SetTimeOneDayForward();
	}
	void World::LockDayTime(TimeSpan LockedTime) {
		if (LockedTime.Ticks < 0) return;
		Scripting::ForceTimeOfDay(LockedTime.Hours, LockedTime.Minutes);
	}
	void World::LockDayTime(int Hour, int Minute) {
		if ( (Hour < 0) || (Hour > 23)  ) return;
		if ( (Minute < 0) || (Minute > 59)  ) return;
		Scripting::ForceTimeOfDay(Hour, Minute);
	}
	void World::LockDayTime() {
		Scripting::eWeather w;
		Scripting::GetCurrentWeather(&w);
		LockDayTime(CurrentDayTime);
		Scripting::ForceWeatherNow(w); //ForceWeatherNow
		//Scripting::ReleaseWeather();
	}
	void World::UnlockDayTime() {
		Scripting::ReleaseTimeOfDay();
	}


	void World::LoadEnvironmentNow(GTA::Vector3 Position) {
		unmanaged::Native::RequestCollisionAtPosn(Position.X, Position.Y, Position.Z);
		unmanaged::Native::LoadAllObjectsNow();
		unmanaged::Native::LoadScene(Position.X, Position.Y, Position.Z); // WARNING: causes a call to OnRender and thus a Deadlock! // Fine now due to deadlock protection
		unmanaged::Native::PopulateNow();
	}


	void World::AddExplosion(Vector3 Position, ExplosionType Type, float Power, bool PlaySound, bool NoVisuals, float CameraShake) {
		unmanaged::Native::AddExplosion(Position.X, Position.Y, Position.Z, (u32)Type, Power, PlaySound, NoVisuals, CameraShake);//13, 4.0, 0, 0, 1.0 //3, 1.00, 1, 0, 1065353216
	}
	void World::AddExplosion(Vector3 Position, ExplosionType Type, float Power) {
		AddExplosion(Position, Type, Power, true, false, 1.0f);
	}
	void World::AddExplosion(Vector3 Position) {
		AddExplosion(Position, ExplosionType::Default, 1.0f, true, false, 1.0f);
	}

	void World::DrawCheckpoint(Vector3 Position, float Diameter, Drawing::Color Color) {
		Scripting::DrawCheckpointWithAlpha(Position.X, Position.Y, Position.Z, Diameter, Color.R, Color.G, Color.B, Color.A);
	}
	void World::DrawLight(Vector3 Position, Drawing::Color Color, float Range, float Intensity) {
		Scripting::DrawLightWithRange(Position.X, Position.Y, Position.Z, Color.R, Color.G, Color.B, Range, Intensity);
	}

	array<int>^ World::GetValidPedHandles(GTA::Model Model) {
		if (!NetHook::isPrimary) {
			System::Object^ res = NetHook::RaiseEventInLocalScriptDomain(RemoteEvent::GetValidPedHandles, Model);
			if (isNULL(res) || (res->GetType() != array<int>::typeid)) return gcnew array<int>(0);
			return (array<int>^)res;
		}

		List<int>^ list = gcnew List<int>();
		array<int>^ handles = unmanaged::MemoryAccess::GetPedHandleList();
		int model = 0; int findmodel = Model.Hash; 

		for (int i = 0; i < handles->Length; i++) {
			if (Scripting::DoesCharExist(handles[i])) {
				model = 0;
				Scripting::GetCharModel(handles[i], &model);
				if ( (model != 0) && ((findmodel == 0) || (findmodel == model)) ) {
					list->Add(handles[i]);
				}
			}
		}

		return list->ToArray();
	}

	array<int>^ World::GetValidVehicleHandles(GTA::Model Model) {
		if (!NetHook::isPrimary) {
			System::Object^ res = NetHook::RaiseEventInLocalScriptDomain(RemoteEvent::GetValidVehicleHandles, Model);
			if (isNULL(res) || (res->GetType() != array<int>::typeid)) return gcnew array<int>(0);
			return (array<int>^)res;
		}

		List<int>^ list = gcnew List<int>();
		array<int>^ handles = unmanaged::MemoryAccess::GetVehicleHandleList();
		int model = 0; int findmodel = Model.Hash; 

		for (int i = 0; i < handles->Length; i++) {
			if (Scripting::DoesVehicleExist(handles[i])) {
				model = 0;
				Scripting::GetCarModel2(handles[i], &model);
				if ( (model != 0) && ((findmodel == 0) || (findmodel == model)) ) { // && (Scripting::DoesVehicleExist(handles[i]))
					list->Add(handles[i]);
				}
			}
		}

		return list->ToArray();
	}

	array<int>^ World::GetValidObjectHandles(GTA::Model Model) {
		if (!NetHook::isPrimary) {
			System::Object^ res = NetHook::RaiseEventInLocalScriptDomain(RemoteEvent::GetValidObjectHandles, Model);
			if (isNULL(res) || (res->GetType() != array<int>::typeid)) return gcnew array<int>(0);
			return (array<int>^)res;
		}

		List<int>^ list = gcnew List<int>();
		array<int>^ handles = unmanaged::MemoryAccess::GetObjectHandleList();
		int model = 0; int findmodel = Model.Hash; 

		for (int i = 0; i < handles->Length; i++) {
			if (Scripting::DoesObjectExist(handles[i]))  {
				model = 0;
				Scripting::GetObjectModel2(handles[i], &model);
				if ( (model != 0) && ((findmodel == 0) || (findmodel == model)) ) { // && (Scripting::DoesObjectExist(handles[i]))
					list->Add(handles[i]);
				}
			}
		}
		return list->ToArray();
	}

	//Ped^ World::GetClosestPed(Vector3 Position, float Radius, int UnknownValue1, int UnknownValue2) {
	//	int ped;
	//	Scripting::BeginCharSearchCriteria();
	//	Scripting::EndCharSearchCriteria();
	//	//Scripting::AllowScenarioPedsToBeReturnedByNextCommand(true);
	//	unmanaged::Native::GetClosestChar(Position.X, Position.Y, Position.Z, Radius, (u32)UnknownValue1, (u32)UnknownValue2, &ped);
	//	if (ped == 0) return nullptr;
	//	return ContentCache::GetPed(ped);
	//}
	Ped^ World::GetClosestPed(Vector3 Position, float Radius) {
		int ped;
		Scripting::BeginCharSearchCriteria();
		Scripting::EndCharSearchCriteria();
		//Scripting::AllowScenarioPedsToBeReturnedByNextCommand(true);
		unmanaged::Native::GetClosestChar(Position.X, Position.Y, Position.Z, Radius, true, true, &ped); //true, false
		if (ped == 0) return nullptr;
		return ContentCache::GetPed(ped);
	}

	Ped^ World::GetRandomPed(Vector3 Position, float Radius) {
		int ped;
		Scripting::BeginCharSearchCriteria();
		Scripting::EndCharSearchCriteria();
		//Scripting::AllowScenarioPedsToBeReturnedByNextCommand(true);
		unmanaged::Native::GetRandomCharInAreaOffsetNoSave(Position.X-Radius, Position.Y-Radius, Position.Z-Radius, Radius*2.0f, Radius*2.0f, Radius*2.0f, &ped);
		if (ped == 0) return nullptr;
		return ContentCache::GetPed(ped);
	}



	array<Ped^>^ World::GetPeds(Vector3 Position, float Radius, int MaxAmount) {
		List<Ped^>^ list = gcnew List<Ped^>();
		Ped^ p;
		array<int>^ handles = GetValidPedHandles(Model::Null);

		for (int i = 0; i < handles->Length; i++) {
			p = ContentCache::GetPed(handles[i]);
			if (p->Position.DistanceTo(Position) <= Radius) {
				list->Add(p);
				if (list->Count >= MaxAmount) return list->ToArray();
			}
		}
		return list->ToArray();
	}
	array<Ped^>^ World::GetPeds(Vector3 Position, float Radius) {
		return GetPeds(Position, Radius, int::MaxValue);
	}

	array<Ped^>^ World::GetAllPeds(GTA::Model Model) {
		array<int>^ handles = GetValidPedHandles(Model);
		array<Ped^>^ list = gcnew array<Ped^>(handles->Length);
		for (int i = 0; i < handles->Length; i++) {
			list[i] = ContentCache::GetPed(handles[i]);
			//if ( (!list[i]->Exists()) || (list[i]->MemoryAddress == 0) || (!list[i]->Exists()) ) list[i] = nullptr;
		}
		return list;
	}
	array<Ped^>^ World::GetAllPeds() {
		return GetAllPeds(Model::Null);
	}
	
	array<Vehicle^>^ World::GetVehicles(Vector3 Position, float Radius, GTA::Model Model) {
		List<Vehicle^>^ list = gcnew List<Vehicle^>();
		Vehicle^ v;
		array<int>^ handles = GetValidVehicleHandles(Model);
		for (int i = 0; i < handles->Length; i++) {
			v = ContentCache::GetVehicle(handles[i]);
			if (v->Position.DistanceTo(Position) <= Radius) list->Add(v);
		}
		return list->ToArray();
	}
	array<Vehicle^>^ World::GetVehicles(Vector3 Position, float Radius) {
		return GetVehicles(Position, Radius, Model::Null);
	}

	array<Vehicle^>^ World::GetAllVehicles(GTA::Model Model) {
		array<int>^ handles = GetValidVehicleHandles(Model);
		array<Vehicle^>^ list = gcnew array<Vehicle^>(handles->Length);
		for (int i = 0; i < handles->Length; i++) {
			list[i] = ContentCache::GetVehicle(handles[i]);
		}
		return list;
	}
	array<Vehicle^>^ World::GetAllVehicles() {
		return GetAllVehicles(Model::Null);
	}


	Vehicle^ World::GetClosestVehicle(Vector3 Position, float Radius, GTA::Model Model) {
		Vehicle^ cv = nullptr;
		Vehicle^ v;	
		float cd = float::MaxValue;
		float dist;

				//NetHook::Log("Do GetValidVehicleHandles...");


		array<int>^ handles = GetValidVehicleHandles(Model);

				//NetHook::Log("GetValidVehicleHandles done!");

				//try {

		for (int i = 0; i < handles->Length; i++) {
			//NetHook::Log("GetVehicle " + i.ToString() + "...");
			v = ContentCache::GetVehicle(handles[i]);
			//NetHook::Log("...and position...");
			dist = v->Position.DistanceTo(Position);
			//NetHook::Log("...done!");
			if ( (dist <= Radius) && (dist < cd) ) {
				cv = v;
				cd = dist;
			}
		}

				//} catchErrors("Error during GetClosestVehicle",)

		//NetHook::Log("GetClosestVehicle done!");

		return cv;
	}
	Vehicle^ World::GetClosestVehicle(Vector3 Position, float Radius) {
		return GetClosestVehicle(Position, Radius, Model::Null);
	}

	array<GTA::Object^>^ World::GetAllObjects(GTA::Model Model) {
		array<int>^ handles = GetValidObjectHandles(Model);
		array<GTA::Object^>^ list = gcnew array<GTA::Object^>(handles->Length);
		for (int i = 0; i < handles->Length; i++) {
			list[i] = ContentCache::GetObject(handles[i]);
		}
		return list;
	}
	array<GTA::Object^>^ World::GetAllObjects() {
		return GetAllObjects(Model::Null);
	}

	float World::GetGroundZBelow(float x, float y, float z) {
		f32 resZ = z;
		Scripting::GetGroundZFor3DCoord(x, y, z, &resZ);
		//if (resZ > (z-1.0f)) return z;
		return resZ;
	}
	float World::GetGroundZAbove(float x, float y, float z) {
		if (z < 0.0f) z = 0.0f;
		float lastZ, resZ;
		for (int i = 0; i<=10; i++) {
			lastZ = z+(float)System::Math::Pow(2.0,(double)i);
			resZ = GetGroundZBelow(x, y, lastZ);
			if ((resZ < lastZ) && (resZ > z)) return resZ;
		}
		return z;
	}
	float World::GetGroundZNext(float x, float y, float z) {
		if (z < 0.0f) z = 0.0f;
		float lastZ, resZ;
		for (int i = 0; i<=10; i++) {
			lastZ = z+(float)System::Math::Pow(2.0,(double)i);
			resZ = GetGroundZBelow(x, y, lastZ);
			if ((resZ < lastZ) && (resZ > 0.0f)) return resZ;
		}
		return z;
	}
	float World::GetGroundZ(Vector3 Position, GroundType Type) {
		switch (Type) {
			case GroundType::Highest: {
				return GetGroundZBelow(Position.X, Position.Y, 1024.0f);
			}
			case GroundType::Lowest: {
				return GetGroundZAbove(Position.X, Position.Y, 0.0f);
			}
			case GroundType::NextBelowCurrent: {
				return GetGroundZBelow(Position.X, Position.Y, Position.Z);
			}
			case GroundType::NextAboveCurrent: {
				return GetGroundZAbove(Position.X, Position.Y, Position.Z);
			}
			//case GroundType::Closest:
			default:
				return GetGroundZNext(Position.X, Position.Y, Position.Z); //+5.0f
				//float resZ = GetGroundZBelow(Position.X, Position.Y, Position.Z);
				//if (resZ < Position.Z) return resZ;
				//return GetGroundZAbove(Position.X, Position.Y, Position.Z);
			
		}
	}
	float World::GetGroundZ(Vector3 Position) {
		return GetGroundZ(Position, GroundType::Closest);
	}
	Vector3 World::GetGroundPosition(Vector3 Position, GroundType Type) {
		float z = GetGroundZ(Position, Type);
		return GTA::Vector3(Position.X, Position.Y, z);
	}
	Vector3 World::GetGroundPosition(Vector3 Position) {
		return GetGroundPosition(Position, GroundType::Closest);
	}

	Vector3 World::GetNextPositionOnPavement(Vector3 Position) {
		f32 x,y,z;
		Scripting::GetSafePositionForChar(Position.X, Position.Y, Position.Z, true, &x, &y, &z);
		return Vector3(x,y,z);
	}
	///
	Vector3 World::GetNextPositionOnStreet(Vector3 Position) {
		f32 x,y,z,h;
		u32 inarea, outarea;
		Vector3 p = Position;
		inarea = Scripting::GetMapAreaFromCoords(p.X,p.Y,p.Z);

		Scripting::GetNthClosestCarNodeWithHeadingOnIsland(p.X,p.Y,p.Z,1,inarea,&x,&y,&z,&h,&outarea);
		return Vector3(x,y,z);

		//Vector3 curpos;
		//float curlen;
		//Vector3 closestpos;
		//float closest = 99999.0f;

		//for (int i = 1; i<40; i++) {
		//	Scripting::GetNthClosestCarNodeWithHeadingOnIsland(p.X,p.Y,p.Z,i,inarea,&x,&y,&z,&h,&outarea);
		//	curpos = Vector3(x,y,z);
		//	curlen = (curpos-Position).Length();
		//	if (curlen<closest) {
		//		closest = curlen;
		//		closestpos = curpos;
		//	}
		//}
		//return closestpos; //Vector3(x,y,z);
	}
	Vector3 World::GetPositionAround(Vector3 Position, float Distance) {
		return Position + Vector3::RandomXY() * Distance;
	}

	String^ World::GetStreetName(Vector3 Position) {
		u32 strHash0, strHash1;
		Scripting::FindStreetNameAtPosition(Position.X, Position.Y, Position.Z, &strHash0, &strHash1);
		String^ str1 = (gcnew String(Scripting::GetStringFromHashKey(strHash0)))->Trim();
		String^ str2 = (gcnew String(Scripting::GetStringFromHashKey(strHash1)))->Trim();
		if (str1->Length == 0) return str2;
		if (str2->Length == 0) return str1;
		return String::Concat( str1, ", ", str2 );
	}
	String^ World::GetZoneName(Vector3 Position) {
		//return gcnew String( Scripting::GetNameOfZone(Position.X, Position.Y, Position.Z) );
		return gcnew String( Scripting::GetNameOfInfoZone(Position.X, Position.Y, Position.Z) );
	}
	//Room World::GetRoomAt(Vector3 Position) {
	//	Scripting::Interior res = 0;
	//	Scripting::GetInteriorAtCoords(Position.X, Position.Y, Position.Z, &res);
	//	return Room(res);
	//}

	bool World::isPositionBlockedByMissionEntity(Vector3 Position, float Radius) {
		float diam = Radius * 2.0f;
		return Scripting::IsPointObscuredByAMissionEntity(Position.X, Position.Y, Position.Z, diam, diam, diam);
	}

	void World::SetGroupRelationship(GTA::RelationshipGroup group, Relationship level, GTA::RelationshipGroup targetgroup) {
		Scripting::AllowGangRelationshipsToBeChangedByNextCommand(true);
		Scripting::SetRelationship((int)level,(int)group,(int)targetgroup);
	}

	ScriptedFire^ World::StartFire(Vector3 Position, int Unknown1, int Unknown2) {
		int fire = unmanaged::Native::StartScriptFire(Position.X, Position.Y, Position.Z, Unknown1, Unknown2);
		if (fire == 0) return nullptr;
		return ContentCache::GetFire(fire, true);
	}
	ScriptedFire^ World::StartFire(Vector3 Position) {
		return StartFire(Position,1,1);
	}
	void World::ExtinguishFire(Vector3 Position, float Radius) {
		Scripting::ExtinguishFireAtPoint(Position.X, Position.Y, Position.Z, Radius);
	}
	void World::ExtinguishAllScriptFires() {
		Scripting::RemoveAllScriptFires();
	}

	void World::UnlockAllIslands() {
		Scripting::SetIntStat(363,3); //STAT_ISLANDS_UNLOCKED
	}

	void World::TriggerCollisionsAt(Vector3 Position) {
		unmanaged::Native::RequestCollisionAtPosn(Position.X, Position.Y, Position.Z);
	}

	void World::SetDoorState(Model model, Vector3 pos, bool locked, float angle) {
		unmanaged::Native::SetStateOfClosestDoorOfType(model.Hash, pos.X, pos.Y, pos.Z, locked, angle);
	}

	Ped^ World::CreatePed(Vector3 Position, GTA::Gender Gender) {
		int ped;
		if (Gender == GTA::Gender::Male) {
			unmanaged::Native::CreateRandomMaleChar(Position.X,Position.Y,Position.Z,&ped);
		} else {
			unmanaged::Native::CreateRandomFemaleChar(Position.X,Position.Y,Position.Z,&ped);
		}
		if (ped == 0) return nullptr;
		Ped^ res = ContentCache::GetPed(ped);
		//res->CurrentRoom = GetRoomAt(Position);
		return res;
	}
	Ped^ World::CreatePed(Vector3 Position) {
		int ped;
		unmanaged::Native::CreateRandomChar(Position.X,Position.Y,Position.Z,&ped);
		if (ped == 0) return nullptr;
		Ped^ res = ContentCache::GetPed(ped);
		//res->CurrentRoom = GetRoomAt(Position);
		return res;
	}
	Ped^ World::CreatePed(GTA::Model Model, Vector3 Position, RelationshipGroup Type) {
		if (!Model.isPed) return nullptr;
		if (!Model.LoadToMemoryNow()) return nullptr;
		int ped = 0;
		unmanaged::Native::CreateChar((int)Type, Model.Hash, Position.X, Position.Y, Position.Z, &ped, true);
		Model.AllowDisposeFromMemory();
		if (ped == 0) return nullptr;
		Ped^ res = ContentCache::GetPed(ped);
		//res->CurrentRoom = GetRoomAt(Position);
		return res;
	}
	Ped^ World::CreatePed(GTA::Model Model, Vector3 Position) {
		Ped^ res = CreatePed(Model, Position, RelationshipGroup::Civillian_Male);
		if isNULL(res) return nullptr;
		if (res->Gender == Gender::Female) res->RelationshipGroup = RelationshipGroup::Civillian_Female;
		return res;
	}

	Vehicle^ World::CreateVehicle(Vector3 Position) {
		int car;
		u32 model;
		Scripting::ScriptAny unknown;
		Scripting::GetRandomCarModelInMemory(true,&model,&unknown);
		unmanaged::Native::CreateCar(model,Position.X,Position.Y,Position.Z,&car,true);
		if (car == 0) return nullptr;
		return ContentCache::GetVehicle(car);
	}

	Vehicle^ World::CreateVehicle(GTA::Model Model, Vector3 Position) {
		if (!Model.isVehicle) return nullptr;
		if (!Model.LoadToMemoryNow()) return nullptr;
		int car;
		unmanaged::Native::CreateCar(Model.Handle,Position.X,Position.Y,Position.Z,&car,true);
		Model.AllowDisposeFromMemory();
		if (car == 0) return nullptr;
		return ContentCache::GetVehicle(car);
	}
	Vehicle^ World::CreateMissionTrain(Vector3 Position) {
		GTA::Model Model = GTA::Model(0x2FBC4D30);
		if (!Model.LoadToMemoryNow()) return nullptr;
		int car;
		unmanaged::Native::CreateMissionTrain(0,Position.X,Position.Y,Position.Z,true,&car);
		Model.AllowDisposeFromMemory();
		if (car == 0) return nullptr;
		return ContentCache::GetVehicle(car);
	}

	GTA::Object^ World::CreateObject(GTA::Model Model, Vector3 Position) {
		if (!Model.LoadToMemoryNow()) return nullptr;
		//Model.LoadCollisionDataToMemoryNow();
		int obj;
		unmanaged::Native::CreateObject((Scripting::eModel)Model.Hash,Position.X,Position.Y,Position.Z,&obj,true);
		Model.AllowDisposeFromMemory();
		if (obj == 0) return nullptr;
		return ContentCache::GetObject(obj);
	}

}