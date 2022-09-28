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
void scale_triangle3d(triangle3d *tri, float scale_factor);

triangle2d project_triangle3d(triangle3d *tri, sim_params *simParams);

// Create shapes
shape create_cube(float side_length);
