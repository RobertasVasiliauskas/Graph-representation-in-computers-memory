cmake_minimum_required(VERSION 3.27)
project(Aizo_2_with_stl)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aizo_2_with_stl main.cpp
        Graph/Graph.cpp
        Graph/Graph.h
        Utilities/Utilities.cpp
        Utilities/Utilities.h
)
