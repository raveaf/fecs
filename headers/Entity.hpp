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

    void kill();

private:
    size_t id;

};
