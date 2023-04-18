#include <gtest/gtest.h>

extern "C" {
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

TEST_F(ShapesTest, WhenRunIsOK) {
    // ARRANGE

    // ACT
    Shapes_Status status = shapesMenu();

    // ASSERT
    ASSERT_EQ(status, Shapes_Status_Ok);
}