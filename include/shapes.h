#include <vectors.h>

// Types
typedef struct Shape {
    int n;
    Vector2D *vertices;
} Shape;

// Utilities
void print_shape(const Shape *shape);

// Operations
void translate_shape(Shape *shape, const Vector2D *translation);
void scale_shape(Shape *shape, float scale_factor);

// Starters
Shape *create_shape(int n, Vector2D *vertices);
Shape *create_empty_shape(int n);
Shape *create_square(float side_length);
Shape *create_circle(float radius, int resolution);
