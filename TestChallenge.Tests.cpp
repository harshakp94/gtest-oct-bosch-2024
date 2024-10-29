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
// Test case to check the sum and output
TEST_F(AddFunctionTest, AddsTwoNumbersCorrectly) {
    // Capture std::cout output
    testing::internal::CaptureStdout();

    // Call the function with the fixture’s `result` variable
    add(3, 5, &result);

    // Stop capturing and store output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify that the result is correct
    ASSERT_EQ(result, 8);

    // Verify that the correct output was printed
    ASSERT_STREQ(output.c_str(), "Sum of 3:5 is 8\n");
}
