#include "App.h"

SDL_Color red_color = {255, 0, 0, 255};
SDL_Color green_color = {0, 255, 0, 255};
SDL_Color blue_color = {0, 0, 255, 255};

struct Vector {
  SDL_Point tail;
  SDL_Point head;
};

void draw_vector(SDL_Renderer *renderer, Vector2d window_center, Vector &vec, SDL_Color &color) {
  int scale = 20;
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(renderer,
                     (int)window_center.x + vec.tail.x * scale,
                     (int)window_center.y - vec.tail.y * scale,
                     (int)window_center.x + vec.head.x * scale,
                     (int)window_center.y - vec.head.y * scale);
}

Vector add_v(Vector vec_a, Vector vec_b) {
  auto temp = Vector{vec_a.tail,
                     (SDL_Point) {vec_a.head.x + vec_b.head.x,
                                  vec_a.head.y + vec_b.head.y}};
  return temp;
}

void draw_content(SDL_Renderer *renderer, const Vector2d* window_center) {
  Vector vec_a = {(SDL_Point) {0, 0}, (SDL_Point) {2, 3}};
  Vector vec_b = {(SDL_Point) {0, 0}, (SDL_Point) {3, 3}};
  Vector vec_s = add_v(vec_a, vec_b);

  draw_vector(renderer, *window_center, vec_a, red_color);
  draw_vector(renderer, *window_center, vec_b, green_color);
  draw_vector(renderer, *window_center, vec_s, blue_color);
}

int main(int argc, char **argv) {
  auto specs = (App::App_Specs) {{640, 480},
                                 "Window Title"};
  auto *application = new App::App(specs);

  auto window_flags = (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  application->init(window_flags, true);

  while (application->running) {
    application->process_events();
    application->update();
    application->draw(&draw_content);
  }

  application->exit();
  delete application;

  return 0;
}