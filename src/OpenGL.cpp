#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenGL.h"
#include <iostream>
#include "Model/DefaultModels.h"

OpenGL::OpenGL(const float &w, const float &h, const std::string &title)
		: m_width(w), m_height(h), m_title(title)
{
}

OpenGL::~OpenGL()
{
	glfwTerminate();
}

void OpenGL::OpenGLInit() const
{
	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);					 // For Mac
}

GLFWwindow *OpenGL::OpenGLCreateWindow() const
{
	GLFWwindow *window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to Create Window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!gladLoadGL() )
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}

	//  Enable features
	glfwSwapInterval(1);		 //V-sync
	glEnable(GL_DEPTH_TEST); //glab enable Z-buffer
													 //GLCall(glEnable(GL_CULL_FACE));
													 //glDisable(GL_CULL_FACE);
													 //glEnable(GL_FRAMEBUFFER_SRGB);
	return window;
}
