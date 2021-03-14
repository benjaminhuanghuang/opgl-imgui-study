#pragma once
#include "Renderer.h"
#include <string>
#include <iostream>
class OpenGL
{
public:
	OpenGL(const float& w,const float& h,const std::string& title);
	~OpenGL();

	void OpenGLInit() const;
	GLFWwindow* OpenGLCreateWindow() const;
	
	static inline void OpenGLAfterProcess(GLFWwindow*& window)
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	inline float GetWindowResolutionX() const { return m_width; }
	inline float GetWindowResolutionY() const { return m_height; }
private:
	float m_width, m_height;
	std::string m_title;
};

