#include "../headers/ComponentsStorage.hpp"

void ComponentsStorage::destroyEntity(size_t id) {
    Component& component =  this->components[id];
    component.active = false;
}


