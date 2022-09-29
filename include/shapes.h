#include <vectors.h>

// Types
typedef struct Shape {
    int n;
    Vector2D *vertices;
} Shape;

// Utilities
void print_shape(const Shape *shape);

// Operations
void translate_shape(const Shape *shape, const Vector2D *translation);

// Starters
Shape create_square(float side_length);
