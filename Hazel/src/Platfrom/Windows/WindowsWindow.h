#pragma once

#include "Hazel/Window.h"
#include <GLFW/glfw3.h>


namespace Hazel
{

	class WindowsWindow:public Window
	{
	public: 
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate()override;

		inline unsigned int GetHeight()const override
		{
			return m_Data.Height;
		}

		inline unsigned int  GetWidth()const override
		{
			return m_Data.Width;
		}

		inline void SetEventCallback(const EventCallbackFn& callback)override
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enable)override;
		bool IsVSync()const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

		GLFWwindow* m_Window;


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback; //?? how does event work?

		};

		WindowData m_Data;

	};
}


