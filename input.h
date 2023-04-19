#include <stdbool.h>

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
// Returns: bool
INPUT_RESULT GetInputDouble(char *prompt, double *value);