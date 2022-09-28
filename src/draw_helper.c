#include <draw_helper.h>
#include <stdio.h>

void draw_triangle2d(SDL_Renderer *renderer, const triangle2d *tri, sim_params *simParams) {

    // Unpack
    vector2d point1 = tri->points[0];
    vector2d point2 = tri->points[1];
    vector2d point3 = tri->points[2];

    // Draw
    SDL_RenderDrawLineF(renderer, point1.x, point1.y, point2.x, point2.y);
    SDL_RenderDrawLineF(renderer, point2.x, point2.y, point3.x, point3.y);
    SDL_RenderDrawLineF(renderer, point3.x, point3.y, point1.x, point1.y);
}