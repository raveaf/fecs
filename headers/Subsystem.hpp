#pragma once

#include "Entity.hpp"
#include "functions.hpp"

#include <vector>

using namespace std;

class Subsystem {
public:

    void use();

private:
    vector<size_t> componentTypeIds;
    bool initialized = false;

    virtual void initializeBeforeProcessing();
    virtual void cleanUpAfterProcessing();
    virtual void processEntity(Entity& entity);

    virtual vector<size_t> defineComponentTypeIds() = 0;

    void init();
};
