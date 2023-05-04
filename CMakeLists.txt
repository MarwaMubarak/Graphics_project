cmake_minimum_required(VERSION 3.23)
project(GraphicsProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphicsProject main.cpp circle.cpp circle.h clipping.cpp clipping.h rectangle.cpp rectangle.h floodfill.cpp floodfill.h)
