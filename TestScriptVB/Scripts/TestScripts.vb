Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports GTA


' ### get 10000 bucks each time you press M ###
Public Class BasicKeyExample
   Inherits Script

   ' KeyDown processes all pressed keys.
   Private Sub BasicKeyExample_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key = Keys.M Then Player.Money += 10000
   End Sub

End Class


' ### This script will give you all advanced weapons and lots of ammo every 5 seconds ###
Public Class BasicTickExample
   Inherits Script

   Public Sub New()
      Me.Interval = 5000 ' Interval is the time between two Ticks (in milliseconds)
   End Sub

   Private Sub BasicTickExample_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      Game.DisableMaxAmmoLimit = True
      With Player.Character
         .Weapons.BaseballBat.Ammo = 1
         .Weapons.Grenades.Ammo = 30000
         .Weapons.DesertEagle.Ammo = 30000
         .Weapons.BarettaShotgun.Ammo = 30000
         .Weapons.MP5.Ammo = 30000
         .Weapons.AssaultRifle_M4.Ammo = 30000
         .Weapons.SniperRifle_M40A1.Ammo = 30000
         .Weapons.RocketLauncher.Ammo = 30000
      End With
   End Sub

End Class


' ### Press the I key to become invincible against everything (besides falling damage) ###
' ### Niko will still be affected by fire, explosions, etc. but won't die.             ###
Public Class InvincibilityScript
   Inherits Script

   Private bInvincible As Boolean = False
   Private Const HEALTH_VALUE As Integer = 500000

   Public Sub New()
      Me.Interval = 250
      BindKey(Keys.I, AddressOf ToggleInvincibility)
   End Sub

   Private Sub InvincibilityScript_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If bInvincible Then
         Player.Character.Health = HEALTH_VALUE
         Player.Character.Armor = HEALTH_VALUE
      End If
   End Sub

   Private Sub ToggleInvincibility()
      bInvincible = Not bInvincible
      Player.Character.ForceHelmet(bInvincible) ' Show a helmet to visualize the invincibility
      If bInvincible Then
         Player.MaxHealth = HEALTH_VALUE
         Player.MaxArmor = HEALTH_VALUE
         Player.Character.Health = HEALTH_VALUE
         Player.Character.Armor = HEALTH_VALUE
         Game.DisplayText("Invincible!")
      Else
         Player.MaxHealth = 100
         Player.MaxArmor = 100
         Player.Character.Health = 100
         Player.Character.Armor = 100
         Game.DisplayText("NOT invincible!")
      End If
   End Sub

End Class


' ### Press O to keep the wanted level at zero ###
Public Class PoliceScript
   Inherits Script

   Private bNoPolice As Boolean = False

   Public Sub New()
      Interval = 250
   End Sub

   Private Sub PoliceScript_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If bNoPolice AndAlso Player.WantedLevel > 0 Then
         Player.WantedLevel = 0
      End If
   End Sub

   Private Sub PoliceScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key <> Keys.O Then Return

      bNoPolice = Not bNoPolice
      If bNoPolice Then
         Player.WantedLevel = 0
         Game.WantedMultiplier = 0.0F
         Game.DisplayText("Police will ignore you!")
      Else
         Game.WantedMultiplier = 1.0F
         Game.DisplayText("Police will NOT ignore you!")
      End If
   End Sub

End Class


' ### Press F7 to spawn a BANSHEE or F8 to change the player skin to the selected multiplayer skin ###
' ### Steal peoples skin by aiming at them and pressing F8                                         ###
Public Class BindKeyExample
   Inherits Script

   Private SavedSkin As SkinTemplate = Player.Skin

   Public Sub New()
      BindKey(Keys.F7, AddressOf SpawnCar)
      BindKey(Keys.F8, AddressOf ChangeSkin)
   End Sub

   Public Sub SpawnCar()
      Dim v As Vehicle = World.CreateVehicle("BANSHEE", Player.Character.Position.Around(5.0F))
      v.NoLongerNeeded() ' Call this to make sure that the game will NOT keep the vehicle forever
   End Sub

   Public Sub ChangeSkin()
      Dim target As Ped = Player.GetTargetedPed() ' Get the ped the player is targetting currently to "steal" his skin
      If target Is Nothing Then
         If Player.Model <> "PLAYER" Then ' check if the player model has changed
            Player.Skin.Template = SavedSkin ' revert back to your original model and outfit
         Else
            Player.ActivateMultiplayerSkin()  ' Activate the player skin selected for multiplayer mode if no ped is targeted and skin is default
            'Player.Model = "M_Y_SWAT" ' use this instead of the line above to change the player model to the SWAT skin
         End If
      Else
         Player.Skin.Template = target.Skin
      End If
   End Sub

End Class


