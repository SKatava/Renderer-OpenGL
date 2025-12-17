#include <renderer/VBO.h>


//Generate the buffer object
VBO::VBO() {
    glGenBuffers(1, &m_ID);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Initialize first data into buffer
void VBO::Init_data(GLfloat* data, size_t size, GLenum draw_usage) {
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), data, draw_usage);
    Unbind();
}

void VBO::Init_data(const std::vector<Vertex>& vertices, GLenum draw_usage) {
    Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), draw_usage);
    Unbind();
}

//Update data of the buffer(no memory allocations)
void VBO::Update_data(GLfloat* data, size_t size, size_t offset) {
    Bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(GLfloat), size * sizeof(GLfloat), data);
    Unbind();
}

void VBO::Update_data(const std::vector<Vertex>& vertices, size_t size, size_t offset) {
    Bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(Vertex), size * sizeof(Vertex), vertices.data());
    Unbind();
}

void VBO::Delete() {
    glDeleteBuffers(1, &m_ID);
}

