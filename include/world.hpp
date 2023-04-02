#pragma once
#ifndef WORLD_H_
#define WORLD_H_

#include <ios>
#include <string>
#include <vector>

#include "tile.hpp"
#include "player.hpp"
#include "person.hpp"
#include "building.hpp"

const int WORLD_SIZE_X = 50; // default world size x
const int WORLD_SIZE_Y = 50; // default world size y

struct Size {
  int x, y;
  bool operator==(const Size&) const;
  bool operator!=(const Size&) const;
};

class World {
private:
  Tile **world = nullptr; // 2d array of tiles, actual world
  Size size;
  
  std::vector<Person> persons;
  std::vector<Building> buildings;
  
  int seed; // unused for now, should be randomized, 
  std::string name; // world name

public:
  World(); // creates an empty world of set size from global variables
  World(Size); // creates a world of defined size x,y
  World(int, Size); // creates a world with defined seed and size int x, y
  World(int, Size, std::string); // creates world with defined seed, Size and name

  // copy constructor
  World(World&);

  Tile getTile(int, int);

  Size getSize() const; // returns world size as Size type
  int getSizeX() const; // returns world size x
  int getSizeY() const; // returns world size y

  std::string getName() const; // returns world name
  void setName(std::string); // sets world name

  int getSeed() const; // returns world seed

  void addPerson(Person); // adds a person to the world
  void addPersons(std::vector<Person>); // adds multiple persons to the world
  
  void addBuilding(Building); // adds a building to the world
  void addBuildings(std::vector<Building>); // adds multiple buildings to the world

  // helper fx's 
  friend bool populateWorld(World, int); // w num of people
  World operator=(World&);

  // destructor
  ~World();
};

#endif