#include <stdbool.h>

#include "shapes.h"

typedef enum {
    INPUT_RESULT_OK,
    INPUT_RESULT_NO_INPUT,
    INPUT_RESULT_TOO_LONG,
    INPUT_RESULT_INVALID_INPUT
} INPUT_RESULT;

INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize);
void getInputValue(char *param, double *value);
