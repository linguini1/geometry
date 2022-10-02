#include <shapes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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

    Shape *shape = (Shape*) malloc(sizeof(Shape));
    shape->n = n;
    shape->vertices = (Vector2D*) malloc(n * sizeof(Vector2D));

    return shape;
}

Shape *create_square(float side_length) {

    Vector2D vertices[4] = {
            0.0f, 0.0f,
            0.0f, side_length,
            side_length, side_length,
            side_length, 0.0f
    };

    Shape *square = create_empty_shape(4);
    square->vertices[0].x = 0;
    square->vertices[0].y = 0;
    square->vertices[1].x = 0;
    square->vertices[1].y = side_length;
    square->vertices[2].x = side_length;
    square->vertices[2].y = side_length;
    square->vertices[3].x = side_length;
    square->vertices[3].y = 0;

    return square;
}

Shape *create_circle(float radius, int resolution) {

    // Define shape
    Shape *circle = create_empty_shape(resolution * 2);

    // How much to increment x by each time
    float step = 2 * radius / (float)resolution;

    // Go through Xs
    for (int i = 0; i < resolution; i++) {
        float x = -radius + step * (float)i;
        float y = sqrtf(radius * radius - x * x);

        // Top half
        circle->vertices[i].x = x;
        circle->vertices[i].y = y;

        // Bottom half
        circle->vertices[resolution + i].x = -x;
        circle->vertices[resolution + i].y = -y;
    }

    return circle;

}
