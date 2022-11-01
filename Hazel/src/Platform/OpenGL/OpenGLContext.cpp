#include "hzpch.h"
#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
	Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void Hazel::OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize GL");

		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO(" Vendor: {0}",glGetString(GL_VENDOR));
		HZ_CORE_INFO(" Renderer: {0}",glGetString(GL_RENDERER));
		HZ_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void Hazel::OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
