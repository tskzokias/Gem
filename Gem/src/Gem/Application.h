#pragma once

#include "Core.h"

namespace Gem
{
	class GEM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT/SANDBOX
	Application* CreateApplication();

}
