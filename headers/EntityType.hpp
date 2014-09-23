#pragma once

#include <vector>
#include "global.hpp"

using namespace std;

template <class T>
class EntityType {
public:
    const size_t id;

    EntityType () : EntityType(0) {}

    EntityType (size_t initialEntityCacheSize) : id {entityStorages.size() } {
        EntityStorage<T>* entityStorage = new EntityStorage<T>();

        entityStorage->addCachedEntities(initialEntityCacheSize);

        entityStorages.push_back(entityStorage);
    }

};
