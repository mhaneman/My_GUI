#pragma once

#include "shader.hpp"
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>

struct BoundingBox {
    float x = 0.1f;
    float y = 0.1f;
    float halfWidth = 0.2f;
    float halfHeight = 0.1f;
};

class UIButton
{
    public:
        UIButton(BoundingBox boundingBox, glm::vec3 color, Shader& shader);
        ~UIButton();
        void draw() const;
        void update(glm::vec2 mousePos);

    private:
    BoundingBox m_boundingBox;
    glm::vec3 m_color;
    Shader& m_shader;
    unsigned int m_VBO, m_VAO, m_EBO;

    bool isHovered = false;
    bool isClicked = false;
};
