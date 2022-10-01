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
    shape->vertices = (Vector2D*) malloc(sizeof(Vector2D));

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
    Shape *circle = create_empty_shape(resolution * 4);
    printf("R=%d\n", resolution * 4);

    // How much to increment x by each time
    float step = radius / (float)resolution;

    // Go through Xs
    for (int i = 0; i < circle->n / 4; i++) {
        float x = step * (float)i;
        float y = sqrtf(radius * radius - x * x);

        // Makes sure points are in order of drawing
        int quad2_index = 4 * resolution - 1 - i;
        int quad3_index = i + 2 * resolution;
        int quad4_index = 2 * resolution - 1 - i;

        printf("%d\n", i);

        // Quad 1
        circle->vertices[i].x = x;
        circle->vertices[i].y = y;

        // Quad 4
        circle->vertices[quad4_index].x = x;
        circle->vertices[quad4_index].y = -y;

        // Quad 3
        circle->vertices[quad3_index].x = -x;
        circle->vertices[quad3_index].y = -y;

        // Quad 2
        circle->vertices[quad2_index].x = -x;
        circle->vertices[quad2_index].y = y;
    }

    return circle;

}
