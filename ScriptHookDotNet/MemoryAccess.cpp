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

#include "MemoryAccess.h"

#include "cppHook.h"

#pragma managed

namespace unmanaged {
//namespace MemoryAccess {

	int MemoryAccess::GetGlobalAddress(int index) {
		int res;
		try {
			res = cppHook::GetGlobalAddress(index); //*(int*)(ADDRESS_GLOBALLIST);
		} catchErrors ("Error in GetGlobalAddress", res = 0; )
		if ( (res == 0) || (res == (index*4)) ) throw gcnew Exception(GobalsError);
		return res;
	}
	int MemoryAccess::GetGlobalInteger(int index) {
		//if (!GTA::NetHook::isPrimary) return (int)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::GetGlobalInteger, index);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return 0;
		return *(int*)(adr);
	}
	float MemoryAccess::GetGlobalFloat(int index) {
		//if (!GTA::NetHook::isPrimary) return (float)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::GetGlobalFloat, index);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return 0.0f;
		return *(float*)(adr);
	}
	String^ MemoryAccess::GetGlobalString(int index) {
		//if (!GTA::NetHook::isPrimary) return (float)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::GetGlobalFloat, index);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return String::Empty;
		return gcnew String((char*)adr);
	}

	void MemoryAccess::SetGlobal(int index, int value) {
		//if (!GTA::NetHook::isPrimary) return (int)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::SetGlobalInteger, index, value);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return;
		*(int*)(adr) = value;
	}
	void MemoryAccess::SetGlobal(int index, float value) {
		//if (!GTA::NetHook::isPrimary) return (int)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::SetGlobalFloat, index, value);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return;
		*(float*)(adr) = value;
	}
	void MemoryAccess::SetGlobal(int index, String^ value) {
		//if (!GTA::NetHook::isPrimary) return (int)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::SetGlobalFloat, index, value);
		int adr = GetGlobalAddress(index);
		//if (adr == 0) return;
		char* trg = (char*)adr;
		char* ptr = PinStringA(value);
		try {
			memcpy(trg, ptr, value->Length);
		} finally {
			FreeString(ptr);
		}
		*(trg + value->Length) = 0;
	}


	
	int MemoryAccess::GetAddressOfItemInPool(int PoolAddress, int Handle) {
		if (PoolAddress == 0) return 0;
		int listadr =		*(int*)(PoolAddress);
		int booladr =		*(int*)(PoolAddress + 4);
		int maxcount =		*(int*)(PoolAddress + 8);
		int itemsize =		*(int*)(PoolAddress + 12);
		int index = HandleToIndex(Handle);
		u8 flag = *(u8*)(booladr + index);
		if (flag&0x80) return 0;
		if (int(flag) != (Handle & 0x000000FF)) return 0; // doing the parity check
		//if (int(*(u8*)(listadr + index*itemsize + 0x08)) == 0) return 0; // not exactly sure, but seems to be 13 for valid and 0 for invalid items
		return (listadr + index*itemsize);
	}
	int MemoryAccess::GetAddressOfItemInPoolByIndex(int PoolAddress, int index) {
		if (PoolAddress == 0) return 0;
		int listadr =		*(int*)(PoolAddress);
		int booladr =		*(int*)(PoolAddress + 4);
		int maxcount =		*(int*)(PoolAddress + 8);
		int itemsize =		*(int*)(PoolAddress + 12);
		u8 flag = *(u8*)(booladr + index);
		if (flag&0x80) return 0;
		return (listadr + index*itemsize);
	}

	array<int>^ MemoryAccess::GetListOfHandlesInPool(int PoolAddress) {
		List<int>^ list = gcnew List<int>();
		int listadr =		*(int*)(PoolAddress);
		int booladr =		*(int*)(PoolAddress + 4);
		int maxcount =		*(int*)(PoolAddress + 8);
		int itemsize =		*(int*)(PoolAddress + 12);
		int val;
		for (int i = 0; i < maxcount; i++) {
			val =  (int) *(u8*)(booladr + i); // parity value
			if ((val&0x80) == 0) { // wrong was: (val > 0)
				val = (i << 8) | val;
				list->Add(val);
			}
		}
		return list->ToArray();
	}

	int MemoryAccess::GetAddressOfPed(int Handle) {
		return GetAddressOfItemInPool( *(int*)(ADDRESS_PEDPOOL), Handle);
	}
	int MemoryAccess::GetAddressOfVehicle(int Handle) {
		return GetAddressOfItemInPool( *(int*)(ADDRESS_VEHICLEPOOL), Handle);
	}
	int MemoryAccess::GetAddressOfObject(int Handle) {
		return GetAddressOfItemInPool( *(int*)(ADDRESS_OBJECTPOOL), Handle);
	}
	int MemoryAccess::GetAddressOfBlip(int bliphandle) {
		int const *Blips = (int*)(ADDRESS_BLIPLIST);
		int handle;
		for (int i = 0; i<1500; i++) { // max. 1500 blips
			if (Blips[i] != 0) {
				handle = *(int*)(Blips[i] + 0x04);
				if (handle == bliphandle) return Blips[i];
			}
		}
		return 0;
	}

