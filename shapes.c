// Utilities for creating shapes
#include "vectors.c"

// Types
typedef struct triangle {
    vector3d points[3];
} triangle;

typedef struct rawShape {
    int vertex_count;
    vector3d vertexes[];
} rawShape;

typedef struct shape {
    int component_count;
    triangle components[];
} shape;

// Build a shape out of components
shape construct_shape(rawShape raw_shape) {
    return 0;
}
