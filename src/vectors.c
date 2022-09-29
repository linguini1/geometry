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

// Utilities
void print_vector(const Vector2D *vector) {
    printf("(%f, %f)\n", vector->x, vector->y);
}

Vector2D copy_vector(const Vector2D *vector) {
    return (Vector2D) {vector->x, vector->y};
}

// Vector 2D operations
float magnitude(const Vector2D *vector) {
    return sqrtf(vector->x * vector->x + vector->y * vector->y);
}

Vector2D unit_vector(const Vector2D *vector) {
    float inv_mag = 1 / magnitude(vector);
    return (Vector2D) {(inv_mag * vector->x), (inv_mag * vector->y)};
}

float distance(const Vector2D *vector1, const Vector2D *vector2) {
    float dx = (vector2->x - vector1->x);
    float dy = (vector2->y - vector1->y);
    return (powf(dx, 2) + powf(dy, 2));
}

Vector2D sum_vectors(const Vector2D *vector1, const Vector2D *vector2) {
    return (Vector2D) {(vector1->x + vector2->x), (vector1->y + vector2->y)};
}

void scale(Vector2D *vector, float scale_factor) {
    vector->x *= scale_factor;
    vector->y *= scale_factor;
}
