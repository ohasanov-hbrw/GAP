#include "scene.h"
#include "ecs.h"

class Entity{
public:
    Entity(CyTT::Entity id, Scene* scene);
    Entity(const Entity& other) = default;
    Entity() = default;

    template<typename T>
    bool hasComponent(){
        return m_Scene->m_Ecs.hasComponent<T>(m_Id);
    }

    template<typename T, typename... Args>
    void addComponent(Args&&... args){
        return m_Scene->m_Ecs.addComponent<T>(m_Id, T(std::forward<Args>(args)...));
    }

    template<typename T>
    T& getComponent(){
        return m_Scene->m_Ecs.getComponent<T>(m_Id);
    }

private:
    CyTT::Entity m_Id;
    Scene* m_Scene;
};