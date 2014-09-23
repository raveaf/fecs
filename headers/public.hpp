#pragma once

#include <vector>

using namespace std;

struct Entity
{
public:
    Entity () = delete;

    void destroy();

private:
    virtual void init();
    virtual void reset();
};

template <class T>
class EntityType {
public:

    EntityType ();

    EntityType (size_t initialEntityCacheSize);

};

template <class T>
class Processor {

public:
    Processor () = delete;
    Processor (EntityType<T>& entityType);

    void use();

private:

    virtual void initializeBeforeProcessing ();
    virtual void cleanUpAfterProcessing ();
    virtual void process (T& entity);

};

template <class T>
T& createEntity (EntityType<T>& type);
