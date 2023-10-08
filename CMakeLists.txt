cmake_minimum_required(VERSION 3.26)
project(Vector_Visualizer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

include_directories(src)
include_directories(vendors/sdl2/include)
#include_directories(vendors/sdl_image)
link_directories(vendors/sdl2/lib)

add_executable(Vector_Visualizer src/main.cpp
        src/App.cpp
        src/App.h)
target_link_libraries(Vector_Visualizer SDL2main SDL2 )