#include "hzpch.h"
#include "Application.h"
#include "Core.h"

#include "Hazel/Events/ApplicationEvent.h"

#include "Input.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

#include "Renderer/Renderer.h"
#include "Renderer/RenderCommand.h"

namespace Hazel
{

	 Application* Application::s_Instance = nullptr;

	
	Application::Application()
	{
		HZ_CORE_ASSERT(!s_Instance,"Application already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);


		m_VertexArray.reset(VertexArray::Create());

		float vertices[3 * 6] =
		{
			-0.5,-0.5,0.0f, 1,0,0,
			0.5,-0.5,0.0f,  0,1,0,
			0,0.5,0.0f,		0,0,1,
		};

		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		m_VertexBuffer.reset(VertexBuffer::Create(vertices,sizeof(vertices)));

		BufferLayout layout = 
		{
			{ShaderDataType::Float3,"a_Position"},
			{ShaderDataType::Float3,"a_Color"},
		};
		m_VertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		
		unsigned int indices[3] = {0,1,2};

		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		m_IndexBuffer.reset(IndexBuffer::Create(indices,sizeof(indices)));

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
		#version 330 core

		layout(location=0)in vec3 a_Position;
		layout(location=1)in vec3 a_Color;

		out vec3 v_Color;

		void main()
		{
			v_Color=a_Color;
			gl_Position = vec4(a_Position,1.0);
		}
		)";

		std::string fragmentSrc = R"(
		#version 330 core

		layout(location=0)out vec4 color;
		in vec3 v_Color;

		void main()
		{
			color = vec4(v_Color,1.0);
		}
		)";
		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));



		/////////////////////
		{
			m_VertexArrayBox.reset(VertexArray::Create());

			float vertices2[3 * 4] =
			{
				-0.75,-0.75,0.0f,
				0.75,-0.75,0.0f,
				0.75,0.75,0.0f,
				-0.75,0.75,0.0f,
			};

			std::shared_ptr<VertexBuffer> m_VertexBuffer2;
			m_VertexBuffer2.reset(VertexBuffer::Create(vertices2, sizeof(vertices2)));

			BufferLayout layout2 =
			{
				{ShaderDataType::Float3,"a_Position"},
			};
			m_VertexBuffer2->SetLayout(layout2);

			m_VertexArrayBox->AddVertexBuffer(m_VertexBuffer2);


			unsigned int indices2[6] = { 0,1,2,2,3,0 };

			std::shared_ptr<IndexBuffer> m_IndexBuffer2;
			m_IndexBuffer2.reset(IndexBuffer::Create(indices2, sizeof(indices2)));

			m_VertexArrayBox->SetIndexBuffer(m_IndexBuffer2);

			std::string vertexSrc2 = R"(
		#version 330 core

		layout(location=0)in vec3 a_Position;

		void main()
		{
			gl_Position = vec4(a_Position,1.0);
		}
		)";

			std::string fragmentSrc2 = R"(
		#version 330 core

		layout(location=0)out vec4 color;

		void main()
		{
			color = vec4(0.3,0.2,0.8,1.0);
		}
		)";
			m_ShaderBox.reset(new Shader(vertexSrc2, fragmentSrc2));

		}
	}

	Application::~Application()
	{

	}
	

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClosed));

		for(auto it= m_LayerStack.end();it!= m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if(e.Handled)
			{
				break;
			}
		}
	}

	

	void Application::Run()
	{
		while(m_Running)
		{
			RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			RenderCommand::Clear();

			Renderer::BeginScene();

			m_ShaderBox->Bind();
			Renderer::Submit(m_VertexArrayBox);

			m_Shader->Bind();
			Renderer::Submit(m_VertexArray);

			Renderer::EndScene();
			
			for(Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			for(Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();


			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}



	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
}