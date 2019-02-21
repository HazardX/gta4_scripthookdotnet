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
	[SerializableAttribute]
	public ref class Camera sealed : 
		public base::HandleObject,
		public base::iPositioned,
		public base::iRotatable,
		public base::iDeletable {

	protected:
		//int pHandle;

	internal:
		Camera(int Handle);
		//property int Handle{ 
		//	int get();
		//}

		virtual bool InternalCheckExists() override;

	public:
		Camera();

		property Vector3 Position {
			virtual Vector3 get();
			virtual void set(Vector3 value);
		}

		property Vector3 Rotation {
			Vector3 get();
			void set(Vector3 value);
		}
		property Vector3 Direction {
			virtual Vector3 get();
			void set(Vector3 value);
		}

		property float Heading {
			virtual float get();
			virtual void set(float value);
		}
		property float Roll {
			float get();
			void set(float value);
		}

		property float FOV {
			float get();
			void set(float value);
		}
		property bool isActive {
			bool get();
			void set(bool value);
		}
		property float DrunkEffectIntensity {
			void set(float value);
		}

		void Activate();
		void Deactivate();
		virtual void Delete();
		bool isSphereVisible(Vector3 Position, float Radius);
		void TargetPed(Ped^ ped);
		void LookAt(GTA::Object^ object);
		void LookAt(Vehicle^ vehicle);
		void LookAt(Ped^ ped);
		void LookAt(Vector3 Position);

		//virtual bool Exists() override;

		//static bool operator == ( Camera^ left, Camera^ right );
		//static bool operator != ( Camera^ left, Camera^ right );

	};

}