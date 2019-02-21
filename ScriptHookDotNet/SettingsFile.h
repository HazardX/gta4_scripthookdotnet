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
//namespace value {

	ref class SettingValue;
	ref class SettingCategory;

	//namespace value {
	//	[ObsoleteAttribute]
	//	public ref class ScriptSettings {
	//	public:
	//		ScriptSettings() {}
	//	};
	//}

	CLASS_ATTRIBUTES
	public ref class SettingsFile { //: value::ScriptSettings {

	private:
		String^ pFilename;
		Collections::Generic::Dictionary<String^,SettingCategory^>^ categories;
		bool bChanged;
		String^ pLastValueName;
		bool bAddNextLine;
		String^ CurrentCategory;

		void ParseLine(String^ Input);
		void ParseAddLine(String^ Input);
		void SaveCategory(System::Text::StringBuilder^ sb, String^ CategoryName);

		SettingCategory^ GetCategory(String^ Name);

	internal:
		SettingsFile(String^ Filename);

	protected:
		!SettingsFile(); // Finialize

	public:
		static SettingsFile^ Open(String^ Filename);
		~SettingsFile() { // Dispose
			this->!SettingsFile();
		}
		
		/// <summary>
		/// The setting file has the same filename as the script, just with an 'ini' extension.
		/// </summary>
		property String^ Filename {
			String^ get() {
				return pFilename;
			}
		}

		void Clear();

		/// <summary>
		/// Load the settings file again. In is automatically loaded on script startup.
		/// </summary>
		void Load();

		/// <summary>
		/// Get the names of all categories.
		/// </summary>
		array<String^>^ GetCategoryNames();

		/// <summary>
		/// Get the names of all values in this category.
		/// </summary>
		array<String^>^ GetValueNames(String^ Category);
		/// <summary>
		/// Get the names of all values in the default category.
		/// </summary>
		array<String^>^ GetValueNames() { return GetValueNames(String::Empty); }

		/// <summary>
		/// Get the value with the given name from the settings file and convert it to a Vector3.
		/// The 3 float values can be seperated by space or by a comma ',' .
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		Vector3 GetValueVector3(String^ OptionName, String^ Category, Vector3 DefaultValue);
		/// <summary>
		/// Get the value with the given name from the settings file and convert it to a Vector3.
		/// The 3 float values can be seperated by space or by a comma ',' .
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		Vector3 GetValueVector3(String^ OptionName, String^ Category) {
			return GetValueVector3(OptionName, Category, Vector3());
		}
		/// <summary>
		/// Get the value with the given name from the settings file and convert it to a Vector3.
		/// The 3 float values can be seperated by space or by a comma ',' .
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		Vector3 GetValueVector3(String^ OptionName) {
			return GetValueVector3(OptionName, String::Empty, Vector3());
		}

		/// <summary>
		/// Get a boolean value with the given name from the settings file.
		/// INI values that return true: true, yes, on, 1.
		/// INI values that return false: false, no, off, 0.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		bool GetValueBool(String^ OptionName, String^ Category, bool DefaultValue);
		/// <summary>
		/// Get a boolean value with the given name from the settings file.
		/// INI values that return true: true, yes, on, 1.
		/// INI values that return false: false, no, off, 0.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		bool GetValueBool(String^ OptionName, bool DefaultValue) {
			return GetValueBool(OptionName, String::Empty, DefaultValue);
		}

		/// <summary>
		/// Get a float value with the given name from the settings file.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		float GetValueFloat(String^ OptionName, String^ Category, float DefaultValue);
		/// <summary>
		/// Get a float value with the given name from the settings file.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		float GetValueFloat(String^ OptionName, float DefaultValue) {
			return GetValueFloat(OptionName, String::Empty, DefaultValue);
		}

		/// <summary>
		/// Get an integer value with the given name from the settings file.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		int GetValueInteger(String^ OptionName, String^ Category, int DefaultValue);
		/// <summary>
		/// Get an integer value with the given name from the settings file.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		int GetValueInteger(String^ OptionName, int DefaultValue) {
			return GetValueInteger(OptionName, String::Empty, DefaultValue);
		}

		/// <summary>
		/// Get a string value with the given name and category from the settings file.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		String^ GetValueString(String^ OptionName, String^ Category, String^ DefaultValue);
		/// <summary>
		/// Get a string value with the given name from the settings file.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		String^ GetValueString(String^ OptionName, String^ Category);
		/// <summary>
		/// Get a string value with the given name from the settings file.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		String^ GetValueString(String^ OptionName);

		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a key.
		/// The key may be given as the key's name or as keycode.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		Windows::Forms::Keys GetValueKey(String^ OptionName, String^ Category, Windows::Forms::Keys DefaultValue);
		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a key.
		/// The key may be given as the key's name or as keycode.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		Windows::Forms::Keys GetValueKey(String^ OptionName, Windows::Forms::Keys DefaultValue) {
			return GetValueKey(OptionName, String::Empty, DefaultValue);
		}

		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a model.
		/// The model may be given as modelname, integer or hex value.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		GTA::Model GetValueModel(String^ OptionName, String^ Category, GTA::Model DefaultValue);
		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a model.
		/// The model may be given as modelname, integer or hex value.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		/// <param name="DefaultValue">Is returned when the value is not found or invalid.</param>
		GTA::Model GetValueModel(String^ OptionName, GTA::Model DefaultValue) {
			return GetValueModel(OptionName, String::Empty, DefaultValue);
		}
		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a model.
		/// The model may be given as modelname, integer or hex value.
		/// </summary>
		/// <param name="Category">The category of the value to look for. (without the []-brackets)</param>
		/// <param name="OptionName">The name of the value to look for.</param>
		GTA::Model GetValueModel(String^ OptionName, String^ Category) {
			return GetValueModel(OptionName, Category, GTA::Model(0));
		}
		/// <summary>
		/// Get a value with the given name from the settings file and convert is to a model.
		/// The model may be given as modelname, integer or hex value.
		/// </summary>
		/// <param name="OptionName">The name of the value to look for.</param>
		GTA::Model GetValueModel(String^ OptionName) {
			return GetValueModel(OptionName, String::Empty, GTA::Model(0));
		}

		bool Save();
		bool SaveCopyTo(String^ Filename);

		void SetValue(String^ OptionName, String^ Category, Vector3 Value);
		void SetValue(String^ OptionName, String^ Category, bool Value);
		void SetValue(String^ OptionName, String^ Category, float Value);
		void SetValue(String^ OptionName, String^ Category, int Value);
		void SetValue(String^ OptionName, String^ Category, String^ Value);
		void SetValue(String^ OptionName, String^ Category, Windows::Forms::Keys Value);
		void SetValue(String^ OptionName, String^ Category, GTA::Model);

		void SetValue(String^ OptionName, Vector3 Value)				{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, bool Value)					{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, float Value)					{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, int Value)					{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, String^ Value)				{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, Windows::Forms::Keys Value)	{ SetValue(OptionName, String::Empty, Value); }
		void SetValue(String^ OptionName, GTA::Model Value)				{ SetValue(OptionName, String::Empty, Value); }

	};

	CLASS_ATTRIBUTES
	private ref class SettingValue {
	public:
		String^ Name;
		String^ Value;
		SettingValue(String^ name, String^ value) {
			this->Name = name;
			this->Value = value;
		}
	};

	CLASS_ATTRIBUTES
	private ref class SettingCategory {
		public:
		String^ Name;
		Collections::Generic::Dictionary<String^,SettingValue^>^ values;
		SettingCategory(String^ name) {
			this->Name = name;
			values = gcnew Collections::Generic::Dictionary<String^,SettingValue^>();
		}
		String^ GetValue(String^ Name, String^ DefaultValue) {
			if (isNULL(Name) || (Name->Length == 0)) return DefaultValue;
			String^ id = Name->ToLower();
			if (!values->ContainsKey(id)) return DefaultValue;
			return values[id]->Value;
		}
		void SetValue(String^ Name, String^ Value) {
			if (isNULL(Name) || (Name->Length == 0)) return;
			String^ id = Name->ToLower();
			if (values->ContainsKey(id))
				values[id]->Value = Value;
			else
				values[id] = gcnew SettingValue(Name, Value);
		}
		array<String^>^ GetValueNames() {
			List<String^>^ list = gcnew List<String^>();
			for each (KeyValuePair<String^,SettingValue^> kvp in values) {
				list->Add(kvp.Value->Name);
			}
			//list->Sort();
			return list->ToArray();
		}
	};

//}
}