#pragma once

#include <vector>

#include "EntityStorage.hpp"

using namespace std;

template<class T>
struct Entity
{
public:
    bool active;
    const size_t id;
    EntityStorage<T>* storage;

    Entity () = delete;
    Entity (size_t id, EntityStorage<T>* storage) :id {id}, storage {storage} {

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
