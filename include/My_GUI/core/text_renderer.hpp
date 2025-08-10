#pragma once

#include <map>
#include <string>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "shader.hpp"

class TextRenderer {
public:
    TextRenderer(int width, int height);
    ~TextRenderer();

    bool LoadFont(const std::string& fontPath, unsigned int fontSize);
    void RenderText(const std::string& text, float x, float y, float scale, glm::vec3 color);

private:
    struct Character {
        GLuint textureID;
        glm::ivec2 size;
        glm::ivec2 bearing;
        GLuint advance;
    };

    std::map<char, Character> characters;
    GLuint VAO, VBO;
    Shader textShader;
};
