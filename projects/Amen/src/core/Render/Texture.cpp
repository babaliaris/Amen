#include "pch.h"
#include "Texture.h"
#include <platform/OpenGL/OpenGLTexture.h>

Hazel::Texture::Texture(const std::string& path)
	: m_width(0), m_height(0), m_path(path)
{
}




Hazel::Ref<Hazel::Texture2D> Hazel::Texture2D::Create(const std::string& path)
{
	return Ref<Texture2D>(new OpenGLTexture2D(path));
}





Hazel::Texture2D::Texture2D(const std::string& path)
	: Texture(path)
{
}
