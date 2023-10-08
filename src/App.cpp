#include "App.h"

namespace App {
SDL_Color white_color = {255, 255, 255, 255};

void draw_grid(SDL_Renderer *renderer,
               const Vector2d window_size,
               const SDL_Color &color) {
  //Rectangle
  SDL_Rect rect = {.x = static_cast<int>(window_size.x / 4),
      .y = static_cast<int>(window_size.y / 4),
      .w = static_cast<int>(window_size.x / 2),
      .h = static_cast<int>(window_size.y / 2)};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawRect(renderer, &rect);

  //Lines
  SDL_Rect line_x = {.x = 0,
      .y = static_cast<int>(window_size.y / 2),
      .w = static_cast<int>(window_size.x),
      .h = static_cast<int>(window_size.y / 2)};

  SDL_Rect line_y = {.x = static_cast<int>(window_size.x / 2),
      .y = 0,
      .w = static_cast<int>(window_size.x / 2),
      .h = static_cast<int>(window_size.y)};

  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(renderer, line_x.x, line_x.y, line_x.w, line_x.h);
  SDL_RenderDrawLine(renderer, line_y.x, line_y.y, line_y.w, line_y.h);
}

App::App(App_Specs &specs) : m_window_title(specs.window_title),
                             m_window_size(specs.window_size),
                             running(false),
                             m_window(nullptr),
                             m_renderer(nullptr),
                             m_window_center(),
                             m_window_flags(),
                             m_event() {
  m_window_center = {(m_window_size.x / 2), (m_window_size.y / 2)};

  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) printf("ErrorInitialization: %s", SDL_GetError());

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void App::init(SDL_WindowFlags window_flags, bool vsync) {
  m_window_flags = window_flags;

  m_window = SDL_CreateWindow(m_window_title,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              (int) m_window_size.x,
                              (int) m_window_size.y,
                              m_window_flags);

  if (m_window == nullptr)
    printf("ErrorWindow: %s", SDL_GetError());

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == nullptr)
    printf("ErrorRenderer: %s", SDL_GetError());

  SDL_RenderSetVSync(m_renderer, vsync);

  SDL_RendererInfo info;
  SDL_GetRendererInfo(m_renderer, &info);
  SDL_Log("Current SDL_Renderer: %s\n", info.name);

  running = true;
}

void App::process_events() {
  while (SDL_PollEvent(&m_event)) {
    if (m_event.type == SDL_QUIT ||
        m_event.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) {
        running = false;
    }
  }
}

void App::exit() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void App::update() {

}

void App::draw(void (*fun)(SDL_Renderer *, const Vector2d *)) {
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  draw_grid(m_renderer, m_window_size, white_color);

  fun(m_renderer, &m_window_center);

  SDL_RenderPresent(m_renderer);
}

}