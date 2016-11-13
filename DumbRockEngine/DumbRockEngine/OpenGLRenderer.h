#ifndef _OPENGLRENDERER_H
#define _OPENGLRENDERER_H

#pragma once

#include "AbstractRenderer.h"

#include "Colour.h"

namespace DRE
{
	class OpenGLRenderer : public AbstractRenderer
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		virtual void SetClearColour(Colour* colour);
		virtual void SetRenderPrimitive(unsigned int primitive);

		virtual bool Initialize();

		virtual void ToggleWireframeMode();
		virtual void ClearRenderer(Window* window);
		virtual void RenderMesh(Mesh* renderTarget);
		virtual void RenderModel(Model* renderTarget);

	private:
		bool m_bDrawWireframes;
		unsigned int m_RenderPrimitive;
		Colour* m_pClearColour;
	};
}

#endif