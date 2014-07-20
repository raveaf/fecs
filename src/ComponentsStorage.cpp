#include "../headers/ComponentsStorage.hpp"

void ComponentsStorage::destroyEntity(size_t id) {
    Component& component = components[id];
    component.active = false;
}


