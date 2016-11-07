#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Quaternion
	{
		float x, y, z, w;

		/*Constructors*/

		inline void Load(float _w, float _x, float _y, float _z)
		{
			w = _w;
			x = _x;
			y = _y;
			z = _z;
		}

		inline Quaternion(float s = float(0.0))
		{
			Load(s, s, s, s);
		}

		inline Quaternion(float _w, Vec3 _v)
		{
			Load(_w, _v.x, _v.y, _v.z);
		}

		inline Quaternion(float _w, float _x, float _y, float _z)
		{
			Load(_w, _x, _y, _z);
		}

		inline Quaternion(const Quaternion& _q)
		{
			Load(_q.w, _q.x, _q.y, _q.z);
		}

		/*Operator Overloads*/

		inline const Quaternion operator * (const float s) const
		{
			return Quaternion(w * s, x * s, y * s, z * s);
		}

		inline const Quaternion operator * (const Quaternion _q) const
		{
			return Quaternion(w * _q.w - Vec3(x, y, z).Dot(Vec3(_q.x, _q.y, _q.z)), Vec3(_q.x, _q.y, _q.z) * w + Vec3(x, y, z) * _q.w + Vec3(x, y, z).Cross(Vec3(_q.x, _q.y, _q.z)));
		}

		/*Utilitarian Functions*/

		inline const float Magnitude() const
		{
			return sqrtf(w * w + x * x + y * y + z * z);
		}

		inline const Quaternion Normalize() const
		{
			return Quaternion(w / Magnitude(), x / Magnitude(), y / Magnitude(), z / Magnitude());
		}

		inline const Quaternion Inverse() const
		{
			return Quaternion(w / (Magnitude() * Magnitude()), -x / (Magnitude() * Magnitude()), -y / (Magnitude() * Magnitude()), -z / (Magnitude() * Magnitude()));
		}

		inline const Quaternion Rotate(float _angle, Vec3 _axis) const
		{
			return Quaternion(cos(_angle * DEG_TO_RAD / 2), (_axis / _axis.Magnitude()) * sin(_angle * DEG_TO_RAD / 2));
		}

		inline const void Print()
		{
			printf("q = [%f, %f, %f, %f]\n", w, x, y, z);
		}
	};
}
