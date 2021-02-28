#pragma once

#include<iostream>
#include<string>

#include<glew.h>
#include<glfw3.h>

#include<SOIL2.h>

class Texture
{

private:
	GLuint id;
	int width;
	int height;
	unsigned int type;
	GLuint textureUnit;

public:

	Texture();
	Texture(const char* fileName, GLenum t, GLuint u);
	~Texture();
	GLuint getID() const;
	void bind(const GLint texture_unit, unsigned int type);
	void unbind();
	void loadFromFile(const char* fileName);
	GLuint getTextureUnit() const;
};