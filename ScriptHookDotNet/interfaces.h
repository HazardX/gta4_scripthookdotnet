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
//#include "sVector3.h"
//#include "sRoom.h"
//#include "sModel.h"
//#include "import_unmanaged.h"

#pragma managed

namespace GTA {

	ref class Ped;
	value class Room;
	value class Model;

namespace base {

	//private interface class iLocalScriptDomain {
	//	void RemoteEvent(String^ EventName, SerializableEventArgs^ Args);
	//};

	public interface class iBaseObject {
		//bool CheckExists();
		bool Exists();
	};

	public interface class iHandleObject :
		System::IEquatable<iHandleObject^>,
		iBaseObject {

		property int Handle {
			int get();
		}
		[System::Runtime::CompilerServices::Dynamic]
		property System::Object^ Metadata {
			System::Object^ get();
		}
	};

	public interface class iGroup
		: System::Collections::Generic::IEnumerable<Ped^> {
		
		property int MemberCount {
			int get();
		}
		property Ped^ Leader {
			Ped^ get();
		}
		bool AddMember(Ped^ ped);

	};

	public interface class iPositioned {
		property Vector3 Position;
	};

	public interface class iRotatable {
		//property Vector3 Rotation;
		property float Heading;
		property GTA::Vector3 Direction {
			GTA::Vector3 get();
		}
	};

	public interface class iInteriorObject {
		property GTA::Room CurrentRoom;
	};

	public interface class iModelObject {
		//property Vector3 Rotation;
		property GTA::Model Model {
			GTA::Model get();
		}
	};

	public interface class iVisibleObject {
		property bool Visible {
			void set(bool value);
		}
	};

	public interface class iRequestable {
		void NoLongerNeeded();
	};
	public interface class iDeletable {
		void Delete();
	};

	public interface class iBurnable {
		property bool isOnFire {
			bool get();
			void set(bool value);
		}
	};

	public interface class iFreezable {
		property bool FreezePosition {
			void set(bool value);
		}
	};

	public interface class iForce {
		void ApplyForce(Vector3 Direction, Vector3 Rotation);
		void ApplyForce(Vector3 Direction);
		void ApplyForceRelative(Vector3 Direction, Vector3 Rotation);
		void ApplyForceRelative(Vector3 Direction);
		property Vector3 Velocity {
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public interface class iAddressableObject {
		property int MemoryAddress {
			int get();
		}
	};
	public interface class iMissionObject {
		property bool isRequiredForMission {
			bool get();
			void set(bool value);
		}
	};

	public interface class iD3DObject {
		int GetD3DObjectID(bool retrieveNew);
		void Unload(bool permanent);
		void Reload();
	};

	public interface class iComplexObject : 
			public iHandleObject,
			public iPositioned,
			public iRotatable,
			public iInteriorObject,
			public iModelObject,
			public iRequestable,
			public iVisibleObject,
			public iBurnable,
			public iFreezable,
			public iForce,
			public iDeletable,
			public iAddressableObject {
	};

}
}