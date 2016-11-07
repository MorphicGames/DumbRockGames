#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Plane
	{
		float a, b, c, d;

		/*Constructors*/

		inline void Load(float _a, float _b, float _c, float _d)
		{
			a = _a;
			b = _b;
			c = _c;
			d = _d;
		}

		inline Plane(float _s = float(0.0))
		{
			Load(_s, _s, _s, _s);
		}

		inline Plane(float _a, float _b, float _c, float _d)
		{
			Load(_a, _b, _c, _d);
		}

		inline Plane(const Plane& _p)
		{
			Load(_p.a, _p.b, _p.c, _p.d);
		}

		inline Plane(Vec3 _n, Vec3 _o)
		{
			Load(_n.x, _n.y, _n.z, _n.x * -_o.x + _n.y * -_o.y + _n.z * -_o.z);
		}

		inline Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2)
		{
			Vec3 a = v1 - v0;
			Vec3 b = v2 - v0;
			Vec3 n = a.Cross(b);
			Plane(n, v0);
		}

		/*Utilitarian Functions*/

		inline const Plane Normalize()
		{
			return Plane(a / Magnitude(), b / Magnitude(), c / Magnitude(), d / Magnitude());
		}

		inline const float Magnitude()
		{
			return sqrtf(a * a + b * b + c * c);
		}

		inline const void Print()
		{
			printf("p = %fx + %fy + %fz + %f\n", a, b, c, d);
		}
	};
}

