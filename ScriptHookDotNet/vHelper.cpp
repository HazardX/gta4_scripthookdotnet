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

#include "stdafx.h"

#include "vHelper.h"

#pragma managed

namespace GTA {

	bool Helper::isKeyPressedAsync(WinForms::Keys key) {
		return ((GetAsyncKeyState((int)key) & 0x8000) != 0);
	}

	GTA::Model Helper::StringToModel(String^ Input, GTA::Model DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;

		// hex
		if (Input->StartsWith("&H",StringComparison::InvariantCultureIgnoreCase) || Input->StartsWith("0x",StringComparison::InvariantCultureIgnoreCase)) {
			if (Input->Length < 3) return DefaultValue;
			try {
				return Model(HexToInteger(Input->Substring(2)));
			} catch(...) {
				return DefaultValue;
			}
		}
		// int
		int num = 0;
		if (int::TryParse(Input, NumberStyles::Integer, CultureIV, num)) return Model(num);
		// name
		return Model(Input);
	}

	Windows::Forms::Keys Helper::StringToKey(String^ Input, Windows::Forms::Keys DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;
		Windows::Forms::Keys res = DefaultValue;
		try {
			res = (Windows::Forms::Keys)System::Enum::Parse(Windows::Forms::Keys::typeid, Input->Trim(), true);
		} catch(...) {
			return DefaultValue;
		}
		return res;
	}

	Vector3 Helper::StringToVector3(String^ Input, Vector3 DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;
		array<String^>^ words = Input->Split(gcnew array<String^>(2){","," "}, StringSplitOptions::RemoveEmptyEntries);
		if (words->Length < 3) return DefaultValue;
		Vector3 res = DefaultValue;
		float f = 0.0F;
		if (!float::TryParse(words[0], NumberStyles::Float, CultureIV, f)) return DefaultValue;
		res.X = f;
		if (!float::TryParse(words[1], NumberStyles::Float, CultureIV, f)) return DefaultValue;
		res.Y = f;
		if (!float::TryParse(words[2], NumberStyles::Float, CultureIV, f)) return DefaultValue;
		res.Z = f;
		return res;
	}

	float Helper::StringToFloat(String^ Input, float DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;
		float res = DefaultValue;
		if (!float::TryParse(Input, NumberStyles::Float, CultureIV, res)) return DefaultValue;
		return res;
	}

	int Helper::StringToInteger(String^ Input, int DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;
		// hex
		if (Input->StartsWith("&H",StringComparison::InvariantCultureIgnoreCase) || Input->StartsWith("0x",StringComparison::InvariantCultureIgnoreCase)) {
			if (Input->Length < 3) return DefaultValue;
			try {
				return HexToInteger(Input->Substring(2));
			} catch(...) {
				return DefaultValue;
			}
		}
		// else
		int res = DefaultValue;
		if (!int::TryParse(Input, NumberStyles::Integer, CultureIV, res)) return DefaultValue;
		return res;
	}

	bool Helper::StringToBoolean(String^ Input, bool DefaultValue) {
		if (isNULL(Input) || (Input->Length == 0)) return DefaultValue;
		Input = Input->ToLower();
		if (Input == "true")  return true;
		if (Input == "false") return false;
		if (Input == "yes")   return true;
		if (Input == "no")    return false;
		if (Input == "on")    return true;
		if (Input == "off")   return false;
		if (Input == "1")     return true;
		if (Input == "0")     return false;
		return DefaultValue;
	}

	String^ Helper::FloatToString(float Input, int Digits) {
		return Input.ToString("F"+Digits.ToString(),CultureIV);
	}
	String^ Helper::FloatToString(float Input) {
		return FloatToString(Input, 2);
	}

	array<System::Byte>^ Helper::FileToData(String^ Filename) {
		try {
			if (!IO::File::Exists(Filename)) return gcnew array<System::Byte>(0);
			IO::FileStream^ fs = gcnew IO::FileStream(Filename, IO::FileMode::Open, IO::FileAccess::Read, IO::FileShare::Read);
         array<System::Byte>^ inbytes = gcnew array<System::Byte>((int)fs->Length);
         fs->Read(inbytes, 0, inbytes->Length);
         fs->Close();
         delete fs;
         return inbytes;
		} catch(...) {
         return gcnew array<System::Byte>(0);
		}
	}
	String^ Helper::FileToString(String^ Filename, System::Text::Encoding^ Encoding) {
		if isNULL(Encoding) Encoding = System::Text::Encoding::Default;
		return Encoding->GetString(FileToData(Filename));
	}

