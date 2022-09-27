#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <SDL.h>

static const int width = 800;
static const int height = 600;
static char window_name[] = "Geometry Visualizer";

int main(int argc, char **argv) {

    // OpenGL params
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

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

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

