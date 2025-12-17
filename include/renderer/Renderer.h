#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <glad/glad.h>
#include <vector>

#include <renderer/Shader_program.h>
#include <renderer/Mesh.h>


class Renderer {
    public:
        Renderer();
        void Init();
        void Render();
        void Clear();
    private:
        Mesh m_mesh;
        Shader_program m_program;
};

#endif
