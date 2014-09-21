#pragma once

#include <vector>
#include <deque>

#include "AbstractEntityStorage.hpp"
#include "Entity.hpp"


using namespace std;

template<class T>
class EntityStorage : AbstractEntityStorage{
private:
    vector<T> entities;
    deque<int> unusedEntities;


public:
    T& createEntity () {
        Entity* entity;

        if (unusedEntities.empty() ) {
            entities.emplace_back();

            entity = entities.back()&;
            entity.storage = this;
        } else {
            entity = unusedEntities.back();

            unusedEntities.pop_back();
        }

        entity->init();
        return entity;
    }


    void destroyEntity (Entity& entity){
        unusedEntities.push_back(entity);
    }




};

