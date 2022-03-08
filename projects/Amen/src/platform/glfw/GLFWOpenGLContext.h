#pragma once
#include <core/Render/GraphicsContext.h>

struct GLFWwindow;

namespace Amen
{
	class GLFWOpenGLContext: public GraphicsContext
	{
		public:
			virtual void Init() override;
			virtual void SwapBuffers() override;

			inline void SetWindow(GLFWwindow* window) { m_window = window; }

	private:
		GLFWwindow* m_window = nullptr;
	};
}
