#pragma once

#include <string>
#include <expected>

class Shader
{
    public:
        const std::string loadFrag(const char* filePath);
        const std::string loadVert(const char* filePath);

    private:
    const std::expected<std::string, std::string> readFile(const char* filePath);
};
