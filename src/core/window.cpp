#include "My_GUI/core/window.hpp"

#include <iostream>
#include <cstdlib>

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(const char* windowName, const unsigned int width, const unsigned int height) :
    m_width(width), m_height(height), m_windowName(windowName)
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(width, height, windowName, NULL, NULL);

    if (!m_window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGL())
    {
        std::cerr << "Failed to initialize GLAD\n";
        std::exit(EXIT_FAILURE);
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::startFrame() const
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::endFrame() const
{
    glfwSwapBuffers(m_window);
}
