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
	public ref class Blip sealed :
		public base::HandleObject,
		public base::iPositioned,
		public base::iDeletable,
		public base::iAddressableObject {

	protected:
		//int pHandle;

	internal:
		Blip(int Handle);
		//property int Handle{ 
		//	int get();
		//}

		virtual bool InternalCheckExists() override;

	public:
		property int MemoryAddress {
			virtual int get();
		}

		property GTA::Vector3 Position{
			virtual GTA::Vector3 get();
			virtual void set(GTA::Vector3 value);
		}

		property BlipColor Color{ 
			BlipColor get();
			void set(BlipColor value);
		}
		property BlipDisplay Display{ 
			BlipDisplay get();
			void set(BlipDisplay value);
		}
		property int Priority{ 
			void set(int value);
		}
		property bool Friendly { 
			void set(bool value);
		}
		property float Scale { 
			void set(float value);
		}
		property float Transparency { 
			void set(float value);
		}
		property BlipIcon Icon { 
			BlipIcon get();
			void set(BlipIcon value);
		}
		property bool ShowOnlyWhenNear { 
			bool get();
			void set(bool value);
		}
		property String^ Name { 
			String^ get();
			void set(String^ value);
		}
		property bool RouteActive { 
			void set(bool value);
		}
		property BlipType Type { 
			BlipType get();
		}

		/// <summary>
		/// Returns the item the Blip is attached to or Nothing/Null if it isn't attached to an item.
		/// </summary>
		base::Object^ GetAttachedItem();

		void SetColorRGB(Drawing::Color color);

		virtual void Delete();
		//virtual bool Exists() override;

		// STATIC

		static Blip^ AddBlip(GTA::Pickup^ Target);
		static Blip^ AddBlip(GTA::Object^ Target);
		static Blip^ AddBlip(GTA::Vector3 Target);
		static Blip^ AddBlip(GTA::Vehicle^ Target);
		static Blip^ AddBlip(GTA::Ped^ Target);
		static Blip^ AddBlipContact(GTA::Vector3 Target);

		static array<Blip^>^ GetAllBlipsOfType(BlipType type);

		//static bool operator == ( Blip^ left, Blip^ right );
		//static bool operator != ( Blip^ left, Blip^ right );

	};

}