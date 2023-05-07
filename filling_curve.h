//
// Created by Legion 5 on 5/7/2023.
//

#ifndef GRAPHICS_PROJECT_FILLING_CURVE_H
#define GRAPHICS_PROJECT_FILLING_CURVE_H
#include <windows.h>
void FillRectangleBezier(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) ;
void FillSquareHermite(HDC hdc, int x, int y, int len, COLORREF c) ;

#endif //GRAPHICS_PROJECT_FILLING_CURVE_H
