#include "entity.h"

Scene::Scene(){

}

Scene::~Scene(){

}

Entity Scene::createEntity(){
    CyTT::Entity id = m_Ecs.createEntity();
    entities.push_back(id);
    Entity entity(id, this);
    return entity;
}