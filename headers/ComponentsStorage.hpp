#pragma once

#include "AbstractComponentsStorage.hpp"
#include <vector>
#include "Component.hpp"

template<class T>
class ComponentsStorage : AbstractComponentsStorage {
public:
    void destroyEntity (size_t id) {
        Component& component = components[id];
        component.active = false;
    }

private:
    vector<T> components;

};
