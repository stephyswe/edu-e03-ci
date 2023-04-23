#include "shapes.h"

#include <stdio.h>
#include <string.h>

#include "input.h"
#include "shapesfunc.h"

typedef struct {
    char *name;
    Shapes_Status (*function)(double *, double *);
} ShapeFunction;


Shapes_Status createParallelogram(double *area, double *perimeter) {
    double base, height, side;
    Shapes_Status status;
    GET_INPUT_VALUE("base: ", &base);
    GET_INPUT_VALUE("height: ", &height);
    GET_INPUT_VALUE("side: ", &side);
    *area = base * height;
    *perimeter = 2 * (base + side);
    return Shapes_Status_Ok;
};

ShapeFunction shapeFunctions[] = {{"rectangle", inputRectangle},
                                  {"triangle", inputTriangle},
                                  {"circle", inputCircle},
                                  {"parallelogram", createParallelogram},
                                  {NULL, NULL}};

Shapes_Status shapesMenu() {
    char shape[20];
    double area, perimeter;
    Shapes_Status status;
    // Create a variable to hold the user's input.
    char *prompt = "Enter shape (rectangle, parallelogram, triangle, circle): ";

    // Print the shapes menu.
    printf("Shapes menu\n");

    do {
        // Get the user's shape input.
        GetInput(prompt, shape, sizeof(shape));

        // Look for the matching shape function.
        ShapeFunction *current = shapeFunctions;

        // loop through the shape functions until we find a match.
        while (current->name != NULL) {
            // If the current shape function matches
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