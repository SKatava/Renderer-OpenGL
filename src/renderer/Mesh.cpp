#include <renderer/Mesh.h>

Mesh::Mesh() {
    m_VAO.Bind();
    m_VBO.Bind();

    m_VAO.Link_VBO(m_VBO, 0, 3, GL_FLOAT, 6, 0);
    m_VAO.Link_VBO(m_VBO, 1, 3, GL_FLOAT, 6, 3);

    m_VAO.Unbind();
    m_VBO.Unbind();
}

void Mesh::Init_vertices(const std::vector<Vertex>& vertices, GLenum draw_usage) {
    m_vertices = vertices; 
    m_VBO.Init_data(m_vertices, draw_usage);
}

void Mesh::Update_vertices(const std::vector<Vertex>& vertices) {
    m_VBO.Update_data(vertices, vertices.size(), 0);
}

void Mesh::Draw(const Shader_program& program) {
    program.Activate();
    m_VAO.Bind();
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    m_VAO.Unbind();
}

void Mesh::Delete() {
    m_VAO.Delete();
    m_VBO.Delete();
}
