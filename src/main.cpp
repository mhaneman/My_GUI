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
    // Shader textShader = Shader{"./res/shaders/textVert.glsl", "./res/shaders/textFrag.glsl"};

    buttonShader.use();
    buttonShader.setMat4("uProjection", orthoProjection);

    // setup button
    // ------------------------------------------------------------------------------
    glm::vec3 color = glm::vec3{0.655f, 0.475f, 0.851f};

    UIButton button1 = {
        BoundingBox{
            .x = 200.0f,
            .y = 200.0f,
            .width = 100.0f,
            .height = 100.0f
        }, color, buttonShader};

    UIButton button2 = {
        BoundingBox{
            .x = 10.0f,
            .y = 400.0f,
            .width = 50.0f,
            .height = 50.0f
        }, color, buttonShader};

    UIButton button3 = {
        BoundingBox{
            .x = 400.0f,
            .y = 10.0f,
            .width = 200.0f,
            .height = 200.0f
        }, color, buttonShader};

    UIButton button4 = {
        BoundingBox{
            .x = 500.0f,
            .y = 100.0f,
            .width = 200.0f,
            .height = 200.0f
        }, color, buttonShader};

    // setup text
    // ------------------------------------------------------------------------------
    TextRenderer text(window.getWidth(), window.getHeight());
    text.LoadFont("./res/fonts/Roboto_Condensed-Black.ttf", 32);

    while (!window.shouldClose())
    {
        window.startFrame();

        // double xpos, ypos;
        // glfwGetCursorPos(window.getGLFWwindow(), &xpos, &ypos);
        // glm::vec2 mousePos = glm::vec2{xpos, ypos};
        // bool isClicked = glfwGetMouseButton(window.getGLFWwindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

        if (glfwGetKey(window.getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window.getGLFWwindow(), GLFW_KEY_Q) == GLFW_PRESS )
            window.close();

        // draw text
        // ------------------------------------------------------------------------------
        text.RenderText("Hello, OpenGL!", 100.0f, 100.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
        text.RenderText("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", 10.0f, 200.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));

        // draw buttons
        // ------------------------------------------------------------------------------
        button1.draw();
        button2.draw();
        button3.draw();
        button4.draw();

        window.endFrame();

        glfwPollEvents();
    }

    return 0;
}
