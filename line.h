//
// Created by 20115 on 5/7/2023.
//
#include <windows.h>
using namespace std;
#ifndef GRAPHICS_PROJECT_LINE_H
#define GRAPHICS_PROJECT_LINE_H

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

void DrawLineMidPoint(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

void DrawLineParametric(HDC hdc,int xs,int ys,int xe,int ye, COLORREF color);

#endif //GRAPHICS_PROJECT_LINE_H

