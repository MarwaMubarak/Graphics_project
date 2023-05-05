cmake_minimum_required(VERSION 3.26)
project(Graphics_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphics_project main.cpp circle.cpp circle.h clipping.cpp clipping.h floodfill.cpp floodfill.h rectangle.cpp rectangle.h)
