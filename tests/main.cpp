#include "../Entity.h"
#include "../Component.h"
#include "../ComponentTypeId.h"
#include "../Subsystem.h"
#include "Test.h"

#include "../functions.h"

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    entity ent = entity();
    ComponentDe test = ComponentDe();
    component_type_id<ComponentDe> test2 = register_component_type(test);

    int x = 5;
    int& i2 = x;
    int* i1 = &i2;


    //ent.component(test2);
    int test3 = test2.get_id();

    //std::cout << std::exception().what();
    std::cout << test2.get_id();
    std::cout << x << *i1 << i2;

    std::vector<bool> vec;

    vec.reserve(5);
    vec.resize(5);

    cout << endl << vec.size() << endl;

    cout << vec.capacity() << endl;

    cout << vec[4] << endl;

    int t;

    std::cin >> t;

}
