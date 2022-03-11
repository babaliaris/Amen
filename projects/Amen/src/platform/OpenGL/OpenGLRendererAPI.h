#pragma once
#include <core/Render/RendererAPI.h>
#include <glad/glad.h>

namespace Amen
{
	class OpenGLRendererAPI: public RendererAPI
	{
		public:
			OpenGLRendererAPI(GLADloadproc proc);

		public:
			virtual void Init() override;
			virtual void SetClearColor(float r, float g, float b, float a) override;
			virtual void ClearColorBuffer() override;
			virtual void SetViewport(int x, int y, int width, int height) override;
			virtual void DrawIndexed(unsigned int count) override;
	};
}
