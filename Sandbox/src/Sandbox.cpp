#include <Gem.h>

class ExampleLayer : public Gem::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
		GE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Gem::Event& event) override
	{
		GE_TRACE("{0}", event);
	}
};

class Sandbox : public Gem::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Gem::Application* Gem::CreateApplication()
{
	return new Sandbox();
}