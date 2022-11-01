#pragma once
#include "Hazel/Layer.h"

namespace Hazel
{
	class HAZEL_API ImGuiLayer :public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach()override;
		void OnDettach()override;
		 void OnImGuiRender()override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;;
	};
}