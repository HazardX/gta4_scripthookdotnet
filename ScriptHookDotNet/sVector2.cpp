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

#include "sVector2.h"

#include "sVector4.h"

namespace GTA {

using namespace System;
using namespace System::Globalization;


	Vector2::Vector2( float x, float y )
	{
		X = x;
		Y = y;
	}
	
	float Vector2::Length()
	{
		return static_cast<float>( Math::Sqrt( (X * X) + (Y * Y) ) );
	}
	
	void Vector2::Normalize()
	{
		float length = Length();
		if( length == 0 )
			return;
		float num = 1 / length;
		X *= num;
		Y *= num;
	}

	Vector2 Vector2::Add( Vector2 left, Vector2 right )
	{
		return Vector2( left.X + right.X, left.Y + right.Y );
	}
	
	Vector2 Vector2::Subtract( Vector2 left, Vector2 right )
	{
		return Vector2( left.X - right.X, left.Y - right.Y );
	}
	
	Vector2 Vector2::Modulate( Vector2 left, Vector2 right )
	{
		return Vector2( left.X * right.X, left.Y * right.Y );
	}
	
	Vector2 Vector2::Multiply( Vector2 value, float scale )
	{
		return Vector2( value.X * scale, value.Y * scale );
	}
	
	Vector2 Vector2::Divide( Vector2 value, float scale )
	{
		return Vector2( value.X / scale, value.Y / scale );
	}

	Vector2 Vector2::Negate( Vector2 value )
	{
		return Vector2( -value.X, -value.Y );
	}
	
	Vector2 Vector2::Clamp( Vector2 value, Vector2 min, Vector2 max )
	{
		float x = value.X;
		x = (x > max.X) ? max.X : x;
		x = (x < min.X) ? min.X : x;

		float y = value.Y;
		y = (y > max.Y) ? max.Y : y;
		y = (y < min.Y) ? min.Y : y;

		return Vector2( x, y );
	}
	
	Vector2 Vector2::Lerp( Vector2 start, Vector2 end, float factor )
	{
		Vector2 vector;

		vector.X = start.X + ((end.X - start.X) * factor);
		vector.Y = start.Y + ((end.Y - start.Y) * factor);

		return vector;
	}
	
	float Vector2::Distance( Vector2 value1, Vector2 value2 )
	{
		float x = value1.X - value2.X;
		float y = value1.Y - value2.Y;

		return static_cast<float>( Math::Sqrt( (x * x) + (y * y) ) );
	}
	
	float Vector2::Dot( Vector2 left, Vector2 right )
	{
		return (left.X * right.X + left.Y * right.Y);
	}
	
	Vector2 Vector2::Normalize( Vector2 vector )
	{
		vector.Normalize();
		return vector;
	}
	
	Vector4 Vector2::Transform( Vector2 vector, Matrix transform )
	{
		Vector4 result;

		result.X = (vector.X * transform.M11) + (vector.Y * transform.M21) + transform.M41;
		result.Y = (vector.X * transform.M12) + (vector.Y * transform.M22) + transform.M42;
		result.Z = (vector.X * transform.M13) + (vector.Y * transform.M23) + transform.M43;
		result.W = (vector.X * transform.M14) + (vector.Y * transform.M24) + transform.M44;

		return result;
	}
	
	Vector4 Vector2::Transform( Vector2 value, Quaternion rotation )
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

		vector.X = ((value.X * ((1.0f - yy) - zz)) + (value.Y * (xy - wz)));
		vector.Y = ((value.X * (xy + wz)) + (value.Y * ((1.0f - xx) - zz)));
		vector.Z = ((value.X * (xz - wy)) + (value.Y * (yz + wx)));
		vector.W = 1.0f;

		return vector;
	}
	
	Vector2 Vector2::TransformCoordinate( Vector2 coord, Matrix transform )
	{
		Vector4 vector;

		vector.X = (coord.X * transform.M11) + (coord.Y * transform.M21) + transform.M41;
		vector.Y = (coord.X * transform.M12) + (coord.Y * transform.M22) + transform.M42;
		vector.Z = (coord.X * transform.M13) + (coord.Y * transform.M23) + transform.M43;
		vector.W = 1 / ((coord.X * transform.M14) + (coord.Y * transform.M24) + transform.M44);

		return Vector2( vector.X * vector.W, vector.Y * vector.W );
	}

	Vector2 Vector2::TransformNormal( Vector2 normal, Matrix transform )
	{
		Vector2 vector;

		vector.X = (normal.X * transform.M11) + (normal.Y * transform.M21);
		vector.Y = (normal.X * transform.M12) + (normal.Y * transform.M22);

		return vector;
	}
	
	Vector2 Vector2::Minimize( Vector2 left, Vector2 right )
	{
		Vector2 vector;
		vector.X = (left.X < right.X) ? left.X : right.X;
		vector.Y = (left.Y < right.Y) ? left.Y : right.Y;
		return vector;
	}
	
	Vector2 Vector2::Maximize( Vector2 left, Vector2 right )
	{
		Vector2 vector;
		vector.X = (left.X > right.X) ? left.X : right.X;
		vector.Y = (left.Y > right.Y) ? left.Y : right.Y;
		return vector;
	}
	
	Vector2 Vector2::operator + ( Vector2 left, Vector2 right )
	{
		return Vector2( left.X + right.X, left.Y + right.Y );
	}

	Vector2 Vector2::operator - ( Vector2 left, Vector2 right )
	{
		return Vector2( left.X - right.X, left.Y - right.Y );
	}
	
	Vector2 Vector2::operator - ( Vector2 value )
	{
		return Vector2( -value.X, -value.Y );
	}
	
	Vector2 Vector2::operator * ( Vector2 value, float scale )
	{
		return Vector2( value.X * scale, value.Y * scale );
	}
	
	Vector2 Vector2::operator * ( float scale, Vector2 vec )
	{
		return vec * scale;
	}
	
	Vector2 Vector2::operator / ( Vector2 value, float scale )
	{
		return Vector2( value.X / scale, value.Y / scale );
	}
	
	bool Vector2::operator == ( Vector2 left, Vector2 right )
	{
		return Vector2::Equals( left, right );
	}
	
	bool Vector2::operator != ( Vector2 left, Vector2 right )
	{
		return !Vector2::Equals( left, right );
	}
	
	String^ Vector2::ToString()
	{
		return String::Format( CultureInfo::CurrentCulture, "X:{0} Y:{1}", X.ToString(CultureInfo::CurrentCulture), Y.ToString(CultureInfo::CurrentCulture) );
	}

	int Vector2::GetHashCode()
	{
		return X.GetHashCode() + Y.GetHashCode();
	}

	bool Vector2::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<Vector2>( value ) );
	}

	bool Vector2::Equals( Vector2 value )
	{
		return ( X == value.X && Y == value.Y );
	}

	bool Vector2::Equals( Vector2% value1, Vector2% value2 )
	{
		return ( value1.X == value2.X && value1.Y == value2.Y );
	}
}