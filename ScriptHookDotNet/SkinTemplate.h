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
	public ref class SkinTemplate sealed {

	private:

		GTA::Model pModel;
		array<int>^ PropIndices;
		array<int>^ ComponentModel;
		array<int>^ ComponentTexture;

		void Initialize();

	internal:
		static const int PROP_COUNT = 20;
		static const int COMPONENT_COUNT = 20;

		SkinTemplate(value::PedSkin^ sk);

		void FromPedSkin(value::PedSkin^ sk);
		void ApplyToPed(Ped^ ped);
		void ApplyToPlayer(Player^ player);
		
	public:
		SkinTemplate();

		property GTA::Model Model { 
			GTA::Model get();
			void set(GTA::Model value);
		}

		int GetPropIndex(PedProp proptype) {
			return PropIndices[(int)proptype];
		}
		void SetPropIndex(PedProp proptype, int index) {
			PropIndices[(int)proptype] = index;
		}

		int GetComponentModel(PedComponent component) {
			return ComponentModel[(int)component];
		}
		void SetComponentModel(PedComponent component, int model) {
			ComponentModel[(int)component] = model;
		}

		int GetComponentTexture(PedComponent component) {
			return ComponentTexture[(int)component];
		}
		void SetComponentTexture(PedComponent component, int texture) {
			ComponentTexture[(int)component] = texture;
		}

		void SetComponent(PedComponent component, int model, int texture) {
			SetComponentModel(component, model);
			SetComponentTexture(component, texture);
		}

		virtual String^ ToString() override;
		static SkinTemplate^ FromString(String^ input);

	};

}