#include <draw.h>
#include <stdio.h>

void draw_shape(SDL_Renderer *renderer, const Shape *shape) {
    for (int i = 0; i < shape->n; i++) {

        // Connect the last point back to the first point
        if (i == shape->n - 1) {
            Vector2D curr_vert = shape->vertices[i];
            Vector2D last_vert = shape->vertices[0];

            SDL_RenderDrawLineF(renderer, curr_vert.x, curr_vert.y, last_vert.x, last_vert.y);
        }

        // Connect current point and next point
        else {
            // Unpack
            Vector2D curr_vert = shape->vertices[i];
            Vector2D next_vert = shape->vertices[i + 1];

            // Render
            SDL_RenderDrawLineF(renderer, curr_vert.x, curr_vert.y, next_vert.x, next_vert.y);
        }



    }
}
