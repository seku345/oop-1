cmake_minimum_required(VERSION 3.26)
project(oop_1)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(oop_1
        main.cpp
        rectangle.cpp
        geometry.h
        circle.cpp
        square.cpp
)
