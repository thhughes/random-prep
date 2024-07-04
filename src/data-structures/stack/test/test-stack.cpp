//
//  test-stack.cpp
//  dsr
//


#include <gtest/gtest.h>

#include "std-lib-stack.h"
#include "linked-list-stack.h"
#include "stack.h"


template <typename t>
class StackTesterFixture : public ::testing::Test {
protected:

    StackTesterFixture() { }

    void SetUp() override {
        testStack = std::make_unique<t>();
    }

    void TearDown() override {
        testStack.reset();
    }

    std::unique_ptr<DataStructures::Stack> testStack;
};


TYPED_TEST_SUITE_P(StackTesterFixture);

/// After Construction: 
TYPED_TEST_P(StackTesterFixture, PeekAfterConstructionIsEmpty) {
    auto v = this->testStack->peek();
    EXPECT_TRUE(v.empty);
}
TYPED_TEST_P(StackTesterFixture, PopAfterConstructionIsEmpty) {
    auto v = this->testStack->pop();
    EXPECT_TRUE(v.empty);
}
TYPED_TEST_P(StackTesterFixture, EmptyOnConstruction) {
    EXPECT_TRUE(this->testStack->isEmpty());
}
TYPED_TEST_P(StackTesterFixture, OnEmptyList) {
    auto v = this->testStack->pop(); 
    EXPECT_TRUE(v.empty);

    EXPECT_TRUE(this->testStack->isEmpty());
    this->testStack->clear();
    EXPECT_TRUE(this->testStack->isEmpty());
    
    v = this->testStack->peek(); 
    EXPECT_TRUE(v.empty);
}


TYPED_TEST_P(StackTesterFixture, PushAndPeek) {
    this->testStack->push({1});
    auto v = this->testStack->peek();
    EXPECT_EQ(v.obj, 1);
    this->testStack->push({2});
    v = this->testStack->peek();
    EXPECT_EQ(v.obj, {2});
}

TYPED_TEST_P(StackTesterFixture, PushAndIsEmpty) {
    EXPECT_TRUE(this->testStack->isEmpty());
    this->testStack->push({1});
    EXPECT_FALSE(this->testStack->isEmpty());
}

TYPED_TEST_P(StackTesterFixture, PopUntilEmpty) {
    this->testStack->push({1});
    EXPECT_FALSE(this->testStack->isEmpty());
    auto v = this->testStack->pop();
    EXPECT_TRUE(this->testStack->isEmpty());
}
TYPED_TEST_P(StackTesterFixture, ClearWorksOnList) {
    this->testStack->push({1});
    EXPECT_FALSE(this->testStack->isEmpty());
    this->testStack->clear();
    EXPECT_TRUE(this->testStack->isEmpty());
}
TYPED_TEST_P(StackTesterFixture, ClearThenAdd) {
    this->testStack->push({1});
    EXPECT_FALSE(this->testStack->isEmpty());
    this->testStack->clear();
    EXPECT_TRUE(this->testStack->isEmpty());
    this->testStack->push({1});
    EXPECT_FALSE(this->testStack->isEmpty());
    auto v = this->testStack->pop();
    EXPECT_FALSE(v.empty);
    EXPECT_EQ(1, v.obj);
}


REGISTER_TYPED_TEST_SUITE_P(StackTesterFixture,
    PeekAfterConstructionIsEmpty,
    PopAfterConstructionIsEmpty, 
    EmptyOnConstruction, 
    OnEmptyList, 
    PushAndPeek, 
    PushAndIsEmpty, 
    PopUntilEmpty, 
    ClearWorksOnList, 
    ClearThenAdd
    );



INSTANTIATE_TYPED_TEST_SUITE_P(StdLibStack, StackTesterFixture, DataStructures::StdLibStack);
INSTANTIATE_TYPED_TEST_SUITE_P(LLStack, StackTesterFixture, DataStructures::LinkedListStack);



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

