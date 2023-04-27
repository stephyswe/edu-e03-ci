#include "shapes.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "input.h"
#include "shapesfunc.h"

// Function to get input values and create a shape
Shapes_Status createShape(const char *const shapeType, double *const area,
                          double *const perimeter) {
    if (STR_EQUAL(shapeType, "rectangle")) {
        double length, width;
        getInputValue("length: ", &length);
        getInputValue("width: ", &width);
        return createRectangle(length, width, area, perimeter);
    } else if (STR_EQUAL(shapeType, "triangle")) {
        double base, height;
        getInputValue("base: ", &base);
        getInputValue("height: ", &height);
        return createTriangle(base, height, area, perimeter);
    } else if (STR_EQUAL(shapeType, "circle")) {
        double radius;
        getInputValue("radius: ", &radius);
        return createCircle(radius, area, perimeter);
    } else if (STR_EQUAL(shapeType, "parallelogram")) {
        double base, height, side;
        getInputValue("base: ", &base);
        getInputValue("height: ", &height);
        getInputValue("side: ", &side);
        return createParallelogram(base, height, side, area, perimeter);
    }
    return Shapes_Status_InvalidInput;
}

int shapesMenu() {
    char shape[20];
    double area, perimeter;
    Shapes_Status status = Shapes_Status_InvalidInput;

    // input
    printf("Shapes menu\n");

    read_shape_choice(shape);

    status = createShape(shape, &area, &perimeter);

    if (status == Shapes_Status_Ok) {
        printf("%s area: %.2f\n", shape, area);
        printf("%s perimeter: %.2f\n", shape, perimeter);
    }
    return 0;
}