#include "person.hpp"

Person::Person(int id) {
  this->id = id;
  this->life_status = true; // alive
  this-> partner_id = -1; // no partner yet
  this->name = "";
  this->age = 0;
}