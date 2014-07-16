#pragma once

#include "Entity.hpp"

#include <vector>

using namespace std;

class Subsystem {
public:

    void use();

private:
    vector<int> componentTypeIds;

    virtual void initializeBeforeProcessing();
    virtual void cleanUpAfterProcessing();
    virtual void processEntity(Entity& entity);

    virtual vector<int> defineComponentTypeIds() = 0;

    void init();
};
