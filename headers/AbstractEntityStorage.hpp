#pragma once

struct Entity ;

class AbstractEntityStorage {
public:
    virtual void destroyEntity(Entity* entity) = 0;
};
