#include "ui_button.hpp"
#include "window.hpp"
#include "shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

int main()
{
    // setup window
    Window window = Window{"My GUI", 800, 800};

    // setup shader
    // ------------------------------------------------------------------------------
    Shader shader = Shader{"./shaders/simpleVert.glsl", "./shaders/simpleFrag.glsl"};

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window.getWidth()), 0.0f, static_cast<float>(window.getHeight()));

    // setup button
    // ------------------------------------------------------------------------------
    BoundingBox box = {
        .x = 500.0f,
        .y = 500.0f,
        .halfWidth = 100.0f,
        .halfHeight = 100.0f
    };
    glm::vec3 color = glm::vec3{0.655f, 0.475f, 0.851f};
    UIButton button = {box, color, shader};

    while (!window.shouldClose())
    {
        window.startFrame();

        if (glfwGetKey(window.getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window.getGLFWwindow(), GLFW_KEY_Q) == GLFW_PRESS )
            window.close();

        double xpos, ypos;
        glfwGetCursorPos(window.getGLFWwindow(), &xpos, &ypos);
        glm::vec2 mousePos = glm::vec2{xpos, ypos};

        // this should probably just be added to the button class
        int projectionLoc = glGetUniformLocation(shader.getProgramID(), "uProjection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        button.draw();
        button.update(mousePos);

        window.endFrame();

        glfwPollEvents();
    }

    return 0;
}
