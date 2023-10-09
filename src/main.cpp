#include "App.h"

void draw_content(SDL_Renderer *renderer, Vector2d<int> window_size) {
  SDL_Color red_color = {255, 0, 0, 255};
  SDL_Color green_color = {0, 255, 0, 255};
  SDL_Color blue_color = {0, 0, 255, 255};
  SDL_Color white_color = {255, 255, 255, 255};

  Vector2d<int> window_center = {window_size.x / 2, window_size.y / 2};

  Renderer::Vector vec_a = {{0, 0}, {2, 3}};
  Renderer::Vector vec_b = {{0, 0}, {3, 1}};
  Renderer::Vector vec_s = Renderer::add_position_vector(vec_a, vec_b);

  Renderer::draw_position_vector(renderer, window_center, vec_a, red_color);
  Renderer::draw_position_vector(renderer, window_center, vec_b, green_color);
  Renderer::draw_position_vector(renderer, window_center, vec_s, blue_color);
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