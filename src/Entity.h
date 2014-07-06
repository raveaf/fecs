#pragma once

#include "ComponentTypeId.h"
#include <vector>

using namespace std;

class Entity
{
public:	
    bool active = false;
    vector<bool> usedComponentsIds;

    size_t getId() const {
        return id;
    }

    void setId(size_t id) {
        this->id = id;
    }

private:
    size_t id;

};
