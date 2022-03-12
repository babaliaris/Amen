#include "pch.h"
#include "Buffer.h"
#include <platform/OpenGL/OpenGLBuffer.h>




Hazel::Ref<Hazel::VertexBuffer> Hazel::VertexBuffer::Create(const float *data, unsigned int size)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<VertexBuffer>(new OpenGLVertexBuffer(data, size));
	#else
		return nullptr;
	#endif
}




void Hazel::VertexBuffer::SetLayout(const BufferLayout& layout)
{
	//Set the layout.
	m_layout = layout;

	//Calculate the stride.
	for (const LayoutElement& element: layout)
	{
		m_stride += GetShaderTypeSize(element.Type);
	}
}




Hazel::Ref<Hazel::IndexBuffer> Hazel::IndexBuffer::Create(unsigned int*data, unsigned int count)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<IndexBuffer>(new OpenGLIndexBuffer(data, count));
	#else
		return nullptr;
	#endif
}




Hazel::IndexBuffer::IndexBuffer(unsigned int count)
	: m_count(count)
{
}




Hazel::ArrayBuffer::ArrayBuffer(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
	: m_vertexBuffer(vertexBuffer), m_indexBuffer(indexBuffer)
{
}




Hazel::Ref<Hazel::ArrayBuffer> Hazel::ArrayBuffer::Create(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<ArrayBuffer>(new OpenGLArrayBuffer(vertexBuffer, indexBuffer));
	#else
		return nullptr;
	#endif
}
