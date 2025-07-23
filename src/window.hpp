#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
  public:
  Window(const char* windowName);
  ~Window();

  GLFWwindow* getGLFWwindow() {return window; };
  bool shouldClose() { return glfwWindowShouldClose(window); };
  void close() { glfwSetWindowShouldClose(window, true); };
  void update();

  private:
  GLFWwindow* window;

};
