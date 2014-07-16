#pragma once
#include <iostream>

template <class T>
class ComponentTypeId {
public:

    ComponentTypeId() {
        static size_t idCounter = 0;
        id = idCounter;
        idCounter++;
    }

    size_t getId() const {
        return id;
    }


private:
    size_t id;

};
