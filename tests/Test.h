#pragma once
#include <iostream>

#include "../src/Component.h"

class ComponentDe : public Component
{
public:	

    void init() {
        std::cout << "test";
    }
    void reset() {}
};
