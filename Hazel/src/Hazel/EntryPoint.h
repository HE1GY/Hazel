#pragma once
#include "hzpch.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();


int main(int argc,char** argv)
{
	Hazel::Log::Init();

	HZ_CORE_WARN("Initial Log");
	HZ_CORE_ERROR("Initial Log");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif