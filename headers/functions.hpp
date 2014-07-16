#pragma once

#include <vector>
#include <deque>
#include <unordered_set>
#include <typeinfo>
#include <iterator>

#include "Entity.hpp"
#include "AbstractComponentsStorage.hpp"
#include "ComponentsStorage.hpp"
#include "ComponentTypeId.hpp"

using namespace std;

extern vector<Entity> entities;

extern deque<size_t> unusedEntities;

extern unordered_set<size_t> registeredComponentTypes;

extern vector<AbstractComponentsStorage*> componentVectors;


template<class T>
ComponentTypeId<T> registerComponentType(T& componentPrototype) {

    
    size_t hash = typeid(componentPrototype).hash_code();
    
    if (registeredComponentTypes.find(hash) == registeredComponentTypes.end() ) {
        registeredComponentTypes.insert(hash);
    } else {
        //crash
    }

    return ComponentTypeId<T>();
}

template<typename T>
void ensureSizeOfVector(vector<T>& vector, size_t size) {
    if (vector.size() < size) {
        vector.resize(size);
    }
}

template<typename T>
size_t indexOfItemInVector(vector<T>& vector, const T& item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (item == vector[i]) {
            return i;
        }
    }

    return -1;
}

Entity& createEntity ();


