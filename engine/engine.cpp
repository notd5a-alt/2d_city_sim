#include "engine.hpp"

Engine::Engine() {
  // initialize the logger
  
  // initialize SDL
  renderer = Renderer();
  
  //Hack to get window to stay up (for now) TODO: Remove this!
  SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
  
}

Engine::~Engine() {

}