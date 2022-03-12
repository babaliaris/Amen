#include "pch.h"
#include <core/logger.h>
#include "GLFWOpenGLContext.h"
#include <GLFW/glfw3.h>


void Hazel::GLFWOpenGLContext::Init()
{
	AMEN_ASSERT(m_window != nullptr, "m_window must not be null at this point.");
	glfwMakeContextCurrent(m_window);
}





void Hazel::GLFWOpenGLContext::SwapBuffers()
{
	AMEN_ASSERT(m_window != nullptr, "m_window must not be null at this point.");
	glfwSwapBuffers(m_window);
}
