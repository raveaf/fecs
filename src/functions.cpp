#include "../headers/functions.hpp"

vector<Entity> entities;

deque<size_t> unusedEntities;

unordered_set<size_t> registeredComponentTypes;

vector<AbstractComponentsStorage*> componentVectors;

Entity& createEntity () {
    if (unusedEntities.empty() ) {
        entities.emplace_back(entities.size(), true);

        return entities.back();
    } else {
        Entity& entity = entities[unusedEntities.back()];

        entity.active = true;
        unusedEntities.pop_back();

        return entity;
    }
}
