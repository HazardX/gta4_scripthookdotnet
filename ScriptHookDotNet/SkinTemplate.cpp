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

#include "SkinTemplate.h"

#include "Ped.h"
#include "Player.h"
#include "vPedSkin.h"

#pragma managed

namespace GTA{

	SkinTemplate::SkinTemplate() {
		Initialize();
	}
	SkinTemplate::SkinTemplate(value::PedSkin^ skin) {
		Initialize();
		FromPedSkin(skin);
	}

	void SkinTemplate::Initialize() {
		pModel = GTA::Model::Null;
		PropIndices = gcnew array<int>(PROP_COUNT);
		ComponentModel = gcnew array<int>(COMPONENT_COUNT);
		ComponentTexture = gcnew array<int>(COMPONENT_COUNT);
	}

	GTA::Model SkinTemplate::Model::get(){
		return pModel;
	}
	void SkinTemplate::Model::set(GTA::Model value){
		pModel = value;
	}

	void SkinTemplate::FromPedSkin(value::PedSkin^ sk) {
		if isNULL(sk) return;
		OBJECT_NON_EXISTING_CHECK(sk->ped);
		int i;
		pModel = sk->Model;
		for (i=0; i<PROP_COUNT; i++) {
			PropIndices[i] = sk->GetPropIndex((PedProp)i); //Scripting::GetCharPropIndex2(ped->Handle, i, &value);
		}
		for (i=0; i<COMPONENT_COUNT; i++) {
			//ComponentModel[i] = sk->GetComponentModel((PedComponent)i);
			//ComponentTexture[i] = sk->GetComponentTexture((PedComponent)i);
			//ComponentModel[i] = sk->Component((PedComponent)i)->ModelIndex;
			//ComponentTexture[i] = sk->Component((PedComponent)i)->TextureIndex;
			ComponentModel[i] = Scripting::GetCharDrawableVariation(sk->ped->Handle, (Scripting::ePedComponent)i);
			ComponentTexture[i] = Scripting::GetCharTextureVariation(sk->ped->Handle, (Scripting::ePedComponent)i);
		}
	}

	void SkinTemplate::ApplyToPed(Ped^ ped) {
		if isNULL(ped) return;
		OBJECT_NON_EXISTING_CHECK(ped);
		value::PedSkin^ sk = ped->Skin;
		int i;
		//ped->Model = pModel;
		for (i=0; i<PROP_COUNT; i++) {
			sk->SetPropIndex((PedProp)i, PropIndices[i]);
		}
		for (i=0; i<COMPONENT_COUNT; i++) {
			//sk->SetComponent((PedComponent)i, ComponentModel[i], ComponentTexture[i]);
			//sk->Component((PedComponent)i)->Change(ComponentModel[i], ComponentTexture[i]);
			Scripting::SetCharComponentVariation(ped->Handle, (Scripting::ePedComponent)i, (u32)ComponentModel[i], (u32)ComponentTexture[i]);
		}
		//ped->SetDefaultVoice();
	}

	void SkinTemplate::ApplyToPlayer(Player^ player) {
		player->Model = pModel;
		ApplyToPed(player->Character);
	}

	String^ SkinTemplate::ToString() {
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		sb->Append(pModel.ToString());
		sb->Append(";");
		for (int i = 0; i < PROP_COUNT; i++) {
			if (i > 0) sb->Append("_");
			sb->Append(Helper::ToShortestHex(PropIndices[i]));
		}
		sb->Append(";");
		for (int i = 0; i < COMPONENT_COUNT; i++) {
			if (i > 0) sb->Append("_");
			sb->Append(Helper::ToShortestHex(ComponentModel[i]));
		}
		sb->Append(";");
		for (int i = 0; i < COMPONENT_COUNT; i++) {
			if (i > 0) sb->Append("_");
			sb->Append(Helper::ToShortestHex(ComponentTexture[i]));
		}
		return sb->ToString();
	}

	SkinTemplate^ SkinTemplate::FromString(String^ input) {
		array<String^>^ segs = input->Split(';');
		if (segs->Length < 4) return nullptr;
		SkinTemplate^ res = gcnew SkinTemplate();
		res->Model = GTA::Model::FromString(segs[0]);
		
		array<String^>^ vals = segs[1]->Split('_');
		for (int i = 0; i < System::Math::Min(vals->Length,PROP_COUNT); i++) {
			res->PropIndices[i] = Helper::HexToInteger(vals[i]);
		}

		vals = segs[2]->Split('_');
		for (int i = 0; i < System::Math::Min(vals->Length,COMPONENT_COUNT); i++) {
			res->ComponentModel[i] = Helper::HexToInteger(vals[i]);
		}

		vals = segs[3]->Split('_');
		for (int i = 0; i < System::Math::Min(vals->Length,COMPONENT_COUNT); i++) {
			res->ComponentTexture[i] = Helper::HexToInteger(vals[i]);
		}
		return res;
	}

}