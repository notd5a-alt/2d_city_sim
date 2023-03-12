#include <ciso646>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/world.hpp"

// std::istream &
// getline(std::istream &ins,
//         int &n) { // function to take user input but force integer input
//   n = 0;
//   std::string s;
//   if (std::getline(ins, s)) {
//     s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);
//     std::istringstream ss(s);
//     ss >> n;

//     if (!ss.eof())
//       ins.setstate(std::ios::failbit);
//   }
//   return ins;
// }

void print_world(World &world) {

  for (int x = 0; x < world.getSizeX(); x++) {
    for (int y = 0; y < world.getSizeY(); y++) {
      world.getTile(x, y).getCoords().print();
      std::cout << '\t'; // prints the ID of each tile
    }
    std::cout << std::endl;
  }
}

void print_main_menu(Size *size, std::string *name, int *seed) {
  int inp;

  std::cout << "Enter world name (optional): ";
  std::cin >> *name;

  if (*name == "") {
    *name = "World";
  }

  std::cout << std::endl;
  std::cout << "Enter world size[int only](required): " << std::endl;
  std::cout << "Size X = ";
  std::cin >> size->x;
  // while(!getline(std::cin, size.x)) {
  //   std::cin.clear();
  //   std::cout << "non-int inputted, try again" << std::endl;
  // }

  std::cout << std::endl << "Size Y = ";
  std::cin >> size->y;
  // while(!getline(std::cin, size.y)) {
  //   std::cin.clear();
  //   std::cout << "non-int inputted, try again" << std::endl;
  // }
}

void print_req() {}

int run() { // holds the game loop

  bool run = true;

  Size size{};
  std::string name;
  int seed = 0;

  print_main_menu(&size, &name, &seed);

  // generate world of size Size
  World world(seed, size, name);

  while (run) {
    print_world(world);
    run = false;
  }

  return 0;
}

int main() {

  run(); // begin running the game

  return 0;
}