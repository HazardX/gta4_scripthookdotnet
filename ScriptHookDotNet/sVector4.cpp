/*
* Copyright (c) 2007-2010 SlimDX Group
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

/* 
* ALTERED in various parts by Hazard (hazard_x@gmx.net) to adapt it to it's 
* role in the GTA4 .Net ScriptHook. 2009-2011
*/

#include "stdafx.h"

/*#include <d3dx9.h>

#include "sMatrix.h"
#include "sQuaternion.h"
#include "sVector2.h"
#include "sVector3.h"*/

#include "sVector4.h"

namespace GTA {

using namespace System;
using namespace System::Globalization;

	Vector4::Vector4( Vector2 value, float z, float w )
	{
		X = value.X;
		Y = value.Y;
		Z = z;
		W = w;
	}
	
	Vector4::Vector4( Vector3 value, float w )
	{
		X = value.X;
		Y = value.Y;
		Z = value.Z;
		W = w;
	}
	
	Vector4::Vector4( float x, float y, float z, float w )
	{
		X = x;
		Y = y;
		Z = z;
		W = w;
	}
	
	float Vector4::Length()
	{
		return static_cast<float>( Math::Sqrt( (X * X) + (Y * Y) + (Z * Z) + (W * W) ) );
	}
	
	void Vector4::Normalize()
	{
		float length = Length();
		if( length == 0 )
			return;
		float num = 1 / length;
		X *= num;
		Y *= num;
		Z *= num;
		W *= num;
	}
	
	Vector4 Vector4::Add( Vector4 left, Vector4 right )
	{
		return Vector4( left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W );
	}
	
	Vector4 Vector4::Subtract( Vector4 left, Vector4 right )
	{
		return Vector4( left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W );
	}
	
	Vector4 Vector4::Modulate( Vector4 left, Vector4 right )
	{
		return Vector4( left.X * right.X, left.Y * right.Y, left.Z * right.Z, left.W * right.W );
	}
	
	Vector4 Vector4::Multiply( Vector4 value, float scale )
	{
		return Vector4( value.X * scale, value.Y * scale, value.Z * scale, value.W * scale );
	}
	
	Vector4 Vector4::Divide( Vector4 value, float scale )
	{
		return Vector4( value.X / scale, value.Y / scale, value.Z / scale, value.W / scale );
	}
	
	Vector4 Vector4::Negate( Vector4 value )
	{
		return Vector4( -value.X, -value.Y, -value.Z, -value.W );
	}
	
	Vector4 Vector4::Clamp( Vector4 value, Vector4 min, Vector4 max )
	{
		float x = value.X;
		x = (x > max.X) ? max.X : x;
		x = (x < min.X) ? min.X : x;

		float y = value.Y;
		y = (y > max.Y) ? max.Y : y;
		y = (y < min.Y) ? min.Y : y;

		float z = value.Z;
		z = (z > max.Z) ? max.Z : z;
		z = (z < min.Z) ? min.Z : z;

		float w = value.W;
		w = (w > max.W) ? max.W : w;
		w = (w < min.W) ? min.W : w;

		return Vector4( x, y, z, w );
	}
	
	Vector4 Vector4::Lerp( Vector4 start, Vector4 end, float factor )
	{
		Vector4 vector;

		vector.X = start.X + ((end.X - start.X) * factor);
		vector.Y = start.Y + ((end.Y - start.Y) * factor);
		vector.Z = start.Z + ((end.Z - start.Z) * factor);
		vector.W = start.W + ((end.W - start.W) * factor);

		return vector;
	}
	
	float Vector4::Distance( Vector4 value1, Vector4 value2 )
	{
		float x = value1.X - value2.X;
		float y = value1.Y - value2.Y;
		float z = value1.Z - value2.Z;
		float w = value1.W - value2.W;

		return static_cast<float>( Math::Sqrt( (x * x) + (y * y) + (z * z) + (w * w) ) );
	}
	
	float Vector4::Dot( Vector4 left, Vector4 right )
	{
		return (left.X * right.X + left.Y * right.Y + left.Z * right.Z + left.W * right.W);
	}

	Vector4 Vector4::Normalize( Vector4 vector )
	{
		vector.Normalize();
		return vector;
	}
	
