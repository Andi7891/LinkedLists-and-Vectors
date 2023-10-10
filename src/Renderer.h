#ifndef VECTOR_VISUALIZER_SRC_RENDERER_H_
#define VECTOR_VISUALIZER_SRC_RENDERER_H_

#include "SDL/SDL.h"
#include "Vector.h"
#include "Linked_List.h"
#include <cstdlib>
#include <cstdio>
#include <cassert>

namespace Renderer {

struct Vector {
  Vector2d<float> tail;
  Vector2d<float> head;
};

struct Node {
  Vector content;
  Node *next_ptr;
  Node *prev_ptr;
};

//Get the last node ptr.
Node *get_last_node(Node *head_ptr);

void add_element(Node* head_ptr, Renderer::Vector element);

void delete_list(Node* head_ptr);

Vector add_position_vector(Vector vec_a, Vector vec_b);
void draw_position_vector(SDL_Renderer *renderer, Vector2d<int> window_center, Vector &vec, SDL_Color &color);

class Renderer {
 private:

 public:
  SDL_Renderer * m_sdl_renderer;
  Node* render_vector_list;
 Renderer(SDL_Window* window, bool vsync);
  ~Renderer();

  void new_frame(SDL_Color clear_buffer_color, Vector2d<int> window_size) const;
  void draw_frame(Vector2d<int> window_size) const;
  void render_frame() const;
};
}

#endif //VECTOR_VISUALIZER_SRC_RENDERER_H_
