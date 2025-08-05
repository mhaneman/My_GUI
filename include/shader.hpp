#pragma once

#include <string>
#include <expected>

#include <glad/glad.h>

class Shader
{
    public:
        Shader(const char* vertPath, const char* fragPath);

        unsigned int getProgramID()
        {
            return shaderProgramID;
        };

        void use()
        {
            glUseProgram(shaderProgramID);
        };

        void setBool(const std::string &name, bool value) const
        {
            glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), (int)value);
        }

        void setInt(const std::string &name, int value) const
        {
            glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), value);
        }

        void setFloat(const std::string &name, float value) const
        {
            glUniform1f(glGetUniformLocation(shaderProgramID, name.c_str()), value);
        }

    private:
        unsigned int shaderProgramID;

        const std::expected<std::string, std::string> readFile(const char* filePath);
        const std::expected<std::string, std::string> checkCompileErrors(unsigned int shader);
};
