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

typedef double (*OperatorFunction)(double, double);

double calculateAddiction(double num1, double num2) {
    if (num1 == 0 && num2 == 0) return Calculator_Status_InvalidInput;
    return num1 + num2;
}

double subtract(double num1, double num2) { return num1 - num2; }

double multiply(double num1, double num2) { return num1 * num2; }

double divide(double num1, double num2) { return num1 / num2; }

double modulus(double num1, double num2) { return fmod(num1, num2); }

#define GET_INPUT(prompt, var)                                               \
    while ((status = getInputValue(prompt, &var)) != Calculator_Status_Ok) { \
        printf("Invalid input for " #var ". Please try again.\n");           \
    }

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

    printf("Maximum number of attempts reached. Defaulting to '+'.\n");
    return '+';
}

OperatorFunction opFunction = NULL;

typedef struct {
    const char* operatorString;
    OperatorFunction operatorFunction;
} OperatorMapping;

OperatorMapping operatorMappings[] = {{"+", calculateAddiction},
                                      {"-", subtract},
                                      {"*", multiply},
                                      {"/", divide},
                                      {"%", modulus}};

OperatorFunction getOperatorFunction(char op) {
    for (int i = 0; i < sizeof(operatorMappings) / sizeof(OperatorMapping);
         i++) {
        if (op == *(operatorMappings[i].operatorString)) {
            return operatorMappings[i].operatorFunction;
        }
    }
    return NULL;
}

void calculatorMenu() {
    printf("Calculator\n");

    double num1, num2, result;
    char op;
    Calculator_Status status = Calculator_Status_Ok;

    GET_INPUT("num1: ", num1);
    GET_INPUT("num2: ", num2);

    op = getValidOperator();
    // Perform the operation
    result = getOperatorFunction(op)(num1, num2);
    if (op == '/' || op == '%') {
        if (num2 == 0) {
            printf("Error: Division by zero.\n");
            return;
        }
    }

    printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
}