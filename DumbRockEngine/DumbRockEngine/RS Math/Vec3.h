#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Vec3
	{
		float x, y, z;

		/*Constructors*/

		inline void Load(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}

		inline Vec3(float s = float(0.0f))
		{
			Load(s, s, s);
		}

		inline Vec3(float _x, float _y, float _z)
		{
			Load(_x, _y, _z);
		}

		inline Vec3(const Vec3& _v)
		{
			Load(_v.x, _v.y, _v.z);
		}

		inline Vec3(const Vec2& _v)
		{
			Load(_v.x, _v.y, 1.0f);
		}

		/*Operator Overloads*/

		inline Vec3& operator = (const Vec3& _v)
		{
			Load(_v.x, _v.y, _v.z);
			return *this;
		}

		inline const float operator [] (unsigned int index) const
		{
			return *(&x + index);
		}

		inline float& operator [] (unsigned int index)
		{
			return *(&x + index);
		}

		inline const Vec3 operator + (const Vec3 _v) const
		{
			return Vec3(x + _v.x, y + _v.y, z + _v.z);
		}

		inline Vec3& operator += (const Vec3 _v)
		{
			x += _v.x;
			y += _v.y;
			z += _v.z;
			return *this;
		}

		inline const Vec3 operator - () const
		{
			return Vec3(-x, -y, -z);
		}

		inline const Vec3 operator - (const Vec3 _v) const
		{
			return Vec3(x - _v.x, y - _v.y, z - _v.z);
		}

		inline Vec3& operator -= (const Vec3 _v)
		{
			x -= _v.x;
			y -= _v.y;
			z -= _v.z;
			return *this;
		}

		inline const Vec3 operator * (const float _s) const
		{
			return Vec3(x * _s, y * _s, z * _s);
		}

		inline Vec3& operator *= (const float _s)
		{
			x *= _s;
			y *= _s;
			z *= _s;
			return *this;
		}

		inline const Vec3 operator / (const float _s) const
		{
			if (fabs(_s) < VERY_SMALL)
			{
				//Debug::Log(EMessageType::FATAL_ERROR, "Divide by Zero Exception!", __FILE__, __LINE__);
			}
			float r = 1.0f / _s;
			return *this * r;
		}

		inline Vec3& operator /= (const float _s)
		{
			if (fabs(_s) < VERY_SMALL)
			{
				//Debug::Log(EMessageType::FATAL_ERROR, "Divide by Zero Exception!", __FILE__, __LINE__);
			}
			float r = 1.0f / _s;
			*this *= r;
			return *this;
		}

		/*Utilitarian Fuctions*/

		inline const float Magnitude() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		inline const Vec3 Normalize() const
		{
			return Vec3(x / Magnitude(), y / Magnitude(), z / Magnitude());
		}

		inline const float Dot(Vec3 _v) const
		{
			return x * _v.x + y * _v.y + z * _v.z;
		}

		inline const Vec3 Cross(Vec3 _v) const
		{
			return Vec3(y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x);
		}

		inline const float GetAngle(Vec3 _v) const
		{
			return acos(Dot(_v) / (Magnitude() * _v.Magnitude())) * RAD_TO_DEG;
		}

		inline const void Print()
		{
			printf("v = [%f, %f, %f]\n", x, y, z);
		}
	};
}
