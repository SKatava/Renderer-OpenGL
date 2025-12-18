#ifndef SCENE_CLASS_H
#define SCENE_CLASS_H

#include <vector>

#include <renderer/Render_object.h>

class Scene {
    public:
        const std::vector<Render_object>& Get_objects() const;
        void Add_object(const Render_object& object);
    private:
        std::vector<Render_object> m_objects;
};

#endif
