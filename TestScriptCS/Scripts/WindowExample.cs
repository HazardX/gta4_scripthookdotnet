using System;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
using GTA;

namespace TestScriptCS {

   public class WindowExapleForm : GTA.Forms.Form {

      private GTA.Forms.Label Label1;
      private GTA.Forms.Button Button1;
      private GTA.Forms.Button Button2;
      private GTA.Forms.Button Button3;
      private GTA.Forms.Button Button4;
      private GTA.Forms.Checkbox chkLock;
      private GTA.Forms.Label Label2;
      private GTA.Forms.Checkbox Checkbox1;
      private GTA.Forms.Checkbox Checkbox2;
      private GTA.Forms.Checkbox Checkbox3;
      private GTA.Forms.Checkbox Checkbox4;
      private GTA.Forms.Checkbox Checkbox5;
      private GTA.Forms.Checkbox Checkbox6;
      private GTA.Forms.ColorDialog dlg;

      public WindowExapleForm() {
         int Y = 8;

         Label1 = new GTA.Forms.Label();
         Label1.Location = new Point(8, Y);
         Label1.Size = new Size(96, 16);
         Label1.Text = "Car Colors:";
         this.Controls.Add(Label1);
         Y += 16;

         Button1 = new GTA.Forms.Button();
         Button1.Location = new Point(8, Y);
         Button1.Size = new Size(48, 32);
         Button1.Text = "base";
         Button1.Click += new GTA.MouseEventHandler(Button1_Click);
         this.Controls.Add(Button1);
         
         Button2 = new GTA.Forms.Button();
         Button2.Location = new Point(56, Y);
         Button2.Size = new Size(48, 32);
         Button2.Text = "spec.";
         Button2.Click += new GTA.MouseEventHandler(Button2_Click);
         this.Controls.Add(Button2);
         Y += 32;

         Button3 = new GTA.Forms.Button();
         Button3.Location = new Point(8, Y);
         Button3.Size = new Size(48, 32);
         Button3.Text = "feat 1";
         Button3.Click += new GTA.MouseEventHandler(Button3_Click);
         this.Controls.Add(Button3);
         
         Button4 = new GTA.Forms.Button();
         Button4.Location = new Point(56, Y);
         Button4.Size = new Size(48, 32);
         Button4.Text = "feat 2";
         Button4.Click += new GTA.MouseEventHandler(Button4_Click);
         this.Controls.Add(Button4);
         Y += 32;

         Y += 16;

         chkLock = new GTA.Forms.Checkbox();
         chkLock.Location = new Point(8, Y);
         chkLock.Size = new Size(96, 24);
         chkLock.Text = "Lock Doors";
         chkLock.CheckedChanged += new EventHandler(chkLock_CheckedChanged);
         this.Controls.Add(chkLock);
         Y += 24;

         Y += 16;

         Label2 = new GTA.Forms.Label();
         Label2.Location = new Point(8, Y);
         Label2.Size = new Size(96, 16);
         Label2.Text = "Doors open:";
         this.Controls.Add(Label2);
         Y += 16;

         Checkbox1 = new GTA.Forms.Checkbox();
         Checkbox1.Location = new Point(8, Y);
         Checkbox1.Size = new Size(96, 24);
         Checkbox1.Text = "Front left";
         Checkbox1.CheckedChanged += new EventHandler(Checkbox1_CheckedChanged);
         this.Controls.Add(Checkbox1);
         Y += 24;

         Checkbox2 = new GTA.Forms.Checkbox();
         Checkbox2.Location = new Point(8, Y);
         Checkbox2.Size = new Size(96, 24);
         Checkbox2.Text = "Front right";
         Checkbox2.CheckedChanged += new EventHandler(Checkbox2_CheckedChanged);
         this.Controls.Add(Checkbox2);
         Y += 24;

         Checkbox3 = new GTA.Forms.Checkbox();
         Checkbox3.Location = new Point(8, Y);
         Checkbox3.Size = new Size(96, 24);
         Checkbox3.Text = "Rear left";
         Checkbox3.CheckedChanged += new EventHandler(Checkbox3_CheckedChanged);
         this.Controls.Add(Checkbox3);
         Y += 24;

         Checkbox4 = new GTA.Forms.Checkbox();
         Checkbox4.Location = new Point(8, Y);
         Checkbox4.Size = new Size(96, 24);
         Checkbox4.Text = "Rear right";
         Checkbox4.CheckedChanged += new EventHandler(Checkbox4_CheckedChanged);
         this.Controls.Add(Checkbox4);
         Y += 24;

         Checkbox5 = new GTA.Forms.Checkbox();
         Checkbox5.Location = new Point(8, Y);
         Checkbox5.Size = new Size(96, 24);
         Checkbox5.Text = "Hood";
         Checkbox5.CheckedChanged += new EventHandler(Checkbox5_CheckedChanged);
         this.Controls.Add(Checkbox5);
         Y += 24;

         Checkbox6 = new GTA.Forms.Checkbox();
         Checkbox6.Location = new Point(8, Y);
         Checkbox6.Size = new Size(96, 24);
         Checkbox6.Text = "Trunk";
         Checkbox6.CheckedChanged += new EventHandler(Checkbox6_CheckedChanged);
         this.Controls.Add(Checkbox6);
         Y += 24;

         dlg = new GTA.Forms.ColorDialog();
         dlg.AllowScrollbars = false;

         this.Text = "Edit Car";
         this.StartPosition = GTA.FormStartPosition.Fixed;
         this.Size = new Size(96 + 16, Y + 8 + this.TitleSize);
         this.Opened += new EventHandler(WindowExapleForm_Opened);
      }

