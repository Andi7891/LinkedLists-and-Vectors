cmake_minimum_required(VERSION 3.26)
project(Vector_Visualizer_3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

include_directories(src)
include_directories(vendors/sdl2/include
        vendors/glew/include
)

#include_directories(vendors/sdl_image)
#include_directories(vendors/imgui)

link_directories(vendors/sdl2/lib
        vendors/glew/lib/Release/x64
)

add_executable(Vector_Visualizer_3D src/main.cpp
        src/Core/Engine_Core.cpp
        src/Core/Engine_Core.h
        src/Core/Engine_Core_Utils.h
        src/Core/VertexBuffer.cpp
        src/Core/VertexBuffer.h
        src/Core/VertexArrayBuffer.cpp
        src/Core/VertexArrayBuffer.h
        src/Core/Shaders/ShaderLoader.cpp
        src/Core/Shaders/ShaderLoader.h)

target_link_libraries(Vector_Visualizer_3D
        SDL2main
        SDL2
        glew32.lib
        Opengl32.lib)