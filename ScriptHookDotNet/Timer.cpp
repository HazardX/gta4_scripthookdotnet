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

#include "Timer.h"

#include "Game.h"
#include "Script.h"

#pragma managed

namespace GTA {

	void Timer::InitValues() {
		pStartTime = CurrentTime;
		pInterval = -1;
		pLastTick = 0;
		pStoppedElapsedTime = 0;
		bRunning = false;
		bHandled = false;
	}

	Timer::Timer() {
		InitValues();
	}
	Timer::Timer(int Interval) {
		InitValues();
		pInterval = Interval;
	}
	Timer::Timer(int Interval, bool StartNow) {
		InitValues();
		pInterval = Interval;
		if (StartNow) Start();
	}

	int Timer::ElapsedTime::get() {
		if (bRunning)
			return (CurrentTime-pStartTime);
		else
			return pStoppedElapsedTime;
	}

	void Timer::CheckHandler() {
		bool newHandled = (bRunning && (pInterval >= 0));
		if (newHandled == bHandled) return;
		bHandled = newHandled;
		if (newHandled)
			Parent->EachTick += gcnew EventHandler(this, &Timer::EachTick);
		else
			Parent->EachTick -= gcnew EventHandler(this, &Timer::EachTick);
	}

	void Timer::Interval::set(int value) {
		pInterval = value;
		CheckHandler();
	}

	void Timer::EachTick(Object^ sender, EventArgs^ e) {
		int t = CurrentTime;
		if (pLastTick + pInterval < t) {
			pLastTick = t;
			Tick(this,e);
		}
	}

	void Timer::Start() {
		pStartTime = CurrentTime;
		pLastTick = pStartTime;
		bRunning = true;
		CheckHandler();
	}

	void Timer::Stop() {
		if (!bRunning) return;
		bRunning = false;
		pStoppedElapsedTime = (CurrentTime-pStartTime);
		CheckHandler();
	}

	int Timer::CurrentTime::get() {
		//u32 g;
		//Scripting::GetGameTimer(&g);
		//return g;
		return Game::GameTime;
	}

}