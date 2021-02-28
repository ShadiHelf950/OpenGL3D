#pragma once

#include"Scene.h"

void Scene::AddRenderer(const Renderer& renderer)
{
	renderers.push_back(renderer);
}

void Scene::AddTexture(const Texture& texture)
{
	textures.push_back(texture);
}

void Scene::AddMaterial(const Material& material)
{
	materials.push_back(material);
}

void Scene::AddMeshModel(const MeshModel& model)
{
	models.push_back(model);
}

void Scene::AddLight(const Light& light)
{
	lights.push_back(light);
}