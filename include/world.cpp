#include "world.hpp"

// constructors

World::World() {
  this->size.x = WORLD_SIZE_X;
  this->size.y = WORLD_SIZE_Y;

  world = new Tile *[size.x];

  for (int x = 0; x < size.x; x++) {
    world[x] = new Tile[size.y];
  }

  float ctr = rand();
  for (int x = 0; x < size.x; x++) {
    for (int y = 0; y < size.y; y++) {
      this->world[x][y] = Tile(ctr, {x, y});
      ctr++;
    }
  }

  this->persons = {};
  this->buildings = {};

  this->seed = 0;
  this->name = "\0";
}

World::World(Size size) {
  this->size.x = size.x;
  this->size.y = size.y;

  world = new Tile *[size.x];
  for (int x = 0; x < size.x; x++) {
    world[x] = new Tile[size.y];
  }

  float ctr = rand();
  for (int x = 0; x < this->size.x; x++) {
    for (int y = 0; y < this->size.y; y++) {
      this->world[x][y] = Tile(ctr, {x, y});
      ctr++;
    }
  }

  this->persons = {};
  this->buildings = {};

  this->seed = rand();
  this->name = "";
}

World::World(int seed, Size size) {
  this->size.x = size.x;
  this->size.y = size.y;

  world = new Tile *[size.x];
  for (int x = 0; x < size.x; x++) {
    world[x] = new Tile[size.y];
  }

  float ctr = rand();
  for (int x = 0; x < this->size.x; x++) {
    for (int y = 0; y < this->size.y; y++) {
      this->world[x][y] = Tile(ctr, {x, y});
      ctr++;
    }
  }

  this->persons = {};
  this->buildings = {};

  this->seed = seed;
  this->name = "";
}

World::World(int seed, Size size, std::string name) {
  this->size.x = size.x;
  this->size.y = size.y;

  world = new Tile *[size.x];
  for (int x = 0; x < size.x; x++) {
    world[x] = new Tile[size.y];
  }

  float ctr = rand();
  for (int x = 0; x < this->size.x; x++) {
    for (int y = 0; y < this->size.y; y++) {
      this->world[x][y] = Tile(ctr, {x, y});
      ctr++;
    }
  }

  this->persons = {};
  this->buildings = {};

  this->seed = seed;
  this->name = name;
}

// tile access

Tile World::getTile(int x, int y) {
  return this->world[x][y];
}

// getters and setters

Size World::getSize() const {
  return this->size;
}

int World::getSizeX() const {
  return this->size.x;
}

int World::getSizeY() const {
  return this->size.y;
}

std::string World::getName() const {
  return this->name;
}

void World::setName(std::string name) {
  this->name = name;
}

int World::getSeed() const {
  return this->seed;
}

// add persons and buildings to world

void World::addPerson(Person person) {
  this->persons.push_back(person);
}

void World::addPersons(std::vector<Person> persons) {
  // this->persons = this->persons + persons; // add 2 persons TODO: operator overload for std::vector<Person>
  for(Person person : persons) {
    this->persons.push_back(person);
  } 
}

void World::addBuilding(Building building) {
  this->buildings.push_back(building);
}

void World::addBuildings(std::vector<Building> buildings) {
  for(Building building : buildings) {
    this->buildings.push_back(building);
  }
}


World::~World() { // clean up memory

  std::cout << "deleting world of size: {" << size.x << ", " << size.y << "} ." << std::endl;
  for(int i = 0; i < this->size.x; i++) {
    delete[] this->world[i];
  }

  delete[] this->world;
}
