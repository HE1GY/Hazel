#pragma once

#include "Events/Event.h"
#include "Core.h"

namespace Hazel
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer") 
			:m_DebugName(name)
		{
		}
		virtual ~Layer() = default;

		virtual void OnAttach(){ }
		virtual void OnDettach(){ }
		virtual void OnUpdate(){ }
		virtual void OnImGuiRender() { }
		virtual void OnEvent(Event& event){ }

		inline const std::string& GetName()const
		{
			return m_DebugName;
		}

	protected:
		std::string m_DebugName;
	};
}