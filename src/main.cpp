#include "ui_button.hpp"
#include "window.hpp"
#include "shader.hpp"
#include "text_renderer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
    // setup window
    // ------------------------------------------------------------------------------
    Window window = Window{"My GUI", 800, 800};
    glm::mat4 orthoProjection = glm::ortho(0.0f, static_cast<float>(window.getWidth()), static_cast<float>(window.getHeight()), 0.0f);

    // setup shader
    // ------------------------------------------------------------------------------
    Shader buttonShader = Shader{"./res/shaders/buttonVert.glsl", "./res/shaders/buttonFrag.glsl"};

    // setup button
    // ------------------------------------------------------------------------------
    BoundingBox box = {
        .x = 200.0f,
        .y = 200.0f,
        .width = 100.0f,
        .height = 50.0f
    };
    glm::vec3 color = glm::vec3{0.655f, 0.475f, 0.851f};
    UIButton button = {box, color, buttonShader};

    // setup text
    // ------------------------------------------------------------------------------
    TextRenderer text(window.getWidth(), window.getHeight());
    text.LoadFont("./res/fonts/Roboto_Condensed-Black.ttf", 64);

    while (!window.shouldClose())
    {
        window.startFrame();
        text.RenderText("Hello, My GUI!!!", 10.0f, 10.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));

        if (glfwGetKey(window.getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window.getGLFWwindow(), GLFW_KEY_Q) == GLFW_PRESS )
            window.close();

        double xpos, ypos;
        glfwGetCursorPos(window.getGLFWwindow(), &xpos, &ypos);
        glm::vec2 mousePos = glm::vec2{xpos, ypos};
        bool isClicked = glfwGetMouseButton(window.getGLFWwindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;


        buttonShader.setMat4("uProjection", orthoProjection);
        button.draw();
        button.update(mousePos, isClicked);

        window.endFrame();

        glfwPollEvents();
    }

    return 0;
}
