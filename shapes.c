#include "shapes.h"

#include <stdio.h>
#include <string.h>

#include "input.h"

#define STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
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
    char input[20];
    INPUT_RESULT inputResult;

    while (numTries < 3) {  // Allow up to 3 attempts
        inputResult = GetInput(param, input, sizeof(input));

        if (inputResult == INPUT_RESULT_OK) {
            if (sscanf(input, "%lf", value) == 1) {
                return Shapes_Status_Ok;
            }
        }

        numTries++;

        if (numTries < 3) {
            printf("Invalid input, please try again.\n");
        }
    }

    return Shapes_Status_InvalidInput;
};

Shapes_Status inputRectangle(double *area, double *perimeter) {
    double length, width;
    Shapes_Status status;
    GET_INPUT_VALUE("length", &length);
    GET_INPUT_VALUE("width", &width);
    createRectangle(length, width, area, perimeter);
    return Shapes_Status_Ok;
}

Shapes_Status createRectangle(double length, double width, double *area, double *perimeter) {
    if (length <= 0 || width <= 0) {
        return Shapes_Status_InvalidInput;
    }

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

ShapeFunction shapeFunctions[] = {{"rectangle", inputRectangle},
                                  {"triangle", createTriangle},
                                  {"circle", createCircle},
                                  {"parallelogram", createParallelogram},
                                  {NULL, NULL}};

Shapes_Status shapesMenu() {
    // Print the shapes menu.
    printf("Shapes menu\n");

    char shape[20];
    double area, perimeter;
    Shapes_Status status;
    char *prompt = "Enter shape (rectangle, parallelogram, triangle, circle): ";

    do {
        // Get the user's shape input.
        GetInput(prompt, shape, sizeof(shape));

        // Look for the matching shape function.
        ShapeFunction *current = shapeFunctions;
        while (current->name != NULL) {
            if (STR_EQUAL(current->name, shape)) {
                // Call the shape function to create the shape.
                status = current->function(&area, &perimeter);

                // Print the area and perimeter of the shape.
                if (status == Shapes_Status_Ok) {
                    printf("Area: %.2lf\n", area);
                    printf("Perimeter: %.2lf\n", perimeter);
                }
                break;
            }
            current++;
        }

        // If the user's input is invalid or the shape was not found, print an
        // error message and try again.
        if (status == Shapes_Status_InvalidShape ||
            GetInput(NULL, NULL, 0) == INPUT_RESULT_INVALID_INPUT) {
            printf("Invalid shape\n");
            status = Shapes_Status_InvalidShape;
        }
    } while (status == Shapes_Status_InvalidShape);

    // Return the status of the shape creation.
    return status;
}