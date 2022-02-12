#include "Window.h"
#include <iostream>

void WindowResize(GLFWwindow* window, int width, int height);

Window::Window(const char* name, int width, int height)
{
	m_Title = name;
	m_Width = width;
	m_Height = height;
	Init();
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Update()
{
	glfwSwapBuffers(m_Window);
	glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
	GLCall(glViewport(0, 0, m_Width, m_Height));
	glfwPollEvents();
}



bool Window::Closed() const
{
	return glfwWindowShouldClose(m_Window);
}

/*
void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
*/

void Window::Init()
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to Initialized!" << std::endl;
	}
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		std::cout << "Window Failed to Create!" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowSizeCallback(m_Window, WindowResize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void WindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}