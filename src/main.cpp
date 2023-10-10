#include "App.h"
#include "Linked_List.h"

int main(int argc, char **argv) {
  auto specs = (App::App_Specs) {{640, 480},
                                 "Window Title"};
  auto *application = new App::App(specs);

  auto window_flags = (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  application->init(window_flags, true);

  auto entity_list = application->get_entity_list();

  Renderer::Vector vec_a = {{0, 0}, {2, 3}};
  Renderer::Vector vec_b = {{0, 0}, {3, 1}};
  Renderer::Vector vec_s = Renderer::add_position_vector(vec_a, vec_b);

  add_element(*entity_list, vec_a);
  add_element(*entity_list, vec_b);
  add_element(*entity_list, vec_s);

  while (application->get_running_status()) {
    application->process_events();
    application->update();
    application->draw();
  }

  application->exit();
  delete application;

  return 0;
}