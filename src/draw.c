#include <draw.h>
#include <stdio.h>

void draw_shape(SDL_Renderer *renderer, const Shape *shape) {

    Vector2D first_vert = shape->vertices[0]; // First vertex

    for (int i = 0; i < shape->n; i++) {

        // Unpack current vector
        Vector2D curr_vert = shape->vertices[i];

        // Connect the last point back to the first point
        if (i == (shape->n - 1)) {
            SDL_RenderDrawLineF(renderer, curr_vert.x, curr_vert.y, first_vert.x, first_vert.y);
        }
        // Connect current point and next point
        else {
            Vector2D next_vert = shape->vertices[i + 1];
            SDL_RenderDrawLineF(renderer, curr_vert.x, curr_vert.y, next_vert.x, next_vert.y);
        }
    }
}
