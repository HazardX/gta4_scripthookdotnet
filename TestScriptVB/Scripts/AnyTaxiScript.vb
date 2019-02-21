Imports System
Imports System.Windows.Forms
Imports GTA

' ### Press N to enter any car as passenger and force the driver to bring you to a remote location... fast!    ###
' ### Press M while he is driving you, to accelerate the time.                                                 ###
' ### My first intend was to let him drive to your waypoint, but reading the waypoint pos is not yet possible. ###
Public Class AnyTaxiScript
   Inherits Script

   Private Enum eState
      Off
      WaitingForPlayer
      Driving
      ReachedTarget
   End Enum

   Private Speed As Integer = 70

   Private SelectedCar As Vehicle
   Private SelectedDriver As Ped
   Private state As eState = eState.Off
   Private Destination As Vector3
   Private ChangedTimescale As Boolean = False

   Public Sub New()
      Interval = 250
   End Sub

   Private Sub AnyTaxiScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      Select Case e.Key

         Case Keys.N
            Select Case state

               Case eState.Off
                  SelectedCar = World.GetClosestVehicle(Player.Character.Position, 5.0F)
                  If Not Exists(SelectedCar) Then Return
                  SelectedDriver = SelectedCar.GetPedOnSeat(VehicleSeat.Driver)
                  If Not Exists(SelectedDriver) Then
                     SelectedDriver = SelectedCar.CreatePedOnSeat(VehicleSeat.Driver) ' create a new driver if there is none
                     If Not Exists(SelectedDriver) Then
                        SelectedCar = Nothing
                        Return
                     End If
                  ElseIf SelectedDriver = Player Then
                     SelectedCar = Nothing
                     SelectedDriver = Nothing
                     Return
                  End If

                  ' force the game to load all path nodes, or he wouldn't be able to find the way to distant locations
                  Game.LoadAllPathNodes = True

                  SelectedCar.DoorLock = 0
                  SelectedCar.MakeProofTo(False, False, False, True, False) ' make the car collision proof, or it will blow up pretty fast

                  ' make sure that the driver won't die from his miserable driving skills
                  SelectedDriver.Invincible = True
                  SelectedDriver.WillFlyThroughWindscreen = False
                  SelectedDriver.CanBeKnockedOffBike = False

                  ' make sure that he will focus on his task
                  SelectedDriver.BlockPermanentEvents = True
                  SelectedDriver.ChangeRelationship(RelationshipGroup.Player, Relationship.Respect)

                  SelectedDriver.Task.ClearAll()
                  SelectedDriver.Task.AlwaysKeepTask = True
                  SelectedDriver.Task.Wait(-1) ' wait until we clear the tasks again

                  If Player.Group.MemberCount > 0 Then
                     ' Group.EnterVehicle will make sure that only members closeby try to enter the vehicle
                     Player.Group.EnterVehicle(SelectedCar, True, True)
                  Else
                     Player.Character.Task.EnterVehicle(SelectedCar, SelectedCar.GetFreePassengerSeat)
                  End If

                  state = eState.WaitingForPlayer

               Case eState.WaitingForPlayer
                  TurnDriverToNormal()
                  state = eState.Off

               Case eState.Driving, eState.ReachedTarget ' change the target
                  If SetDestination() Then
                     ' give the new task to the driver
                     SelectedDriver.BlockPermanentEvents = True
                     SelectedDriver.Task.ClearAll()
                     SelectedDriver.Task.AlwaysKeepTask = True
                     SelectedDriver.Task.DriveTo(SelectedCar, Destination, Speed, False)

                     state = eState.Driving
                  End If

            End Select

         Case Keys.M
            If state = eState.Driving Then ' Accelerate time when M is pressed while driving
               ChangedTimescale = Not ChangedTimescale
               If ChangedTimescale Then
                  Game.TimeScale = 4.0F
               Else
                  Game.TimeScale = 1.0F
               End If
            End If

      End Select
   End Sub

   Private Sub AnyTaxiScript_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If state = 0 Then Return
      Select Case state

         Case eState.WaitingForPlayer
            If Player.Character.isSittingInVehicle(SelectedCar) Then ' player entered the vehicle

               ' the player needs some proofs to... the NPC driving style is just horrible!
               Player.Character.CanBeKnockedOffBike = False
               Player.Character.WillFlyThroughWindscreen = False
               Player.Character.MakeProofTo(False, False, False, True, True)

               If SetDestination() Then
                  ' tell driver where to drive to...
                  SelectedDriver.Task.ClearAll()
                  SelectedDriver.Task.AlwaysKeepTask = True
                  SelectedDriver.Task.DriveTo(SelectedCar, Destination, Speed, False)

                  state = eState.Driving
               Else
                  state = eState.ReachedTarget
               End If

            ElseIf Player.Character.Position.DistanceTo(SelectedCar.Position) > 8 Then ' player got too far away
               TurnDriverToNormal()
               state = eState.Off
            End If

         Case eState.Driving
            If Player.Character.isInVehicle(SelectedCar) Then
               If SelectedCar.Position.DistanceTo2D(Destination) < 10 Then ' we are close to the destination

                  SelectedDriver.Task.ClearAll()
                  SelectedDriver.Task.AlwaysKeepTask = True
                  If SelectedCar.Model.isHelicopter Then
                     SelectedDriver.Task.LandHelicopter(SelectedCar, Destination)
                  Else
                     SelectedDriver.Task.StandStill(-1)
                  End If

                  If ChangedTimescale Then
                     Game.TimeScale = 1.0F
                     ChangedTimescale = False
                  End If

                  Game.DisplayText("Here we are!")

                  state = eState.ReachedTarget

               ElseIf Not SelectedDriver.isInVehicle(SelectedCar) Then ' the driver left the vehicle
                  TurnDriverToNormal()
                  state = eState.Off
               End If
            Else
               TurnDriverToNormal()
               state = eState.Off
            End If

         Case eState.ReachedTarget
            If Not Player.Character.isInVehicle(SelectedCar) Then ' wait for player to get out of the car
               TurnDriverToNormal()
               state = eState.Off
            End If

      End Select
   End Sub

   Private Function SetDestination() As Boolean
      Dim w As Blip = Game.GetWaypoint
      If w Is Nothing Then
         Game.DisplayText("You have to select a waypoint first!")
         Return False
      End If
      Destination = World.GetNextPositionOnStreet(w.Position)
      Game.DisplayText("Driving to " & World.GetStreetName(Destination) & "...")
      Return True
   End Function

   ' revert any settings we have done during the script
   Private Sub TurnDriverToNormal()
      Player.Character.CanBeKnockedOffBike = True
      Player.Character.WillFlyThroughWindscreen = True
      Player.Character.MakeProofTo(False, False, False, False, False)
      Game.LoadAllPathNodes = False
      If ChangedTimescale Then
         Game.TimeScale = 1.0F
         ChangedTimescale = False
      End If
      state = eState.Off
      Dim gotcar As Boolean = Exists(SelectedCar)
      If gotcar Then
         SelectedCar.PassengersLeaveVehicle(True)
         SelectedCar.MakeProofTo(False, False, False, False, False)
      End If
      If Exists(SelectedDriver) Then
         SelectedDriver.Invincible = False
         SelectedDriver.WillFlyThroughWindscreen = True
         SelectedDriver.CanBeKnockedOffBike = True
         SelectedDriver.BlockPermanentEvents = False
         SelectedDriver.ChangeRelationship(RelationshipGroup.Player, Relationship.Like)
         If gotcar Then
            SelectedDriver.Task.ClearAll()
            SelectedDriver.Task.AlwaysKeepTask = True
            SelectedDriver.Task.CruiseWithVehicle(SelectedCar, 20.0F, True)
         End If
      End If
   End Sub

End Class