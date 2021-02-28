#pragma once

#include "Renderer.h"
#include "Texture.h"
#include "Material.h"
#include "Vertex.h"
#include "MeshModel.h"
#include "Camera.h"
#include "Light.h"

class Scene
{

private:

	std::vector<Renderer> renderers;

	std::vector<Texture> textures;

	std::vector<Material> materials;

	std::vector<MeshModel> models;

	std::vector<Light> lights;

public:

	void AddRenderer(const Renderer& renderer);
	void AddTexture(const Texture& texture);
	void AddMaterial(const Material& material);
	void AddMeshModel(const MeshModel& model);
	void AddLight(const Light& light);
	
};