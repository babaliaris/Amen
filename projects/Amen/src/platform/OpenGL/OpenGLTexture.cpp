#include "pch.h"
#include "OpenGLTexture.h"
#include "glcall.h"
#include <core/logger.h>
#include <glad/glad.h>
#include <stb_image.h>


Amen::OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
	: Texture2D(path), m_id(0), m_channels(0)
{
	//Flip the image on load.
	stbi_set_flip_vertically_on_load(1);

	//Load the image and initialize member variables.
	int width, height;
	stbi_uc* data	= stbi_load(path.c_str(), &width, &height, &m_channels, 0);
	m_width			= width;
	m_height		= height;
	AMEN_ASSERT(data != NULL, "Image[%s] failed to load.", path.c_str());

	//Choose the right external(source) format.
	GLenum src_channels;
	switch (m_channels)
	{
		case 1:
			src_channels = GL_RED;
			break;

		case 2:
			src_channels = GL_RG;
			break;

		case 3:
			src_channels = GL_RGB;
			break;

		case 4:
			src_channels = GL_RGBA;
			break;

		default:
		{
			AMEN_ASSERT(false, "This line should never be reached.")
			src_channels = 0;
			break;
		}
	}

	//Create and Bind the texture.
	GLCall(glGenTextures(1, &m_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_id));

	//Set Filter and Wrapper Options.
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

	//Upload the data.
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, src_channels, GL_UNSIGNED_BYTE, data));

	//Generate Mipmaps.
	GLCall(glGenerateMipmap(GL_TEXTURE_2D));

	//Unbind the Texture.
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	//Free the image from RAM.
	stbi_image_free(data);
}




Amen::OpenGLTexture2D::~OpenGLTexture2D()
{
	AMEN_INFO("Calling ~OpenGLTexture2D()...");
	GLCall(glDeleteTextures(1, &m_id));
}




void Amen::OpenGLTexture2D::Bind(unsigned int slot)
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_id));
}




void Amen::OpenGLTexture2D::UnBind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
