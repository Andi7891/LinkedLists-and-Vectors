#include <cstdio>

#include "SDL/SDL.h"

void draw_grid(SDL_Renderer *renderer,
               const SDL_Point &window_size,
               const SDL_Color &color) {
  //Rectangle
  SDL_Rect rect = {.x = window_size.x / 4, .y = window_size.y / 4, .w = window_size.x / 2, .h = window_size.y / 2};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawRect(renderer, &rect);

  //Lines
  SDL_Rect rect_x = {.x = 0, .y = window_size.y / 2, .w = window_size.x, .h = window_size.y / 2};
  SDL_Rect rect_y = {.x = window_size.x / 2, .y = 0, .w = window_size.x / 2, .h = window_size.y};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(renderer, rect_x.x, rect_x.y, rect_x.w, rect_x.h);
  SDL_RenderDrawLine(renderer, rect_y.x, rect_y.y, rect_y.w, rect_y.h);
}

struct Vector {
  SDL_Point origin;
  SDL_Point tail;
  SDL_Point head;
};

void draw_vector(SDL_Renderer *renderer, Vector &vec, SDL_Color &color) {
  int scale = 20;
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(renderer,
                     vec.origin.x + vec.tail.x * scale,
                     vec.origin.y - vec.tail.y * scale,
                     vec.origin.x + vec.head.x * scale,
                     vec.origin.y - vec.head.y * scale);
}

Vector add_v(Vector vec_a, Vector vec_b) {
  auto temp = Vector{vec_a.origin,
                     vec_a.tail,
                     (SDL_Point) {vec_a.head.x + vec_b.head.x, vec_a.head.y + vec_b.head.y}};
  return temp;
}

int main(int argc, char **argv) {
  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) printf("ErrorInitialization: %s", SDL_GetError());

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_Point windowSize = {640, 480};
  const char *title = "Window_Title";

  auto window_flags = (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_Window *windowPtr = SDL_CreateWindow(title,
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           windowSize.x,
                                           windowSize.y,
                                           window_flags);

  if (windowPtr == nullptr) printf("ErrorWindow: %s", SDL_GetError());

  SDL_Renderer *rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);
  if (rendererPtr == nullptr) printf("ErrorRenderer: %s", SDL_GetError());

  bool vsync = true;
  vsync ? SDL_RenderSetVSync(rendererPtr, 1) : SDL_RenderSetVSync(rendererPtr, 0);

  SDL_RendererInfo info;
  SDL_GetRendererInfo(rendererPtr, &info);
  SDL_Log("Current SDL_Renderer: %s\n", info.name);

  bool quit = false;
  SDL_Event event;

  SDL_Point origin = {(windowSize.x / 2), (windowSize.y / 2)};

  Vector vec_a = {origin, (SDL_Point) {0, 0}, (SDL_Point) {2, 3}};
  Vector vec_b = {origin, (SDL_Point) {0, 0}, (SDL_Point) {3, 3}};
  Vector vec_s = add_v(vec_a, vec_b);

  SDL_Color white_color = {255, 255, 255, 255};
  SDL_Color red_color = {255, 0, 0, 255};
  SDL_Color green_color = {0, 255, 0, 255};
  SDL_Color blue_color = {0, 0, 255, 255};

  while (!quit) {
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE)
        quit = true;

    SDL_SetRenderDrawColor(rendererPtr, 0, 0, 0, 255);
    SDL_RenderClear(rendererPtr);

    draw_grid(rendererPtr, windowSize, white_color);
    draw_vector(rendererPtr, vec_a, red_color);
    draw_vector(rendererPtr, vec_b, green_color);
    draw_vector(rendererPtr, vec_s, blue_color);

    SDL_RenderPresent(rendererPtr);
  }

  SDL_DestroyRenderer(rendererPtr);
  SDL_DestroyWindow(windowPtr);

  SDL_Quit();
  return 0;
}