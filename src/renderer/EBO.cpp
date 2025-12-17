#include <renderer/EBO.h>

EBO::EBO() {
    glGenBuffers(1, &m_ID);
}

void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Set_indicies(GLuint* indices, size_t size, GLenum draw_usage) {
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, draw_usage);
    Unbind();
}

void EBO::Delete() {
    glDeleteBuffers(1, &m_ID);
}