	bool Helper::DataToFile(String^ Filename, array<System::Byte>^ Data) {
		try {
			IO::FileStream^ fs = gcnew IO::FileStream(Filename, IO::FileMode::Create, IO::FileAccess::Write);
         fs->Write(Data, 0, Data->Length);
         fs->Close();
         delete fs;
         return true;
		} catch(...) {
         return false;
		}
	}
	bool Helper::StringToFile(String^ Filename, String^ Data, System::Text::Encoding^ Encoding) {
		if isNULL(Encoding) Encoding = System::Text::Encoding::Default;
		return DataToFile(Filename, Encoding->GetBytes(Data));
	}

	array<String^>^ Helper::StringToLines(String^ Input) {
		if (isNULL(Input) || (Input->Length == 0)) return gcnew array<String^>(0);
		return Input->Replace(vbCr,String::Empty)->Split(gcnew array<String^>(1){vbLf}, StringSplitOptions::RemoveEmptyEntries);
	}

	array<String^>^ Helper::GetResourceNames(System::Type^ SameNamespaceAs) {
      return SameNamespaceAs->Assembly->GetManifestResourceNames();
	}

	System::IO::Stream^ Helper::GetResourceStream(String^ ResourceName, System::Type^ SameNamespaceAs) {
         //Return CurrentAssembly.GetManifestResourceStream(SameNamespaceAs, Name) // DOES NOT WORK!!!
		String^ dotted = "." + ResourceName;
      array<String^>^ items = GetResourceNames(SameNamespaceAs);
		for (int i = 0; i < items->Length; i++) {
			if ( (items[i]->Equals(ResourceName, StringComparison::InvariantCultureIgnoreCase)) || (items[i]->EndsWith(dotted, StringComparison::InvariantCultureIgnoreCase)) ) {
				return SameNamespaceAs->Assembly->GetManifestResourceStream(items[i]);
			}
		}
		if (VERBOSE) NetHook::Log("Resource '" + ResourceName + "' not found in Namespace '" + SameNamespaceAs->FullName + "'!");
      return nullptr;
	}

	array<Byte>^ Helper::GetResourceData(String^ ResourceName, System::Type^ SameNamespaceAs) {
		System::IO::Stream^ s = GetResourceStream(ResourceName, SameNamespaceAs);
      if ( isNULL(s) || (s->Length == 0) ) return gcnew array<Byte>(0);
      array<Byte>^ Data = gcnew array<Byte>((int)s->Length);
      s->Read(Data, 0, (int)s->Length);
      return Data;
	}

	String^ Helper::GetResourceString(String^ ResourceName, System::Type^ SameNamespaceAs, System::Text::Encoding^ optEncoding) {
		if isNULL(optEncoding) optEncoding = System::Text::Encoding::ASCII;
      return optEncoding->GetString(GetResourceData(ResourceName, SameNamespaceAs));
	}

	String^ Helper::CleanPhoneNumber(String^ PhoneNumber) {
		return PhoneNumber->ToUpper()
		->Replace(" ",String::Empty)->Replace("-",String::Empty)->Replace("+","0")
		->Replace("A","2")->Replace("B","2")->Replace("C","2")
		->Replace("D","3")->Replace("E","3")->Replace("F","3")
		->Replace("G","4")->Replace("H","4")->Replace("I","4")
		->Replace("J","5")->Replace("K","5")->Replace("L","5")
		->Replace("M","6")->Replace("N","6")->Replace("O","6")
		->Replace("P","7")->Replace("Q","7")->Replace("R","7")->Replace("S","7")
		->Replace("T","8")->Replace("U","8")->Replace("V","8")
		->Replace("W","9")->Replace("X","9")->Replace("Y","9")->Replace("Z","9");
	}
	WinForms::Keys Helper::RemoveRedundantKeyModifiers(WinForms::Keys key) {
		switch (key & WinForms::Keys::KeyCode) {
			case WinForms::Keys::ShiftKey:
			case WinForms::Keys::LShiftKey:
			case WinForms::Keys::RShiftKey:
				return key & ~WinForms::Keys::Shift;
			case WinForms::Keys::ControlKey:
			case WinForms::Keys::LControlKey:
			case WinForms::Keys::RControlKey:
				return key & ~WinForms::Keys::Control;
			case WinForms::Keys::Menu:
			case WinForms::Keys::LMenu:
			case WinForms::Keys::RMenu:
				return key & ~WinForms::Keys::Alt;
		}
		return key;
	}



