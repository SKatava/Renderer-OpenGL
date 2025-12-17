#ifndef RENDEROBJECT_STRUCT_H
#define RENDEROBJECT_STRUCT_H

#include <renderer/Mesh.h>
#include <renderer/Material.h>

struct Render_object {
    Mesh* mesh;
    Material* material;
    GLenum draw_type;
};

#endif
