#pragma once
#include <iostream>

#include "../headers/Component.hpp"

class ComponentDe : public Component
{
public:	

    void init() {
        std::cout << "test";
    }
    void reset() {}
};
