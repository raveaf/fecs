#pragma once
#include "ComponentTypeId.hpp"

class Component
{
public:

    bool active = false;

    virtual void init() {}
    virtual void reset() {}

};

