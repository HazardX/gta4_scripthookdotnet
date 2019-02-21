Imports System
Imports System.Windows.Forms
Imports GTA


' ### This example shall show inter-script-communication using ScriptCommands.  ###
' ### The first script gets a random Ped and sends it to the second script.     ###
' ### The second script can then process the Ped as usual.                      ###

Public Class ScriptCommunicationExample1
   Inherits Script

   ' Scripts are identified by GUIDs. Here we store the GUID of our target script into a global variable for later use
   Private GuidOfScript2 As Guid = New Guid("0652B17E-FB29-11DD-97BB-2E9356D89593")

   Private Sub ScriptCommunicationExample1_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Tick
      If isKeyPressed(Keys.T) Then SendAPedToScript2() ' Look for Peds every Frame, while T is pressed
   End Sub

   Private Sub SendAPedToScript2()
      Dim p As Ped = World.GetRandomPed(Player.Character.Position, 10.0F) ' get a random Ped
      If Not Exists(p) Then Return ' make sure that p is valid and not empty
      SendScriptCommand(GuidOfScript2, "DoSomethingWithPed", p) ' send a command, with our ped attached, to the second script
   End Sub

End Class

Public Class ScriptCommunicationExample2
   Inherits Script

   Public Sub New()
      ' set the script's GUID to enable other scripts to send messages to it.
      ' IMPORTANT: DO NOT use the same GUID for multiple scripts! Generate a new one instead!
      ' Google "generate guid" to find an online GUID generator!
      GUID = New Guid("0652B17E-FB29-11DD-97BB-2E9356D89593")

      BindScriptCommand("DoSomethingWithPed", AddressOf ThrowAPed)
   End Sub

   Private Sub ThrowAPed(ByVal sender As GTA.Script, ByVal Parameter As GTA.ObjectCollection)
      Dim ped As Ped = Parameter.Convert(Of Ped)(0)
      If Not Exists(ped) OrElse ped.isInAir Then Return
      ped.ApplyForce(New Vector3(0.0F, 0.0F, 5.0F), New Vector3(0.0F, 5.0F, 0.0F))
   End Sub

End Class
