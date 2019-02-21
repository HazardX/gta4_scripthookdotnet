Imports System
Imports System.Drawing
Imports System.Windows.Forms
Imports System.Collections.Generic
Imports Microsoft.VisualBasic
Imports GTA

' ### This example will show you how to load and draw textures ###
Public Class TextureDrawingExample
   Inherits Script

   ' To use textures in your script, add them to your Visual Studio Project (in the "Solution Explorer").
   ' Afterwards, select the added image and change the option "Build Action" to "Embedded Resource".
   ' This will embed the image into your script and allows you to load it via Resources.GetTexture .

   Private Gauge As Texture = Resources.GetTexture("rpm_gauge.png")
   Private Needle As Texture = Resources.GetTexture("rpm_needle.png")

   Private Sub TextureDrawingExample_PerFrameDrawing(ByVal sender As Object, ByVal e As GTA.GraphicsEventArgs) Handles Me.PerFrameDrawing
      Dim v As Vehicle = Player.Character.CurrentVehicle
      If v Is Nothing Then Return

      Dim rpm As Single = v.CurrentRPM * Math.PI * -0.5F ' here we calulate the radians required for the rotation of the needle
      Dim radar As RectangleF = e.Graphics.GetRadarRectangle(FontScaling.Pixel) ' this retrieves the rectangle of the radar on screen
      Dim size As Single = radar.Width * 0.75F ' scale the size of the gauge according to the size of the radar

      ' calculate the center of the radar
      Dim radarCenterX As Single = radar.X + radar.Width * 0.5F
      Dim radarCenterY As Single = radar.Y + radar.Height * 0.5F

      e.Graphics.Scaling = FontScaling.Pixel ' Pixel is the default setting, but you could also use any other scaling instead


      ' The gauge itself is easy to draw, since no rotation is required. The upper left corner of the image is at the center of the radar.
      ' The source images only use white color. This allows us to draw the image in any color we want using the last parameter.
      e.Graphics.DrawSprite(Gauge, New RectangleF(radarCenterX, radarCenterY, size, size), Color.Black)


      ' The needle is more complicated due to the rotation.
      ' We build a matrix here to position the needle exactly as required.
      e.Graphics.DrawSprite(Needle, _
            Matrix.Translation(-0.5F, 0.0F, 0.0F) * _
            Matrix.Scaling(size, size, 1.0F) * _
            Matrix.RotationZ(rpm) * _
            Matrix.Translation(radarCenterX, radarCenterY, 0.0F), _
            Color.Red)

      'Explanation of matrices used:
      ' Matrix.Translation(-0.5F, 0.0F, 0.0F)                  ' first we shift the texture half of it's size to the left, because the needle is in the horizontal center of the texture
      ' Matrix.Scaling(size, size, 1.0F)                       ' now we scale the image to the desired size
      ' Matrix.RotationZ(rpm)                                  ' here we apply the rotation based on our RPM value (given in radians)
      ' Matrix.Translation(radarCenterX, radarCenterY, 0.0F)   ' and finally we move the image to the desired location on the screen (the center of the radar in this case)

   End Sub

End Class
