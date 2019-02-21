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

#include "ConsoleCommands.h"

#include "Blip.h"
#include "Console.h"
#include "Game.h"
#include "Ped.h"
#include "Player.h"
#include "ScriptDomain.h"
#include "Vehicle.h"
#include "World.h"
#include "mHost.h"

#pragma managed

namespace GTA {

	GTA::Console^ ConsoleCommands::Console::get() {
		return NetHook::LocalConsole;
	}
	GTA::Player^ ConsoleCommands::Player::get() {
		return GTA::Game::LocalPlayer;
	}

	bool ConsoleCommands::ProcessCommand(ConsoleEventArgs^ e) {
		String^ cmd = e->Command->ToLower();

		if (cmd == "help") { // HELP
			Console->Print("Commands:\n\
				AbortScripts       - Abort all .Net scripts. Useful if you want to play multiplayer.\n\
				Autosave           - Trigger an autosave\n\
				Exit               - Leave the game\n\
				Flip               - Put your car on its wheels again.\n\
				Heal               - Heal the player character and repair his current vehicle.\n\
				Minimize           - Minimize the game window. Use Alt+Tab in fullscreen mode.\n\
				ReloadScripts      - Reload any .Net scripts from disk\n\
				RunningScripts     - Lists all currently running .Net scripts.\n\
				Save               - Open save menu\n\
				ScriptHelp         - Displays general info and available console commands for scripts.\n\
				SetDaytime HH:MM   - Sets the current daytime\n\
				SetTimescale x     - Sets the timescale. 1 is normal speed, 2 is double, 0.5 is half, etc.\n\
				ShowPosition       - Displays the current position of the player and writes it to the log file.\n\
				ShowPlayers        - Lists all Players in the current game\n\
				Spawn modelname    - Spawns a ped, vehicle or object, depending on the given model.\n\
				StartScripts       - Start scripts again if they were aborted earlier.\n\
				Teleport x y [z] [h] - Teleport to the given coordinates. Z and heading are optional.\n\
				Teleport WP        - Teleport to your current waypoint (yes, just write down \"WP\")");
			return true;

		//} else if (cmd == "gccollect") { // GCCOLLECT
		//	try {
		//		System::GC::Collect();
		//		NetHook::Log("GC::Collect done!");
		//	} catch(...) {
		//		NetHook::Log("GC::Collect ERROR!!!");
		//	}
		//	return true;

		//} else if (cmd == "dotest") { // DO TEST
		//	try {
		//		GTA::Game::Test();
		//	} catchErrors("Error in Test",)
		//	return true;

		} else if (cmd == "displaytext") { // DISPLAY TEXT
			if (e->ParameterCount < 1) return true;
			int dur = e->Parameter->ToInteger(1);
			if (dur <= 0) dur = 4000;
			NetHook::DisplayText(e->Parameter->ToString(0),dur);
			return true;

		

		} else if (cmd == "abortscripts") { // ABORTSCRIPTS
			if (NetHook::isInsideScript) {
				Console->Print("You can't call 'AbortScripts' from inside a script!");
				return true;
			}
			NetHook::RequestScriptAction(ScriptAction::AbortScripts);
			return true;


		} else if (cmd == "autosave") { // AUTOSAVE
			GTA::Game::DoAutoSave();
			return true;

		} else if (cmd == "flip") { // FLIP
			GTA::Vehicle^ v = GTA::Game::LocalPlayer->Character->CurrentVehicle;
			if isNULL(v) {
				Console->Print("You have to be in a vehicle to call the 'Flip' command!");
				return true;
			}
			NetHook::ScriptDomain->ScheduleForRemoteProcessingThread(RemoteProcessingTask::TeleportTo, v->Position, v->Heading);

		} else if (cmd == "heal") { // HEAL
			GTA::Game::LocalPlayer->Character->Health = 9999999;
			GTA::Game::LocalPlayer->Character->Armor = 9999999;
			GTA::Vehicle^ v = GTA::Game::LocalPlayer->Character->CurrentVehicle;
			if isNotNULL(v) v->Repair();
			return true;


		} else if (cmd == "loadedscripts") { // LOADED SCRIPTS
			Console->Print("Loaded scripts ("+NetHook::ScriptDomain->LoadedScriptCount+"):");
			for each (String^ sn in GTA::NetHook::ScriptDomain->GetLoadedScriptNames()) {
				Console->Print(" - " + sn);
			}
			return true;


		} else if (cmd == "minimize") { // MINIMIZE
			if (Game::isFullscreen)
				Console->Print("Mimimize works only in window mode. Use Alt+Tab in Fullscreen!");
			else
				GTA::NetHook::Minimize();
			return true;


		} else if (cmd == "runningscripts") { // RUNNING SCRIPTS
			Console->Print("Currently running scripts ("+NetHook::ScriptDomain->RunningScriptCount+"):");
			for each (String^ sn in GTA::NetHook::ScriptDomain->GetRunningScriptNames()) {
				Console->Print(" - " + sn);
			}
			return true;


		} else if (cmd == "reloadscripts") { // RELOAD SCRIPTS
			if (NetHook::isInsideScript) {
				Console->Print("You can't call 'ReloadScripts' from inside a script!");
				return true;
			}
			NetHook::ReloadScriptDomain();
			NetHook::RequestScriptAction(ScriptAction::ReloadAndStartScripts);
			//Console->Print(NetHook::ScriptDomain->LoadedScriptCount + " Scripts reloaded!");
			return true;

			
		} else if (cmd == "save") { // SAVE
			Console->Close();
			GTA::Game::ShowSaveMenu();
			return true;


		} else if (cmd == "scripthelp") { // SCRIPT HELP
			//NetHook::ScriptDomain->PrintScriptHelp();
			NetHook::ScriptDomain->ScheduleForRemoteProcessingThread(RemoteProcessingTask::PrintScriptHelp);
			return true;


		} else if (cmd == "setdaytime") { // SET DAYTIME
			if (e->ParameterCount < 1) {
				Console->Print("SetDaytime: A daytime (format HH:MM) is required!");
				return true;
			}
			String^ val = e->Parameter->ToString(0);
			TimeSpan res;
			if (!val->Contains(":") || !TimeSpan::TryParse(e->Parameter->ToString(0),res)) { //"hh:mm"
				Console->Print("SetDaytime: The daytime has to be in format HH:MM !");
				return true;
			}
			World::CurrentDayTime = res;
			return true;


		} else if (cmd == "settimescale") { // SET TIMESCALE
			float val = e->Parameter->ToFloat(0);
			if (val <= 0.0f) val = 1.0f;
			Game::TimeScale = val;


		} else if (cmd == "showplayers") { // SHOW PLAYERS
			array<GTA::Player^>^ p = Game::PlayerList;
			String^ res = "Current Players (" + p->Length + "):";
			for (int i = 0; i < p->Length; i++) {
				res += Environment::NewLine + " - " + p[i]->Name + " (ID " + p[i]->ID.ToString() + ")"; // + ", Index=" + p[i]->Index.ToString() + ")";
			}
			NetHook::Log(res);
			return true;


		} else if (cmd == "showposition") { // SHOWPOSITION
			NetHook::Log("Current Position: " + Player->Character->Position.ToString() + " Heading:" + Helper::FloatToString(Player->Character->Heading) );
			return true;


		} else if (cmd == "spawn") { // SPAWN
			if (e->ParameterCount < 1) {
				Console->Print("Spawn: modelname is required!");
				return true;
			}
			GTA::Model pSpawnModel = e->Parameter[0]->ToUpper();
			if (pSpawnModel.Hash == 0) return true;
			GTA::Vector3 pSpawnPosition = Player->Character->GetOffsetPosition(Vector3(0.0f,5.0f,0.0f));
			//pSpawnTimeout = DateTime::Now + TimeSpan(0,0,5);
			//tickaction = 1;
			NetHook::ScriptDomain->ScheduleForRemoteProcessingThread(RemoteProcessingTask::Spawn, pSpawnModel, pSpawnPosition);
			return true;


		} else if (cmd == "startscripts") { // STARTSCRIPTS
			if (NetHook::isInsideScript) {
				Console->Print("You can't call 'StartScripts' from inside a script!");
				return true;
			}
			NetHook::RequestScriptAction(ScriptAction::StartScripts);
			return true;


		} else if (cmd == "teleport") { // TELEPORT
			GTA::Vector3 pos;
			if (e->ParameterCount == 0) { // no parameter given, store current postion as last command
				String^ cmd = "teleport " + Player->Character->Position.ToString(" ", 2) + " " + Player->Character->Heading.ToString("F2",Globalization::CultureInfo::InvariantCulture);
				Console->Print("Stored as last command: " + cmd);
				Console->AddOldCommand(cmd);
				return true;

			} else if (e->ParameterCount < 3) {
				// wrote "teleport wp" -> warp to the waypoint
				if ( (e->ParameterCount == 1) && ((e->Parameter->ToString(0)->ToLower() == "wp") || (e->Parameter->ToString(0)->ToLower() == "waypoint")) ) {
					Blip^ waypoint = GTA::Game::GetWaypoint();
					if isNULL(waypoint) {
						Console->Print("Teleport to waypoint: You have to select a waypoint first!");
						return true;
					}
					pos = waypoint->Position;

				} else if (e->ParameterCount == 2) {
					pos = e->Parameter->ToVector3(0);
					if (pos.Length() == 0.0f) {
						Console->Print("Teleport: Invalid parameters!");
						return true;
					}
				} else {
					Console->Print("Teleport: Invalid parameters!");
					return true;
				}

			} else {
				pos = e->Parameter->ToVector3(0);
			}
			if (e->ParameterCount >= 4)
				NetHook::ScriptDomain->ScheduleForRemoteProcessingThread(RemoteProcessingTask::TeleportTo, pos, e->Parameter->ToFloat(3));
			else
				NetHook::ScriptDomain->ScheduleForRemoteProcessingThread(RemoteProcessingTask::TeleportTo, pos);

			////if (pos.Z == 0.0f) pos.Z = Player->Character->Position.Z;
			//Console->Print("Teleport to " + pos.ToString());
			//Player->Character->Position = pos;
			//if (e->ParameterCount >= 4) Player->Character->Heading = e->Parameter->ToFloat(3);
			//GTA::Game::LoadEnvironmentNow(pos);
			//if (pos.Z == 0.0f) Player->Character->Position = World::GetGroundPosition(pos, GroundType::Highest);
			return true;


			// ### HOST COMMANDS ###

		} else if (cmd == "kick") { // KICK
			if (!Multiplayer::Host::isHost) {
				Console->Print("Kick: Only the Host can kick players!");
				return true;
			}
			if (e->ParameterCount < 1) {
				Console->Print("Kick: Player ID is required!");
				return true;
			}
			Multiplayer::Host::KickPlayer(gcnew GTA::Player(e->Parameter->ToInteger(0)));

		}
		return false;
	}

