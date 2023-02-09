cmake_minimum_required(VERSION 3.23)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment2 Driver.cpp Point.cpp Point.h Shape.cpp Shape.h Movable.h Circle.cpp Circle.h Square.cpp Square.h Rectangle.cpp Rectangle.h Helper.cpp Helper.h)
