#include <draw_helper.h>
#include <stdio.h>

void draw_triangles(SDL_Renderer *renderer, const triangle *tri, sim_params *simParams) {

    // Unpack points
    vector3d point1 = tri->points[0];
    vector3d point2 = tri->points[1];
    vector3d point3 = tri->points[2];

    printf("%f, %f\n", point1.x, point1.y);
    printf("%f, %f\n", point2.x, point2.y);
    printf("%f, %f\n", point3.x, point3.y);

    // Draw
    SDL_RenderDrawLineF(renderer, point1.x, point1.y, point2.x, point2.y);
    SDL_RenderDrawLineF(renderer, point2.x, point2.y, point3.x, point3.y);
    SDL_RenderDrawLineF(renderer, point3.x, point3.y, point1.x, point1.y);
}