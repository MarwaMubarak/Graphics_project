

#ifndef GRAPHICSPROJECT_CIRCLE_H
#define GRAPHICSPROJECT_CIRCLE_H

#include <windows.h>

void Draw8Points(HDC hdc, int xc, int yc, int a, int b, COLORREF c) ;
void DrawCircleIterativePolar(HDC hdc, int xc, int yc, int r, COLORREF c) ;
void DrawModifiedMidpointCircle(HDC hdc, int xc, int yc, int r, COLORREF c) ;
void DrawMidpointCircle(HDC hdc, int xc, int yc, int r, COLORREF c);
void DrawPolarCircle(HDC hdc, int xc, int yc, int r, COLORREF c);
void DrawCartesianCircle(HDC hdc, int xc, int yc, int r, COLORREF c);

#endif //GRAPHICSPROJECT_CIRCLE_H