      private void Button1_Click(System.Object sender , GTA.MouseEventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         dlg.SelectedColorGTA = v.Color;
         if (dlg.ShowDialog() == DialogResult.OK) {
            v.Color = dlg.SelectedColorGTA;
            Button1.BackColor = v.Color.ToColor();
         }
      }

      private void Button2_Click(System.Object sender, GTA.MouseEventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         dlg.SelectedColorGTA = v.SpecularColor;
         if (dlg.ShowDialog() == DialogResult.OK) {
            v.SpecularColor = dlg.SelectedColorGTA;
            Button2.BackColor = v.SpecularColor.ToColor();
         }
      }

      private void Button3_Click(System.Object sender, GTA.MouseEventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         dlg.SelectedColorGTA = v.FeatureColor1;
         if (dlg.ShowDialog() == DialogResult.OK) {
            v.FeatureColor1 = dlg.SelectedColorGTA;
            Button3.BackColor = v.FeatureColor1.ToColor();
         }
      }

      private void Button4_Click(System.Object sender, GTA.MouseEventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         dlg.SelectedColorGTA = v.FeatureColor2;
         if (dlg.ShowDialog() == DialogResult.OK) {
            v.FeatureColor2 = dlg.SelectedColorGTA;
            Button4.BackColor = v.FeatureColor2.ToColor();
         }
      }

      private void chkLock_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         if (chkLock.Checked)
            v.DoorLock = DoorLock.ImpossibleToOpen;
         else
            v.DoorLock = DoorLock.None;
      }

      private void Checkbox1_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.LeftFront).isOpen = Checkbox1.Checked;
      }

      private void Checkbox2_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.RightFront).isOpen = Checkbox2.Checked;
      }

      private void Checkbox3_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.LeftRear).isOpen = Checkbox3.Checked;
      }

      private void Checkbox4_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.RightRear).isOpen = Checkbox4.Checked;
      }

      private void Checkbox5_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.Hood).isOpen = Checkbox5.Checked;
      }

      private void Checkbox6_CheckedChanged(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v == null) return;
         v.Door(VehicleDoor.Trunk).isOpen = Checkbox6.Checked;
      }

      private void WindowExapleForm_Opened(System.Object sender, System.EventArgs e) {
         Vehicle v = Game.LocalPlayer.Character.CurrentVehicle;
         if (v != null) {
            Button1.BackColor = v.Color.ToColor();
            Button2.BackColor = v.SpecularColor.ToColor();
            Button3.BackColor = v.FeatureColor1.ToColor();
            Button4.BackColor = v.FeatureColor2.ToColor();
            chkLock.Checked = (v.DoorLock == DoorLock.ImpossibleToOpen);
            Checkbox1.Checked = v.Door(VehicleDoor.LeftFront).isOpen;
            Checkbox2.Checked = v.Door(VehicleDoor.RightFront).isOpen;
            Checkbox3.Checked = v.Door(VehicleDoor.LeftRear).isOpen;
            Checkbox4.Checked = v.Door(VehicleDoor.RightRear).isOpen;
            Checkbox5.Checked = v.Door(VehicleDoor.Hood).isOpen;
            Checkbox6.Checked = v.Door(VehicleDoor.Trunk).isOpen;
         }
      }

   }

   public class WindowExapleScript : Script {

      WindowExapleForm Window;

      public WindowExapleScript() {
         Window = new WindowExapleForm();
         this.BindConsoleCommand("EditCar", new ConsoleCommandDelegate(ShowWindow), "- Displays a window with several car options");
      }

      private void ShowWindow(ParameterCollection Parameter) {
         if (!Player.Character.isSittingInVehicle()) {
            Game.Console.Print("You must be sitting in a vehicle!");
            return;
         }
         Game.Console.Close();
         Window.Location = new Point(0, 0);
         Window.Show();
      }

   }

}