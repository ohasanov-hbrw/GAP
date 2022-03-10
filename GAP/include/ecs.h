#pragma once

#include <cstdint>
#include <queue>
#include <array>
#include <bitset>
#include <unordered_map>
#include <memory>
#include "utils.h"
#include <iostream>

namespace CyTT{

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 50000;

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 50;

using Signature = std::bitset<MAX_COMPONENTS>;


class EntityManager{
public:
    EntityManager();

    Entity createEntity();
    void destroyEntity(Entity entity);

    void setSignature(Entity entity, Signature signature);
    Signature getSignature(Entity entity);
    
private:
    std::queue<Entity> m_Entities { };
    std::array<Signature, MAX_ENTITIES> m_Signatures { };

    std::uint32_t m_EntityCount { };
};

class IComponentArray{
public:
    IComponentArray() = default;
    virtual ~IComponentArray() = default;
    virtual void entityDestroyed(Entity entity) = 0;
};


template<typename T>
class ComponentArray : public IComponentArray{
public:
    ComponentArray() = default;
    void insertData(Entity entity, T component){
        //GAP_ASSERT(m_EntityToIndexMap.find(entity) == m_EntityToIndexMap.end(), "Component added to same entity more than once");

        std::size_t newIndex = m_Size;

        m_EntityToIndexMap[entity] = newIndex;
        m_IndexToEntityMap[newIndex] = entity;
        m_ComponentArray[newIndex] = component;

        m_Size++;
    }
    
    void removeData(const Entity& entity){
        //GAP_ASSERT(m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end(), "Removing non-existent component");

        std::size_t indexOfRemovedEntity = m_EntityToIndexMap[entity];
        std::size_t indexOfLastElement = m_Size - 1;
        m_ComponentArray[indexOfRemovedEntity] = m_ComponentArray[indexOfLastElement];

        Entity entityOfLastElement = m_IndexToEntityMap[indexOfLastElement];
        m_EntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
        m_IndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

        m_EntityToIndexMap.erase(entity);
        m_IndexToEntityMap.erase(indexOfLastElement);

        m_Size--;
    }

    inline T& getData(const Entity& entity){
        //GAP_ASSERT(m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end(), "Accessing non-existent component");    
        return m_ComponentArray[m_EntityToIndexMap[entity]];
    }
    
    void entityDestroyed(Entity entity) override{
        if (m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end()){
            removeData(entity);
        }
    }

private:
    std::array<T, MAX_ENTITIES> m_ComponentArray;

    std::unordered_map<Entity, std::size_t> m_EntityToIndexMap;
    std::unordered_map<std::size_t, Entity> m_IndexToEntityMap;
    
    std::size_t m_Size;
};

class ComponentManager{
public:
    ComponentManager() = default;
    
    template<typename T>
    inline ComponentType getComponentType(){
        const char* typeName = typeid(T).name();

        //GAP_ASSERT(m_ComponentTypes.find(typeName) != m_ComponentTypes.end(), "Component not registered before use");
        return m_ComponentTypes[typeName];
    }

    template<typename T>
    inline void addComponent(Entity entity, T component){
        const char* typeName = typeid(T).name();
        if (m_ComponentTypes.find(typeName) != m_ComponentTypes.end()){
            getComponentArray<T>()->insertData(entity, component);
        }
        else{
            registerComponent<T>();
            getComponentArray<T>()->insertData(entity, component);
        }
    }

    template<typename T>
    void removeComponent(Entity entity){
        getComponentArray<T>()->removeData(entity);
    }

    template<typename T>
    inline T& getComponent(const Entity& entity){
        return getComponentArray<T>()->getData(entity);
    }

    template<typename T>
    inline bool hasComponent(const Entity& entity){
        const char* typeName = typeid(T).name();
        return !(m_ComponentTypes.find(typeName) == m_ComponentTypes.end());
    }

    void entityDestroyed(Entity entity){
        for(auto const& pair : m_ComponentArrays){
            //pair poop
            auto const& component = pair.second;
            component->entityDestroyed(entity);
        }
    }

private:
    std::unordered_map<const char*, ComponentType> m_ComponentTypes;
    std::unordered_map<const char*, IComponentArray*> m_ComponentArrays;

    ComponentType m_NextComponentType{};

    template<typename T>
    inline ComponentArray<T>* getComponentArray(){
        const char* typeName = typeid(T).name();
        if (m_ComponentTypes.find(typeName) == m_ComponentTypes.end())
            LOG_WARN("null %s", typeName);
        //GAP_ASSERT(m_ComponentTypes.find(typeName) != m_ComponentTypes.end(), "Component not registered before use");
        return static_cast<ComponentArray<T>*>(m_ComponentArrays[typeName]);
    }

    template<typename T>
    void registerComponent(){
        const char* typeName = typeid(T).name();

        //GAP_ASSERT(m_ComponentTypes.find(typeName) == m_ComponentTypes.end(), "Registering component more than once");

        m_ComponentTypes.insert({typeName, m_NextComponentType});
        m_ComponentArrays.insert({typeName, new ComponentArray<T>()});
        m_NextComponentType++;
    }    
};

class ECS{
public:
    ECS();

    Entity createEntity();
    void destroyEntity(Entity entity);

    template<typename T>
    void registerComponent(){
        m_ComponentManager.registerComponent<T>();
    }

    template<typename T>
    inline void addComponent(Entity entity, T component){
        m_ComponentManager.addComponent<T>(entity, component);
        auto signature = m_EntityManager.getSignature(entity);
        signature.set(m_ComponentManager.getComponentType<T>(), true);
        m_EntityManager.setSignature(entity, signature);
    }
    
    template<typename T>
    inline void removeComponent(Entity entity){
        m_ComponentManager.removeComponent<T>(entity);
        auto signature = m_EntityManager.getSignature(entity);
        signature.set(m_ComponentManager.getComponentType<T>(), false);
        m_EntityManager.setSignature(entity, signature);
    }

    template<typename T>
    inline T& getComponent(const Entity& entity){
        return m_ComponentManager.getComponent<T>(entity);
    }

    template<typename T>
    inline bool hasComponent(const Entity& entity){
        return m_ComponentManager.hasComponent<T>(entity);
    }

    template<typename T>
    ComponentType getComponentType(){
        return m_ComponentManager.getComponentType<T>();
    }

    ~ECS(){
        
    }

private:
    ComponentManager m_ComponentManager;
    EntityManager m_EntityManager;
};
}