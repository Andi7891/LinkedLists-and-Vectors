#include "Engine_Core.h"

namespace Engine_Core {

Engine::Engine(char *title, int32_t width, int32_t height, bool vsync)
    : m_title(title),
      m_window(nullptr),
      m_running{false},
      m_vsync(vsync),
      m_event(),
      m_width(width),
      m_height(height),
      m_gl_context(nullptr),
      m_sleep(0),
      m_lastTick(0),
      m_currentTick(0) {

}
Engine::~Engine() {
  SDL_GL_DeleteContext(m_gl_context);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}
void Engine::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_LogCritical(SDL_LOG_PRIORITY_CRITICAL, "SDL initialization failed %s\n", SDL_GetError());
    std::exit(-1);
  }

  //Using OpenGL 4.6 core, I used my opengl version for intel igpu;
  //there it should be an automatic selection of the newest gl version. Not yet implemented.
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  m_window = SDL_CreateWindow(m_title,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              m_width,
                              m_height,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

  if (m_window == nullptr) {
    SDL_LogCritical(SDL_LOG_PRIORITY_CRITICAL, "Creation of the window failed %s\n", SDL_GetError());
    std::exit(-2);
  }

  m_gl_context = SDL_GL_CreateContext(m_window);
  if (m_gl_context == nullptr) {
    SDL_LogCritical(SDL_LOG_PRIORITY_CRITICAL, "Creating gl context failed %s\n", SDL_GetError());
    std::exit(-3);
  }

  auto glew_init_result = glewInit();

  if (glew_init_result != GLEW_OK) {
    SDL_LogCritical(SDL_LOG_PRIORITY_CRITICAL, "%s\n", glewGetErrorString(glewInit()));
    std::exit(-4);
  }

  if (m_vsync) {
    //Try with adaptive sync, if there is no support go for the synchronized one.
    SDL_ClearError();
    if (SDL_GL_SetSwapInterval(-1) != 0)
      if (SDL_GL_SetSwapInterval(1) != 0)
        SDL_LogError(SDL_LOG_PRIORITY_WARN, "Set vsync failed, %s\n", SDL_GetError());
  } else {
    SDL_GL_SetSwapInterval(0); //No sync.
  }

  ON_DEBUG(SDL_Log("OpenGL %s\nGLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION)));

  ON_DEBUG(SDL_Log("Vsync status %d\n", SDL_GL_GetSwapInterval()));

  m_running = true;
}
void Engine::process_events() {
  if (m_vsync)
    m_lastTick = SDL_GetTicks();
  while (SDL_PollEvent(&m_event)) {
    if (m_event.quit.type == SDL_QUIT || m_event.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) {
      m_running = false;
    }
  }
}
void Engine::update() {

}
void Engine::draw() {

  //Vsync
  if (m_vsync) {
    m_currentTick = SDL_GetTicks();
    //wait the appropriate amount of time
    m_sleep = m_milliPeriod - (int) (m_currentTick - m_lastTick);
    if (m_sleep < 0) m_sleep = 0;
    SDL_Delay(m_sleep);
  }
}
void Engine::shutdown() {
  this->~Engine();
}
bool Engine::status() const {
  return m_running;
}} // Engine