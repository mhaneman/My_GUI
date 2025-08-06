#pragma once

#include <string>
#include <expected>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        unsigned int getProgramID()
        {
            return m_shaderProgramID;
        };

        void use()
        {
            glUseProgram(m_shaderProgramID);
        };

        void setBool(const std::string &name, bool value) const
        {
            glUniform1i(glGetUniformLocation(m_shaderProgramID, name.c_str()), (int)value);
        }

        void setInt(const std::string &name, int value) const
        {
            glUniform1i(glGetUniformLocation(m_shaderProgramID, name.c_str()), value);
        }

        void setFloat(const std::string &name, float value) const
        {
            glUniform1f(glGetUniformLocation(m_shaderProgramID, name.c_str()), value);
        }

        void setVec2(const std::string &name, const glm::vec2 &value) const
        {
            glUniform2fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, &value[0]);
        }
        void setVec2(const std::string &name, float x, float y) const
        {
            glUniform2f(glGetUniformLocation(m_shaderProgramID, name.c_str()), x, y);
        }

        void setVec3(const std::string &name, const glm::vec3 &value) const
        {
            glUniform3fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, &value[0]);
        }
        void setVec3(const std::string &name, float x, float y, float z) const
        {
            glUniform3f(glGetUniformLocation(m_shaderProgramID, name.c_str()), x, y, z);
        }

        void setVec4(const std::string &name, const glm::vec4 &value) const
        {
            glUniform4fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, &value[0]);
        }
        void setVec4(const std::string &name, float x, float y, float z, float w) const
        {
            glUniform4f(glGetUniformLocation(m_shaderProgramID, name.c_str()), x, y, z, w);
        }

        void setMat2(const std::string &name, const glm::mat2 &mat) const
        {
            glUniformMatrix2fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

        void setMat3(const std::string &name, const glm::mat3 &mat) const
        {
            glUniformMatrix3fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

        void setMat4(const std::string &name, const glm::mat4 &mat) const
        {
            glUniformMatrix4fv(glGetUniformLocation(m_shaderProgramID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

    private:
        unsigned int m_shaderProgramID;

        const std::expected<std::string, std::string> readFile(const char* filePath);
        const std::expected<std::string, std::string> checkCompileErrors(unsigned int shader);
};
