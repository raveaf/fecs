#pragma once
#include <iostream>

#include "../src/Component.hpp"

class ComponentDe : public Component
{
public:	

    void init() {
        std::cout << "test";
    }
    void reset() {}
};
