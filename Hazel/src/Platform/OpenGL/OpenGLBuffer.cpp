#include "hzpch.h"
#include "OpenGLBuffer.h"
#include "glad/glad.h"

Hazel::OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
{
	glCreateBuffers(1, &m_RendererID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

Hazel::OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void Hazel::OpenGLVertexBuffer::Bind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void Hazel::OpenGLVertexBuffer::UnBind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//IndexBuffer

Hazel::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count):
	m_Count(count)
{
	glCreateBuffers(1, &m_RendererID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
}

Hazel::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void Hazel::OpenGLIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void Hazel::OpenGLIndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32_t Hazel::OpenGLIndexBuffer::GetCount() const
{
	return m_Count;
}
