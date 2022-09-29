// Contains utilities for manipulating vectors
#include <math.h>
#include <vectors.h>
#include <stdio.h>

// Constants
const float PI = 3.1415926358f;

// Conversion utilities
float degree_to_rad(float degrees) {
    return degrees * (PI / 180.0f);
}

float rad_to_degrees(float radians) {
    return radians * (180.0f / PI);
}

// Print utilities
void print_vector2d(const vector2d *vector) {
    printf("(%f, %f)\n", vector->x, vector->y);
}

void print_vector3d(const vector3d *vector) {
    printf("(%f, %f, %f)\n", vector->x, vector->y, vector->z);
}

// Vector 3d operations
float magnitude3d(const vector3d *vector) {
    return sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}

vector3d unit_vector3d(const vector3d *vector) {
    float inv_mag = 1 / magnitude3d(vector);
    return (vector3d) {(inv_mag * vector->x), (inv_mag * vector->y), (inv_mag * vector->z)};
}

float distance3d(const vector3d *vector1, const vector3d *vector2) {
    float dx = (vector2->x - vector1->x);
    float dy = (vector2->y - vector1->y);
    float dz = (vector2->z - vector1->z);
    return (powf(dx, 2) + powf(dy, 2) + powf(dz, 2));
}

vector3d add_vectors3d(const vector3d *vector1, const vector3d *vector2) {
    return (vector3d) {(vector1->x + vector2->x), (vector1->y + vector2->y), (vector1->z + vector2->z)};
}

void scale3d(vector3d *vector, float scale_factor) {
    vector->x *= scale_factor;
    vector->y *= scale_factor;
    vector->z *= scale_factor;
}

// Vector 2D operations
float magnitude2d(const vector2d *vector) {
    return sqrtf(vector->x * vector->x + vector->y * vector->y);
}

vector2d unit_vector2d(const vector2d *vector) {
    float inv_mag = 1 / magnitude2d(vector);
    return (vector2d) {(inv_mag * vector->x), (inv_mag * vector->y)};
}

float distance2d(const vector2d *vector1, const vector2d *vector2) {
    float dx = (vector2->x - vector1->x);
    float dy = (vector2->y - vector1->y);
    return (powf(dx, 2) + powf(dy, 2));
}

vector2d add_vectors2d(const vector2d *vector1, const vector2d *vector2) {
    return (vector2d) {(vector1->x + vector2->x), (vector1->y + vector2->y)};
}

void scale2d(vector2d *vector, float scale_factor) {
    vector->x *= scale_factor;
    vector->y *= scale_factor;
}

// Projection

