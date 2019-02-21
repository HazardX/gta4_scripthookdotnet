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

	using namespace System;
	//using namespace System::Collections::Generic;

	value class Vector3;
	ref class Script;
	ref class Graphics;

	CLASS_ATTRIBUTES
	[AttributeUsage(AttributeTargets::Property)]
	public ref class ConfigItemAttribute : public System::Attribute {
		
	private:
		String^ pName;

	public:
		ConfigItemAttribute() {
			pName = String::Empty;
		}
		ConfigItemAttribute(String^ Name) {
			pName = Name;
		}

		property String^ Name {
			String^ get() {
				return pName;
			}
		}

	};

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class SerializableEventArgs : EventArgs {};
	public delegate void SerializableEventHandler(System::Object^ sender, SerializableEventArgs^ e);


	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class KeyEventArgs : SerializableEventArgs {
	private:
		System::Windows::Forms::Keys pKey;

	internal:
		KeyEventArgs(System::Windows::Forms::Keys Key) {
			pKey = Key;
		}

	public:
		/// <summary>
		/// Returns the key without any modifier information.
		/// </summary>
		property System::Windows::Forms::Keys Key {
			System::Windows::Forms::Keys get() {
				return (pKey & System::Windows::Forms::Keys::KeyCode);
			}
		}
		/// <summary>
		/// Returns the key combined with modifier (Shift, Control, Alt) information.
		/// </summary>
		property System::Windows::Forms::Keys KeyWithModifiers {
			System::Windows::Forms::Keys get() {
				return pKey;
			}
		}
		/// <summary>
		/// Returns if the key was pressed in combination with Shift.
		/// </summary>
		property bool Shift {
			bool get() {
				return ((pKey & System::Windows::Forms::Keys::Shift) != System::Windows::Forms::Keys::None);
			}
		}
		/// <summary>
		/// Returns if the key was pressed in combination with Control.
		/// </summary>
		property bool Control {
			bool get() {
				return ((pKey & System::Windows::Forms::Keys::Control) != System::Windows::Forms::Keys::None);
			}
		}
		/// <summary>
		/// Returns if the key was pressed in combination with Alt.
		/// </summary>
		property bool Alt {
			bool get() {
				return ((pKey & System::Windows::Forms::Keys::Alt) != System::Windows::Forms::Keys::None);
			}
		}

		property bool isModifier {
			bool get() {
				switch (Key) {
					case System::Windows::Forms::Keys::ShiftKey: return true;
					case System::Windows::Forms::Keys::LShiftKey: return true;
					case System::Windows::Forms::Keys::RShiftKey: return true;
					case System::Windows::Forms::Keys::ControlKey: return true;
					case System::Windows::Forms::Keys::LControlKey: return true;
					case System::Windows::Forms::Keys::RControlKey: return true;
					case System::Windows::Forms::Keys::Menu: return true;
					case System::Windows::Forms::Keys::LMenu: return true;
					case System::Windows::Forms::Keys::RMenu: return true;
				}
				return false;
			}
		}
		property System::Windows::Forms::MouseButtons MouseButton {
			System::Windows::Forms::MouseButtons get() {
				switch (Key) {
					case System::Windows::Forms::Keys::LButton: return System::Windows::Forms::MouseButtons::Left;
					case System::Windows::Forms::Keys::RButton: return System::Windows::Forms::MouseButtons::Right;
					case System::Windows::Forms::Keys::MButton: return System::Windows::Forms::MouseButtons::Middle;
					case System::Windows::Forms::Keys::XButton1: return System::Windows::Forms::MouseButtons::XButton1;
					case System::Windows::Forms::Keys::XButton2: return System::Windows::Forms::MouseButtons::XButton2;
				}
				return System::Windows::Forms::MouseButtons::None;
			}
		}
		property bool isMouseButton {
			bool get() {
				return (MouseButton != System::Windows::Forms::MouseButtons::None);
			}
		}
	};
	public delegate void KeyEventHandler(System::Object^ sender, KeyEventArgs^ e);

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class MouseEventArgs : SerializableEventArgs {
	private:
		bool bMouseVisible;
		System::Windows::Forms::MouseButtons pButton;
		Drawing::PointF pLocation;

	internal:
		MouseEventArgs(bool isMouseVisible, Drawing::PointF Location, System::Windows::Forms::MouseButtons Button) {
			bMouseVisible = isMouseVisible;
			pLocation = Location;
			pButton = Button;
		}

	public:
		property bool isMouseVisible {
			bool get() {
				return bMouseVisible;
			}
		}
		property System::Windows::Forms::MouseButtons Button {
			System::Windows::Forms::MouseButtons get() {
				return pButton;
			}
		}
		property Drawing::PointF Location {
			Drawing::PointF get() {
				return pLocation;
			}
		}
		property float X {
			float get() {
				return pLocation.X;
			}
		}
		property float Y {
			float get() {
				return pLocation.Y;
			}
		}
		property Drawing::Point PixelLocation {
			Drawing::Point get();
		}
	};
	public delegate void MouseEventHandler(System::Object^ sender, MouseEventArgs^ e);

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class ParameterCollection : base::ReadOnlyCollection<String^> {
	public:

		ParameterCollection(array<String^>^ Parameters);

		/// <summary>
		/// Converts the parameter at the given index into an integer value.
		/// </summary>
		int ToInteger(int index);
		/// <summary>
		/// Converts the parameter at the given index into a float value.
		/// </summary>
		float ToFloat(int index);
		/// <summary>
		/// Converts the 3 parameters starting at the given index into a Vector3 value.
		/// </summary>
		Vector3 ToVector3(int firstIndex);
		/// <summary>
		/// Converts the parameter at the given index into a model. It takes names, integers or hex values.
		/// </summary>
		GTA::Model ToModel(int index);
		/// <summary>
		/// Converts the parameter at the given index into a string.
		/// </summary>
		String^ ToString(int index);

	};

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class ObjectCollection : base::ReadOnlyCollection<System::Object^> {
	public:

		ObjectCollection(array<System::Object^>^ Objects);

		/// <summary>
		/// Tries to convert the parameter at the given index to type T.
		/// </summary>
		generic <typename T>
		T Convert(int index);

	};

	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class ConsoleEventArgs : SerializableEventArgs {

	private:
		String^ pCommand;
		ParameterCollection^ pParameter;

	internal:
		ConsoleEventArgs(String^ Command, array<String^>^ Parameter);

	public:
		property String^ Command {
			String^ get() { return pCommand; }
		}
		property ParameterCollection^ Parameter {
			ParameterCollection^ get() { return pParameter; }
		}
		property int ParameterCount {
			int get() { return pParameter->Count; }
		}

		virtual String^ ToString() override {
			if (pParameter->Count > 0)
				return pCommand + " _ " + String::Join(" _ ", pParameter->ToArray());
			else
				return pCommand;
		}

	};
	public delegate void ConsoleEventHandler(System::Object^ sender, ConsoleEventArgs^ e);
	
	[SerializableAttribute]
	public ref class ScriptCommandEventArgs : SerializableEventArgs {

	private:
		Script^ pSender;
		String^ pCommand;
		ObjectCollection^ pParameters;

	internal:
		ScriptCommandEventArgs(Script^ sender, String^ Command, array<System::Object^>^ Parameter);

	public:
		property Script^ sender {
			Script^ get() { return pSender; }
		}
		property String^ Command {
			String^ get() { return pCommand; }
		}
		property ObjectCollection^ Parameters {
			ObjectCollection^ get() { return pParameters; }
		}
		property int ParameterCount {
			int get() { return pParameters->Count; }
		}

		virtual String^ ToString() override {
			if (pParameters->Count > 0)
				return pCommand + " (" + ParameterCount.ToString() + " Parameters)";
			else
				return pCommand;
		}

	};
	public delegate void ScriptCommandEventHandler(System::Object^ sender, ScriptCommandEventArgs^ e);


	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class PhoneDialEventArgs : SerializableEventArgs {
	private:
		String^ pPhoneNumber;

	internal:
		PhoneDialEventArgs(String^ PhoneNumber) {
			pPhoneNumber = PhoneNumber;
		}

	public:
		property String^ PhoneNumber {
			String^ get() {
				return pPhoneNumber;
			}
		}
	};
	public delegate void PhoneDialEventHandler(System::Object^ sender, PhoneDialEventArgs^ e);


	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class GraphicsEventArgs : SerializableEventArgs {
	private:
		GTA::Graphics^ pGraphics;

	internal:
		GraphicsEventArgs(GTA::Graphics^ Graphics) {
			pGraphics = Graphics;
		}

	public:
		property GTA::Graphics^ Graphics {
			GTA::Graphics^ get() {
				return pGraphics;
			}
		}
	};
	public delegate void GraphicsEventHandler(System::Object^ sender, GraphicsEventArgs^ e);


	CLASS_ATTRIBUTES
	[SerializableAttribute]
	private ref class RemoteEventArgs : SerializableEventArgs {

	private:
		GTA::RemoteEvent pEventID;
		array<System::Object^>^ pArguments;

	internal:
		RemoteEventArgs(RemoteEvent EventID, ... array<System::Object^>^ Arguments) {
			pEventID = EventID;
			pArguments = Arguments;
		}

	public:
		property RemoteEvent EventID {
			RemoteEvent get() { return pEventID; }
		}
		property array<System::Object^>^ ArgumentArray {
			array<System::Object^>^ get() {	return pArguments; }
		}
		property int ArgumentCount {
			int get() {	return pArguments->Length; }
		}
		System::Object^ Argument(int index) {
			if ((index < 0) || (index >= ArgumentCount)) return nullptr;
			return pArguments[index];
		}
		
	};
	private delegate void RemoteEventHandler(System::Object^ sender, RemoteEventArgs^ e);



	CLASS_ATTRIBUTES
	[SerializableAttribute]
	public ref class ObjectEventArgs : SerializableEventArgs {
	private:
		System::Object^ pObject;

	internal:
		ObjectEventArgs(System::Object^ object) {
			pObject = object;
		}

	public:
		property System::Object^ Object {
			System::Object^ get() {
				return pObject;
			}
		}
	};
	public delegate void ObjectEventHandler(System::Object^ sender, ObjectEventArgs^ e);

	public delegate void KeyPressDelegate();
	public delegate void ConsoleCommandDelegate(ParameterCollection^ Parameter);
	public delegate void ScriptCommandDelegate(Script^ sender, ObjectCollection^ Parameter);
	public delegate void PhoneDialDelegate();

	private value class BoundKeyItem {
	public:
		System::Windows::Forms::Keys Key;
		KeyPressDelegate^ Delegate;
		BoundKeyItem(System::Windows::Forms::Keys key, KeyPressDelegate^ deleg) {
			Key = key;
			Delegate = deleg;
		}
	};
	private value class BoundCommandItem {
		public:
		String^ Command;
		String^ CommandPretty;
		ConsoleCommandDelegate^ Delegate;
		String^ HelpText;
		BoundCommandItem(String^ command, ConsoleCommandDelegate^ deleg, String^ helpText) {
			CommandPretty = command;
			Command = command->ToLower();
			Delegate = deleg;
			HelpText = helpText->Replace("\r",String::Empty)->Replace("\n"," ");
			//if (HelpText->Length > 99) HelpText = HelpText->Substring(0,99);
		}
	};
	private value class BoundScriptCommandItem {
		public:
		String^ Command;
		ScriptCommandDelegate^ Delegate;
		BoundScriptCommandItem(String^ command, ScriptCommandDelegate^ deleg) {
			Command = command->ToLower();
			Delegate = deleg;
		}
	};
	private value class BoundPhoneNumberItem {
		public:
		String^ PhoneNumber;
		PhoneDialDelegate^ Delegate;
		BoundPhoneNumberItem(String^ phoneNumber, PhoneDialDelegate^ deleg) {
			PhoneNumber = phoneNumber;
			Delegate = deleg;
		}
	};

	CLASS_ATTRIBUTES
	public ref class NonExistingObjectException : System::Exception {

		internal:

		static System::String^ DEFAULT_MESSAGE = "Invalid call to an object that doesn't exist anymore!";

		public:

		NonExistingObjectException() : System::Exception(DEFAULT_MESSAGE) {
		}

		NonExistingObjectException(System::String^ message) : System::Exception(message) {
		}

	};

}