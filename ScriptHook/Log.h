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

#include "Types.h"

#define LogDebug(x, ...) Log::Debug(x, __VA_ARGS__)
#define LogInfo(x, ...) Log::Info(x, __VA_ARGS__)
#define LogWarn(x, ...) Log::Warn(x, __VA_ARGS__)
#define LogError(x, ...) Log::Error(x, __VA_ARGS__)
#define LogFatal(x, ...) Log::Fatal(x, __VA_ARGS__)

#ifndef _DEBUG

// Redefine some for release mode logging

#undef LogDebug
#define LogDebug(x, ...) /* Debug: x */ __noop

//#undef LogInfo
//#define LogInfo(x, ...) /* Info: x */ __noop

#endif

class DllExport GenericLogger
{
private:
	GenericLogger *m_pNextLogger;
    
	virtual void Log(const ch *type, const ch *message)
	{
		if (m_pNextLogger)
		{
			m_pNextLogger->Log(type, message);
		}
	}

public:
	GenericLogger() { m_pNextLogger = 0; }
    virtual ~GenericLogger() {}

    virtual void Debug(const ch *message) { Log("DEBUG", message); }
    virtual void Info(const ch *message) { Log("INFO", message); }
    virtual void Warn(const ch *message) { Log("WARN", message); }
	virtual void Error(const ch *message) { Log("ERROR", message); }
    virtual void Fatal(const ch *message) { Log("FATAL", message); }

	inline GenericLogger *GetNext() { return m_pNextLogger; }
	inline void SetNext(GenericLogger *logger) { m_pNextLogger = logger; }
};

class DllExport Log
{
private:
    static GenericLogger *m_pLogger;

public:
    static void AddLogger(GenericLogger *logger);

    static void Debug(const ch *format, ...);
    static void Info(const ch *format, ...);
    static void Warn(const ch *format, ...);
	static void Error(const ch *format, ...);
    static void Fatal(const ch *format, ...);
};
