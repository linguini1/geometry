// Utilities for creating shapes
#include <malloc.h>
#include <shapes.h>

// Build a shape out of components
shape *create_shape(shape *s, int shape_component_count, triangle shape_components[]) {

    // Allocate memory for variable length components array
    s = malloc(sizeof(*s) + sizeof(triangle) * shape_component_count);
    s -> component_count = shape_component_count;
    s -> components = shape_components;
}

shape create_cube(float side_length) {

    // Vertices
    vector3d corner1 = {0.0f, 0.0f, 0.0f};
    vector3d corner2 = {0.0f, 1.0f, 0.0f};
    vector3d corner3 = {1.0f, 1.0f, 0.0f};
    vector3d corner4 = {1.0f, 0.0f, 0.0f};
    vector3d corner5 = {0.0f, 0.0f, -1.0f};
    vector3d corner6 = {1.0f, 0.0f, -1.0f};
    vector3d corner7 = {0.0f, 1.0f, -1.0f};
    vector3d corner8 = {1.0f, 1.0f, -1.0f};

    // Components
    triangle components[] = {
            {corner1, corner2, corner3},
            {corner1, corner3, corner4},
            {corner1, corner2, corner7},
            {corner1, corner7, corner5},
            {corner5, corner7, corner8},
            {corner5, corner8, corner6},
            {corner4, corner3, corner8},
            {corner4, corner8, corner6},
            {corner1, corner5, corner6},
            {corner1, corner6, corner4},
            {corner2, corner7, corner8},
            {corner2, corner8, corner3}
    };

    shape cube = {12, components};
    return cube;
}
