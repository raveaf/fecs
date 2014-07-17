#pragma once

#include <vector>

using namespace std;

class AbstractComponentsStorage {
public:
    virtual void destroyEntity (std::size_t id) = 0;

 };
