#pragma once

#include"Utils.h"

std::vector<Vertex> Utils::loadModel1(const std::string& file_name)
{
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texcoords;
	std::vector<glm::vec3> normals;

	std::vector<int> position_indicies;
	std::vector<int> texcoord_indicies;
	std::vector<int> normal_indicies;

	std::vector<Vertex> vertices;

	std::stringstream ss;
	std::ifstream object_file(file_name.c_str());
	std::string line = "";
	std::string start = "";
	glm::vec3 vector3D;
	glm::vec2 vector2D;
	int number = 0;

	if (!object_file.is_open()) throw "Error Opening OBJ file";

	while (std::getline(object_file, line))
	{
		ss.clear();
		ss.str(line);
		ss >> start;

        if (start == "v")
		{
			ss >> vector3D.x >> vector3D.y >> vector3D.z;
			positions.push_back(vector3D);
		}

		else if (start == "vt")
		{
			ss >> vector2D.x >> vector2D.y;
			texcoords.push_back(vector2D);
		}

		else if (start == "vn")
		{
			ss >> vector3D.x >> vector3D.y >> vector3D.z;
			normals.push_back(vector3D);
		}

		else if (start == "f")
		{
			int counter = 0;

			while (ss >> number)
			{
				if (counter == 0)
				{
					position_indicies.push_back(number);
				}

				else if (counter == 1)
				{
					texcoord_indicies.push_back(number);
				}

				else if (counter == 2)
				{
					normal_indicies.push_back(number);
				}

				if (ss.peek() == '/')
				{
					++counter;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					++counter;
					ss.ignore(1, ' ');
				}
				else if (ss.peek() == '//')
				{
					++counter;
					ss.ignore(1, '//');
				}

				if (counter > 2) counter = 0;
			}
		}
		else
		{

		}
	}

	vertices.resize(position_indicies.size(), Vertex());

	for (size_t i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = positions[position_indicies[i] - 1];

		vertices[i].texcoord = texcoords[texcoord_indicies[i] - 1];

		vertices[i].normal = normals[normal_indicies[i] - 1];

		vertices[i].color = glm::vec3(0.8f, 0.8f, 0.8f);
	}

	return vertices;
}


