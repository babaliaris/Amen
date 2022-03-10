#include "pch.h"
#include "Renderer.h"

void Amen::Renderer::BeginScene()
{
}





void Amen::Renderer::EndScene()
{
}





void Amen::Renderer::Submit(Shader& shader, ArrayBuffer& buffer)
{
	shader.Bind();
	buffer.Bind();

	RendererAPI::Get().DrawIndexed(buffer.GetIndexBuffer().GetCount());

	shader.UnBind();
	buffer.UnBind();
}
