Imports GTA

Friend Enum ePosition
   Top
   Left
   Right
   Front
   Back
   Unknown
End Enum

Friend Class GrabInfo

   Private bActive As Boolean
   Public Player As Player
   Public Ped As Ped
   Public Vehicle As Vehicle
   Public Driver As Ped
   Public DriverIsPlayer As Boolean = False
   Public Position As ePosition
   Public Time As Integer

   Public Function isGrabbed() As Boolean
      Return Ped.Euphoria.Grab.isGrabbed
   End Function

   Public Function isBalanced() As Boolean
      Return Ped.Euphoria.BodyBalance.isBalanced
   End Function

   Public Sub New(ByVal Ped As Ped, ByVal Vehicle As Vehicle, ByVal Position As ePosition, ByVal Time As Integer)
      Me.Ped = Ped
      Me.Vehicle = Vehicle
      Me.Position = Position
      Me.Time = Time
      RefreshDriver()
      Me.bActive = True
   End Sub

   Public Function RefreshDriver() As Boolean
      DriverIsPlayer = False
      If Vehicle Is Nothing OrElse Not Vehicle.Exists Then
         Driver = Nothing
         Return False
      End If
      Driver = Vehicle.GetPedOnSeat(VehicleSeat.Driver)
      If Driver Is Nothing Then Return False
      If (Driver = Game.LocalPlayer.Character) OrElse (Driver.GetControllingPlayer() IsNot Nothing) Then
         'Driver = Nothing ' do not store driver when he is a player
         'Return False
         DriverIsPlayer = True
      End If
      Return True
   End Function

   Public Sub TryToGrabAgain()
      Dim info As GrabInfo
      If Player Is Nothing Then
         info = DoGrab(Ped, Vehicle)
      Else
         info = DoGrab(Player, Vehicle)
      End If
      bActive = True
      Driver = info.Driver
      DriverIsPlayer = info.DriverIsPlayer
      Position = info.Position
      Time = info.Time
   End Sub

   Public Function RefeshGrab() As Boolean
      If Game.GameTime - Time < 40000 Then Return False '40000
      Time = Game.GameTime
      Ped.Euphoria.Grab.Start(-1)
      'If State = eState.Driving AndAlso MovingFast Then ShakeLegs(True)
      Return True
   End Function

   Public Sub LetGo()
      If Not bActive Then Return
      bActive = False

      Ped.MakeProofTo(False, False, False, False, False)

      Ped.Euphoria.Grab.Stop()
      Ped.Euphoria.PedalLegs.Stop()

      If Player IsNot Nothing Then

         Do While Ped.Velocity.Length > 2.0F
            Game.WaitInCurrentScript(0)
         Loop
         If Ped.isRagdoll Then Ped.isRagdoll = False

      End If
   End Sub



End Class

