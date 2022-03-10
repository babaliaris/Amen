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

			virtual void UploadMat(const std::string& uniformName, const glm::mat4& mat) override;

		private:
			unsigned int m_id;
	};
}
