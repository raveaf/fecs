#pragma once

#include "Entity.h"
#include "ComponentTypeId.h"
#include "functions.h"

#include <vector>

using namespace std;

class Subsystem {
public:

    void use() {
        initializeBeforeProcessing();
        processing = true;

        for (i = 0; i < entitiesToProcess.size(); i++) {
            processEntity(*entitiesToProcess[i]);
        }

        processing = false;
        cleanUpAfterProcessing();
    }

private:
    vector<int> componentTypeIds;
    vector<Entity*> entitiesToProcess;
    vector<bool> addedEntitiesLookup;
    size_t i;
    bool processing;

    virtual void initializeBeforeProcessing() {}
    virtual void cleanUpAfterProcessing() {}
    virtual void processEntity(Entity& entity) {}

    virtual vector<int> defineComponentTypeIds() = 0;

    void init() {
        componentTypeIds = defineComponentTypeIds();
    }

    void addEntity(Entity& entity) {
        int id = entity.getId();

        ensureSizeOfVector(addedEntitiesLookup, id);
        addedEntitiesLookup.push_back(true);
        entitiesToProcess.push_back(&entity);
    }

    void removeEntity(Entity& entity) {
        int id = entity.getId();

        ensureSizeOfVector(addedEntitiesLookup, id + 1);

        if (addedEntitiesLookup[id]) {
            size_t index = indexOfItemInVector(entitiesToProcess, &entity);
            bool remove_fast = true;

            addedEntitiesLookup[id] = false;

            if (processing) {
                if (index <= i) {
                    i--;
                    if (index < i) {
                        remove_fast = false;
                    }
                }
            }

            if (remove_fast) {
                entitiesToProcess[index] = entitiesToProcess.back();
                entitiesToProcess.pop_back();
            }
            else {
                entitiesToProcess.erase(entitiesToProcess.begin() + index);
            }
        }
    }
};
