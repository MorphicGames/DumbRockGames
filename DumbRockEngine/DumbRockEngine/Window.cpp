#include "Window.h"

namespace DRE
{
	Window::Window()
	{

	}

	Window::~Window()
	{

	}

	bool Window::Initialize()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			return false;
		}

		return true;
	}

	void Window::Shutdown()
	{

	}

	void Window::ToggleFullscreen()
	{
		
	}

	void Window::SetWindowSize(const int width, const int height)
	{

	}

	int Window::GetWindowWidth() const
	{
		return m_WindowRect.w;
	}

	int Window::GetWindowHeight() const
	{
		return m_WindowRect.h;
	}
}
