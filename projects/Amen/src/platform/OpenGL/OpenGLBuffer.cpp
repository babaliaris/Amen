#include "pch.h"
#include "OpenGLBuffer.h"
#include "glcall.h"
#include <core/logger.h>
#include <glad/glad.h>



GLenum HazelShaderTypeToGLenum(Hazel::ShaderType type);



Hazel::OpenGLVertexBuffer::OpenGLVertexBuffer(const float* data, unsigned int size)
	: m_id(0)
{
	GLCall(glGenBuffers(1, &m_id));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}





Hazel::OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	AMEN_INFO("Calling ~OpenGLVertexBuffer()");
	GLCall(glDeleteBuffers(1, &m_id));
}





void Hazel::OpenGLVertexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}





void Hazel::OpenGLVertexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}





Hazel::OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, unsigned int count)
	: IndexBuffer(count), m_id(0)
{
	GLCall(glGenBuffers(1, &m_id));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, data, GL_STATIC_DRAW));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}





Hazel::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	AMEN_INFO("Calling ~OpenGLIndexBuffer()");
	GLCall(glDeleteBuffers(1, &m_id));
}





void Hazel::OpenGLIndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}





void Hazel::OpenGLIndexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}





Hazel::OpenGLArrayBuffer::OpenGLArrayBuffer(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
	: ArrayBuffer(vertexBuffer, indexBuffer), m_id(0)
{
	GLCall(glGenVertexArrays(1, &m_id));
	GLCall(glBindVertexArray(m_id));

	vertexBuffer->Bind();
	indexBuffer->Bind();

	const BufferLayout& layout = vertexBuffer->GetLayout();

	unsigned int offset = 0;
	unsigned int index	= 0;
	for (const LayoutElement& element: layout)
	{
		GLCall(glVertexAttribPointer(
			index, 
			GetShaderTypeCount(element.Type), 
			HazelShaderTypeToGLenum(element.Type), 
			element.Normalized ? GL_TRUE : GL_FALSE, 
			vertexBuffer->GetStride(),
			(const void *)offset));

		GLCall(glEnableVertexAttribArray(index));

		offset += GetShaderTypeSize(element.Type);
		index++;
	}

	GLCall(glBindVertexArray(0));
	indexBuffer->UnBind();
	vertexBuffer->UnBind();
}





Hazel::OpenGLArrayBuffer::~OpenGLArrayBuffer()
{
	AMEN_INFO("Calling ~OpenGLArrayBuffer()");
	GLCall(glDeleteVertexArrays(1, &m_id));
}





void Hazel::OpenGLArrayBuffer::Bind()
{
	GLCall(glBindVertexArray(m_id));
}





void Hazel::OpenGLArrayBuffer::UnBind()
{
	GLCall(glBindVertexArray(0));
}




GLenum HazelShaderTypeToGLenum(Hazel::ShaderType type)
{
	switch (type)
	{
		case Hazel::ShaderType::NONE:	return GL_NONE;
		case Hazel::ShaderType::BOOL1:	return GL_BOOL;
		case Hazel::ShaderType::BOOL2:	return GL_BOOL;
		case Hazel::ShaderType::BOOL3:	return GL_BOOL;
		case Hazel::ShaderType::BOOL4:	return GL_BOOL;
		case Hazel::ShaderType::INT1:	return GL_INT;
		case Hazel::ShaderType::INT2:	return GL_INT;
		case Hazel::ShaderType::INT3:	return GL_INT;
		case Hazel::ShaderType::INT4:	return GL_INT;
		case Hazel::ShaderType::FLOAT1:	return GL_FLOAT;
		case Hazel::ShaderType::FLOAT2:	return GL_FLOAT;
		case Hazel::ShaderType::FLOAT3:	return GL_FLOAT;
		case Hazel::ShaderType::FLOAT4:	return GL_FLOAT;
		case Hazel::ShaderType::MAT3:	return GL_FLOAT_MAT3;
		case Hazel::ShaderType::MAT4:	return GL_FLOAT_MAT4;

		default:
		{
			AMEN_ASSERT(false, "This line should not be reached...");
			return GL_NONE;
		}
	}
}