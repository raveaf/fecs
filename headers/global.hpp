#pragma once

#include <vector>
#include "EntityStorage.hpp"

using namespace std;

extern vector<void*> entityStorages;

template <class T>
class EntityType;

template <class T>
T& createEntity (EntityType<T>& type) {
    EntityStorage<T>* storage = static_cast<EntityStorage<T>*> (entityStorages[type.id]);

    return storage->createEntity();
}

template <class T>
void destroyEntity (T& entity) {
    entity.storage->destroyEntity(entity);
}
