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

	CLASS_ATTRIBUTES
	private ref class ContentCache sealed {

	private:

		static const int MAX_FIRES = 100;

		ContentCache() { }

		static Dictionary<int,Player^>^ PlayerCache = gcnew Dictionary<int,Player^>();
		static Dictionary<int,Ped^>^ PedCache = gcnew Dictionary<int,Ped^>();
		static Dictionary<int,Vehicle^>^ VehicleCache = gcnew Dictionary<int,Vehicle^>();
		static Dictionary<int,GTA::Object^>^ ObjectCache = gcnew Dictionary<int,GTA::Object^>();
		static Dictionary<int,Pickup^>^ PickupCache = gcnew Dictionary<int,Pickup^>();
		static Dictionary<int,Group^>^ GroupCache = gcnew Dictionary<int,Group^>();
		static Dictionary<int,Blip^>^ BlipCache = gcnew Dictionary<int,Blip^>();
		static Dictionary<int,Camera^>^ CameraCache = gcnew Dictionary<int,Camera^>();
		static Dictionary<String^,SettingsFile^>^ iniCache = gcnew Dictionary<String^,SettingsFile^>();
		static List<ScriptedFire^>^ FireCache = gcnew List<ScriptedFire^>();

		static List<base::iDeletable^>^ DeleteCache = gcnew List<base::iDeletable^>();
		static List<int>^ DeleteCueue = gcnew List<int>();
		static Dictionary<String^,System::Object^>^ metadata = gcnew Dictionary<String^,System::Object^>();

		static void DeleteStuff();

		generic <class T> where T: base::Object
		static void RemoveNonExisting(List<T>^ list);
		generic <class T> where T: base::Object
		static void RemoveNonExisting(Dictionary<int,T>^ dict);

	public:

		static void RemoveNonExisting();
		static void RemoveAll(bool DeleteStuff);
		
		static void AddPlayer(GTA::Player^ p);
		static GTA::Player^ GetPlayer(int ID);
		static void RemovePlayer(int ID);
		static void RemovePlayer(GTA::Player^ p);

		static void AddPed(GTA::Ped^ p);
		static GTA::Ped^ GetPed(int Handle);
		static void RemovePed(int Handle);
		static void RemovePed(GTA::Ped^ p);

		static void AddVehicle(GTA::Vehicle^ v);
		static GTA::Vehicle^ GetVehicle(int Handle);
		static void RemoveVehicle(int Handle);
		static void RemoveVehicle(GTA::Vehicle^ v);

		static void AddObject(GTA::Object^ o);
		static GTA::Object^ GetObject(int Handle);
		static void RemoveObject(int Handle);
		static void RemoveObject(GTA::Object^ o);

		static void AddPickup(GTA::Pickup^ p);
		static GTA::Pickup^ GetPickup(int Handle);
		static void RemovePickup(int Handle);
		static void RemovePickup(GTA::Pickup^ p);

		static void AddGroup(GTA::Group^ g, bool CreatedByMe);
		static GTA::Group^ GetGroup(int Handle, bool CreatedByMe);
		static void RemoveGroup(int Handle);
		static void RemoveGroup(GTA::Group^ g);

		static void AddBlip(GTA::Blip^ b, bool CreatedByMe);
		static GTA::Blip^ GetBlip(int Handle, bool CreatedByMe);
		static void RemoveBlip(int Handle);
		static void RemoveBlip(GTA::Blip^ b);

		static void AddCamera(GTA::Camera^ c, bool CreatedByMe);
		static GTA::Camera^ GetCamera(int Handle, bool CreatedByMe);
		static void RemoveCamera(int Handle);
		static void RemoveCamera(GTA::Camera^ c);

		static void AddINI(GTA::SettingsFile^ file);
		static GTA::SettingsFile^ GetINI(String^ Filename);
		static void RemoveINI(String^ Filename);
		static void RemoveINI(GTA::SettingsFile^ file);
		static void SaveINIs();

		static void AddFire(GTA::ScriptedFire^ f, bool CreatedByMe);
		static GTA::ScriptedFire^ GetFire(int Handle, bool CreatedByMe);
		static void RemoveFire(int Handle);
		static void RemoveFire(GTA::ScriptedFire^ f);
		static void FireAmountCheck();

		static System::Object^ GetMetaData(int ItemHandle, String^ ValueName) {
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			if (!metadata->ContainsKey(id)) return nullptr;
			try {
				return metadata[id];
			} catch(...) {
				return nullptr;
			}
		}

		static void SetMetaData(int ItemHandle, String^ ValueName, System::Object^ Value) {
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			metadata[id] = Value;
		}

		static bool HasMetaData(int ItemHandle, String^ ValueName) {
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			return metadata->ContainsKey(id);
		}
		
	};

}