#pragma once

#include<iostream>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec3.hpp>
#include<mat4x4.hpp>
#include<gtc\matrix_transform.hpp>

class Camera
{

private:

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::mat4 view;
	glm::mat4 projection;

public:

	Camera();

	Camera(glm::vec3 Position, glm::vec3 Front, glm::vec3 Up);
	
	~Camera();

	void setOrthographicMatrix(float left, float right, float bottom, float top);

	void setPerspectiveMatrix(float fovy, float near, float far, float width, float height);

	glm::vec3 getPosition() const;

	glm::mat4 getViewMatrix() const;

	glm::mat4 getProjectionMatrix() const;

	void setPosition(glm::vec3 Position);

	void setFront(glm::vec3 Front);

	void setUp(glm::vec3 Up);

	void move(glm::vec3 shift);

	void spin(glm::vec3 rotation);

};