#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Matrix4D
	{
		float a[4][4];

		/*Constructors*/

		inline void Load(float _a11, float _a12, float _a13, float _a14,
			float _a21, float _a22, float _a23, float _a24,
			float _a31, float _a32, float _a33, float _a34,
			float _a41, float _a42, float _a43, float _a44)
		{
			a[0][0] = _a11;
			a[0][1] = _a12;
			a[0][2] = _a13;
			a[0][3] = _a14;
			a[1][0] = _a21;
			a[1][1] = _a22;
			a[1][2] = _a23;
			a[1][3] = _a24;
			a[2][0] = _a31;
			a[2][1] = _a32;
			a[2][2] = _a33;
			a[2][3] = _a34;
			a[3][0] = _a31;
			a[3][1] = _a32;
			a[3][2] = _a33;
			a[3][3] = _a44;
		}

		inline Matrix4D(float s = (0.0f))
		{
			Load(s, s, s, s,
				s, s, s, s,
				s, s, s, s,
				s, s, s, s);
		}

		inline Matrix4D(float _a11, float _a12, float _a13, float _a14,
			float _a21, float _a22, float _a23, float _a24,
			float _a31, float _a32, float _a33, float _a34,
			float _a41, float _a42, float _a43, float _a44)
		{
			Load(_a11, _a12, _a13, _a14,
				_a21, _a22, _a23, _a24,
				_a31, _a32, _a33, _a34,
				_a41, _a42, _a43, _a44);
		}
	};
}
