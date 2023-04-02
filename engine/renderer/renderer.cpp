#include "renderer.hpp"

Renderer::Renderer() { // initializes SDL and opens a window
  // Try to initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    exit(1);
  } else { // success
    // create window
    window = SDL_CreateWindow("2D CITY SIM", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, screen_width,
                              screen_height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
      exit(1);
    } else {
      surface = SDL_GetWindowSurface(window);
    }
  }
}

Renderer::~Renderer() { // close SDL and subprocesses
  // Deallocate surface
  SDL_FreeSurface(surface);
  surface = NULL;

  // Destroy window
  SDL_DestroyWindow(window);
  window = NULL;

  // Quit SDL Subsystems
  SDL_Quit();
}
