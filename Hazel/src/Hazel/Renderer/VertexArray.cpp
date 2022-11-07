#include "hzpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

Hazel::VertexArray* Hazel::VertexArray::Create()
{
    switch(Renderer::GetAPI())
    {
        case RendererAPI::None:HZ_ASSERT(false, "RendererAPI::None is curretly not supported!");
            break;
        case RendererAPI::OpenGL:
            return new OpenGLVertexArray();
    }
    HZ_ASSERT(false, "Unknown RendereAPI!");
    return nullptr;
}
