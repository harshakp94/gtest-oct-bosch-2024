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
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_zero){
  //Arrange
  StringCalculator objUndertest;
  string input = "0";
  int expectedValue = 0;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_one){
  //Arrange
  StringCalculator objUndertest;
  string input = "1";
  int expectedValue = 1;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_two_comma_delimited_numbers_returns_their_sum){
  //Arrange
  StringCalculator objUndertest;
  string input = "1,2";
  int expectedValue = 3;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_numbers_returns_their_sum){
  //Arrange
  StringCalculator objUndertest;
  string input = "1,2,3";
  int expectedValue = 6;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add,when_delimited_with_newline_and_comma_returns_their_sum){
  //Arrange
  StringCalculator objUndertest;
  string input = "1\n2,3";
  int expectedValue = 6;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add,when_passed_a_delimiter_returns_the_sum_based_on_that_delimiter){
  //Arrange
  StringCalculator objUndertest;
  string input = "//;\n1;2";
  int expectedValue = 3;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add,when_passed_negative_numbers_throws_an_exception_listing_invalid_values){
  //Arrange
  StringCalculator objUndertest;
  string input = "1,-2,-4,5";
  int expectedValue = 6;

  //act
  int actualValue = objUndertest.Add(input);
  //Assert
   ASSERT_STREQ(e.what(), "Negatives not allowed: -2,-4");
}
