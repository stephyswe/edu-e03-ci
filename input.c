#define _CRT_SECURE_NO_WARNINGS
#include "input.h"

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shapes.h"

void getInputValue(char *param, double *value) {
    char input[20];
    INPUT_RESULT inputResult;

    while (true) {  // Allow up to 3 attempts
        inputResult = GetInput(param, input, sizeof(input));

        if (inputResult == INPUT_RESULT_OK) {
            // check number is positive
            if (sscanf(input, "%lf", value) == 1 && atoi(input) > 0) {
                break;
            }
        }

        printf("Invalid input, please try again.\n");
    }
};

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

void getValidInput(const char *prompt, InputList *list, char *shape) {
    while (true) {
        printf("%s", prompt);
        scanf("%s", shape);

        // Convert the input shape to lowercase
        for (int i = 0; shape[i]; i++) {
            shape[i] = tolower(shape[i]);
        }

        // Check if the shape is valid
        bool isValid = false;
        for (int i = 0; i < list->numValidList; i++) {
            // If the shape is valid, return it
            if (strcmp(shape, list->validList[i]) == 0) {
                isValid = true;
                break;
            }
        }

        if (isValid) {
            return;
        }

        printf("%s", list->errorMsg);
    }
}
