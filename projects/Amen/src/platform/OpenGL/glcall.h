#pragma once

namespace Hazel
{
	void CleanAllOpenGLErrors();
	void RetrieveAllOpenGLErrors(const char *file, unsigned int line);
}



#ifdef AMEN_DEBUG
	#define GLCall(func) Hazel::CleanAllOpenGLErrors(); func; Hazel::RetrieveAllOpenGLErrors(__FILE__, __LINE__)

#else
	#define GLCall(func) func

#endif