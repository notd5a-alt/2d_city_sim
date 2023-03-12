project(2D_CITY_SIM)
set(CMAKE_CXX_STANDARD 14)

set(MAIN main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(MAIN main.cpp include/world.cpp include/tile.cpp include/building.cpp include/person.cpp)