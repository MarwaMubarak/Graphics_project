//
// Created by 20115 on 5/7/2023.
//

#ifndef GRAPHICS_PROJECT_ELLIPSE_H
#define GRAPHICS_PROJECT_ELLIPSE_H


#include <windows.h>

void DrawCartesianEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c);

void DrawPolarEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c);

void Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

void DrawMidpointEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c);

#endif //GRAPHICS_PROJECT_ELLIPSE_H
