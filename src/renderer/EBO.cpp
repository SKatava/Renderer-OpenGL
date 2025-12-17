#include <renderer/EBO.h>

//Generates the EBO
EBO::EBO() {
    glGenBuffers(1, &m_ID);
}

//Binds the EBO
void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

//Unbinds the EBO
void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Sets the EBO's data
void EBO::Set_indices(GLuint* indices, size_t size, GLenum draw_usage) {
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, draw_usage);
    Unbind();
}

//Deletes the EBO
void EBO::Delete() {
    glDeleteBuffers(1, &m_ID);
}
