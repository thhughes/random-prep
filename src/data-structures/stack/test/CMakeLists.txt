
add_executable(test-stack test-stack.cpp)

target_link_libraries(test-stack stack gtest gtest_main)

add_test(NAME TestStack COMMAND test-stack)