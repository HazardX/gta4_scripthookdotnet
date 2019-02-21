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

#include "stdafx.h"
//#include "nFunction.h"
#include "nTemplate.h"

#pragma managed

namespace GTA {
namespace Native{

	Template::Template(String^ Name, ... array<Parameter^>^ Arguments) {
		pName = Name;
		pReturnType = nullptr;
		pArguments = Arguments;
		bInvoked = false;
	}
	Template::Template(String^ Name, System::Type^ ReturnType, ... array<Parameter^>^ Arguments) {
		pName = Name;
		pReturnType = ReturnType;
		pArguments = Arguments;
		bInvoked = false;
	}

	System::Object^ Template::Invoke() {
		if isNULL(pReturnType) {
			Function::Call(pName,pArguments);
			pReturnValue = nullptr;
		} else {
			pReturnValue = Function::Call(pName,pReturnType,pArguments);
		}
		bInvoked = true;
		//if isNotNULL(wInvoked) wInvoked->Set();
		return pReturnValue;
	}

	//void Template::WaitForInvoke() {
	//	if isNULL(wInvoked) wInvoked = gcnew System::Threading::ManualResetEvent(false);
	//	wInvoked->WaitOne();
	//}

}
}