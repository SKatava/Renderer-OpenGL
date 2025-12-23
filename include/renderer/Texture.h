#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include <renderer/Shader_program.h>

class Texture {
    public:
        Texture();
        Texture(const char* image, GLenum texture_type, GLenum slot, GLenum format, GLenum pixel_type);
        void Texture_unit(Shader_program& program, const char* uniform, GLuint unit);
        void Bind() const;
        void Unbind() const;
        void Delete() const;
    private:
        GLuint m_ID;
        GLenum m_type;
};

#endif
