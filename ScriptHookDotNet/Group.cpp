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

#include "Group.h"

#include "ContentCache.h"
#include "PedCollection.h"
#include "Ped.h"
#include "Vehicle.h"
#include "vTasks.h"

#pragma managed

namespace GTA{

	Group::Group(int Handle)
		: HandleObject(Handle) {
		//pHandle = Handle;
	}
	Group::Group(Ped^ Leader)
		: HandleObject(0) {
		int g;
		Scripting::CreateGroup(false,&g,true);
		pHandle = g;
		this->Leader = Leader;
		ContentCache::AddGroup(this, true);
	}

	//int Group::Handle::get(){
	//	return pHandle;
	//}

	void Group::SetHandle(int Handle, bool CreatedByMe) {
		ContentCache::RemoveGroup(this);
		pHandle = Handle;
		ResetExists();
		ContentCache::AddGroup(this, CreatedByMe);
	}

	Ped^ Group::Leader::get(){
		NON_EXISTING_CHECK(nullptr);
		int p;
		Scripting::GetGroupLeader(pHandle,&p);
		if (p == 0) return nullptr;
		return ContentCache::GetPed(p);
	}
	void Group::Leader::set(Ped^ value){
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(value);
		Scripting::SetGroupLeader(pHandle,value->Handle);
	}

	int Group::MemberCount::get(){
		NON_EXISTING_CHECK(0);
		u32 s,c; // s is ALWAYS 1, maybe LeaderCount
		Scripting::GetGroupSize(pHandle,&s,&c);
		return c;
	}
	int Group::MaxMemberCount::get(){
		return MAX_GROUP_SIZE;
	}
	//int Group::MemberIndex::get(){
	//	u32 s,c;
	//	Scripting::GetGroupSize(pHandle,&s,&c);
	//	return s;
	//}


	bool Group::isLeader(Ped^ ped) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(ped, false);
		return Scripting::IsGroupLeader(ped->Handle,pHandle);
	}
	bool Group::isMember(Ped^ ped) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(ped, false);
		return Scripting::IsGroupMember(ped->Handle,pHandle);
	}
	bool Group::AddMember(Ped^ ped, bool NeverLeave) {
		NON_EXISTING_CHECK(false);
		OBJECT_NON_EXISTING_CHECK(ped, false);
		if (MemberCount >= MaxMemberCount) return false;
		Scripting::SetGroupMember(pHandle,ped->Handle);
		if (NeverLeave) Scripting::SetCharNeverLeavesGroup(ped->Handle,true);
		return true;
	}
	bool Group::AddMember(Ped^ ped) {
		return AddMember(ped,false);
	}
	Ped^ Group::GetMember(int Index) {
		NON_EXISTING_CHECK(nullptr);
		//u32 i,c;
		//Scripting::GetGroupSize(pHandle,&i,&c);
		int p;
		Scripting::GetGroupMember(pHandle,Index,&p);
		if (p == 0) return nullptr;
		return ContentCache::GetPed(p);
	}
	void Group::RemoveAllMembers() {
		NON_EXISTING_CHECK();
		for (int i = MemberCount-1; i >= 0; i--) {
			RemoveMember(i);
		}
		ForceNextExistsCheck();
	}
	void Group::RemoveMember(Ped^ ped) {
		if (!isMember(ped)) return;
		ped->LeaveGroup();
		ForceNextExistsCheck();
	}
	void Group::RemoveMember(int Index) {
		NON_EXISTING_CHECK();
		int p;
		Scripting::GetGroupMember(pHandle,Index,&p);
		if (p != 0) Scripting::RemoveCharFromGroup(p);
		ForceNextExistsCheck();
	}

	array<Ped^>^ Group::ToArray(bool IncludingLeader) {
		return ToList(IncludingLeader)->ToArray();
	}
	PedCollection^ Group::ToList(bool IncludingLeader) {
		Ped^ p;
		PedCollection^ list = gcnew PedCollection();
		NON_EXISTING_CHECK(list);
		if (IncludingLeader) {
			p = Leader;
			if (!Object::ReferenceEquals(p,nullptr)) list->Add(p);
		}
		for (int i = 0; i<MemberCount; i++) {
			p = GetMember(i);
			if (!Object::ReferenceEquals(p,nullptr)) list->Add(p);
		}
		return list;
	}


	//int Group::GetIndex(Ped^ ped) {
	//	return Scripting::IsGroupMember(ped->Handle,pHandle);
	//}
	//void Group::SetMembersDuckWhenAimedAt(bool duck) {
	//	Scripting::SetGroupCharDucksWhenAimedAt(pHandle,duck);
	//}
	void Group::SeparationRange::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetGroupSeparationRange(pHandle,value);
	}
	void Group::FollowStatus::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetGroupFollowStatus(pHandle,value);
	}
	void Group::Formation::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetGroupFormation(pHandle,value);
	}
	void Group::FormationSpacing::set(float value) {
		NON_EXISTING_CHECK();
		Scripting::SetGroupFormationSpacing(pHandle,value);
	}

	void Group::EnterVehicle(Vehicle^ vehicle, bool WithLeader, bool KeepCurrentDriver) {
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(vehicle);
		PedCollection^ m = ToList(false);
		m->OrderByDistanceTo(vehicle->Position);
		if (WithLeader) {
			Ped^ l = Leader;
			if (!Object::ReferenceEquals(l,nullptr)) m->Insert(0,l);
		}
		if (m->Count == 0) return;
		if ((KeepCurrentDriver) && (vehicle->isSeatFree(VehicleSeat::Driver))) KeepCurrentDriver = false;

		int mid = 0;
		if (!KeepCurrentDriver) {
			m->default[mid]->Task->EnterVehicle(vehicle, VehicleSeat::Driver);
			mid++;
		}
		int seats = vehicle->PassengerSeats;
		for (int seat = 0; seat < seats; seat++) {
			if (mid >= m->Count) return;
			m->default[mid]->Task->EnterVehicle(vehicle, (VehicleSeat)seat);
			mid++;
		}

		//array<Ped^>^ m = ToArray(WithLeader);
		//if (m->Length == 0) return;
		//if ((KeepCurrentDriver) && (vehicle->isSeatFree(VehicleSeat::Driver))) KeepCurrentDriver = false;

		//int mid = 0;
		//if (!KeepCurrentDriver) {
		//	m[mid]->Task->EnterVehicle(vehicle, VehicleSeat::Driver);
		//	mid++;
		//}
		//int seats = vehicle->PassengerSeats;
		//for (int seat = 0; seat < seats; seat++) {
		//	if (mid >= m->Length) return;
		//	m[mid]->Task->EnterVehicle(vehicle, (VehicleSeat)seat);
		//	mid++;
		//}
	}

	bool Group::InternalCheckExists() {
		return Scripting::DoesGroupExist(pHandle);
	}
	void Group::Delete() {
		//NON_EXISTING_CHECK_RELAXED();
		 if (!ExistsForced()) return;
		SetExistsFalse();
		if (pHandle == 0) return;
		try {
			unmanaged::Native::RemoveGroup(pHandle);
		} catch (...) { }
	}

	bool Group::operator == (Group^ left, Group^ right) {
		return (left->Handle == right->Handle);
	}
	bool Group::operator != (Group^ left, Group^ right) {
		return !(left == right);
	}

}