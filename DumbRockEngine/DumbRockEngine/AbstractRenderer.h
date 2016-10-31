#ifndef _ABSTRACTRENDERER_H
#define _ABSTRACTRENDERER_H

#pragma once

class Mesh;

namespace DRE
{
	class AbstractRenderer
	{
	public:
		AbstractRenderer() {

		}
		virtual ~AbstractRenderer() = 0;

		virtual void SetRenderPrimitive() = 0;

		virtual bool Initialize() = 0;
		virtual void RenderMesh(Mesh* renderTarget) = 0;
	};
}

#endif