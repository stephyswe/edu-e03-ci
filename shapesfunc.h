#ifndef __SHAPES_FUNC_H_
#define __SHAPES_FUNC_H_

#include "shapes.h"

Shapes_Status inputRectangle(double *area, double *perimeter);
Shapes_Status createRectangle(double length, double width, double *area,
                              double *perimeter);

Shapes_Status inputTriangle(double *area, double *perimeter);
Shapes_Status createTriangle(double base, double height, double *area,
                             double *perimeter);

Shapes_Status inputCircle(double *area, double *perimeter);
Shapes_Status createCircle(double radius, double *area, double *perimeter);

Shapes_Status inputParallelogram(double *area, double *perimeter);
Shapes_Status createParallelogram(double base, double height, double side, double *area,
                                  double *perimeter);

#endif