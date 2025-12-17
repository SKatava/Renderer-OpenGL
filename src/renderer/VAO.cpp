#include <renderer/VAO.h>

VAO::VAO() {
    glGenVertexArrays(1, &m_ID);
}

void VAO::Bind() {
    glBindVertexArray(m_ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

//Link the buffer to the array object
void VAO::Link_VBO(VBO &VBO, GLuint layout, GLint size, GLenum type, size_t space, size_t offset) {
    VBO.Bind();
    glVertexAttribPointer(layout, size, type, GL_FALSE, space * sizeof(GLfloat), (void*)( offset * sizeof(GLfloat)) );
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &m_ID);
}


