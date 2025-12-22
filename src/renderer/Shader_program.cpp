#include <renderer/Shader_program.h>

//Default constructor
Shader_program::Shader_program() {}

//Construct an actual shader program with given files and shader types, the file and type should share same index in vector
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

//Get the shader program(ID)
const GLuint& Shader_program::Get_ID() const {
    return m_ID;
}

//Activates the program
void Shader_program::Activate() const {
    glUseProgram(m_ID);
}

//Deactivates the program
void Shader_program::Deactivate() const {
    glUseProgram(0);
}

void Shader_program::Set_vec3(const std::string& name, const glm::vec3& value) const {
    GLint loc = glGetUniformLocation(m_ID, name.c_str());
    glUniform3f(loc, value.r, value.g, value.b);
}

//Deletes the program
void Shader_program::Delete() const {
    glDeleteProgram(m_ID);
}

//Checks for errors when linking shaders
void Shader_program::Compile_errors() const {
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


