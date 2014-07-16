#pragma once

class Component
{
public:

    bool active = false;

    virtual void init();
    virtual void reset();

};

