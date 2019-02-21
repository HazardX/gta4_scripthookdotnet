using System;
using System.Windows.Forms;
using GTA;

namespace TestScriptCS {


   // ### Press N to enter any car as passenger and force the driver to bring you to a remote location... fast!    ###
   // ### Press M while he is driving you, to accelerate the time.                                                 ###
   // ### My first intend was to let him drive to your waypoint, but reading the waypoint pos is not yet possible. ###
   public class AnyTaxiScript : Script {

      enum eState {
         Off,
         WaitingForPlayer,
         Driving,
         ReachedTarget,
      }

      float Speed = 70.0f;

      Vehicle SelectedCar = null;
      Ped SelectedDriver = null;
      eState state = eState.Off;
      Vector3 Destination;
      bool ChangedTimescale = false;

      public AnyTaxiScript() {
         Interval = 250;
         this.KeyDown += new GTA.KeyEventHandler(this.AnyTaxiScript_KeyDown);
         this.Tick += new EventHandler(this.AnyTaxiScript_Tick);
      }

      private void AnyTaxiScript_KeyDown(object sender, GTA.KeyEventArgs e) {
         switch (e.Key) {

            case Keys.N:
               switch (state) {

                  case eState.Off:
                     SelectedCar = World.GetClosestVehicle(Player.Character.Position, 5.0F);
                     if (!Exists(SelectedCar)) return;
                     SelectedDriver = SelectedCar.GetPedOnSeat(VehicleSeat.Driver);
                     if (!Exists(SelectedDriver)) {
                        SelectedDriver = SelectedCar.CreatePedOnSeat(VehicleSeat.Driver);
                        if (!Exists(SelectedDriver)) {
                           SelectedCar = null;
                           return;
                        }
                     } else if (SelectedDriver == Player) {
                        SelectedCar = null;
                        SelectedDriver = null;
                        return;
                     }

                     // force the game to load all path nodes, or he wouldn't be able to find the way to distant locations
                     Game.LoadAllPathNodes = true;

                     SelectedCar.DoorLock = 0;
                     SelectedCar.MakeProofTo(false, false, false, true, false); // make the car collision proof, or it will blow up pretty fast

                     // make sure that the driver won't die from his miserable driving skills
                     SelectedDriver.Invincible = true;
                     SelectedDriver.WillFlyThroughWindscreen = false;
                     SelectedDriver.CanBeKnockedOffBike = false;

                     // make sure that he will focus on his task
                     SelectedDriver.BlockPermanentEvents = true;
                     SelectedDriver.ChangeRelationship(RelationshipGroup.Player, Relationship.Respect);

                     SelectedDriver.Task.ClearAll();
                     SelectedDriver.Task.AlwaysKeepTask = true;
                     SelectedDriver.Task.Wait(-1); // wait until we clear the tasks again

                     if (Player.Group.MemberCount > 0)
                        // Group.EnterVehicle will make sure that only members closeby try to enter the vehicle
                        Player.Group.EnterVehicle(SelectedCar, true, true);
                     else
                        Player.Character.Task.EnterVehicle(SelectedCar, SelectedCar.GetFreePassengerSeat());

                     state = eState.WaitingForPlayer;
                     break;

                  case eState.WaitingForPlayer:
                     TurnDriverToNormal();
                     state = eState.Off;
                     break;

                  case eState.Driving: // Change Route
                  case eState.ReachedTarget:
                     if (SetDestination()) {
                        // give the new task to the driver
                        SelectedDriver.BlockPermanentEvents = true;
                        SelectedDriver.Task.ClearAll();
                        SelectedDriver.Task.AlwaysKeepTask = true;
                        SelectedDriver.Task.DriveTo(SelectedCar, Destination, Speed, false);

                        state = eState.Driving;
                     }
                     break;
               }
               break;

            case Keys.M:
               if (state == eState.Driving) { // Accelerate time when M is pressed while driving
                  ChangedTimescale = !ChangedTimescale;
                  if (ChangedTimescale)
                     Game.TimeScale = 4.0F;
                  else
                     Game.TimeScale = 1.0F;
               }
               break;
         }
      }

