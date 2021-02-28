#pragma once

#include "Texture.h"

Texture::Texture()
{}

Texture::Texture(const char* fileName, GLenum t, GLuint u)
{
	    textureUnit = u;

		type = t;

		unsigned char* image = SOIL_load_image(fileName, &width, &height, NULL, SOIL_LOAD_RGBA);

		glGenTextures(1, &id);
		glBindTexture(type, id);

		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		if (image)
		{
			glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(type);
		}
		else
		{
			std::cout << "Error loading texture \n";
		}

		glActiveTexture(0);
		glBindTexture(type, 0);
		SOIL_free_image_data(image);
}

Texture::~Texture()
{
		glDeleteTextures(1, &id);
}

 GLuint Texture::getID() const
{
   return id;
}

void Texture::bind(const GLint texture_unit, unsigned int type)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(type, id);
}

void Texture::unbind()
{
	glActiveTexture(0);
	glBindTexture(type, 0);
}

void Texture::loadFromFile(const char* fileName)
{
		if (id) glDeleteTextures(1, &id);

		unsigned char* image = SOIL_load_image(fileName, &width, &height, NULL, SOIL_LOAD_RGBA);

		glGenTextures(1, &id);
		glBindTexture(type, id);

		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		if (image)
		{
			glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(type);
		}
		else
		{
			std::cout << "Error loading from file \n";
		}

		glActiveTexture(0);
		glBindTexture(type, 0);
		SOIL_free_image_data(image);
}

GLuint Texture::getTextureUnit() const
{
	return textureUnit;
}