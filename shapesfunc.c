#include "input.h"
#include "shapes.h"

Shapes_Status inputRectangle(double *area, double *perimeter) {
    double length, width;
    Shapes_Status status = Shapes_Status_Ok;
    GET_INPUT_VALUE("length: ", &length);
    GET_INPUT_VALUE("width: ", &width);
    return createRectangle(length, width, area, perimeter);
}

Shapes_Status createRectangle(double length, double width, double *area,
                              double *perimeter) {
    if (length <= 0 || width <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = length * width;
    *perimeter = 2 * (length + width);
    return Shapes_Status_Ok;
}

Shapes_Status createTriangle(double base, double height, double *area,
                             double *perimeter) {
    if (base <= 0 || height <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = base * height / 2;
    *perimeter = 2 * (base + height);
    return Shapes_Status_Ok;
}

Shapes_Status inputTriangle(double *area, double *perimeter) {
    double base, height;
    Shapes_Status status;
    GET_INPUT_VALUE("base: ", &base);
    GET_INPUT_VALUE("height: ", &height);
    return createTriangle(base, height, area, perimeter);
}

Shapes_Status createCircle(double radius, double *area,
                           double *perimeter) {
    const double PI = 3.14159265358979323846;
    if (radius <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = PI * radius * radius;
    *perimeter = 2 * PI * radius;
    return Shapes_Status_Ok;
}

Shapes_Status inputCircle(double *area, double *perimeter) {
    double radius;
    Shapes_Status status;
    GET_INPUT_VALUE("radius: ", &radius);
    return createCircle(radius, area, perimeter);
}
