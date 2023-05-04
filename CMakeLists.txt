cmake_minimum_required(VERSION 3.23)
project(GraphicsProject C)

set(CMAKE_C_STANDARD 17)

add_executable(GraphicsProject main.c circle.h circle.c Clipping.c Clipping.h Rectangle.c Rectangle.h)
