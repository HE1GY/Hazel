#include "hzpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"



Hazel::VertexBuffer* Hazel::VertexBuffer::Create(float* vertices, uint32_t size)
{
    switch(Renderer::GetAPI())
    {
        case RendererAPI::None:HZ_ASSERT(false, "RendererAPI::None is curretly not supported!");
            break;
        case RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
    }
    HZ_ASSERT(false, "Unknown RendereAPI!");
    return nullptr;
}


//IndexBuffer
////////////////////////////////////////////////////////////////////////////////////////////



Hazel::IndexBuffer* Hazel::IndexBuffer::Create(uint32_t* indices, uint32_t count)
{
    switch(Renderer::GetAPI())
    {
        case RendererAPI::None:HZ_ASSERT(false, "RendererAPI::None is curretly not supported!");
            break;
        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(indices, count);
    }
    HZ_ASSERT(false, "Unknown RendereAPI!");
    return nullptr;
}
