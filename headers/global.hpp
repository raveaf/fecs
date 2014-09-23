#pragma once

#include <vector>
#include "AbstractEntityStorage.hpp"
#include "EntityStorage.hpp"

using namespace std;

extern deque<AbstractEntityStorage*> entityStorages;

template <class T>
class EntityType;

template <class T>
T& createEntity (EntityType<T>& type) {
    EntityStorage<T>* storage = static_cast<EntityStorage<T>*> (entityStorages[type.id]);

    return storage->createEntity();
}
