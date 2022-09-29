// Utilities for creating shapes
#include <shapes.h>
#include <stdio.h>

// Utilities
void scale_triangle3d(triangle3d *tri, float scale_factor) {
    scale3d(&(tri->points[0]), scale_factor);
    scale3d(&(tri->points[1]), scale_factor);
    scale3d(&(tri->points[2]), scale_factor);
}

triangle2d project_triangle3d(triangle3d *tri, sim_params *simParams) {
    vector2d point1 = project3d(&(tri->points[0]), simParams);
    vector2d point2 = project3d(&(tri->points[1]), simParams);
    vector2d point3 = project3d(&(tri->points[2]), simParams);

    return (triangle2d) {point1, point2, point3};
}

void translate_triangle3d(triangle3d *tri, vector3d *translation) {
    for (int i = 0; i < 3; i ++) {
        vector3d translated_vector = add_vectors3d(&(tri->points[i]), translation);
        printf("(%f, %f, %f)\n", tri->points[i].x, tri->points[i].y, tri->points[i].z);
        (*tri).points[i] = translated_vector;
    }
}

// Scale shapes
shape create_cube(float side_length) {

    // Vertices
    vector3d corner1 = {0.0f, 0.0f, 0.0f};
    vector3d corner2 = {0.0f, side_length, 0.0f};
    vector3d corner3 = {side_length, side_length, 0.0f};
    vector3d corner4 = {side_length, 0.0f, 0.0f};
    vector3d corner5 = {0.0f, 0.0f, -side_length};
    vector3d corner6 = {side_length, 0.0f, -side_length};
    vector3d corner7 = {0.0f, side_length, -side_length};
    vector3d corner8 = {side_length, side_length, -side_length};

    // Components
    triangle3d components[] = {
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

    return (shape) {12, components};
}
