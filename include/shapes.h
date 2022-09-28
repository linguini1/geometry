// Utilities for creating shapes
#include <malloc.h>
#include <vectors.h>

// Types
typedef struct triangle {
    vector3d points[3];
} triangle;

typedef struct shape {
    int component_count;
    triangle *components;
} shape;


shape create_cube(float side_length);
