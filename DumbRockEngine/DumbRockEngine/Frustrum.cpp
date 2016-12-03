#include "Frustrum.h"

namespace DRE
{
	Frustrum::Frustrum() {

	}

	void Frustrum::CameraChanged(glm::vec3& cameraPosition, glm::vec3& lookAt, glm::vec3& up)
	{
		viewDirection = glm::normalize(cameraPosition - lookAt);

		rightDirection = glm::normalize(glm::cross(up, viewDirection));

		upDirection = glm::cross(viewDirection, rightDirection);

		nearCenter = cameraPosition - (viewDirection * nearDistance);
		farCenter = cameraPosition - (viewDirection * farDistance);

		ntl = nearCenter + upDirection * nearHeight - rightDirection * nearWidth;
		ntr = nearCenter + upDirection * nearHeight + rightDirection * nearWidth;
		nbl = nearCenter - upDirection * nearHeight - rightDirection * nearWidth;
		nbr = nearCenter - upDirection * nearHeight + rightDirection * nearWidth;

		ftl = farCenter + upDirection * farHeight - rightDirection * farWidth;
		ftr = farCenter + upDirection * farHeight + rightDirection * farWidth;
		fbl = farCenter - upDirection * farHeight - rightDirection * farWidth;
		fbr = farCenter - upDirection * farHeight + rightDirection * farWidth;

		planes[TOP_PLANE] = Plane(ntr, ntl, ftl);
		planes[BOTTOM_PLANE] = Plane(nbl, nbr, fbr);
		planes[LEFT_PLANE] = Plane(ntl, nbl, fbl);
		planes[RIGHT_PLANE] = Plane(nbr, ntr, fbr);
		planes[NEAR_PLANE] = Plane(ntl, ntr, nbr);
		planes[FAR_PLANE] = Plane(ftr, ftl, fbl);
	}

	Frustrum::EnclosureType Frustrum::IsInside(glm::vec3& pt)
	{
		for (I32 i = 0; i < 6; i++)
		{
			if (planes[i].SignedDistance(pt) < 0)
			{
				return OUTISDE;
			}
		}
		return INSIDE;
	}

	Frustrum::EnclosureType Frustrum::InInside(glm::vec3& center, F32 radius)
	{
		F32 distance;
		EnclosureType result = INSIDE;

		for (I32 i = 0; i < 6; i++)
		{
			distance = planes[i].SignedDistance(center);

			if (distance < -radius)
			{
				return OUTISDE;
			}
			else if (distance < radius)
			{
				result = OVERLAP;
			}
		}

		return result;
	}
}
