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

namespace GTA{

	public ref class Group sealed : 
		public base::HandleObject, 
		public base::iGroup,
		public base::iDeletable,
		public System::Collections::Generic::IEnumerable<Ped^> {

	protected:
		//int pHandle;
		static const int MAX_GROUP_SIZE = 7;

	internal:
		Group(int Handle);
		//property int Handle{ 
		//	int get();
		//}

		void SetHandle(int Handle, bool CreatedByMe);
		virtual bool InternalCheckExists() override;

	public:
		Group(Ped^ Leader);

		property Ped^ Leader{ 
			virtual Ped^ get();
			void set(Ped^ value);
		}
		property int MemberCount { 
			virtual int get();
		}
		property int MaxMemberCount { 
			int get();
		}
		
		property int FollowStatus { 
			void set(int value);
		}
		property int Formation { 
			void set(int value);
		}
		property float FormationSpacing { 
			void set(float value);
		}

		/// <summary>
		/// The distance at which members leave the group automatically (in meters/yard). Default is 75.
		/// </summary>
		property float SeparationRange { 
			void set(float value);
		}

		bool isLeader(Ped^ ped);
		bool isMember(Ped^ ped);
		bool AddMember(Ped^ ped, bool NeverLeave);
		virtual bool AddMember(Ped^ ped);
		Ped^ GetMember(int Index);
		void RemoveMember(Ped^ ped);
		void RemoveMember(int Index);
		void RemoveAllMembers();
		array<Ped^>^ ToArray(bool IncludingLeader);
		PedCollection^ ToList(bool IncludingLeader);

		//int GetIndex(Ped^ ped);
		//void SetMembersDuckWhenAimedAt(bool duck);
		//void SetSeparationRange(float seperation);
		//void SetFollowStatus(int status);
		//void SetFormation(int formation);
		//void SetFormationSpacing(float space);

		void EnterVehicle(GTA::Vehicle^ Vehicle, bool WithLeader, bool KeepCurrentDriver);

		//virtual bool Exists() override;
		virtual void Delete();

		static bool operator == ( Group^ left, Group^ right );
		static bool operator != ( Group^ left, Group^ right );

	private:

		// Enumerator
		ref struct enumerator : System::Collections::Generic::IEnumerator<Ped^> {
        enumerator( Group^ group ) {
            colInst = group;
            currentIndex = group->MemberCount;
        }

        virtual bool MoveNext() {
            if( currentIndex > 0 ) {
               currentIndex--;
					currentPed = colInst->GetMember(currentIndex);
					if (!Object::ReferenceEquals(currentPed,nullptr)) return true;
               return MoveNext();
            }
				currentPed = nullptr;
            return false;
        }
    
        virtual property Ped^ Current {
            Ped^ get() {
					return currentPed;
            }
        };
        // This is required as IEnumerator<T> also implements IEnumerator
        virtual property Object^ Current2 {
            virtual Object^ get() sealed = System::Collections::IEnumerator::Current::get {
                return Current;
            }
        };
        
        virtual void Reset() {}
        ~enumerator() {}
            
        Group^ colInst;
        int currentIndex;
		  Ped^ currentPed;
    };
   
    virtual System::Collections::IEnumerator^ Group::GetEnumerator2() sealed = System::Collections::IEnumerable::GetEnumerator {
        return gcnew enumerator(this);
    }

	public:

	 virtual System::Collections::Generic::IEnumerator<Ped^>^ Group::GetEnumerator() {
        return gcnew enumerator(this);
    }

	};

}