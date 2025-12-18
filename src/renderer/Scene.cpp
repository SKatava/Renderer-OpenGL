#include <renderer/Scene.h>

const std::vector<Render_object>& Scene::Get_objects() const {
    return m_objects;
}

void Scene::Add_object(const Render_object& object) {
    m_objects.push_back(object);
}
