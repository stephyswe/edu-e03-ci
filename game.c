#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gamefunc.h"
#include "input.h"

const char *choices[MAX_CHOICES] = {"Stones", "Scissors", "Bag"};

// Function to check if two strings are equal

enum Game_Status play_game(const char *user_choice,
                           enum Choice *computer_const_choice) {
    enum Choice user = parse_choice(user_choice);
    enum Choice computer = -1;

    if (computer_const_choice == NULL) {
        computer = get_random_choice();
    } else {
        computer = *computer_const_choice;
    }

    return determine_winner(user, computer);
}

int game() {
    printf("Game menu\n");

    int num_wins = 0;
    int num_games = 0;
    double avg_wins = 0.0;

    const char *prompt = "Enter your choice (Stones, Bag, Scissors): ";
    const char *validList[] = {"stones", "bag", "scissors"};
    int numValidList = sizeof(validList) / sizeof(validList[0]);
    char *errorMsg = "Invalid choice \n";

    while (1) {
        char user_choice[MAX_CHOICE_LEN];

        read_file(&num_wins, &num_games);

        getValidInput(prompt, validList, numValidList, errorMsg, user_choice);

        // result: 2 computer, 1 tie, 0 user
        enum Game_Status result = play_game(user_choice, NULL);

        update_statistics(result, &num_wins, &num_games, &avg_wins);

        print_score(result);

        // print stats
        printf("Your average win rate is %.2lf%% (%d/%d).\n\n",
               avg_wins * 100.0, num_wins, num_games);
    }
    return 0;
}
