#pragma once

#include "shader.hpp"
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>

struct BoundingBox {
    float x = 100.0f;
    float y = 100.0f;
    float width = 100.0f;
    float height = 50.0f;
};

class UIButton
{
    public:
        UIButton(BoundingBox boundingBox, glm::vec3 color, Shader& shader);
        ~UIButton();
        void draw() const;
        void update(glm::vec2 mousePos, bool isClicked);

    private:
    BoundingBox m_boundingBox;
    glm::vec3 m_color;
    Shader& m_shader;
    unsigned int m_VBO, m_VAO, m_EBO;

    bool isHovered = false;
    bool isClicked = false;
};
