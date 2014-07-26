#pragma once

#include <vector>
#include <deque>

#include "ComponentTypeId.hpp"
#include "AbstractComponentsStorage.hpp"
#include "ComponentsStorage.hpp"


using namespace std;

extern vector<AbstractComponentsStorage*> componentVectors;
extern deque<size_t> unusedEntities;

class Entity
{
public:	
    bool active;
    vector<bool> usedComponentsIds;

    Entity();

    Entity(size_t id, bool active);

    size_t getId() const;

    void destroy();

    template <class T>
    T* component(ComponentTypeId<T> type) {
        ComponentsStorage<T>& componentsStorage = componentVectors[type.getId()];

        return componentsStorage.componentOfEntity(id);
    }

    template <class T>
    T addComponent(ComponentTypeId<T> type) {
        ComponentsStorage<T>& componentsStorage = componentVectors[type.getId()];

        return componentsStorage.addComponentToEntity(id);
    }

    template <class T>
    void removeComponent (ComponentTypeId<T> type) {
        ComponentsStorage<T>& componentsStorage = componentVectors[type.getId()];

        componentsStorage.removeComponentFromEntity(id);
    }

    template <class T>
    bool hasComponent (ComponentTypeId<T> type) {
        ComponentsStorage<T>& componentsStorage = componentVectors[type.getId()];

        return componentsStorage.entityHasComponent(id);
    }

    bool hasComponent(size_t typeId);





private:
    size_t id;

};
