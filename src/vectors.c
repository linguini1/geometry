// Contains utilities for manipulating vectors
#include <math.h>
#include <vectors.h>

// Constants
const float PI = 3.1415926358f;

// Conversion utilities
float degree_to_rad(float degrees) {
    return degrees * (PI / 180.0f);
}

float rad_to_degrees(float radians) {
    return radians * (180.0f / PI);
}

// Vector 3d operations
float magnitude3d(vector3d vector) {
    return sqrtf(
        vector.x * vector.x +
        vector.y * vector.y +
        vector.z * vector.z
    );
}

vector3d unit_vector3d(vector3d vector) {
    float inv_mag = 1 / magnitude3d(vector);
    vector3d new_vector = {(inv_mag * vector.x), (inv_mag * vector.y), (inv_mag * vector.z)};
    return new_vector;
}

float distance3d(vector3d vector1, vector3d vector2) {
    float dx = (vector2.x - vector1.x);
    float dy = (vector2.y - vector1.y);
    float dz = (vector2.z - vector1.z);
    return (powf(dx, 2) + powf(dy, 2) + powf(dz, 2));
}

vector3d add_vectors3d(vector3d vector1, vector3d vector2) {
    vector3d sum_vector = {(vector1.x + vector2.x), (vector1.y, vector2.y), (vector1.z + vector2.z)};
    return sum_vector;
}

vector3d scale3d(vector3d vector, float scale_factor) {
    vector3d new_vector = {vector.x * scale_factor, vector.y * scale_factor, vector.z * scale_factor};
    return new_vector;
}

// Vector 2D operations
float magnitude2d(vector2d vector) {
    return sqrtf(
            vector.x * vector.x +
            vector.y * vector.y
    );
}

vector2d unit_vector2d(vector2d vector) {
    float inv_mag = 1 / magnitude2d(vector);
    vector2d new_vector = {(inv_mag * vector.x), (inv_mag * vector.y)};
    return new_vector;
}

float distance2d(vector2d vector1, vector2d vector2) {
    float dx = (vector2.x - vector1.x);
    float dy = (vector2.y - vector1.y);
    return (powf(dx, 2) + powf(dy, 2));
}

vector2d add_vectors2d(vector2d vector1, vector2d vector2) {
    vector2d sum_vector = {(vector1.x + vector2.x), (vector1.y, vector2.y)};
    return sum_vector;
}

vector2d scale2d(vector2d vector, float scale_factor) {
    vector2d new_vector = {vector.x * scale_factor, vector.y * scale_factor};
    return new_vector;
}

// Projection
vector2d project3d(vector3d vector, float fNear, float fFar, float fFov, float fAspectRatio) {

    vector3d projected_3d;

    float f = 1/tanf(fFov / 2);
    float q = fFar / (fFar - fNear);

    // Projection
    projected_3d.x = vector.x * fAspectRatio * f;
    projected_3d.y = vector.y * f;
    projected_3d.z = vector.z * q - (q * fNear);

    // Avoid 0 division
    if (vector.z != 0.0f) {
        projected_3d.x /= vector.z;
        projected_3d.y /= vector.z;
        projected_3d.z /= vector.z;
    }

    vector2d projected_2d = {projected_3d.x + 1.0f, projected_3d.y + 1.0f};

    return projected_2d;
}
