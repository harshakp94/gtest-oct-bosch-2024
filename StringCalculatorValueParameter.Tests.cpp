#include "stringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

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

class StringCalculatorAddParameterizedFixture:
public StringCalculatorAddFixture,
public testing::WithParamInterface<tuple<string,int>>{

};
INSTANTIATE_TEST_SUITE_P(ValuesDataSet,StringCalculatorAddParameterizedFixture,testing::Values(
  make_tuple("",0),
  make_tuple("0",0),
  make_tuple("1",1),
  make_tuple("1,2",3),
  make_tuple("1,2,3", 6),
  make_tuple("1\n2,3",6),
  make_tuple("//;\n1;2",3),
  make_tuple("42,1001,3",45),
  make_tuple("//[***]\n8***2***3",13),
  make_tuple("//[*][%]\n4*2%3",9),
  make_tuple("//[**][%^]\n4**1%^9",14)
));


TEST_P(StringCalculatorAddParameterizedFixture, DataDrivenTestCase){
    string input=std::get<0>(GetParam());
    int expectedValue=std::get<1>(GetParam());
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST_F(StringCalculatorAddFixture, Throw_Invalid_Argument_For_Neg_Number){
    string input="-3,-1,-14";
    EXPECT_THROW(objUnderTest->Add(input),invalid_argument);
  }

