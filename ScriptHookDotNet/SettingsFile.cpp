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

#include "SettingsFile.h"

#include "ContentCache.h"

#pragma managed

namespace GTA {
//namespace value {

	SettingsFile::SettingsFile(String^ Filename) {
		pFilename = Filename;
		categories = gcnew Collections::Generic::Dictionary<String^,SettingCategory^>();
		bChanged = false;
	}
	SettingsFile^ SettingsFile::Open(String^ Filename) {
		return ContentCache::GetINI(Filename);
	}
	SettingsFile::!SettingsFile() {
		if (bChanged) Save();
	}

	//String^ SettingsFile::Filename::get() {
	//	return IO::Path::ChangeExtension(script->Filename,"ini");
	//}

	SettingCategory^ SettingsFile::GetCategory(String^ Name) {
		String^ id = Name->ToLower();
		if (categories->ContainsKey(id)) {
			return categories[id];
		} else {
			SettingCategory^ cat = gcnew SettingCategory(Name);
			categories[id] = cat;
			return cat;
		}
	}

	void SettingsFile::Clear() {
		categories->Clear();
		bChanged = true;
		bAddNextLine = false;
	}

	void SettingsFile::Load() {
		Clear();
		array<String^>^ Lines = Helper::StringToLines(Helper::FileToString(Filename, System::Text::Encoding::ASCII));
		//if (Lines->Length == 0) NetHook::Log("No settings in file '"+Filename+"'!");
		CurrentCategory = String::Empty;
		for (int i = 0; i < Lines->Length; i++) {
			if (!bAddNextLine)
				ParseLine(Lines[i]);
			else
				ParseAddLine(Lines[i]);
		}
		bChanged = false;
	}
	void SettingsFile::ParseLine(String^ DataLine) {
		try {
         DataLine = DataLine->Trim();
         if (DataLine->StartsWith("/") || DataLine->StartsWith("'") || DataLine->StartsWith("#")) return;
			if (DataLine->StartsWith("[")) {
				int sPos = DataLine->IndexOf("]");
				if (sPos<=1) return;
				CurrentCategory = DataLine->Substring(1,sPos-1);
				return;
			}
			int eq = DataLine->IndexOf("=");
			if (eq <= 0) return;
			String^ name = DataLine->Substring(0, eq)->Trim();
			String^ val;
			if (eq < DataLine->Length-1) {
				val = DataLine->Substring(eq+1)->Trim();
				if (val->EndsWith("\\n\\")) {
					pLastValueName = name;
					bAddNextLine = true;
					if (val->Length > 3)
						val = val->Substring(0,val->Length-3);
					else
						val = String::Empty;
				}
				val = val->Replace("\\n",Environment::NewLine);
				val = val->Replace("#\\#n#","\\n");
			} else {
				val = String::Empty;
			}
			//values->Add(name->ToLower(), val);
			GetCategory(CurrentCategory)->SetValue(name, val);
			//NetHook::Log("Found setting '"+name+"' with value '"+val+"'!");
		} catchErrors("Error in setting file '"+Filename+"'",)//catch(...) {}
	}
	void SettingsFile::ParseAddLine(String^ DataLine) {
		bAddNextLine = false;
		try {
         DataLine = DataLine->Trim();

			if (DataLine->Length > 0) {
				if (DataLine->EndsWith("\\n\\")) {
					//pLastValueName = name;
					bAddNextLine = true;
					if (DataLine->Length > 3)
						DataLine = DataLine->Substring(0,DataLine->Length-3);
					else
						DataLine = String::Empty;
				}
				DataLine = DataLine->Replace("\\n",Environment::NewLine);
				DataLine = DataLine->Replace("#\\#n#","\\n");
			} else {
				DataLine = String::Empty;
			}
			SetValue(CurrentCategory, pLastValueName, GetValueString(pLastValueName, CurrentCategory, String::Empty) + Environment::NewLine + DataLine);
		} catchErrors("Error in setting file '"+Filename+"'",)//catch(...) {}
	}

