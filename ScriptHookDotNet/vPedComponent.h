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
	public ref class PedComponent sealed {

	private:
		Ped^ ped;
		GTA::PedComponent pID;

		int GetAvailableTextures(int ModelIndex);

	internal:
		PedComponent(Ped^ ped, GTA::PedComponent ID) {
			this->ped = ped;
			this->pID = ID;
		}
	
	public:

		/// <summary>
		/// Returns the number of available models for the component.
		/// </summary>
		property int AvailableModels { 
			int get();
		}

		/// <summary>
		/// Returns the number of available textures for the currently selected component model.
		/// </summary>
		property int AvailableTextures { 
			int get();
		}

		/// <summary>
		/// Gets or sets the index of the model for this component. Changing it will reset the TextureIndex to 0! (Value range: 0 to AvailableModels-1)
		/// </summary>
		property int ModelIndex { 
			int get();
			void set(int value);
		}

		/// <summary>
		/// Gets or sets the index of the texture for the currently selected component model. (Value range: 0 to AvailableTextures-1)
		/// </summary>
		property int TextureIndex { 
			int get();
			void set(int value);
		}

		/// <summary>
		/// Returns whether or not the given model and texture index combination is valid.
		/// </summary>
		bool isValid(int ModelIndex, int TextureIndex);

		/// <summary>
		/// Changes ModelIndex and TextureIndex at the same time. May throw an ArgumentOutOfRangeException when a given index is invalid.
		/// </summary>
		void Change(int ModelIndex, int TextureIndex);

		/// <summary>
		/// Changes ModelIndex and TextureIndex at the same time. Will do nothing when a given index is invalid.
		/// </summary>
		void ChangeIfValid(int ModelIndex, int TextureIndex) {
			if (!isValid(ModelIndex,TextureIndex)) return;
			Change(ModelIndex,TextureIndex);
		}

		void SetToDefault() {
			ChangeIfValid(0,0);
		};

		static operator GTA::PedComponent (GTA::value::PedComponent^ source);

		static bool operator == ( GTA::value::PedComponent^ left, GTA::value::PedComponent^ right );
		static bool operator != ( GTA::value::PedComponent^ left, GTA::value::PedComponent^ right );

		static bool operator == ( GTA::PedComponent left, GTA::value::PedComponent^ right );
		static bool operator != ( GTA::PedComponent left, GTA::value::PedComponent^ right );

		static bool operator == ( GTA::value::PedComponent^ left, GTA::PedComponent right );
		static bool operator != ( GTA::value::PedComponent^ left, GTA::PedComponent right );

	};

	CLASS_ATTRIBUTES
	public ref class PedComponentCollection sealed {

	private:
		Ped^ ped;
		Dictionary<GTA::PedComponent,GTA::value::PedComponent^>^ pComponentCache;

		value::PedComponent^ Component(GTA::PedComponent component);

	internal:
		PedComponentCollection(Ped^ ped) {
			this->ped = ped;
		}

	public:
		property value::PedComponent^ default[GTA::PedComponent] {
			value::PedComponent^ get(GTA::PedComponent component) {
				return Component(component);
			}
		}

		property value::PedComponent^ Head {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Head); }
		}
		property value::PedComponent^ UpperBody {
			value::PedComponent^ get() { return Component(GTA::PedComponent::UpperBody); }
		}
		property value::PedComponent^ LowerBody {
			value::PedComponent^ get() { return Component(GTA::PedComponent::LowerBody); }
		}
		property value::PedComponent^ Bags {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Bags); }
		}
		property value::PedComponent^ Hand {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Hand); }
		}
		property value::PedComponent^ Feet {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Feet); }
		}
		property value::PedComponent^ Jacket {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Jacket); }
		}
		property value::PedComponent^ Hair {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Hair); }
		}
		property value::PedComponent^ Teeth {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Teeth); }
		}
		property value::PedComponent^ Face {
			value::PedComponent^ get() { return Component(GTA::PedComponent::Face); }
		}

	};

}
}