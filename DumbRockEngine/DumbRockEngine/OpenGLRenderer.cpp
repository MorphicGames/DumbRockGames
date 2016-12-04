#include "OpenGLRenderer.h"

#include "DRE_typedef.h"
#include "Window.h"
#include "LogManager.h"

#include "Model.h"
#include "ShaderProgram.h"

#include "SDL\include\SDL.h"

#include <glew.h>
#include <glut.h>

namespace DRE
{
	OpenGLRenderer::OpenGLRenderer()
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_FRONT);
		glDepthFunc(GL_LESS);
		glDepthMask(GL_TRUE);
		glFrontFace(GL_CCW);
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	}

	OpenGLRenderer::~OpenGLRenderer()
	{

	}

	void OpenGLRenderer::RenderPrimitive(PrimitiveType prim)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
	}
}