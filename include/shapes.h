// Utilities for creating shapes
#include <vectors.h>

// Types
typedef struct triangle3d {
    vector3d points[3];
} triangle3d;

typedef struct triangle2d {
    vector2d points[3];
} triangle2d;


typedef struct shape {
    int component_count;
    triangle3d *components;
} shape;

// Utilities

