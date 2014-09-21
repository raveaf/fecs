#pragma once

#include "globalVars.hpp"
#include "EntityType.hpp"
#include "EntityStorage.hpp"

template<class T>
EntityType<T> registerEntityType(T* entityPrototype) {
    EntityType<T> entityType;

    entityStorages.push_back(new EntityStorage<T>());
    entityType.id = entityStorages.size() - 1;

    return entityType;
}

template <class T>
T* createEntity (EntityType<T> type) {
    EntityStorage<T>* storage = entityStorages[type.id];

    return storage->createEntity();
}