	array<int>^ MemoryAccess::GetPedHandleList() {
		return GetListOfHandlesInPool( *(int*)(ADDRESS_PEDPOOL) );
	}
	array<int>^ MemoryAccess::GetVehicleHandleList() {
		return GetListOfHandlesInPool( *(int*)(ADDRESS_VEHICLEPOOL) );
	}
	array<int>^ MemoryAccess::GetObjectHandleList() {
		return GetListOfHandlesInPool( *(int*)(ADDRESS_OBJECTPOOL) );
	}
	array<int>^ MemoryAccess::GetBlipHandleList() {
		List<int>^ list = gcnew List<int>();
		int const *Blips = (int*)(ADDRESS_BLIPLIST);
		int handle;
		for (int i = 0; i<1500; i++) { // max. 1500 blips
			if (Blips[i] != 0) {
				handle = *(int*)(Blips[i] + 0x04);
				if (handle != 0) list->Add(handle);
			}
		}
		return list->ToArray();
	}

	float MemoryAccess::GetVehicleRPM(int Handle) {
		//if (!GTA::NetHook::isPrimary) return (float)GTA::NetHook::RaiseEventInLocalScriptDomain(GTA::RemoteEvent::GetVehicleRPM, Handle);
		int adr = GetAddressOfVehicle(Handle);
		if (adr == 0) return 0.0f;
		return *(float*)(adr + 0x688);
	}

	GTA::Vector3 MemoryAccess::GetPositionOfVehicle(int Handle) {
		int adr = GetAddressOfVehicle(Handle);
		if (adr == 0) return GTA::Vector3();
		adr = *(int*)(adr+32);
		if (adr == 0) return GTA::Vector3();
		float x = *(float*)(adr + 0x30); 
		float y = *(float*)(adr + 0x34); 
		float z = *(float*)(adr + 0x38);
		return GTA::Vector3(x, y, z);
	}

	GTA::Vector3 MemoryAccess::GetPositionOfBlip(int Handle) {
		int adr = GetAddressOfBlip(Handle);
		if (adr == 0) return GTA::Vector3();
		float x = *(float*)(adr + 0x30); 
		float y = *(float*)(adr + 0x34); 
		float z = *(float*)(adr + 0x38);
		return GTA::Vector3(x, y, z);
	}

	typedef struct {
		//i32 v0;
		//i32 v1;
		//i32 v2;
		//i32 v3;
		//i32 v4;
		//i32 v5;
		//i32 v6;
		//i32 v7;
		//i32 v8;
		//i32 v9;
		//i32 v10;
		//i32 v11;
		//i32 v12;
		//i32 v13;
		//i32 v14;
		//i32 v15;
		//i32 v16;
		//i32 v17;
		//i32 v18;
		//i32 v19;
		//i32 v20;
		//i32 v21;
		//i32 v22;
		//i32 v23;
		//i32 v24;
		//i32 v25;
		//i32 v26;
		//i32 v27;
		//i32 v28;
		//i32 v29;
		//i32 v30;
		//i32 v31;
		int dummy[32];
		char lastCalledNumber[10];
	} sPhoneInfo;

	String^ MemoryAccess::GetPhoneNumber() {
		//if (ADDRESS_PHONENUMBER == 0) return String::Empty;
		//char* pPhoneNumberPtr = (char*)(ADDRESS_PHONENUMBER);
		//return gcnew String(pPhoneNumberPtr);
		//GTA::NetHook::Log("Phone1");
		int adr = GetGlobalAddress(91);
		if (adr == 0) return String::Empty;
		if (adr == 364) throw gcnew Exception("Accessing Globals failed!");
		//GTA::NetHook::Log("Phone2 " + adr.ToString());
		sPhoneInfo pi = *(sPhoneInfo*)(adr);
		//GTA::NetHook::Log("Phone3");
		if ( (pi.lastCalledNumber == 0) || (pi.lastCalledNumber[0] == 0) ) return String::Empty;
		//GTA::NetHook::Log("Phone4");
		return gcnew String(pi.lastCalledNumber);
	}

	//System::IntPtr MemoryAccess::GetDirect3DDevice9() {
	//	return *(System::IntPtr*)(ADDRESS_GETDIRECT3DDEVICE9);
	//}

//}
}