' ### Type "Explode" into the console and you will explode...                   ###
' ### Type "SpawnCar ?" (where ? is a number from 1 to 6) to get a new vehicle. ###
' ### Call 123 on the phone to get an Annihilator helicopter.                   ###
Public Class InfoAndBindExample
   Inherits Script

   Public Sub New()
      GeneralInfo = "Use console commands to make you explode, or spawn some vehicles. Call 123 on the phone to get an Annihilator helicopter."
      BindConsoleCommand("Explode", AddressOf ExplodeCommand, "- BOOOOOM!")
      BindConsoleCommand("SpawnCar", AddressOf CarCommand, "[number] - Spawn an Infernus, Comet, SultanRS, Partiot, NRG 900 or Airtug")
      BindPhoneNumber("GET 555 heli", AddressOf SpawnAnnihilator)
   End Sub

   Private Sub ExplodeCommand()
      World.AddExplosion(Player.Character.Position)
   End Sub

   Private Sub SpawnAnnihilator()
      Dim v As Vehicle = World.CreateVehicle("ANNIHILATOR", Player.Character.Position.Around(5.0F))
      v.NoLongerNeeded() ' Call this to make sure that the game will NOT keep the vehicle forever
   End Sub

   Private Sub CarCommand(ByVal Parameter As ParameterCollection)
      Dim CarType As String
      Select Case Parameter.ToInteger(0) ' convert the first parameter (0) into an integer value
         Case 1 : CarType = "INFERNUS"
         Case 2 : CarType = "COMET"
         Case 3 : CarType = "SULTANRS"
         Case 4 : CarType = "PATRIOT"
         Case 5 : CarType = "NRG900"
         Case Else : CarType = "AIRTUG"
      End Select
      Dim v As Vehicle = World.CreateVehicle(CarType, Player.Character.Position.Around(5.0F))
      v.NoLongerNeeded() ' Call this to make sure that the game will NOT keep the vehicle forever
   End Sub

End Class


' ### Shows how to use PerFrameDrawing to draw graphical elements to the screen.         ###
' ### Hold down the NumPad0 key in game and two boxes with red numbers will appear.      ###
Public Class DrawingScript
   Inherits Script

   Private screenFont As New GTA.Font(0.15F, FontScaling.ScreenUnits)
   Private pixelFont As New GTA.Font(48, FontScaling.Pixel)

   Private screenBoxColor As Color = Color.FromArgb(127, 0, 0, 255)
   Private pixelBoxColor As Color = Color.FromArgb(127, 0, 255, 0)

   Public Sub New()
      screenFont.Color = Color.Red
      pixelFont.Color = Color.Red
   End Sub

   Protected Sub DrawingScript_PerFrameDrawing(ByVal sender As Object, ByVal e As GraphicsEventArgs) Handles MyBase.PerFrameDrawing
      If isKeyPressed(Keys.NumPad0) Then
         e.Graphics.Scaling = FontScaling.Pixel ' fixed amount of pixels, size on screen will differ for each resolution
         Dim rect As New RectangleF(64, 64, 128, 128)
         e.Graphics.DrawRectangle(rect, pixelBoxColor)
         e.Graphics.DrawText("1", rect, TextAlignment.Center Or TextAlignment.VerticalCenter, pixelFont)

         e.Graphics.Scaling = FontScaling.ScreenUnits ' size on screen will always be the same, regardless of resolution
         rect = New RectangleF(0.65F, 0.65F, 0.2F, 0.2F)
         e.Graphics.DrawRectangle(rect, screenBoxColor)
         e.Graphics.DrawText("2", rect, TextAlignment.Center Or TextAlignment.VerticalCenter, screenFont)
      End If
   End Sub

End Class


' ### Spawns a Ped when pressing K, which attacks you for 5 sec, flees for 5 sec and then dies  ###
Public Class TaskSequenceExample
   Inherits Script

   Private FleeTask As New TaskSequence

   Public Sub New()
      ' Add tasks to the TaskSequence
      FleeTask.AddTask.SwapWeapon(Weapon.Handgun_Glock)
      FleeTask.AddTask.FightAgainst(Player, 5000)
      FleeTask.AddTask.FleeFromChar(Player, False, 5000)
      FleeTask.AddTask.Die()
   End Sub

   Private Sub TaskSequenceExample_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key <> Keys.K Then Return

      Dim p As Ped = World.CreatePed(Player.Character.Position.Around(3.0F))
      p.CurrentRoom = Player.Character.CurrentRoom
      p.Weapons.Glock.Ammo = 1000
      p.Task.PerformSequence(FleeTask)
   End Sub

End Class


