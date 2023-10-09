#include "App.h"

namespace App {

SDL_Color red_color = {255, 0, 0, 255};
SDL_Color green_color = {0, 255, 0, 255};
SDL_Color blue_color = {0, 0, 255, 255};
SDL_Color black_color = {0, 0, 0, 255};
SDL_Color white_color = {255, 255, 255, 255};

App::App(App_Specs &specs) : m_window_title(specs.window_title),
                             m_window_size(specs.window_size),
                             running(false),
                             m_window(nullptr),
                             m_renderer(nullptr),
                             m_window_flags(),
                             m_event() {
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

  m_renderer = new Renderer::Renderer(m_window, vsync);

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
  delete m_renderer;
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void App::update() {

}

void App::draw(void (*p_function)(SDL_Renderer *, Vector2d<int>)) {
  m_renderer->new_frame(black_color, m_window_size);
  m_renderer->draw_frame(p_function, m_window_size);
  m_renderer->render_frame();
}

}