#pragma once

#include"Material.h"

Material::Material(glm::vec3 a, glm::vec3 d, glm::vec3 s)
{
		ambient = a;
		diffuse = d;
		specular = s;
}

Material::~Material() {}

glm::vec3 Material::GetAmbient() const
{
	return ambient;
}

glm::vec3 Material::GetDiffuse() const
{
	return diffuse;
}

glm::vec3 Material::GetSpecular() const
{
	return specular;
}

