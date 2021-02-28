#pragma once

#include "Camera.h"

Camera::Camera()
{}

Camera::Camera(glm::vec3 Position, glm::vec3 Front, glm::vec3 Up)
{
	up = Up;
	position = Position;
	front = Front;
	view = glm::lookAt(position, position + front, up);
}

Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix() const
{
	return view;
}

glm::mat4 Camera::getProjectionMatrix() const
{
	return projection;
}

void Camera::setOrthographicMatrix(float left, float right, float bottom, float top)
{
	projection = glm::ortho(left, right, bottom, top);
}

void Camera::setPerspectiveMatrix(float fovy, float near, float far, float width, float height) 
{
	projection = glm::perspective(glm::radians(fovy), static_cast<float>(width) / static_cast<float>(height), near, far);
}

glm::vec3 Camera::getPosition() const
{
		return position;
}

void Camera::setPosition(glm::vec3 Position)
{
	position = Position;
	view = glm::lookAt(position, position + front, up);
}

void Camera::setFront(glm::vec3 Front)
{
	front = Front;
	view = glm::lookAt(position, position + front, up);
}

void Camera::setUp(glm::vec3 Up)
{
	up = Up;
	view = glm::lookAt(position, position + front, up);
}

void Camera::move(glm::vec3 shift)
{
	position += shift;
	view = glm::lookAt(position, position + front, up);
}

void Camera::spin(glm::vec3 rotation)
{
	glm::vec4 position_homogenous = glm::vec4(position, 1.0);

	glm::mat4 T = glm::mat4(1.0);

    T = glm::rotate(T, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
	T = glm::rotate(T, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
	T = glm::rotate(T, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));

	position_homogenous = T * position_homogenous;

	position = glm::vec3(position_homogenous.x, position_homogenous.y, position_homogenous.z);

	view = glm::lookAt(position, position + front, up);
}
