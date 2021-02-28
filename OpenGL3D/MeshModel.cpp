#pragma once

#include "MeshModel.h"

MeshModel::MeshModel(Vertex* vertexArray, const unsigned int& verticesCount,
	glm::vec3  ambient, glm::vec3 diffuse, glm::vec3 specular,
	glm::vec3 pos, glm::vec3 start, glm::vec3 rotate, glm::vec3 scaling) :

	material(ambient, diffuse, specular)
{

	position = pos;

	origin = start;

	rotation = rotate;

	scale = scaling;

	vertices_size = verticesCount;

	vertex_array = new Vertex[vertices_size];

	for (int i = 0; i < vertices_size; i++)
	{
		vertex_array[i] = vertexArray[i];
	}

	//Create vao (vertex array object) and bind it
	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Create vbo (vertex buffer object) bind it, and fill it with the vertices of the mesh that we want to render
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices_size * sizeof(Vertex), vertex_array, GL_STATIC_DRAW);

	//Setting vertex attribute pointers

	// Vertex Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);

	// Vertex Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	// Vertex Texture Coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(2);

	// Vertex Normal
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(3);

	// Unbind our vao
	glBindVertexArray(0);

	ModelMatrixUpdate();
}

MeshModel::~MeshModel()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	delete[] vertex_array;
}

void MeshModel::ModelMatrixUpdate()
{
		Model = glm::mat4(1.0f);
		Model = glm::translate(Model, origin);
	    Model= glm::rotate(Model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		Model = glm::rotate(Model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		Model = glm::rotate(Model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		Model = glm::scale(Model, scale);
}

void MeshModel::setPosition(const glm::vec3 pos)
{
		position = pos;
}

void MeshModel::setOrigin(const glm::vec3 start)
{
		origin = start;
}

void MeshModel::setRotation(const glm::vec3 rotate)
{
		rotation = rotate;
}

void MeshModel::setScale(const glm::vec3 scaling)
{
		scale = scaling;
}

void MeshModel::move(const glm::vec3 p)
{
		origin += p;
}

void MeshModel::rotate(const glm::vec3 r)
{
		rotation += r;
}

void MeshModel::scaleUp(const glm::vec3 s)
{
		scale += s;
}

glm::mat4 MeshModel::GetModelTransformation() const
{
	return Model;
}

unsigned int MeshModel::GetVerticesSize() const
{
	return vertices_size;
}

GLuint MeshModel::GetVAO() const
{
	return vao;
}

GLuint MeshModel::GetVBO() const
{
	return vbo;
}

Material MeshModel::GetMaterial() const
{
	return material;
}
