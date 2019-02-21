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
	value class Vector3;
}

namespace unmanaged {

	using namespace System;
	using namespace System::Collections::Generic;

	private ref class MemoryAccess {
	private:
		MemoryAccess(){}

		static String^ GobalsError = "Accessing Globals failed! Invalid Memory Address!";

		static u32 ADDRESS_BLIPLIST = 0;
		static u32 ADDRESS_OBJECTPOOL = 0;
		static u32 ADDRESS_PEDPOOL = 0;
		static u32 ADDRESS_VEHICLEPOOL = 0;
		//static u32 ADDRESS_GETDIRECT3DDEVICE9 = 0; //GetDirect3DDevice9
		//static u32 ADDRESS_GLOBALLIST = 0;
		//static u32 ADDRESS_PHONENUMBER = 0;
		//static u32 ADDRESS_PLAYERLIST = 0;

	public:

		// IMPORTANT: EASY way to get the adresses! Run "FunctionAddressScript" or get adresses of object script function manually (subtract baseAddress).
		// Then open IDA Pro and jump to the adresses. Enter the inner function (usually first and only CALL).
		// In the inner function, first call usually takes the index and THE POOL ADDRESS)
		// funcs: GET_CAR_HEALTH, GET_CHAR_HEALTH, SET_OBJECT_VISIBLE, GET_BLIP_COLOUR

		static void Init(u32 BaseAddress, GTA::GameVersion Version) {
			switch (Version) {
				case GTA::GameVersion::v1000:
					ADDRESS_BLIPLIST			= BaseAddress + 0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0;
					ADDRESS_PEDPOOL				= BaseAddress + 0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x013DE9D0;	// itemsize 8400(0x20D0), count 140(0x8C)
					break;
				case GTA::GameVersion::v1010:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FB1AF0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011E73E8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x016EB9A0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011E1540;
					//ADDRESS_GETDIRECT3DDEVICE9	= BaseAddress + 0x0156F56C;
					//ADDRESS_GLOBALLIST			= BaseAddress + 0x015B5A88;
					//ADDRESS_PHONENUMBER			= BaseAddress + 0x0142D7D0;
					//ADDRESS_PLAYERLIST			= BaseAddress + 0x01064808;
					break;
				case GTA::GameVersion::v1020:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FAB470;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011D13C8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x016E37E0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011CB520;
					//ADDRESS_GETDIRECT3DDEVICE9	= BaseAddress + 0x0155F750;
					//ADDRESS_GLOBALLIST			= BaseAddress + 0x015AD8B4;
					//ADDRESS_PHONENUMBER			= BaseAddress + 0x0141E1D0;
					//ADDRESS_PLAYERLIST			= BaseAddress + 0x01009798;
					break;
				case GTA::GameVersion::v1030:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FCA9D0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011F5B38;
					ADDRESS_PEDPOOL				= BaseAddress + 0x017564D8;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011EFC90;
					break;
				case GTA::GameVersion::v1040:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FCFC70;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011FADD8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x0175B77C;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011F4F30;
					break;
				case GTA::GameVersion::v1050:
					ADDRESS_BLIPLIST			= BaseAddress + 0x010D3AF0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x010EBD08;
					ADDRESS_PEDPOOL				= BaseAddress + 0x017DFCA8;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x010E8BD0;
					break;
				case GTA::GameVersion::v1060:
					ADDRESS_BLIPLIST			= BaseAddress + 0x119DD50;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x134FD00;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A72BC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1618260;
					break;
				case GTA::GameVersion::v1070:
					ADDRESS_BLIPLIST			= BaseAddress + 0x119ED50;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x1350CE0;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A82AC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1619240;
					break;
				case GTA::GameVersion::v1110:
					ADDRESS_BLIPLIST			= BaseAddress + 0x1122E20;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x1471440;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A3080;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1621C10;
					break;
				case GTA::GameVersion::v1120:
					ADDRESS_BLIPLIST			= BaseAddress + 0x10C3EA0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x118A660;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18219EC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x15C17B0;
					break;
			}
		}

		static int GetGlobalAddress(int index);
		static int GetGlobalInteger(int index);
		static float GetGlobalFloat(int index);
		static String^ GetGlobalString(int index);
		static void SetGlobal(int index, int value);
		static void SetGlobal(int index, float value);
		static void SetGlobal(int index, String^ value);

		static int HandleToIndex(int Handle) {
			return Handle >> 8;
		}
		static int GetAddressOfItemInPool(int PoolAddress, int Handle);
		static int GetAddressOfItemInPoolByIndex(int PoolAddress, int Index);
		static array<int>^ GetListOfHandlesInPool(int PoolAddress);

		static int GetAddressOfPed(int Handle);
		static int GetAddressOfVehicle(int Handle);
		static int GetAddressOfObject(int Handle);
		static int GetAddressOfBlip(int Handle);

		static array<int>^ GetPedHandleList();
		static array<int>^ GetVehicleHandleList();
		static array<int>^ GetObjectHandleList();
		static array<int>^ GetBlipHandleList();

		static float GetVehicleRPM(int Handle);
		static GTA::Vector3 GetPositionOfVehicle(int Handle);

		static GTA::Vector3 GetPositionOfBlip(int Handle);

		static String^ GetPhoneNumber();

		//static System::IntPtr GetDirect3DDevice9();

	};
}