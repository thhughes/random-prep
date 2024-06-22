
# Add the test executable
add_executable(test-stack test-stack.cpp test-runner.cpp test-runner.h)

# Link the test executable with the queue library
target_link_libraries(test-stack stack gtest gtest_main)

# Add a test
add_test(NAME TestStack COMMAND test-stack)