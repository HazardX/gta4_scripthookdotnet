using System;
using System.Windows.Forms;
using GTA;

public class PositionScript : Script {

   public PositionScript() {
      this.KeyDown += new GTA.KeyEventHandler(this.PositionScript_KeyDown);
   }

   private void PositionScript_KeyDown(object sender, GTA.KeyEventArgs e) {
      if (e.Key == Keys.Home) Game.DisplayText(Player.Character.Position.ToString());
   }

}