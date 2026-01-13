#include <renderer/Camera.h>

//Default constructor
Camera::Camera() {}

//Constructor for initializing default values
Camera::Camera(int width, int height, glm::vec3 position) {
    m_width = width;
    m_height = height;
    m_position = position;
}   

//Calculating and passing the matrix to the deisred shader
void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader_program& program, const char* uniform) {
    /*This is just for testing, needed rotation to test depth buffer
    static float rotation = 0.f;
    rotation += 0.5f;
    glm::mat4 model = glm::mat4(1.0f);
    */

    glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

    //model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 1.0f, 1.0f));
	view = glm::lookAt(m_position, m_position + m_orientation, m_up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)m_width / m_height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(program.Get_ID(), uniform), 1, GL_FALSE, glm::value_ptr(projection * view));    
}

