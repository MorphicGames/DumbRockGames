#pragma once

#include "RS_MATH_DEF.h"
#include "Matrix4D.h"

namespace RS_MATH
{
	struct EulerAngle : public Matrix4D
	{
		/*Constructors*/

		inline void Load(float _thetaX, float _thetaY, float _thetaZ)
		{
			a[0][0] = cos(_thetaY * DEG_TO_RAD) * cos(_thetaZ * DEG_TO_RAD);
			a[0][1] = cos(_thetaY * DEG_TO_RAD) * sin(_thetaZ * DEG_TO_RAD);
			a[0][2] = -sin(_thetaY * DEG_TO_RAD);
			a[0][3] = 0;
			a[1][0] = sin(_thetaX * DEG_TO_RAD) * sin(_thetaY * DEG_TO_RAD) * cos(_thetaZ * DEG_TO_RAD) - cos(_thetaX * DEG_TO_RAD) * sin(_thetaZ * DEG_TO_RAD);
			a[1][1] = sin(_thetaX * DEG_TO_RAD) * sin(_thetaY * DEG_TO_RAD) * sin(_thetaZ * DEG_TO_RAD) + cos(_thetaX * DEG_TO_RAD) * cos(_thetaZ * DEG_TO_RAD);
			a[1][2] = sin(_thetaX * DEG_TO_RAD) * cos(_thetaY * DEG_TO_RAD);
			a[1][3] = 0;
			a[2][0] = cos(_thetaX * DEG_TO_RAD) * sin(_thetaY * DEG_TO_RAD) * cos(_thetaZ * DEG_TO_RAD) + sin(_thetaX * DEG_TO_RAD) * sin(_thetaZ * DEG_TO_RAD);
			a[2][1] = cos(_thetaX * DEG_TO_RAD) * sin(_thetaY * DEG_TO_RAD) * sin(_thetaZ * DEG_TO_RAD) - sin(_thetaX * DEG_TO_RAD) * cos(_thetaZ * DEG_TO_RAD);
			a[2][2] = cos(_thetaX * DEG_TO_RAD) * cos(_thetaY * DEG_TO_RAD);
			a[2][3] = 0;
			a[3][0] = 0;
			a[3][1] = 0;
			a[3][2] = 0;
			a[3][3] = 1;
		}

		inline EulerAngle(float _thetaX, float _thetaY, float _thetaZ)
		{
			Load(_thetaX, _thetaY, _thetaZ);
		}

		/*Utilitarian Functions*/

		inline const void Print()
		{
			printf("|%f %f %f %f|\n|%f %f %f %f|\n|%f %f %f %f|\n|%f %f %f %f|\n",
				a[0][0], a[0][1], a[0][2], a[0][3], a[1][0], a[1][1], a[1][2],
				a[1][3], a[2][0], a[2][1], a[2][2], a[2][3], a[3][0], a[3][1],
				a[3][2], a[3][3]);
		}
	};
}
