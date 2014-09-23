#pragma once

#include <vector>
#include <deque>

#include "AbstractEntityStorage.hpp"
#include "Entity.hpp"


using namespace std;

template<class T>
class EntityStorage : public AbstractEntityStorage{
private:    
    deque<int> unusedEntities;


public:
    vector<T> entities;

    void addCachedEntities (size_t count) {
        for (size_t i = 0; i < count; i++) {
            size_t currentSize = entities.size();

            unusedEntities.emplace_back(currentSize);
            entities.emplace_back(currentSize, this);

            Entity& entity = entities.back();
            entity.active = false;
        }
    }

    T& createEntity () {
        Entity* entity;

        if (unusedEntities.empty() ) {
            entities.emplace_back(entities.size(), this);

            entity = &entities.back();
        } else {
            entity = &entities[unusedEntities.back()];
            unusedEntities.pop_back();
        }        

        entity->active = true;
        entity->doInit();

        return *static_cast<T*>(entity);
    }


    void destroyEntity (Entity* entity){
        unusedEntities.emplace_back(entity->id);

        entity->active = false;
        entity->doReset();
    }
};

