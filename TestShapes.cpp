#include <gtest/gtest.h>

extern "C" {
#include "calculator.h"
#include "game.h"
#include "input.h"
#include "shapesfunc.h"
}

class ShapesTest : public testing::Test {
   protected:
    // Override this to define how to set up the environment.
    void SetUp() override {
        // game_initialize();	/* Without this the Tests could break*/
        srand(12345);
    }

    static int mock_rand(void) { return mock_computer_choice; }

    // global variable that holds the computer's choice for each test case
    static int mock_computer_choice;

    // Override this to define how to tear down the environment.
    virtual void TearDown() {}

    // function to compare the result of play_game() with the expected result
    void assert_game_result(const char *user_choice,
                            enum Game_Status expected) {
        enum Game_Status result = play_game(user_choice, &mock_rand);
        EXPECT_EQ(result, expected);
    }
};

int ShapesTest::mock_computer_choice = 0;

// ** Shapes Tests - All Four (rectangle, triangle, circle, parallelogram) **

// ** 1 - Rectangle **

TEST_F(ShapesTest, WhenCreateRectangleIsOK) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createRectangle(5.0, 6.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 30.0);
    ASSERT_DOUBLE_EQ(perimeter, 22.0);
}

TEST_F(ShapesTest, WhenCreateRectangleLengthIsZero) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createRectangle(0, 6.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 2 - Triangle **

TEST_F(ShapesTest, WhenCreateTriangleLengthIsOK) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createTriangle(5.0, 6.0, &area, &perimeter);

    // ASSERT
    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 15.0);
    ASSERT_DOUBLE_EQ(perimeter, 22.0);
}

TEST_F(ShapesTest, WhenCreateTriangleLengthIsZero) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createTriangle(0, 6.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 3 - Circle **

TEST_F(ShapesTest, WhenCreateCircleLengthIsOK) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createCircle(5.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 78.50);
    ASSERT_DOUBLE_EQ(perimeter, 31.40);
}

TEST_F(ShapesTest, WhenCreateCircleLengthIsZero) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createCircle(0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 4 - Parallelogram **
TEST_F(ShapesTest, WhenCreateParallelogramLengthIsOK) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status =
        createParallelogram(5.0, 6.0, 7.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 30.0);
    ASSERT_DOUBLE_EQ(perimeter, 24.0);
}

TEST_F(ShapesTest, WhenCreateParallelogramLengthIsZero) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createParallelogram(0, 6.0, 7.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** Calculator Tests **

// ** 1 - addition **
TEST_F(ShapesTest, AddsTwoNumbersCorrectly) {
    // Arrange
    double num1 = 2.5;
    double num2 = 3.5;
    double expected_result = 6.0;

    // Act
    double result = calculateAddiction(num1, num2);

    // Assert
    EXPECT_EQ(result, expected_result);
}

TEST_F(ShapesTest, AddsTwoNumbersWrongResultInError) {
    // Arrange
    double num1 = 2.5;
    double num2 = 3.5;
    double expected_result = 6.1;

    // Act
    double result = calculateAddiction(num1, num2);

    // Assert
    EXPECT_FALSE(result == expected_result);
}

// ** Game Tests **

// ** 1 - Stones vs Scissors - Winner: User **
TEST_F(ShapesTest, TestStonesVsScissors) {
    mock_computer_choice = 1;  // Set the computer's choice to "Stones"

    Game_Status status = play_game("Stones", &rand);

    EXPECT_EQ(status, Game_Status_Win_User);
}

