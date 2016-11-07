#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Ray
	{
		Vec3 o;
		Vec3 d;

		/*Constructors*/

		inline void Load(Vec3 _origin, Vec3 _direction)
		{
			o = _origin;
			d = _direction;
		}

		inline Ray(Vec3 _origin, Vec3 _direction)
		{
			Load(_origin, _direction - _origin);
		}

		/*Utilitarian Functions*/

		inline const void Print()
		{
			printf("r(t) = [%f, %f, %f] + t([%f, %f, %f])\n", o.x, o.y, o.z, d.x, d.y, d.z);
		}
	};
}
