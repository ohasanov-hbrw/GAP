#include "utils.h"
#include "ecs.h"

class Entity;

class Scene{
public:
    Scene();
    ~Scene();

    Entity createEntity();
    virtual void onStep() { };

    std::vector<CyTT::Entity> entities;

public:
    CyTT::ECS m_Ecs;

    friend class Entity;
};