// Contains utilities for manipulating vectors
#include <math.h>

// Types
typedef struct vector3d {
    float x, y, z;
} vector3d;

typedef struct vector2d {
    float x, y;
} vector2d;

typedef struct matrix4x4 {
    float matrix[4][4];
} matrix4x4;

// Constants
extern const float PI;

// Conversion utilities
float degree_to_rad(float degrees);

float rad_to_degrees(float radians);

// Vector 3d operations
float magnitude3d(vector3d vector);

vector3d unit_vector3d(vector3d vector);

float distance3d(vector3d vector1, vector3d vector2);

vector3d add_vectors3d(vector3d vector1, vector3d vector2);

vector3d scale3d(vector3d vector, float scale_factor);

// Vector 2D operations
float magnitude2d(vector2d vector);

vector2d unit_vector2d(vector2d vector);

float distance2d(vector2d vector1, vector2d vector2);

vector2d add_vectors2d(vector2d vector1, vector2d vector2);

vector2d scale2d(vector2d vector, float scale_factor);

// Projection
vector2d project3d(vector3d vector, float fNear, float fFar, float fFov, float fAspectRatio);
