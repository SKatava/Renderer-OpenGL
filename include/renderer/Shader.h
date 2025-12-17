#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>

#include <renderer/Logger.h>

enum class Shader_type {
    VERTEX,
    FRAGMENT,
    COMPUTE
};

class Shader {
    public:
        Shader();
        Shader(const std::string& shader_file, Shader_type type);
        std::string Get_file_content(const std::string& file);
        void Compile_errors();
        GLuint Shader_ID();
        void Delete();
    private:
        GLuint m_ID;
        Shader_type m_type;
};

#endif
