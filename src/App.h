#ifndef VECTOR_VISUALIZER_SRC_APP_H_
#define VECTOR_VISUALIZER_SRC_APP_H_

#include <cstdio>

#include "SDL/SDL.h"
#include "Vector.h"
#include "Renderer.h"

namespace App {

struct App_Specs {
  Vector2d<int> window_size;
  const char* window_title;
};

class App {
 private:
  Vector2d<int> m_window_size;
  const char* m_window_title;

  SDL_Window* m_window;
  Vector2d<int> m_window_center;
  SDL_WindowFlags m_window_flags;

  Renderer::Renderer* m_renderer;

  SDL_Event m_event;
 public:
  bool running;

  explicit App(App_Specs& specs);
  ~App() = default;

  void init(SDL_WindowFlags window_flags, bool vsync);
  void process_events();
  void update();
  void draw(void (*p_function)(SDL_Renderer *, Vector2d<int>));
  void exit();
};

}

#endif //VECTOR_VISUALIZER_SRC_APP_H_
