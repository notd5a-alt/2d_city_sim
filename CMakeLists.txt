project(2D_CITY_SIM)
set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(MAIN main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(MAIN main.cpp include/world.cpp include/tile.cpp include/building.cpp include/person.cpp)
target_link_libraries(MAIN ${SDL2_LIBRARIES})