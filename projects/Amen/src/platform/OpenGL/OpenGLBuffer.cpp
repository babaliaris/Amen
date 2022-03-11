#include "pch.h"
#include "OpenGLBuffer.h"
#include "glcall.h"
#include <core/logger.h>
#include <glad/glad.h>



GLenum AmenShaderTypeToGLenum(Amen::ShaderType type);



Amen::OpenGLVertexBuffer::OpenGLVertexBuffer(const float* data, unsigned int size)
	: m_id(0)
{
	GLCall(glGenBuffers(1, &m_id));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}





Amen::OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	AMEN_INFO("Calling ~OpenGLVertexBuffer()");
	GLCall(glDeleteBuffers(1, &m_id));
}





void Amen::OpenGLVertexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}





void Amen::OpenGLVertexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}





Amen::OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, unsigned int count)
	: IndexBuffer(count), m_id(0)
{
	GLCall(glGenBuffers(1, &m_id));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, data, GL_STATIC_DRAW));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}





Amen::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	AMEN_INFO("Calling ~OpenGLIndexBuffer()");
	GLCall(glDeleteBuffers(1, &m_id));
}





void Amen::OpenGLIndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}





void Amen::OpenGLIndexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}





Amen::OpenGLArrayBuffer::OpenGLArrayBuffer(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
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
			AmenShaderTypeToGLenum(element.Type), 
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





Amen::OpenGLArrayBuffer::~OpenGLArrayBuffer()
{
	AMEN_INFO("Calling ~OpenGLArrayBuffer()");
	GLCall(glDeleteVertexArrays(1, &m_id));
}





void Amen::OpenGLArrayBuffer::Bind()
{
	GLCall(glBindVertexArray(m_id));
}





void Amen::OpenGLArrayBuffer::UnBind()
{
	GLCall(glBindVertexArray(0));
}




GLenum AmenShaderTypeToGLenum(Amen::ShaderType type)
{
	switch (type)
	{
		case Amen::ShaderType::NONE:	return GL_NONE;
		case Amen::ShaderType::BOOL1:	return GL_BOOL;
		case Amen::ShaderType::BOOL2:	return GL_BOOL;
		case Amen::ShaderType::BOOL3:	return GL_BOOL;
		case Amen::ShaderType::BOOL4:	return GL_BOOL;
		case Amen::ShaderType::INT1:	return GL_INT;
		case Amen::ShaderType::INT2:	return GL_INT;
		case Amen::ShaderType::INT3:	return GL_INT;
		case Amen::ShaderType::INT4:	return GL_INT;
		case Amen::ShaderType::FLOAT1:	return GL_FLOAT;
		case Amen::ShaderType::FLOAT2:	return GL_FLOAT;
		case Amen::ShaderType::FLOAT3:	return GL_FLOAT;
		case Amen::ShaderType::FLOAT4:	return GL_FLOAT;
		case Amen::ShaderType::MAT3:	return GL_FLOAT_MAT3;
		case Amen::ShaderType::MAT4:	return GL_FLOAT_MAT4;

		default:
		{
			AMEN_ASSERT(false, "This line should not be reached...");
			return GL_NONE;
		}
	}
}