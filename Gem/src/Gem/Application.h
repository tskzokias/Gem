#pragma once

#include "Core.h"

#include "Window.h"
#include "Gem/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Gem
{
	class GEM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void operator=(Application* app) = delete;
		Application(Application* app) = delete;

		inline static Application& Get()
		{
			return *s_Instance;
		}

		inline Window& GetWindow() 
		{
			return *m_Window;
		}

	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT/SANDBOX
	Application* CreateApplication();

}

