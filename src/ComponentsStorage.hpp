#pragma once

#include "AbstractComponentsStorage.hpp"
#include <vector>

template<class T>
class ComponentsStorage : AbstractComponentsStorage {
public:
    void deleteEntity (size_t id) {

    }

private:
    vector<T> components;

};
