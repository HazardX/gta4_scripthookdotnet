/*
* Copyright (c) 2009-2011 Hazard (hazard_x@gmx.net / twitter.com/HazardX)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#pragma once
#pragma managed

namespace GTA {

	public enum class DecisionCategory {
		Behavior,
		Combat,
		GroupBehavior,
		GroupCombat,
	};

	public ref class DecisionMaker sealed : base::HandleObject {

		private:static const int COPY_OFFSET = 0xFFFF + 1;

	public:

		enum class BehaviorTemplate {
			None = 0,
			Normal = 1,
			Tough = 2,
			Weak = 3,
		};

		enum class CombatTemplate {
			GP_CR = 0,
			GP_NO = 1,
			GP_PR = 2,
			GP_Hide = 3,
			M_NO_NO = 4,
			M_Coward = 5,
			//M_NO_NO = 6,
			//M_NO_NO = 7,
			CopNormal = 8,
			CopWantedLevel1 = 9,
			CopWantedLevel2 = 10,
			CopWantedLevel3 = 11,
		};

		enum class CopyTemplate {
			Behavior_CR_Norm	= COPY_OFFSET + 0,
			Behavior_m_norm	= COPY_OFFSET + 1,
			Behavior_m_plyr	= COPY_OFFSET + 2,
			Behavior_GP_Norm	= COPY_OFFSET + 3,
			Behavior_GP_JustFollow		= COPY_OFFSET + 4,
			Behavior_Cop		= COPY_OFFSET + 5,
			Behavior_R_Norm	= COPY_OFFSET + 6,
			Behavior_Fireman	= COPY_OFFSET + 7,
			Behavior_m_empty	= COPY_OFFSET + 8,
			Combat_gp_cr		= COPY_OFFSET + 9,
			Combat_gp_no		= COPY_OFFSET + 10,
			Combat_gp_pr		= COPY_OFFSET + 11,
			Combat_gp_hide		= COPY_OFFSET + 12,
			Combat_m_no_no		= COPY_OFFSET + 13,
			Combat_m_Coward	= COPY_OFFSET + 14,
			//Combat_m_no_no		= COPY_OFFSET + 15,
			//Combat_m_no_no		= COPY_OFFSET + 16,
			Combat_cop_nrm		= COPY_OFFSET + 17,
			Combat_cop_wl1		= COPY_OFFSET + 18,
			Combat_cop_wl2		= COPY_OFFSET + 19,
			Combat_cop_wl3		= COPY_OFFSET + 20,
			//Behavior_m_empty	= COPY_OFFSET + 21,
			//Behavior_m_norm	= COPY_OFFSET + 22,
			Behavior_m_tough	= COPY_OFFSET + 23,
			Behavior_m_weak	= COPY_OFFSET + 24,
			Combat_m_Empty		= COPY_OFFSET + 25,
			//Combat_m_Coward	= COPY_OFFSET + 26,
			Combat_m_no_de		= COPY_OFFSET + 27,
			Combat_m_no_fi		= COPY_OFFSET + 28,
			Combat_m_hide		= COPY_OFFSET + 29,
			Combat_m_cr_de		= COPY_OFFSET + 30,
			Combat_m_cr_no		= COPY_OFFSET + 31,
			Combat_m_cr_fi		= COPY_OFFSET + 32,
			Combat_m_pr_de		= COPY_OFFSET + 33,
			Combat_m_pr_no		= COPY_OFFSET + 34,
			Combat_m_pr_fi		= COPY_OFFSET + 35,
			Combat_m_boss		= COPY_OFFSET + 36,
			//Behavior_m_empty	= COPY_OFFSET + 37,
			//Behavior_m_norm	= COPY_OFFSET + 38,
			//Behavior_m_tough	= COPY_OFFSET + 39,
			//Behavior_m_weak	= COPY_OFFSET + 40,
			//Combat_m_Empty		= COPY_OFFSET + 41,
			//Combat_m_Coward	= COPY_OFFSET + 42,
			//Combat_m_no_de		= COPY_OFFSET + 43,
			//Combat_m_no_fi		= COPY_OFFSET + 44,
			//Combat_m_hide		= COPY_OFFSET + 45,
			//Combat_m_cr_de		= COPY_OFFSET + 46,
			//Combat_m_cr_no		= COPY_OFFSET + 47,
			//Combat_m_cr_fi		= COPY_OFFSET + 48,
			//Combat_m_pr_de		= COPY_OFFSET + 49,
			//Combat_m_pr_no		= COPY_OFFSET + 50,
			//Combat_m_pr_fi		= COPY_OFFSET + 51,
			//Combat_m_boss		= COPY_OFFSET + 52,
		};


	private:

		//static const int COPY_OFFSET = 0xFFFF + 1;

		DecisionCategory pCategory;

	internal:
		DecisionMaker(int Handle, DecisionCategory Category);

		virtual bool InternalCheckExists() override;
		
	public:
		~DecisionMaker();

		static DecisionMaker^ LoadBehavior(BehaviorTemplate Template);
		static DecisionMaker^ LoadCombat(CombatTemplate Template);
		static DecisionMaker^ CopyBehavior(CopyTemplate Template);
		static DecisionMaker^ CopyCombat(CopyTemplate Template);
		static DecisionMaker^ CopyBehaviorForGroupMembers(CopyTemplate Template);
		static DecisionMaker^ CopyCombatForGroupMembers(CopyTemplate Template);

		//property DecisionTemplate Template {
		//	DecisionTemplate get();
		//}
		property DecisionCategory Category {
			DecisionCategory get();
		}

		void ApplyTo(GTA::Ped^ Ped);

		//virtual bool Exists() override;

		void RemoveEventResponse(int EventID);
		void AddEventResponse(int EventID, int ResponseID, float param1, float param2, float param3, float param4);

		property bool CanChangeTarget {
			void set(bool value);
		}

		/// <summary>
		/// Not sure which values it takes. 2 is a common value and means most likely "more cautious than normal".
		/// </summary>
		property int Caution {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common values are 0, 1 and 2.
		/// </summary>
		property int FireRate {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes.
		/// </summary>
		property int LowHealth {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes.
		/// </summary>
		property int MovementStyle {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common values are 0, 1 and 2.
		/// </summary>
		property int NavigationStyle {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common values are 1 and 2.
		/// </summary>
		property int RetreatingBehavior {
			void set(int value);
		}

		/// <summary>
		/// Range of sight in meters/yards.
		/// </summary>
		property int SightRange {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes.
		/// </summary>
		property int StandingStyle {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common value is 0.
		/// </summary>
		property int TargetInjuredReaction {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common values are 0 and 2.
		/// </summary>
		property int TargetLossResponse {
			void set(int value);
		}

		/// <summary>
		/// Not sure what it does or which values it takes. Common value is 2.
		/// </summary>
		property int Teamwork {
			void set(int value);
		}

		/// <summary>
		/// Weapon accuracy. Overrides Ped.Accuracy
		/// </summary>
		property int WeaponAccuracy {
			void set(int value);
		}

	};

}

//LOAD:
//char:
//0
//1
//2
//3
//combat:
//0
//1
//2
//3
//4
//7
//8
//9
//10
//11

//COPY:
//65536 -> 0
//65537 -> 1
//65539 -> 3
//65546 -> 10
//65555 -> 19
//65568 -> 32

//CR_Norm.ped
//m_norm.ped
//m_plyr.ped
//GP_Norm.ped
//GP_JustFollow.ped
//Cop.ped
//R_Norm.ped
//Fireman.ped
//m_empty.ped
//
//Combat/gp_cr.cmb
//Combat/gp_no.cmb
//Combat/gp_pr.cmb
//Combat/gp_hide.cmb
//Combat/m_no_no.cmb
//Combat/m_Coward.cmb
//Combat/m_no_no.cmb
//Combat/m_no_no.cmb
//Combat/cop_nrm.cmb
//Combat/cop_wl1.cmb
//Combat/cop_wl2.cmb
//Combat/cop_wl3.cmb
//
//m_empty.ped
//m_norm.ped
//m_tough.ped
//m_weak.ped
//
//Combat/m_Empty.cmb
//Combat/m_Coward.cmb
//Combat/m_no_de.cmb
//Combat/m_no_fi.cmb
//Combat/m_hide.cmb
//Combat/m_cr_de.cmb
//Combat/m_cr_no.cmb
//Combat/m_cr_fi.cmb
//Combat/m_pr_de.cmb
//Combat/m_pr_no.cmb
//Combat/m_pr_fi.cmb
//Combat/m_boss.cmb
//
//m_empty.ped
//m_norm.ped
//m_tough.ped
//m_weak.ped
//
//Combat\m_Empty.cmb
//Combat\m_Coward.cmb
//Combat\m_no_de.cmb
//Combat\m_no_fi.cmb
//Combat\m_hide.cmb.
//Combat\m_cr_de.cmb
//Combat\m_cr_no.cmb
//Combat\m_cr_fi.cmb
//Combat\m_pr_de.cmb
//Combat\m_pr_no.cmb
//Combat\m_pr_fi.cmb
//Combat\m_boss.cmb