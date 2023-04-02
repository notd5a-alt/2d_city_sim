#pragma once
#ifndef TILE_H_
#define TILE_H_

#include <string> 
#include <vector>
#include <cstdlib>
#include <iostream>

#include "building.hpp"
#include "person.hpp"

struct TileCoords {
  int x,y;
  void print() {
    std::cout << "{" << x << ", " << y << "}";
  }
};

struct TileResources { // resources available in a tile
  int stone;
  int wood;
  int oil;
  int water;
};

enum TerrainType {
  FLAT,
  HILLY,
  MOUNTAIN,
  WATER,
};

enum TileState {
  EMPTY, // 0
  FULL // 1
};

class Tile {
private:
  float id; // each tile has a unique ID, can be used to search for tile within the world
  
  TileResources resources;
  TerrainType terrain; // terrain type
  TileState state;
  TileCoords coord; // unqiue coordinate within the world
  
  // contains
  Building building; // only one building can exist on a tile
  std::vector<Person> persons; // but multiple people can exist on a tile

public:
  Tile();
  Tile(int);
  Tile(int, TileCoords);
  Tile(int, TileCoords, TerrainType);
  Tile(int, TileCoords, TerrainType, TileResources);

  float getID();
  
  TileResources getResources() const;
  
  void setResources(TileResources);
  void setResources(int, int, int, int);

  int getResourceStone() const;
  void setResourceStone(int);

  int getResourceWood() const;
  void setResourceWood(int);

  int getResourceOil() const;
  void setResourceOil(int);

  int getResourceWater() const;
  void setResourceWater(int);

  TerrainType getTerrain() const;
  void setTerrain(TerrainType);

  TileState getState() const;
  void setState(TileState);

  TileCoords getCoords() const;

  Building getBuilding() const;
  void placeBuilding(Building);
  void removeBuilding(Building);

  std::vector<Person> getPersons() const;
  void setPersons(std::vector<Person>);
  
  void addPerson(Person); // adds person to tile
  void removePerson(Person); // TODO: figure out impl for this fx when Person class is finished

  // Helper fxs
  
   // remove all buildings and persons and then set all the Tile's attributes to NULL
};

#endif