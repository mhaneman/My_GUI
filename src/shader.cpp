#include "shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

const std::string Shader::loadFrag(const char* filePath)
{

}

const std::string Shader::loadVert(const char* filePath)
{

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