	String^ Helper::ToHex(int Input, int Digits) {
		return Input.ToString("X"+Digits.ToString());
	}
	String^ Helper::ToHex(int Input) {
		return ToHex(Input,8);
	}
	String^ Helper::ToShortestHex(int Input) {
		if (Input < 0) return ToHex(Input,8);
		if (Input < 256) return ToHex(Input,2);
		if (Input < 65536) return ToHex(Input,4);
		if (Input < 16777216) return ToHex(Input,6);
		return ToHex(Input,8);
	}
	int Helper::HexToInteger(String^ hex) {
		return Convert::ToInt32(hex, 16);
	}

	float Helper::RadianToDegree(float radians) {
		return radians * float(180.0 / System::Math::PI);
	}
	float Helper::RadianToDegree(double radians) {
		return float(radians * (180.0 / System::Math::PI));
	}
	float Helper::DegreeToRadian(float degrees) {
		return degrees * float(System::Math::PI / 180.0);
	}

	GTA::Vector3 Helper::HeadingToDirection(float Heading) {
		Heading = DegreeToRadian(Heading);
		GTA::Vector3 res;
		res.X = (float)-Math::Sin(Heading);
		res.Y = (float)Math::Cos(Heading);
		res.Z = 0.0f;
		return res;
	}
	float Helper::DirectionToHeading(GTA::Vector3 dir) {
		dir.Z = 0.0f;
		dir.Normalize();
		return RadianToDegree(-System::Math::Atan2(dir.X, dir.Y));
	}
		
	GTA::Vector3 Helper::RotationToDirection(GTA::Vector3 Rotation) {
		float rotZ = DegreeToRadian(Rotation.Z);
		float rotX = DegreeToRadian(Rotation.X);
		float multXY = System::Math::Abs((float)Math::Cos(rotX));
		GTA::Vector3 res;
		res.X = float(-Math::Sin(rotZ)) * multXY;
		res.Y = float(Math::Cos(rotZ)) * multXY;
		res.Z = float(Math::Sin(rotX));
		return res;
	}
	GTA::Vector3 Helper::DirectionToRotation(GTA::Vector3 dir, float roll) {
		dir = Vector3::Normalize(dir);

      GTA::Vector3 rotval;
      //Z Rotation errechnen aus dem Floor-Vector der Direction. (Normal sind X und Z)
      rotval.Z = -RadianToDegree(System::Math::Atan2(dir.X, dir.Y));
      //X Rotation errechnen aus dem Winkel zwischen der Länge des Floor-Vectors und der Höhe 
		GTA::Vector3 rotpos = Vector3::Normalize( Vector3(dir.Z, Vector3(dir.X, dir.Y, 0.0f).Length() , 0.0f) );

      rotval.X = RadianToDegree(System::Math::Atan2(rotpos.X, rotpos.Y));

      rotval.Y = roll; //Roll
      return rotval;
	}

	float Helper::Vector2Length(float X, float Y) {
		return (float)System::Math::Sqrt( (X*X) + (Y*Y) ) ;
	}

	void Helper::EnforceCultureUS() {
		System::Threading::Thread::CurrentThread->CurrentCulture = gcnew System::Globalization::CultureInfo("en-US");
		System::Threading::Thread::CurrentThread->CurrentUICulture = gcnew System::Globalization::CultureInfo("en-US");
	}

	GTA::WeaponSlot Helper::GetSlotUsedByWeapon(GTA::Weapon Weapon) {
		if (Weapon <= GTA::Weapon::Unarmed) return GTA::WeaponSlot::Unarmed;
		i32 slot = 0;
		Scripting::GetWeaponTypeSlot((i32)Weapon,&slot);
		return (GTA::WeaponSlot)slot;
	}

}