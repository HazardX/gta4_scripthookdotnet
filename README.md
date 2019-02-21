# GTAIV .Net Script Hook

by Hazard (hazard_x@gmx.net / twitter.com/HazardX)

based on and includes parts of the GTAIV C++ Script Hook
from Aru <oneforaru at gmail dot com>

Classes Vector2, Vector3, Vector4, Quaternion and Matrix based on
sourcecode from SlimDX (https://github.com/SlimDX/slimdx)


**Description**

This archive contains the complete C++/CLI sourcecode of the 
GTAIV .Net Script Hook. The compiled ASI plugin allows you to 
run in-game GTAIV scripts written in any .Net language. 
The goal of this project is to provide a .Net-typical and easy 
to use class structure that wraps all scripting functionality 
of the game.
Scripts can be developed directly with Visual Studio, granting 
you all it's benefits like code highlighting and IntelliSense.

WARNING: The code is messy as hell. It was one of my first 
larger C++ based projects and many very C++ specific things 
like file structure and includes are a total DISASTER!
Potential health risks of trying to understand or restructure 
the code include, but are not limited to:
Loss of sanity, brain damage and irreversible nerdism.


Special thanks to Aru for his help and for his C++ Script Hook.
This project wouldn't have been possible without it.

You can get Aru's C++ Script Hook here:
http://www.gtaforums.com/index.php?showtopic=390582


**Requirements**

Required to compile the sourcecode are:

- Microsoft Visual Studio 2010 (newer versions will probably work too)
- Microsoft DirectX SDK March 2008
- Microsoft Windows SDK (maybe? am not entirely sure...)

IMPORTANT: After installing the DirectX SDK March 2008 you'll have to
set up a system variable in windows named "DXSDK_2008-03" containing 
the full path to the installation folder of the SDK. This is to allow 
multiple versions of the SDK to be installed. Make sure to include a 
final backslash ( \ ) at the end of the path.

See the included ScriptHookDotNet.readme.txt on how to actually run 
the Script Hook with the game.


**License**

The GTAIV .Net Script Hook sourcecode is published unter the MIT license. 
See LICENSE.txt for the complete license text.

When you release sourcecode from this project make sure that you keep 
the full, unaltered license text at the beginning of the files. When
you changed parts of the released sourcecode make sure to include a
notice right below the license text in the modified files that states
that you altered the sourcecode, to make clear that i am not the sole 
author of all of the file's contents anymore.

You are free to distribute compiled derivative works of this in binary
form in any way you see fit and without limitations. It would be nice,
though, to give credit to Hazard (hazard_x@gmx.net / twitter.com/HazardX)
as author of the original GTAIV .Net Script Hook.

See LICENSE-ScriptHook.txt for the license of the GTAIV C++ Script Hook,
and LICENSE-SlimDX.txt for the license of the SlimDX sourcecode.
