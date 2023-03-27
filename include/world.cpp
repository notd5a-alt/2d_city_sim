#include "world.hpp"

// struct functions
bool Size::operator==(const Size &size) const {
  if (this->x == size.x && this->y == size.y) {
    return true;
  } else {
    return false;
  }
}

bool Size::operator!=(const Size &size) const {
  if (this->x != size.x || this->y != size.y) {
    return true;
  } else {
    return false;
  }
}

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

// copy constructor

World::World(World &world) {
  // create memory
  this->size.x = world.size.x;
  this->size.y = world.size.y;

  this->world = new Tile *[this->size.x];
  for (int i = 0; i < this->size.y; i++) {
    this->world[i] = new Tile[this->size.y];
  }

  // deep copy
  for (int x = 0; x < this->size.x; x++) {
    for (int y = 0; y < this->size.y; y++) {
      this->world[x][y] = world.world[x][y];
    }
  }

  // other things
  this->persons = world.persons;
  this->buildings = world.buildings;
  this->seed = world.seed;
  this->name = world.name;
}

// tile access

Tile World::getTile(int x, int y) { return this->world[x][y]; }

// getters and setters

Size World::getSize() const { return this->size; }

int World::getSizeX() const { return this->size.x; }

int World::getSizeY() const { return this->size.y; }

std::string World::getName() const { return this->name; }

void World::setName(std::string name) { this->name = name; }

int World::getSeed() const { return this->seed; }

// add persons and buildings to world

void World::addPerson(Person person) { this->persons.push_back(person); }

void World::addPersons(std::vector<Person> persons) {
  // this->persons = this->persons + persons; // add 2 persons TODO: operator
  // overload for std::vector<Person>
  for (Person person : persons) {
    this->persons.push_back(person);
  }
}

void World::addBuilding(Building building) {
  this->buildings.push_back(building);
}

void World::addBuildings(std::vector<Building> buildings) {
  for (Building building : buildings) {
    this->buildings.push_back(building);
  }
}

bool populateWorld(World world, int countPeople) {
  // randomly generate 10 people and place them into the world
  std::vector<Person> persons;
  world.persons = persons;

  return true;
}

World World::operator=(World &world) {
  // copy world over, with some precautions
  if (this->size != world.size) { // world size doesnt match
    if (this->world != nullptr) { // if world is pointing to something delete memory
      for (int i = 0; i < this->size.y; i++) {
        delete[] this->world[i];
      }
      
      delete[] this->world;
    }

    // allocate new memory for a new world
    this->size = world.size;
    this->world = new Tile *[this->size.x];
    for (int i = 0; i < this->size.y; i++) {
      this->world[i] = new Tile[this->size.y];
    }
  }

  // since size now matches then copy over all of the data
  for(int x = 0; x < this->size.x; x++) { 
    for(int y = 0; y < this->size.y; y++) {
      this->world[x][y] = world.world[x][y]; 
    }
  }

  // copy over other miscellanious stuff
  this->seed = world.seed;
  this->name = world.name;
  
  this->persons = world.persons;
  this->buildings = world.buildings;

  return *this;
}

World::~World() { // clean up memory

  std::cout << "deleting world of size: {" << size.x << ", " << size.y << "} ."
            << std::endl;
  for (int i = 0; i < this->size.x; i++) {
    delete[] this->world[i];
  }

  delete[] this->world;
}
