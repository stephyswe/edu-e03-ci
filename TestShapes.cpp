#include <gtest/gtest.h>

extern "C" {
#include "input.h"
#include "shapes.h"
}

class ShapesTest : public testing::Test {
   protected:
    // Override this to define how to set up the environment.
    void SetUp() override {
        // game_initialize();	/* Without this the Tests could break*/
    }

    // Override this to define how to tear down the environment.
    virtual void TearDown() {}
};

// Test the createRectangle function
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