      private void AnyTaxiScript_Tick(object sender, EventArgs e) {
         if (state == 0) return;
         switch (state) {

            case eState.WaitingForPlayer:
               if (Player.Character.isSittingInVehicle(SelectedCar)) { // player entered the vehicle

                  // the player needs some proofs to... the NPC driving style is just horrible!
                  Player.Character.CanBeKnockedOffBike = false;
                  Player.Character.WillFlyThroughWindscreen = false;
                  Player.Character.MakeProofTo(false, false, false, true, true);
                  
                  if (SetDestination()) {
                     // tell driver where to drive to...
                     SelectedDriver.Task.ClearAll();
                     SelectedDriver.Task.AlwaysKeepTask = true;
                     SelectedDriver.Task.DriveTo(SelectedCar, Destination, Speed, false);

                     state = eState.Driving;
                  } else {
                     state = eState.ReachedTarget;
                  }

               } else if (Player.Character.Position.DistanceTo(SelectedCar.Position) > 8.0f) { // player got too far away
                  TurnDriverToNormal();
                  state = eState.Off;
               }
               break;

            case eState.Driving:
               if (Player.Character.isInVehicle(SelectedCar)) {
                  if (SelectedCar.Position.DistanceTo2D(Destination) < 10.0f) { // we are close to the destination

                     SelectedDriver.Task.ClearAll();
                     SelectedDriver.Task.AlwaysKeepTask = true;
                     if (SelectedCar.Model.isHelicopter)
                        SelectedDriver.Task.LandHelicopter(SelectedCar, Destination);
                     else
                        SelectedDriver.Task.StandStill(-1);

                     if (ChangedTimescale) {
                        Game.TimeScale = 1.0F;
                        ChangedTimescale = false;
                     }

                     Game.DisplayText("Here we are!");

                     state = eState.ReachedTarget;

                  } else if (!SelectedDriver.isInVehicle(SelectedCar)) { // the driver left the vehicle
                     TurnDriverToNormal();
                     state = eState.Off;
                  }
               } else {
                  TurnDriverToNormal();
                  state = eState.Off;
               }
               break;

            case eState.ReachedTarget:
               if (!Player.Character.isInVehicle(SelectedCar)) { // wait for player to get out of the car
                  TurnDriverToNormal();
                  state = eState.Off;
               }
               break;
         }
      }

      private bool SetDestination() {
         Blip w = Game.GetWaypoint();
         if (w == null) {
            Game.DisplayText("You have to select a waypoint first!");
            return false;
         }
         Destination = World.GetNextPositionOnStreet(w.Position);
         Game.DisplayText("Driving to " + World.GetStreetName(Destination) + "...");
         return true;
      }

      // revert any settings we have done during the script
      private void TurnDriverToNormal() {
         Player.Character.CanBeKnockedOffBike = true;
         Player.Character.WillFlyThroughWindscreen = true;
         Player.Character.MakeProofTo(false, false, false, false, false);
         Game.LoadAllPathNodes = false;
         if (ChangedTimescale) {
            Game.TimeScale = 1.0F;
            ChangedTimescale = false;
         }
         state = eState.Off;
         bool gotcar = Exists(SelectedCar);
         if (gotcar) {
            SelectedCar.PassengersLeaveVehicle(true);
            SelectedCar.MakeProofTo(false, false, false, false, false);
         }
         if (Exists(SelectedDriver)) {
            SelectedDriver.Invincible = false;
            SelectedDriver.WillFlyThroughWindscreen = true;
            SelectedDriver.CanBeKnockedOffBike = true;
            SelectedDriver.BlockPermanentEvents = false;
            SelectedDriver.ChangeRelationship(RelationshipGroup.Player, Relationship.Like);
            if (gotcar) {
               SelectedDriver.Task.ClearAll();
               SelectedDriver.Task.AlwaysKeepTask = true;
               SelectedDriver.Task.CruiseWithVehicle(SelectedCar, 12.0f, true);
            }
         }
      }

   }

}