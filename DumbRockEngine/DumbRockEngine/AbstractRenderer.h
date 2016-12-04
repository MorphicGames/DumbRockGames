#ifndef _ABSTRACTRENDERER_H
#define _ABSTRACTRENDERER_H

#pragma once

#include "DRE_defines.h"

#include "Window.h"

namespace DRE
{
	enum PrimitiveType
	{
		NONE,
		QUADS,
		TRIANGLES
	};

	class AbstractRenderer
	{
	public:
		AbstractRenderer() {}
		virtual ~AbstractRenderer() {}

		virtual void RenderPrimitive(PrimitiveType prim) = 0;

	protected:
		Window* windowRef;
	};
}

#endif