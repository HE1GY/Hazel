#pragma once
#include <string>

namespace Hazel
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& frameSrc);
		~Shader();

		void Bind();
		void UnBind();
	private:
		uint32_t m_RendererID;
	};
}