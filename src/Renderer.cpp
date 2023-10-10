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
void delete_list(Node *head_ptr) {
  if (head_ptr == nullptr) return;
  Node* current_ptr = head_ptr;
  Node* next_ptr = nullptr;

  while(current_ptr != nullptr) {
    next_ptr = current_ptr->next_ptr;
    delete current_ptr;
    current_ptr = next_ptr;
  }
}
void add_element(Node *head_ptr, Vector element) {
  auto* new_node = (Node*)nullptr;

  if (head_ptr == nullptr) {
    head_ptr = new Node;
    head_ptr->prev_ptr = nullptr;
    new_node = head_ptr;
  }
  else {
    new_node = new Node;
  }

  new_node->next_ptr = nullptr;
  new_node->content = element;

  auto* last_node = get_last_node(head_ptr);
  last_node->next_ptr = new_node;
  new_node->prev_ptr = last_node;
}
Node *get_last_node(Node *head_ptr) {
  //Check if there is a linked list in the first place :).
  //You can't assume that there will be always a linked list.
  //Assert is used when the program cannot continue because of an error considered impossible to recover from.
  assert(head_ptr != nullptr);

  Node *current_node = head_ptr;
  while (current_node->next_ptr != nullptr) current_node = current_node->next_ptr;
  return current_node;
}

Renderer::Renderer::Renderer(SDL_Window *window, bool vsync) : render_vector_list {nullptr} {
  m_sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (m_sdl_renderer == nullptr)
    SDL_Log("ErrorRenderer: %s", SDL_GetError());

  SDL_RenderSetVSync(m_sdl_renderer, vsync);

  SDL_RendererInfo info;
  SDL_GetRendererInfo(m_sdl_renderer, &info);
  SDL_Log("Current SDL_Renderer: %s\n", info.name);
}

Renderer::Renderer::~Renderer() {
  delete_list(render_vector_list);
  SDL_DestroyRenderer(m_sdl_renderer);
  m_sdl_renderer = nullptr;
}

void Renderer::Renderer::new_frame(SDL_Color clear_buffer_color, Vector2d<int> window_size) const {
  SDL_SetRenderDrawColor(m_sdl_renderer, clear_buffer_color.r, clear_buffer_color.g,
                                             clear_buffer_color.b, clear_buffer_color.a);
  SDL_RenderClear(m_sdl_renderer);
  draw_grid(m_sdl_renderer, window_size, white_color);
}
void Renderer::Renderer::draw_frame(Vector2d<int> window_size) const {
  //fun(m_sdl_renderer, window_size);
  Vector2d<int> window_center = {window_size.x / 2, window_size.y / 2};
  Node* current_ptr = render_vector_list;
  while (render_vector_list != nullptr) {
    printf("%f %f\n", current_ptr->content.head.x, current_ptr->content.head.y);
    draw_position_vector(m_sdl_renderer, window_center, current_ptr->content, white_color);
    current_ptr = current_ptr->next_ptr;
  }
}
void Renderer::Renderer::render_frame() const {
  SDL_RenderPresent(m_sdl_renderer);
}
}
