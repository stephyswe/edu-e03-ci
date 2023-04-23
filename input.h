#include <stdbool.h>

#include "shapes.h"

#define STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
#define GET_INPUT_VALUE(param, value)     \
    status = getInputValue(param, value); \
    if (status != Shapes_Status_Ok) {     \
        return status;                    \
    }

typedef enum {
    INPUT_RESULT_OK,
    INPUT_RESULT_NO_INPUT,
    INPUT_RESULT_TOO_LONG,
    INPUT_RESULT_INVALID_INPUT
} INPUT_RESULT;

// Function: GetInput
// Description: Get input type int
// Parameters: char *prompt, char *buff, int maxSize
// Returns: INPUT_RESULT
INPUT_RESULT GetInput(char *prompt, char *buff, int maxSize);

// Function: GetInputDouble
// Description: Get input type double
// Parameters: char *prompt, double *value
// Returns: INPUT_RESULT
INPUT_RESULT GetInputDouble(char *prompt, double *value);

Shapes_Status getInputValue(char *param, double *value);
