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

#include "PedCollection.h"

#include "Ped.h"

#pragma managed

namespace GTA {

	void PedCollection::OrderByDistanceTo(Vector3 Position) {
		PedDistanceComparer^ compare = gcnew PedDistanceComparer(Position);
		Sort(compare);
	}

	void PedCollection::RemoveDead() {
		for (int i = Count-1; i>=0; i--) {
			if (!default[i]->isAliveAndWell) {
				RemoveAt(i);
			}
		}
	}

	int PedDistanceComparer::Compare(Ped^ x, Ped^ y) {
		float dx = (pos - x->Position).Length();
		float dy = (pos - y->Position).Length();
		if (dx>dy) return 1;
		if (dx<dy) return -1;
		return 0;
	}

}
