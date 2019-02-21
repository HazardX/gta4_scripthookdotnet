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

		/// <summary>
		/// Defines the various types of surface formats.
		/// </summary>
		/// <unmanaged>D3DFORMAT</unmanaged>
		private enum class Format : System::Int32
		{
			/// <summary>
			/// 32-bit surface format using 2 bits for alpha and 10 bits for color components (red, green, blue).
			/// </summary>
			A2R10G10B10 = D3DFMT_A2R10G10B10,

			/// <summary>
			/// 32-bit surface format using 8 bits for each channel (alpha, red, green, blue). 
			/// </summary>
			A8R8G8B8 = D3DFMT_A8R8G8B8,

			/// <summary>
			/// 32-bit surface format using 8 bits for each color component (red, green, blue).
			/// </summary>
			X8R8G8B8 = D3DFMT_X8R8G8B8,

			/// <summary>
			/// 16-bit surface format using 1 bit for alpha and 5 bits for each channel (red, green, blue).
			/// </summary>
			A1R5G5B5 = D3DFMT_A1R5G5B5,

			/// <summary>
			/// 16-bit surface format using 5 bits for each color component (red, green, blue).
			/// </summary>
			X1R5G5B5 = D3DFMT_X1R5G5B5,

			/// <summary>
			/// 16-bit surface format using 5 bits for red and blue and 6 bits for green.
			/// </summary>
			R5G6B5 = D3DFMT_R5G6B5,

			/***/

			/// <summary>
			/// 16-bit z-buffer lockable format with 16 bits for depth.
			/// </summary>
			D16Lockable = D3DFMT_D16_LOCKABLE,

			/// <summary>
			/// 32-bit z-buffer format with 32 bits for depth.
			/// </summary>
			D32 = D3DFMT_D32,

			/// <summary>
			/// 16-bit z-buffer format with 15 bits for depth and 1 bit for stencil.
			/// </summary>
			D15S1 = D3DFMT_D15S1,

			/// <summary>
			/// 32-bit z-buffer format with 24 bits for depth and 8 bits for stencil.
			/// </summary>
			D24S8 = D3DFMT_D24S8,

			/// <summary>
			/// 32-bit z-buffer format with 24 bits for depth.
			/// </summary>
			D24X8 = D3DFMT_D24X8,

			/// <summary>
			/// 32-bit z-buffer format with 24 bits for depth and 4 bits for stencil.
			/// </summary>
			D24X4S4 = D3DFMT_D24X4S4,

			/// <summary>
			/// 32-bit z-buffer lockable format with 32 bits for depth (in standard IEEE floating point format).
			/// </summary>
			D32SingleLockable = D3DFMT_D32F_LOCKABLE,

			/// <summary>
			/// 32-bit z-buffer format with 24 bits for depth (in 24-bit floating point format) and 8 bits for stencil.
			/// </summary>
			D24SingleS8 = D3DFMT_D24FS8,

			/// <summary>
			/// Lockable 32-bit depth buffer. Available for Direct3D9Ex only.
			/// </summary>
			D32Lockable = D3DFMT_D32_LOCKABLE,

			/// <summary>
			/// Lockable 8-bit stencil buffer. Available for Direct3D9Ex only.
			/// </summary>
			S8Lockable = D3DFMT_S8_LOCKABLE,

			/// <summary>
			/// 16-bit z-buffer format with 16 bits for depth.
			/// </summary>
			D16 = D3DFMT_D16,

			/***/

			/// <summary>
			/// Describes a vertex buffer surface.
			/// </summary>
			VertexData = D3DFMT_VERTEXDATA,

			/// <summary>
			/// 16-bit index buffer bit depth.
			/// </summary>
			Index16 = D3DFMT_INDEX16,

			/// <summary>
			/// 32-bit index buffer bit depth.
			/// </summary>
			Index32 = D3DFMT_INDEX32,

			/***/		

			/// <summary>
			/// DXT1 compression texture format.
			/// </summary>
			Dxt1 = D3DFMT_DXT1,

			/// <summary>
			/// DXT2 compression texture format.
			/// </summary>
			Dxt2 = D3DFMT_DXT2,

			/// <summary>
			/// DXT3 compression texture format.
			/// </summary>
			Dxt3 = D3DFMT_DXT3,

			/// <summary>
			/// DXT4 compression texture format.
			/// </summary>
			Dxt4 = D3DFMT_DXT4,

			/// <summary>
			/// DXT5 compression texture format.
			/// </summary>
			Dxt5 = D3DFMT_DXT5,

			/***/

			/// <summary>
			/// 16-bit floating point format using 16 bits for the red channel.
			/// </summary>
			R16F = D3DFMT_R16F,

			/// <summary>
			/// 32-bit floating point format using 16 bits for the red channel and 16 bits for the green channel.
			/// </summary>
			G16R16F = D3DFMT_G16R16F,

			/// <summary>
			/// 64-bit floating point format using 16 bits for each channel (alpha, blue, green, red).
			/// </summary>
			A16B16G16R16F = D3DFMT_A16B16G16R16F,

			/***/

			/// <summary>
			/// Multielement texture.
			/// </summary>
			Multi2Argb8 = D3DFMT_MULTI2_ARGB8,

			/// <summary>
			/// 16-bit packed RGB format consisting of pixel pairs to express color.
			/// </summary>
			G8R8_G8B8 = D3DFMT_G8R8_G8B8,

			/// <summary>
			/// 16-bit packed RGB format consisting of pixel pairs to express color.
			/// </summary>
			R8G8_B8G8 = D3DFMT_R8G8_B8G8,

			/// <summary>
			/// UYUV format (PC98 compliance).
			/// </summary>
			Uyvy = D3DFMT_UYVY,

			/// <summary>
			/// YUY2 format (PC98 compliance).
			/// </summary>
			Yuy2 = D3DFMT_YUY2,

			/***/

			/// <summary>
			/// 32-bit floating point format using 32 bits for the red channel.
			/// </summary>
			R32F = D3DFMT_R32F,

			/// <summary>
			/// 64-bit floating point format using 32 bits for the red channel and 32 bits for the green channel.
			/// </summary>
			G32R32F = D3DFMT_G32R32F,

			/// <summary>
			/// 128-bit floating point format using 32 bits for each channel (alpha, blue, green, red).
			/// </summary>
			A32B32G32R32F = D3DFMT_A32B32G32R32F,

			/***/

			/// <summary>
			/// 16-bit bump map format using 6 bits for luminance and 5 bits each for V and U.
			/// </summary>
			L6V5U5 = D3DFMT_L6V5U5,

			/// <summary>
			/// 32-bit bump map format using 8 bits for each channel (luminance, V, U).
			/// </summary>
			X8L8V8U8 = D3DFMT_X8L8V8U8,

			/// <summary>
			/// 32-bit bump map format using 2 bits for alpha and 10 bits each for W, V, and U.
			/// </summary>
			A2W10V10U10 = D3DFMT_A2W10V10U10,

			/***/

			/// <summary>
			/// 16-bit bump map format using 8 bits each for U and V.
			/// </summary>
			V8U8 = D3DFMT_V8U8,

			/// <summary>
			/// 32-bit bump map format using 8 bits for each channel (Q, W, V, U).
			/// </summary>
			Q8W8V8U8 = D3DFMT_Q8W8V8U8,

			/// <summary>
			/// 32-bit bump map format using 16 bits each for V and U.
			/// </summary>
			V16U16 = D3DFMT_V16U16,

			/// <summary>
			/// 64-bit bump map format using 16 bits for each channel (Q, W, V, U).
			/// </summary>
			Q16W16V16U16 = D3DFMT_Q16W16V16U16,

			/// <summary>
			/// 16-bit normal compression format.
			/// </summary>
			CxV8U8 = D3DFMT_CxV8U8,

			/***/

			/// <summary>
			/// 24-bit RGB format using 8 bits per channel.
			/// </summary>
			R8G8B8 = D3DFMT_R8G8B8,

			/// <summary>
			/// 16-bit ARGB format using 4 bits for each channel.
			/// </summary>
			A4R4G4B4 = D3DFMT_A4R4G4B4,

			/// <summary>
			/// 8-bit RGB format using 3 bits for red and green and 2 bits for blue.
			/// </summary>
			R3G3B2 = D3DFMT_R3G3B2,

			/// <summary>
			/// 8-bit alpha format.
			/// </summary>
			A8 = D3DFMT_A8,

			/// <summary>
			/// 16-bit ARGB format using 8 bits for alpha, 3 bits for red and green, and 2 bits for blue.
			/// </summary>
			A8R3G3B2 = D3DFMT_A8R3G3B2,

			/// <summary>
			/// 16-bit RGB format using 4 bits for each color channel.
			/// </summary>
			X4R4G4B4 = D3DFMT_X4R4G4B4,

			/// <summary>
			/// 32-bit ABGR format using 2 bits for alpha and 10 bits for each color component.
			/// </summary>
			A2B10G10R10 = D3DFMT_A2B10G10R10,

			/// <summary>
			/// 32-bit ABGR format using 8 bits for each channel.
			/// </summary>
			A8B8G8R8 = D3DFMT_A8B8G8R8,

			/// <summary>
			/// 32-bit BGR format using 8 bits for each color channel.
			/// </summary>
			X8B8G8R8 = D3DFMT_X8B8G8R8,

			/// <summary>
			/// 32-bit pixel format using 16 bits each for green and red.
			/// </summary>
			G16R16 = D3DFMT_G16R16,

			/// <summary>
			/// 64-bit pixel ABGR format using 16 bits for each channel.
			/// </summary>
			A16B16G16R16 = D3DFMT_A16B16G16R16,

			/// <summary>
			/// 8-bit color indexed with 8 bits of alpha.
			/// </summary>
			A8P8 = D3DFMT_A8P8,

			/// <summary>
			/// 8-bit color indexed.
			/// </summary>
			P8 = D3DFMT_P8,

			/// <summary>
			/// 16-bit luminance.
			/// </summary>
			L16 = D3DFMT_L16,

			/// <summary>
			/// 8-bit luminance.
			/// </summary>
			L8 = D3DFMT_L8,

			/// <summary>
			/// 16-bit format using 8 bits each for alpha and luminance.
			/// </summary>
			A8L8 = D3DFMT_A8L8,

			/// <summary>
			/// 8-bit format using 4 bits each for alpha and luminance.
			/// </summary>
			A4L4 = D3DFMT_A4L4,

			/// <summary>
			/// 1-bit monochrome format. Available for Direct3D9Ex only.
			/// </summary>
			A1 = D3DFMT_A1,

			/// <summary>
			/// Binary buffer format indicating that the data has no inherent type. Available for Direct3D9Ex only.
			/// </summary>
			BinaryBuffer = D3DFMT_BINARYBUFFER,

			/***/

			///// <summary>
			///// Surface format for Render-To-Vertex-Buffer (R2VB).
			///// </summary>
			//ATI_R2VB = R2VB_FOURCC_R2VB,

			/***/

			/// <summary>
			/// Unknown surface format.
			/// </summary>
			Unknown = D3DFMT_UNKNOWN,
		};

		/// <summary>
		/// Describes the supported image file formats.
		/// </summary>
		/// <unmanaged>D3DXIMAGE_FILEFORMAT</unmanaged>
		private enum class ImageFileFormat : System::Int32
		{
			/// <summary>
			/// Windows bitmap (BMP) file format. 
			/// </summary>
			Bmp = 0, //D3DXIFF_BMP,

			/// <summary>
			/// Joint Photographics Experts Group (JPEG) compressed file format.
			/// </summary>
			Jpg = 1, //D3DXIFF_JPG,

			/// <summary>
			/// Truevision (Targa, or TGA) image file format.
			/// </summary>
			Tga = 2, //D3DXIFF_TGA,

			/// <summary>
			/// Portable Network Graphics (PNG) file format.
			/// </summary>
			Png = 3, //D3DXIFF_PNG,

			/// <summary>
			/// DirectDraw surface (DDS) file format.
			/// </summary>
			Dds = 4, //D3DXIFF_DDS,

			/// <summary>
			/// Portable pixmap (PPM) file format.
			/// </summary>
			Ppm = 5, //D3DXIFF_PPM,

			/// <summary>
			/// Windows device-independent bitmap (DIB) file format.
			/// </summary>
			Dib = 6, //D3DXIFF_DIB,

			/// <summary>
			/// High dynamic range (HDR) file format.
			/// </summary>
			Hdr = 7, //D3DXIFF_HDR,

			/// <summary>
			/// Portable float map file format.
			/// </summary>
			Pfm = 8, //D3DXIFF_PFM,
		};

		/// <summary>
		/// Defines resource types.
		/// </summary>
		/// <unmanaged>D3DRESOURCETYPE</unmanaged>
		private enum class ResourceType : System::Int32
		{
			/// <summary>
			/// Surface resource.
			/// </summary>
			Surface = D3DRTYPE_SURFACE,

			/// <summary>
			/// Volume resource.
			/// </summary>
			Volume = D3DRTYPE_VOLUME,

			/// <summary>
			/// Texture resource.
			/// </summary>
			Texture = D3DRTYPE_TEXTURE,

			/// <summary>
			/// Volume texture resource.
			/// </summary>
			VolumeTexture = D3DRTYPE_VOLUMETEXTURE,

			/// <summary>
			/// Cube texture resource.
			/// </summary>
			CubeTexture = D3DRTYPE_CUBETEXTURE,

			/// <summary>
			/// Vertex buffer resource.
			/// </summary>
			VertexBuffer = D3DRTYPE_VERTEXBUFFER,

			/// <summary>
			/// Index buffer resource.
			/// </summary>
			IndexBuffer = D3DRTYPE_INDEXBUFFER,
		};

		/// <summary>
		/// Defines texture filtering modes for a texture stage.
		/// </summary>
		/// <unmanaged>D3DTEXTUREFILTERTYPE</unmanaged>
		private enum class TextureFilter : System::Int32
		{
			/// <summary>
			/// Mipmapping is disabled.
			/// </summary>
			None = D3DTEXF_NONE,

			/// <summary>
			/// Point filtering is used.
			/// </summary>
			Point = D3DTEXF_POINT,

			/// <summary>
			/// Bilinear interpolation is used.
			/// </summary>
			Linear = D3DTEXF_LINEAR,

			/// <summary>
			/// Anisotropic interpolation is used.
			/// </summary>
			Anisotropic = D3DTEXF_ANISOTROPIC,

			/// <summary>
			/// A 4 sample tent filter is used.
			/// </summary>
			PyramidalQuad = D3DTEXF_PYRAMIDALQUAD,

			/// <summary>
			/// A 4 sample Guassian filter is used.
			/// </summary>
			GaussianQuad = D3DTEXF_GAUSSIANQUAD,

			/// <summary>
			/// Convolution filter for monochrome textures. Available for Direct3D9Ex only.
			/// </summary>
			ConvolutionMono = D3DTEXF_CONVOLUTIONMONO
		};

		/// <summary>
		/// Defines possible transformation states.
		/// </summary>
		/// <unmanaged>D3DTRANSFORMSTATETYPE</unmanaged>
		private enum class TransformState : System::Int32
		{
			/// <summary>
			/// Identifies the transformation matrix being set as the view transformation matrix.
			/// </summary>
			View = D3DTS_VIEW,

			/// <summary>
			/// Identifies the transformation matrix being set as the projection transformation matrix.
			/// </summary>
			Projection = D3DTS_PROJECTION,

			/// <summary>
			/// Identifies the transformation matrix being set as a world transformation matrix.
			/// </summary>
			World = D3DTS_WORLD,

			/// <summary>
			/// Identifies the transformation matrix being set as a world transformation matrix.
			/// </summary>
			World1 = D3DTS_WORLD1,

			/// <summary>
			/// Identifies the transformation matrix being set as a world transformation matrix.
			/// </summary>
			World2 = D3DTS_WORLD2,

			/// <summary>
			/// Identifies the transformation matrix being set as a world transformation matrix.
			/// </summary>
			World3 = D3DTS_WORLD3,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture0 = D3DTS_TEXTURE0,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture1 = D3DTS_TEXTURE1,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture2 = D3DTS_TEXTURE2,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture3 = D3DTS_TEXTURE3,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture4 = D3DTS_TEXTURE4,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture5 = D3DTS_TEXTURE5,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture6 = D3DTS_TEXTURE6,

			/// <summary>
			/// Identifies the transformation matrix being set for the specified texture stage.
			/// </summary>
			Texture7 = D3DTS_TEXTURE7
		};

		/// <summary>
		/// Specifies codes that can be used to define Flexible-Vertex-Formats (FVF).
		/// </summary>
		/// <unmanaged>D3DFVF</unmanaged>
		[System::Flags]
		private enum class VertexFormat : System::Int32
		{
			/// <summary>
			/// No vertex format defined.
			/// </summary>
			None = 0,

			/***/

			/// <summary>
			/// Vertex format includes a vertex normal vector.
			/// </summary>
			Normal = D3DFVF_NORMAL,

			/// <summary>
			/// Vertex format contains a point size.
			/// </summary>
			PointSize = D3DFVF_PSIZE,

			/// <summary>
			/// Vertex format includes a diffuse color component.
			/// </summary>
			Diffuse = D3DFVF_DIFFUSE,

			/// <summary>
			/// Vertex format includes a specular color component.
			/// </summary>
			Specular = D3DFVF_SPECULAR,

			/// <summary>
			/// Vertex format includes the position of an untransformed vertex.
			/// </summary>
			Position = D3DFVF_XYZ,

			/// <summary>
			/// Vertex format includes the position of a transformed vertex.
			/// </summary>
			PositionRhw = D3DFVF_XYZRHW,

			/// <summary>
			/// Vertex format contains position and weighting values for multimatrix blending operations.
			/// </summary>
			PositionBlend1 = D3DFVF_XYZB1,

			/// <summary>
			/// Vertex format contains position and weighting values for multimatrix blending operations.
			/// </summary>
			PositionBlend2 = D3DFVF_XYZB2,

			/// <summary>
			/// Vertex format contains position and weighting values for multimatrix blending operations.
			/// </summary>
			PositionBlend3 = D3DFVF_XYZB3,

			/// <summary>
			/// Vertex format contains position and weighting values for multimatrix blending operations.
			/// </summary>
			PositionBlend4 = D3DFVF_XYZB4,

			/// <summary>
			/// Vertex format contains position and weighting values for multimatrix blending operations.
			/// </summary>
			PositionBlend5 = D3DFVF_XYZB5,

			/// <summary>
			/// Vertex format contains transformed and clipped data.
			/// </summary>
			PositionW = D3DFVF_XYZW,

			/// <summary>
			/// Vertex format contains a position and a normal.
			/// </summary>
			PositionNormal = Position | Normal,

			/***/

			/// <summary>
			/// Vertex format contains no texture coordinate sets.
			/// </summary>
			Texture0 = D3DFVF_TEX0,

			/// <summary>
			/// Vertex format contains 1 texture coordinate set.
			/// </summary>
			Texture1 = D3DFVF_TEX1,

			/// <summary>
			/// Vertex format contains 2 texture coordinate sets.
			/// </summary>
			Texture2 = D3DFVF_TEX2,

			/// <summary>
			/// Vertex format contains 3 texture coordinate sets.
			/// </summary>
			Texture3 = D3DFVF_TEX3,

			/// <summary>
			/// Vertex format contains 4 texture coordinate sets.
			/// </summary>
			Texture4 = D3DFVF_TEX4,

			/// <summary>
			/// Vertex format contains 5 texture coordinate sets.
			/// </summary>
			Texture5 = D3DFVF_TEX5,

			/// <summary>
			/// Vertex format contains 6 texture coordinate sets.
			/// </summary>
			Texture6 = D3DFVF_TEX6,

			/// <summary>
			/// Vertex format contains 7 texture coordinate sets.
			/// </summary>
			Texture7 = D3DFVF_TEX7,

			/// <summary>
			/// Vertex format contains 8 texture coordinate sets.
			/// </summary>
			Texture8 = D3DFVF_TEX8,

			/***/

			/// <summary>
			/// Mask for position bits.
			/// </summary>
			PositionMask = D3DFVF_POSITION_MASK,

			/// <summary>
			/// Mask for texture flag bits.
			/// </summary>
			TextureCountMask = D3DFVF_TEXCOUNT_MASK,

			/***/

			/// <summary>
			/// The number of bits by which to shift an integer value that identifies the number of texture 
			/// coordinates for a vertex.
			/// </summary>
			TextureCountShift = D3DFVF_TEXCOUNT_SHIFT,

			/// <summary>
			/// The last beta field in the vertex position data will be of type UByte4. The data in the beta 
			/// fields are used with matrix palette skinning to specify matrix indices.
			/// </summary>
			LastBetaUByte4 = D3DFVF_LASTBETA_UBYTE4,

			/// <summary>
			/// The last beta field in the vertex position data will be of type Color. The data in the beta 
			/// fields are used with matrix palette skinning to specify matrix indices.
			/// </summary>
			LastBetaColor = D3DFVF_LASTBETA_D3DCOLOR
		};



}