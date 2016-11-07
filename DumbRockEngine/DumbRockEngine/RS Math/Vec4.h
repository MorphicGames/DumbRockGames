#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Vec4
	{
		float x, y, z, w;

		/*Constructors*/

		inline void Load(float _x, float _y, float _z, float _w)
		{
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		inline Vec4(float s = (0.0f))
		{
			Load(s, s, s, s);
		}

		inline Vec4(float _x, float _y, float _z, float _w)
		{
			Load(_x, _y, _z, _w);
		}

		inline Vec4(const Vec4& _v)
		{
			Load(_v.x, _v.y, _v.z, _v.w);
		}

		inline Vec4(const Vec3& _v)
		{
			Load(_v.x, _v.y, _v.z, 1.0f);
		}

		/*Operator Overloads*/

		inline const float operator [] (unsigned int index) const
		{
			return *(&x + index);
		}

		inline float& operator [] (unsigned int index)
		{
			return *(&x + index);
		}
	};
}
