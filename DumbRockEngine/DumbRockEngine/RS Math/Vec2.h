#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Vec2
	{
		float x, y;

		/*Constructors*/

		inline void Load(float _x, float _y)
		{
			x = _x;
			y = _y;
		}

		inline Vec2(float s = float(0.0f))
		{
			Load(s, s);
		}

		inline Vec2(float _x, float _y)
		{
			Load(_x, _y);
		}

		inline Vec2(const Vec2& _v)
		{
			Load(_v.x, _v.y);
		}

		/*Operator Overloads*/

		const float operator [] (unsigned int index) const
		{
			return *(&x + index);
		}

		float operator [] (unsigned int index)
		{
			return *(&x + index);
		}
	};
}
