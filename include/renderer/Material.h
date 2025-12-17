#ifndef MATERIAL_CLASS_H
#define MATERIAL_CLASS_H

#include <glm/vec3.hpp>

#include <renderer/Shader_program.h>

class Material {
    public:
        void Set_program(Shader_program* program);
        void Set_color(const glm::vec3& color);
        void Bind() const;
        void Unbind() const;
        void Delete() const;
    private:
        Shader_program* m_program;
        glm::vec3 m_color;
        //Fali texture

};

#endif
