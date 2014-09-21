#pragma once

#include <vector>
#include "AbstractEntityStorage.hpp"

using namespace std;

class Entity
{
public:
    bool active;
    size_t id;
    AbstractEntityStorage& storage;

    void destroy(){
        storage.destroyEntity(*this);
        active = false;
        reset();
    }

    void initialize() {
        active = true;
        init();
    }

private:
    virtual void init(){}
    virtual void reset(){}



};
