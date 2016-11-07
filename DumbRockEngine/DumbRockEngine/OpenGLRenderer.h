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
		virtual ~OpenGLRenderer();

		virtual void SetRenderPrimitive();

		virtual bool Initialize();
		virtual void RenderMesh(Mesh* renderTarget);

	private:
		unsigned char m_RenderPrimitive;
	};
}

#endif