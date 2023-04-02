#include "tile.hpp"

Tile::Tile() {
  this->id = rand();

  this->resources = {};
  this->terrain = FLAT;
  this->state = EMPTY;
  this->coord = {};

  this->building = {};
  this->persons = {};
}

Tile::Tile(int id) { // empty tile
  this->id = id;

  this->resources = {};
  this->terrain = FLAT;
  this->state = EMPTY;
  this->coord = {};

  this->building = {};
  this->persons = {};
}

Tile::Tile(int id, TileCoords coord) {
  this->id = id;

  this->resources = {};
  this->terrain = FLAT;
  this->state = EMPTY;
  this->coord = coord;

  this->building = {};
  this->persons = {};
}

Tile::Tile(int id, TileCoords coord, TerrainType terrain) {
  this->id = id;

  this->resources = {};
  this->terrain = terrain;
  this->state = EMPTY;
  this->coord = coord;

  this->building = {};
  this->persons = {};
}

Tile::Tile(int id, TileCoords coord, TerrainType terrain,
           TileResources resources) {
  this->id = id;

  this->resources = resources;
  this->terrain = terrain;
  this->state = EMPTY;
  this->coord = coord;

  this->building = {};
  this->persons = {};
}

// getters and setters

// tile id

float Tile::getID() { return this->id; }

// tile resources

TileResources Tile::getResources() const { return this->resources; }

void Tile::setResources(TileResources resources) {
  this->resources = resources;
}

void Tile::setResources(int stone, int wood, int oil, int water) {
  this->resources = {stone, wood, oil, water};
}

int Tile::getResourceStone() const { return this->resources.stone; }

void Tile::setResourceStone(int stone) { this->resources.stone = stone; }

int Tile::getResourceWood() const { return this->resources.wood; }

void Tile::setResourceWood(int wood) { this->resources.wood = wood; }

int Tile::getResourceOil() const { return this->resources.oil; }

void Tile::setResourceOil(int oil) { this->resources.oil = oil; }

int Tile::getResourceWater() const { return this->resources.water; }

void Tile::setResourceWater(int water) { this->resources.water = water; }

// tile terrain

TerrainType Tile::getTerrain() const { return this->terrain; }

void Tile::setTerrain(TerrainType terrain) { this->terrain = terrain; }

// tile state

TileState Tile::getState() const { return this->state; }

void Tile::setState(TileState state) { this->state = state; }

// coords

TileCoords Tile::getCoords() const { return this->coord; }

// building functions

Building Tile::getBuilding() const { return this->building; }

void Tile::placeBuilding(Building building) { this->building = building; }

void Tile::removeBuilding(Building building) { this->building = {}; }

// person functions

std::vector<Person> Tile::getPersons() const { return this->persons; }

void Tile::setPersons(std::vector<Person> persons) { this->persons = persons; }

void Tile::addPerson(Person person) { this->persons.push_back(person); }

void Tile::removePerson(Person person) {
  // figure out impl
}
