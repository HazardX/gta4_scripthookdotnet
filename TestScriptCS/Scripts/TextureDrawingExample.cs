using System;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
using GTA;

namespace TestScriptCS {

   // ### This example will show you how to load and draw textures ###
   public class TextureDrawingExample : Script {

      // To use textures in your script, add them to your Visual Studio Project (in the "Solution Explorer").
      // Afterwards, select the added image and change the option "Build Action" to "Embedded Resource".
      // This will embed the image into your script and allows you to load it via Resources.GetTexture .

      private Texture Gauge;
      private Texture Needle;

      public TextureDrawingExample() {
         Gauge = Resources.GetTexture("rpm_gauge.png");
         Needle = Resources.GetTexture("rpm_needle.png");
         PerFrameDrawing += new GTA.GraphicsEventHandler(TextureDrawingExample_PerFrameDrawing);
      }

      private void TextureDrawingExample_PerFrameDrawing(System.Object sender, GTA.GraphicsEventArgs e) {
         Vehicle v = Player.Character.CurrentVehicle;
         if (v == null) return;

         float rpm = v.CurrentRPM * (float)Math.PI * -0.5f;  // here we calulate the radians required for the rotation of the needle
         RectangleF radar = e.Graphics.GetRadarRectangle(FontScaling.Pixel);  // this retrieves the rectangle of the radar on screen
         float size = radar.Width * 0.75f;  // scale the size of the gauge according to the size of the radar

         // calculate the center of the radar
         float radarCenterX = radar.X + radar.Width * 0.5f;
         float radarCenterY = radar.Y + radar.Height * 0.5f;

         e.Graphics.Scaling = FontScaling.Pixel;  // Pixel is the default setting, but you could also use any other scaling instead


         // The gauge itself is easy to draw, since no rotation is required. The upper left corner of the image is at the center of the radar.
         // The source images only use white color. This allows us to draw the image in any color we want using the last parameter.
         e.Graphics.DrawSprite(Gauge, new RectangleF(radarCenterX, radarCenterY, size, size), System.Drawing.Color.Black);


         // The needle is more complicated due to the rotation.
         // We build a matrix here to position the needle exactly as required.
         e.Graphics.DrawSprite(Needle,
            Matrix.Translation(-0.5f, 0.0f, 0.0f) *               // first we shift the texture half of it's size to the left, because the needle is in the horizontal center of the texture
            Matrix.Scaling(size, size, 1.0f) *                    // now we scale the image to the desired size
            Matrix.RotationZ(rpm) *                               // here we apply the rotation based on our RPM value (given in radians)
            Matrix.Translation(radarCenterX, radarCenterY, 0.0f), // and finally we move the image to the desired location on the screen (the center of the radar in this case)
            Color.Red);
      }

   }

}