#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>
#include <cstddef>

class EBO {
    public:
        EBO();
        void Set_indicies(GLuint* indices, size_t size, GLenum draw_usage);
        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint m_ID;
};

#endif
