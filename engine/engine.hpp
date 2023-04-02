#pragma once
#ifndef ENGINE_H_
#define ENGINE_H_

#include "../include/world.hpp"
#include "renderer/renderer.hpp"
#include "logger/owl.hpp"

class Engine {
private:
  Renderer renderer;
  // World world;

public:
  Engine();
  ~Engine();
};

#endif