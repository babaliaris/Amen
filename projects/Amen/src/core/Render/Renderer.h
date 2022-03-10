#pragma once
#include <core/Render/RendererAPI.h>
#include <core/Render/Buffer.h>
#include <core/Render/Shader.h>

namespace Amen
{
	class AMEN_API Renderer
	{
		public:

			static void BeginScene();
			static void EndScene();
			static void Submit(Shader& shader, ArrayBuffer& buffer);
	};
}
