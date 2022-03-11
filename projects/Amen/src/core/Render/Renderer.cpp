#include "pch.h"
#include "Renderer.h"


Amen::Camera* Amen::Renderer::s_ActiveCamera = nullptr;





void Amen::Renderer::BeginScene(Camera& camera)
{
	s_ActiveCamera = &camera;
}





void Amen::Renderer::EndScene()
{
}





void Amen::Renderer::Submit(Ref<Shader> shader, Ref<ArrayBuffer> buffer, const glm::mat4& transform)
{
	//Upload View and Projection matrices.
	if (s_ActiveCamera->GetReason() != Camera::RecalculateReasonE::NONE)
	{
		shader->UploadMat("u_View", s_ActiveCamera->GetView());
		shader->UploadMat("u_Proj", s_ActiveCamera->GetProj());
		s_ActiveCamera->m_reason = Camera::RecalculateReasonE::NONE;
	}

	//Upload Model Matrix.
	shader->UploadMat("u_Model", transform);

	shader->Bind();
	buffer->Bind();

	RendererAPI::Get().DrawIndexed(buffer->GetIndexBuffer()->GetCount());

	shader->UnBind();
	buffer->UnBind();
}
