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

	using namespace System;

	ref class GraphicsEventArgs;

	CLASS_ATTRIBUTES
	public ref class Light sealed : public base::ScriptChild {

	private:
		System::Drawing::Color pColor;
		bool bEnabled;
		float pRange;
		float pIntensity;
		Vector3 pPosition;

		void PerFrameDrawing(Object^ sender, EventArgs^ e);

	internal:


	public:
		Light(System::Drawing::Color Color, float Range, float Intensity, Vector3 Position) {
			bEnabled = false;
			pColor = Color;
			pRange = Range;
			pIntensity = Intensity;
			pPosition = Position;
		}
		Light(System::Drawing::Color Color, float Range, float Intensity) {
			bEnabled = false;
			pColor = Color;
			pRange = Range;
			pIntensity = Intensity;
			pPosition = Vector3();
		}
		Light() {
			bEnabled = false;
			pColor = System::Drawing::Color::White;
			pRange = 3.0F;
			pIntensity = 50.0F;
			pPosition = Vector3();
		}

		property bool Enabled {
			bool get() {
				return bEnabled;
			}
			void set(bool value);
		}

		void Disable() {
			Enabled = false;
		}

		property System::Drawing::Color Color {
			System::Drawing::Color get() {
				return pColor;
			}
			void set(System::Drawing::Color value) {
				pColor = value;
			}
		}

		property Vector3 Position {
			Vector3 get() {
				return pPosition;
			}
			void set(Vector3 value) {
				pPosition = value;
			}
		}

		property float Range {
			float get() {
				return pRange;
			}
			void set(float value) {
				pRange = value;
			}
		}

		property float Intensity {
			float get() {
				return pIntensity;
			}
			void set(float value) {
				pIntensity = value;
			}
		}

	};

}