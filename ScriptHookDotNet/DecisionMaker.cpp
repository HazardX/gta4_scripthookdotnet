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

#include "DecisionMaker.h"

#include "Ped.h"

#pragma managed

namespace GTA {

	DecisionMaker::DecisionMaker(int Handle, DecisionCategory Category)
		:HandleObject(Handle) {
		pCategory = Category;
	}
	DecisionMaker::~DecisionMaker() {
		Scripting::RemoveDecisionMaker(pHandle);
	}


	DecisionMaker^ DecisionMaker::LoadBehavior(BehaviorTemplate Template) {
		u32 dm = 0;
		Scripting::LoadCharDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::Behavior);
	}
	DecisionMaker^ DecisionMaker::LoadCombat(CombatTemplate Template) {
		u32 dm = 0;
		Scripting::LoadCombatDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::Combat);
	}

	DecisionMaker^ DecisionMaker::CopyBehavior(CopyTemplate Template) {
		u32 dm = 0;
		Scripting::CopyCharDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::Behavior);
	}
	DecisionMaker^ DecisionMaker::CopyCombat(CopyTemplate Template) {
		u32 dm = 0;
		Scripting::CopyCombatDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::Combat);
	}

	DecisionMaker^ DecisionMaker::CopyBehaviorForGroupMembers(CopyTemplate Template) {
		u32 dm = 0;
		Scripting::CopyGroupCharDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::GroupBehavior);
	}
	DecisionMaker^ DecisionMaker::CopyCombatForGroupMembers(CopyTemplate Template) {
		u32 dm = 0;
		Scripting::CopyGroupCombatDecisionMaker((int)Template, &dm);
		if (dm == 0) return nullptr;
		return gcnew DecisionMaker(dm, DecisionCategory::GroupCombat);
	}

	DecisionCategory DecisionMaker::Category::get() {
		return pCategory;
	}

	void DecisionMaker::ApplyTo(GTA::Ped^ ped) {
		if isNULL(ped) return;
		NON_EXISTING_CHECK();
		OBJECT_NON_EXISTING_CHECK(ped);
		switch (pCategory) {
			case DecisionCategory::Behavior:
				Scripting::SetCharDecisionMaker(ped->Handle,pHandle);
				return;
			case DecisionCategory::Combat:
				Scripting::SetCombatDecisionMaker(ped->Handle,pHandle);
				return;
			case DecisionCategory::GroupBehavior:
				Scripting::SetGroupCharDecisionMaker(ped->Handle,pHandle);
				return;
			case DecisionCategory::GroupCombat:
				Scripting::SetGroupCombatDecisionMaker(ped->Handle,pHandle);
				return;
		}
	}

	bool DecisionMaker::InternalCheckExists() {
		return Scripting::DoesDecisionMakerExist(pHandle);
	}

	void DecisionMaker::RemoveEventResponse(int EventID) {
		NON_EXISTING_CHECK();
		switch (pCategory) {
			case DecisionCategory::Behavior:
			case DecisionCategory::GroupBehavior:
				Scripting::ClearCharDecisionMakerEventResponse(pHandle,EventID);
				return;
			case DecisionCategory::Combat:
			case DecisionCategory::GroupCombat:
				Scripting::ClearCombatDecisionMakerEventResponse(pHandle,EventID);
				return;
			//case DecisionCategory::Group:
			//	Scripting::ClearGroupDecisionMakerEventResponse(pHandle,EventID);
			//	return;
		}
	}
	void DecisionMaker::AddEventResponse(int EventID, int ResponseID, float param1, float param2, float param3, float param4) {
		NON_EXISTING_CHECK();
		switch (pCategory) {
			case DecisionCategory::Behavior:
			case DecisionCategory::GroupBehavior:
				Scripting::AddCharDecisionMakerEventResponse(pHandle,EventID,ResponseID,param1,param2,param3,param4,1,1);
				return;
			case DecisionCategory::Combat:
			case DecisionCategory::GroupCombat:
				Scripting::AddCombatDecisionMakerEventResponse(pHandle,EventID,ResponseID,param1,param2,param3,param4,1,1);
				return;
			//case DecisionCategory::Group:
			//	Scripting::AddGroupDecisionMakerEventResponse(pHandle,EventID,ResponseID,param1,param2,param3,param4,1,1);
			//	return;
		}
	}

	void DecisionMaker::CanChangeTarget::set(bool value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeCanChangeTarget(pHandle,value);
	}
	void DecisionMaker::Caution::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeCaution(pHandle,value);
	}
	void DecisionMaker::FireRate::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeFireRate(pHandle,value);
	}
	void DecisionMaker::LowHealth::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeLowHealth(pHandle,value);
	}
	void DecisionMaker::MovementStyle::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeMovementStyle(pHandle,value);
	}
	void DecisionMaker::NavigationStyle::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeNavigationStyle(pHandle,value);
	}
	void DecisionMaker::RetreatingBehavior::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeRetreatingBehaviour(pHandle,value);
	}
	void DecisionMaker::SightRange::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeSightRange(pHandle,value);
	}
	void DecisionMaker::StandingStyle::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeStandingStyle(pHandle,value);
	}
	void DecisionMaker::TargetInjuredReaction::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeTargetInjuredReaction(pHandle,value);
	}
	void DecisionMaker::TargetLossResponse::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeTargetLossResponse(pHandle,value);
	}
	void DecisionMaker::Teamwork::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeTeamwork(pHandle,value);
	}
	void DecisionMaker::WeaponAccuracy::set(int value) {
		NON_EXISTING_CHECK();
		Scripting::SetDecisionMakerAttributeWeaponAccuracy(pHandle,value);
	}

}