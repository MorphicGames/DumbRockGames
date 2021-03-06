#ifndef _OPENGLRENDERER_H
#define _OPENGLRENDERER_H

#pragma once

#include "AbstractRenderer.h"

namespace DRE
{
	class OpenGLRenderer : public AbstractRenderer
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		void RenderPrimitive(PrimitiveType prim);
	};
}

#endif