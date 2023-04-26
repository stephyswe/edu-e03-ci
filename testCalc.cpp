#include <gtest/gtest.h>

extern "C" {
#include "calculator.h"
#include "input.h"
}

class CalcTest : public testing::Test {
   protected:
    // Override this to define how to set up the environment.
    void SetUp() override {
        // game_initialize();	/* Without this the Tests could break*/
    }
};

// ** 1 - addition **
TEST_F(CalcTest, AddTwoNumbersCorrectly) {
    // Arrange
    double num1 = 2.5;
    double num2 = 3.5;
    double expected_result = 6.0;

    // Act
    double result = addition(num1, num2);

    // Assert
    EXPECT_EQ(result, expected_result);
}

TEST_F(CalcTest, AddTwoNumbersWrongResultInError) {
    // Arrange
    double num1 = 2.5;
    double num2 = 3.5;
    double expected_result = 6.1;

    // Act
    double result = addition(num1, num2);

    // Assert
    EXPECT_FALSE(result == expected_result);
}

// ** 2 - subtraction **
TEST_F(CalcTest, SubtractTwoNumbersCorrectly) {
    double result = subtract(6, 3);
    EXPECT_TRUE(result == 3);
}

TEST_F(CalcTest, SubtractTwoNumbersWrongResultInError) {
    double result = subtract(6, 3);
    EXPECT_FALSE(result == 4);
}

// ** 3 - multiply **
TEST_F(CalcTest, MultiplyTwoNumbersCorrectly) {
    double result = multiply(6, 3);
    EXPECT_TRUE(result == 18);
}

TEST_F(CalcTest, MultiplyTwoNumbersWrongResultInError) {
    double result = multiply(6, 3);
    EXPECT_FALSE(result == 19);
}

// ** 4 - divide **
TEST_F(CalcTest, DivideTwoNumbersCorrectly) {
    double result = divide(6, 3);
    EXPECT_TRUE(result == 2);
}

TEST_F(CalcTest, DivideTwoNumbersWrongResultInError) {
    double result = divide(6, 3);
    EXPECT_FALSE(result == 3);
}

// ** 3 - modulus **
TEST_F(CalcTest, ModulusTwoNumbersCorrectly) {
    double result = modulus(3, 10);
    EXPECT_TRUE(result == 3);
}

TEST_F(CalcTest, ModulusTwoNumbersWrongResultInError) {
    double result = modulus(3, 10);
    EXPECT_FALSE(result == 4);
}