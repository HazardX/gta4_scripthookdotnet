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

#include "sVector3.h"

#include "World.h"
#include "sVector4.h"

#pragma managed

namespace GTA {

	using namespace System;
	using namespace System::Globalization;


	Vector3::Vector3( Vector2 value, float z )
	{
		X = value.X;
		Y = value.Y;
		Z = z;
	}

	Vector3::Vector3(float x, float y, float z) {
		X = x;
		Y = y;
		Z = z;
	}


	float Vector3::Length() {
		return static_cast<float>( Math::Sqrt((X*X)+(Y*Y)+(Z*Z)) );
	}

	float Vector3::LengthSquared()
	{
		return (X * X) + (Y * Y) + (Z * Z);
	}
	
	void Vector3::Normalize() {
		float length = Length();
		if(length == 0) return;
		float num = 1 / length;
		X *= num;
		Y *= num;
		Z *= num;
	}

	Vector3 Vector3::Add( Vector3 left, Vector3 right )
	{
		return Vector3( left.X + right.X, left.Y + right.Y, left.Z + right.Z );
	}

	Vector3 Vector3::Subtract( Vector3 left, Vector3 right )
	{
		return Vector3( left.X - right.X, left.Y - right.Y, left.Z - right.Z );
	}

	Vector3 Vector3::Modulate( Vector3 left, Vector3 right )
	{
		return Vector3( left.X * right.X, left.Y * right.Y, left.Z * right.Z );
	}

	Vector3 Vector3::Multiply( Vector3 value, float scale )
	{
		return Vector3( value.X * scale, value.Y * scale, value.Z * scale );
	}

	Vector3 Vector3::Divide( Vector3 value, float scale )
	{
		return Vector3( value.X / scale, value.Y / scale, value.Z / scale );
	}

	Vector3 Vector3::Negate( Vector3 value )
	{
		return Vector3( -value.X, -value.Y, -value.Z );
	}

	Vector3 Vector3::Clamp( Vector3 value, Vector3 min, Vector3 max )
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

