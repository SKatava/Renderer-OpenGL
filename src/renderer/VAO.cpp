#include <renderer/VAO.h>

//Generates the VAO
VAO::VAO() {
    glGenVertexArrays(1, &m_ID);
}

//Binds the VAO
void VAO::Bind() const {
    glBindVertexArray(m_ID);
}

//Unbinds the VAO
void VAO::Unbind() const {
    glBindVertexArray(0);
}

//Link the VBO to the VAO
void VAO::Link_VBO(VBO &VBO, GLuint layout, GLint size, GLenum type, size_t space, size_t offset) {
    VBO.Bind();
    glVertexAttribPointer(layout, size, type, GL_FALSE, space * sizeof(GLfloat), (void*)( offset * sizeof(GLfloat)) );
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

//Deletes the VAO
void VAO::Delete() {
    glDeleteVertexArrays(1, &m_ID);
}


