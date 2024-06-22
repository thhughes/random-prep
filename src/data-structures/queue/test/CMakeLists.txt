# Add the test executable
add_executable(test-queue test-queue.cpp test-runner.cpp test-runner.h)

# Link the test executable with the queue library
target_link_libraries(test-queue queue gtest gtest_main)

# Add a test
add_test(NAME TestQueue COMMAND test-queue)