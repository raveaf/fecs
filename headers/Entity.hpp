#pragma once

#include <vector>
#include "AbstractEntityStorage.hpp"

using namespace std;

struct Entity
{
public:
    bool active;
    const size_t id;

    Entity () = delete;
    explicit Entity (size_t id, AbstractEntityStorage* storage) :id {id}, storage {storage} {

    }

    void destroy(){
        storage->destroyEntity(this);
    }        

    void doInit () {
        init();
    }

    void doReset() {
        reset();

    }


private:
    AbstractEntityStorage* storage;

    virtual void init(){}
    virtual void reset(){}

};
