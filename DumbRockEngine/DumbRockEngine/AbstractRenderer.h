#ifndef _ABSTRACTRENDERER_H
#define _ABSTRACTRENDERER_H

#pragma once

namespace DRE
{
	class Mesh;
	class Window;

	class AbstractRenderer
	{
	public:
		virtual ~AbstractRenderer() {}

		virtual void SetRenderPrimitive(unsigned int primitive) = 0;

		virtual bool Initialize() = 0;

		virtual void ClearRenderer(Window* window) = 0;

		virtual void RenderMesh(Mesh* renderTarget) = 0;
	};
}

#endif