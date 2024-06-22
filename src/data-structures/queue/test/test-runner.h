//
//  test-runner.h
//  dsr
//

#pragma once
#include <functional>
#include <string_view>
#include <vector>
#include <string>

namespace Quality {

using TestFx = std::function<bool(std::string&)>;
struct Test {
    std::string_view name;
    TestFx execute;
};
using TestList = std::vector<Test>;

enum Persistence {
    QuitOnFailure,
    RunAllTests
};

struct Results {
    bool allPassed;
    std::string errors;
};



class ResultFormatter {
public:
    enum Format {
        Default,
        /// JSON
        /// ...
    };
    static std::unique_ptr<ResultFormatter> Factory(Format f);
    
    virtual ~ResultFormatter(){}
    virtual bool format(std::string& outp, const std::string_view& testName, const std::string& testErr) = 0;
};

class DefaultFormatter: public ResultFormatter{
    virtual bool format(std::string& outp, const std::string_view& testName, const std::string& testErr);
};


class Tester {
public:
    
    Tester(Persistence p, ResultFormatter::Format f=ResultFormatter::Default) : persist(p), formatter(ResultFormatter::Factory(f)) {}
    virtual ~Tester() { }
    
    /// @function RunTests
    /// @brief Runs X tests from the list of tests the tester knows about. X depends on the persistence level passed in at construction.
    /// @return Results of the tests where the "errors" are formatted by the ResultFormatter type passed at instantiation.
    Results RunTests();
    
protected:
    struct FailedTest {
        std::string_view name;
        std::string errStr;
    };
    using FailedTestList = std::vector<FailedTest>;
    
    void recordFailedTest(const std::string_view& testName, const std::string& testErr);
    
    /// @brief overloadable but default assumption is that the ResultFormatter object will do most of the required heavy lifting.
    virtual void formatFailures(std::string& formattedOutput);
    
    /// Required overload. This is how the tester knows about all the tests in question.
    virtual TestList& getTests() = 0;
    /// Overloadable setup and cleanup tooling 
    virtual void setupTest() { }
    virtual void cleanupTest() { }
    
    /// Standard Getters
    Persistence checkPersistence() { return persist; }
    FailedTestList getFailedTests() { return failedTests; }
private:
    
    Persistence persist;
    FailedTestList failedTests;
    std::unique_ptr<ResultFormatter> formatter;
    
};



}

