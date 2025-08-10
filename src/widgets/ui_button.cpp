#include "My_GUI/widgets/ui_button.hpp"

#include <glad/glad.h>

UIButton::UIButton(BoundingBox boundingBox, glm::vec3 color, Shader& shader)
    : m_boundingBox(boundingBox)
    , m_color(color)
    , m_shader(shader)
{
    float vertices[] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
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

    // bind VBO and EBO to VAO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

UIButton::~UIButton()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void UIButton::draw() const
{
    m_shader.use();
    m_shader.setVec2("uPosition", m_boundingBox.x, m_boundingBox.y);
    m_shader.setVec2("uSize", m_boundingBox.width, m_boundingBox.height);
    m_shader.setVec3("uColor", m_color);

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void UIButton::update(glm::vec2 mousePos, bool isClicked)
{
    isHovered = (mousePos.x >= m_boundingBox.x && mousePos.x <= m_boundingBox.x + m_boundingBox.width &&
                 mousePos.y >= m_boundingBox.y && mousePos.y <= m_boundingBox.y + m_boundingBox.height);
}
