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

namespace GTA{

	[System::SerializableAttribute]
	private value class sEvent {
	public:
		ScriptEvent Event;
		EventArgs^ args;
		DateTime Time;
		sEvent(ScriptEvent Event, EventArgs^ args,DateTime Time) {
			this->Event = Event;
			this->args = args;
			this->Time = Time;
		}
	};

	public ref class Script abstract { //: MarshalByRefObject {

	private:
		RemoteScriptDomain^ domain;
		SettingsFile^ pSettings;
		System::DateTime NextTick;
		List<BoundKeyItem>^ keylist;
		List<BoundScriptCommandItem>^ scriptcommandlist;
		List<BoundPhoneNumberItem>^ phonenumberlist;
		List<sEvent>^ eventlist;
		Dictionary<String^,System::Object^>^ metadata;
		value::Resources^ pResources;
		String^ pFilename;
		String^ pFilenameWithoutExtension;
		bool bRunning;

		int pInterval;
		//float pRequiredVersion;
		bool BlockWait;
		bool bWaiting;

		Guid pGUID;
		String^ pGeneralInfo;

		void TryTick();

		void ProcessBoundKey(System::Windows::Forms::Keys Key);
		void ProcessBoundCommand(ConsoleEventArgs^);
		void ProcessBoundScriptCommand(ScriptCommandEventArgs^ sceva);
		void ProcessBoundPhoneNumber(String^ PhoneNumber);

	protected:

		!Script() {}

	internal:

		event EventHandler^ EachTick;
		event EventHandler^ PerFrameScriptDrawing;

		GTA::Forms::FormHost^ FormHost;
		List<BoundCommandItem>^ commandlist;
		ScriptThread^ myThread;

		void Initialize(ScriptThread^ scriptThread);

		void DoStartup();
      void DoTick();
		void DoPerFrameDrawing(GTA::GraphicsEventArgs^ Graphics);
		void DoPerFrameScriptDrawing();
		void ProcessEvents();

		void AddEvent(ScriptEvent Event, EventArgs^ args, DateTime Time) {
			eventlist->Add( sEvent(Event,args,Time) );
		}

		property bool CanWaitNow {
			bool get();
		}

		System::Object^ GetMetaData(int ItemHandle, String^ ValueName) {
			if isNULL(metadata) return nullptr;
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			if (!metadata->ContainsKey(id)) return nullptr;
			try {
				return metadata[id];
			} catch(...) {
				return nullptr;
			}
		}

		void SetMetaData(int ItemHandle, String^ ValueName, System::Object^ Value) {
			if isNULL(metadata) metadata = gcnew Dictionary<String^,System::Object^>();
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			metadata[id] = Value;
			//LogCount(metadata,1000);
		}

		bool HasMetaData(int ItemHandle, String^ ValueName) {
			if isNULL(metadata) return false;
			String^ id = ItemHandle.ToString() + "#" + ValueName->ToLower();
			return metadata->ContainsKey(id);
		}

#ifdef DEBUG
	public:
#else
	internal:
#endif

		property int RenderID {
			int get();
		}
		
	protected:

		/// <summary>
		/// Access the settings file of the script.
		/// It has the same filename as the script, just with an 'ini' extension.
		/// </summary>
		property GTA::SettingsFile^ Settings {
			GTA::SettingsFile^ get();
		}
		//[ObsoleteAttribute]
		//property GTA::value::ScriptSettings^ Settings {
		//	GTA::value::ScriptSettings^ get() {
		//		return nullptr;
		//	}
		//}

		property GTA::Player^ Player {
			GTA::Player^ get();
		}

		property int Interval {
			int get();
			void set(int value);
		}

		//property float RequiredVersion {
		//	float get();
		//	void set(float value);
		//}

		bool isKeyPressed(System::Windows::Forms::Keys Key);

		bool Exists(System::Object^ Object);
		bool Exists(GTA::base::Object^ GtaObject);


		void BindKey(Windows::Forms::Keys Key, bool Shift, bool Ctrl, bool Alt, KeyPressDelegate^ MethodToBindTo);
		void BindKey(Windows::Forms::Keys Key, KeyPressDelegate^ MethodToBindTo);
		void BindConsoleCommand(String^ Command, ConsoleCommandDelegate^ MethodToBindTo);
		void BindConsoleCommand(String^ Command, ConsoleCommandDelegate^ MethodToBindTo, String^ HelpText);
		void BindScriptCommand(String^ Command, ScriptCommandDelegate^ MethodToBindTo);
		void BindPhoneNumber(String^ PhoneNumber, PhoneDialDelegate^ MethodToBindTo);

		void UnbindKey(Windows::Forms::Keys Key, bool Shift, bool Ctrl, bool Alt);
		void UnbindKey(Windows::Forms::Keys Key);
		void UnbindConsoleCommand(String^ Command);
		void UnbindScriptCommand(String^ Command);
		void UnbindPhoneNumber(String^ PhoneNumber);

		void SendScriptCommand(GTA::Script^ TargetScript, String^ Command, ... array<System::Object^>^ Parameter);
		void SendScriptCommand(String^ TargetScriptGUID, String^ Command, ... array<System::Object^>^ Parameter);
		void SendScriptCommand(Guid TargetScriptGUID, String^ Command, ... array<System::Object^>^ Parameter);
		bool isScriptRunning(String^ GUID);
		bool isScriptRunning(Guid GUID);

	public protected:
		void Wait(int ms);

		/// <summary>
		/// Allows access to resources embedded in the script
		/// </summary>
		property value::Resources^ Resources {
			value::Resources^ get();
		}

	public:
		Script();
		~Script() {this->!Script();}

		//event EventHandler^ Startup;
		event EventHandler^ Tick;
		event GTA::KeyEventHandler^ KeyDown;
		event GTA::KeyEventHandler^ KeyUp;
		event GTA::MouseEventHandler^ MouseDown;
		event GTA::MouseEventHandler^ MouseUp;
		event ConsoleEventHandler^ ConsoleCommand;
		event ScriptCommandEventHandler^ ScriptCommand;
		event PhoneDialEventHandler^ PhoneNumberDialed;

		/// <summary>
		/// Will run every Frame. Use ONLY for drawing functions! Do NOT call Wait() here!
		/// </summary>
		event GraphicsEventHandler^ PerFrameDrawing;

		/// <summary>
		/// The GUID is used to uniquely idetify your script. With it you are able to communicate between scripts.
		/// DO NOT use the same GUID for multiple scripts!
		/// If you want to get a new GUID for your script, just google "generate guid" to find an online generator.
		/// </summary>
		property Guid GUID {
			Guid get() {
				return pGUID;
			}
			protected: void set(Guid value) {
				pGUID = value;
			}
		}

		/// <summary>
		/// The general info is shown by the 'ScriptHelp' console command, together with all available console commands.
		/// </summary>
		property String^ GeneralInfo {
			String^ get() {
				return pGeneralInfo;
			}
			protected: void set(String^ value) {
				pGeneralInfo = value;
			}
		}

		property bool isRunning {
			bool get() {
				return bRunning;
			}
		}
		property bool isWaiting {
			bool get() {
				return bWaiting;
			}
		}
		
		property String^ Filename {
			String^ get() {
				return pFilename;
			}
		}
		property String^ Name {
			String^ get() {
				return GetType()->FullName;
			}
		}
		property String^ FullName {
			String^ get() {
				return System::IO::Path::GetFileName(Filename)+":"+Name;
			}
		}
	
		void Abort();

		virtual System::String^ ToString() override;

	};

}