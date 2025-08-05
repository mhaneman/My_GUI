#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
  public:
  Window(const char* windowName, const unsigned int width, const unsigned int height);
  ~Window();

  GLFWwindow* getGLFWwindow() { return m_window; };
  unsigned int getWidth() { return m_width; };
  unsigned int getHeight() { return m_height; };

  bool shouldClose() { return glfwWindowShouldClose(m_window); };
  void close() { glfwSetWindowShouldClose(m_window, true); };

  void startFrame() const;
  void endFrame() const;

  private:
  GLFWwindow* m_window;
  const char* m_windowName;
  unsigned int m_width, m_height;

};
