#ifndef TRANSFORM_CLASS_H
#define TRANSFORM_CLASS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL 
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

class Transform {
    public:
        Transform();
        void Rotate(float degrees, double duration);
        void Scale(float factor, double duration);
        void Apply();
    private:
        glm::mat4 m_model = glm::mat4(1.0f);
        double m_duration = 0.f;
};

#endif
