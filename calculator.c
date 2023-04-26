#include "calculator.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

double addition(double num1, double num2) { return num1 + num2; }

double subtract(double num1, double num2) { return num1 - num2; }

double multiply(double num1, double num2) { return num1 * num2; }

double divide(double num1, double num2) { return num1 / num2; }

double modulus(double num1, double num2) { return fmod(num1, num2); }

char getValidOperator() {
    const char* VALID_OPERATORS = "+-*/%";
    char op;

    do {
        printf("Enter operator (%s): ", VALID_OPERATORS);
        scanf(" %c%*[^\n]", &op);
        scanf("%*c");
        if (strchr(VALID_OPERATORS, op) == NULL) {
            printf("Invalid operator. Please try again.\n");
        }
    } while (strchr(VALID_OPERATORS, op) == NULL);

    return op;
}

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
    double num1, num2, result;
    char op;

    printf("Calculator menu\n");

    getInputValue("num1: ", &num1);
    getInputValue("num2: ", &num2);

    op = getValidOperator();
    // Perform the operation
    result = getOperatorFunction(op)(num1, num2);

    printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
}
