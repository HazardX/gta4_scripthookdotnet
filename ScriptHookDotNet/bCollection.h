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

	using namespace System;
	//using namespace System::Collections::Generic;

	generic <typename T>
	[System::SerializableAttribute]
	public ref class BaseCollection abstract : System::Collections::Generic::IList<T> {

	protected:

		virtual bool isReadOnly() = System::Collections::Generic::ICollection<T>::IsReadOnly::get {
			return false;
		}

		virtual void pAdd(T item) abstract = System::Collections::Generic::ICollection<T>::Add;
		virtual void pInsert(int index, T item) abstract = System::Collections::Generic::IList<T>::Insert;
		virtual bool pRemove(T item) abstract = System::Collections::Generic::ICollection<T>::Remove;
		virtual void pRemoveAt(int index) abstract = System::Collections::Generic::IList<T>::RemoveAt;
		virtual void pClear() abstract = System::Collections::Generic::ICollection<T>::Clear;

		virtual void pAddRange(System::Collections::Generic::IEnumerable<T>^ collection) {
			for each (T item in collection) {
				pAdd(item);
			}
		}

	public:

		property T default[int] {
			virtual T get(int index) abstract;
			virtual void set(int index, T value) abstract;
		}

		property int Count {
			virtual int get() abstract;
		}

		virtual bool Contains(T item) abstract;
		virtual int IndexOf(T item) abstract;

		virtual System::Collections::Generic::IEnumerator<T>^ GetEnumerator() abstract;
		virtual void CopyTo(int Index, array<T>^ TargetArray, int TargetIndex, int Count) abstract;

		virtual void CopyTo(array<T>^ Array, int ArrayIndex) sealed = System::Collections::Generic::ICollection<T>::CopyTo {
			CopyTo(0, Array, ArrayIndex, Count);
		}

		array<T>^ ToArray() {
			array<T>^ ary = gcnew array<T>(Count);
			CopyTo(0, ary, 0, Count);
			return ary;
		}

	private:

		virtual System::Collections::IEnumerator^ GetEnumerator2() sealed = System::Collections::IEnumerable::GetEnumerator {
			return GetEnumerator();
		}

	};

	generic <typename T>
	[System::SerializableAttribute]
	public ref class ReadOnlyCollection abstract : BaseCollection<T> {

	protected:

		System::Collections::Generic::List<T>^ pList;

	public:

		ReadOnlyCollection() {
			pList = gcnew System::Collections::Generic::List<T>();
		}

	protected:

		virtual bool isReadOnly() override {
			return true;
		}

		virtual void pAdd(T item) override {
			pList->Add(item);
		}

		virtual void pInsert(int index, T item) override {
			pList->Insert(index,item);
		}

		virtual bool pRemove(T item) override {
			return pList->Remove(item);
		}

		virtual void pRemoveAt(int index) override {
			pList->RemoveAt(index);
		}

		virtual void pClear() override {
			pList->Clear();
		}

	public:

		property T default[int] {
			virtual T get(int index) override {
				return pList->default[index];
			}
			virtual void set(int index, T value) override {
				pList->default[index] = value;
			}
		}

		property int Count {
			virtual int get() override {
				return pList->Count;
			}
		}

		virtual bool Contains(T item) override {
			return pList->Contains(item);
		}
		virtual int IndexOf(T item) override {
			return pList->IndexOf(item);
		}

		virtual void CopyTo(int Index, array<T>^ TargetArray, int TargetIndex, int Count) override {
			pList->CopyTo(Index, TargetArray, TargetIndex, Count);
		}

		virtual System::Collections::Generic::IEnumerator<T>^ GetEnumerator() override {
			return pList->GetEnumerator();
		}

	};

	generic <typename T>
	[System::SerializableAttribute]
	public ref class Collection : ReadOnlyCollection<T> {

	protected:

		virtual bool isReadOnly() override {
			return false;
		}

	public:

		void Add(T item) {
			pAdd(item);
		}
		void AddRange(System::Collections::Generic::IEnumerable<T>^ collection) {
			pAddRange(collection);
		}

		void Insert(int index, T item) {
			pInsert(index,item);
		}

		bool Remove(T item) {
			return pRemove(item);
		}

		void RemoveAt(int index) {
			pRemoveAt(index);
		}

		void Clear() {
			pClear();
		}

	};

}
}