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

#include "EventArgs.h"

#include "Graphics.h"

#pragma managed

namespace GTA {

	// MOSUE EVENT ARGS

	Drawing::Point MouseEventArgs::PixelLocation::get() {
		return Drawing::Point((int)Graphics::ConvertUnitsToPixelX(pLocation.X), (int)Graphics::ConvertUnitsToPixelY(pLocation.Y));
	}

	// CONSOLE EVENT ARGS

	ConsoleEventArgs::ConsoleEventArgs(String^ Command, array<String^>^ Parameter) {
		pCommand = Command;
		pParameter = gcnew ParameterCollection(Parameter);
	}

	// SCRIPT COMMAND EVENT ARGS

	ScriptCommandEventArgs::ScriptCommandEventArgs(Script^ sender, String^ Command, array<System::Object^>^ Parameter) {
		pSender = sender;
		pCommand = Command;
		pParameters = gcnew ObjectCollection(Parameter);
	}

	// PARAMETER COLLECTION

	ParameterCollection::ParameterCollection(array<String^>^ Parameters) {
		pAddRange(Parameters);
	}

	int ParameterCollection::ToInteger(int index) {
		if ((index < 0) || (index >= Count)) return 0;
		return Helper::StringToInteger(this->default[index], 0);
	}
	float ParameterCollection::ToFloat(int index) {
		if ((index < 0) || (index >= Count)) return 0.0f;
		return Helper::StringToFloat(this->default[index], 0.0f);
	}
	Vector3 ParameterCollection::ToVector3(int firstIndex) {
		Vector3 val;
		val.X = ToFloat(firstIndex);
		val.Y = ToFloat(firstIndex+1);
		val.Z = ToFloat(firstIndex+2);
		return val;
	}
	Model ParameterCollection::ToModel(int index) {
		if ((index < 0) || (index >= Count)) return 0;
		return Helper::StringToModel(this->default[index],Model(0));
	}
	String^ ParameterCollection::ToString(int index) {
		if ((index < 0) || (index >= Count)) return String::Empty;
		return this->default[index];
	}

	// OBJECT COLLECTION

	ObjectCollection::ObjectCollection(array<System::Object^>^ Objects) {
		pAddRange(Objects);
	}

	generic <typename T>
	T ObjectCollection::Convert(int index) {
		if ((index < 0) || (index >= Count)) return T(); //nullptr;
		try {
			return static_cast<T>(this->default[index]); //static_cast<T>(this->default[index]);
		} catch(...) {
			return T(); //nullptr;
		}
	}

}