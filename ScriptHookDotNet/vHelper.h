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
	using namespace System::Globalization;

	//value class Model;
	//value class Vector3;

	CLASS_ATTRIBUTES
	public ref class Helper sealed {
	private:
		Helper() {}

	internal:
		static String^ vbCr = gcnew String( (unsigned char)13 , 1);
		static String^ vbLf = gcnew String( (unsigned char)10 , 1);
		static System::Globalization::CultureInfo^ CultureIV = System::Globalization::CultureInfo::InvariantCulture;
		static System::Random^ Random = gcnew System::Random();

		static Drawing::Point SubtractPoint(Drawing::Point left, Drawing::Point right) {
			return Drawing::Point(left.X-right.X, left.Y-right.Y);
		}
		static Drawing::PointF SubtractPoint(Drawing::PointF left, Drawing::PointF right) {
			return Drawing::PointF(left.X-right.X, left.Y-right.Y);
		}
		static Drawing::Point AddPoint(Drawing::Point left, Drawing::Point right) {
			return Drawing::Point(left.X+right.X, left.Y+right.Y);
		}
		static Drawing::PointF AddPoint(Drawing::PointF left, Drawing::PointF right) {
			return Drawing::PointF(left.X+right.X, left.Y+right.Y);
		}
		static bool PointInRect(Drawing::Point pt, Drawing::Rectangle rect) {
			if ((pt.X < rect.X) || (pt.Y < rect.Y)) return false;
			if ((pt.X > rect.Right) || (pt.Y > rect.Bottom)) return false;
			return true;
		}
		static bool PointInRect(Drawing::PointF pt, Drawing::RectangleF rect) {
			if ((pt.X < rect.X) || (pt.Y < rect.Y)) return false;
			if ((pt.X > rect.Right) || (pt.Y > rect.Bottom)) return false;
			return true;
		}

		static bool isKeyPressedAsync(System::Windows::Forms::Keys key);

		static array<String^>^ StringToLines(String^ Input);

		static array<String^>^ GetResourceNames(System::Type^ SameNamespaceAs);
		static System::IO::Stream^ GetResourceStream(String^ ResourceName, System::Type^ SameNamespaceAs);
		static array<Byte>^ GetResourceData(String^ ResourceName, System::Type^ SameNamespaceAs);
		static String^ GetResourceString(String^ ResourceName, System::Type^ SameNamespaceAs, System::Text::Encoding^ optEncoding);

		static String^ CleanPhoneNumber(String^ PhoneNumber);
		static System::Windows::Forms::Keys RemoveRedundantKeyModifiers(System::Windows::Forms::Keys key);

		static String^ ToHex(int Input, int Digits);
		static String^ ToHex(int Input);
		static String^ ToShortestHex(int Input);
		static int HexToInteger(String^ hex);

		static float Vector2Length(float X, float Y);

		static void EnforceCultureUS();

	public:

		static GTA::Model StringToModel(String^ Input, GTA::Model DefaultValue);
		static Windows::Forms::Keys StringToKey(String^ Input, Windows::Forms::Keys DefaultValue);
		static Vector3 StringToVector3(String^ Input, Vector3 DefaultValue);
		static float StringToFloat(String^ Input, float DefaultValue);
		static int StringToInteger(String^ Input, int DefaultValue);
		static bool Helper::StringToBoolean(String^ Input, bool DefaultValue);

		static String^ FloatToString(float Input, int Digits);
		static String^ FloatToString(float Input);

		static array<System::Byte>^ FileToData(String^ Filename);
		static String^ FileToString(String^ Filename, System::Text::Encoding^ Encoding);
		static bool DataToFile(String^ Filename, array<System::Byte>^ Data);
		static bool StringToFile(String^ Filename, String^ Data, System::Text::Encoding^ Encoding);

		static float RadianToDegree(float radians);
		static float RadianToDegree(double radians);
		static float DegreeToRadian(float degrees);
		static GTA::Vector3 HeadingToDirection(float Heading);
		static GTA::Vector3 RotationToDirection(GTA::Vector3 Rotation);
		static float DirectionToHeading(GTA::Vector3 dir);
		static GTA::Vector3 DirectionToRotation(GTA::Vector3 dir, float roll);

		static GTA::WeaponSlot GetSlotUsedByWeapon(GTA::Weapon Weapon);

	};

}