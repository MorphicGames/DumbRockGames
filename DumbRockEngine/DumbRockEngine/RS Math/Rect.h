#pragma once

#include "RS_MATH_DEF.h"

namespace RS_MATH
{
	struct Rect
	{
		float x, y, w, h;
		Vec2 center;

		/*Constructor*/

		inline Rect(float _x, float _y, float _w, float _h)
		{
			x = _x;
			y = _y;
			w = _w;
			h = _h;
			center = Vec2(x + x + w, y + y + h);
		}

		/*Member Functions*/
		bool Intersects(Rect _rect)
		{
			return (x <= _rect.x + _rect.w && x + w >= _rect.x && y <= _rect.y + _rect.h && y + h >= _rect.y);
		}

	};
}