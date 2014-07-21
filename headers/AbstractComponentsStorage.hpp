#pragma once

#include <vector>

using namespace std;

class AbstractComponentsStorage {
public:
    virtual void removeComponentFromEntity (std::size_t entityId) = 0;
    virtual bool entityHasComponent (std::size_t entityId) = 0;

 };
