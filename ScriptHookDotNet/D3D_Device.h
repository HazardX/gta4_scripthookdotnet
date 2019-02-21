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
//namespace Direct3D {

	//namespace base {
	//	interface class iD3DObject;
	//}
	//namespace VertexFormat {
	//	interface class iVertexFormat;
	//}
	//enum class TransformState;
	value class ImageInformation;
	value class Viewport;



	using namespace System;
	//using namespace SlimDX;

	//#pragma unmanaged

	class Direct3DHookNative :
		public ID3DDeviceHook {

		private:

		void OnCreateDevice(ID3DDevice *cDevice, PresentParameters *cPresentParameters) { /* nothing to do here */ }
		void OnResetDevice(ID3DDevice *cDevice, PresentParameters *cPresentParameters);
		void OnLostDevice(ID3DDevice *cDevice);
		void OnDestroyDevice(ID3DDevice *cDevice) { /* nothing to do here */ }
		void OnRender(ID3DDevice *cDevice);

	};

	//#pragma managed

	//using namespace System;
	//using namespace SlimDX;

	private ref class Direct3D sealed {

	private:
		Direct3D() {}

		//static u32 devicePtr = 0;
		//static GTA::Direct3D9::Device^ pDevice;
		static Direct3DHookNative* nativeHook = new Direct3DHookNative();
		static IDirect3DDevice9* cDevice = NULL;
		//static ID3DXSprite* sprite = NULL;
		static bool bDrawing = false;
		static bool bResettedOnce = false;

		static System::Collections::Generic::List<GTA::base::iD3DObject^>^ ObjectList = gcnew System::Collections::Generic::List<GTA::base::iD3DObject^>();

		//static Direct3D();

		~Direct3D() {
			if (nativeHook != NULL) delete nativeHook;
			cDevice = 0;
		}

		//static void Direct3D::CreateSprite();
		//static void Direct3D::BeginSprite(int flags);
		//static void Direct3D::EndSprite();

		static void ReleaseFont(GTA::Font^ Font);
		static void ReleaseTexture(GTA::Texture^ Texture);

	internal:
		static void CheckDevice(IDirect3DDevice9 *device, bool force);
		static void OnDeviceCreated();
		static void OnDeviceLost();
		static void OnRender();

		static void InstallHook();
		static void RemoveHook();
		static void ForceDeviceRelease();
		static void ForceDeviceReset();

		//static void Release(int index);
		static void Release(GTA::base::iD3DObject^ D3DObject);
		static void ReleaseAll(bool permanent);

	public:
		//static property GTA::Direct3D9::Device^ Device {
		//	GTA::Direct3D9::Device^ get() { return pDevice;	}
		//}
		static property bool isDrawing {
			bool get() { return bDrawing;	}
		}

		static property GTA::Viewport Viewport {
			GTA::Viewport get();
		}

		static Matrix GetTransform(TransformState state);
		static void SetTransform(TransformState state, Matrix value);

		//static Vector3 TransformFromObjectToScreen(Vector3 PositionInObject, Matrix ObjectMatrix);

		generic<typename vType, typename iType> where vType: VertexFormats::iVertexFormat
		static void DrawPolygons(array<vType>^ vertices, array<iType>^ indices, int TextureID);

		//static void DrawLine(GTA::Vector3 pos1, GTA::Vector3 pos2, float width1, float width2, int color1, int color2);
		//static void DrawLine(float x1, float y1, float x2, float y2, float width, int color);
		static void DrawLine(GTA::Vector3 pos1, GTA::Vector3 pos2, float width1, float width2, int color1, int color2);
		static void DrawLine(float x1, float y1, float x2, float y2, float width, int color);

		static void DrawBoxFilled(Vector3 CornerTL, Vector3 CornerTR, Vector3 CornerBL, Vector3 CornerBR, int ColorTL, int ColorTR, int ColorBL, int ColorBR);
		static void DrawBoxFilled(Drawing::RectangleF rect, int color);
		static void DrawBoxFilled(float x, float y, float width, float height, int color);

		static void DrawSprite(GTA::Texture^ Texture, Vector3 CornerTL, Vector3 CornerTR, Vector3 CornerBL, Vector3 CornerBR, int ColorTL, int ColorTR, int ColorBL, int ColorBR);
		static void DrawSprite(GTA::Texture^ Texture, Drawing::RectangleF rect, int Color);
		//static void DrawSprite(GTA::Texture^ Texture, float x, float y, float width, float height, float Rotation, int Color);

		static void DrawMouseArrow(int x, int y, int size, int color);
		static void DrawMouseArrow(int x, int y, int size, int color, int borderColor);

		static void DrawString(String^ Text, Drawing::Rectangle area, TextAlignment alignment, int Color, int FontID);
		//static void DrawString(String^ Text, int X, int Y, int Color, int FontPtr);

		/// <summary>
		/// Adds a new Direct3D object to the ObjectCache and returns the ID.
		/// </summary>
		static int AddNewObject(GTA::base::iD3DObject^ object);

		/// <summary>
		/// Creates a new Direct3D Font and returns the pointer. LOCAL ONLY!
		/// </summary>
		static int NewFontInternal(int height, int width, int weight, int mipLevels, bool italic, int charSet, int outputPrecision, int quality, int pitchAndFamily, String^ faceName );

		/// <summary>
		/// Creates a new Direct3D Font and returns the pointer. LOCAL ONLY!
		/// </summary>
		static int NewTextureInternal(array<Byte>^ data, [Out] ImageInformation% imageInformatio);


	};

}