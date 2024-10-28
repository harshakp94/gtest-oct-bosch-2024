#include "stringCalculator.h"
#include<gtest/gtest.h>
//TEST(TESTSUITE, TestCaseName)
TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_empty){
  //Arrange
  StringCalculator objUndertest;
  string input = "";
  int expectedValue = 0;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue)
}
