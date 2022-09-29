#include <shapes.h>
#include <stdio.h>

// Utilities
void print_shape(const Shape *shape) {
    printf("Shape of %d vertices:\n", shape->n); // Label

    for (int i = 0; i < shape->n; i++) {
        print_vector(&(shape->vertices[i])); // Vertices
    }
}

// Operations
void translate_shape(const Shape *shape, const Vector2D *translation) {
    for (int i = 0; i < shape->n; i++) {
        sum_vectors(&(shape->vertices[i]), translation);
    }
}

// Starters
Shape create_square(float side_length) {

    // Define vertices
    Vector2D vertices[4] = {
            {0, 0}, {0, 1}, {1, 1}, {1, 0}
    };

    return (Shape) {4, vertices};
}
