#include "stringCalculator.h"
#include <gtest/gtest.h>

//Fixture Class

class StringCalculatorAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void SetUp() override {
      objUnderTest=new StringCalculator();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

TEST_F(StringCalculatorAddFixture, Returns_0_For_Empty){
    string input="";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, Returns_0_For_0){
    string input="0";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, returns_1_for_one){
    string input="1";
    int expectedValue=1;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_two_comma_delimited_numbers_returns_their_sum){
    string input="1,2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_multiple_comma_delimited_numbers_returns_their_sum){
    string input="1,2,3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_delimited_with_newline_and_comma_returns_their_sum){
    string input="1\n2,3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_a_delimiter_returns_the_sum_based_on_that_delimiter){
    string input="//;\n1;2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_numbers_over_1000_ignores_them){
    string input="42,1001,3";
    int expectedValue=45;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_multicharacter_delimiter_uses_that_delimiter_to_sum_values){
    string input="//[***]\n8***2***3";
    int expectedValue=13;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_multiple_delimiters_sums_on_each_delimiter){
    string input="//[*][%]\n4*2%3";
    int expectedValue=9;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_multiple_multicharacter_delimiters_sums_on_each_delimiter){
    string input="//[**][%^]\n4**1%^9";
    int expectedValue=14;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture,  when_passed_negative_numbers_throws_an_exception_listing_invalid_values){
    string input = "1,-2,-4,5";
    int expectedValue=6;
   ASSERT_THROW({
      objUnderTest.Add(input);
    }, std::invalid_argument);
}


