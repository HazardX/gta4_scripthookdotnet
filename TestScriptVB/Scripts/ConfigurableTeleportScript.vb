Imports System
Imports System.Windows.Forms
Imports System.Collections.Generic
Imports Microsoft.VisualBasic
Imports GTA

' ### This is a customizable Teleport script. Define you own teleport locations in scripts\teleportlocs.txt ###
' ### The script will load the scripts\teleportlocs.txt on startup and register the keys and locations.     ###
' ### In game hold the END key and press the key associated for your location at the same time .            ###
' ### Special Thanks to CoMPMStR for the idea and the basic script!                                         ###

' ### The locations are defined in scripts\teleportlocs.txt like this (without the ' symbols in front):     ###
' K, 2354.0, 385.0, 5.5    # Airport
' L, -1971.0, -190.5, 2.0  # Industy park

Public Class ConfigurableTeleportScript
   Inherits Script

   Private Locations As New List(Of TeleportLocation)

   Public Sub New()
      LoadTeleportLocations(Game.InstallFolder & "\scripts\teleportlocs.txt")
      If Locations.Count > 0 Then Game.DisplayText("Total Teleport Locations: " & Locations.Count, 4000)
   End Sub

   Private Sub ConfigurableTeleportScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      If Not isKeyPressed(Keys.End) Then Return ' isKeyPressed works also on keys not watched by the script

      Dim Target As Vector3 = GetPositionForKey(e.Key)
      If Target.Length = 0.0F Then Return ' vector is empty

      Game.FadeScreenOut(1000, True)
      Player.Character.Position = Target
      World.LoadEnvironmentNow(Target)
      Game.FadeScreenIn(2000)
   End Sub

   Private Function GetPositionForKey(ByVal key As Keys) As Vector3
      For i As Integer = 0 To Locations.Count - 1
         If Locations(i).Key = key Then Return Locations(i).Position
      Next
      Return New Vector3
   End Function

#Region " Data loading "

   Private Structure TeleportLocation
      Public Key As Keys
      Public Position As Vector3
   End Structure

   Private Sub LoadTeleportLocations(ByVal Filename As String)
      Dim data As String = LoadFileText(Filename)
      Dim lines() As String = data.Split(New Char() {vbCr, vbLf}, StringSplitOptions.RemoveEmptyEntries)
      For i As Integer = 0 To lines.Length - 1
         ParseTeleportLocation(lines(i))
      Next
   End Sub

   Private Sub ParseTeleportLocation(ByVal DataLine As String)
      Dim vals() As String = DataLine.Split(New Char() {",", "#"})
      If vals.Length < 4 Then Return
      Dim loc As TeleportLocation
      Try
         loc.Key = ParseKey(vals(0))
         loc.Position = New Vector3(ParseSingle(vals(1)), ParseSingle(vals(2)), ParseSingle(vals(3)))
      Catch ex As Exception
         Return
      End Try
      Locations.Add(loc)
   End Sub

#End Region

#Region " Helper Functions "

   Private Function LoadFileData(ByVal Filename As String) As Byte()
      Try
         Dim fs As New IO.FileStream(Filename, IO.FileMode.Open, IO.FileAccess.Read, IO.FileShare.Read)
         Dim inbytes(fs.Length - 1) As Byte
         fs.Read(inbytes, 0, inbytes.Length)
         fs.Close()
         fs.Dispose()
         Return inbytes
      Catch ex As Exception
         Return New Byte() {}
      End Try
   End Function

   Private Function LoadFileText(ByVal Filename As String) As String
      Return System.Text.Encoding.Default.GetString(LoadFileData(Filename))
   End Function

   Private Function ParseKey(ByVal Input As String) As Keys
      Return [Enum].Parse(GetType(Keys), Input.Trim, True)
   End Function

   Private Function ParseSingle(ByVal Input As String) As Single
      Return Single.Parse(Input.Trim, Globalization.CultureInfo.InvariantCulture)
   End Function

#End Region

End Class