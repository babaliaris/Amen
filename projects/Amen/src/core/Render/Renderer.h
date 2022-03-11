#pragma once
#include <core/Render/RendererAPI.h>
#include <core/Render/Buffer.h>
#include <core/Render/Shader.h>
#include <core/Render/Cameras/Camera.h>

namespace Amen
{
	class AMEN_API Renderer
	{
		public:

			static void BeginScene(Camera& camera);
			static void EndScene();
			static void Submit(Ref<Shader> shader, Ref<ArrayBuffer> buffer);

		private:
			static Camera* s_ActiveCamera;
	};
}
