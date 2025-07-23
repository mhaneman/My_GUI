#include "window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main()
{
    Window window = Window{"My GUI"};

    while (!window.shouldClose())
    {
        if (glfwGetKey(window.getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            window.close();

        window.update();
        glfwPollEvents();
    }

    return 0;
}
