#include <gtest/gtest.h>

extern "C" {
#include "input.h"
#include "shapesfunc.h"
}

class ShapesTest : public testing::Test {
   protected:
    // Override this to define how to set up the environment.
    void SetUp() override {
        // game_initialize();	/* Without this the Tests could break*/
    }
};

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
    double area, perimeter;
    Shapes_Status status = createRectangle(0, 6.0, &area, &perimeter);
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 2 - Triangle **

TEST_F(ShapesTest, WhenCreateTriangleIsOK) {
    double area, perimeter;
    Shapes_Status status = createTriangle(5.0, 6.0, &area, &perimeter);
    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 15.0);
    ASSERT_DOUBLE_EQ(perimeter, 22.0);
}

TEST_F(ShapesTest, WhenCreateTriangleBaseIsZero) {
    double area, perimeter;
    Shapes_Status status = createTriangle(0, 6.0, &area, &perimeter);
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 3 - Circle **

TEST_F(ShapesTest, WhenCreateCircleIsOK) {
    // ARRANGE
    double area, perimeter;

    // ACT
    Shapes_Status status = createCircle(5.0, &area, &perimeter);

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
    ASSERT_DOUBLE_EQ(area, 78.50);
    ASSERT_DOUBLE_EQ(perimeter, 31.40);
}

TEST_F(ShapesTest, WhenCreateCircleRadiusIsZero) {
    double area, perimeter;
    Shapes_Status status = createCircle(0, &area, &perimeter);
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}

// ** 4 - Parallelogram **
TEST_F(ShapesTest, WhenCreateParallelogramIsOK) {
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

TEST_F(ShapesTest, WhenCreateParallelogramBaseIsZero) {
    double area, perimeter;
    Shapes_Status status = createParallelogram(0, 6.0, 7.0, &area, &perimeter);
    ASSERT_EQ(status, Shapes_Status_InvalidInput);
}