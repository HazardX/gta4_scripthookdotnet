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

#include "Player.h"

#include "ContentCache.h"
#include "Group.h"
#include "Object.h"
#include "Ped.h"
#include "Team.h"
#include "World.h"
#include "vPedSkin.h"
#include "vWeaponCollection.h"

#pragma managed

namespace GTA{

	Player::Player(int ID) {
		//:Ped(GetCharHandleFromID(ID)){
		this->pID=ID;
	}

	//int Player::GetCharHandleFromID(int PlayerID){
	//	int Index = Scripting::ConvertIntToPlayerIndex(PlayerID);
	//	int c;
	//	Scripting::GetPlayerChar(Index,&c);
	//	return c;
	//}

	int Player::ID::get(){
		return pID;
	}
	int Player::Index::get(){
		return Scripting::ConvertIntToPlayerIndex(pID);
	}
	int Player::PedHandle::get(){
		int c;
		Scripting::GetPlayerChar(Index,&c);
		return c;
	}

	Ped^ Player::Character::get(){
		int c = PedHandle;
		if (c == 0) return nullptr;

		if (!Object::ReferenceEquals(pPed,nullptr)) {
			if (c == pPed->Handle) return pPed;
			pPed->SetHandle(c);
		} else {
			pPed = ContentCache::GetPed(c);
		}
		//GTA::Game::DisplayText("NEW PLAYER PED!");
		return pPed;
	}

	GTA::Group^ Player::Group::get(){
		int c;
		Scripting::GetPlayerGroup(Index,&c);
		if (c == 0) return nullptr;

		if (!Object::ReferenceEquals(pGroup,nullptr)) {
			if (c == pGroup->Handle) return pGroup;
			pGroup->SetHandle(c, false);
		} else {
			pGroup = ContentCache::GetGroup(c, false);
		}
		return pGroup;
	}

	String^ Player::Name::get(){
		return gcnew String( Scripting::GetPlayerName(Index) );
	}

	GTA::Model Player::Model::get() {
		Scripting::eModel model;
		Scripting::GetCharModel(PedHandle, &model);
		return GTA::Model((int)model);
	}
	void Player::Model::set(GTA::Model value) {
		if (!Model.isPed) return;
		if (value == Model) return;

		Room r = Character->CurrentRoom;
		float heading = Character->Heading;
		//int maxhealth = Character->MaxHealth;
		int health = Character->Health;
		int armor = Character->Armor;
		int wanted = WantedLevel;
		array<int>^ ammo = Character->Weapons->GetAmmoArray();
		GTA::Weapon weap = Character->Weapons->CurrentType;

		if (!value.LoadToMemoryNow(10000)) return;
		unmanaged::Native::ChangePlayerModel(Index,(Scripting::eModel)value.Hash);
		value.AllowDisposeFromMemory();

		Character->SetDefaultVoice();

		Character->CurrentRoom = r;
		Character->Heading = heading;
		//Character->MaxHealth = maxhealth;
		Character->Health = health;
		Character->Armor = armor;
		WantedLevel = wanted;
		Character->Weapons->SetAmmoArray(ammo);
		Character->Weapons->Select(weap);
	}

	GTA::value::PlayerSkin^ Player::Skin::get() {
		if isNULL(pSkin) pSkin = gcnew value::PlayerSkin(this);
		return pSkin;
	}

	System::Drawing::Color Player::Color::get(){
		u32 R = 0; u32 G = 0; u32 B = 0;
		Scripting::GetPlayerRgbColour(Index, &R, &G, &B);
		return System::Drawing::Color::FromArgb(R,G,B);
	}

	GTA::Multiplayer::Team^ Player::Team::get() {
		int t = force_cast<int>(Scripting::GetPlayerTeam(Index));
		if (t < 0) return nullptr;
		return gcnew GTA::Multiplayer::Team(t);
	}
	void Player::Team::set(GTA::Multiplayer::Team^ value) {
		if (isNULL(value) || (value->ID < 0) || (value->ID > 16))
			Scripting::SetPlayerTeam(Index, -1);
		else
			Scripting::SetPlayerTeam(Index, value->ID);
	}


	bool Player::isActive::get() {
		if (isLocalPlayer) return isNotNULL(Character);
		return Scripting::IsNetworkPlayerActive(ID);
	}

	bool Player::CanControlCharacter::get(){
		return Scripting::IsPlayerControlOn(Index);
	}
	void Player::CanControlCharacter::set(bool value){
		unmanaged::Native::SetPlayerControl(Index,value);
	}

	int Player::WantedLevel::get(){
		//int idx = Index;
		//for (int i = 0; i<6; i++) {
		//	if (!Scripting::IsWantedLevelGreater(idx, i)) return i;
		//}
		//return 6;
		i32 wl;
		Scripting::StoreWantedLevel(Index, &wl);
		return wl;
	}
	void Player::WantedLevel::set(int value){
		if (value > 0) {
			Scripting::AlterWantedLevel(Index, value);
		} else {
			Scripting::ClearWantedLevel(Index);
		}
		unmanaged::Native::ApplyWantedLevelChangeNow(Index);
	}

	int Player::Money::get() {
		i32 s;
		Scripting::StoreScore(Index, &s);
		return s;
	}
	void Player::Money::set(int value) {
		i32 idx = Index;
		i32 s;
		Scripting::StoreScore(idx, &s);
		if (value < 0) value = 0;
		Scripting::AddScore(idx,value-s);
	}

