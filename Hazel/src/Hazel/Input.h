#pragma once

#include "Core.h"


namespace Hazel
{
	class HAZEL_API Input
	{
	public:
		static bool IsKeyPressed(int keycode)
		{
			return s_Instance->IsKeyPressedImp(keycode);
		};

		static bool IsMouseButtonPressed(int button)
		{
			return s_Instance->IsMouseButtonPressedImp(button);
		};

		static float GetMouseX()
		{
			return s_Instance->GetMouseXImp();
		};
		static float GetMouseY()
		{
			return s_Instance->GetMouseYImp();
		};

		static std::pair<float,float> GetMousePosition()
		{
			return s_Instance->GetMousePositionImp();
		};
	
	protected:
		virtual bool IsKeyPressedImp(int keycode)=0;
		virtual bool IsMouseButtonPressedImp(int button)=0;
		virtual float GetMouseXImp()=0;
		virtual float GetMouseYImp()=0;
		virtual std::pair<float, float> GetMousePositionImp()=0;
	private:
		static Input* s_Instance;
	};
}