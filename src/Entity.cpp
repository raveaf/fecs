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

void Entity::kill() {
    for (AbstractComponentsStorage* s: componentVectors) {
        s->deleteEntity(id);
    }
}
