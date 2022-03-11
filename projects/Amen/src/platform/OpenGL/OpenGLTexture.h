#pragma once
#include <core/Render/Texture.h>

namespace Amen
{
	class OpenGLTexture2D: public Texture2D
	{
		public:
			OpenGLTexture2D(const std::string& path);
			virtual ~OpenGLTexture2D();
			virtual void Bind(unsigned int slot = 0) override;
			virtual void UnBind() override;

		private:
			unsigned int m_id;
			int m_channels;
	};
}
