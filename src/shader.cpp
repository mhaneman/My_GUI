#include "shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Shader::loadFrag(const char* filePath)
{
    std::expected fragmentShaderLoad = readFile(filePath);

    if (!fragmentShaderLoad.has_value()) {
        std::cerr << "Failed load Fragment Shader\n";
        // perform some kind of recovery
    }

    const char* fragmentShaderSource = fragmentShaderLoad.value().c_str();

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
}

void Shader::loadVert(const char* filePath)
{
    std::expected vertexShaderLoad = readFile(filePath);

    if (!vertexShaderLoad.has_value()) {
        std::cerr << "Failed to load Vertex Shader\n";
        // perform some kind of recovery
    }

    const char* vertexShaderSource = vertexShaderLoad.value().c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
}

const std::expected<std::string, std::string> Shader::readFile(const char* filePath)
{
    std::ifstream file(filePath);

        if (!file.is_open()) {
            return std::unexpected("Failed to open file");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        return buffer.str();
}

// hate this... just return a boolean
const std::expected<std::string, std::string> checkCompileErrors(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        return std::unexpected("Shader Compilation Failed");
    }

    return "Compiled";

}
