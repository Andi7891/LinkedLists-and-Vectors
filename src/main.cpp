#include "GL/glew.h" //Never include glew after SDL.
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "Core/Engine_Core.h"

int main(int argc, char **argv) {
  auto engine = new Engine_Core::Engine((char*)"Window_Title", 640, 480, true);
  engine->init();

  while(engine->status()) {
    engine->process_events();
    engine->update();
    engine->draw();
  }

  delete engine;
  return 0;
}