using System;
using System.Windows.Forms;
using GTA;

namespace TestScriptCS {


   // ### This example shall show inter-script-communication using ScriptCommands.  ###
   // ### The first script gets a random Ped and sends it to the second script.     ###
   // ### The second script can then process the Ped as usual.                      ###

   public class ScriptCommunicationExample1 : Script {

      // Scripts are identified by GUIDs. Here we store the GUID of our target script into a global variable for later use
      Guid GuidOfScript2 = new Guid("0652B17E-FB29-11DD-97BB-2E9356D89593");

      public ScriptCommunicationExample1() {
         this.Tick += new EventHandler(this.ScriptCommunicationExample1_Tick);
      }

      private void ScriptCommunicationExample1_Tick(object sender, EventArgs e) {
         if (isKeyPressed(Keys.T)) SendAPedToScript2(); // Look for Peds every Frame, while T is pressed
      }

      private void SendAPedToScript2() {
         Ped p = World.GetRandomPed(Player.Character.Position, 10.0F); // get a random Ped
         if (!Exists(p)) return; // make sure that p is valid and not empty
         SendScriptCommand(GuidOfScript2, "DoSomethingWithPed", p); // send a command, with our ped attached, to the second script
      }

   }

   public class ScriptCommunicationExample2 : Script {

      public ScriptCommunicationExample2() {
         // set the script's GUID to enable other scripts to send messages to it.
         // IMPORTANT: DO NOT use the same GUID for multiple scripts! Generate a new one instead!
         // Google "generate guid" to find an online GUID generator!
         GUID = new Guid("0652B17E-FB29-11DD-97BB-2E9356D89593");

         BindScriptCommand("DoSomethingWithPed", new ScriptCommandDelegate(ThrowAPed));
      }

      private void ThrowAPed(GTA.Script sender, GTA.ObjectCollection Parameter) {
         Ped ped = Parameter.Convert<Ped>(0);
         if (!Exists(ped) || ped.isInAir) return;
         ped.ApplyForce(new Vector3(0.0F, 0.0F, 5.0F), new Vector3(0.0F, 5.0F, 0.0F));
      }

   }

}