//
//  test-runner.cpp
//  dsr
//

#include "test-runner.h"

/// MARK: Formatters

std::unique_ptr<Quality::ResultFormatter> Quality::ResultFormatter::Factory(Format f) {
    switch(f) {
        case Default: {
            return std::make_unique<DefaultFormatter>();
        }
        /**
         Other Types to be added 
         */
        default: {
            return nullptr;
        }
    }
}

bool Quality::DefaultFormatter::format(std::string& outp, const std::string_view& testName, const std::string& testErr)
{
    auto startSize = outp.length();
    outp += "Test [";
    outp += testName;
    outp += "] Failed with error [";
    outp += testErr;
    outp += "]\n";
    return outp.length() > startSize;
}


/// MARK: Tester
    
Quality::Results Quality::Tester::RunTests() {
    Results res;
    std::string testErrLog;
    for (const auto& _test: getTests()) {
        testErrLog.clear();
        
        setupTest();
        bool passedTest = _test.execute(testErrLog);
        cleanupTest();
        if (passedTest) {
            continue;
        }
        
        if (testErrLog.empty()) {
            /// There's no requirement that tests provide an error string (just highly recommended)
            /// If there is no error stirng, we populate a generic message for the user.
            testErrLog = "<No Error Log>";
        }
        recordFailedTest( _test.name, testErrLog);
        
        if (QuitOnFailure == checkPersistence()) {
            break;
        }
    }
    formatFailures(res.errors);
    res.allPassed = res.errors.empty();
    return res;
}

void Quality::Tester::recordFailedTest(const std::string_view& testName, const std::string& testErr) {
    failedTests.push_back({testName, testErr});
}

void Quality::Tester::formatFailures(std::string& formattedOutput) {
    formattedOutput.clear();
    for (const auto& _test: getFailedTests()) {
        formatter->format(formattedOutput, _test.name, _test.errStr);
    }
}




