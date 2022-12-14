#pragma once

#include "RendererAPI.h"

namespace Hazel
{
	class RenderCommand
	{
	public:
		inline static void  DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndex(vertexArray);
		}

		inline static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}
		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}