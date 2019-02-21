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

#define USE_APPDOMAINS true
#define USE_NETTHREAD true
//#define USE_THREADPOOL true

#ifdef DEBUG
#define VERBOSE true
#else
#define VERBOSE false
#endif

namespace GTA {

	value class Vector2;
	value class Vector3;
	value class Vector4;
	value class Matrix;
	value class Quaternion;
	value class Model;
	value class Room;
	value class ColorIndex;

	ref class SkinTemplate;
	ref class AnimationSet;

	ref class NetThread;
	ref class ScriptThread;
	ref class GenericThread;
	ref class ScriptDomain;
	ref class RemoteScriptDomain;
	ref class Script;
	ref class Console;
	ref class KeyboardLayout;
	ref class KeyWatchDog;

	ref class ContentCache;
	ref class Game;
	ref class Player;
	ref class Ped;
	ref class Vehicle;
	ref class Group;
	ref class World;
	ref class Blip;
	ref class Camera;
	ref class Object;
	ref class Pickup;
	ref class ScriptedFire;

	ref class TaskSequence;
	ref class Graphics;
	ref class Font;
	ref class Texture;
	ref class PedCollection;
	ref class SettingsFile;

	namespace base {
		ref class Object;
		ref class HandleObject;
		ref class Console;
		ref class Mouse;

		generic <typename T>
		ref class BaseCollection;
		generic <typename T>
		ref class ReadOnlyCollection;
		generic <typename T>
		ref class Collection;
	}
	/*namespace Euphoria {
		ref class General;
		ref class BaseMessage;
		ref class BaseHelper;
		ref class CustomHelper;
		ref class ArmsWindmillHelper;
		ref class BeingShotHelper;
		ref class BodyBalanceHelper;
		ref class GrabHelper;
		ref class LeanToPositionHelper;
		ref class LeanTowardsObjectHelper;
		ref class PedalLegsHelper;
	}*/
	namespace Forms {
		ref class Button;
		ref class Checkbox;
		ref class Control;
		ref class Form;
		ref class FormHost;
		ref class Keybox;
		ref class Label;
		ref class Mouse;
		ref class Scrollbar;
		ref class Textbox;
	}
	namespace Multiplayer {
		ref class Host;
		ref class Team;
	}
	namespace Native {
		ref class Parameter;
		ref class Pointer;
		ref class Function;
		ref class Template;
	}
	namespace value {
		ref class DynamicMetadata;
		ref class Euphoria;
		ref class Globals;
		ref class PedAnimation;
		ref class PedSkin;
		ref class PedComponent;
		ref class PedComponentCollection;
		ref class PedTasks;
		ref class PlayerSkin;
		ref class Resources;
		ref class Tasks;
		ref class VehicleDoor;
		ref class VehicleExtra;
		ref class Weapon;
		ref class WeaponCollection;
		
	}
	namespace VertexFormats {
		interface class iVertexFormat;
		value class TransformedColored;
		value class TransformedColoredTextured;
	}
}
namespace unmanaged {
	ref class MemoryAccess;
	class NativeContext3;
	namespace Native {
		class Function;
	}
}


#define isNULL(var) (System::Object::ReferenceEquals(var,nullptr))
#define isNotNULL(var) (!System::Object::ReferenceEquals(var,nullptr))

#define PinStringA(str) (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str).ToPointer()
#define PinStringU(str) (WCHAR*)System::Runtime::InteropServices::Marshal::StringToHGlobalUni(str).ToPointer()
#define FreeString(ptr) System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(ptr))

#define catchScriptErrors(Script,CodeLocation,onCatch)	\
	catch(System::Exception^ ex) { GTA::RemoteScriptDomain::Instance->ScriptError(Script,CodeLocation,ex); onCatch } \
		catch(...) { GTA::RemoteScriptDomain::Instance->ScriptError(Script,CodeLocation); onCatch } 

#define catchErrors(LogMessage,onCatch)	\
	catch(System::Exception^ ex) { GTA::NetHook::Log( LogMessage + ":" ,ex); onCatch } \
	catch(...) { GTA::NetHook::Log( LogMessage + "!" ); onCatch } 

#define lock(lockobj) { System::Threading::Monitor::Enter(lockobj); try {
#define unlock(lockobj) } catch (System::Exception^ ex){throw ex;} catch (...){throw gcnew Exception();} finally { System::Threading::Monitor::Exit(lockobj); } }

#define LOCK lock(syncroot)
#define UNLOCK unlock(syncroot)

#define LogFin(name) if (VERBOSE) GTA::NetHook::Log( "FINALIZING " + name )
#define DoGC(name) { if (VERBOSE) GTA::NetHook::Log( "After "+name+" do GC::Collect..." ); System::GC::Collect(); }

#define ALTERNATE_LOCAL_EVENT(EventID,Arguments,CodeBefore,CodeAfter) if (!NetHook::isPrimary) { CodeBefore \
			NetHook::RaiseEventInLocalScriptDomain(EventID, Arguments); CodeAfter }


#ifdef DEBUG
#define NON_EXISTING_MESSAGE(object) NonExistingObjectException::DEFAULT_MESSAGE + " (" + object->GetType()->Name + " " + object->UID.ToString() + ")" 
#else
#define NON_EXISTING_MESSAGE(object)
#endif

#define OBJECT_NON_EXISTING_CHECK(object,returns) if (!object->Exists()) { throw gcnew NonExistingObjectException( NON_EXISTING_MESSAGE(object) ); return returns; }
#define OBJECT_NON_EXISTING_CHECK_ALLOW_NULL(object,returns) if ((object->Handle != 0) && (!object->Exists())) { throw gcnew NonExistingObjectException( NON_EXISTING_MESSAGE(object) ); return returns; }
#define OBJECT_NON_EXISTING_CHECK_RELAXED(object,returns) if (!object->Exists()) return returns

#define NON_EXISTING_CHECK(returns) OBJECT_NON_EXISTING_CHECK(this,returns)
#define NON_EXISTING_CHECK_RELAXED(returns) OBJECT_NON_EXISTING_CHECK_RELAXED(this,returns)

#define V3_NaN Vector3(float::NaN,float::NaN,float::NaN)
#define V3_NULL Vector3()

#define CLASS_ATTRIBUTES [System::Diagnostics::DebuggerNonUserCode()]


#ifdef DEBUG
#define VLOG(text) if (VERBOSE) GTA::NetHook::Log( text )
#define LogCount(cache, name, amount) if ( (VERBOSE) && ((cache->Count % amount) == 0) ) GTA::NetHook::Log("WARNING! " + name + " count: " + cache->Count.ToString());
#else
#define VLOG(text) // nothing to see here
#define LogCount(cache, name, amount) // nothing to see here
#endif


template <typename R, typename T>
inline R force_cast(T value) {
	return *reinterpret_cast<R*>(&value);
}

typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

#define WinForms System::Windows::Forms

namespace GTA {

	using namespace System;
	using namespace System::IO;
	//using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;

}