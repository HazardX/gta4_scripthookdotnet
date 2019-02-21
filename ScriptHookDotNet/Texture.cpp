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

#include "stdafx.h"

#include "Texture.h"

#include "D3D_Device.h"

#pragma managed

namespace GTA {

	void Texture::InitValues() {
		pInternalPointer = 0;
		pD3DObjectID = -1;
	}

	Texture::Texture(array<Byte>^ ImageData) {
		InitValues();
		if ( isNULL(ImageData) || (ImageData->Length == 0) ) throw gcnew Exception("ImageData for Texture is empty!");
		data = ImageData;
		//if (!NetHook::isPrimary) GetD3DObjectID(true);
	}



	Texture::~Texture() { // Dispose
		//Unload(true); DO NOT unload it here! unload does not work in the remote script domain!
		this->!Texture();
	}
	Texture::!Texture() { // Finalize
		//Unload(true);
	}

	//ImageInformation Texture::GetImageInfo() {
	//	int id = GetD3DObjectID(true);
	//	if (id < 0) throw new Exception("Unable to load image information!");

	//}

	void Texture::Unload(bool permanent) {
		if (pInternalPointer != 0) {
			Direct3D::Release(this);
			pInternalPointer = 0;
		}
		if (permanent) {
			pD3DObjectID = -1;
		}
	}

	void Texture::Reload() {
		Unload(false);
		try {
			if ( isNULL(data) || (data->Length == 0) ) throw gcnew Exception("No image data!"); //return;
			pInternalPointer = Direct3D::NewTextureInternal(data, pImageInformation);
		} catchErrors("Texture.GetInternalPointer: Error while creating new texture", pInternalPointer = 0; )
	}

	int Texture::GetInternalPointer(bool retrieveNew) {
		if (!NetHook::isPrimary) throw gcnew Exception("Texture.GetInternalPointer cannot be called from remote script domain!");
		if ( (pInternalPointer == 0) && (retrieveNew) ) Reload();
		return pInternalPointer;
	}

	int Texture::GetD3DObjectID(bool retrieveNew) {
		if ((pD3DObjectID < 0) && retrieveNew) {
			//Direct3D::Release(pD3DObjectID); // DO NOT unload it here! unload does not work in the remote script domain!
			//pD3DObjectID = -1;
			try {
				pD3DObjectID = Direct3D::AddNewObject(this);
			} catchErrors("Texture.GetD3DObjectID: Error while creating new texture", pD3DObjectID = -1; )

			if ( (pD3DObjectID >= 0) && (!NetHook::isPrimary) ) {
				data = nullptr; // make sure that data is deleted in remote domain after is has been passed to the local domain
			}
		}
		return pD3DObjectID;
	}

}