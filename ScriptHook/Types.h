/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

\*****************************************************************************/

#pragma once

// Some standard types

typedef unsigned int u32;
typedef int i32;

typedef unsigned short u16;
typedef short i16;

typedef unsigned char u8;
typedef char i8, ch;

typedef wchar_t wch;

typedef float f32;
typedef double f64;

typedef bool b8;
typedef unsigned int b32;

// Define a "any" pointer type, and define casting operations

typedef void * ptr;

template <typename T>
inline T *ptr_cast(u32 value)
{
	return *reinterpret_cast<T **>(&value);
}

inline ptr ptr_cast(u32 value)
{
	return *reinterpret_cast<ptr*>(&value);
}

template <class T>
inline T* ptr_cast(ptr value)
{
    return reinterpret_cast<T*>(value);
}

// Define a null if it already hasn't been

#ifndef NULL
#define NULL (0)
#endif

#ifdef SCRIPTHOOK_EXPORTS
#define DllExport _declspec(dllexport)
#else
#define DllExport _declspec(dllimport)
#endif

