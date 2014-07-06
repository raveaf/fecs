#pragma once
#include "ComponentTypeId.h"

class Component
{
public:
	
	bool active = false;

    virtual void init() {}
    virtual void reset() {}
	
};

