#include <renderer/Renderer.h>


Renderer::Renderer() : m_mesh(), m_program() {
    std::vector<std::string> files = {"../shaders/default.vert", "../shaders/default.frag"};
    std::vector<Shader_type> types = {Shader_type::VERTEX, Shader_type::FRAGMENT};
    m_program = Shader_program(files, types);

    Vertex v1, v2, v3, v4, v5, v6;
    v1.position = {-0.5f, -0.5f, 1.f};
    v1.color = {1.f, 0.f, 0.f};
    v2.position = {0.5f, -0.5f, 1.f};
    v2.color = {0.f, 1.f, 0.f};
    v3.position = {-0.5f, 0.5f, 1.f};
    v3.color = {0.f, 0.f, 1.f};

    v4.position = {-0.5f, 0.5f, 1.f};
    v4.color = {0.f, 0.f, 1.f};
    v5.position = {0.5f, -0.5f, 1.f};
    v5.color = {0.f, 1.f, 0.f};
    v6.position = {0.5f, 0.5f, 1.f};
    v6.color = {1.f, 0.f, 0.f};

    std::vector<Vertex> vertices = {v1, v2, v3, v4, v5, v6};
    m_mesh.Init_vertices(vertices, GL_STATIC_DRAW);

}

void Renderer::Init() {
    glViewport(0, 0, 800, 800);       
}

void Renderer::Render() {
    glClearColor(0.f, 0.f, 0.f, 1.f); 
    glClear(GL_COLOR_BUFFER_BIT);
    m_mesh.Draw(m_program);
}
