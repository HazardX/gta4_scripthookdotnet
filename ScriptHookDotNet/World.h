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

	public ref class World sealed {

	private:
		World() { }
		static int pBaseYear = 2003;

		static int GetDayDiff(TimeSpan time);
		static TimeSpan GetTimeOfDay(TimeSpan time);

	internal:

		static float GetGroundZBelow(float x, float y, float z);
		static float GetGroundZAbove(float x, float y, float z);
		static float GetGroundZNext(float x, float y, float z);

		/// <summary>
		/// Draws a 3D Checkpoint at the given position.
		/// </summary>
		static void DrawCheckpoint(Vector3 Position, float Diameter, Drawing::Color Color);

		/// <summary>
		/// Draws a 3D Light at the given position.
		/// </summary>
		/// <param name="Intensity">Light Intensity. 50 is a common value.</param>
		static void DrawLight(Vector3 Position, Drawing::Color Color, float Range, float Intensity);

		static array<int>^ World::GetValidPedHandles(GTA::Model Model);
		static array<int>^ World::GetValidVehicleHandles(GTA::Model Model);
		static array<int>^ World::GetValidObjectHandles(GTA::Model Model);

	public:

		static property GTA::Weather Weather{
			GTA::Weather get();
			void set(GTA::Weather value);
		}

		static property TimeSpan CurrentDayTime {
			TimeSpan get();
			void set(TimeSpan value);
		}
		static property DateTime CurrentDate {
			DateTime get();
			//void set(DateTime value);
		}
		/// <summary>
		/// Sets the car density. 1.0 is default, 2.0 is twice as much as normal, etc.
		/// </summary>
		static property float CarDensity {
			void set(float value);
		}
		/// <summary>
		/// Sets the ped density. 1.0 is default, 2.0 is twice as much as normal, etc.
		/// </summary>
		static property float PedDensity {
			void set(float value);
		}

		static property bool GravityEnabled {
			void set(bool value);
		}

		static void OneDayForward();
		static void LockDayTime(TimeSpan LockedTime);
		static void LockDayTime(int Hour, int Minute);
		static void LockDayTime();
		static void UnlockDayTime();

		static void LoadEnvironmentNow(GTA::Vector3 Position);
	
		static void AddExplosion(Vector3 Position); 
		static void AddExplosion(Vector3 Position, ExplosionType Type, float Power, bool PlaySound, bool NoVisuals, float CameraShake); 
		static void AddExplosion(Vector3 Position, ExplosionType Type, float Power); 

		//static Ped^ GetClosestPed(Vector3 Position, float Radius, int UnknownValue1, int UnknownValue2); 
		static Ped^ GetClosestPed(Vector3 Position, float Radius); 
		static Ped^ GetRandomPed(Vector3 Position, float Radius); 
		/// <summary>
		/// Returns all peds in the given area. Slow, but very reliable! Also includes players, mission peds and vehicle passengers!
		/// </summary>
		static array<Ped^>^ GetPeds(Vector3 Position, float Radius, int MaxAmount); 
		/// <summary>
		/// Returns all peds in the given area. Slow, but very reliable! Also includes players, mission peds and vehicle passengers!
		/// </summary>
		static array<Ped^>^ GetPeds(Vector3 Position, float Radius); 
		/// <summary>
		/// Returns all currently existing peds of one model. Slow, but very reliable! Also includes players, mission peds and vehicle passengers!
		/// Make sure to check every returned Ped with Exists() before using it!
		/// </summary>
		static array<Ped^>^ GetAllPeds(GTA::Model ofModel); 
		/// <summary>
		/// Returns all currently existing peds. SLOW! Also includes players, mission peds and vehicle passengers!
		/// Make sure to check every returned Ped with Exists() before using it!
		/// </summary>
		static array<Ped^>^ GetAllPeds(); 

		static Vehicle^ GetClosestVehicle(Vector3 Position, float MaxRadius, GTA::Model ofModel); 
		static Vehicle^ GetClosestVehicle(Vector3 Position, float MaxRadius); 
		/// <summary>
		/// Returns all vehicles of one model in the given area. Slow, but very reliable! Also includes player and mission vehicles!
		/// </summary>
		static array<Vehicle^>^ GetVehicles(Vector3 Position, float Radius, GTA::Model ofModel); 
		/// <summary>
		/// Returns all vehicles in the given area. Slow, but very reliable! Also includes player and mission vehicles!
		/// </summary>
		static array<Vehicle^>^ GetVehicles(Vector3 Position, float Radius); 
		/// <summary>
		/// Returns all currently existing vehicles of one model. Slow, but very reliable! Also includes player and mission vehicles!
		/// Make sure to check every returned Vehicle with Exists() before using it!
		/// </summary>
		static array<Vehicle^>^ GetAllVehicles(GTA::Model ofModel); 
		/// <summary>
		/// Returns all currently existing vehicles. SLOW! Also includes player and mission vehicles!
		/// Make sure to check every returned Vehicle with Exists() before using it!
		/// </summary>
		static array<Vehicle^>^ GetAllVehicles(); 

		/// <summary>
		/// Returns all currently existing objects of one model. VERY SLOW! Also includes mission objects!
		/// Make sure to check every returned Object with Exists() before using it!
		/// </summary>
		static array<GTA::Object^>^ GetAllObjects(GTA::Model ofModel); 
		/// <summary>
		/// Returns all currently existing objects. VERY SLOW! Also includes mission objects!
		/// Make sure to check every returned Object with Exists() before using it!
		/// </summary>
		static array<GTA::Object^>^ GetAllObjects(); 

		static float GetGroundZ(Vector3 Position, GroundType Type);
		static float GetGroundZ(Vector3 Position);
		static Vector3 GetGroundPosition(Vector3 Position, GroundType Type);
		static Vector3 GetGroundPosition(Vector3 Position);

		static Vector3 GetNextPositionOnPavement(Vector3 Position);
		static Vector3 GetNextPositionOnStreet(Vector3 Position);
		static Vector3 GetPositionAround(Vector3 Position, float Distance);
		
		static String^ GetStreetName(Vector3 Position);
		static String^ GetZoneName(Vector3 Position);
		//static Room GetRoomAt(Vector3 Position);

		static bool isPositionBlockedByMissionEntity(Vector3 Position, float Radius);

		static void SetGroupRelationship(GTA::RelationshipGroup group, Relationship level, GTA::RelationshipGroup targetgroup);

		static ScriptedFire^ StartFire(Vector3 Position, int Unknown1, int Unknown2);
		static ScriptedFire^ StartFire(Vector3 Position);
		static void ExtinguishFire(Vector3 Position, float Radius);
		static void ExtinguishAllScriptFires();
		static void UnlockAllIslands();
		static void TriggerCollisionsAt(Vector3 Position);
		/// <summary>
		/// Sets the state of the closest door with the given model.
		/// </summary>
		/// <param name="DoorModel">Model of the nearby door to open.</param>
		/// <param name="NearbyPosition">A position close to the door.</param>
		/// <param name="Locked">The door cannot be moved when locked.</param>
		/// <param name="Angle">The current door angle. 0 is closed, 1 is open, -1 is open to the other direction.</param>
		static void SetDoorState(Model DoorModel, Vector3 NearbyPosition, bool Locked, float Angle);

		static Ped^ CreatePed(Vector3 Position, GTA::Gender Gender);
		static Ped^ CreatePed(Vector3 Position);
		static Ped^ CreatePed(GTA::Model Model, Vector3 Position, RelationshipGroup Type);
		static Ped^ CreatePed(GTA::Model Model, Vector3 Position);

		static Vehicle^ CreateVehicle(Vector3 Position);
		static Vehicle^ CreateVehicle(GTA::Model Model, Vector3 Position);
		static Vehicle^ CreateMissionTrain(Vector3 Position);

		static GTA::Object^ CreateObject(GTA::Model Model, Vector3 Position);

	};

}