#pragma once

#include<iostream>
#include<fstream>
#include<string>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc\type_ptr.hpp>

#include "MeshModel.h"
#include "Camera.h"
#include "Texture.h"

class Renderer
{
private:

	GLuint renderer_id;
	Camera active_camera;
	Texture active_texture;

private:

	std::string loadSource(const char* source_file);
	GLuint loadRenderer(GLenum type, const char*  source_file);
	void link(GLuint vertexRenderer, GLuint fragmentRenderer);
	

public:

	Renderer(const char* vertexShader, const char* fragmentShader);
	~Renderer();

	void use_renderer();
	void unuse_renderer();
	void render(MeshModel& model);


	void setActiveCamera(const Camera& cam);

	Camera& getActiveCamera();

	void setActiveTexture(const char* source_file, GLenum type, GLuint unit);

	void set1int(int value, const char* variable);

	void set1float(float value, const char* variable);

	void setVector2f(glm::vec2 value, const char* variable);

	void setVector3f(glm::vec3 value, const char* variable);

	void setVector4f(glm::vec4 value, const char* variable);

	void setMatrix3fv(glm::mat3 value, const char* variable, bool transpose_flag = GL_FALSE);

	void setMatrix4fv(glm::mat4 value, const char* variable, bool transpose_flag = GL_FALSE);
};