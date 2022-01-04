#include <Gem.h>

class Sandbox : public Gem::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Gem::Application* Gem::CreateApplication()
{
	return new Sandbox();
}