#include "pch.h"
#include "Shader.h"
#include <platform/OpenGL/OpenGLShader.h>


Hazel::Ref<Hazel::Shader> Hazel::Shader::Create(const std::string& filePath)
{
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		return Ref<Shader>(new OpenGLShader(filePath));
	#endif
}
