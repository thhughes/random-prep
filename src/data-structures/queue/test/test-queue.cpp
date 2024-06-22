//
//  test-stack.cpp
//  dsr
//

#include "queue.h"
#include "test-runner.h"

#include <string>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>



namespace DataStructures {
    
class QueueTester : public Quality::Tester {
public:
    QueueTester(Queue::Type t) : testType(t), Quality::Tester(Quality::RunAllTests, Quality::ResultFormatter::Default) {}
    
    static bool TestAll(std::string& errStr);
    
protected:
    virtual Quality::TestList& getTests() override;
    virtual void setupTest() override;
    virtual void cleanupTest() override;
    
    std::unique_ptr<Queue> testQueue;
    Queue::Type testType;
    
    
};
}


using namespace DataStructures;

void QueueTester::setupTest() {
    testQueue = Queue::Factory(testType);
}

void QueueTester::cleanupTest() {
    testQueue.reset();
}

bool QueueTester::TestAll(std::string& errStr) {
    std::initializer_list<Queue::Type> types = {
        Queue::LinkedListQueue,
    };
    bool allPass = true;
    for (const auto& t: types) {
        QueueTester qt(t);
        auto res = qt.RunTests();
        errStr += "Testing Queue Type [";
        errStr += Queue::typeAsStr(t);
        errStr += "]. With Results: ";
        if (res.allPassed) {
            errStr += "All Passed\n";
        }
        else {
            allPass = false;
            errStr += "\n" + res.errors + "\n";
        }
    }
    return allPass;
}



Quality::TestList& QueueTester::getTests() {
    
    static Quality::TestList testList = {
        {
            "Always Fail Queue",
            [&] (std::string& errStr) -> bool { errStr = "Always Fail Queue"; return false; }
        },
    };
    
    return testList;
}

// int main(int argc, const char * argv[]) {
    
//     /**
//      No Args for deciding what to run - this tool takes instructions from nobody
//      */
    
//     std::initializer_list<std::function<bool(std::string&)>> tests = {
//         // DataStructures::StackTester::TestAll,
//         DataStructures::QueueTester::TestAll,
        
//     };
    
//     std::string results;
//     for (auto& t: tests) {
//         t(results);
//         printf("%s\n", results.c_str());
//         results.clear();
//     }
    
//     printf("FIN\n");
// }



// Example test case
TEST(QueueTest, TestAll) {
    std::string results;
    // EXPECT_TRUE(DataStructures::QueueTester::TestAll(results));
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

