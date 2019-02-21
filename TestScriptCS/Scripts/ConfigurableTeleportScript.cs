using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.IO;
using GTA;

namespace TestScriptCS {


   // ### This is a customizable Teleport script. Define you own teleport locations in scripts\teleportlocs.txt ###
   // ### The script will load the scripts\teleportlocs.txt on startup and register the keys and locations.     ###
   // ### In game hold the END key and press the key associated for your location at the same time .            ###
   // ### Special Thanks to CoMPMStR for the idea and the basic script!                                         ###

   // ### The locations are defined in scripts\teleportlocs.txt like this (without the // symbols in front):    ###
   // K, 2354.0, 385.0, 5.5    # Airport
   // L, -1971.0, -190.5, 2.0  # Industy park

   public class ConfigurableTeleportScript : Script {

      List<TeleportLocation> Locations = new List<TeleportLocation>();

      public ConfigurableTeleportScript() {
         LoadTeleportLocations(Game.InstallFolder + "\\scripts\\teleportlocs.txt");
         if (Locations.Count > 0) Game.DisplayText("Total Teleport Locations: " + Locations.Count, 4000);
         this.KeyDown += new GTA.KeyEventHandler(this.ConfigurableTeleportScript_KeyDown);
      }

      private void ConfigurableTeleportScript_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (!isKeyPressed(Keys.End)) return; // isKeyPressed works also on keys not watched by the script

         Vector3 Target = GetPositionForKey(e.Key);
         if (Target.Length() == 0.0F) return; // vector is empty

         Game.FadeScreenOut(1000, true);
         Player.Character.Position = Target;
         World.LoadEnvironmentNow(Target);
         Game.FadeScreenIn(2000);
      }

      private Vector3 GetPositionForKey(Keys key) {
         for (int i = 0; i < Locations.Count; i++) {
            if (Locations[i].Key == key) return Locations[i].Position;
         }
         return new Vector3();
      }

      #region Data loading

      private struct TeleportLocation {
         public Keys Key;
         public Vector3 Position;
      }

      private void LoadTeleportLocations(String Filename) {
         String data = LoadFileText(Filename);
         String[] lines = data.Split(new Char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
         for (int i = 0; i < lines.Length; i++) {
            ParseTeleportLocation(lines[i]);
         }
      }

      private void ParseTeleportLocation(String DataLine) {
         String[] vals = DataLine.Split(new Char[] { ',', '#' });
         if (vals.Length < 4) return;
         TeleportLocation loc;
         try {
            loc.Key = ParseKey(vals[0]);
            loc.Position = new Vector3(ParseSingle(vals[1]), ParseSingle(vals[2]), ParseSingle(vals[3]));
         } catch {
            return;
         }
         Locations.Add(loc);
      }

      #endregion

      #region Helper Functions

      private Byte[] LoadFileData(String Filename) {
         try {
            FileStream fs = new FileStream(Filename, FileMode.Open, FileAccess.Read, FileShare.Read);
            Byte[] inbytes = new Byte[fs.Length];
            fs.Read(inbytes, 0, inbytes.Length);
            fs.Close();
            fs.Dispose();
            return inbytes;
         } catch {
            return new Byte[0];
         }
      }

      private String LoadFileText(String Filename) {
         return System.Text.Encoding.Default.GetString(LoadFileData(Filename));
      }

      private Keys ParseKey(String Input) {
         return (Keys)Enum.Parse(typeof(Keys), Input.Trim(), true);
      }

      private Single ParseSingle(String Input) {
         return Single.Parse(Input.Trim(), System.Globalization.CultureInfo.InvariantCulture);
      }

      #endregion

   }

}