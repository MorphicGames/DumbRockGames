#include "OpenGLRenderer.h"

#include "DRE_typedef.h"
#include "Window.h"

#include "SDL\include\SDL.h"

#include <glew.h>
#include <glut.h>

namespace DRE
{
	OpenGLRenderer::OpenGLRenderer()
	{

	}

	OpenGLRenderer::~OpenGLRenderer()
	{

	}

	void OpenGLRenderer::SetRenderPrimitive(unsigned int primitive)
	{
		this->m_RenderPrimitive = primitive;
	}

	bool OpenGLRenderer::Initialize()
	{
		return true;
	}

	void OpenGLRenderer::ClearRenderer(Window* window)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window->GetSDLWindow());
	}

	void OpenGLRenderer::RenderMesh(Mesh* renderTarget)
	{
		glBegin(m_RenderPrimitive);
	}
}