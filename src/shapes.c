#include <shapes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Utilities
void print_shape(const Shape *shape) {
    printf("Shape of %d vertices:\n", shape->n); // Label

    for (int i = 0; i < shape->n; i++) {
        print_vector(&(shape->vertices[i])); // Vertices
    }
}

// Operations
void translate_shape(Shape *shape, const Vector2D *translation) {
    for (int i = 0; i < shape->n; i++) {
        translate_vector(&(shape->vertices[i]), translation);
    }
}

void scale_shape(Shape *shape, float scale_factor) {
    for (int i = 0; i < shape->n; i++) {
        scale(&(shape->vertices[i]), scale_factor);
    }
}

// Starters
Shape *create_shape(int n, Vector2D *vertices) {

    Shape *shape = malloc(sizeof(Shape) + n * sizeof(Vector2D));
    shape->n = n;
    memcpy(shape->vertices, vertices, sizeof(*vertices));

    return shape;
}

Shape *create_empty_shape(int n) {

    Shape *shape = malloc(sizeof(Shape) + n * sizeof(Vector2D));
    shape->n = n;

    return shape;
}

Shape create_square(float side_length) {

    Shape *square = create_empty_shape(4);
    square->vertices[0].x = 0;
    square->vertices[0].y = 0;
    square->vertices[1].x = 0;
    square->vertices[1].y = side_length;
    square->vertices[2].x = side_length;
    square->vertices[2].y = side_length;
    square->vertices[3].x = side_length;
    square->vertices[3].y = 0;

    return *square;
}
