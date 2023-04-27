#include "shapes.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "input.h"
#include "shapesfunc.h"

// Function to get input values and create a shape
void createShape(const char *const shapeType, double *const area,
                 double *const perimeter) {
    if (STR_EQUAL(shapeType, "rectangle")) {
        double length, width;
        getInputValue("length: ", &length);
        getInputValue("width: ", &width);
        createRectangle(length, width, area, perimeter);
    } else if (STR_EQUAL(shapeType, "triangle")) {
        double base, height;
        getInputValue("base: ", &base);
        getInputValue("height: ", &height);
        createTriangle(base, height, area, perimeter);
    } else if (STR_EQUAL(shapeType, "circle")) {
        double radius;
        getInputValue("radius: ", &radius);
        createCircle(radius, area, perimeter);
    } else if (STR_EQUAL(shapeType, "parallelogram")) {
        double base, height, side;
        getInputValue("base: ", &base);
        getInputValue("height: ", &height);
        getInputValue("side: ", &side);
        createParallelogram(base, height, side, area, perimeter);
    }
}

int shapesMenu() {
    char shape[20];
    double area, perimeter;

    const char *prompt =
        "Enter shape (rectangle, parallelogram, triangle, circle): ";
    const char *validList[] = {"rectangle", "parallelogram", "triangle",
                               "circle", NULL};
    char *errorMsg = "Invalid shape \n";

    printf("Shapes menu\n");

    getValidInput(prompt, validList, errorMsg, shape);

    createShape(shape, &area, &perimeter);

    capitalInput(shape);

    printf("%s area: %.2f\n", shape, area);
    printf("%s perimeter: %.2f\n", shape, perimeter);

    return 0;
}