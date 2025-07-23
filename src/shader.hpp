#pragma once

#include <string>
#include <expected>

class Shader
{
    public:
        void loadFrag(const char* filePath);
        void loadVert(const char* filePath);

    private:
        const std::expected<std::string, std::string> readFile(const char* filePath);
        const std::expected<std::string, std::string> checkCompileErrors(unsigned int shader);
};
