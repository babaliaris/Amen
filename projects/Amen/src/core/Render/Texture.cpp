#include "pch.h"
#include "Texture.h"
#include <platform/OpenGL/OpenGLTexture.h>

Amen::Texture::Texture(const std::string& path)
	: m_width(0), m_height(0), m_path(path)
{
}




Amen::Ref<Amen::Texture2D> Amen::Texture2D::Create(const std::string& path)
{
	return Ref<Texture2D>(new OpenGLTexture2D(path));
}





Amen::Texture2D::Texture2D(const std::string& path)
	: Texture(path)
{
}
