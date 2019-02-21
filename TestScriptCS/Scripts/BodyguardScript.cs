using System;
using System.Windows.Forms;
using GTA;

namespace TestScriptCS {


   // ### Spawn Bodyguards with the INSERT key, and kill them with the DELETE key ###
   public class BodyguardScript : Script {

      Group group;
      Model PedModel = "M_Y_BOUNCER_02";

      public BodyguardScript() {
         Interval = 250;
         group = Player.Group;

         this.KeyDown += new GTA.KeyEventHandler(this.BodyguardScript_KeyDown);
      }

      private void BodyguardScript_KeyDown(object sender, GTA.KeyEventArgs e) {
         switch (e.Key) {

            case Keys.Insert:
               if (group.MemberCount < 3) { // limit to 3 members, to make sure that all fit in a car
                  Ped p = World.CreatePed(PedModel, Player.Character.Position.Around(3.0F), RelationshipGroup.Player);
                  AddToGroup(p);
               }
               break;

            case Keys.Delete:
               foreach (Ped member in group) {
                  member.Weapons.RemoveAll();
                  member.Die();
               }
               group.RemoveAllMembers();
               break;
         }
      }

      private void AddToGroup(Ped p) {
         if (!Exists(p)) return; // check if the ped is valid

         p.CurrentRoom = Player.Character.CurrentRoom; // required, or ped won't be visible when spawned inside a building
         p.WillDoDrivebys = true;
         p.PriorityTargetForEnemies = true;
         p.DuckWhenAimedAtByGroupMember = false;
         p.AlwaysDiesOnLowHealth = true;
         p.SetPathfinding(true, true, true);

         Weapon weap = Player.Character.Weapons.CurrentType;
         p.Weapons.FromType(weap).Ammo = 30000;
         p.Weapons.MP5.Ammo = 30000;
         p.Weapons.Select(weap); // activate same weapon as the one the player carries

         p.RelationshipGroup = RelationshipGroup.Player;
         p.ChangeRelationship(RelationshipGroup.Player, Relationship.Companion);
         p.CantBeDamagedByRelationshipGroup(RelationshipGroup.Player, true);

         group.AddMember(p);
         Game.DisplayText(group.MemberCount + " members in gang");
      }

   }

}