#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

#include <renderer/VAO.h>
#include <renderer/EBO.h>
#include <renderer/Shader_program.h>

class Mesh {
    public:
        Mesh();
        void Draw(const Shader_program& program);
        void Init_vertices(const std::vector<Vertex>& vertices, GLenum draw_usage);
        void Update_vertices(const std::vector<Vertex>& vertices);
        void Delete();
    private:
        VAO m_VAO;
        VBO m_VBO;
        std::vector<Vertex> m_vertices;
        std::vector<GLuint> m_indices;
};

#endif