	void Player::MaxHealth::set(int value){
		Scripting::IncreasePlayerMaxHealth(Index,value+100);
	}
	void Player::MaxArmor::set(int value){
		Scripting::IncreasePlayerMaxArmour(Index,value);
	}

	//void Player::ChangeModel(Model model) {
	//	Room r = Character->CurrentRoom;
	//	model.LoadToMemoryNow();
	//	Scripting::ChangePlayerModel(Index,(Scripting::eModel)model.Hash);
	//	model.AllowDisposeFromMemory();
	//	Character->CurrentRoom = r;
	//}

	GTA::Vehicle^ Player::LastVehicle::get(){
		if (!isLocalPlayer) {
			throw gcnew InvalidOperationException("Player.LastVehicle can only be used on the local player!");
			return nullptr;
		}
		int car;
		Scripting::GetPlayersLastCarNoSave(&car);
		if (car == 0) return nullptr;
		return ContentCache::GetVehicle(car);
	}

	bool Player::isLocalPlayer::get() {
		return (pID == Scripting::GetPlayerId());
	}
	bool Player::isOnMission::get() {
		return !Scripting::CanPlayerStartMission(Index);
	}
	bool Player::isPlaying::get() {
		return Scripting::IsPlayerPlaying(Index);
	}
	bool Player::isPressingHorn::get() {
		return Scripting::IsPlayerPressingHorn(Index);
	}
	//bool Player::isTargettingAnything::get() {
	//	return Scripting::IsPlayerTargettingAnything(Index);
	//}

	void Player::IgnoredByEveryone::set(bool value) {
		Scripting::SetEveryoneIgnorePlayer(Index, value);
	}
	void Player::CanControlRagdoll::set(bool value) {
		Scripting::GivePlayerRagdollControl(Index, value);
	}
	void Player::NeverGetsTired::set(bool value) {
		Scripting::SetPlayerNeverGetsTired(Index, value);
	}

	bool Player::isTargetting(Ped^ ped) {
		return Scripting::IsPlayerFreeAimingAtChar(Index, ped->Handle);
		//return Scripting::IsPlayerTargettingChar(Index, ped->Handle);
	}
	bool Player::isTargetting(GTA::Object^ object) {
		return Scripting::IsPlayerTargettingObject(Index, object->Handle);
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	Ped^ Player::GetTargetedPed() {
		array<int>^ list = World::GetValidPedHandles(GTA::Model::Null); //unmanaged::MemoryAccess::GetPedHandleList();
		int idx = Index;
		for (int i = 0; i < list->Length; i++) {
			try {
				if (Scripting::IsPlayerFreeAimingAtChar(idx, list[i])) return ContentCache::GetPed(list[i]);
			} catch (...) {}
		}
		return nullptr;
	}

	void Player::SetComponentVisibility(PedComponent Component, bool Visible) {
		if (!isLocalPlayer) {
			throw gcnew InvalidOperationException("Player.SetComponentVisibility can only be used on the local player!");
			return;
		}
		Scripting::SetDrawPlayerComponent((i32)Component, Visible);
	}

	void Player::ActivateMultiplayerSkin() {
		if (!isLocalPlayer) {
			throw gcnew InvalidOperationException("Player.ActivateMultiplayerSkin can only be used on the local player!");
			return;
		}
		Model = GTA::Model(Scripting::GetPlayerSettingsModelChoice());
		Scripting::SetPlayerSettingsModelVariationsChoice(Index);
		Character->SetDefaultVoice();
	}

	void Player::TeleportTo(Vector3 Position) {
		if (!isLocalPlayer) {
			throw gcnew InvalidOperationException("Player.TeleportTo can only be used on the local player!");
			return;
		}
		GTA::Ped^ p = Character;
		p->Position = Position;
		GTA::World::LoadEnvironmentNow(Position);
		if (Position.Z == 0.0f) p->Position = GTA::World::GetGroundPosition(Position, GroundType::Highest);
	}
	void Player::TeleportTo(float X, float Y) {
		TeleportTo(Vector3(X,Y,0.0f));
	}
	
	bool Player::operator == (Player^ left, Player^ right) {
		if (Object::ReferenceEquals(left,nullptr)) return Object::ReferenceEquals(right,nullptr);
		if (Object::ReferenceEquals(right,nullptr)) return false;
		return (left->ID == right->ID);
	}
	bool Player::operator != (Player^ left, Player^ right) {
		return !(left == right);
	}

	bool Player::operator == (Player^ left, Ped^ right) {
		if (Object::ReferenceEquals(left,nullptr)) return Object::ReferenceEquals(right,nullptr);
		if (Object::ReferenceEquals(right,nullptr)) return false;
		return (left->PedHandle == right->Handle);
	}
	bool Player::operator != (Player^ left, Ped^ right) {
		return !(left == right);
	}
	bool Player::operator == (Ped^ left, Player^ right) {
		if (Object::ReferenceEquals(left,nullptr)) return Object::ReferenceEquals(right,nullptr);
		if (Object::ReferenceEquals(right,nullptr)) return false;
		return (left->Handle == right->PedHandle);
	}
	bool Player::operator != (Ped^ left, Player^ right) {
		return !(left == right);
	}

}