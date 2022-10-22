#pragma once
#include "hzpch.h"
#include "Core.h"
#include "Window.h"

#include "Events/Event.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
	};

	//To be defined in Client
	Application* CreateApplication();
}







