#include "shapes.h"

#include <stdio.h>
#include <string.h>

#include "input.h"
#include "shapesfunc.h"

typedef struct {
    char *name;
    Shapes_Status (*function)(double *, double *);
} ShapeFunction;

ShapeFunction shapeFunctions[] = {{"rectangle", inputRectangle},
                                  {"triangle", inputTriangle},
                                  {"circle", inputCircle},
                                  {"parallelogram", inputParallelogram},
                                  {NULL, NULL}};

Shapes_Status createShape(char *shape, Shapes_Status status) {
    double area, perimeter;

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

    if (status == Shapes_Status_InvalidShape) {
        printf("Invalid shape\n");
    }

    return status;
}

int shapesMenu() {
    char shape[20];
    Shapes_Status status = Shapes_Status_InvalidShape;
    char *prompt = "Enter shape (rectangle, parallelogram, triangle, circle): ";

    printf("Shapes menu\n");
    while (status == Shapes_Status_InvalidShape) {
        GetInput(prompt, shape, sizeof(shape));
        status = createShape(shape, status);
    }
    return 0;
}