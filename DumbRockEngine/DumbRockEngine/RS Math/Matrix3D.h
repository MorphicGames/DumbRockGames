#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Matrix3D
	{
		float a[3][3];

		/*Constructors*/

		inline void Load(float _a11, float _a12, float _a13,
			float _a21, float _a22, float _a23,
			float _a31, float _a32, float _a33)
		{
			a[0][0] = _a11;
			a[0][1] = _a12;
			a[0][2] = _a13;
			a[1][0] = _a21;
			a[1][1] = _a22;
			a[1][2] = _a23;
			a[2][0] = _a31;
			a[2][1] = _a32;
			a[2][2] = _a33;
		}

		inline Matrix3D(float s = (0.0f))
		{
			Load(s, s, s,
				s, s, s,
				s, s, s);
		}

		inline Matrix3D(float _a11, float _a12, float _a13,
			float _a21, float _a22, float _a23,
			float _a31, float _a32, float _a33)
		{
			Load(_a11, _a12, _a13,
				_a21, _a22, _a23,
				_a31, _a32, _a33);
		}

		inline const float Determinant() const
		{
			return (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])) - (a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])) + (a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]));
		}
	};
}
