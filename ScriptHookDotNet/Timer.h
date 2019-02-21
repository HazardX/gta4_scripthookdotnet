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

	CLASS_ATTRIBUTES
	public ref class Timer : base::ScriptChild {

	private:
		int pStartTime;
		int pStoppedElapsedTime;
		int pLastTick;
		int pInterval;
		bool bRunning;
		bool bHandled;

		property int CurrentTime {
			int get();
		}

		void EachTick(Object^ sender, EventArgs^ e);
		void CheckHandler();
		void InitValues();

	public:
		Timer(int Interval, bool StartNow);
		Timer(int Interval);
		Timer();

		event EventHandler^ Tick;

		/// <summary>
		/// Time elapsed since the last Start. Does not increase when the Timer is stopped.
		/// </summary>
		property int ElapsedTime {
			int get();
		}

		property bool isRunning {
			bool get() { return bRunning; }
		}

		/// <summary>
		/// The interval (in Milliseconds) at which the Tick event will be fired. The Tick event will not run if Interval is negative.
		/// Any Wait() in your Script will delay the next Tick until after the Wait is finished.
		/// </summary>
		property int Interval {
			int get() {	return pInterval;	}
			void set(int value);
		}

		/// <summary>
		/// Starts the Timer and resets the ElapsedTime back to 0. The Tick event will fire each Interval if Interval is greater than or equal to 0.
		/// </summary>
		void Start();

		/// <summary>
		/// Stops the Timer from firing Tick events and freezes the current value of ElapsedTime.
		/// </summary>
		void Stop();

	protected:
		virtual void OnTick(EventArgs^ e) {
			Tick(this, e);
		}

	};

}