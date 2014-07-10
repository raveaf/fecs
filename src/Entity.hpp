#pragma once

#include "ComponentTypeId.hpp"
#include <vector>

using namespace std;

class Entity
{
public:	
    bool active;
    vector<bool> usedComponentsIds;

    Entity() {
    }

    Entity (size_t id, bool active) {
        this->id = id;
        this->active = active;
    }

    size_t getId() const {
        return id;
    }

private:
    size_t id;

};
