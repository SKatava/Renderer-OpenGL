#ifndef SHADERPROGRAM_CLASS_H
#define SHADERPROGRAM_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include <renderer/Shader.h>
#include <renderer/Logger.h>

#include <iostream>

class Shader_program {
    public:
        Shader_program();
        Shader_program(const std::vector<std::string>& files, const std::vector<Shader_type>& types);
        const GLuint& Get_ID() const;
        void Activate() const;
        void Deactivate() const;
        void Delete() const;
        void Compile_errors() const;
        void Set_vec3(const std::string& name, const glm::vec3& value) const;
        void Set_mat4(const std::string& name, const glm::mat4& value) const;
    private:
        GLuint m_ID;
};

#endif
