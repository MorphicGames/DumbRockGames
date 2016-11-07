#ifndef _COLOUR_H
#define _COLOUR_H

#pragma once

#include "DRE_typedef.h"

namespace DRE
{
	struct Colour
	{
		friend class Vertex;
	public:
		Colour(F32 r, F32 g, F32 b, F32 a) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

	protected:
		F32 r, g, b, a;
	};
}

#endif