	//void ConsoleCommands::Tick() {
	//	//try {
	//	//	if (tickaction == 1) DoSpawn();
	//	//	if (tickaction == 2) DoNoLongerNeeded();
	//	//} catchErrors("Error during ConsoleCommands.Tick",)
	//}

	//void ConsoleCommands::DoSpawn() {
	//	if (pSpawnModel.Handle == 0) {
	//		tickaction = 0; return;
	//	} else if (DateTime::Now > pSpawnTimeout) {
	//		tickaction = 0; return;
	//	} else if (!pSpawnModel.isValid) {
	//		Console->Print("Spawn: Invalid model!");
	//		tickaction = 0; return;
	//	}
	//	try {
	//		if (!pSpawnModel.isInMemory) {
	//			pSpawnModel.LoadToMemory();
	//			return;
	//		}

	//		base::iComplexObject^ obj;
	//		bool bFreeze = false;
	//		bool bStay = false;

	//		if (pSpawnModel.isPed) {
	//			obj = World::CreatePed(pSpawnModel,pSpawnPosition);
	//		} else if (pSpawnModel.isVehicle) {
	//			obj = World::CreateVehicle(pSpawnModel,pSpawnPosition);
	//		} else {
	//			obj = World::CreateObject(pSpawnModel,World::GetGroundPosition(pSpawnPosition));
	//			bFreeze = true;
	//			bStay = true;
	//		}

	//		if isNotNULL(obj) {
	//			obj->CurrentRoom = Player->Character->CurrentRoom;
	//			obj->Heading = Player->Character->Heading;
	//			if (bFreeze) obj->FreezePosition = true;
	//			LastSpawned = obj;
	//			if (!bStay) { // obj->NoLongerNeeded();
	//				tickaction = 2;
	//				pSpawnTimeout = DateTime::Now + TimeSpan(0,0,1);
	//				return;
	//			}
	//		} else {
	//			Console->Print("Spawn: Unable to create object!");
	//		}
	//	} catchErrors("Spawn Error",)
	//	tickaction = 0;
	//}

	//void ConsoleCommands::DoNoLongerNeeded() {
	//	if (DateTime::Now < pSpawnTimeout) return;
	//	World::TriggerCollisionsAt(pSpawnPosition);
	//	if isNotNULL(LastSpawned)
	//		LastSpawned->NoLongerNeeded();
	//	tickaction = 0;
	//}

}