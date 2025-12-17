#include <renderer/Shader_program.h>

Shader_program::Shader_program() {}

Shader_program::Shader_program(const std::vector<std::string>& files, const std::vector<Shader_type>& types) {
    m_ID = glCreateProgram();
    
    for(size_t i{}; i < files.size(); ++i) {
        Shader shader;

        try {
            shader = Shader(files[i], types[i]); 
        }
        catch(std::string msg) {
            Logger::Log(msg); 
            throw("SHADER_PROGRAM: Can't create the shader program");
        }


        glAttachShader(m_ID, shader.Shader_ID());
        shader.Delete();
    }

    glLinkProgram(m_ID);
    Logger::Log("SHADER_PROGRAM: Shader program created successfuly");
}

void Shader_program::Activate() const {
    glUseProgram(m_ID);
}

void Shader_program::Deactivate() const {
    glUseProgram(0);
}

void Shader_program::Delete() {
    glDeleteProgram(m_ID);
}

void Shader_program::Compile_errors() {
    GLint hasCompiled;
    char infoLog[1024];
    glGetProgramiv(m_ID, GL_LINK_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE)
    {
        glGetProgramInfoLog(m_ID, 1024, NULL, infoLog);
        std::string msg = "SHADER_PROGRAM: Compiling failed, info: ";
        msg.append(infoLog);
        throw(msg);
    }
}


