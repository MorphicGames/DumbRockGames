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
		m_bDrawWireframes = false;
		m_RenderPrimitive = NULL;
		m_pClearColour = nullptr;
	}

	OpenGLRenderer::~OpenGLRenderer()
	{
		P_DELETE(m_pClearColour);
	}

	void OpenGLRenderer::SetClearColour(Colour* colour)
	{
		this->m_pClearColour = colour;
	}

	void OpenGLRenderer::SetRenderPrimitive(unsigned int primitive)
	{
		this->m_RenderPrimitive = primitive;
	}

	void OpenGLRenderer::ToggleWireframeMode()
	{
		m_bDrawWireframes = !m_bDrawWireframes;
		if (m_bDrawWireframes) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	}

	bool OpenGLRenderer::Initialize()
	{
		if (!m_RenderPrimitive) {
			m_RenderPrimitive = GL_TRIANGLES;
		}

		if (!m_pClearColour) {
			m_pClearColour = new Colour(0.0f, 0.0f, 0.0f, 1.0f);
		}

		return true;
	}

	void OpenGLRenderer::ClearRenderer(Window* window)
	{
		glClearColor(m_pClearColour->r, m_pClearColour->g, m_pClearColour->b, m_pClearColour->a);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window->GetSDLWindow());
	}

	void OpenGLRenderer::RenderMesh(Mesh* renderTarget)
	{
		glBegin(m_RenderPrimitive);

		glEnd();
	}

	void OpenGLRenderer::RenderModel(Model* renderTarget)
	{
		glBegin(m_RenderPrimitive);

		glEnd();
	}
}