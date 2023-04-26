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

enum Choice parse_choice(const char *str) {
    if (strcmp(str, "Stones") == 0) {
        return Choice_Stones;
    } else if (strcmp(str, "Scissors") == 0) {
        return Choice_Scissors;
    } else {
        return Choice_Bag;
    }
};

enum Game_Status play_game(const char *user_choice,
                           enum Choice *computer_const_choice) {
    // variables
    enum Choice user = parse_choice(user_choice);
    enum Choice computer = -1;

    // randomize computer choice if not testing
    if (computer_const_choice == NULL) {
        srand(time(NULL));
        computer = rand() % MAX_CHOICES;
    } else {
        computer = *computer_const_choice;
    }

    // print user and computer choice.
    printf("User: %s\tComputer: %s\n", choices[user], choices[computer]);

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
        // Check if the token starts with "U"
        if (token[0] == 'U') {
            (*num_wins)++;
        }
        (*num_games)++;
    }

    // close file
    fclose(f);
}

void printScore(int result) {
    printf("%s\n", (result == Game_Status_Win_Tie)    ? "It's a tie!"
                   : (result == Game_Status_Win_User) ? "You win!"
                                                      : "Computer wins!");
}

int game() {
    // variables for game
    srand(time(NULL));
    printf("Game menu\n");

    while (1) {
        int num_wins = 0;
        int num_games = 0;
        double avg_wins = 0.0;

        read_results(&num_wins, &num_games);

        printf("num of wins: %d", num_wins);

        char user_choice[MAX_CHOICE_LEN];

        do {
            printf("Please enter 'Bag', 'Stones', or 'Scissors': ");
            scanf("%s", user_choice);
        } while (strcmp(user_choice, "Bag") != 0 &&
                 strcmp(user_choice, "Stones") != 0 &&
                 strcmp(user_choice, "Scissors") != 0);

        // result: 2 computer, 1 tie, 0 user
        enum Game_Status result = play_game(user_choice, NULL);

        printScore(result);

        // update stats
        num_wins += (result == 0);
        num_games++;

        if (num_games > 0) {
            avg_wins = (double)num_wins / num_games;
        }

        // Debugging
        printf("num of wins: %d\n", num_wins);
        printf("num of num_games: %d\n", num_games);
        printf("avg wins: %lf\n", avg_wins);

        // save result
        save_result(result, avg_wins);

        // print stats
        printf("Your average win rate is %.2lf%% (%d/%d).\n\n",
               avg_wins * 100.0, num_wins, num_games);
    }
    return 0;
}
