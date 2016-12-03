#ifndef _FRUSTRUM_H
#define _FRUSTRUM_H

#pragma once

#include <glm.hpp>

#include "Plane.h"
#include "DRE_typedef.h"

namespace DRE
{
	class Frustrum
	{
	public:
		enum EnclosureType
		{
			INSIDE,
			OUTISDE,
			OVERLAP
		};

		Frustrum();

		void CameraChanged(glm::vec3& cameraPosition, glm::vec3& lookAt, glm::vec3& up);

		EnclosureType IsInside(glm::vec3& pt);
		EnclosureType InInside(glm::vec3& center, F32 radius);

	protected:
		enum PlaneNames
		{
			NEAR_PLANE,
			FAR_PLANE,
			TOP_PLANE,
			BOTTOM_PLANE,
			RIGHT_PLANE,
			LEFT_PLANE
		};

		F32 ratio;
		F32 angle;
		F32 tangent;
		F32 nearDistance;
		F32 farDistance;
		F32 nearWidth;
		F32 nearHeight;
		F32 farWidth;
		F32 farHeight;

		glm::vec3 cameraPosition;
		glm::vec3 viewDirection;
		glm::vec3 nearCenter;
		glm::vec3 farCenter;
		glm::vec3 upDirection;
		glm::vec3 rightDirection;
		glm::vec3 ntl, nbl, nbr, ntr, ftl, fbl, fbr, ftr;

		Plane planes[6];
	};
}

#endif