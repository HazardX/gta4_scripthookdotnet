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

namespace GTA {
namespace value {

	CLASS_ATTRIBUTES
	public ref class VehicleDoor sealed {

	private:
		Vehicle^ vehicle;
		GTA::VehicleDoor door;

	internal:
		VehicleDoor(Vehicle^ vehicle, GTA::VehicleDoor door);

	public:
		property GTA::VehicleDoor Index {
			GTA::VehicleDoor get();
		}

		property float Angle {
			float get();
			void set(float value);
		}
		property bool isFullyOpen {
			bool get();
			//void set(bool value);
		}
		property bool isOpen {
			bool get();
			void set(bool value);
		}
		property bool isDamaged {
			bool get();
		}

		void Open();
		void Close();
		void Break();

		static operator GTA::VehicleDoor (GTA::value::VehicleDoor^ source);

	};

}
}