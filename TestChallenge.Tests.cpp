#include <gtest/gtest.h>
#include <iostream>
#include "TestChallenge.h"

class AddFunctionTest : public ::testing::Test {
protected:
    int result;

    void SetUp() override {
        result = 0; //
    }
};

TEST_F(AddFunctionTest, AddsTwoNumbersCorrectly) {
    testing::internal::CaptureStdout();
    add(3, 5, &result);
    ASSERT_EQ(result, 8);
}
