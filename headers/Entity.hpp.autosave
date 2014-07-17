#pragma once

#include <vector>

using namespace std;

class Entity
{
public:	
    bool active;
    vector<bool> usedComponentsIds;

    Entity();

    Entity(size_t id, bool active);

    size_t getId() const;

    void destroy();

private:
    size_t id;

};
