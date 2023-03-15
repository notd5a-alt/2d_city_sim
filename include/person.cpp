#include "person.hpp"

Person::Person(float id) { // initialize person with an ID
  this->id = id;
  this->life_status = true; // alive
  this->partner_id = -1;    // no partner yet
  this->name = "";
  this->age = 0;
  this->state = FREE;
  this->attributes = {0, 0, 0, 0};
  this->status = {100, 100}; // default hp and stamina levels
  this->gender = MALE;
}

Person::Person(float id, Loc location) {
  this->id = id;
  this->location = location;

  this->life_status = true; // alive
  this->partner_id = -1;    // no partner yet
  this->name = "";
  this->age = 0;
  this->state = FREE;
  this->attributes = {0, 0, 0, 0};
  this->status = {100, 100}; // default hp and stamina levels

  this->gender = MALE;
}

Person::Person(float id, int x, int y, float tile_id) {
  this->id = id;
  this->location = {x, y, tile_id, -1}; // -1 for no building

  this->life_status = true; // alive
  this->partner_id = -1;    // no partner yet
  this->name = "";
  this->age = 0;
  this->state = FREE;
  this->attributes = {0, 0, 0, 0};
  this->status = {100, 100}; // default hp and stamina levels

  this->gender = MALE;
}

Person::Person(float id, Loc location, Parents parents, std::string name,
               Gender gender) {
  this->id = id;
  this->location = location;

  this->life_status = true; // alive
  this->partner_id = -1;    // no partner yet
  this->parents = parents;

  this->name = name;

  this->age = 0;
  this->state = FREE;
  this->attributes = {0, 0, 0, 0};
  this->status = {100, 100}; // default hp and stamina levels

  this->gender = gender;
}

Person::Person(float id, int x, int y, Parents parents, float tile_id,
               std::string name, Gender gender) {
  this->id = id;
  this->location = {x, y, tile_id, -1};

  this->life_status = true; // alive
  this->partner_id = -1;    // no partner yet
  this->parents = parents;

  this->name = name;

  this->age = 0;
  this->state = FREE;
  this->attributes = {0, 0, 0, 0};
  this->status = {100, 100}; // default hp and stamina levels

  this->gender = gender;
}

// getters and setters
float Person::getID() const { return this->id; }

bool Person::alive() const { return life_status; }
bool Person::kill() { // kills a person
  this->life_status = false;
  return life_status;
}

std::string Person::getName() const { return this->name; }
void Person::setName(std::string name) { this->name = name; }

int Person::getAge() const { return this->age; }
void Person::setAge(int age) { this->age = age; }
void Person::incAge() { this->age++; }

Gender Person::getGender() const { return this->gender; }
void Person::setGender(Gender gender) { this->gender = gender; }

Loc Person::getLocation() const { return this->location; }
int Person::getLocX() const { return this->location.x; }
int Person::getLocY() const { return this->location.y; }
float Person::getTileID() const { return this->location.tile_id; }
float Person::getBuildingID() const { return this->location.building_id; }

State Person::getState() const { return this->state; }
void Person::setState(State state) { this->state = state; }

Attributes Person::getAttributes() const { return this->attributes; }
void Person::setAttributes(Attributes attributes) {
  this->attributes = attributes;
}
void Person::setAttributes(float strength, float intelligence, float speed,
                           float dexterity) {
  this->attributes = {strength, intelligence, speed, dexterity};
}

Status Person::getStatus() const { return this->status; }
int Person::getHealth() const { return this->status.health; }
int Person::getStamina() const { return this->status.stamina; }

void Person::setStatus(Status status) { this->status = status; }
void Person::setStatus(int health, int stamina) {
  this->status = {health, stamina};
}

void Person::setHealth(int health) { this->status.health = health; }
void Person::setStamina(int stamina) { this->status.stamina = stamina; }

// Other fxs 
// TODO: Add error checking for these functions below

int Person::move(int x, int y) {
  this->location = {x, y};
  return 1; // for success
}
int Person::move(Loc location) {
  this->location = location;
  return 1;
}
int Person::move(float tile_id) {
  this->location.tile_id = tile_id;
  return 1; // not working rn
}

int Person::assign(float building_id) {
  this->location.building_id = building_id;
  return 1;
}