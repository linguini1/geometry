#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <draw_helper.h>

// Window parameters
static const int width = 500;
static const int height = 500;
static char window_name[] = "Geometry Visualizer";

// Simulation parameters
sim_params simulation_parameters = {
        1.0f,
        10.0f,
        90.0f,
        (float)width / (float)height,
        {(float)width / 2, (float)height / 2},
        {(float)width / 2, (float)height / 2, 10.0f}
};

int main(int argc, char **argv) {

    // OpenGL params
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    // Simulation params
    simulation_parameters.fov = degree_to_rad(simulation_parameters.fov);

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

    // Initialize assets
    vector3d vec = {0.0f, 0.0f, 0.0f};
    vector3d vec2 = {1.0f, 0.0f, -2.0f};
    vector3d vec3 = {0.0f, 1.0f, 0.0f};
    float scale_factor = 50.0f;
    scale3d(&vec, scale_factor);
    scale3d(&vec2, scale_factor);
    scale3d(&vec3, scale_factor);


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

        vector3d vec_1 = add_vectors3d(&vec, &simulation_parameters.origin3d);
        vector3d vec2_1 = add_vectors3d(&vec2, &simulation_parameters.origin3d);
        vector3d vec3_1 = add_vectors3d(&vec3, &simulation_parameters.origin3d);

        SDL_RenderDrawLineF(renderer, vec_1.x, vec_1.y, vec2_1.x, vec2_1.y);
        SDL_RenderDrawLineF(renderer, vec2_1.x, vec2_1.y, vec3_1.x, vec3_1.y);
        SDL_RenderDrawLineF(renderer, vec3_1.x, vec3_1.y, vec_1.x, vec_1.y);

        float scalar = 1.005f;
        scale3d(&vec, scalar);
        scale3d(&vec2, scalar);
        scale3d(&vec3, scalar);

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
