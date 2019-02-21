Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports System.Collections.Generic
Imports Microsoft.VisualBasic
Imports GTA

Public Class WindowExapleForm
   Inherits GTA.Forms.Form

   Private WithEvents Label1 As GTA.Forms.Label
   Private WithEvents Button1 As GTA.Forms.Button
   Private WithEvents Button2 As GTA.Forms.Button
   Private WithEvents Button3 As GTA.Forms.Button
   Private WithEvents Button4 As GTA.Forms.Button
   Private WithEvents chkLock As GTA.Forms.Checkbox
   Private WithEvents Label2 As GTA.Forms.Label
   Private WithEvents Checkbox1 As GTA.Forms.Checkbox
   Private WithEvents Checkbox2 As GTA.Forms.Checkbox
   Private WithEvents Checkbox3 As GTA.Forms.Checkbox
   Private WithEvents Checkbox4 As GTA.Forms.Checkbox
   Private WithEvents Checkbox5 As GTA.Forms.Checkbox
   Private WithEvents Checkbox6 As GTA.Forms.Checkbox
   Private dlg As New GTA.Forms.ColorDialog

   Public Sub New()
      Dim Y As Integer = 8

      Label1 = New GTA.Forms.Label
      Label1.Location = New Drawing.Point(8, Y)
      Label1.Size = New Drawing.Size(96, 16)
      Label1.Text = "Colors:"
      Me.Controls.Add(Label1)
      Y += 16

      Button1 = New GTA.Forms.Button
      Button1.Location = New Drawing.Point(8, Y)
      Button1.Size = New Drawing.Size(48, 32)
      Button1.Text = "base"
      Me.Controls.Add(Button1)

      Button2 = New GTA.Forms.Button
      Button2.Location = New Drawing.Point(56, Y)
      Button2.Size = New Drawing.Size(48, 32)
      Button2.Text = "spec."
      Me.Controls.Add(Button2)
      Y += 32

      Button3 = New GTA.Forms.Button
      Button3.Location = New Drawing.Point(8, Y)
      Button3.Size = New Drawing.Size(48, 32)
      Button3.Text = "feat 1"
      Me.Controls.Add(Button3)

      Button4 = New GTA.Forms.Button
      Button4.Location = New Drawing.Point(56, Y)
      Button4.Size = New Drawing.Size(48, 32)
      Button4.Text = "feat 2"
      Me.Controls.Add(Button4)
      Y += 32

      Y += 16

      chkLock = New GTA.Forms.Checkbox
      chkLock.Location = New Drawing.Point(8, Y)
      chkLock.Size = New Drawing.Size(96, 24)
      chkLock.Text = "Lock Doors"
      Me.Controls.Add(chkLock)
      Y += 24

      Y += 16

      Label2 = New GTA.Forms.Label
      Label2.Location = New Drawing.Point(8, Y)
      Label2.Size = New Drawing.Size(96, 16)
      Label2.Text = "Doors open:"
      Me.Controls.Add(Label2)
      Y += 16

      Checkbox1 = New GTA.Forms.Checkbox
      Checkbox1.Location = New Drawing.Point(8, Y)
      Checkbox1.Size = New Drawing.Size(96, 24)
      Checkbox1.Text = "Front left"
      Me.Controls.Add(Checkbox1)
      Y += 24

      Checkbox2 = New GTA.Forms.Checkbox
      Checkbox2.Location = New Drawing.Point(8, Y)
      Checkbox2.Size = New Drawing.Size(96, 24)
      Checkbox2.Text = "Front right"
      Me.Controls.Add(Checkbox2)
      Y += 24

      Checkbox3 = New GTA.Forms.Checkbox
      Checkbox3.Location = New Drawing.Point(8, Y)
      Checkbox3.Size = New Drawing.Size(96, 24)
      Checkbox3.Text = "Rear left"
      Me.Controls.Add(Checkbox3)
      Y += 24

      Checkbox4 = New GTA.Forms.Checkbox
      Checkbox4.Location = New Drawing.Point(8, Y)
      Checkbox4.Size = New Drawing.Size(96, 24)
      Checkbox4.Text = "Rear right"
      Me.Controls.Add(Checkbox4)
      Y += 24

      Checkbox5 = New GTA.Forms.Checkbox
      Checkbox5.Location = New Drawing.Point(8, Y)
      Checkbox5.Size = New Drawing.Size(96, 24)
      Checkbox5.Text = "Hood"
      Me.Controls.Add(Checkbox5)
      Y += 24

      Checkbox6 = New GTA.Forms.Checkbox
      Checkbox6.Location = New Drawing.Point(8, Y)
      Checkbox6.Size = New Drawing.Size(96, 24)
      Checkbox6.Text = "Trunk"
      Me.Controls.Add(Checkbox6)
      Y += 24

      dlg.AllowScrollbars = False
      Me.Text = "Edit Car"
      Me.StartPosition = GTA.FormStartPosition.Fixed
      Me.Size = New Size(96 + 16, Y + 8 + Me.TitleSize)
   End Sub

   Private Sub Button1_Click(ByVal sender As Object, ByVal e As GTA.MouseEventArgs) Handles Button1.Click
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      dlg.SelectedColorGTA = v.Color
      If (dlg.ShowDialog = Windows.Forms.DialogResult.OK) Then
         v.Color = dlg.SelectedColorGTA
         Button1.BackColor = v.Color.ToColor
      End If
   End Sub

   Private Sub Button2_Click(ByVal sender As Object, ByVal e As GTA.MouseEventArgs) Handles Button2.Click
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      dlg.SelectedColorGTA = v.SpecularColor
      If (dlg.ShowDialog = Windows.Forms.DialogResult.OK) Then
         v.SpecularColor = dlg.SelectedColorGTA
         Button2.BackColor = v.SpecularColor.ToColor
      End If
   End Sub

   Private Sub Button3_Click(ByVal sender As Object, ByVal e As GTA.MouseEventArgs) Handles Button3.Click
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      dlg.SelectedColorGTA = v.FeatureColor1
      If (dlg.ShowDialog = Windows.Forms.DialogResult.OK) Then
         v.FeatureColor1 = dlg.SelectedColorGTA
         Button3.BackColor = v.FeatureColor1.ToColor
      End If
   End Sub

   Private Sub Button4_Click(ByVal sender As Object, ByVal e As GTA.MouseEventArgs) Handles Button4.Click
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      dlg.SelectedColorGTA = v.FeatureColor2
      If (dlg.ShowDialog = Windows.Forms.DialogResult.OK) Then
         v.FeatureColor2 = dlg.SelectedColorGTA
         Button4.BackColor = v.FeatureColor2.ToColor
      End If
   End Sub

   Private Sub chkLock_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles chkLock.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      If chkLock.Checked Then
         v.DoorLock = DoorLock.ImpossibleToOpen
      Else
         v.DoorLock = DoorLock.None
      End If
   End Sub

   Private Sub Checkbox1_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox1.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.LeftFront).isOpen = Checkbox1.Checked
   End Sub

   Private Sub Checkbox2_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox2.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.RightFront).isOpen = Checkbox2.Checked
   End Sub

   Private Sub Checkbox3_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox3.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.LeftRear).isOpen = Checkbox3.Checked
   End Sub

   Private Sub Checkbox4_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox4.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.RightRear).isOpen = Checkbox4.Checked
   End Sub

   Private Sub Checkbox5_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox5.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.Hood).isOpen = Checkbox5.Checked
   End Sub

   Private Sub Checkbox6_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Checkbox6.CheckedChanged
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v Is Nothing Then Return
      v.Door(VehicleDoor.Trunk).isOpen = Checkbox6.Checked
   End Sub

   Private Sub WindowExapleForm_Opened(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Opened
      Dim v As Vehicle = Game.LocalPlayer.Character.CurrentVehicle
      If v IsNot Nothing Then
         Button1.BackColor = v.Color.ToColor
         Button2.BackColor = v.SpecularColor.ToColor
         Button3.BackColor = v.FeatureColor1.ToColor
         Button4.BackColor = v.FeatureColor2.ToColor
         chkLock.Checked = (v.DoorLock = DoorLock.ImpossibleToOpen)
         Checkbox1.Checked = v.Door(VehicleDoor.LeftFront).isOpen
         Checkbox2.Checked = v.Door(VehicleDoor.RightFront).isOpen
         Checkbox3.Checked = v.Door(VehicleDoor.LeftRear).isOpen
         Checkbox4.Checked = v.Door(VehicleDoor.RightRear).isOpen
         Checkbox5.Checked = v.Door(VehicleDoor.Hood).isOpen
         Checkbox6.Checked = v.Door(VehicleDoor.Trunk).isOpen
      End If
   End Sub

End Class

Public Class WindowExapleScript
   Inherits Script

   Private Window As New WindowExapleForm

   Public Sub New()
      Me.BindConsoleCommand("EditCar", AddressOf ShowWindow, "- Displays a window with several car options")
   End Sub

   Private Sub ShowWindow()
      If Not Player.Character.isSittingInVehicle Then
         Game.Console.Print("You must be sitting in a vehicle!")
         Return
      End If
      Game.Console.Close()
      Window.Location = New Point(0, 0)
      Window.Show()
   End Sub

End Class