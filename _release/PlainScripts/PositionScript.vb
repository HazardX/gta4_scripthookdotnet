Imports System
Imports System.Windows.Forms
Imports GTA

Public Class PositionScript
   Inherits Script

   Private Sub PositionScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If e.Key = Keys.Home Then Game.DisplayText(Player.Character.Position.ToString)
   End Sub

End Class