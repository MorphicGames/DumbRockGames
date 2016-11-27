#ifndef _ABSTRACTRENDERER_H
#define _ABSTRACTRENDERER_H

#pragma once

#include "DRE_defines.h"

namespace DRE
{
	struct Colour;

	class Model;
	class Window;

	class ShaderProgram;

	enum RenderEnvironment
	{
		TWO_D,
		THREE_D
	};

	class AbstractRenderer
	{
	public:
		virtual ~AbstractRenderer() {}

		virtual void SetClearColour(Colour* colour) = 0;
		virtual void SetRenderPrimitive(unsigned int primitive) = 0;

		virtual bool Initialize() = 0;

		virtual void ToggleWireframeMode() = 0;
		virtual void ClearRenderer(Window* window) = 0;
		virtual void RenderModel(Model* renderTarget, ShaderProgram program) = 0;
	};
}

#endif