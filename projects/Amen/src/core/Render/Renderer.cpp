#include "pch.h"
#include "Renderer.h"


Hazel::Camera* Hazel::Renderer::s_ActiveCamera = nullptr;





void Hazel::Renderer::BeginScene(Camera& camera)
{
	s_ActiveCamera = &camera;
}





void Hazel::Renderer::EndScene()
{
}





void Hazel::Renderer::Submit(Ref<Shader> shader, Ref<ArrayBuffer> buffer, const glm::mat4& transform)
{

	shader->UploadMat("u_View", s_ActiveCamera->GetView());
	shader->UploadMat("u_Proj", s_ActiveCamera->GetProj());


	//Upload Model Matrix.
	shader->UploadMat("u_Model", transform);

	shader->Bind();
	buffer->Bind();

	RendererAPI::Get().DrawIndexed(buffer->GetIndexBuffer()->GetCount());

	shader->UnBind();
	buffer->UnBind();
}
