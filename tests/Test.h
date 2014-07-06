#pragma once
#include <iostream>

class ComponentDe : public component
{
public:	

	void init() {
		std::cout << "test";
	}
	void reset() {}
};