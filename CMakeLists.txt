cmake_minimum_required(VERSION 3.26)
project(LinkedList_C C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList_C main.c
        Linked_List.h
        Linked_List.c
        Vector.h
        Vector.c
        Utility.h)
