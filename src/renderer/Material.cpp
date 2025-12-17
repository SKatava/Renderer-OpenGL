#include <renderer/Material.h>

//Set shader program for material
void Material::Set_program(Shader_program* program) {
    m_program = program;
}

//Set color of the material(not needed if using texture)
void Material::Set_color(const glm::vec3& color) {
    m_color = color;
}

//Bind the material for usage
void Material::Bind() const{
    m_program->Activate();
    m_program->Set_vec3("u_color", m_color);
}

//Unbind the material
void Material::Unbind() const{
    m_program->Deactivate();
}

//Delete the material
void Material::Delete() const {
    m_program->Delete();
}
