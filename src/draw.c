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

Axes create_axes(const Vector2D *origin, float width, float height) {
    return (Axes) {
            {0, origin->y, width, origin->y},
            {origin->x, 0, origin->x, height}
    };
}

void draw_axes(SDL_Renderer *renderer, const Axes *axes) {

    // Draw X axis
    SDL_RenderDrawLineF(
            renderer,
            axes->x_axis[0].x, axes->x_axis[0].y,
            axes->x_axis[1].x, axes->x_axis[1].y
    );

    // Draw Y axis
    SDL_RenderDrawLineF(
            renderer,
            axes->y_axis[0].x, axes->y_axis[0].y,
            axes->y_axis[1].x, axes->y_axis[1].y
    );
}
