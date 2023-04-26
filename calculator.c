#include <math.h>
#include <stdio.h>
#include <string.h>

#include "input.h"

typedef enum {
    Calculator_Status_Ok = 0,
    Calculator_Status_InvalidInput = 1,
    Calculator_Status_DivideByZero = 2
} Calculator_Status;

#define OPERATOR_ADD '+'
#define OPERATOR_SUB '-'
#define OPERATOR_MUL '*'
#define OPERATOR_DIV '/'
#define OPERATOR_MOD '%'

#define GET_INPUT(prompt, var)                                               \
    while ((status = getInputValue(prompt, &var)) != Calculator_Status_Ok) { \
        printf("Invalid input for " #var ". Please try again.\n");           \
    }

typedef double (*OperatorFunction)(double, double);

double addition(double num1, double num2) { return num1 + num2; }

double subtract(double num1, double num2) { return num1 - num2; }

double multiply(double num1, double num2) { return num1 * num2; }

double divide(double num1, double num2) { return num1 / num2; }

double modulus(double num1, double num2) { return fmod(num1, num2); }

// what does fmod do?
// is fmod same as modulus operator? Answer is yes

char getValidOperator() {
    const char* VALID_OPERATORS = "+-*/%";
    char op;

    while (true) {
        printf("Enter operator (%s): ", VALID_OPERATORS);
        scanf(" %c", &op);

        // Check if the first character of the input is a valid operator
        if (op != '\n' && strchr(VALID_OPERATORS, op) != NULL) {
            // Clear the input buffer
            scanf("%*[^\n]");
            scanf("%*c");
            return op;
        } else {
            printf("Invalid operator. Please try again.\n");
            // clear the input buffer
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }
}

OperatorFunction opFunction = NULL;

typedef struct {
    char operatorChar;
    OperatorFunction operatorFunction;
} OperatorMapping;

OperatorMapping operatorMappings[] = {{OPERATOR_ADD, addition},
                                      {OPERATOR_SUB, subtract},
                                      {OPERATOR_MUL, multiply},
                                      {OPERATOR_DIV, divide},
                                      {OPERATOR_MOD, modulus}};

OperatorFunction getOperatorFunction(char op) {
    for (int i = 0; i < sizeof(operatorMappings) / sizeof(OperatorMapping);
         i++) {
        if (op == operatorMappings[i].operatorChar) {
            return operatorMappings[i].operatorFunction;
        }
    }
    return NULL;
}

void calculatorMenu() {
    printf("Calculator menu\n");

    double num1, num2, result;
    char op;
    Calculator_Status status = Calculator_Status_Ok;

    GET_INPUT("num1: ", num1);
    GET_INPUT("num2: ", num2);

    op = getValidOperator();
    // Perform the operation
    result = getOperatorFunction(op)(num1, num2);

    printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
}
