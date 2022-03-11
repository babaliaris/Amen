#include "pch.h"
#include "Buffer.h"
#include <platform/OpenGL/OpenGLBuffer.h>




Amen::Ref<Amen::VertexBuffer> Amen::VertexBuffer::Create(const float *data, unsigned int size)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<VertexBuffer>(new OpenGLVertexBuffer(data, size));
	#else
		return nullptr;
	#endif
}




void Amen::VertexBuffer::SetLayout(const BufferLayout& layout)
{
	//Set the layout.
	m_layout = layout;

	//Calculate the stride.
	for (const LayoutElement& element: layout)
	{
		m_stride += GetShaderTypeSize(element.Type);
	}
}




Amen::Ref<Amen::IndexBuffer> Amen::IndexBuffer::Create(unsigned int*data, unsigned int count)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<IndexBuffer>(new OpenGLIndexBuffer(data, count));
	#else
		return nullptr;
	#endif
}




Amen::IndexBuffer::IndexBuffer(unsigned int count)
	: m_count(count)
{
}




Amen::ArrayBuffer::ArrayBuffer(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
	: m_vertexBuffer(vertexBuffer), m_indexBuffer(indexBuffer)
{
}




Amen::Ref<Amen::ArrayBuffer> Amen::ArrayBuffer::Create(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<ArrayBuffer>(new OpenGLArrayBuffer(vertexBuffer, indexBuffer));
	#else
		return nullptr;
	#endif
}
