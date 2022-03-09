#pragma once

namespace Amen
{
	void CleanAllOpenGLErrors();
	void RetrieveAllOpenGLErrors(const char *file, unsigned int line);
}



#ifdef AMEN_DEBUG
	#define GLCall(func) Amen::CleanAllOpenGLErrors(); func; Amen::RetrieveAllOpenGLErrors(__FILE__, __LINE__)

#else
	#define GLCall(func) func

#endif