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

namespace GTA{

	public ref class Player sealed {

	private:
		int pID;

		[NonSerializedAttribute]
		Ped^ pPed;

		[NonSerializedAttribute]
		Group^ pGroup;

		[NonSerializedAttribute]
		value::PlayerSkin^ pSkin;

		//int GetCharHandleFromID(int PlayerID);

	internal:

		property int PedHandle{
			int get();
		}

	public:
		Player(int ID);
		property int ID{
			int get();
		}
		property int Index{
			int get();
		}

		property Ped^ Character {
			Ped^ get();
		}
		property GTA::Group^ Group {
			GTA::Group^ get();
		}
		property String^ Name {
			String^ get();
		}
		property GTA::Model Model {
			GTA::Model get();
			void set(GTA::Model value);
		}
		property GTA::value::PlayerSkin^ Skin {
			GTA::value::PlayerSkin^ get();
		}
		property System::Drawing::Color Color {
			System::Drawing::Color get();
		}
		property GTA::Multiplayer::Team^ Team {
			GTA::Multiplayer::Team^ get();
			void set(GTA::Multiplayer::Team^ value);
		}
		property bool isActive {
			bool get();
		}

		property bool CanControlCharacter {
			bool get();
			void set(bool value);
		}
		property int WantedLevel {
			int get();
			void set(int value);
		}
		property int Money {
			int get();
			void set(int value);
		}

		property int MaxHealth {
			void set(int value);
		}
		property int MaxArmor {
			void set(int value);
		}

		property bool isLocalPlayer {
			bool get();
		}
		property bool isOnMission {
			bool get();
		}
		property bool isPlaying {
			bool get();
		}
		property bool isPressingHorn {
			bool get();
		}
		//property bool isTargettingAnything {
		//	bool get();
		//}

		property bool IgnoredByEveryone {
			void set(bool value);
		}
		property bool CanControlRagdoll {
			void set(bool value);
		}
		property bool NeverGetsTired {
			void set(bool value);
		}

		bool isTargetting(GTA::Object^ object);
		bool isTargetting(Ped^ ped);
		Ped^ GetTargetedPed();

		property GTA::Vehicle^ LastVehicle {
			GTA::Vehicle^ get();
		}

		void ActivateMultiplayerSkin();

		void TeleportTo(Vector3 Position);
		void TeleportTo(float X, float Y);

		//void AddMoney(int Amount);
		//void ChangeModel(Model model);
		//GTA::Vehicle^ GetLastVehicle();
		//void SetInvincible(bool enable);

		void SetComponentVisibility(PedComponent Component, bool Visible);

		static bool operator == ( Player^ left, Player^ right );
		static bool operator != ( Player^ left, Player^ right );

		static bool operator == ( Player^ left, Ped^ right );
		static bool operator != ( Player^ left, Ped^ right );
		static bool operator == ( Ped^ left, Player^ right );
		static bool operator != ( Ped^ left, Player^ right );

	};

}