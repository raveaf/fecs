#pragma once

class Entity ;
class AbstractEntityStorage {
public:
    virtual void destroyEntity(Entity& entity) = 0;
};
