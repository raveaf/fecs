#include "../headers/Entity.hpp"
#include "../headers/AbstractComponentsStorage.hpp"
#include "../headers/functions.hpp"

Entity::Entity() {
}

Entity::Entity (size_t id, bool active) {
    this->id = id;
    this->active = active;
}

size_t Entity::getId() const {
    return id;
}

void Entity::destroy() {
    for (AbstractComponentsStorage* s: componentVectors) {
        s->removeComponentFromEntity(id);
        active = false;
        unusedEntities.push_back(id);
    }
}

bool Entity::hasComponent(size_t typeId) {
    componentVectors[typeId]->entityHasComponent(id);
}
