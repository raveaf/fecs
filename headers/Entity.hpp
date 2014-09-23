#pragma once

#include <vector>
#include "AbstractEntityStorage.hpp"

using namespace std;

struct Entity
{
public:
    bool active;
    const size_t id;
    AbstractEntityStorage* storage;

    Entity () = delete;
    explicit Entity (size_t id, AbstractEntityStorage* storage) :id {id}, storage {storage} {

    }

    void doInit () {
        init();
    }

    void doReset() {
        reset();

    }


private:    

    virtual void init(){}
    virtual void reset(){}

};
