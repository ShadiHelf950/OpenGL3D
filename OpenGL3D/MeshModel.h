#pragma once

#include<iostream>
#include<vector>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc\type_ptr.hpp>

#include"Vertex.h"
#include"Texture.h"
#include"Material.h"

class MeshModel
{
private:

	Vertex* vertex_array;
	unsigned int vertices_size;
	Material material;

	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	glm::vec3 position;
	glm::vec3 origin;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 Model;

public:

	MeshModel(Vertex* vertex_array, const unsigned int& verticesCount,
		 glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 pos = glm::vec3(0.0f),
		 glm::vec3 start = glm::vec3(0.0f,0.0f,0.0f), glm::vec3 rotate = glm::vec3(0.0f),
		 glm::vec3 scaling = glm::vec3(1.0f));

	void ModelMatrixUpdate();

	unsigned int GetVerticesSize() const;

	glm::mat4 GetModelTransformation() const;

	GLuint GetVAO() const;

	GLuint GetVBO() const;

	Material GetMaterial() const;
	
	~MeshModel();

	void setPosition(const glm::vec3 pos);

	void setOrigin(const glm::vec3 start);

	void setRotation(const glm::vec3 rotate);

	void setScale(const glm::vec3 scaling);

	void move(const glm::vec3 p);

	void rotate(const glm::vec3 r);

	void scaleUp(const glm::vec3 s);
};