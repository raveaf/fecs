#pragma once

#include <vector>
#include <deque>


using namespace std;

template<class T>
class EntityStorage {
private:    
    deque<int> unusedEntities;


public:
    vector<T> entities;

    void addCachedEntities (size_t count) {
        for (size_t i = 0; i < count; i++) {
            size_t currentSize = entities.size();

            unusedEntities.emplace_back(currentSize);
            entities.emplace_back(currentSize, this);

            T& entity = entities.back();
            entity.active = false;
        }
    }

    T& createEntity () {
        T* entity;

        if (unusedEntities.empty() ) {
            entities.emplace_back(entities.size(), this);

            entity = &entities.back();
        } else {
            entity = &entities[unusedEntities.back()];
            unusedEntities.pop_back();
        }        

        entity->active = true;
        entity->doInit();

        return *entity;
    }


    void destroyEntity (T& entity){
        unusedEntities.emplace_back(entity.id);

        entity.active = false;
        entity.doReset();
    }
};

