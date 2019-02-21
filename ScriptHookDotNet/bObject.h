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
namespace base {

	CLASS_ATTRIBUTES
	[System::SerializableAttribute]
	public ref class Object abstract :
		iBaseObject {

	public:
		/// <summary>
		/// The event will be raised as soon as the object ceases to exist in game.
		/// </summary>
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		event EventHandler^ CeasedToExist;

	private:
		bool bExists;
		static int sUID = 1;
		int pUID;
		int pLastExistsCheck;

	protected:
		[System::ComponentModel::EditorBrowsableAttribute(EditorBrowsableState::Never)]
		virtual void OnCeasedToExist(EventArgs^ e) {
			CeasedToExist(this, e);
		}

	internal:
		virtual bool InternalCheckExists() {
			return true;
		}

		//bool ThrowExistError();

		property int UID {
			int get() { return pUID; }
		}

		void SetExistsFalse() {
			bExists = false;
		}
		void ResetExists() {
			bExists = true;
			pLastExistsCheck = -1;
		}
		void ForceNextExistsCheck() {
			pLastExistsCheck = -1;
		}
		bool ExistsForced() {
			pLastExistsCheck = -1;
			return Exists();
		}

	public:
		Object(){
			bExists = true;
			pUID = sUID++;
			pLastExistsCheck = -1;
		}

		/// <summary>
		/// Returns whether the object still exists in game. Other calls to non-existing objects will result in an error. This function is FAST and is better checked too much rather than too less.
		/// </summary>
		virtual bool Exists() sealed;

	};

}
}