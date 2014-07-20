#pragma once

#include <vector>
#include "ComponentTypeId.hpp"
#include "AbstractComponentsStorage.hpp"

using namespace std;

extern vector<AbstractComponentsStorage*> componentVectors;

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
    T component(ComponentTypeId<T> type) {
        return componentVectors[type.getId()][id];
    }

    template <class T>
    T addComponent(ComponentTypeId<T> type) {
        return componentVectors[type.getId()][id];
    }



private:
    size_t id;

};
