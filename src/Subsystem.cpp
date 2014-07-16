#include "../headers/Subsystem.hpp"

void Subsystem::use(){

}


void Subsystem::initializeBeforeProcessing() {}
void Subsystem::cleanUpAfterProcessing() {}
void Subsystem::processEntity(Entity& entity) {}

void Subsystem::init() {
    componentTypeIds = defineComponentTypeIds();
}
