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

#include "Team.h"

#pragma managed

namespace GTA {
namespace Multiplayer {

	Team::Team(int ID) {
		//if (ID > 7) throw new System::Exception("Maximum ID for a Multiplayer.Team is 7!");
		this->pID = ID;
	}

	int Team::ID::get() {
		return pID;
	}

	int Team::MemberCount::get() {
		return Scripting::GetNoOfPlayersInTeam(pID);
	}

	int Team::ColorID::get() {
		u32 pCol = 0;
		Scripting::GetTeamColour(pID,&pCol);
		return pCol;
	}
	void Team::ColorID::set(int value) {
		Scripting::SetTeamColour(pID,value);
	}

	Drawing::Color Team::Color::get() {
		u32 R = 0; u32 G = 0; u32 B = 0;
		Scripting::GetTeamRGBColour(pID,&R,&G,&B);
		return Drawing::Color::FromArgb(R,G,B);
	}

}
}