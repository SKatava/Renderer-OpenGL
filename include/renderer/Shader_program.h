#ifndef SHADERPROGRAM_CLASS_H
#define SHADERPROGRAM_CLASS_H

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <vector>

#include <renderer/Shader.h>
#include <renderer/Logger.h>

#include <iostream>

class Shader_program {
    public:
        Shader_program();
        Shader_program(const std::vector<std::string>& files, const std::vector<Shader_type>& types);
        void Activate() const;
        void Deactivate() const;
        void Delete();
        void Compile_errors();
        void Set_vec3(const std::string& name, const glm::vec3& value) const;
    private:
        GLuint m_ID;
};

#endif
