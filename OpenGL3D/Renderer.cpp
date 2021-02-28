#pragma once

#include "Renderer.h"

std::string Renderer::loadSource(const char* source_file)
{
		std::ifstream input_file;

		input_file.open(source_file);

		std::string line = "";
		std::string shader_code = "";

		if (input_file.is_open())
		{
			while (std::getline(input_file, line)) shader_code += (line + "\n");
		}
		else
		{
			return "Error Opening File \n";
		}

		input_file.close();

		return shader_code;
}

GLuint Renderer::loadRenderer(GLenum type, const char* source_file)
{
		GLuint renderer = glCreateShader(type);

		std::string source_str = loadSource(source_file);

		const char* source = source_str.c_str();

		glShaderSource(renderer, 1, &source, NULL);

		glCompileShader(renderer);

		GLint success;

		glGetShaderiv(renderer, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			std::cout << "Error Compiling Program \n";
			return -1;
		}

		return renderer;
}

void Renderer::link(GLuint vertexRenderer, GLuint fragmentRenderer)
{
		renderer_id = glCreateProgram();

		glAttachShader(renderer_id, vertexRenderer);

		glAttachShader(renderer_id, fragmentRenderer);

		glLinkProgram(renderer_id);

		GLint success;

		glGetProgramiv(renderer_id, GL_LINK_STATUS, &success);

		if (!success)
		{
			std::cout << "Error linking program \n";
			return;
		}

		glUseProgram(0);
}

Renderer::Renderer(const char* vertexShader, const char* fragmentShader) : active_camera(), active_texture()
{
		GLuint vertexRenderer = loadRenderer(GL_VERTEX_SHADER, vertexShader);

		GLuint fragmentRenderer = loadRenderer(GL_FRAGMENT_SHADER, fragmentShader);

		link(vertexRenderer, fragmentRenderer);

		glDeleteShader(vertexRenderer);

		glDeleteShader(fragmentRenderer);
}

Renderer::~Renderer()
{
	glDeleteProgram(renderer_id);
}

void Renderer::use_renderer()
{
	glUseProgram(renderer_id);
}

void Renderer::unuse_renderer()
{
	glUseProgram(0);
}

void Renderer::setActiveCamera(const Camera& cam)
{
	active_camera = cam;
}

Camera& Renderer::getActiveCamera()
{
	return active_camera;
}

void Renderer::setActiveTexture(const char* source_file, GLenum type, GLuint unit)
{
	Texture temp_texture(source_file, type, unit);

	active_texture = temp_texture;
}

void Renderer::set1int(int value, const char* variable)
{
	glUniform1i(glGetUniformLocation(renderer_id, variable), value);
}

void Renderer::set1float(float value, const char* variable)
{	
	glUniform1f(glGetUniformLocation(renderer_id, variable), value);
}

void Renderer::setVector2f(glm::vec2 value, const char* variable)
{
	glUniform2fv(glGetUniformLocation(renderer_id, variable), 1, glm::value_ptr(value));
}

void Renderer::setVector3f(glm::vec3 value, const char* variable)
{
	glUniform3fv(glGetUniformLocation(renderer_id, variable), 1, glm::value_ptr(value));
}

void Renderer::setVector4f(glm::vec4 value, const char* variable)
{
	glUniform4fv(glGetUniformLocation(renderer_id, variable), 1, glm::value_ptr(value));
}

void Renderer::setMatrix3fv(glm::mat3 value, const char* variable, bool transpose_flag)
{
	glUniformMatrix3fv(glGetUniformLocation(renderer_id, variable), 1, transpose_flag, glm::value_ptr(value));
}

void Renderer::setMatrix4fv(glm::mat4 value, const char* variable, bool transpose_flag)
{
	glUniformMatrix4fv(glGetUniformLocation(this->renderer_id, variable), 1, transpose_flag, glm::value_ptr(value));
}

void Renderer::render(MeshModel& model)
{
        Material mat = model.GetMaterial(); // Get ambient, diffusive and specular material of the mesh

		model.ModelMatrixUpdate(); // Update the model transformation matrix 

		setMatrix4fv(model.GetModelTransformation(), "Model"); // Send the model transformation matrix to the vertex shader

		// Send the material of the mesh to the fragment shader

		setVector3f(mat.GetAmbient(), "material.ambient");
		setVector3f(mat.GetDiffuse(), "material.diffuse");
		setVector3f(mat.GetSpecular(), "material.specular");

		glm::mat4 View = active_camera.getViewMatrix();
		glm::mat4 Projection = active_camera.getProjectionMatrix();

		setMatrix4fv(View, "View");
		setMatrix4fv(Projection, "Projection");

		setVector3f(active_camera.getPosition(), "camera_position");

		use_renderer(); // Call glUseProgram(renderer_id) in order to run this renderer as the current program

		glBindVertexArray(model.GetVAO()); // Get the vertex array object of the mesh and bind it

		// Rendering Properties :

		/*********************************************************************/

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		/*********************************************************************/

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Fill the traingles of the mesh

		glDrawArrays(GL_TRIANGLES, 0, model.GetVerticesSize()); // Finally render the mesh

		glBindVertexArray(0); // Unbind the vertex array object of the mesh

		glUseProgram(0); // Set the current renderer program to NOT be the active program anymore

		glActiveTexture(0);  // Set active texture unit to 0

		glBindTexture(GL_TEXTURE_2D, 0); // Bind current texture 
}

