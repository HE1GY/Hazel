#pragma once
#include "Core.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in Client
	Application* CreateApplication();
}


//Core log macros
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATL(...)	::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Core log macros
#define HZ_WARN(...)		::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATL(...)		::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)



