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

//#include "NmCommands.h"

#include "NmCommands.h"
#include "vEuphoria.h"

#include "Vehicle.h"
#include "Ped.h"

#pragma managed

namespace GTA {
namespace value {

	Euphoria::Euphoria(Ped^ ped) {
		this->ped = ped;
	}

	//bool Euphoria::GrabLine(GTA::base::HandleObject^ ItemToGrab, Vector3 Offset1, Vector3 Offset2) {
	//	GTA::Euphoria::GrabHelper^ h = GetHelper<GTA::Euphoria::GrabHelper>(GTA::Euphoria::nmMessageID::nm161_grab);
	//	h->GrabMethod = GTA::Euphoria::GrabMethod::Line;
	//	h->Offset1 = Offset1;
	//	h->Offset2 = Offset2;
	//	return h;
	//}

	//GTA::Euphoria::GrabHelper Euphoria::GrabHelper::get() {
	//	return GetHelper<GTA::Euphoria::GrabHelper>(GTA::Euphoria::nmMessageID::nm161_grab);
	//}

	generic <typename HelperType> where HelperType: GTA::Euphoria::BaseHelper
	HelperType Euphoria::GetHelper(GTA::Euphoria::nmMessageID MessageID) {
		GTA::Euphoria::BaseHelper^ h;
		if isNULL(pHelperCache) {
			pHelperCache = gcnew Dictionary<GTA::Euphoria::nmMessageID,GTA::Euphoria::BaseHelper^>();
		} else {
			if (pHelperCache->TryGetValue(MessageID, h)) return (HelperType)h;
		}
		h = (GTA::Euphoria::BaseHelper^)Activator::CreateInstance(HelperType::typeid, ped);
		pHelperCache->Add(MessageID, h);
		return (HelperType)h;
	}

	/*
	void Euphoria::GrabVehicle(Vehicle^ v, int duration) {
		OBJECT_NON_EXISTING_CHECK(ped);
		OBJECT_NON_EXISTING_CHECK(v);

		BodyBalance->Start(duration);

		LeanToPosition->Position = v->Position;
		LeanToPosition->Amount = 1.5F;
		LeanToPosition->ApplyAsForce = true;
		LeanToPosition->Start();

		Vector3 min, max;
		v->Model.GetDimensions(min, max);

		float CarRoof = max.Z - 0.1F; //car.HeightOffset * 1.35F
		float CarRoofFront = CarRoof * 0.25F; //0.75F
		float CarFront = max.Y - 0.1F; //2.0F
		float CarBack = min.Y + 0.1F; //-2.0F
		float CarSide = max.X - 0.1F; //0.9F
		float CarSideRoof = CarSide * 0.9F; //0.9F
		float CarBottom = 0.4F + min.Z; //0.0F
		float GrabHeight = System::Math::Min(0.9F + min.Z, (max.Z - min.Z) * 0.5F - min.Z); //0.3F //0.9 above floor or half of total vehicle height

		if (v->Model.isBike) {
			CarRoofFront = 0.5F;
			GrabHeight = 0.28F;
		} else if (v->Model.isHelicopter) {
			CarRoofFront = 3.0F;
			CarRoof = 1.3F;
			CarFront = 4.0F;
			CarBack = -3.0F;
			CarSide = 1.15F;
			CarBottom = -1.0F;
			GrabHeight = -0.1F;
		} else if (v->Model.isTrain) {
			CarRoofFront = CarFront;
			CarBottom = -1.0F;
			GrabHeight = 0.5F;
		}

		Grab->ItemToGrab = v;
		Vector3 vo = v->GetOffset(ped->Position);
		if (vo.Z > 0.75f) { //Top
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Surface;
			Grab->Offset1 = Vector3(-CarSideRoof, CarRoofFront, CarRoof);
			Grab->Offset2 = Vector3(-CarSideRoof, CarBack, CarRoof);
			Grab->Offset3 = Vector3(CarSideRoof, CarBack, CarRoof);
			Grab->Offset4 = Vector3(CarSideRoof, CarRoofFront, CarRoof);

		} else if (vo.Y > 1.5f) { // Front
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Line;
			Grab->Offset1 = Vector3(-CarSide, CarFront, GrabHeight);
			Grab->Offset2 = Vector3(CarSide, CarFront, GrabHeight);

		} else if (vo.Y < -1.5f) { // Back
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Line;
			Grab->Offset1 = Vector3(-CarSide, CarBack, GrabHeight);
			Grab->Offset2 = Vector3(CarSide, CarBack, GrabHeight);

		} else if (vo.X > 0.5f) { // Right
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Line;
			Grab->Offset1 = Vector3(CarSide, CarFront, GrabHeight);
			Grab->Offset2 = Vector3(CarSide, CarBack, GrabHeight);

		} else if (vo.X < -0.5f) { // Left
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Line;
			Grab->Offset1 = Vector3(-CarSide, CarFront, GrabHeight);
			Grab->Offset2 = Vector3(-CarSide, CarBack, GrabHeight);

		} else { // Unknown // Bottom?
			Grab->GrabMethod = GTA::Euphoria::GrabMethod::Surface;
			Grab->Offset1 = Vector3(-CarSide, CarFront, CarBottom);
			Grab->Offset2 = Vector3(-CarSide, CarBack, CarBottom);
			Grab->Offset3 = Vector3(CarSide, CarBack, CarBottom);
			Grab->Offset4 = Vector3(CarSide, CarFront, CarBottom);
		}
		Grab->UseLeftHand = true;
		Grab->UseRightHand = true;
		Grab->DontLetGo = true;
		Grab->GrabDistance = 5.0F;
		Grab->GrabStrength = -999999.0F; //-999999.0F //-1.0F //9999.0F
		Grab->MaxDuration = duration;
		Grab->Start();
	}
	*/

}
}