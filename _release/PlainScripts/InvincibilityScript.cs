using System;
using System.Windows.Forms;
using GTA;

   // ### Press the I key to become invincible against everything (besides falling damage) ###
   // ### Niko will still be affected by fire, explosions, etc. but won't die.             ###

   public class InvincibilityScript : Script {

      bool bInvincible = false;
      const int HEALTH_VALUE = 500000;

      public InvincibilityScript() {
         Interval = 250;
         BindKey(Keys.I, new KeyPressDelegate(ToggleInvincibility));
         this.Tick += new EventHandler(this.InvincibilityScript_Tick);
      }

      private void InvincibilityScript_Tick(object sender, EventArgs e) {
         if (bInvincible) {
            Player.Character.Health = HEALTH_VALUE;
            Player.Character.Armor = HEALTH_VALUE;
         }
      }

      private void ToggleInvincibility() {
         bInvincible = !bInvincible;
         Player.Character.ForceHelmet(bInvincible); // Show a helmet to visualize the invincibility
         if (bInvincible) {
            Player.MaxHealth = HEALTH_VALUE;
            Player.MaxArmor = HEALTH_VALUE;
            Player.Character.Health = HEALTH_VALUE;
            Player.Character.Armor = HEALTH_VALUE;
            Game.DisplayText("Invincible!");
         } else {
            Player.MaxHealth = 100;
            Player.MaxArmor = 100;
            Player.Character.Health = 100;
            Player.Character.Armor = 100;
            Game.DisplayText("NOT invincible!");
         }
      }

   }