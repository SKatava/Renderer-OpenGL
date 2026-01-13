#include <renderer/Transform.h>

Transform::Transform() {}

void Transform::Rotate(float degrees, double duration, glm::vec3 direction) {
    m_transformation = Transformation::ROTATION;
    m_model = glm::rotate(m_model, glm::radians(degrees), direction);
}

void Transform::Scale(float factor, double duration) {
    m_transformation = Transformation::SCALING;
}

void Transform::Apply(Shader_program& program, const char* uniform) {
    glUniformMatrix4fv(glGetUniformLocation(program.Get_ID(), uniform), 1, GL_FALSE, glm::value_ptr(m_model));  
}
