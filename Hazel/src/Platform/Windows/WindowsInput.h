#pragma once
#include "Hazel/Input.h"

namespace Hazel
{
	class WindowsInput :public Input
	{
	public:	
		virtual bool IsKeyPressedImp(int keycode)override;
		virtual bool IsMouseButtonPressedImp(int button) override;
		virtual float GetMouseXImp() override;
		virtual float GetMouseYImp() override;
		virtual std::pair<float, float> GetMousePositionImp() override;
	};
}