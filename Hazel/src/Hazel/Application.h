#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Hazel/ImGui/ImGuiLayer.h"
#include "Renderer/Shader.h"

#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"


namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static inline Application& Get()
		{
			return *s_Instance;
		}

		 inline Window& GetWindow()
		{
			return *m_Window;
		}

	private:
		static Application* s_Instance;

		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window>m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_ShaderBox;
		std::shared_ptr<VertexArray> m_VertexArrayBox;
	};

	//To be defined in Client
	Application* CreateApplication();
}