' ### Press Z and the ped you are aiming at will start walking towards you like a zombie  ###
Public Class EuphoriaExample
   Inherits Script

   Private Zombie As Ped

   Public Sub New()
      Interval = 250
      GeneralInfo = "Press Z and the ped you are aiming at will start walking towards you like a zombie!"
      BindKey(Keys.Z, AddressOf DoTheZombie)
   End Sub

   Private Sub DoTheZombie()
      If Exists(Zombie) Then
         Zombie.isRagdoll = False
         Zombie = Nothing
         Return
      End If

      Zombie = Player.GetTargetedPed
      If Not Exists(Zombie) Then Return

      Game.DisplayText("ZOMBIES!!!")
      Zombie.Euphoria.BodyBalance.Start(-1)
   End Sub

   Private Sub EuphoriaExample_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If Not Exists(Zombie) Then Return

      If Zombie.isGettingUp Then Return ' wait until the zombie is standing
      If Not Zombie.isRagdoll Then Zombie.Euphoria.BodyBalance.Start(-1)
      If Not Zombie.Euphoria.BodyBalance.isBalanced Then ' get up again when fallen to the ground
         Zombie.isRagdoll = False
         Return
      End If

      With Zombie.Euphoria.LeanToPosition
         .Amount = 1.0F
         .ApplyAsForce = True
         .Position = Player.Character.Position
         .Start()
      End With
   End Sub

End Class


' ### Uses native calls to get the name of the current vehicle when pressing L  ###
Public Class NativeCallExample
   Inherits Script

   Private Sub NativeCallExample_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key <> Keys.L Then Return

      Dim PedPointer As New Native.Pointer(GetType(Ped))
      Native.Function.Call("GET_PLAYER_CHAR", Player, PedPointer)
      Dim PlayerChar As Ped = PedPointer

      If Not Native.Function.Call(Of Boolean)("IS_CHAR_IN_ANY_CAR", PlayerChar) Then
         Game.DisplayText("Not in a car!")
         Return
      End If

      Dim CarPointer As New Native.Pointer(GetType(Vehicle))
      Native.Function.Call("GET_CAR_CHAR_IS_USING", PlayerChar, CarPointer)

      Dim ModelPointer As New Native.Pointer(GetType(Model))
      Native.Function.Call("GET_CAR_MODEL", CarPointer.ToInputParameter, ModelPointer)

      Dim name As String = Native.Function.Call(Of String)("GET_DISPLAY_NAME_FROM_VEHICLE_MODEL", ModelPointer.ToInputParameter)

      Game.DisplayText("Car name: " & name)
   End Sub

End Class


'' ### Syncronizes ingame time with the real time ###
'Public Class TimeSyncExample
'   Inherits Script

'   Private day As Integer

'   Public Sub New()
'      Interval = 10000
'      Dim real As Date = Date.Now
'      day = real.DayOfYear
'      World.LockDayTime(real.Hour, real.Minute)
'   End Sub

'   Private Sub TimeSyncExample_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
'      Dim real As Date = Date.Now
'      If day <> real.DayOfYear Then ' we can be sure that a new day begun in reality when the DayOfYear has changed
'         day = real.DayOfYear
'         World.OneDayForward()
'      End If
'      Dim w As Weather = World.Weather ' store and reset the weather, because LockDayTime changes it instantly
'      World.LockDayTime(real.Hour, real.Minute)
'      World.Weather = w
'   End Sub

'End Class


'### Press J to smoke a spliff... Press J again or switch to a weapon to drop it. ###
Public Class AnimationExample
   Inherits Script

   Private bSmoking As Boolean = False
   Private spliff As GTA.Object
   Private timer As New GTA.Timer

   Private anims As New AnimationSet("amb@smoking_spliff")
   Private animflags As AnimationFlags = AnimationFlags.Unknown12 Or AnimationFlags.Unknown11 Or AnimationFlags.Unknown09

   Public Sub New()
      Interval = 1000
   End Sub

   Private Sub AnimationExample_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key <> Keys.J Then Return
      If bSmoking Then
         StopSmoking()
      Else
         StartSmoking()
      End If
   End Sub

   Private Sub StartSmoking()
      If bSmoking Then Return
      bSmoking = True

      Player.Character.Weapons.Unarmed.Select()
      Player.Character.Animation.Play(anims, "create_spliff", 8.0F, animflags)
      Wait(1600)

      spliff = World.CreateObject(&HD130ADEF, Player.Character.Position)
      spliff.AttachToPed(Player.Character, Bone.RightHand, New Vector3(0.14F, 0.03F, 0.04F), New Vector3(2.21F, -0.12F, 0.0F))

      Player.Character.Animation.WaitUntilFinished(anims, "create_spliff")
      timer.Start()
   End Sub

   Private Sub StopSmoking()
      If Not bSmoking Then Return
      bSmoking = False
      If spliff Is Nothing Then Return

      spliff.Detach()
      spliff.NoLongerNeeded()
   End Sub

   Private Sub AnimationExample_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If bSmoking Then
         If Player.Character.Weapons.CurrentType <> Weapon.Unarmed Then
            StopSmoking()
         ElseIf timer.ElapsedTime > 10000 AndAlso Player.Character.isIdle Then
            If Player.Character.isInVehicle Then
               Player.Character.Task.PlayAnimation(anims, "partial_smoke_car", 8.0F, animflags)
            Else
               Player.Character.Task.PlayAnimation(anims, "partial_smoke", 8.0F, animflags)
            End If
            timer.Start()
         End If
      End If
   End Sub

End Class