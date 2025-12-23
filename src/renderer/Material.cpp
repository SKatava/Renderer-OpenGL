#include <renderer/Material.h>

Material::Material() {}

//Set shader program for material
void Material::Set_program(Shader_program* program) {
    m_program = program;
}

//Set color of the material(not needed if using texture)
void Material::Set_color(const glm::vec3& color) {
    m_color = color;
}

//Set the texture of the object(if texture is set it will be used instead of color)
void Material::Set_Texture(const Texture& texture) {
    m_texture = texture;
}

//Bind the material for usage
void Material::Bind() const{
    m_program->Activate();
    m_program->Set_vec3("u_color", m_color);
    m_texture.Bind(); 
}

//Unbind the material
void Material::Unbind() const{
    m_texture.Unbind();
    m_program->Deactivate();
}

//Delete the material
void Material::Delete() const {
    m_program->Delete();
    m_texture.Delete();
}
