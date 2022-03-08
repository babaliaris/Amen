#pragma once
#include <core/Render/Renderer.h>
#include <glad/glad.h>

namespace Amen
{
	class OpenGLRenderer: public Renderer
	{
		public:
			OpenGLRenderer(GLADloadproc proc);

		public:
			virtual void SetClearColor(float r, float g, float b, float a) override;
			virtual void ClearColorBuffer() override;
	};
}
