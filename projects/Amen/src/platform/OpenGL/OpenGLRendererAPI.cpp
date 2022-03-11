#include "pch.h"
#include "OpenGLRendererAPI.h"
#include "glcall.h"
#include <core/logger.h>


Amen::OpenGLRendererAPI::OpenGLRendererAPI(GLADloadproc proc)
{
	//Try initializing glad.
	AMEN_ASSERT(gladLoadGLLoader(proc) == 1, "Glad failed to initialize.");
}





void Amen::OpenGLRendererAPI::Init()
{
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}




void Amen::OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a)
{
	GLCall(glClearColor(r, g, b, a));
}





void Amen::OpenGLRendererAPI::ClearColorBuffer()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}




void Amen::OpenGLRendererAPI::SetViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}





void Amen::OpenGLRendererAPI::DrawIndexed(unsigned int count)
{
	GLCall(glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr));
}
