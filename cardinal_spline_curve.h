//
// Created by Hazem Adel on 5/10/2023.
//

#include <windows.h>
#include <utility>
#include "vector"

#ifndef GRAPHICS_PROJECT_CARDINAL_SPLINE_CURVE_H
#define GRAPHICS_PROJECT_CARDINAL_SPLINE_CURVE_H
using namespace std;
void DrawCardinalSpline(HDC hdc, vector<pair<int, int>> &vecPoints, int numPoints, double tension, COLORREF color);
#endif //GRAPHICS_PROJECT_CARDINAL_SPLINE_CURVE_H
