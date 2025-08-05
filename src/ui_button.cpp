#include "ui_button.hpp"

#include <iostream>
#include <glad/glad.h>

UIButton::UIButton(BoundingBox boundingBox, glm::vec3 color, Shader& shader) :
    m_boundingBox(boundingBox), m_color(color), m_shader(shader)
{
    float vertices[] = {
        m_boundingBox.x + m_boundingBox.halfWidth,  m_boundingBox.y + m_boundingBox.halfHeight, 0.0f,   color.x, color.y, color.z,
        m_boundingBox.x + m_boundingBox.halfWidth,  m_boundingBox.y - m_boundingBox.halfHeight, 0.0f,   color.x, color.y, color.z,
        m_boundingBox.x - m_boundingBox.halfWidth,  m_boundingBox.y - m_boundingBox.halfHeight, 0.0f,   color.x, color.y, color.z,
        m_boundingBox.x - m_boundingBox.halfWidth,  m_boundingBox.y + m_boundingBox.halfHeight, 0.0f,   color.x, color.y, color.z,
    };

    unsigned int indices[] = {
        0, 1, 3,  // first triangle
        1, 2, 3   // second triangle
    };

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    // bind vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // bind element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // bind both to the vertex attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

UIButton::~UIButton()
{

}

void UIButton::draw() const
{
    m_shader.use();
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void UIButton::update(glm::vec2 mousePos)
{
    std::cout << mousePos.x << ", " << mousePos.y << "\n";

    isHovered = (mousePos.x >= m_boundingBox.x && mousePos.x <= m_boundingBox.x + m_boundingBox.halfWidth &&
                 mousePos.y >= m_boundingBox.y && mousePos.y <= m_boundingBox.y + m_boundingBox.halfHeight);

    if (isHovered) {
        std::cout << "Is hovering" << "\n";
    }
}