		return Vector3( x, y, z );
	}

	Vector3 Vector3::Lerp( Vector3 start, Vector3 end, float factor )
	{
		Vector3 vector;

		vector.X = start.X + ((end.X - start.X) * factor);
		vector.Y = start.Y + ((end.Y - start.Y) * factor);
		vector.Z = start.Z + ((end.Z - start.Z) * factor);

		return vector;
	}

	float Vector3::Dot( Vector3 left, Vector3 right ) {
		return (left.X * right.X + left.Y * right.Y + left.Z * right.Z);
	}
	
	Vector3 Vector3::Cross( Vector3 left, Vector3 right )	{
		Vector3 result;
		result.X = left.Y * right.Z - left.Z * right.Y;
		result.Y = left.Z * right.X - left.X * right.Z;
		result.Z = left.X * right.Y - left.Y * right.X;
		return result;
	}

	Vector3 Vector3::Reflect( Vector3 vector, Vector3 normal )
	{
		Vector3 result;
		float dot = ((vector.X * normal.X) + (vector.Y * normal.Y)) + (vector.Z * normal.Z);

		result.X = vector.X - ((2.0f * dot) * normal.X);
		result.Y = vector.Y - ((2.0f * dot) * normal.Y);
		result.Z = vector.Z - ((2.0f * dot) * normal.Z);

		return result;
	}
	
	Vector3 Vector3::Normalize(Vector3 vector) {
		vector.Normalize();
		return vector;
	}

	Vector4 Vector3::Transform( Vector3 vector, Matrix transform )
	{
		Vector4 result;

		result.X = (((vector.X * transform.M11) + (vector.Y * transform.M21)) + (vector.Z * transform.M31)) + transform.M41;
		result.Y = (((vector.X * transform.M12) + (vector.Y * transform.M22)) + (vector.Z * transform.M32)) + transform.M42;
		result.Z = (((vector.X * transform.M13) + (vector.Y * transform.M23)) + (vector.Z * transform.M33)) + transform.M43;
		result.W = (((vector.X * transform.M14) + (vector.Y * transform.M24)) + (vector.Z * transform.M34)) + transform.M44;

		return result;
	}

	Vector4 Vector3::Transform( Vector3 value, Quaternion rotation )
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
		vector.W = 1.0f;

		return vector;
	}

	Vector3 Vector3::TransformCoordinate( Vector3 coord, Matrix transform )
	{
		Vector4 vector;

		vector.X = (((coord.X * transform.M11) + (coord.Y * transform.M21)) + (coord.Z * transform.M31)) + transform.M41;
		vector.Y = (((coord.X * transform.M12) + (coord.Y * transform.M22)) + (coord.Z * transform.M32)) + transform.M42;
		vector.Z = (((coord.X * transform.M13) + (coord.Y * transform.M23)) + (coord.Z * transform.M33)) + transform.M43;
		vector.W = 1 / ((((coord.X * transform.M14) + (coord.Y * transform.M24)) + (coord.Z * transform.M34)) + transform.M44);

		return Vector3( vector.X * vector.W, vector.Y * vector.W, vector.Z * vector.W );
	}

	Vector3 Vector3::TransformNormal( Vector3 normal, Matrix transform )
	{
		Vector3 vector;

		vector.X = ((normal.X * transform.M11) + (normal.Y * transform.M21)) + (normal.Z * transform.M31);
		vector.Y = ((normal.X * transform.M12) + (normal.Y * transform.M22)) + (normal.Z * transform.M32);
		vector.Z = ((normal.X * transform.M13) + (normal.Y * transform.M23)) + (normal.Z * transform.M33);

		return vector;
	}

	Vector3 Vector3::Project( Vector3 vector, int x, int y, int width, int height, float minZ, float maxZ, Matrix worldViewProjection )
	{
		vector = Vector3::TransformCoordinate( vector, worldViewProjection );
		return Vector3( ( ( 1.0f + vector.X ) * 0.5f * width ) + x, ( ( 1.0f - vector.Y ) * 0.5f * height ) + y, ( vector.Z * ( maxZ - minZ ) ) + minZ );
	}

	Vector3 Vector3::Unproject( Vector3 vector, int x, int y, int width, int height, float minZ, float maxZ, Matrix worldViewProjection )
	{
		Vector3 v;
		Matrix matrix =	Matrix::Invert( worldViewProjection );

		v.X = ( ( ( vector.X - x ) / width ) * 2.0f ) - 1.0f;
		v.Y = -( ( ( ( vector.Y - y ) / height ) * 2.0f ) - 1.0f );
		v.Z = ( vector.Z - minZ ) / ( maxZ - minZ );

		return Vector3::TransformCoordinate( v, matrix );
	}

	Vector3 Vector3::Minimize( Vector3 left, Vector3 right )
	{
		Vector3 vector;
		vector.X = (left.X < right.X) ? left.X : right.X;
		vector.Y = (left.Y < right.Y) ? left.Y : right.Y;
		vector.Z = (left.Z < right.Z) ? left.Z : right.Z;
		return vector;
	}

	Vector3 Vector3::Maximize( Vector3 left, Vector3 right )
	{
		Vector3 vector;
		vector.X = (left.X > right.X) ? left.X : right.X;
		vector.Y = (left.Y > right.Y) ? left.Y : right.Y;
		vector.Z = (left.Z > right.Z) ? left.Z : right.Z;
		return vector;
	}

	Vector3 Vector3::operator + ( Vector3 left, Vector3 right )
	{
		return Vector3( left.X + right.X, left.Y + right.Y, left.Z + right.Z );
	}
	
	Vector3 Vector3::operator - ( Vector3 left, Vector3 right )
	{
		return Vector3( left.X - right.X, left.Y - right.Y, left.Z - right.Z );
	}
	
	Vector3 Vector3::operator - ( Vector3 value )
	{
		return Vector3( -value.X, -value.Y, -value.Z );
	}

	Vector3 Vector3::operator * ( Vector3 value, float scale )
	{
		return Vector3( value.X * scale, value.Y * scale, value.Z * scale );
	}

	Vector3 Vector3::operator * ( float scale, Vector3 vec )
	{
		return vec * scale;
	}
	
	Vector3 Vector3::operator / ( Vector3 value, float scale )
	{
		return Vector3( value.X / scale, value.Y / scale, value.Z / scale );
	}
	
	bool Vector3::operator == ( Vector3 left, Vector3 right )
	{
		return Vector3::Equals( left, right );
	}
	
	bool Vector3::operator != ( Vector3 left, Vector3 right )
	{
		return !Vector3::Equals( left, right );
	}

	int Vector3::GetHashCode()
	{
		return X.GetHashCode() + Y.GetHashCode() + Z.GetHashCode();
	}

	bool Vector3::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<Vector3>( value ) );
	}

	bool Vector3::Equals( Vector3 value )
	{
		return ( X == value.X && Y == value.Y && Z == value.Z );
	}

	bool Vector3::Equals( Vector3% value1, Vector3% value2 )
	{
		return ( value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z );
	}

	// ### my stuff ###

	Vector3 Vector3::Around(float Distance) {
		return Vector3(X,Y,Z) + Vector3::RandomXY() * Distance;
	}
	Vector3 Vector3::ToGround() {
		return World::GetGroundPosition(Vector3(X,Y,Z));
	}
	float Vector3::ToHeading() {
		return Helper::DirectionToHeading(Vector3(X,Y,Z));
	}

	float Vector3::DistanceTo(Vector3 Position) {
		return (Position - Vector3(X,Y,Z)).Length();
	}
	float Vector3::DistanceTo2D(Vector3 Position) {
		Position.Z = 0.0f;
		return (Position - Vector3(X,Y,0.0f)).Length();
	}

	Vector3 Vector3::RandomXYZ() {
		Vector3 v;
		v.X = (float)(Helper::Random->NextDouble() - 0.5);
		v.Y = (float)(Helper::Random->NextDouble() - 0.5);
		v.Z = (float)(Helper::Random->NextDouble() - 0.5);
		v.Normalize();
		return v;
	}
	Vector3 Vector3::RandomXY() {
		Vector3 v;
		v.X = (float)(Helper::Random->NextDouble() - 0.5);
		v.Y = (float)(Helper::Random->NextDouble() - 0.5);
		v.Z = 0.0f;
		v.Normalize();
		return v;
	}

	String^ Vector3::ToString() {
		return String::Format( CultureInfo::InvariantCulture, "X:{0} Y:{1} Z:{2}", Helper::FloatToString(X), Helper::FloatToString(Y), Helper::FloatToString(Z) );
	}
	String^ Vector3::ToString(String^ Seperator, int Digits) {
		return String::Format( CultureInfo::InvariantCulture, "{0}{3}{1}{3}{2}", Helper::FloatToString(X,Digits), Helper::FloatToString(Y,Digits), Helper::FloatToString(Z,Digits), Seperator );
	}

}