Imports System
Imports System.Windows.Forms
Imports GTA

Public Class GrabScript
   Inherits Script

   Private GrabKey As Keys = Keys.B
   Private GrabKeyShift As Keys = GrabKey Or Keys.Shift
   Private Info As GrabInfo = Nothing
   Private MovingFast As Boolean = False
   Private State As eState = eState.Off

   Private Enum eState
      Off
      TryToGrab
      WaitForDriver
      Driving
      TryToGrabAgain
      WaitToGetUp
   End Enum



   Public Sub New()
      Interval = 250
      GrabKey = Me.Settings.GetValueKey("GrabKey", Keys.B)
      GrabKeyShift = GrabKey Or Keys.Shift
   End Sub

   'Private Function isGrabbed() As Boolean
   '   Return Player.Character.Euphoria.Grab.isGrabbed
   'End Function

   Private Sub LetGo()
      If Info Is Nothing Then Return

      State = eState.Off
      MovingFast = False

      If Not Info.DriverIsPlayer AndAlso Exists(Info.Driver) Then
         Info.Driver.BlockPermanentEvents = False
         Info.Driver.Task.ClearAll()
         Info.Driver.Task.AlwaysKeepTask = False
         Info.Driver.Task.CruiseWithVehicle(Info.Vehicle, 12.0F, True)
      End If

      Info.LetGo()
      Info = Nothing
   End Sub

   Private Sub ShakeLegs(ByVal value As Boolean)
      If value Then
         Player.Character.Euphoria.PedalLegs.Start()
      Else
         Player.Character.Euphoria.PedalLegs.Stop()
      End If
   End Sub

   Private Sub RefeshGrab()
      If Not Info.RefeshGrab() Then Return
      If State = eState.Driving AndAlso MovingFast Then ShakeLegs(True)
   End Sub

   Private Sub GrabScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.KeyWithModifiers <> GrabKey AndAlso e.KeyWithModifiers <> GrabKeyShift Then Return
      If Info IsNot Nothing Then
         LetGo()
      Else
         If Player.Character.isInVehicle OrElse Player.Character.isGettingIntoAVehicle Then Return

         Dim v As Vehicle = World.GetClosestVehicle(Player.Character.GetOffsetPosition(New Vector3(0.0F, 1.5F, 0.0F)), 5.0F)

         'If GrabbedVehicle Is Nothing Then
         '   GrabbedVehicle = GetClosestPlayerVehicle(8.0F)
         '   isPlayer = True
         'End If
         'If GrabbedVehicle Is Nothing Then
         '   GrabbedVehicle = Player.LastVehicle
         '   isPlayer = False
         'End If

         If v Is Nothing Then Return

         Select Case Player.Character.Weapons.CurrentType
            Case Weapon.Handgun_DesertEagle, Weapon.Handgun_Glock, Weapon.Melee_BaseballBat, Weapon.Melee_Knife, Weapon.SMG_MP5, Weapon.SMG_Uzi, Weapon.Thrown_Grenade, Weapon.Thrown_Molotov, Weapon.Unarmed
            Case Else
               Player.Character.Weapons.Unarmed.Select()
         End Select

         Info = DoGrab(Player, v)
         Player.Character.MakeProofTo(False, False, False, True, True)
         State = eState.TryToGrab
      End If
   End Sub

   Private Sub GrabScript_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If Info Is Nothing Then Return
      If Not Exists(Info.Vehicle) Then LetGo() : Return
      If Info.Vehicle.Position.DistanceTo(Player.Character.Position) > 10 Then
         LetGo()
         Return
      End If

      Select Case State

         Case eState.TryToGrab
            If Not Info.isGrabbed() Then
               Info.TryToGrabAgain()
            Else
               State = eState.WaitForDriver
            End If

         Case eState.WaitForDriver
            If Info.isGrabbed() Then

               If Not Info.RefreshDriver() Then
                  RefeshGrab()
               Else
                  If Not Info.DriverIsPlayer Then
                     Info.Driver.BlockPermanentEvents = True
                     Info.Driver.Task.ClearAll()
                     Info.Driver.Task.AlwaysKeepTask = True
                     Info.Driver.Task.CruiseWithVehicle(Info.Vehicle, 70.0F, False)
                  End If
                  Player.Character.MakeProofTo(False, False, False, True, True)
                  State = eState.Driving
               End If
            Else
               State = eState.TryToGrabAgain
            End If

         Case eState.Driving
            If Info.isGrabbed() Then
               RefeshGrab()
               If MovingFast Then
                  If Player.Character.Velocity.Length < 2 Then
                     MovingFast = False
                     ShakeLegs(False)
                  End If
               Else
                  If Player.Character.Velocity.Length > 6 Then
                     MovingFast = True
                     ShakeLegs(True)
                  End If
               End If
            Else
               State = eState.TryToGrabAgain
            End If

      End Select
      If State = eState.TryToGrabAgain Then
         If Not Info.isGrabbed() Then
            Info.TryToGrabAgain()
         Else
            State = eState.WaitForDriver
         End If
      End If

   End Sub

End Class