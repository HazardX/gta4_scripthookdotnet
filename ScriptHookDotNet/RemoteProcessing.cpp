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

#include "RemoteProcessing.h"

#include "Game.h"
#include "NetThread.h"
#include "GenericThread.h"
#include "Object.h"
#include "Ped.h"
#include "Player.h"
#include "RemoteScriptDomain.h"
#include "Vehicle.h"
#include "World.h"

#pragma managed

namespace GTA {

	//static RemoteProcessing::RemoteProcessing() {
	//}

	GTA::RemoteScriptDomain^ RemoteProcessing::Domain::get() {
		return RemoteScriptDomain::Instance;
	}

	GTA::NetThread^ RemoteProcessing::Thread::get() {
		if isNULL(pThread) {
			pThread = gcnew GenericThread(Domain, gcnew SomeFunction(&RemoteProcessing::ProcessTasks), "RemoteProcessingThread");
			pThread->Launch();
		}
		return (GTA::NetThread^)pThread;
	}

	GTA::base::Console^ RemoteProcessing::Console::get() {
		return NetHook::Console;
	}
	GTA::Player^ RemoteProcessing::Player::get() {
		return GTA::Game::LocalPlayer;
	}

	[System::Runtime::ExceptionServices::HandleProcessCorruptedStateExceptions]
	void RemoteProcessing::ProcessTask(RemoteEventArgs^ Task) {
		try {
			switch ((RemoteProcessingTask)Task->EventID) {

				case RemoteProcessingTask::TeleportTo: {
					if (Task->ArgumentCount < 1) return;
					GTA::Vector3 pos = (GTA::Vector3)Task->Argument(0);
					Console->Print("Teleport to " + pos.ToString());
					//GTA::Ped^ p = Player->Character;
					//p->Position = pos;
					//if (Task->ArgumentCount >= 2) p->Heading = (float)Task->Argument(1);
					//GTA::World::LoadEnvironmentNow(pos);
					//if (pos.Z == 0.0f) p->Position = GTA::World::GetGroundPosition(pos, GroundType::Highest);
					Player->TeleportTo(pos);
					if (Task->ArgumentCount >= 2) Player->Character->Heading = (float)Task->Argument(1);
					return;
				}

				case RemoteProcessingTask::Spawn: {
					if (Task->ArgumentCount != 2) return;
					GTA::Model pSpawnModel = (GTA::Model)Task->Argument(0);
					GTA::Vector3 pSpawnPosition = (GTA::Vector3)Task->Argument(1);
					if (pSpawnModel.Handle == 0) return;
					if (!pSpawnModel.isValid) { Console->Print("Spawn: Invalid model!"); return; }
					try {
						if (!pSpawnModel.isInMemory) pSpawnModel.LoadToMemoryNow();
						base::iComplexObject^ obj;
						bool bFreeze = false;
						bool bStay = false;
						if (pSpawnModel.isPed) {
							obj = World::CreatePed(pSpawnModel,pSpawnPosition);
						} else if (pSpawnModel.isVehicle) {
							obj = World::CreateVehicle(pSpawnModel,pSpawnPosition);
						} else {
							obj = World::CreateObject(pSpawnModel,World::GetGroundPosition(pSpawnPosition));
							bFreeze = true;
							bStay = true;
						}
						if isNotNULL(obj) {
							obj->CurrentRoom = Player->Character->CurrentRoom;
							obj->Heading = Player->Character->Heading;
							if (bFreeze) obj->FreezePosition = true;
							Thread->Wait(1000);
							World::TriggerCollisionsAt(pSpawnPosition);
							if (!bStay) obj->NoLongerNeeded();
						} else {
							Console->Print("Spawn: Unable to create object!");
						}
					} catchErrors("Spawn Error",)
					return;
				}

				case RemoteProcessingTask::PrintScriptHelp: {
					Domain->PrintScriptHelp();
					return;
				}

			}
		} catchErrors("Error while processing RemoteProcessingTask " + ((RemoteProcessingTask)Task->EventID).ToString(),)
	}

}