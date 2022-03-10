#pragma once
#include <core/Render/RendererAPI.h>

namespace Amen
{
	class RendererCommand
	{
		public:

			inline static void SetClearColor(float r, float g, float b, float a)
			{
				RendererAPI::Get().SetClearColor(r, g, b, a);
			};

			inline static void ClearColorBuffer()
			{
				RendererAPI::Get().ClearColorBuffer();
			};

	};
}