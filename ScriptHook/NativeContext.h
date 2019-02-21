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
#include "GameTypes.h"

class NativeContext :
	public GameTypes::scrNativeCallContext
{
private:
	// Configuration
	enum
	{
		MaxNativeParams = 16,
		ArgSize = sizeof(u32),
	};
	
	// Anything temporary that we need
	u8 m_TempStack[MaxNativeParams * ArgSize];

public:
	inline NativeContext()
	{
		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;		// It's okay to point both args and return at 
										// the same pointer. The game should handle this.
		m_nArgCount = 0;
		m_nDataCount = 0;
	}

	template <typename T>
	inline void Push(T value)
	{
		if (sizeof(T) > ArgSize)
		{
			// We only accept sized 4 or less arguments... that means no double/f64 or large structs are allowed.
			throw "Argument has an invalid size";
		}
		else if (sizeof(T) < ArgSize)
		{
			// Ensure we don't have any stray data
			*ptr_cast<u32>(m_TempStack + ArgSize * m_nArgCount) = 0;
		}

		*ptr_cast<T>(m_TempStack + ArgSize * m_nArgCount) = value;
		m_nArgCount++;
	}

	template <typename T>
	inline T GetResult()
	{
        // Copy back any vector results
        while(m_nDataCount > 0)
        {
            m_nDataCount--;
            Vector3 *pVec3 = m_pOriginalData[m_nDataCount];
            Vector4 *pVec4 = &m_TemporaryData[m_nDataCount];
            pVec3->X = pVec4->X;
            pVec3->Y = pVec4->Y;
            pVec3->Z = pVec4->Z;
        }

        // Return the top of the stack
		return *ptr_cast<T>(m_TempStack);
	}
};
