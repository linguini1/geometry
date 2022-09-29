// Contains utilities for manipulating vectors
#include <math.h>

// Types
typedef struct Vector2D {
    float x, y;
} Vector2D;

// Constants
extern const float PI;

// Conversion utilities
float degree_to_rad(float degrees);
float rad_to_degrees(float radians);

// Utilities
void print_vector(const Vector2D *vector);
Vector2D copy_vector(const Vector2D *vector);

// Vector 2D operations
float magnitude(const Vector2D *vector);
Vector2D unit_vector(const Vector2D *vector);
float distance(const Vector2D *vector1, const Vector2D *vector2);
Vector2D sum_vectors(const Vector2D *vector1, const Vector2D *vector2);
void scale(Vector2D *vector, float scale_factor);