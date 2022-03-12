#pragma once
#include <core/Render/RendererAPI.h>

namespace Hazel
{
	class RendererCommand
	{
		public:
			inline static void Init()
			{
				RendererAPI::Get().Init();
			}

			inline static void SetClearColor(float r, float g, float b, float a)
			{
				RendererAPI::Get().SetClearColor(r, g, b, a);
			};

			inline static void SetViewport(int x, int y, int width, int height)
			{
				RendererAPI::Get().SetViewport(x, y, width, height);
			}

			inline static void ClearColorBuffer()
			{
				RendererAPI::Get().ClearColorBuffer();
			};

	};
}