#pragma once
#include <core/Render/Shader.h>

namespace Amen
{
	class OpenGLShader:public Shader
	{
		public:
			OpenGLShader(const std::string& filePath);
			~OpenGLShader();
			virtual void Bind() override;
			virtual void UnBind() override;

		private:
			unsigned int m_id;
	};
}
