#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Matrix2D
	{
		float a[2][2];

		/*Constructors*/

		inline void Load(float _a11, float _a12,
			float _a21, float _a22)
		{
			a[0][0] = _a11;
			a[0][0] = _a12;
			a[0][0] = _a21;
			a[0][0] = _a22;
		}

		inline Matrix2D(float s = (0.0f))
		{
			Load(s, s,
				s, s);
		}

		inline Matrix2D(float _a11, float _a12, float _a21, float _a22)
		{
			Load(_a11, _a12,
				_a21, _a22);
		}
	};
}