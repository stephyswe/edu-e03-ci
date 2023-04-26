#ifndef __SHAPES_H_
#define __SHAPES_H_

#include <stdbool.h>

#define STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)

typedef enum {
    Shapes_Status_Ok,
    Shapes_Status_InvalidShape,
    Shapes_Status_InvalidInput,
} Shapes_Status;

typedef struct {
    double area;
    double perimeter;
} Shapes;

typedef struct {
    char *name;
    Shapes_Status (*function)(double *, double *);
} ShapeFunction;

int shapesMenu();

#endif
