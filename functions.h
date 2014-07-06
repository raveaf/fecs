#pragma once

#include <vector>
#include <unordered_set>
#include <typeinfo>
#include <iterator>

#include "Entity.h"

using namespace std;

vector<void*> componentVectors;

vector<Entity> entities;

unordered_set<size_t> registeredComponentTypes;




template<class T>
component_type_id<T>  register_component_type(T& component_prototype) {

    
    size_t hash = typeid(component_prototype).hash_code();
    
    if (registeredComponentTypes.find(hash) == registeredComponentTypes.end() ) {
        registeredComponentTypes.insert(hash);
    } else {
      //crash
    }
    
    return component_type_id<T>();
}

template<typename T>
void ensure_size_of_vector(vector<T>& vector, size_t size) {
    if (vector.size() < size) {
        vector.resize(size);
    }
}

template<typename T>
size_t index_of_item_in_vector(vector<T>& vector, const T& item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (item == vector[i]) {
            return i;
        }
    }

    return -1;
}
