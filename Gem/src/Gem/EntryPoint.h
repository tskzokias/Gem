#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Gem::Application* Gem::CreateApplication();

int main(int argc, char** agrv)
{
	auto app = Gem::CreateApplication();
	app->Run();
	delete app;

	return 1;
}

#endif // GE_PLATFORM_WINDOWS
