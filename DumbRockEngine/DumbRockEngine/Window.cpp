#include "Window.h"

#include <glew.h>

namespace DRE
{
	Window::Window(const char* windowTitle)
	{
		this->m_WindowTitle = windowTitle;
		this->m_WindowRect = new SDL_Rect();
	}

	Window::~Window()
	{
		Shutdown();
	}

	bool Window::Initialize()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		m_pSDLWindow = SDL_CreateWindow(m_WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowRect->w, m_WindowRect->h, SDL_WINDOW_OPENGL);
		if (!m_pSDLWindow)
		{
			Shutdown();
			return false;
		}

		m_SDLContext = SDL_GL_CreateContext(m_pSDLWindow);

		SetOpenGLAttributes();

		SDL_GL_SetSwapInterval(1);

#ifndef __APPLE__
		glewExperimental = GL_TRUE;
		glewInit();
#endif

		return true;
	}

	void Window::Shutdown()
	{
		SDL_GL_DeleteContext(m_SDLContext);

		SDL_DestroyWindow(m_pSDLWindow);

		delete m_WindowRect;
		m_WindowRect = nullptr;
	}

	void Window::ToggleFullscreen()
	{
		
	}

	void Window::SetWindowSize(const int width, const int height)
	{
		m_WindowRect->w = width;
		m_WindowRect->h = height;
	}

	int Window::GetWindowWidth() const
	{
		return m_WindowRect->w;
	}

	int Window::GetWindowHeight() const
	{
		return m_WindowRect->h;
	}

	SDL_Window* Window::GetSDLWindow() const
	{
		return m_pSDLWindow;
	}

	void Window::SetOpenGLAttributes()
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	}
}
