#include <renderer/Renderer.h>

//Constructor - doesn't do anything
Renderer::Renderer() : m_program() {
    std::vector<std::string> files = {"../shaders/default.vert", "../shaders/default.frag"};
    std::vector<Shader_type> types = {Shader_type::VERTEX, Shader_type::FRAGMENT};
    m_program = Shader_program(files, types);

    Vertex v1, v2, v3, v4, v5, v6;
    v1.position = {-0.5f, -0.5f, 1.f};
    v1.texture_pos = {0.f, 0.f};
    v2.position = {0.5f, -0.5f, 1.f};
    v2.texture_pos = {1.f, 0.f};
    v3.position = {-0.5f, 0.5f, 1.f};
    v3.texture_pos = {0.f, 1.f};

    v4.position = {-0.5f, 0.5f, 1.f};
    v4.texture_pos = {0.f, 1.f};
    v5.position = {0.5f, -0.5f, 1.f};
    v5.texture_pos = {1.f, 0.f};
    v6.position = {0.5f, 0.5f, 1.f};
    v6.texture_pos = {1.f, 1.f};

    std::vector<Vertex> vertices = {v1, v2, v3, v4, v5, v6};

    obj.mesh = new Mesh();
    obj.material = new Material;
    
    obj.mesh->Init_vertices(vertices, GL_STATIC_DRAW);
    obj.material->Set_program(&m_program);
    obj.material->Set_color({0.2f, 0.5f, 0.8f});
    Texture texture("../assets/textures/white-granite.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    obj.material->Set_Texture(texture);
    obj.draw_type = GL_TRIANGLES;
}

// Initializes OpenGL and default 
void Renderer::Init() {
    glViewport(0, 0, 800, 800);       
}

//Renders everything in queue
void Renderer::Render() {
    glClearColor(0.f, 0.f, 0.f, 1.f); 
    glClear(GL_COLOR_BUFFER_BIT);
    obj.material->Bind();
    obj.mesh->Bind();
    glDrawArrays(obj.draw_type, 0, obj.mesh->Get_vertices_count());

}

void Renderer::Shutdown() {
    obj.material->Delete();
    obj.mesh->Delete();

    delete obj.mesh;
    delete obj.material;
}
