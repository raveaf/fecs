#include <iostream>

using namespace std;

int* testt (int p) {
    cout << p << endl;

    return &p;
}


int main()
{
    int test = 6;
    int& test2 = test;
    int* test3 = &test;
    int& test4 = *test3;

    test = 5;

    cout << testt(test2) << endl;

    cout << test2 << endl;
    return 0;
}

