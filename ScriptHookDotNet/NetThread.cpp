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

#include "NetThread.h"

//#define USE_SIGNALANDWAIT true

namespace GTA {

	NetThread::NetThread() {
		bRunning = 0;
		bInLoop = 0;
		WaitUntil = DateTime::MinValue;
		runFlag = gcnew System::Threading::AutoResetEvent(false);
		stopFlag = gcnew System::Threading::ManualResetEvent(true);
		bThreadActive = false;
	}

	bool NetThread::CanWaitNow::get() {
		return bThreadActive;
	}

	void NetThread::Launch() {
#ifdef USE_THREADPOOL
		if (System::Threading::ThreadPool::QueueUserWorkItem(gcnew System::Threading::WaitCallback(this,&NetThread::MainLoop))) {
			//if (VERBOSE) NetHook::Log("Queued NetThread!");
		} else {
			NetHook::Log("Unable to queue NetThread!");
		}
#else
		tThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &NetThread::MainLoop)); //this,&NetThread::MainLoop
		tThread->Start();
#endif
	}

#ifdef USE_THREADPOOL
	void NetThread::MainLoop(System::Object^ state) {
#else
	void NetThread::MainLoop() {
#endif
		ThreadBegins();
		ThreadWaitForContinue();
		OnStartup();
		while (bRunning) {
			ThreadWaitForContinue();
			OnTick();
		}
		OnEnd();
		ThreadEnds();
	}

	void NetThread::Wait(int ms) {
		bThreadActive = false;
		OnThreadHalt();

		if (ms <=0)
			WaitUntil = DateTime::MinValue;
		else
			WaitUntil = DateTime::Now + TimeSpan(0,0,0,0,ms);

		do {
#ifdef USE_SIGNALANDWAIT
			System::Threading::WaitHandle::SignalAndWait(stopFlag, runFlag);
#else
			stopFlag->Set();
			runFlag->WaitOne();
#endif
			if (!bRunning) Threading::Thread::CurrentThread->Abort(); //throw gcnew Exception("AbortThread");
		} while (DateTime::Now < WaitUntil);

		bThreadActive = true;
		OnThreadContinue();
	}

	void NetThread::WaitForCommandResult() {
		bJustWaitingForCommand = true;
		bThreadActive = false;
#ifdef USE_SIGNALANDWAIT
		System::Threading::WaitHandle::SignalAndWait(stopFlag, runFlag);
#else
		stopFlag->Set();
		runFlag->WaitOne();
#endif
		bThreadActive = true;
	}

	void NetThread::TickNow(bool WaitForEnd) {
		//NetHook::Log("NetThread.TickNow: started");
		//	return;
		//}
		if (bInLoop != 1) {
			//NetHook::Log("NetThread.TickNow: Thread not in loop!");
			return;
		}
		if (bThreadActive) return;

		//NetHook::Log("NetThread.TickNow: before stopFlag->Reset");
		stopFlag->Reset();
		//NetHook::Log("NetThread.TickNow: after stopFlag->Reset");
		//runFlag->Set();
		if (WaitForEnd) {
			//WaitForEndOfTick(); //stopFlag->WaitOne();
#ifdef USE_SIGNALANDWAIT
			NetHook::Log("ATTENTION!");
			try {
			System::Threading::WaitHandle::SignalAndWait(runFlag, stopFlag);
			} catchErrors("ERROR on NetThread.TickNow",throw gcnew Exception("CRAP!"); )
				NetHook::Log("HUH?!");
#else
			runFlag->Set();
			stopFlag->WaitOne();
#endif
		} else {
			runFlag->Set();
		}
	}

	bool NetThread::TickNowWithState() {
		//NetHook::Log("NetThread.TickNowWithState: started");
		bJustWaitingForCommand = false;
		TickNow(true);
		return bJustWaitingForCommand;
	}

	//void NetThread::WaitForEndOfTick() {
	//	stopFlag->WaitOne();
	//}

	void NetThread::Abort() {
		bRunning = 0;

		ThreadEnds();
		if isNotNULL(tThread) {
			//try {
				if (tThread->IsAlive) {
					tThread->Abort();
					OnEnd();
				}
			//} catch (System::Threading::ThreadAbortException^ ex) {
			//	throw ex;
			//} catchErrors("Error in Thread.Abort",)
			tThread = nullptr;
		}
	}

	void NetThread::ThreadBegins() {
		bRunning = 1;
		bInLoop = 1;
		bThreadActive = false;
		Helper::EnforceCultureUS();
	}

	void NetThread::ThreadWaitForContinue() { // Wait() is NOT using this function!!!
		if (bThreadActive) {
			bThreadActive = false;
			OnThreadHalt();
		}
#ifdef USE_SIGNALANDWAIT
		System::Threading::WaitHandle::SignalAndWait(stopFlag, runFlag);
#else
		stopFlag->Set();
		runFlag->WaitOne();
#endif
		//if (bInLoop) {
			bThreadActive = true;
			OnThreadContinue();
		//}
	}

	void NetThread::ThreadEnds() {
		if (bThreadActive) {
			bThreadActive = false;
			OnThreadHalt();
		}
		bInLoop = 0;
		stopFlag->Set();
	}
}