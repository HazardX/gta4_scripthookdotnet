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

//typedef unsigned long DWORD;
//#define D3D_FVF_XYZRHW 0x004;
//#define D3D_FVF_DIFFUSE 0x040;

namespace GTA {

	//value class Vector3;

namespace VertexFormats {

	using namespace System;

	private interface class iVertexFormat {
		property int StrideSize {
			int get();
		}
		property DWORD Format {
			DWORD get();
		}
	};

	[Serializable]
	private value class TransformedColored :
		public iVertexFormat {

	public:

      float X, Y, Z, Rhw;
      int Color;

      static const int StrideSize = 20;
		static const DWORD Format = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;

	private:

		virtual int getStrideSize() sealed = iVertexFormat::StrideSize::get {
			return StrideSize;
		}
		virtual DWORD getFormat() sealed = iVertexFormat::Format::get {
			return Format;
		}

	public:

		property Vector3 Position {
			Vector3 get() {
            return Vector3(X, Y, Z);
			}
			void set(Vector3 value) {
            X = value.X;
            Y = value.Y;
            Z = value.Z;
			}
		}

		property Drawing::Color ColorDrawing {
			Drawing::Color get() {
				return Drawing::Color::FromArgb(Color);
			}
			void set(Drawing::Color value) {
            Color = value.ToArgb();
			}
		}

		TransformedColored(float x, float y, float z, float rhw, int color) {
         X = x;
         Y = y;
         Z = z;
         Rhw = rhw;
         Color = color;
		}

		TransformedColored(Vector3 position, float rhw, Drawing::Color color) {
         Position = position;
         Rhw = rhw;
         ColorDrawing = color;
		}

	};

	[Serializable]
	private value class TransformedColoredTextured :
		public iVertexFormat {

	public:

      float X, Y, Z, Rhw;
      int Color;
		float U, V;

      static const int StrideSize = 28;
		static const DWORD Format = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;

	private:

		virtual int getStrideSize() sealed = iVertexFormat::StrideSize::get {
			return StrideSize;
		}
		virtual DWORD getFormat() sealed = iVertexFormat::Format::get {
			return Format;
		}

	public:

		property Vector3 Position {
			Vector3 get() {
            return Vector3(X, Y, Z);
			}
			void set(Vector3 value) {
            X = value.X;
            Y = value.Y;
            Z = value.Z;
			}
		}

		property Drawing::Color ColorDrawing {
			Drawing::Color get() {
				return Drawing::Color::FromArgb(Color);
			}
			void set(Drawing::Color value) {
            Color = value.ToArgb();
			}
		}

		property Vector2 TextureCoordinate {
			Vector2 get() {
            return Vector2(U, V);
			}
			void set(Vector2 value) {
            U = value.X;
            V = value.Y;
			}
		}

		TransformedColoredTextured(float x, float y, float z, float rhw, int color, float u, float v) {
         X = x;
         Y = y;
         Z = z;
         Rhw = rhw;
         Color = color;
			U = u;
			V = v;
		}

		TransformedColoredTextured(Vector3 position, float rhw, Drawing::Color color, Vector2 texCoordinate) {
         Position = position;
         Rhw = rhw;
         ColorDrawing = color;
			TextureCoordinate = texCoordinate;
		}

	};

	//typedef struct {
	//public:
 //     float X, Y, Z, Rhw;
 //     int Color;
 //     static const int StrideSize = 20;
	//	static const DWORD Format = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	//} cTransformedColored;

}
}