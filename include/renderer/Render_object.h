#ifndef RENDEROBJECT_STRUCT_H
#define RENDEROBJECT_STRUCT_H

#include <renderer/Mesh.h>
#include <renderer/Material.h>
#include <renderer/Transform.h>



struct Render_object {
    Mesh* mesh;
    Material* material;
    Transform transform;
    GLenum draw_type;
};

#endif
