//
//  test-stack.h
//  dsr
//

#pragma once

/// Interface
#include "stack.h"
/// Specific implementation
#include "std-lib-stack.h"

/// Include the quality namespace
#include "test-runner.h"

#include <vector>

namespace DataStructures {



class StackTester : public Quality::Tester {
public:
    StackTester(Stack::Type t) : testType(t), Quality::Tester(Quality::RunAllTests, Quality::ResultFormatter::Default) {}
    
    static bool TestAll(std::string& errStr);
    
protected:
    virtual Quality::TestList& getTests() override;
    virtual void setupTest() override;
    virtual void cleanupTest() override;
    
    std::unique_ptr<Stack> testStack;
    Stack::Type testType;
    
    
};





}

