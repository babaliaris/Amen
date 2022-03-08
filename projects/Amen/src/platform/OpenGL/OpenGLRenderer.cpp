#include "pch.h"
#include "OpenGLRenderer.h"
#include <core/logger.h>


Amen::OpenGLRenderer::OpenGLRenderer(GLADloadproc proc)
{
	//Try initializing glad.
	AMEN_ASSERT(gladLoadGLLoader(proc) == 1, "Glad failed to initialize.");
}





void Amen::OpenGLRenderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Amen::OpenGLRenderer::ClearColorBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
