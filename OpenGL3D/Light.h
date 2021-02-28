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

class Light
{
public:

	Light(std::string t, glm::vec3 pos, glm::vec3 a, glm::vec3 d, glm::vec3 s)
	{
		type = t; // parallel or point light
		position = pos;
		ambient = a;
		diffuse = d;
		specular = s;
		transformations = glm::mat4(1.0f);
	}

	void SetTransformations(glm::mat4&  T) { transformations = T; }

	const glm::vec3 GetAmbient() const { return ambient; }

	const glm::vec3 GetDiffuse() const { return diffuse; }

	const glm::vec3 GetSpecular() const { return specular; }

	const glm::vec3 GetPosition() const { return position; }

	const glm::mat4 GetTransformations() const { return transformations; }

	std::string GetType() const { return type; }

private:

	std::string type;
	glm::mat4 transformations;
	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};
