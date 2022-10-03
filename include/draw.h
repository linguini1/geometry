#include <shapes.h>
#include <SDL.h>

// Types
typedef struct Axes {
    // Each axis contains upper and lower limits
    Vector2D x_axis[2];
    Vector2D y_axis[2];
} Axes;

Axes create_axes(const Vector2D *origin, float width, float height);

// Drawing
void draw_shape(SDL_Renderer *renderer, const Shape *shape);
void draw_axes(SDL_Renderer *renderer, const Axes *axes);