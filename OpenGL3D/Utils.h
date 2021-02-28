#pragma once

//STD Libs
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

//GLEW
#include<glew.h>

//GLFW
#include<glfw3.h>

//OpenGL Math libs
#include<glm.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

//Own libs
#include"Vertex.h"

class Utils
{
public:

	static std::vector<Vertex> loadModel1(const std::string& file_name);
	static std::vector<Vertex> loadModel2(const std::string& filePath);
	static std::vector<Vertex> loadModel3(const std::string& filePath);
	static std::vector<Vertex> loadModel4(const std::string& filePath);
	static std::string GetFileName(const std::string& filePath);
};