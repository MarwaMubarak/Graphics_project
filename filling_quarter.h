//
// Created by Esawy on 5/5/2023.
//

#ifndef GRAPHICSPROJECT_FILLING_QUARTER_H
#define GRAPHICSPROJECT_FILLING_QUARTER_H

#include <windows.h>

void line_DDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

void draw_circul_line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c, int quarter);

void draw_circul_quarter(HDC hdc, int x1, int y1, int x2, int y2, int r, COLORREF c, int quarter);

void draw_circul_circuler(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c, int quarter);

#endif //GRAPHICSPROJECT_FILLING_QUARTER_H
