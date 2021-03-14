#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenGL.h"
#include <iostream>
#include "Model/DefaultModels.h"

OpenGL::OpenGL(const float& WindowResolutionX, const float& WindowResolutionY, const std::string& WindowName)
	:m_WindowResolutionX(WindowResolutionX), m_WindowResolutionY(WindowResolutionY),m_WindowName(WindowName)
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
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
}

GLFWwindow* OpenGL::OpenGLCreateWindow() const
{
	return glfwCreateWindow(this->m_WindowResolutionX, this->m_WindowResolutionY, this->m_WindowName.c_str(), NULL, NULL);
}

void OpenGL::OpenGLEnableFunctions() const
{
	glfwSwapInterval(1);//V-sync
	GLCall(glEnable(GL_DEPTH_TEST));//Z-buffer
	//GLCall(glEnable(GL_CULL_FACE));//���޳�
	//glDisable(GL_CULL_FACE);
	//glEnable(GL_FRAMEBUFFER_SRGB);
}
