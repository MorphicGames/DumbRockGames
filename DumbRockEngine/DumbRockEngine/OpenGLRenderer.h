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

		virtual void SetRenderPrimitive(unsigned int primitive);

		virtual bool Initialize();

		virtual void ClearRenderer(Window* window);

		virtual void RenderMesh(Mesh* renderTarget);

	private:
		unsigned int m_RenderPrimitive;
	};
}

#endif