	Vector4 Vector4::Transform( Vector4 vector, Matrix transform )
	{
		Vector4 result;

		result.X = (vector.X * transform.M11) + (vector.Y * transform.M21) + (vector.Z * transform.M31) + (vector.W * transform.M41);
		result.Y = (vector.X * transform.M12) + (vector.Y * transform.M22) + (vector.Z * transform.M32) + (vector.W * transform.M42);
		result.Z = (vector.X * transform.M13) + (vector.Y * transform.M23) + (vector.Z * transform.M33) + (vector.W * transform.M43);
		result.W = (vector.X * transform.M14) + (vector.Y * transform.M24) + (vector.Z * transform.M34) + (vector.W * transform.M44);

		return result;
	}
	
	Vector4 Vector4::Transform( Vector4 value, Quaternion rotation )
	{
		Vector4 vector;
		float x = rotation.X + rotation.X;
		float y = rotation.Y + rotation.Y;
		float z = rotation.Z + rotation.Z;
		float wx = rotation.W * x;
		float wy = rotation.W * y;
		float wz = rotation.W * z;
		float xx = rotation.X * x;
		float xy = rotation.X * y;
		float xz = rotation.X * z;
		float yy = rotation.Y * y;
		float yz = rotation.Y * z;
		float zz = rotation.Z * z;

		vector.X = ((value.X * ((1.0f - yy) - zz)) + (value.Y * (xy - wz))) + (value.Z * (xz + wy));
		vector.Y = ((value.X * (xy + wz)) + (value.Y * ((1.0f - xx) - zz))) + (value.Z * (yz - wx));
		vector.Z = ((value.X * (xz - wy)) + (value.Y * (yz + wx))) + (value.Z * ((1.0f - xx) - yy));
		vector.W = value.W;

		return vector;
	}

	Vector4 Vector4::Minimize( Vector4 left, Vector4 right )
	{
		Vector4 vector;
		vector.X = (left.X < right.X) ? left.X : right.X;
		vector.Y = (left.Y < right.Y) ? left.Y : right.Y;
		vector.Z = (left.Z < right.Z) ? left.Z : right.Z;
		vector.W = (left.W < right.W) ? left.W : right.W;
		return vector;
	}

	Vector4 Vector4::Maximize( Vector4 left, Vector4 right )
	{
		Vector4 vector;
		vector.X = (left.X > right.X) ? left.X : right.X;
		vector.Y = (left.Y > right.Y) ? left.Y : right.Y;
		vector.Z = (left.Z > right.Z) ? left.Z : right.Z;
		vector.W = (left.W > right.W) ? left.W : right.W;
		return vector;
	}

	Vector4 Vector4::operator + ( Vector4 left, Vector4 right )
	{
		return Vector4( left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W );
	}
	
	Vector4 Vector4::operator - ( Vector4 left, Vector4 right )
	{
		return Vector4( left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W );
	}
	
	Vector4 Vector4::operator - ( Vector4 value )
	{
		return Vector4( -value.X, -value.Y, -value.Z, -value.W );
	}
	
	Vector4 Vector4::operator * ( Vector4 value, float scale )
	{
		return Vector4( value.X * scale, value.Y * scale, value.Z * scale, value.W * scale );
	}
	
	Vector4 Vector4::operator * ( float scale, Vector4 vec )
	{
		return vec * scale;
	}
	
	Vector4 Vector4::operator / ( Vector4 value, float scale )
	{
		return Vector4( value.X / scale, value.Y / scale, value.Z / scale, value.W / scale );
	}

	bool Vector4::operator == ( Vector4 left, Vector4 right )
	{
		return Vector4::Equals( left, right );
	}

	bool Vector4::operator != ( Vector4 left, Vector4 right )
	{
		return !Vector4::Equals( left, right );
	}

	String^ Vector4::ToString()
	{
		return String::Format( CultureInfo::CurrentCulture, "X:{0} Y:{1} Z:{2} W:{3}", X.ToString(CultureInfo::CurrentCulture), 
			Y.ToString(CultureInfo::CurrentCulture), Z.ToString(CultureInfo::CurrentCulture),
			W.ToString(CultureInfo::CurrentCulture) );
	}

	int Vector4::GetHashCode()
	{
		return X.GetHashCode() + Y.GetHashCode() + Z.GetHashCode() + W.GetHashCode();
	}

	bool Vector4::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<Vector4>( value ) );
	}

	bool Vector4::Equals( Vector4 value )
	{
		return ( X == value.X && Y == value.Y && Z == value.Z && W == value.W );
	}

	bool Vector4::Equals( Vector4% value1, Vector4% value2 )
	{
		return ( value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z && value1.W == value2.W );
	}
}