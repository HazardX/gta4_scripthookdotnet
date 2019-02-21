Imports System
Imports System.Windows.Forms
Imports GTA

Public Class EveryoneGrabMeScript
   Inherits Script

   Private GrabKey As Keys = Keys.B
   Private LetGoKey As Keys = Keys.B Or Keys.Alt
   Private Infos As New List(Of GrabInfo)
   Private WaitingToGetUp As New List(Of Ped)
   Private MovingFast As Boolean = False
   Private Const MaxCount As Integer = 6

   Public Sub New()
      Interval = 250
      GrabKey = Me.Settings.GetValueKey("EveryoneGrabKey", Keys.B)
      LetGoKey = Me.Settings.GetValueKey("EveryoneLetGoKey", Keys.B Or Keys.Alt)
   End Sub

   Private Function isGrabbingAlready(ByVal ped As Ped) As Boolean
      For i As Integer = 0 To Infos.Count - 1
         If Infos(i).Ped = ped Then Return True
      Next
      Return False
   End Function

   Private Sub LetGo(ByVal info As GrabInfo)
      If info Is Nothing Then Return
      info.LetGo()
      Infos.Remove(info)
      If info.Ped.Exists Then
         info.Ped.MakeProofTo(False, False, False, False, False)
         WaitingToGetUp.Add(info.Ped)
      End If
   End Sub
   Private Sub LetEveryoneGo()
      For i As Integer = Infos.Count - 1 To 0 Step -1
         LetGo(Infos(i))
      Next
      Infos.Clear()
   End Sub

   Private Sub EveryoneShakeLegs(ByVal value As Boolean)
      For i As Integer = Infos.Count - 1 To 0 Step -1
         ShakeLegs(Infos(i), value)
      Next
   End Sub
   Private Sub ShakeLegs(ByVal info As GrabInfo, ByVal value As Boolean)
      If value Then
         info.Ped.Euphoria.PedalLegs.Start()
      Else
         info.Ped.Euphoria.PedalLegs.Stop()
      End If
   End Sub

   Private Sub RefeshGrab(ByVal info As GrabInfo)
      If Not Info.RefeshGrab() Then Return
      If MovingFast Then ShakeLegs(info, True)
   End Sub

   Private Sub GrabScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.KeyWithModifiers = LetGoKey Then
         LetEveryoneGo()
         Return
      End If
      If e.KeyWithModifiers <> GrabKey Then Return

      If Infos.Count >= MaxCount Then Return

      Dim v As Vehicle = Player.Character.CurrentVehicle
      If v Is Nothing Then Return

      For Each Ped As Ped In World.GetPeds(v.Position, 10)

         If Ped.isInVehicle OrElse isGrabbingAlready(Ped) Then Continue For

         Select Case Ped.Weapons.CurrentType
            Case Weapon.Handgun_DesertEagle, Weapon.Handgun_Glock, Weapon.Melee_BaseballBat, Weapon.Melee_Knife, Weapon.SMG_MP5, Weapon.SMG_Uzi, Weapon.Thrown_Grenade, Weapon.Thrown_Molotov, Weapon.Unarmed
            Case Else
               Ped.Weapons.Unarmed.Select()
         End Select

         Ped.MakeProofTo(False, False, False, True, True)

         Infos.Add(DoGrab(Ped, v))
         If Infos.Count >= MaxCount Then Exit For

      Next
   End Sub

   Private Sub GrabScript_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If WaitingToGetUp.Count > 0 Then
         For i As Integer = WaitingToGetUp.Count - 1 To 0 Step -1
            If WaitingToGetUp(i).Velocity.Length <= 2.0F Then
               If WaitingToGetUp(i).isRagdoll Then WaitingToGetUp(i).isRagdoll = False
               WaitingToGetUp.RemoveAt(i)
            End If
         Next
      End If

      If Infos.Count = 0 Then Return

      Dim v As Vehicle = Player.Character.CurrentVehicle
      If v Is Nothing Then
         LetEveryoneGo()
         Return
      End If

      If MovingFast AndAlso v.Speed < 2 Then
         MovingFast = False
         EveryoneShakeLegs(False)
      ElseIf Not MovingFast AndAlso v.Speed > 6 Then
         MovingFast = True
         EveryoneShakeLegs(True)
      End If

      For i As Integer = Infos.Count - 1 To 0 Step -1
         TickGrab(Infos(i))
      Next
   End Sub

   Private Sub TickGrab(ByVal info As GrabInfo)
      If Not info.Ped.Exists OrElse info.Vehicle.Position.DistanceTo(info.Ped.Position) > 10 Then
         LetGo(info)
         Return
      End If

      If Not info.isGrabbed() Then
         info.TryToGrabAgain()
      Else
         RefeshGrab(info)
      End If
   End Sub

End Class