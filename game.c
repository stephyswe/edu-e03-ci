#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHOICES 3
#define MAX_CHOICE_LEN 10
#define MAX_LINE_LEN 50
#define FILENAME "game_results.txt"

const char *choices[MAX_CHOICES] = {"Stones", "Scissors", "Bag"};

// Function to check if two strings are equal
int strings_are_equal(const char *string1, const char *string2) {
    return strcmp(string1, string2) == 0;
}

enum Game_Status play_game(const char *user_choice,
                           enum Choice *computer_const_choice) {
    // variables
    int computer_choice;
    enum Choice user = -1;
    enum Choice computer = -1;

    // randomize computer choice
    if (computer_const_choice == NULL) {
        // variables for game
        srand(time(NULL));
        computer_choice = rand() % MAX_CHOICES;
    } else {
        computer_choice = *computer_const_choice;
    }

    // convert user choice to enum type
    if (strings_are_equal(user_choice, "Stones")) {
        user = Choice_Stones;
    } else if (strings_are_equal(user_choice, "Scissors")) {
        user = Choice_Scissors;
    } else if (strings_are_equal(user_choice, "Bag")) {
        user = Choice_Bag;
    }

    // convert computer choice to enum type
    if (strings_are_equal(choices[computer_choice], "Stones")) {
        computer = Choice_Stones;
    } else if (strings_are_equal(choices[computer_choice], "Scissors")) {
        computer = Choice_Scissors;
    } else if (strings_are_equal(choices[computer_choice], "Bag")) {
        computer = Choice_Bag;
    }

    // check if it's a tie
    if (user == computer) {
        return Game_Status_Win_Tie;
    }

    // check if user wins
    else if ((user == Choice_Stones && computer == Choice_Scissors) ||
             (user == Choice_Scissors && computer == Choice_Bag) ||
             (user == Choice_Bag && computer == Choice_Stones)) {
        return Game_Status_Win_User;
    }
    // check if computer wins
    else {
        return Game_Status_Win_Computer;
    }
}

char *convertResult(int result) {
    if (result == Game_Status_Win_Computer) {
        return "Computer";
    } else if (result == Game_Status_Win_Tie) {
        return "Tie\t\t";
    } else {
        return "User\t";
    }
}

void save_result(int result, double avg_wins) {
    char date[20];

    // save result to file
    time_t now = time(NULL);

    // format date
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&now));

    FILE *f = fopen(FILENAME, "a");

    // check file
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // write result to file
    fprintf(f, "%s\t%s\t%.2lf%%\n", convertResult(result), date,
            avg_wins * 100.0);
    fclose(f);
}

void read_results(int *num_wins, int *num_games) {
    char line[MAX_LINE_LEN];
    FILE *f = fopen(FILENAME, "r");

    // check file
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // read results from file
    while (fgets(line, sizeof(line), f) != NULL) {
        if (line[0] == '\n') {
            continue;
        }
        char *token = strtok(line, "\t");
        int result = atoi(token);
        if (result == 1) {
            (*num_wins)++;
        }
        (*num_games)++;
    }

    // close file
    fclose(f);
}

int game() {
    // variables for game
    srand(time(NULL));
    int num_wins = 0;
    int num_games = 0;
    double avg_wins = 0.0;

    // read results from file
    read_results(&num_wins, &num_games);

    // calculate average win rate
    if (num_games > 0) {
        avg_wins = (double)num_wins / num_games;
    }

    printf("Game menu\n");

    // play game
    while (1) {
        char user_choice[MAX_CHOICE_LEN];

        printf("Enter your choice (Stones, Scissors, or Bag): ");
        scanf("%s", user_choice);

        // result: 2 computer, 1 tie, 0 user
        enum Game_Status result = play_game(user_choice, NULL);

        if (result == Game_Status_Win_Tie) {
            printf("It's a tie!\n");
        } else if (result == Game_Status_Win_User) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        avg_wins = (double)num_wins / num_games;

        // save result
        save_result(result, avg_wins);

        // update stats
        num_wins += (result == 1);
        num_games++;

        // print stats
        printf("Your average win rate is %.2lf%% (%d/%d).\n\n",
               avg_wins * 100.0, num_wins, num_games);
    }
    return 0;
}
