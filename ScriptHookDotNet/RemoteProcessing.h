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
	private ref class RemoteProcessing sealed {

	private:
		RemoteProcessing() { }
		//static RemoteProcessing();

		static List<GTA::RemoteEventArgs^>^ pTaskList = gcnew List<GTA::RemoteEventArgs^>();
		static GTA::GenericThread^ pThread;

		static property GTA::RemoteScriptDomain^ Domain {
			GTA::RemoteScriptDomain^ get();
		}
		static property GTA::base::Console^ Console {
			GTA::base::Console^ get();
		}
		static property GTA::Player^ Player {
			GTA::Player^ get();
		}

	public:
		static property GTA::NetThread^ Thread {
			GTA::NetThread^ get();
		}

		static void ScheduleTask(RemoteProcessingTask Task, ... array<System::Object^>^ Arguments) {
			pTaskList->Add(gcnew RemoteEventArgs((RemoteEvent)Task, Arguments));
		}


		static void ProcessTask(RemoteEventArgs^ Task);

		static void ProcessTasks() {
			if (pTaskList->Count == 0) return;
			int i = 0;
			while (i < pTaskList->Count) {
				ProcessTask(pTaskList[i]);
				i++;
			}
			pTaskList->Clear();
		}

	};

}