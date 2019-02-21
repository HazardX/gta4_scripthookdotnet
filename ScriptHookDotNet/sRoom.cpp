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

#include "sRoom.h"

#pragma managed

namespace GTA{

	//String^ Room::Name::get() {
	//	//GetStringFromHashKey(pHash)
	//	if (pName == "") pName = gcnew String( Scripting::GetModelNameForDebug((Scripting::eModel)pHash) );
	//	return pName;
	//}

	bool Room::operator == (Room left, Room right) {
		return ( (left.RoomKey == right.RoomKey) && (left.InteriorID == right.InteriorID) );
	}
	bool Room::operator != (Room left, Room right) {
		return !(left == right);
	}

	Room Room::FromString(String^ StringID) {
		if isNULL(StringID) return Room(0,0);
		array<String^>^ vals = StringID->Trim()->Split('_');
		if ((vals->Length != 3) || (vals[0] != "R")) return Room(0,0);
		return Room(Helper::HexToInteger(vals[1]), Helper::HexToInteger(vals[2]));
	}
	String^ Room::ToString() {
		return ( "R_" + Helper::ToHex(pRoomKey) + "_" + Helper::ToHex(pInteriorID) );
	}

}