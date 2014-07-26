#include "../headers/Subsystem.hpp"

void Subsystem::use(){
    if (initialized) {
        componentTypeIds = defineComponentTypeIds();
    }

    initializeBeforeProcessing();
    for (Entity& entity: entities) {
        if (entity.active && indexOfItemInVector(componentTypeIds, entity.getId() ) >= 0) {
            processEntity(entity);
        }
    }
    cleanUpAfterProcessing();
}


void Subsystem::initializeBeforeProcessing() {}
void Subsystem::cleanUpAfterProcessing() {}
void Subsystem::processEntity(Entity& entity) {}
