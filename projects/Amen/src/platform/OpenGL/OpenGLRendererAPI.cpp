#include "pch.h"
#include "OpenGLRendererAPI.h"
#include "glcall.h"
#include <core/logger.h>


Hazel::OpenGLRendererAPI::OpenGLRendererAPI(GLADloadproc proc)
{
	//Try initializing glad.
	AMEN_ASSERT(gladLoadGLLoader(proc) == 1, "Glad failed to initialize.");
}





void Hazel::OpenGLRendererAPI::Init()
{
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}




void Hazel::OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a)
{
	GLCall(glClearColor(r, g, b, a));
}





void Hazel::OpenGLRendererAPI::ClearColorBuffer()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}




void Hazel::OpenGLRendererAPI::SetViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}





void Hazel::OpenGLRendererAPI::DrawIndexed(unsigned int count)
{
	GLCall(glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr));
}
