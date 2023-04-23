#define _CRT_SECURE_NO_WARNINGS
#include "input.h"

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shapes.h"



Shapes_Status getInputValue(char *param, double *value) {
    int numTries = 0;
    char input[20];
    INPUT_RESULT inputResult;

    while (numTries < 3) {  // Allow up to 3 attempts
        inputResult = GetInput(param, input, sizeof(input));

        if (inputResult == INPUT_RESULT_OK) {
            if (sscanf(input, "%lf", value) == 1) {
                return Shapes_Status_Ok;
            }
        }

        numTries++;

        if (numTries < 3) {
            printf("Invalid input, please try again.\n");
        }
    }

    return Shapes_Status_InvalidInput;
};

INPUT_RESULT GetInputDouble(char *prompt, double *value) {
    char input[20];
    INPUT_RESULT inputResult;

    if (prompt != NULL && strlen(prompt) > 0) {
        printf("%s", prompt);
    }

    fflush(stdin);  // Flush input buffer

    inputResult = GetInput(NULL, input, sizeof(input));

    if (inputResult == INPUT_RESULT_OK) {
        if (sscanf(input, "%lf", value) == 1) {
            return INPUT_RESULT_OK;
        } else {
            return INPUT_RESULT_INVALID_INPUT;
        }
    }

    return inputResult;
}

INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize) {
    if (prompt != NULL && strlen(prompt) > 0) {
        printf("%s", prompt);
    }

    fflush(stdin);  // Flush input buffer

    if (fgets(buff, maxSize, stdin) == NULL ||
        (strlen(buff) == 1 && buff[0] == '\n'))
        return INPUT_RESULT_NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff) - 1] != '\n') {
        int extra = 0;
        char ch;
        while (((ch = getchar()) != '\n') && (ch != EOF)) extra = 1;
        return (extra == 1) ? INPUT_RESULT_TOO_LONG : INPUT_RESULT_OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff) - 1] = '\0';
    return INPUT_RESULT_OK;
}
