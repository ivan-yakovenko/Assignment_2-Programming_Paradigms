cmake_minimum_required(VERSION 3.28)
project(Assignment_2_Programming_Paradigms)

set(CMAKE_CXX_STANDARD 26)

add_executable(Assignment_2_Programming_Paradigms Assignment_2/main.cpp
        Assignment_2/DynamicArray/DynamicArray.cpp
        Assignment_2/DynamicArray/DynamicArray.h
)
