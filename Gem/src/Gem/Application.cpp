#include "gepch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Gem/Log.h"

#include <GLFW/glfw3.h>

namespace Gem
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		GE_TRACE(e);
		
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}