#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

#include "shapes.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef enum {
    INPUT_RESULT_OK,
    INPUT_RESULT_NO_INPUT,
    INPUT_RESULT_TOO_LONG,
    INPUT_RESULT_INVALID_INPUT
} INPUT_RESULT;

typedef struct {
    const char **validList;
    int numValidList;
    const char *errorMsg;
} InputList;

INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize);
void getInputValue(char *param, double *value);
void getValidInput(const char *prompt, const char *validList[],
                   const char *errorMsg, char *shape);
void capitalInput(char *input);

#endif /* INPUT_H */
