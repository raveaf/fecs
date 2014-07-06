#pragma once
#include <iostream>

#include "../Component.h"

class ComponentDe : public Component
{
public:	

	void init() {
		std::cout << "test";
	}
	void reset() {}
};