Friend Module Tools

   Public Function GetPosition(ByVal ped As Ped, ByVal car As Vehicle) As ePosition
      Dim vo As Vector3 = car.GetOffset(ped.Position)
      If vo.Z > 0.75 Then
         Return ePosition.Top
      ElseIf vo.Y > 1.5 Then
         Return ePosition.Front
      ElseIf vo.Y < -1.5 Then
         Return ePosition.Back
      ElseIf vo.X > 0.5 Then
         Return ePosition.Right
      ElseIf vo.X < -0.5 Then
         Return ePosition.Left
      Else
         Return ePosition.Unknown
      End If
   End Function

   Public Function DoGrab(ByVal player As Player, ByVal car As Vehicle) As GrabInfo
      Dim res As GrabInfo = DoGrab(player.Character, car)
      player.CanControlRagdoll = True
      res.Player = player
      Return res
   End Function

   Public Function DoGrab(ByVal ped As Ped, ByVal car As Vehicle) As GrabInfo
      ped.Euphoria.BodyBalance.Start(-1)

      With ped.Euphoria.LeanToPosition
         .Position = car.Position
         .Amount = 1.5F
         .ApplyAsForce = True
         .Start()
      End With

      Return DoGrab(ped, car, GetPosition(ped, car))
   End Function

   Private Function DoGrab(ByVal ped As Ped, ByVal car As Vehicle, ByVal pos As ePosition) As GrabInfo
      Dim info As New GrabInfo(ped, car, pos, Game.GameTime)

      Dim min, max As Vector3
      car.Model.GetDimensions(min, max)


      Dim CarRoof As Single = max.Z - 0.1F 'car.HeightOffset * 1.35F
      Dim CarRoofFront As Single = CarRoof * 0.25F '0.75F
      Dim CarFront As Single = max.Y - 0.1F '2.0F
      Dim CarBack As Single = min.Y + 0.1F '-2.0F
      Dim CarSide As Single = max.X - 0.1F '0.9F
      Dim CarSideRoof As Single = CarSide * 0.9F '0.9F
      Dim CarBottom As Single = 0.4F + min.Z '0.0F
      Dim GrabHeight As Single = Math.Min(0.9F + min.Z, (max.Z - min.Z) * 0.5F - min.Z) '0.3F '0.9 above floor or half of total vehicle height

      If car.Model.isBike Then
         CarRoofFront = 0.5F
         'CarRoof = car.HeightOffset
         'CarFront = 0.5F
         'CarBack = -0.5F
         'CarSide = 0.3F
         'CarBottom = 0.0F
         GrabHeight = 0.28F '((CarRoof * 2) * 0.45F) - CarRoof ' 45% Height
      ElseIf car.Model.isHelicopter Then
         CarRoofFront = 3.0F
         CarRoof = 1.3F
         CarFront = 4.0F
         CarBack = -3.0F
         CarSide = 1.15F
         CarBottom = -1.0F
         GrabHeight = -0.1F
      ElseIf car.Model.isTrain Then
         CarRoofFront = CarFront 'CarRoofFront = 6.0F
         'CarRoof = 2.0F
         'CarFront = 6.0F
         'CarBack = -6.0F
         'CarSide = 1.6F
         CarBottom = -1.0F
         GrabHeight = 0.5F
      End If

      With ped.Euphoria.Grab
         .ItemToGrab = car

         Select Case pos
            Case ePosition.Top
               .GrabMethod = Euphoria.GrabMethod.Surface
               .Offset1 = New Vector3(-CarSideRoof, CarRoofFront, CarRoof)
               .Offset2 = New Vector3(-CarSideRoof, CarBack, CarRoof)
               .Offset3 = New Vector3(CarSideRoof, CarBack, CarRoof)
               .Offset4 = New Vector3(CarSideRoof, CarRoofFront, CarRoof)

            Case ePosition.Front
               .GrabMethod = Euphoria.GrabMethod.Line
               .Offset1 = New Vector3(-CarSide, CarFront, GrabHeight)
               .Offset2 = New Vector3(CarSide, CarFront, GrabHeight)

            Case ePosition.Back
               .GrabMethod = Euphoria.GrabMethod.Line
               .Offset1 = New Vector3(-CarSide, CarBack, GrabHeight)
               .Offset2 = New Vector3(CarSide, CarBack, GrabHeight)

            Case ePosition.Right
               .GrabMethod = Euphoria.GrabMethod.Line
               .Offset1 = New Vector3(CarSide, CarFront, GrabHeight)
               .Offset2 = New Vector3(CarSide, CarBack, GrabHeight)

            Case ePosition.Left
               .GrabMethod = Euphoria.GrabMethod.Line
               .Offset1 = New Vector3(-CarSide, CarFront, GrabHeight)
               .Offset2 = New Vector3(-CarSide, CarBack, GrabHeight)

            Case ePosition.Unknown ' Bottom?
               .GrabMethod = Euphoria.GrabMethod.Surface
               .Offset1 = New Vector3(-CarSide, CarFront, CarBottom)
               .Offset2 = New Vector3(-CarSide, CarBack, CarBottom)
               .Offset3 = New Vector3(CarSide, CarBack, CarBottom)
               .Offset4 = New Vector3(CarSide, CarFront, CarBottom)

         End Select
         .UseLeftHand = True
         .UseRightHand = True
         .DontLetGo = True
         .GrabDistance = 5.0F
         .GrabStrength = -999999.0F '-999999.0F '-1.0F '9999.0F
         .MaxDuration = -1
         .Start()
      End With

      Return info
   End Function

   'Public Function GetClosestPlayerVehicle(ByVal Position As Vector3, ByVal MaxDist As Single) As Vehicle
   '   If MaxDist < 0 Then MaxDist = Single.MaxValue
   '   Dim ClosestDist As Single = MaxDist
   '   Dim ClosestCar As Vehicle = Nothing
   '   For Each p As Player In Game.PlayerList
   '      Dim v As Vehicle = p.Character.CurrentVehicle
   '      If v IsNot Nothing Then
   '         Dim dist As Single = (v.Position - Position).Length
   '         If dist < ClosestDist Then
   '            ClosestDist = dist
   '            ClosestCar = v
   '         End If
   '      End If
   '   Next
   '   Return ClosestCar
   'End Function

End Module
