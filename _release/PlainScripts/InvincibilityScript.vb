Imports System
Imports System.Windows.Forms
Imports GTA

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