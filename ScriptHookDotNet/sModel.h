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

	using namespace System;
	value class Vector3;

	[System::SerializableAttribute]
	public value class Model {

	private:
		int pHash;
		String^ pName;

	internal:

		//Model(int Hash);
		void LoadToMemory();
		bool LoadToMemoryNow(int timeout);
		bool LoadToMemoryNow() { return LoadToMemoryNow(1000); }

		void LoadCollisionDataToMemory();
		bool LoadCollisionDataToMemoryNow(int timeout);
		bool LoadCollisionDataToMemoryNow() { return LoadCollisionDataToMemoryNow(1000); }

		void AllowDisposeFromMemory();

		property unsigned int Handle { 
			unsigned int get();
		}
		property bool isCollisionDataInMemory { 
			bool get();
		}
		
	public:
		Model(int Hash);
		Model(UInt32 Hash);
		Model(String^ ModelName);

		/// <summary>
		/// Returns an empty (NULL) model.
		/// </summary>
		static property Model Null { 
			Model get() {
				return Model(0);
			}
		}

		property int Hash { 
			int get();
		}
		//property String^ Name { 
		//	String^ get();
		//}

		property bool isInMemory { 
			bool get();
		}
		property bool isValid { 
			bool get();
		}

		property bool isBike { 
			bool get();
		}
		property bool isBoat { 
			bool get();
		}
		property bool isCar { 
			bool get();
		}
		property bool isHelicopter { 
			bool get();
		}
		property bool isPed { 
			bool get();
		}
		property bool isPlane { 
			bool get();
		}
		property bool isTrain { 
			bool get();
		}
		property bool isVehicle { 
			bool get();
		}
		//void LoadToMemory(bool PriorizeRequest);

		/// <summary>
		/// Returns the dimensions of the model as a 3D box defined by two vectors.
		/// Directions: positive X is right, positive Y is front, positive Z is Top 
		/// </summary>
		void GetDimensions(GTA::Vector3% MinVector, GTA::Vector3% MaxVector);

		/// <summary>
		/// Returns the total dimensions of the model. X is width, Y is length, Z is height.
		/// </summary>
		GTA::Vector3 GetDimensions();

		static property Model BasicCopModel { 
			Model get();
		}
		static property Model CurrentCopModel { 
			Model get();
		}
		static property Model BasicPoliceCarModel { 
			Model get();
		}
		static property Model CurrentPoliceCarModel { 
			Model get();
		}
		static property Model TaxiCarModel { 
			Model get();
		}
		static Model GetWeaponModel(GTA::Weapon weapon);

		static bool operator == ( Model left, Model right );
		static bool operator != ( Model left, Model right );
		static operator Model (String^ source);
		static operator Model (int source);
		static operator Model (UInt32 source);

		static Model FromString(String^ string);
		virtual System::String^ ToString() override;

	};

}