	bool SettingsFile::Save() {
		if (!bChanged) return true;
		if (SaveCopyTo(Filename)) {
			bChanged = false;
			return true;
		} else {
			return false;
		}
	}
	bool SettingsFile::SaveCopyTo(String^ Filename) {
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		array<String^>^ cats = GetCategoryNames();
		for (int i = 0; i < cats->Length; i++) {
			SaveCategory(sb, cats[i]);
		}
		return Helper::StringToFile(Filename, sb->ToString(), System::Text::Encoding::ASCII);
	}
	void SettingsFile::SaveCategory(System::Text::StringBuilder^ sb, String^ CategoryName) {
		array<String^>^ vals = GetValueNames(CategoryName);
		if (vals->Length == 0) return;
		String^ val;
		sb->AppendLine();
		if (CategoryName->Length > 0) sb->AppendLine("[" + CategoryName + "]");
		for (int i = 0; i < vals->Length; i++) {
			val = GetValueString(vals[i], CategoryName, String::Empty);
			val = val->Replace("\\n","#\\#n#");
			val = val->Replace("\r",String::Empty);
			val = val->Replace("\n","\\n");
			sb->AppendLine(vals[i] + "=" + val);
		}
	}

	array<String^>^ SettingsFile::GetCategoryNames() {
		List<String^>^ list = gcnew List<String^>();
		//list->Add(String::Empty);
		for each (KeyValuePair<String^,SettingCategory^> kvp in categories) {
			if (kvp.Key->Length > 0) list->Add(kvp.Value->Name);
		}
		list->Sort();
		list->Insert(0, String::Empty);
		return list->ToArray();
	}

	array<String^>^ SettingsFile::GetValueNames(String^ Category) {
		return GetCategory(Category)->GetValueNames();
	}

	String^ SettingsFile::GetValueString(String^ OptionName, String^ Category, String^ DefaultValue) {
		return GetCategory(Category)->GetValue(OptionName,DefaultValue);
	}
	String^ SettingsFile::GetValueString(String^ OptionName, String^ Category) {
		return GetValueString(OptionName, Category, String::Empty);
		//OptionName = OptionName->ToLower();
		//if (!values->ContainsKey(OptionName)) return DefaultValue;
		//return values[OptionName];
	}
	String^ SettingsFile::GetValueString(String^ OptionName) {
		return GetValueString(OptionName, String::Empty, String::Empty);
	}

	int SettingsFile::GetValueInteger(String^ OptionName, String^ Category, int DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		return Helper::StringToInteger(val, DefaultValue);
	}

	float SettingsFile::GetValueFloat(String^ OptionName, String^ Category, float DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		return Helper::StringToFloat(val, DefaultValue);
	}

	bool SettingsFile::GetValueBool(String^ OptionName, String^ Category, bool DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		return Helper::StringToBoolean(val, DefaultValue);
	}

	Vector3 SettingsFile::GetValueVector3(String^ OptionName, String^ Category, Vector3 DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		return Helper::StringToVector3(val, DefaultValue);
	}

	Windows::Forms::Keys SettingsFile::GetValueKey(String^ OptionName, String^ Category, Windows::Forms::Keys DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		//if (val->Length == 0) NetHook::Log("Requested setting '"+OptionName+"' not found!");
		return Helper::StringToKey(val, DefaultValue);
	}

	GTA::Model SettingsFile::GetValueModel(String^ OptionName, String^ Category, GTA::Model DefaultValue) {
		String^ val = GetValueString(OptionName, Category, String::Empty);
		return Helper::StringToModel(val,DefaultValue);
	}

	void SettingsFile::SetValue(String^ OptionName, String^ Category, String^ Value) {
		GetCategory(Category)->SetValue(OptionName, Value);
		bChanged = true;
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, Vector3 Value) {
		SetValue(OptionName, Category, Value.ToString(", ", 4));
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, bool Value) {
		SetValue(OptionName, Category, Value.ToString());
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, float Value) {
		SetValue(OptionName, Category, Helper::FloatToString(Value,4));
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, int Value) {
		SetValue(OptionName, Category, Value.ToString());
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, Windows::Forms::Keys Value) {
		SetValue(OptionName, Category, Value.ToString());
	}
	void SettingsFile::SetValue(String^ OptionName, String^ Category, GTA::Model Value) {
		SetValue(OptionName, Category, Value.ToString());
	}

//}
}