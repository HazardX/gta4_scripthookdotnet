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
	public ref class PedSkin {

	private:
		PedComponentCollection^ pComponent;

	internal:
		Ped^ ped;

		PedSkin(Ped^ ped) {
			this->ped = ped;
		}
	
	public:

		property value::PedComponentCollection^ Component {
			value::PedComponentCollection^ get();
		}

		property GTA::Model Model { 
			virtual GTA::Model get();
		}

		property SkinTemplate^ Template { 
			virtual SkinTemplate^ get();
			virtual void set(SkinTemplate^ value);
		}

		int GetPropIndex(PedProp proptype);
		void SetPropIndex(PedProp proptype, int index);

		//int GetAvailableModelCount(PedComponent component);
		//int GetAvailableTextureCount(PedComponent component);

		//int GetComponentModel(PedComponent component);
		//void SetComponentModel(PedComponent component, int model);

		//int GetComponentTexture(PedComponent component);
		//void SetComponentTexture(PedComponent component, int texture);

		//void SetComponent(PedComponent component, int model, int texture);

		static operator SkinTemplate^ (PedSkin^ source);

	};

	CLASS_ATTRIBUTES
	public ref class PlayerSkin sealed : public PedSkin {

	private:
		Player^ player;

	internal:
		PlayerSkin(Player^ player);

	public:

		property GTA::Model Model { 
			virtual GTA::Model get() override { return PedSkin::Model; }
			void set(GTA::Model value);
		}
		property SkinTemplate^ Template { 
			virtual SkinTemplate^ get() override { return PedSkin::Template; }
			virtual void set(SkinTemplate^ value) override;
		}

	};

}
}