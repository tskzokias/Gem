#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Gem/Window.h"

namespace Gem
{
	class GEM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT/SANDBOX
	Application* CreateApplication();

}