std::vector<Vertex> Utils::loadModel2(const std::string& filePath)
{
	std::string line;
	std::string delimiter1 = " ";
	std::string delimiter2 = "//";
	std::string token;
	size_t pos = 0;
	size_t temp_pos = 0;
	size_t temp_pos1 = 0;

	std::string coordinates;
	std::string face_coords;
	std::string pair;

	std::string x;
	std::string y;
	std::string z;

	std::string v1;
	std::string v2;
	std::string v3;

	std::string n1;
	std::string n2;
	std::string n3;

	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;

	std::vector<Vertex> output;

	std::ifstream object(filePath.c_str());

	while (std::getline(object, line))
	{
		    pos = line.std::string::find(delimiter1);

			token = line.std::string::substr(0, pos);

			if (token._Equal("v"))
			{
				coordinates = line.substr(token.length() + 1, line.length() - token.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				x = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(x.length() + 1, coordinates.length() - x.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				y = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(y.length() + 1, coordinates.length() - y.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				z = coordinates.substr(0, temp_pos);

				glm::vec3 V = glm::vec3(std::stof(x), std::stof(y), std::stof(z));

				vertices_.push_back(V);
			}

			if (token._Equal("vn"))
			{
				coordinates = line.substr(token.length() + 1, line.length() - token.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				x = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(x.length() + 1, coordinates.length() - x.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				y = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(y.length() + 1, coordinates.length() - y.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				z = coordinates.substr(0, temp_pos);

				glm::vec3 VN = glm::vec3(std::stof(x), std::stof(y), std::stof(z));

				normals_.push_back(VN);
			}

			if (token._Equal("f"))
			{
				if (GetFileName(filePath)._Equal("beetle.obj") || GetFileName(filePath)._Equal("body.obj"))
				{
					face_coords = line.substr(token.length() + 1, line.length() - token.length());
				}

				else
				{
					face_coords = line.substr(token.length() + 2, line.length() - token.length());
				}

				temp_pos = face_coords.std::string::find(delimiter1);
				pair = face_coords.substr(0, temp_pos);

				temp_pos1 = pair.std::string::find(delimiter2);

					v1 = pair.substr(0, temp_pos1);
					n1 = pair.substr(temp_pos1 + 2, pair.length() - temp_pos1 - 2);

					face_coords = face_coords.substr(pair.length() + 1, face_coords.length() - pair.length());
					temp_pos = face_coords.std::string::find(delimiter1);
					pair = face_coords.substr(0, temp_pos);
					temp_pos1 = pair.std::string::find(delimiter2);

					v2 = pair.substr(0, temp_pos1);
					n2 = pair.substr(temp_pos1 + 2, pair.length() - temp_pos1 - 2);

					face_coords = face_coords.substr(pair.length() + 1, face_coords.length() - pair.length());
					temp_pos = face_coords.std::string::find(delimiter1);
					pair = face_coords.substr(0, temp_pos);
					temp_pos1 = pair.std::string::find(delimiter2);

					v3 = pair.substr(0, temp_pos1);
					n3 = pair.substr(temp_pos1 + 2, pair.length() - temp_pos1 - 2);

					Vertex t1,t2,t3;

					t1.position = vertices_[std::stoi(v1) - 1];
					t1.normal = normals_[std::stoi(n1) - 1];
					t1.texcoord = glm::vec2(8.0f, 8.0f);
					t1.color = glm::vec3(1.0f, 1.0f, 1.0f);

					t2.position = vertices_[std::stoi(v2) - 1];
					t2.normal = normals_[std::stoi(n2) - 1];
					t2.texcoord = glm::vec2(8.0f, 8.0f);
					t2.color = glm::vec3(1.0f, 1.0f, 1.0f);

					t3.position = vertices_[std::stoi(v3) - 1];
					t3.normal = normals_[std::stoi(n3) - 1];
					t3.texcoord = glm::vec2(8.0f, 8.0f);
					t3.color = glm::vec3(1.0f, 1.0f, 1.0f);

					output.push_back(t1);
					output.push_back(t2);
					output.push_back(t3);
			}
	}

	return output;
}

std::vector<Vertex> Utils::loadModel3(const std::string& filePath)
{
	std::string line;
	std::string delimiter1 = " ";
	std::string delimiter2 = "//";
	std::string token;
	size_t pos = 0;
	size_t temp_pos = 0;
	size_t temp_pos1 = 0;

	std::string coordinates;
	std::string face_coords;
	std::string res;

	std::string x;
	std::string y;
	std::string z;

	std::string v1;
	std::string v2;
	std::string v3;

	std::vector<glm::vec3> vertices_;

	std::vector<Vertex> output;

	std::ifstream object(filePath.c_str());

	while (std::getline(object, line))
	{
		pos = line.std::string::find(delimiter1);

		token = line.std::string::substr(0, pos);

		if (token._Equal("v"))
		{
			coordinates = line.substr(token.length() + 1, line.length() - token.length());
			temp_pos = coordinates.std::string::find(delimiter1);

			x = coordinates.substr(0, temp_pos);

			coordinates = coordinates.substr(x.length() + 1, coordinates.length() - x.length());
			temp_pos = coordinates.std::string::find(delimiter1);

			y = coordinates.substr(0, temp_pos);

			coordinates = coordinates.substr(y.length() + 1, coordinates.length() - y.length());
			temp_pos = coordinates.std::string::find(delimiter1);

			z = coordinates.substr(0, temp_pos);

			glm::vec3 V = glm::vec3(std::stof(x), std::stof(y), std::stof(z));

			vertices_.push_back(V);
		}

		if (token._Equal("f"))
		{
			face_coords = line.substr(token.length() + 1, line.length() - token.length());

			std::stringstream ss(face_coords);
			std::string item;
		    std::vector<std::string> tokens;

			while (std::getline(ss, item, ' '))
			{
				tokens.push_back(item);
			}

			v1 = tokens[0];
			v2 = tokens[1];
			v3 = tokens[2];

			Vertex t1, t2, t3;

			t1.position = vertices_[std::stoi(v1) - 1];
			t1.normal = glm::vec3(1.0f, 1.0f, 1.0f);
			t1.texcoord = glm::vec2(1.0f, 1.0f);
			t1.color = glm::vec3(1.0f, 1.0f, 1.0f);

			t2.position = vertices_[std::stoi(v2) - 1];
			t2.normal = glm::vec3(1.0f, 1.0f, 1.0f);
			t2.texcoord = glm::vec2(1.0f, 1.0f);
			t2.color = glm::vec3(1.0f, 1.0f, 1.0f);

			t3.position = vertices_[std::stoi(v3) - 1];
			t3.normal = glm::vec3(1.0f, 1.0f, 1.0f);
			t3.texcoord = glm::vec2(1.0f, 1.0f);
			t3.color = glm::vec3(1.0f, 1.0f, 1.0f);

			output.push_back(t1);
			output.push_back(t2);
			output.push_back(t3);
		}
	}

	return output;
}

std::vector<Vertex> Utils::loadModel4(const std::string& filePath)
{
	std::string line;
	std::string delimiter1 = " ";
	std::string delimiter2 = "/";
	std::string token;
	size_t pos = 0;
	size_t temp_pos = 0;
	size_t temp_pos1 = 0;

	std::string coordinates;
	std::string face_coords;
	std::string pair;

	std::string x;
	std::string y;
	std::string z;

	std::string v1;
	std::string v2;
	std::string v3;

	std::string t1;
	std::string t2;
	std::string t3;

	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec2> textures_;

	std::vector<Vertex> output;

	std::ifstream object(filePath.c_str());

	while (std::getline(object, line))
	{
		    pos = line.std::string::find(delimiter1);

			token = line.std::string::substr(0, pos);

			if (token._Equal("v"))
			{
				coordinates = line.substr(token.length() + 1, line.length() - token.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				x = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(x.length() + 1, coordinates.length() - x.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				y = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(y.length() + 1, coordinates.length() - y.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				z = coordinates.substr(0, temp_pos);

				glm::vec3 V = glm::vec3(std::stof(x), std::stof(y), std::stof(z));

				vertices_.push_back(V);
			}

			if (token._Equal("vt"))
			{
				coordinates = line.substr(token.length() + 1, line.length() - token.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				x = coordinates.substr(0, temp_pos);

				coordinates = coordinates.substr(x.length() + 1, coordinates.length() - x.length());
				temp_pos = coordinates.std::string::find(delimiter1);

				y = coordinates.substr(0, temp_pos);

				glm::vec2 VT = glm::vec2(std::stof(x), std::stof(y));

				textures_.push_back(VT);
			}

			if (token._Equal("f"))
			{
				face_coords = line.substr(token.length() + 1, line.length() - token.length());
				temp_pos = face_coords.std::string::find(delimiter1);
				pair = face_coords.substr(0, temp_pos);

				temp_pos1 = pair.std::string::find(delimiter2);

					v1 = pair.substr(0, temp_pos1);
					t1 = pair.substr(temp_pos1 + 1, pair.length() - temp_pos1 - 1);

					face_coords = face_coords.substr(pair.length() + 1, face_coords.length() - pair.length());
					temp_pos = face_coords.std::string::find(delimiter1);
					pair = face_coords.substr(0, temp_pos);
					temp_pos1 = pair.std::string::find(delimiter2);

					v2 = pair.substr(0, temp_pos1);
					t2 = pair.substr(temp_pos1 + 1, pair.length() - temp_pos1 - 1);

					face_coords = face_coords.substr(pair.length() + 1, face_coords.length() - pair.length());
					temp_pos = face_coords.std::string::find(delimiter1);
					pair = face_coords.substr(0, temp_pos);
					temp_pos1 = pair.std::string::find(delimiter2);

					v3 = pair.substr(0, temp_pos1);
					t3 = pair.substr(temp_pos1 + 1, pair.length() - temp_pos1 - 1);

					Vertex q1,q2,q3;

					q1.position = vertices_[std::stoi(v1) - 1];
					q1.normal = glm::vec3(1.0f, 1.0f, 1.0f);
					q1.texcoord = textures_[std::stoi(t1) - 1];
					q1.color = glm::vec3(1.0f, 1.0f, 1.0f);

					q2.position = vertices_[std::stoi(v2) - 1];
					q2.normal = glm::vec3(1.0f, 1.0f, 1.0f);
					q2.texcoord = textures_[std::stoi(t2) - 1];
					q2.color = glm::vec3(1.0f, 1.0f, 1.0f);

					q3.position = vertices_[std::stoi(v3) - 1];
					q3.normal = glm::vec3(1.0f, 1.0f, 1.0f);
					q3.texcoord = textures_[std::stoi(t3) - 1];
					q3.color = glm::vec3(1.0f, 1.0f, 1.0f);

					output.push_back(q1);
					output.push_back(q2);
					output.push_back(q3);
			}
	}

	return output;
}

std::string Utils::GetFileName(const std::string& filePath)
{
	if (filePath.empty()) {
		return {};
	}

	auto len = filePath.length();
	auto index = filePath.find_last_of("/\\");

	if (index == std::string::npos) {
		return filePath;
	}

	if (index + 1 >= len) {

		len--;
		index = filePath.substr(0, len).find_last_of("/\\");

		if (len == 0) {
			return filePath;
		}

		if (index == 0) {
			return filePath.substr(1, len - 1);
		}

		if (index == std::string::npos) {
			return filePath.substr(0, len);
		}

		return filePath.substr(index + 1, len - index - 1);
	}

	return filePath.substr(index + 1, len - index);
}
