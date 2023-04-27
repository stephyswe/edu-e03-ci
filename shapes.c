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

void getValidShape(const char *prompt, char *shape) {
    const char *validShapes[] = {"rectangle", "parallelogram", "triangle",
                                 "circle"};
    while (true) {
        printf(prompt);
        scanf("%s", shape);

        // Convert the input shape to lowercase
        for (int i = 0; shape[i]; i++) {
            shape[i] = tolower(shape[i]);
        }

        // Check if the shape is valid
        for (int i = 0; i < sizeof(validShapes) / sizeof(validShapes[0]); i++) {
            // If the shape is valid, return it
            if (strcmp(shape, validShapes[i]) == 0) {
                return;
            }
        }

        printf("Invalid shape. \n");
    }
}

int shapesMenu() {
    char shape[20];
    double area, perimeter;
    Shapes_Status status = Shapes_Status_InvalidInput;
    char *prompt = "Enter shape (rectangle, parallelogram, triangle, circle): ";

    printf("Shapes menu\n");

    // Use the original 'shape' variable to store the result of getValidShape
    getValidShape(prompt, shape);

    status = createShape(shape, &area, &perimeter);

    if (status == Shapes_Status_Ok) {
        printf("%s area: %.2f\n", shape, area);
        printf("%s perimeter: %.2f\n", shape, perimeter);
    }
    return 0;
}