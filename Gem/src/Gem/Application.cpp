#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Gem/Log.h"

namespace Gem
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		GE_TRACE(e);

		while (true);
	}
}