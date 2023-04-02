#pragma once
#ifndef UTIL_H_
#define UTIL_H_

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T> inline std::string tostring(T t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

#endif