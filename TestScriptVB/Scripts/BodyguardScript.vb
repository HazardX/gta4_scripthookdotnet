Imports System
Imports System.Windows.Forms
Imports GTA

' ### Spawn Bodyguards with the INSERT key, and kill them with the DELETE key ###
Public Class BodyguardScript
   Inherits Script

   Private Group As Group = Player.Group
   Private PedModel As Model = "M_Y_BOUNCER_02"

   Public Sub New()
      Interval = 250
   End Sub

   Private Sub BodyguardScript_KeyDown(ByVal sender As Object, ByVal e As GTA.KeyEventArgs) Handles MyBase.KeyDown
      Select Case e.Key

         Case Keys.Insert
            If Group.MemberCount < 3 Then ' limit to 3 members, to make sure that all fit in a car
               Dim p As Ped = World.CreatePed(PedModel, Player.Character.Position.Around(3.0F), RelationshipGroup.Player)
               AddToGroup(p)
            End If

         Case Keys.Delete
            For Each Member As Ped In Group
               Member.Weapons.RemoveAll()
               Member.Die()
            Next
            Group.RemoveAllMembers()

      End Select
   End Sub

   Private Sub AddToGroup(ByVal p As Ped)
      If Not Exists(p) Then Return ' check if the ped is valid
      If Group.isMember(p) Then Return

      p.CurrentRoom = Player.Character.CurrentRoom ' required, or ped won't be visible when spawned inside a building
      p.WillDoDrivebys = True
      p.PriorityTargetForEnemies = True
      p.DuckWhenAimedAtByGroupMember = False
      p.SetPathfinding(True, True, True)
      p.AlwaysDiesOnLowHealth = True
      p.Accuracy = 100

      Dim weap As Weapon = Player.Character.Weapons.Current
      p.Weapons(weap).Ammo = 30000
      p.Weapons.MP5.Ammo = 30000
      p.Weapons.Select(weap) ' activate same weapon as the one the player carries

      p.RelationshipGroup = RelationshipGroup.Player
      p.ChangeRelationship(RelationshipGroup.Player, Relationship.Companion)
      p.CantBeDamagedByRelationshipGroup(RelationshipGroup.Player, True)

      Group.AddMember(p)
      Game.DisplayText(Group.MemberCount & " members in gang")
   End Sub

End Class