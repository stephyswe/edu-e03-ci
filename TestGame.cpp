#include <gtest/gtest.h>

extern "C" {
#include "game.h"
#include "input.h"
}

class GameTest : public testing::Test {
   protected:
    // Override this to define how to set up the environment.
    void SetUp() override {
        // game_initialize();	/* Without this the Tests could break*/
    }
};

// ** Game Tests **

// ** 1. User options to win. **
// * 1.1. Stones vs Scissors - Winner: User
// * 1.2. Scissors vs Bag - Winner: User
// * 1.3. Bag vs Stones - Winner: User

// ** 2. User options to lose. **
// * 2.1. Scissors vs Stones - Winner: Computer
// * 2.2. Bag vs Scissors - Winner: Computer
// * 2.3. Stones vs Bag - Winner: Computer

// ** 3. User options to tie. **
// * 3.1. Same vs Same - Winner: Tie

// **  **

// 0 - Stones, 1 - Scissors, 2 - Bag
// * 1.1. Stones vs Scissors - Winner: User
TEST_F(GameTest, TestStonesVsScissors) {
    enum Choice mock_choice = Choice_Scissors;
    Game_Status status = play_game("Stones", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_User);
}

// * 1.2. Scissors vs Bag - Winner: User
TEST_F(GameTest, TestScissorsVsBag) {
    enum Choice mock_choice = Choice_Bag;
    Game_Status status = play_game("Scissors", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_User);
}

// * 1.3. Bag vs Stones - Winner: User
TEST_F(GameTest, TestBagVsStones) {
    enum Choice mock_choice = Choice_Stones;
    Game_Status status = play_game("Bag", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_User);
}

// * 2.1. Scissors vs Stones - Winner: Computer
TEST_F(GameTest, TestScissorsVsStones) {
    enum Choice mock_choice = Choice_Stones;
    Game_Status status = play_game("Scissors", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Computer);
}

// * 2.2. Bag vs Scissors - Winner: Computer
TEST_F(GameTest, TestBagVsScissors) {
    enum Choice mock_choice = Choice_Scissors;
    Game_Status status = play_game("Bag", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Computer);
}

// * 2.3. Stones vs Bag - Winner: Computer
TEST_F(GameTest, TestStonesVsBag) {
    enum Choice mock_choice = Choice_Bag;
    Game_Status status = play_game("Stones", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Computer);
}

// * 3.1. Same Stones - Winner: Tie
TEST_F(GameTest, TestStonesVsStones) {
    enum Choice mock_choice = Choice_Stones;
    Game_Status status = play_game("Stones", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Tie);
}

// * 3.2. Same Bag - Winner: Tie
TEST_F(GameTest, TestBagVsBag) {
    enum Choice mock_choice = Choice_Bag;
    Game_Status status = play_game("Bag", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Tie);
}

// * 3.3. Same Scissors - Winner: Tie
TEST_F(GameTest, TestScissorsVsScissors) {
    enum Choice mock_choice = Choice_Scissors;
    Game_Status status = play_game("Scissors", &mock_choice);
    EXPECT_EQ(status, Game_Status_Win_Tie);
}