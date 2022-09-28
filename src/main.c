#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <SDL.h>
#include <shapes.h>

// Window parameters
static const int width = 800;
static const int height = 600;
static char window_name[] = "Geometry Visualizer";

// Simulation parameters
float fNear = 1;
float fFar = 10;
float fFov = 90.0f;
float fAspectRatio = (float)width / (float)height;

int main(int argc, char **argv) {

    // OpenGL params
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    // Simulation params
    float fFovRad = degree_to_rad(fFov);

    // Start SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow(
        window_name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC // Accelerated and in sync with monitor refresh rate
    );

    bool running = true;
    SDL_Event event;

    while (running) {

        // Process events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black bg
        SDL_RenderClear(renderer);

        // Draw
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White stroke
        shape cube = create_cube(50);

        for (int i = 0; i < cube.component_count; i++) {
            triangle component = cube.components[i];
            vector3d point1 = component.points[0];
            vector3d point2 = component.points[1];
            vector3d point3 = component.points[2];

            SDL_RenderDrawLineF(renderer, point1.x, point1.y, point2.x, point2.y);
            SDL_RenderDrawLineF(renderer, point2.x, point2.y, point3.x, point3.y);
            SDL_RenderDrawLineF(renderer, point3.x, point3.y, point1.x, point1.y);
        }

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
