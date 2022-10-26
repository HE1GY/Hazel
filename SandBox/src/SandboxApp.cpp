#include <Hazel.h>

class ExampleLayer :public Hazel::Layer
{
public:
	ExampleLayer():
		Layer("Example")
	{
	}

	void OnUpdate()override 
	{
	}

	void OnEvent(Hazel::Event& event)override
	{
		Hazel::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Hazel::KeyPressedEvent>(HZ_BIND_EVENT_FN(ExampleLayer::OnKeyPressed));
	}

	bool OnKeyPressed(Hazel::KeyPressedEvent& keyPressed)
	{
		HZ_TRACE("{0}",(char)keyPressed.GetKeyCode());
		return false;
	}
};



class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Hazel::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}