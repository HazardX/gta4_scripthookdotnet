using System;
using System.Drawing;
using System.Windows.Forms;
using GTA;

namespace TestScriptCS {


   // ### get 10000 bucks each time you press M ###
   public class BasicKeyExample : Script {

      public BasicKeyExample() {
         // Bind method BasicKeyExample_KeyDown to the KeyDown event
         this.KeyDown += new GTA.KeyEventHandler(this.BasicKeyExample_KeyDown);
      }

      // KeyDown returns the pressed key.
      // but there is no need to check it when your script watches only this one key
      private void BasicKeyExample_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (e.Key == Keys.M) Player.Money += 10000;
      }

   }


   // ### This script will give you all advanced weapons and lots of ammo every 5 seconds ###
   public class BasicTickExample : Script {

      public BasicTickExample() {
         Interval = 5000; // Interval is the time between two Ticks (in milliseconds)
         this.Tick += new EventHandler(this.BasicTickExample_Tick);
      }

      private void BasicTickExample_Tick(object sender, EventArgs e) {
         Game.DisableMaxAmmoLimit = true;
         Ped p = Player.Character;
         p.Weapons.BaseballBat.Ammo = 1;
         p.Weapons.Grenades.Ammo = 30000;
         p.Weapons.DesertEagle.Ammo = 30000;
         p.Weapons.BarettaShotgun.Ammo = 30000;
         p.Weapons.MP5.Ammo = 30000;
         p.Weapons.AssaultRifle_M4.Ammo = 30000;
         p.Weapons.SniperRifle_M40A1.Ammo = 30000;
         p.Weapons.RocketLauncher.Ammo = 30000;
      }

   }


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


   // ### Press O to keep the wanted level at zero ###
   public class PoliceScript : Script {

      bool bNoPolice = false;

      public PoliceScript() {
         Interval = 250;
         this.Tick += new EventHandler(this.PoliceScript_Tick);
         this.KeyDown += new GTA.KeyEventHandler(this.PoliceScript_KeyDown);
      }

      private void PoliceScript_Tick(object sender, EventArgs e) {
         if ((bNoPolice) && (Player.WantedLevel > 0))
            Player.WantedLevel = 0;
      }

      private void PoliceScript_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (e.Key != Keys.O) return;

         bNoPolice = !bNoPolice;
         if (bNoPolice) {
            Player.WantedLevel = 0;
            Game.WantedMultiplier = 0.0F;
            Game.DisplayText("Police will ignore you!");
         } else {
            Game.WantedMultiplier = 1.0F;
            Game.DisplayText("Police will NOT ignore you!");
         }
      }

   }


   // ### Press F7 to spawn a BANSHEE or F8 to change the player skin to the selected multiplayer skin ###
   // ### Steal peoples skin by aiming at them and pressing F8                                         ###
   public class BindKeyExample : Script {

      SkinTemplate SavedSkin;

      public BindKeyExample() {
         SavedSkin = Player.Skin;
         BindKey(Keys.F7, new KeyPressDelegate(SpawnCar));
         BindKey(Keys.F8, new KeyPressDelegate(ChangeSkin));
      }

      private void SpawnCar() {
         Vehicle v = World.CreateVehicle("BANSHEE", Player.Character.Position.Around(5.0F));
         v.NoLongerNeeded(); // Call this to make sure that the game will NOT keep the vehicle forever
      }

      private void ChangeSkin() {
         Ped target = Player.GetTargetedPed(); // Get the ped the player is targetting currently to "steal" his skin
         if (target == null) {
            if (Player.Model != "PLAYER")        // check if the player model has changed
               Player.Skin.Template = SavedSkin; // revert back to your original model and outfit
            else
               Player.ActivateMultiplayerSkin();  // Activate the player skin selected for multiplayer mode if no ped is targeted and skin is default
               //Player.Model = "M_Y_SWAT";       // use this instead of the line above to change the player model to the SWAT skin
         } else {
            Player.Skin.Template = target.Skin;
         }
      }

   }


   // ### Type "Explode" into the console and you will explode...                   ###
   // ### Type "SpawnCar ?" (where ? is a number from 1 to 6) to get a new vehicle. ###
   // ### Call 123 on the phone to get an Annihilator helicopter.                   ###
   public class InfoAndBindExample : Script {

      public InfoAndBindExample() {
         GeneralInfo = "Use console commands to make you explode, or spawn some vehicles. Call 123 on the phone to get an Annihilator helicopter.";
         BindConsoleCommand("Explode", new ConsoleCommandDelegate(ExplodeCommand), "- BOOOOOM!");
         BindConsoleCommand("SpawnCar", new ConsoleCommandDelegate(CarCommand), "[number] - Spawn an Infernus, Comet, SultanRS, Partiot, NRG 900 or Airtug");
         BindPhoneNumber("GET 555 heli", new PhoneDialDelegate(SpawnAnnihilator)); // the number "GET 555 heli" is dialed as 438 555 4354
      }

      private void ExplodeCommand(ParameterCollection Parameter) {
         World.AddExplosion(Player.Character.Position);
      }

      private void SpawnAnnihilator() {
         Vehicle v = World.CreateVehicle("ANNIHILATOR", Player.Character.Position.Around(5.0F));
         v.NoLongerNeeded(); // Call this to make sure that the game will NOT keep the vehicle forever
      }

      private void CarCommand(ParameterCollection Parameter) {
         String CarType;
         switch (Parameter.ToInteger(0)) { // convert the first parameter (0) into an integer value
            case 1: CarType = "INFERNUS"; break;
            case 2: CarType = "COMET"; break;
            case 3: CarType = "SULTANRS"; break;
            case 4: CarType = "PATRIOT"; break;
            case 5: CarType = "NRG900"; break;
            default: CarType = "AIRTUG"; break;
         }
         Vehicle v = World.CreateVehicle(CarType, Player.Character.Position.Around(5.0F));
         v.NoLongerNeeded(); // Call this to make sure that the game will NOT keep the vehicle forever
      }

   }


   // ### Shows how to use PerFrameDrawing to draw graphical elements to the screen.         ###
   // ### Hold down the NumPad0 key in game and two blue boxes with red numbers will appear. ###
   public class DrawingExample : Script {

   GTA.Font screenFont;
   GTA.Font pixelFont;

   Color screenBoxColor = Color.FromArgb(127, 0, 0, 255);
   Color pixelBoxColor = Color.FromArgb(127, 0, 255, 0);

      public DrawingExample() {
         screenFont = new GTA.Font(0.15F, FontScaling.ScreenUnits);
         screenFont.Color = Color.Red;
         
         pixelFont = new GTA.Font(48.0F, FontScaling.Pixel);
         pixelFont.Color = Color.Red;

         this.PerFrameDrawing += new GraphicsEventHandler(this.DrawingExample_PerFrameDrawing);
      }

      private void DrawingExample_PerFrameDrawing(object sender, GraphicsEventArgs e) {
         if (isKeyPressed(Keys.NumPad0)) {
            e.Graphics.Scaling = FontScaling.Pixel; // fixed amount of pixels, size on screen will differ for each resolution
            RectangleF rect = new RectangleF(64, 64, 128, 128);
            e.Graphics.DrawRectangle(rect, pixelBoxColor);
            e.Graphics.DrawText("1", rect, TextAlignment.Center | TextAlignment.VerticalCenter, pixelFont);

            e.Graphics.Scaling = FontScaling.ScreenUnits; // size on screen will always be the same, regardless of resolution
            rect = new RectangleF(0.65F, 0.65F, 0.2F, 0.2F);
            e.Graphics.DrawRectangle(rect, screenBoxColor);
            e.Graphics.DrawText("2", rect, TextAlignment.Center | TextAlignment.VerticalCenter, screenFont);
         }
      }

   }


   // ### Spawns a Ped when pressing K, which attacks you for 5 sec, flees for 5 sec and then dies  ###
   public class TaskSequenceExample : Script {

      TaskSequence FleeTask;

      public TaskSequenceExample() {
         // Add tasks to the TaskSequence
         FleeTask = new TaskSequence();
         FleeTask.AddTask.SwapWeapon(Weapon.Handgun_Glock);
         FleeTask.AddTask.FightAgainst(Player, 5000);
         FleeTask.AddTask.FleeFromChar(Player, false, 5000);
         FleeTask.AddTask.Die();

         this.KeyDown += new GTA.KeyEventHandler(this.TaskSequenceExample_KeyDown);
      }

      private void TaskSequenceExample_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (e.Key != Keys.K) return;

         Ped p = World.CreatePed(Player.Character.Position.Around(3.0F));
         p.CurrentRoom = Player.Character.CurrentRoom;
         p.Weapons.Glock.Ammo = 1000;
         p.Task.PerformSequence(FleeTask);
      }

   }


   // ### Press Z and the ped you are aiming at will start walking towards you like a zombie  ###
   public class EuphoriaExample : Script {

      Ped Zombie;

      public EuphoriaExample() {
         Interval = 250;
         GeneralInfo = "Press Z and the ped you are aiming at will start walking towards you like a zombie!";
         BindKey(Keys.Z, new KeyPressDelegate(DoTheZombie));

         this.Tick += new EventHandler(this.EuphoriaExample_Tick);
      }

      private void DoTheZombie() {
         if (Exists(Zombie)) {
            Zombie.isRagdoll = false;
            Zombie = null;
            return;
         }

         Zombie = Player.GetTargetedPed();
         if (!Exists(Zombie)) return;

         Game.DisplayText("ZOMBIES!!!");
         Zombie.Euphoria.BodyBalance.Start(-1);
      }

      private void EuphoriaExample_Tick(object sender, EventArgs e) {
         if (!Exists(Zombie)) return;

         if (Zombie.isGettingUp) return; // wait until the zombie is standing
         if (!Zombie.isRagdoll) Zombie.Euphoria.BodyBalance.Start(-1);
         if (!Zombie.Euphoria.BodyBalance.isBalanced) { // get up again when fallen to the ground
            Zombie.isRagdoll = false;
            return;
         }

         Zombie.Euphoria.LeanToPosition.Amount = 1.0F;
         Zombie.Euphoria.LeanToPosition.ApplyAsForce = true;
         Zombie.Euphoria.LeanToPosition.Position = Player.Character.Position;
         Zombie.Euphoria.LeanToPosition.Start();
      }

   }


   // ### Uses native calls to get the name of the current vehicle when pressing L  ###
   public class NativeCallExample : Script {

      public NativeCallExample() {
         this.KeyDown += new GTA.KeyEventHandler(this.NativeCallExample_KeyDown);
      }

      private void NativeCallExample_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (e.Key != Keys.L) return;

         GTA.Native.Pointer PedPointer = typeof(Ped);
         GTA.Native.Function.Call("GET_PLAYER_CHAR", Player, PedPointer);
         Ped PlayerChar = PedPointer;

         if (!GTA.Native.Function.Call<bool>("IS_CHAR_IN_ANY_CAR", PlayerChar)) {
            Game.DisplayText("Not in a car!");
            return;
         }

         GTA.Native.Pointer CarPointer = typeof(Vehicle);
         GTA.Native.Function.Call("GET_CAR_CHAR_IS_USING", PlayerChar, CarPointer);

         GTA.Native.Pointer ModelPointer = typeof(Model);
         GTA.Native.Function.Call("GET_CAR_MODEL", CarPointer.ToInputParameter(), ModelPointer);

         String name = GTA.Native.Function.Call<String>("GET_DISPLAY_NAME_FROM_VEHICLE_MODEL", ModelPointer.ToInputParameter());

         Game.DisplayText("Car name: " + name);
      }

   }


   //// ### Syncronizes ingame time with the real time ###
   //public class TimeSyncExample : Script {

   //   private int day;

   //   public TimeSyncExample() {
   //      Interval = 10000;
   //      DateTime real = DateTime.Now;
   //      day = real.DayOfYear;
   //      World.LockDayTime(real.Hour, real.Minute);

   //      this.Tick += new EventHandler(this.TimeSyncExample_Tick);
   //   }

   //   private void TimeSyncExample_Tick(object sender, EventArgs e) {
   //      DateTime real = DateTime.Now;
   //      if (day != real.DayOfYear) { // we can be sure that a new day begun in reality when the DayOfYear has changed
   //         day = real.DayOfYear;
   //         World.OneDayForward();
   //      }
   //      Weather w = World.Weather; // store and reset the weather, because LockDayTime changes it instantly
   //      World.LockDayTime(real.Hour, real.Minute);
   //      World.Weather = w;
   //   }

   //}


   //### Press J to smoke a spliff... Press J again or switch to a weapon to drop it. ###
   public class AnimationExample : Script {

      bool bSmoking = false;
      GTA.Object spliff;
      GTA.Timer timer = new GTA.Timer(); // the timer will always show the elapsed gametime since the last Start()

      AnimationSet anims = new AnimationSet("amb@smoking_spliff");
      AnimationFlags animflags = AnimationFlags.Unknown12 | AnimationFlags.Unknown11 | AnimationFlags.Unknown09;

      public AnimationExample() {
         Interval = 1000;
         this.KeyDown += new GTA.KeyEventHandler(this.AnimationExample_KeyDown);
         this.Tick += new EventHandler(this.AnimationExample_Tick);
      }

      private void AnimationExample_KeyDown(object sender, GTA.KeyEventArgs e) {
         if (e.Key != Keys.J) return;
         if (bSmoking)
            StopSmoking();
         else
            StartSmoking();
      }

      private void StartSmoking() {
         if (bSmoking) return;
         bSmoking = true;

         Player.Character.Weapons.Unarmed.Select();
         Player.Character.Animation.Play(anims, "create_spliff", 8.0F, animflags);
         Wait(1600);

         spliff = World.CreateObject(0xD130ADEF, Player.Character.Position);
         spliff.AttachToPed(Player.Character, Bone.RightHand, new Vector3(0.14F, 0.03F, 0.04F), new Vector3(2.21F, -0.12F, 0.0F));

         Player.Character.Animation.WaitUntilFinished(anims, "create_spliff");
         timer.Start();
      }

      private void StopSmoking() {
         if (!bSmoking) return;
         bSmoking = false;
         if (spliff == null) return;

         spliff.Detach();
         spliff.NoLongerNeeded();
      }

      private void AnimationExample_Tick(object sender, EventArgs e) {
         if (bSmoking) {
            if (Player.Character.Weapons.CurrentType != Weapon.Unarmed) {
               StopSmoking();
            } else if ((timer.ElapsedTime > 10000) && (Player.Character.isIdle)) {
               if (Player.Character.isInVehicle())
                  Player.Character.Task.PlayAnimation(anims, "partial_smoke_car", 8.0F, animflags);
               else
                  Player.Character.Task.PlayAnimation(anims, "partial_smoke", 8.0F, animflags);
               timer.Start();
            }
         }
      }

   }

}