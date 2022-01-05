#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Gem::Application* Gem::CreateApplication();

int main(int argc, char** agrv)
{
	Gem::Log::Init();
	GE_CORE_WARN("Initialized Log");
	int a = 5;
	GE_INFO("Hello!!! Var={0} ", a);

	auto app = Gem::CreateApplication();
	app->Run();
	delete app;

	return 1;
}

#endif // GE_PLATFORM_WINDOWS
