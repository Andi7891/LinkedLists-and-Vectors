#ifndef VECTOR_VISUALIZER_3D_ENGINE_CORE_H_
#define VECTOR_VISUALIZER_3D_ENGINE_CORE_H_

#include "SDL/SDL.h"
#include "GL/glew.h"

namespace Engine_Core {
#define DEBUG
#include "Engine_Core_Utils.h"

class Engine {
 public:
  Engine(char *title, int32_t width, int32_t height, bool vsync);
  ~Engine();

  void init();
  void process_events();
  void update();
  void draw();

  void shutdown();

  [[nodiscard]] bool status() const;
 private:
  SDL_Window *m_window;
  SDL_GLContext m_gl_context;
  SDL_Event m_event;

  char *m_title;
  int32_t m_width;
  int32_t m_height;

  bool m_running;
  bool m_vsync;

  //Vsync
  const int m_FPS = 24;
  //calculate the period
  double m_period = (1.0 / (double) m_FPS) * 1000;
  int m_milliPeriod = (int) m_period;
  int m_sleep;
  Uint32 m_lastTick;
  Uint32 m_currentTick;
};

} // Engine

#endif //VECTOR_VISUALIZER_3D_ENGINE_CORE_H_
