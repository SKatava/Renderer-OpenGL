#ifndef RENDEROBJECT_STRUCT_H
#define RENDEROBJECT_STRUCT_H

#include <renderer/Mesh.h>
#include <renderer/Material.h>



struct Render_object {
    Mesh* mesh;
    Material* material;
    glm::mat4 model = glm::mat4(1.0f);
    GLenum draw_type;
};

#endif
