#pragma once
#include <core/Render/RendererAPI.h>
#include <core/Render/Buffer.h>
#include <core/Render/Shader.h>
#include <core/Render/Cameras/Camera.h>

namespace Hazel
{
	class AMEN_API Renderer
	{
		public:

			static void BeginScene(Camera& camera);
			static void EndScene();
			static void Submit(Ref<Shader> shader, Ref<ArrayBuffer> buffer, const glm::mat4& transform = glm::mat4(1.0f));

		private:
			static Camera* s_ActiveCamera;
	};
}
