
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"

enum Choice parse_choice(const char *str) {
    if (strcmp(str, "Stones") == 0) {
        return Choice_Stones;
    } else if (strcmp(str, "Scissors") == 0) {
        return Choice_Scissors;
    } else {
        return Choice_Bag;
    }
};

enum Choice get_random_choice() {
    srand(60);
    return rand() % MAX_CHOICES;
}

enum Game_Status determine_winner(enum Choice user, enum Choice computer) {
    if (user == computer) {
        return Game_Status_Win_Tie;
    } else if ((user == Choice_Stones && computer == Choice_Scissors) ||
               (user == Choice_Scissors && computer == Choice_Bag) ||
               (user == Choice_Bag && computer == Choice_Stones)) {
        return Game_Status_Win_User;
    } else {
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
    FILE *f = fopen(FILENAME, "a");
    char date[20];
    time_t now = time(NULL);

    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&now));
    // write result to file
    fprintf(f, "%s\t%s\t%.2lf%%\n", convertResult(result), date,
            avg_wins * 100.0);
    fclose(f);
}

void read_file(int *num_wins, int *num_games) {
    char line[MAX_LINE_LEN];
    FILE *f = fopen(FILENAME, "r");

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
    fclose(f);
}

void print_score(int result) {
    printf("%s\n", (result == Game_Status_Win_Tie)    ? "It's a tie!"
                   : (result == Game_Status_Win_User) ? "You win!"
                                                      : "Computer wins!");
}

// Update the statistics based on the result of a single game
void update_statistics(enum Game_Status result, int *num_wins, int *num_games,
                       double *avg_wins) {
    // update stats
    *num_wins += (result == 0);
    *num_games += 1;
    if (*num_games > 0) {
        *avg_wins = (double)*num_wins / *num_games;
    }

    // Debugging
    printf("num of wins: %d\n", *num_wins);
    printf("num of num_games: %d\n", *num_games);
    printf("avg wins: %lf\n", *avg_wins);

    // save result
    save_result(result, *avg_wins);
}
