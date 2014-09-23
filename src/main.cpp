#include <iostream>
//#include "../headers/public.hpp"
#include "../headers/AbstractEntityStorage.hpp"
#include "../headers/Entity.hpp"
#include "../headers/EntityStorage.hpp"
#include "../headers/EntityType.hpp"
#include "../headers/global.hpp"
#include "../headers/Processor.hpp"


using namespace std;

int testt (int p) {
    cout << p << endl;

    return p;
}






struct TestEntity : Entity {
    using Entity::Entity;

public:
    string teststr = "test";


private:
    void reset() {
        cout << "reset" << endl;
    }

    void init() {
        cout << "init" << endl;
    }
};

EntityType<TestEntity> type;


class TestProcessor : public Processor<TestEntity> {
public:
    TestProcessor (EntityType<TestEntity> type) : Processor<TestEntity> (type) {}

private:

    virtual void initializeBeforeProcessing () {
        cout << "initializeBeforeProcessing" << endl;
    }
    virtual void cleanUpAfterProcessing () {
        cout << "cleanUpAfterProcessing" << endl;
    }
    virtual void process (TestEntity& entity) {
        cout << entity.teststr << endl;
    }
};

int main()
{
    int test = 6;
    int& test2 = test;
    int* test3 = &test;
    int& test4 = *test3;
    int* test5;

    test = 5;

    cout << testt(test4) << endl;

    test5 = test3;
    test2 = *test3;

    cout << &test2 << endl;
    cout << test3 << endl;

    TestProcessor* testProcessor = new TestProcessor(type);

    TestEntity& testEntity = createEntity(type);

    //testEntity.teststr = "blahblah";

    TestEntity& testEntity2 = createEntity(type);

    //testEntity2.teststr = "blahblahhjfjhj";


    testProcessor->use();

    destroyEntity(testEntity);






    return 0;
}


