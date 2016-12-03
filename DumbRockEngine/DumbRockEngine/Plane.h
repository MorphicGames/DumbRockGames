#ifndef _PLANE_H
#define _PLANE_H

#pragma once

#include <glm.hpp>

#include "DRE_typedef.h"

namespace DRE
{
	class Plane
	{
	private:
		glm::vec3 point;
		F32  a, b, c, d;

	public:
		Plane();
		Plane(F32 a, F32 b, F32 c, F32 d, glm::vec3& point);
		Plane(glm::vec3& pointA, glm::vec3& pointB, glm::vec3& pointC);

		glm::vec3 GetNormal() const;
		F32 GetDistance() const;
		F32 SignedDistance(glm::vec3& point);

		Plane& operator=(const Plane &other);
		friend bool operator==(const Plane& a, const Plane& b);
		friend bool operator!=(const Plane& a, const Plane& b);
	};
}

#endif