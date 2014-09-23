#include <iostream>
//#include "../headers/public.hpp"
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






struct TestEntity : public Entity<TestEntity> {
    using Entity::Entity;

public:
    string teststr = "test";
    static EntityType<TestEntity> type;


private:
    virtual void reset() {
        cout << "reset" << endl;
    }

    virtual void init() {
        cout << "init" << endl;
    }
};

EntityType<TestEntity> TestEntity::type;




class TestProcessor : public Processor<TestEntity> {
    using Processor::Processor;
public:

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
    TestProcessor* testProcessor = new TestProcessor(TestEntity::type);

    TestEntity& testEntity = createEntity(TestEntity::type);

    testEntity.teststr = "blahblah";

    TestEntity& testEntity2 = createEntity(TestEntity::type);

    testEntity2.teststr = "blahblahhjfjhj";

    TestEntity* testEntity3 = &createEntity(TestEntity::type);
    testEntity3->teststr = "ddssaasffafvbgfffdssdf";

    testEntity3 = &createEntity(TestEntity::type);
    testEntity3->teststr = "dfgdweffffaddddddddddddddddddfd";

    testEntity3 = &createEntity(TestEntity::type);
    testEntity3->teststr = "q2342456434564";

    testEntity3 = &createEntity(TestEntity::type);
    testEntity3->teststr = "+++##+ää+##";

    testProcessor->use();
    testProcessor->use();

    destroyEntity(*testEntity3);

    testProcessor->use();






    return 0;
}


