// Contains utilities for manipulating vectors
#include <math.h>

// Types
typedef struct vector3d {
    float x, y, z;
} vector3d;

typedef struct vector2d {
    float x, y;
} vector2d;

typedef struct sim_params {
    float near;
    float far;
    float fov;
    float aspect_ratio;
    vector2d origin2d;
    vector3d origin3d;
} sim_params;

// Constants
extern const float PI;

// Conversion utilities
float degree_to_rad(float degrees);
float rad_to_degrees(float radians);

// Print utilities
void print_vector2d(const vector2d *vector);
void print_vector3d(const vector3d *vector);

// Vector 3d operations
float magnitude3d(const vector3d *vector);
vector3d unit_vector3d(const vector3d *vector);
float distance3d(const vector3d *vector1, const vector3d *vector2);
vector3d add_vectors3d(const vector3d *vector1, const vector3d *vector2);
void scale3d(vector3d *vector, float scale_factor);

// Vector 2D operations
float magnitude2d(const vector2d *vector);
vector2d unit_vector2d(const vector2d *vector);
float distance2d(const vector2d *vector1, const vector2d *vector2);
vector2d add_vectors2d(const vector2d *vector1, const vector2d *vector2);
void scale2d(vector2d *vector, float scale_factor);

// Projection
