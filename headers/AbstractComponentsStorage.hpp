#pragma once

#include <vector>

using namespace std;

class AbstractComponentsStorage {
public:
    virtual void deleteEntity (std::size_t id) = 0;

 };
