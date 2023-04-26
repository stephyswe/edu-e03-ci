// game.h

#ifndef GAME_H
#define GAME_H

#define MAX_CHOICES 3
#define MAX_CHOICE_LEN 10
#define MAX_LINE_LEN 50
#define FILENAME "game_results.txt"

enum Game_Status {
    Game_Status_Win_User,
    Game_Status_Win_Tie,
    Game_Status_Win_Computer
};

enum Choice {
    Choice_Stones,
    Choice_Scissors,
    Choice_Bag,
};

enum Game_Status play_game(const char *user_choice,
                           enum Choice *computer_const_choice);
int game();

#endif  // GAME_H
