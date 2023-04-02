#include <SDL2/SDL.h>

// Currently uses SDL, but will eventually switch over to a proper renderer

class Renderer {
private:
  int screen_width = 800;
  int screen_height = 400;
  
  SDL_Window* window = NULL;
  SDL_Surface* surface = NULL;
  
public:
  Renderer(); // loads up SDL etc...
  ~Renderer(); // closes all SDL related processes etc..
};