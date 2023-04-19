#include "shapes.h"

#include <stdio.h>
#include <string.h>

#include "input.h"

#define GET_INPUT_VALUE(param, value)     \
    status = getInputValue(param, value); \
    if (status != Shapes_Status_Ok) {     \
        return status;                    \
    }

typedef struct {
    char *name;
    Shapes_Status (*function)(double *, double *);
} ShapeFunction;

Shapes_Status getInputValue(char *param, double *value) {
    int numTries = 0;
    while (numTries < 3) {  // Allow up to 3 attempts
        printf("Enter %s: ", param);
        if (scanf("%lf", value) == 1) {
            return Shapes_Status_Ok;
        }
        numTries++;
        if (numTries < 3) {
            printf("Invalid input, please try again.\n");
            fflush(stdin);  // Flush input buffer
        }
    }
    return Shapes_Status_InvalidInput;
}

Shapes_Status createRectangle(double *area, double *perimeter) {
    double length, width;
    Shapes_Status status;
    GET_INPUT_VALUE("length", &length)
    GET_INPUT_VALUE("width", &width)
    *area = length * width;
    *perimeter = 2 * (length + width);
    return Shapes_Status_Ok;
}

Shapes_Status createTriangle(double *area, double *perimeter) {
    double base, height;
    Shapes_Status status;
    GET_INPUT_VALUE("base", &base);
    GET_INPUT_VALUE("height", &height);
    *area = base * height / 2;
    *perimeter = 2 * (base + height);
    return Shapes_Status_Ok;
}

Shapes_Status createCircle(double *area, double *perimeter) {
    const double PI = 3.14159265358979323846;
    double radius;
    Shapes_Status status;
    GET_INPUT_VALUE("radius", &radius);
    *area = PI * radius * radius;
    *perimeter = 2 * PI * radius;
    return Shapes_Status_Ok;
}

Shapes_Status createParallelogram(double *area, double *perimeter) {
    double base, height, side;
    Shapes_Status status;
    GET_INPUT_VALUE("base", &base);
    GET_INPUT_VALUE("height", &height);
    GET_INPUT_VALUE("side", &side);
    *area = base * height;
    *perimeter = 2 * (base + side);
    return Shapes_Status_Ok;
};

ShapeFunction shapeFunctions[] = {{"rectangle", createRectangle},
                                  {"triangle", createTriangle},
                                  {"circle", createCircle},
                                  {"parallelogram", createParallelogram},
                                  {NULL, NULL}};

Shapes_Status shapesMenu() {
    // Menu
    printf("Shapes menu\n");

    char shape[20];
    double area, perimeter;
    Shapes_Status status;

    do {
        GetInput("Enter shape (rectangle, parallelogram, triangle, circle): ",
                 shape, sizeof(shape));

        ShapeFunction *current = shapeFunctions;
        while (current->name != NULL) {
            if (strcmp(current->name, shape) == 0) {
                status = current->function(&area, &perimeter);
                if (status == Shapes_Status_Ok) {
                    printf("Area: %.2lf\n", area);
                    printf("Perimeter: %.2lf\n", perimeter);
                }
                break;
            }
            current++;
        }

        if (status == Shapes_Status_InvalidShape ||
            GetInput(NULL, NULL, 0) == INPUT_RESULT_INVALID_INPUT) {
            printf("Invalid shape\n");
            status = Shapes_Status_InvalidShape;
        }
    } while (status == Shapes_Status_InvalidShape);

    return status;
}