#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include <cstddef>

#include <renderer/VBO.h>

class VAO {
    public:
        VAO();
        void Bind();
        void Unbind();
        void Link_VBO(VBO &VBO, GLuint layout, GLint size, GLenum type, size_t space, size_t offset);
        void Delete();
    private:
        GLuint m_ID;

};

#endif
