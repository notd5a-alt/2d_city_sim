#include <string>
#include <vector>

struct Loc {
  int x, y;          // the tile they are on
  float tile_id;     // the tile id of tile x,y
  float building_id; // if in a building, have the building id here
};

enum Gender { MALE, FEMALE };

enum State {
  BUSY,
  FREE,
};

enum Job { WORKER, CIVILIAN, BUILDER, CHILD, NONE };

struct Attributes {
  float strength;
  float intelligence;
  float speed;
  float dexterity;
};

struct Status {
  int health;
  int stamina;
};

class Person {
private:
  float id;

  bool life_status;
  float partner_id; // partner, if not in a relationship then will be -1

  std::string name;
  int age;
  Gender gender;

  Loc location;
  State state;

  Attributes attributes;
  Status status;

public:
  Person() : id(rand()), life_status(true), partner_id(-1), name(""), age(0), gender(MALE)
  , location({}), state(FREE), attributes({0,0,0,0}), status({0,0}) {}
  Person(int);                  // w id
  Person(int, Loc);             // w id and Loc
  Person(int, int, int, float); // w id, x, y, tile_id
  Person(int, Loc, std::string, Gender);

  // getters and setters
  float getID() const;

  bool alive() const; // returns true for alive, false for dead
  bool kill();        // kills a person

  std::string getName() const;
  void setName(std::string); // sets the name of the person

  int getAge() const; // returns age
  void setAge(int);   // sets age to defined age
  void incAge();      // increments age by 1

  Gender getGender() const; // returns gender
  void setGender(Gender);   // sets gender to defined gender

  Loc getLocation() const; // returns location
  int getLocX() const;     // returns location.x
  int getLocY() const;     // returns locatiion.y
  float getTileID() const; // returns locaiton.tile_id
  float getBuildingID()
      const; // return location.building_id, returns 0 if not in a building

  State getState() const; // returns person state
  void setState(State);   // sets person state, BUSY or FREE

  Attributes getAttributes() const;               // returns attrs
  void setAttributes(Attributes);                 // sets attrs
  void setAttributes(float, float, float, float); // sets attrs

  Status getStatus() const; // returns status
  int getHealth() const;    // returns health
  int getStamina() const;   // returns stamina available

  void setStatus(Status);   // sets status
  void setStatus(int, int); // sets status

  void setHealth(int);
  void setStamina(int);

  // Other fx's
  int move(int, int); // moves person to coord x y
  int move(Loc);      // move to specific Loc
  int move(float);    // move to tile_id

  int assign(float); // assign to building with building_id
};

// m4 = m3.operator+(m1.operator+(m2));