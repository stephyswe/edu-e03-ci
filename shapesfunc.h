#ifndef __SHAPES_FUNC_H_
#define __SHAPES_FUNC_H_

#include "shapes.h"

Shapes_Status inputRectangle(double *area, double *perimeter);
Shapes_Status createRectangle(double length, double width, double *area,
                              double *perimeter);

Shapes_Status inputTriangle(double *area, double *perimeter);
Shapes_Status createTriangle(double base, double height, double *area,
                             double *perimeter);

#endif