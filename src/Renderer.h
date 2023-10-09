#ifndef VECTOR_VISUALIZER_SRC_RENDERER_H_
#define VECTOR_VISUALIZER_SRC_RENDERER_H_

#include "SDL/SDL.h"
#include "Vector.h"

namespace Renderer {

struct Vector {
  Vector2d<float> tail;
  Vector2d<float> head;
};

Vector add_position_vector(Vector vec_a, Vector vec_b);
void draw_position_vector(SDL_Renderer *renderer, Vector2d<int> window_center, Vector &vec, SDL_Color &color);

class Renderer {
 private:

 public:
  SDL_Renderer * m_sdl_renderer;

 Renderer(SDL_Window* window, bool vsync);
  ~Renderer();

  void new_frame(SDL_Color clear_buffer_color, Vector2d<int> window_size);
  void draw_frame(void (*fun)(SDL_Renderer *, Vector2d<int>), Vector2d<int> window_size);
  void render_frame();
};
}

#endif //VECTOR_VISUALIZER_SRC_RENDERER_H_
