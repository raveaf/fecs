#pragma once

#include "AbstractComponentsStorage.hpp"
#include <vector>
#include "Component.hpp"
#include "functions.hpp"

template<class T>
class ComponentsStorage : AbstractComponentsStorage {
public:
    void removeComponentFromEntity (size_t entityId) {
        Component& component =  components[entityId];
        component.active = false;
        component.reset();
    }

    bool entityHasComponent (std::size_t entityId) {

        if (components.size() > entityId) {
            Component& component =  components[entityId];
            return component.active;
        } else {
            return false;
        }
    }

    T* componentOfEntity (size_t entityId) {
        if ( ! entityHasComponent(entityId) ) {
            return nullptr;
        }

        ensureSizeOfVector(components, entityId - 1);
        Component& component =  components[entityId];

        return component;

    }

    T* addComponentToEntity (size_t entityId) {
        ensureSizeOfVector(components, entityId - 1);
        Component& component =  components[entityId];

        if (component.active) {
            //TODO: crash
        }

        component.active = true;
        component.init();
        return component;
    }

private:
    vector<T> components;

};
