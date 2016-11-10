#ifndef _TRANSFORM_HPP
#define _TRANSFORM_HPP

#pragma once

#include "RS Math\RS_Math_Engine.h"

using namespace RS_MATH;

namespace DRE
{
	struct Transform
	{
	public:
		Vec3 position;
		Vec3 rotation;
		Vec3 scale;
	};
}

#endif