#pragma once
#include <core/core.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Hazel
{
	class Shader
	{
		public:
			static Ref<Shader> Create(const std::string& filePath);

			inline bool IsValid() const { return m_isValid; }

		public:
			virtual ~Shader() {};
			virtual void Bind() = 0;
			virtual void UnBind() = 0;
			virtual void UploadMat(const std::string& uniformName, const glm::mat4& mat) = 0;
			virtual void UploadInt(const std::string& uniformName, int value) = 0;

		protected:
			bool m_isValid = false;
	};
}
