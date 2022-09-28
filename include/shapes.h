// Utilities for creating shapes
#include <malloc.h>
#include <vectors.h>

// Types
typedef struct triangle {
    vector3d points[3];
} triangle;

typedef struct rawShape {
    int vertex_count;
    triangle *vertexes;
} rawShape;

typedef struct shape {
    int component_count;
    triangle *components;
} shape;

// Build a shape out of components
shape *create_shape(shape *s, int shape_component_count, triangle shape_components[]);

shape create_cube(float side_length);
