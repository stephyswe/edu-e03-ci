#include "input.h"

#ifndef __CALCULATOR_H_
#define __CALCULATOR_H_

typedef double (*OperatorFunction)(double, double);

typedef struct {
    char operatorChar;
    OperatorFunction operatorFunction;
} OperatorMapping;

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

void calculatorMenu();

double addition(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double modulus(double num1, double num2);
#endif