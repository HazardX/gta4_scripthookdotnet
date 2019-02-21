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

#include "vPedAnimation.h"

#include "AnimationSet.h"
#include "Game.h"
#include "Ped.h"
#include "vTasks.h"

#pragma managed

namespace GTA {
namespace value {

	PedAnimation::PedAnimation(Ped^ ped) {
		this->ped = ped;
	}

	bool PedAnimation::isPlaying(GTA::AnimationSet^ AnimationSet, String^ AnimationName) {
		if isNULL(AnimationSet) return false;
		return AnimationSet->isPedPlayingAnimation(ped,AnimationName);
	}
	float PedAnimation::GetCurrentAnimationTime(GTA::AnimationSet^ AnimationSet, String^ AnimationName) {
		if isNULL(AnimationSet) return 0.0f;
		return AnimationSet->GetPedsCurrentAnimationTime(ped,AnimationName);
	}
	void PedAnimation::WaitUntilFinished(GTA::AnimationSet^ AnimationSet, String^ AnimationName) {
		if isNULL(AnimationSet) return;
		while (AnimationSet->isPedPlayingAnimation(ped,AnimationName)) {
			GTA::Game::WaitInCurrentScript(0);
		}
	}

	void PedAnimation::Play(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed, AnimationFlags Flags) {
		ped->Task->PlayAnimation(AnimationSet, AnimationName, Speed, Flags);
	}
	void PedAnimation::Play(GTA::AnimationSet^ AnimationSet, String^ AnimationName, float Speed) {
		ped->Task->PlayAnimation(AnimationSet, AnimationName, Speed);
	}

}
}