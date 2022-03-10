#pragma once
#include <core/core.h>

namespace Amen
{
	class AMEN_API RendererAPI
	{
		friend class RendererCommand;
		friend class Renderer;

		public:
			inline static RendererAPI& Get() { return *s_instance; }

		protected:
			virtual void SetClearColor(float r, float g, float b, float a) = 0;
			virtual void ClearColorBuffer() = 0;
			virtual void SetViewport(int x, int y, int width, int height) = 0;
			virtual void DrawIndexed(unsigned int count) = 0;


		protected:
			RendererAPI();

		private:
			static RendererAPI* s_instance;
	};
}
