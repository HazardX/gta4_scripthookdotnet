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

namespace GTA{

	CLASS_ATTRIBUTES
	private ref class ConsoleCommands sealed {

	private:
		//static ConsoleCommands();
		ConsoleCommands() { }

		//static int tickaction = 0;
		//static GTA::Model pSpawnModel;
		//static Vector3 pSpawnPosition;
		//static DateTime pSpawnTimeout;
		//static base::iComplexObject^ LastSpawned;

		static property GTA::Console^ Console {
			GTA::Console^ get();
		}
		static property GTA::Player^ Player {
			GTA::Player^ get();
		}

	public:

		static bool ProcessCommand(ConsoleEventArgs^ e);

		//static void Tick();

		//static void DoSpawn();
		//static void DoNoLongerNeeded();

	};

}