#include "Renderer.h"

namespace Renderer {

SDL_Color red_color = {255, 0, 0, 255};
SDL_Color green_color = {0, 255, 0, 255};
SDL_Color blue_color = {0, 0, 255, 255};
SDL_Color black_color = {0, 0, 0, 255};
SDL_Color white_color = {255, 255, 255, 255};

void draw_grid(SDL_Renderer *renderer, const Vector2d<int> window_size, const SDL_Color &color) {
  //Rectangle
  SDL_FRect rect = {.x = (float)window_size.x / 4.f, .y = (float)window_size.y / 4.f,
                    .w = (float)window_size.x / 2.f, .h = (float)window_size.y / 2.f};

  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawRectF(renderer, &rect);

  //Lines
  SDL_FRect line_x = {.x = 0, .y = (float)window_size.y / 2.f,
                      .w = (float)window_size.x, .h = (float)window_size.y / 2.f};

  SDL_FRect line_y = {.x = (float)window_size.x / 2.f, .y = 0.f,
                      .w = (float)window_size.x / 2.f, .h = (float)window_size.y};

  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLineF(renderer, line_x.x, line_x.y, line_x.w, line_x.h);
  SDL_RenderDrawLineF(renderer, line_y.x, line_y.y, line_y.w, line_y.h);
}

void draw_position_vector(SDL_Renderer *renderer, Vector2d<int> window_center, Vector &vec, SDL_Color &color) {
  //This is the scale, which makes the most sense. You can play with this scale.
  float scale = 20.f;
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLineF(renderer,
                      (float)window_center.x + vec.tail.x * scale,
                      (float)window_center.y - vec.tail.y * scale,
                      (float)window_center.x + vec.head.x * scale,
                      (float)window_center.y - vec.head.y * scale);
}

Vector add_position_vector(Vector vec_a, Vector vec_b) {
  auto temp = Vector{vec_a.tail,{vec_a.head.x + vec_b.head.x,
                                       vec_a.head.y + vec_b.head.y}};
  return temp;
}

Renderer::Renderer::Renderer(SDL_Window *window, bool vsync) {
  m_sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (m_sdl_renderer == nullptr)
    SDL_Log("ErrorRenderer: %s", SDL_GetError());

  SDL_RenderSetVSync(m_sdl_renderer, vsync);

  SDL_RendererInfo info;
  SDL_GetRendererInfo(m_sdl_renderer, &info);
  SDL_Log("Current SDL_Renderer: %s\n", info.name);
}

Renderer::Renderer::~Renderer() {
  SDL_DestroyRenderer(m_sdl_renderer);
  m_sdl_renderer = nullptr;
}

void Renderer::Renderer::new_frame(SDL_Color clear_buffer_color, Vector2d<int> window_size) {
  SDL_SetRenderDrawColor(m_sdl_renderer, clear_buffer_color.r, clear_buffer_color.g,
                                             clear_buffer_color.b, clear_buffer_color.a);
  SDL_RenderClear(m_sdl_renderer);
  draw_grid(m_sdl_renderer, window_size, white_color);
}
void Renderer::Renderer::draw_frame(void (*fun)(SDL_Renderer *, Vector2d<int>), Vector2d<int> window_size) {
  fun(m_sdl_renderer, window_size);
}
void Renderer::Renderer::render_frame() {
  SDL_RenderPresent(m_sdl_renderer);
}
}
