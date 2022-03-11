#include "pch.h"
#include "Shader.h"
#include <platform/OpenGL/OpenGLShader.h>


Amen::Ref<Amen::Shader> Amen::Shader::Create(const std::string& filePath)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<Shader>(new OpenGLShader(filePath));
	#endif
}
