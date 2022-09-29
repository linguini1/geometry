// Contains utilities for manipulating vectors
#include <math.h>

// Types
typedef struct vector2d {
    float x, y;
} vector2d;

// Constants
extern const float PI;

// Conversion utilities
float degree_to_rad(float degrees);
float rad_to_degrees(float radians);

// Print utilities
void print_vector2d(const vector2d *vector);

// Vector 2D operations
float magnitude2d(const vector2d *vector);
vector2d unit_vector2d(const vector2d *vector);
float distance2d(const vector2d *vector1, const vector2d *vector2);
vector2d add_vectors2d(const vector2d *vector1, const vector2d *vector2);
void scale2d(vector2d *vector, float scale_factor);