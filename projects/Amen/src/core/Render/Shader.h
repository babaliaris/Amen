#pragma once
#include <string>

namespace Amen
{
	class Shader
	{
		public:
			static Shader *Create(const std::string& filePath);

			inline bool IsValid() const { return m_isValid; }

		public:
			virtual ~Shader() {};
			virtual void Bind() = 0;
			virtual void UnBind() = 0;

		protected:
			bool m_isValid = false;
	};
}
