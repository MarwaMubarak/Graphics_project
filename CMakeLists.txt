cmake_minimum_required(VERSION 3.23)
project(Graphics_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphics_project main.cpp circle.cpp circle.h clipping.cpp clipping.h floodfill.cpp floodfill.h rectangle.cpp rectangle.h filling_quarters.cpp filling_quarters.h line.cpp line.h ellipse.cpp ellipse.h square.cpp square.h curve.cpp curve.h filling_curve.cpp filling_curve.h)
