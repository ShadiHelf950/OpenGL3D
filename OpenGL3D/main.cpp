#include "Scene.h"
#include "Utils.h"

int main()
{

	glfwInit();

	int viewport_width = 1920;
	int viewport_height = 1080;

	GLFWwindow* window = glfwCreateWindow(viewport_width, viewport_height, "MeshViewer", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error in GLEW intitiallizing" << "\n";
		glfwTerminate();
	}

	Renderer renderer = Renderer("vshader.glsl", "fshader.glsl");

	Camera cam = Camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	cam.setPerspectiveMatrix(30.0f, 0.1, 1000, viewport_width, viewport_height);

	Light light = Light("Point", glm::vec3(1.0f, 1.3f, 20000.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f)
		               , glm::vec3(0.1f, 0.1f, 0.1f));

	std::vector<Vertex> vertices = Utils::loadModel1("Data/goku.obj");

	Vertex* vertexArray = new Vertex[vertices.size()];

	for (size_t i = 0; i < vertices.size(); i++)
	{
		vertexArray[i].position = vertices[i].position;
		vertexArray[i].normal = vertices[i].normal;
		vertexArray[i].color = vertices[i].color;
		vertexArray[i].texcoord = vertices[i].texcoord;
	}

	MeshModel model = MeshModel(vertexArray, vertices.size(),
		glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f));

	Texture texture_0 = Texture("Images/goku.jpg", GL_TEXTURE_2D, 0);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.2f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		renderer.use_renderer();

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			model.move(glm::vec3(0.0f, 0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			model.move(glm::vec3(0.0f, -0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			model.move(glm::vec3(-0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			model.move(glm::vec3(0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		{
			model.scaleUp(glm::vec3(-0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			model.scaleUp(glm::vec3(0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		{
			model.scaleUp(glm::vec3(0.0f, 0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		{
			model.scaleUp(glm::vec3(0.0f, -0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(0.0f, 0.0f, -0.01f));
		}

		if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(0.0f, 0.0f, 0.01f));
		}

		if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(0.0f, -0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(0.0f, 0.01f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(-0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		{
			model.rotate(glm::vec3(0.01f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			cam.move(glm::vec3(0.01f, 0.0f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			cam.move(glm::vec3(-0.01f, 0.0f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			cam.move(glm::vec3(0.0f, 0.01f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		{
			cam.move(glm::vec3(0.0f, -0.01f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		{
			cam.move(glm::vec3(0.0f, 0.0f, 0.01f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		{
			cam.move(glm::vec3(0.0f, 0.0f, -0.01f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(0.01f, 0.0f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(-0.01f, 0.0f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(0.0f, 0.01f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(0.0f, -0.01f, 0.0f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(0.0f, 0.0f, 0.01f));
			renderer.setActiveCamera(cam);
		}

		if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
		{
			cam.spin(glm::vec3(0.0f, 0.0f, -0.01f));
			renderer.setActiveCamera(cam);
		}

		renderer.setVector3f(light.GetPosition(), "light_position");
		renderer.setVector3f(light.GetAmbient(), "light_ambient");
		renderer.setVector3f(light.GetDiffuse(), "light_diffusive");
		renderer.setVector3f(light.GetSpecular(), "light_specular");

		texture_0.bind(texture_0.getTextureUnit(), GL_TEXTURE_2D);

		renderer.render(model);

		glfwSwapBuffers(window);
		glFlush();

		glBindVertexArray(0);
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		renderer.unuse_renderer();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}