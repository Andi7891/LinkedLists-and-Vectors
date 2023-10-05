cmake_minimum_required(VERSION 3.26)
project(LinkedList_C C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList_C src/main.c
        src/Linked_List.h
        src/Linked_List.c
        src/Vector.h
        src/Vector.c
        src/Utility.h
        src/Vector.h
        src/Vector.h)
