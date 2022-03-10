#include "ecs.h"
namespace CyTT{
EntityManager::EntityManager() {
    for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
        m_Entities.push(entity);
    }
}

Entity EntityManager::createEntity() {
    //GAP_ASSERT(m_EntityCount < MAX_ENTITIES, "Too many entities");
    
    Entity id = m_Entities.front();
    m_Entities.pop();
    m_EntityCount++;

    return id;
}

void EntityManager::destroyEntity(Entity entity) {
    //GAP_ASSERT(m_EntityCount < MAX_ENTITIES, "Entity out of range");
    
    m_Signatures[entity].reset();
    m_Entities.push(entity);

    m_EntityCount--;
}

void EntityManager::setSignature(Entity entity, Signature signature) {
    //GAP_ASSERT(m_EntityCount < MAX_ENTITIES, "Entity out of range");

    m_Signatures[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity) {
    //GAP_ASSERT(m_EntityCount < MAX_ENTITIES, "Entity out of range");
    
    return m_Signatures[entity];
}

ECS::ECS(){
    /*
      m_ComponentManager = new ComponentManager();
      m_EntityManager = new EntityManager();
    */
}

Entity ECS::createEntity(){
    return m_EntityManager.createEntity();
}

void ECS::destroyEntity(Entity entity){
    m_EntityManager.destroyEntity(entity);
    m_ComponentManager.entityDestroyed(entity);
}
}